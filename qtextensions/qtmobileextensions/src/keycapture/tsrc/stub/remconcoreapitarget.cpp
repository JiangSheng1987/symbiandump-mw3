/*
* Copyright (c) 2006 Nokia Corporation and/or its subsidiary(-ies).
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


#include <e32debug.h>

#include "stub/remconcoreapitarget.h"
#include "stub/remconinterfaceselector.h"

int gCRemConCoreApiTargetCount = 0;
bool gCRemConCoreApiTargetNewLLeave = false;
int gCRemConCoreApiTargetSendResponseCount = 0;
TRemConCoreApiOperationId gLastOperationId = ENop;

//static functions start

TRemConCoreApiOperationId CRemConCoreApiTarget::getLastOperationId()
    {
    return gLastOperationId;
    }

int CRemConCoreApiTarget::getCount()
{
    return gCRemConCoreApiTargetCount;
}

void CRemConCoreApiTarget::setNewLLeave( bool value )
{
    gCRemConCoreApiTargetNewLLeave = value;
}

void CRemConCoreApiTarget::NewLLeaveIfDesiredL()
{
    if (gCRemConCoreApiTargetNewLLeave)
    {
        RDebug::Print(_L("CRemConCoreApiTarget::NewLLeaveIfDesiredL Leave"));
        gCRemConCoreApiTargetNewLLeave = false;
        User::Leave(KErrGeneral);
    }
}

int CRemConCoreApiTarget::getSendResponseCount()
{
    return gCRemConCoreApiTargetSendResponseCount;
}

//static functions end


CRemConCoreApiTarget::CRemConCoreApiTarget()
    : CActive(EPriorityStandard),
      iClientStatus(NULL)
{
    gCRemConCoreApiTargetCount++;
}

CRemConCoreApiTarget::~CRemConCoreApiTarget()
{
    //Cancel();
    gCRemConCoreApiTargetCount--;
    gCRemConCoreApiTargetSendResponseCount = 0;
}

CRemConCoreApiTarget* CRemConCoreApiTarget::NewL(CRemConInterfaceSelector& aInterfaceSelector, MRemConCoreApiTargetObserver& /*aObserver*/)
{
    RDebug::Print(_L("stub CRemConCoreApiTarget::NewL"));
    CRemConCoreApiTarget::NewLLeaveIfDesiredL();
    CRemConCoreApiTarget* self = new(ELeave) CRemConCoreApiTarget();
    aInterfaceSelector.RegisterCoreApiL(self);
    return self;
}


void CRemConCoreApiTarget::VolumeUpResponse(TRequestStatus& aStatus, TInt /*aError*/)
{
    RDebug::Print(_L(">>CRemConCoreApiTarget::VolumeUpResponse"));    
    iClientStatus = &aStatus;
    gCRemConCoreApiTargetSendResponseCount++;
    RunL();    
    RDebug::Print(_L("<<CRemConCoreApiTarget::VolumeUpResponse"));
}

void CRemConCoreApiTarget::VolumeDownResponse(TRequestStatus& aStatus, TInt /*aError*/)
{
    RDebug::Print(_L(">>CRemConCoreApiTarget::VolumeDownResponse"));    
    iClientStatus = &aStatus;
    gCRemConCoreApiTargetSendResponseCount++;
    RunL();    
    RDebug::Print(_L("<<CRemConCoreApiTarget::VolumeDownResponse"));
}

void CRemConCoreApiTarget::SendResponse(TRequestStatus& aStatus, TRemConCoreApiOperationId aOperationId, TInt /*aError*/)
{
    RDebug::Print(_L(">>CRemConCoreApiTarget::SendResponse"));    
    iClientStatus = &aStatus;
    gLastOperationId = aOperationId;
    gCRemConCoreApiTargetSendResponseCount++;   
    RunL();
    RDebug::Print(_L("<<CRemConCoreApiTarget::SendResponse"));
}


void CRemConCoreApiTarget::DoCancel()
{
}

void CRemConCoreApiTarget::RunL()
{
    RDebug::Print(_L(">>CRemConCoreApiTarget::RunL"));
    User::RequestComplete(iClientStatus, KErrNone);
    RDebug::Print(_L("<<CRemConCoreApiTarget::RunL"));
}

//end of file
