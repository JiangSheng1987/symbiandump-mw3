/*
* Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description: 
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "CLucene.h"
#include "CLucene/queryParser/MultiFieldQueryParser.h"

#include "cpixhits.h"
#include "cpixsearch.h"
#include "cpixidxdb.h"
#include "cpixexc.h"
#include "iidxdb.h"
#include "initparams.h"
#include "cpixutil.h"
#include "iqrytype.h"

//Introduced for prefix optimization.
#include "prefixopt.h"
#include "cpixmaindefs.h"

#include "queryparser.h"

namespace Cpix
{

    /**
     * Format and semantics are described in iqrytype.cpp
     */
    class LuceneQryType : public IQryType
    {
    private:
        //
        // private members
        //
        lucene::search::Query            * clQuery_;

    public:
        //
        // public operators
        //

        //
        // lifetime management
        //
        LuceneQryType()
            : clQuery_(NULL)
        {
            ;
        }


        ~LuceneQryType()
        {
            _CLDECDELETE(clQuery_);
        }
        

        //
        // from interface IQryType
        //

        virtual void setUp(cpix_QueryParser              * queryParser,
                           const std::list<std::wstring> & args,
                           const wchar_t                 * qryStr)
        {
        	if (args.size() > 0)
                {
                    THROW_CPIXEXC(PL_ERROR "No arguments needed here");
                }
            
             IQueryParser* qp = Cast2Native<cpix_QueryParser>(queryParser);
             clQuery_ = qp->parse(qryStr).release();

             if (clQuery_ == NULL)
            	 {
                    THROW_CPIXEXC("Query reduced to empty query.");
            	 }
        }


        virtual cpix_Hits * search(cpix_IdxSearcher * idxSearcher)
        {
            return CLuceneSearchIdx(idxSearcher,
                                    clQuery_
                                    );
        }


        virtual cpix_Hits * search(cpix_IdxDb * idxDb)
        {
            return CLuceneSearchIdx(idxDb,
                                    clQuery_
                                    );
        }

    private:
        //
        // implementation details
        //
    };



    IQryType * CreateCLuceneQryType()
    {
        return new LuceneQryType;
    }


}
