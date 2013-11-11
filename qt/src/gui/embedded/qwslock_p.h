/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QWSLOCK_P_H
#define QWSLOCK_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the Qt API.  This header file may
// change from version to version without notice, or even be
// removed.
//
// We mean it.
//

#include <qglobal.h>

QT_BEGIN_NAMESPACE

#ifndef QT_NO_QWS_MULTIPROCESS

class QWSLock
{
public:
    enum LockType { BackingStore, Communication, RegionEvent };

    QWSLock();
    QWSLock(int lockId);
    ~QWSLock();

    bool lock(LockType type, int timeout = -1);
    void unlock(LockType type);
    bool wait(LockType type, int timeout = -1);
    bool hasLock(LockType type);
    int id() const { return semId; }

private:
    int semId;
    int lockCount[2];
};


QT_END_NAMESPACE
#endif // QT_NO_QWS_MULTIPROCESS
#endif // QWSLOCK_P_H