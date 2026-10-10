/*
    SPDX-FileCopyrightText: 2020 Michail Vourlakos <mvourlakos@gmail.com>
    SPDX-License-Identifier: GPL-2.0-or-later

*/

#ifndef ACTIVITYDATA_H
#define ACTIVITYDATA_H

//! local
#include "genericdata.h"
#include "generictable.h"

//! Qt
#include <QMetaType>
#include <QIcon>
#include <QString>

namespace Latte {
namespace Data {

class Activity : public Generic
{
public:
    //! Plasma 6 removed KActivities::Info::State, activities no longer have a
    //! running/stopped lifecycle. Keep the same notion locally so that the
    //! delegates can still distinguish real activities (always Running) from
    //! the synthetic "All/Free/Current" entries (Stopped).
    enum State {
        Invalid,
        Stopped,
        Running,
        Starting,
        Stopping
    };

    Activity();
    Activity(Activity &&o);
    Activity(const Activity &o);

    //! Layout data
    bool isCurrent{false};
    QString icon;
    State state{Invalid};

    bool isValid() const;
    bool isRunning() const;

    //! Operators
    Activity &operator=(const Activity &rhs);
    Activity &operator=(Activity &&rhs);
};

//! This is an Activities map in the following structure:
//! #activityId -> activite_information
typedef GenericTable<Data::Activity> ActivitiesTable;

}
}

Q_DECLARE_METATYPE(Latte::Data::Activity)
Q_DECLARE_METATYPE(Latte::Data::ActivitiesTable)

#endif
