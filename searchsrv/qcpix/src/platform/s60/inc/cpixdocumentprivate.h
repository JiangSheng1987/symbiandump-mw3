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

#ifndef _CPIXDOCUMENTPVTIMPL_H
#define _CPIXDOCUMENTPVTIMPL_H

#include <QString>
#include <QList>
#include "cpixdocumentfield.h"

//Forward Declarations
class CpixDocumentField;

class CpixDocumentPrivate: public QObject
{
public:
    QString iDocId;
    QString iExcerpt;
    QString iBaseAppClass;
    QList< CpixDocumentField* > iFields;
    
    CpixDocumentPrivate::~CpixDocumentPrivate()
        {
        for (int i =0; i< iFields.count();i++)
            {
            delete iFields.at(i);
            }
        }
};

#endif //_CPIXDOCUMENTPVTIMPL_H
