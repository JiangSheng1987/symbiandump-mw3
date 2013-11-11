/*
* Copyright (c) 2004 Nokia Corporation and/or its subsidiary(-ies). 
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
* Description:  Alert queue and handler
*
*/


// INCLUDE FILES
#include "NSmlAlertQueue.h"


// ============================ MEMBER FUNCTIONS ===============================

// ---------------------------------------------------------
// CNSmlAlertInfo::~CNSmlAlertInfo()
// Destructor
// ---------------------------------------------------------
//
CNSmlAlertInfo::~CNSmlAlertInfo()
	{
	iTaskInfo.ResetAndDestroy();
	iTaskInfo.Close();
	}

//End of File