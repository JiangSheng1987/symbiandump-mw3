/*
* Copyright (c) 2009 Nokia Corporation and/or its subsidiary(-ies).
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
* Description: remconcoreapitarget stub for testing keycapture
*
*/


#ifndef REMCONCOREAPITARGET_H
#define REMCONCOREAPITARGET_H


#include <remconcoreapi.h>  // TRemConCoreApiOperationId 
#include "remconinterfacebase.h"

class CRemConInterfaceSelector;
class MRemConCoreApiTargetObserver;

class CRemConCoreApiTarget : public CActive, public CRemConInterfaceBase
    {

public:
    
    static int getCount();
    static void setNewLLeave( bool value = true );
    static void NewLLeaveIfDesiredL();
    static int getSendResponseCount();
    static TRemConCoreApiOperationId getLastOperationId();

public:

    static CRemConCoreApiTarget* NewL(CRemConInterfaceSelector& aInterfaceSelector, MRemConCoreApiTargetObserver& aObserver);
    virtual ~CRemConCoreApiTarget();

    void VolumeUpResponse(TRequestStatus& aStatus, TInt aError);
    void VolumeDownResponse(TRequestStatus& aStatus, TInt aError);
    void SendResponse(TRequestStatus& aStatus, TRemConCoreApiOperationId aOperationId, TInt aError);    
    
protected:

    // from CActive
    //void Cancel(){};
    virtual void DoCancel();
    virtual void RunL();
    
private:
    
    CRemConCoreApiTarget();
    
private:

    TRequestStatus*             iClientStatus;
    
    };

#endif      // REMCONCOREAPITARGET_H

// End of File
