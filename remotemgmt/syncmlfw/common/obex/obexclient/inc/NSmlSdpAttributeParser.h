/*
* Copyright (c) 2002 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  SyncML Obex client
*
*/


#include <btsdp.h>
#include "StaticArrayC.h"


#ifndef __SDP_ATTRIBUTE_PARSER_PAN__
#define __SDP_ATTRIBUTE_PARSER_PAN__

/** BTPointToPoint application panic codes */
enum TSdpAttributeParserPanics 
    {
    ESdpAttributeParserInvalidCommand = 1,
    ESdpAttributeParserNoValue,
    ESdpAttributeParserValueIsList,
    ESdpAttributeParserValueTypeUnsupported
    };

inline void Panic(TSdpAttributeParserPanics aReason)
    { 
    User::Panic(_L("SAP"), aReason);
    }


#endif // __SDP_ATTRIBUTE_PARSER_PAN__



#ifndef __NSML_SDP_ATTRIBUTE_PARSER_H__
#define __NSML_SDP_ATTRIBUTE_PARSER_H__


class MSdpAttributeNotifier;

/*! 
  @class TSdpAttributeParser
  
  @discussion An instance of TSdpAttributeParser is used to check an SDP 
  attribute value, and read selected parts
  */
class TSdpAttributeParser : public MSdpAttributeValueVisitor 
    {
public:

/*!
  @enum TNodeCommand
  
  @discussion The command to be carried out at a node
  @value ECheckType check the type of the value
  @value ECheckValue check the type and the value
  @value ECheckEnd check that a list ends at this point
  @value ESkip do not check this value - can not match a list end
  @value EReadValue pass the value onto the observer
  @value EFinished marks the end of the node list
  */
    enum TNodeCommand
        {
        ECheckType,     
        ECheckValue,  
        ECheckEnd,      
        ESkip,        
        EReadValue,    
        EFinished
        };

/*! 
  struct SSdpAttributeNode
  
  @discussion An instance of SSdpAttributeNode is used to determine how
  to parse an SDP attribute value data element
  */
    struct SSdpAttributeNode
        {
        /*! @var iCommand the command for the node */
        TNodeCommand iCommand;

        /*! @var iType the expected type */
        TSdpElementType iType;

        /*! @var iValue the expected value for ECheckValue, the value of aKey
        passed to the observer for EReadValue */
        TInt iValue;    
        };

    typedef const TStaticArrayC<SSdpAttributeNode> TSdpAttributeList;

/*!
  @function TSdpAttributeParser
  
  @discussion Construct a TSdpAttributeParser
  @param aNodeList the list of expected nodes 
  @param aObserver an observer to read specified node values
  */
    TSdpAttributeParser(TSdpAttributeList& aNodeList, MSdpAttributeNotifier& aObserver);

/*!
  @function HasFinished
  
  @discussion Check if parsing processed the whole list
  @result true is the index refers to the EFinished node
  */
    TBool HasFinished() const;

public: // from MSdpAttributeValueVisitor

/*!
  @function VisitAttributeValueL
  
  @discussion Process a data element
  @param aValue the data element 
  @param aType the type of the data element
  */
    void VisitAttributeValueL(CSdpAttrValue& aValue, TSdpElementType aType);

/*!
  @function StartListL
  
  @discussion Process the start of a data element list
  @param aList the data element list 
  */
    void StartListL(CSdpAttrValueList& aList);

/*!
  @function EndListL
  
  @discussion Process the end of a data element list
  */
    void EndListL();

private:

/*!
  @function CheckTypeL
  
  @discussion Check the type of the current node is the same as the specified type
  @param aElementType the type of the current data element
  */
    void CheckTypeL(TSdpElementType aElementType) const;

/*!
  @function CheckValueL
  
  @discussion Check the value of the current node is the same as the specified value
  @param aValue the value of the current data element.
  */
    void CheckValueL(CSdpAttrValue& aValue) const;

/*!
  @function ReadValueL
  
  @discussion Pass the data element value to the observer
  @param aValue the value of the current data element.
  */
    void ReadValueL(CSdpAttrValue& aValue) const;

/*!
  @function CurrentNode
  
  @discussion Get the current node
  @result the current node
  */
    const SSdpAttributeNode& CurrentNode() const;

/*!
  @function AdvanceL
  
  @discussion Advance to the next node. Leaves with KErrEof if at the finished node.
  */
    void AdvanceL();

private:

    /*! @var iObserver the observer to read values */
    MSdpAttributeNotifier& iObserver;

    /*! @var iNodeList a list defining the expected structure of the value */
    TSdpAttributeList& iNodeList;

    /*! @var iCurrentNodeIndex the index of the current node in iNodeList */
    TInt iCurrentNodeIndex;
    };

#endif // __NSML_SDP_ATTRIBUTE_PARSER_H__
