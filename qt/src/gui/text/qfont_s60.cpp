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

#include "qfont.h"
#include "qfont_p.h"
#include <private/qt_s60_p.h>
#include <private/qpixmap_s60_p.h>
#include "qmutex.h"

QT_BEGIN_NAMESPACE

#ifdef QT_NO_FREETYPE
Q_GLOBAL_STATIC(QMutex, lastResortFamilyMutex);
Q_GLOBAL_STATIC_WITH_INITIALIZER(QStringList, fontFamiliesOnFontServer, {
    QSymbianFbsHeapLock lock(QSymbianFbsHeapLock::Unlock);
    const int numTypeFaces = S60->screenDevice()->NumTypefaces();
    for (int i = 0; i < numTypeFaces; i++) {
        TTypefaceSupport typefaceSupport;
        S60->screenDevice()->TypefaceSupport(typefaceSupport, i);
        const QString familyName((const QChar *)typefaceSupport.iTypeface.iName.Ptr(), typefaceSupport.iTypeface.iName.Length());
        x->append(familyName);
    }
    lock.relock();
});
#endif // QT_NO_FREETYPE

QString QFont::lastResortFamily() const
{
#ifdef QT_NO_FREETYPE
    QMutexLocker locker(lastResortFamilyMutex());
    static QString family;
    if (family.isEmpty()) {
        
        QSymbianFbsHeapLock lock(QSymbianFbsHeapLock::Unlock);
        
        CFont *font;
        const TInt err = S60->screenDevice()->GetNearestFontInTwips(font, TFontSpec());
        Q_ASSERT(err == KErrNone);
        const TFontSpec spec = font->FontSpecInTwips();
        family = QString((const QChar *)spec.iTypeface.iName.Ptr(), spec.iTypeface.iName.Length());
        S60->screenDevice()->ReleaseFont(font);
        
        lock.relock();
    }
    return family;
#else // QT_NO_FREETYPE
    // For the FreeType case we just hard code the face name, since otherwise on
    // East Asian systems we may get a name for a stroke based (non-ttf) font.

    // TODO: Get the type face name in a proper way

    const bool isJapaneseOrChineseSystem =
        User::Language() == ELangJapanese || User::Language() == ELangPrcChinese;

    return QLatin1String(isJapaneseOrChineseSystem?"Heisei Kaku Gothic S60":"Series 60 Sans");
#endif // QT_NO_FREETYPE
}

QString QFont::defaultFamily() const
{
#ifdef QT_NO_FREETYPE
    switch(d->request.styleHint) {
        case QFont::SansSerif: {
            static const char* const preferredSansSerif[] = {"Nokia Sans S60", "Series 60 Sans"};
            for (int i = 0; i < sizeof preferredSansSerif / sizeof preferredSansSerif[0]; ++i) {
                const QString sansSerif = QLatin1String(preferredSansSerif[i]);
                if (fontFamiliesOnFontServer()->contains(sansSerif))
                    return sansSerif;
            }
        }
        // No break. Intentional fall through.
        default:
            return lastResortFamily();
    }
#endif // QT_NO_FREETYPE
    return lastResortFamily();
}

QT_END_NAMESPACE