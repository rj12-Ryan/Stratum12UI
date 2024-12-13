#include "dateprovider.h"
#include <QTimer>
#include <QDateTime>
#include <QTimeZone>


DateProvider::DateProvider(QObject* parent) : QObject(parent), m_currentDate("") {

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &DateProvider::updateDate);
    timer->start(1000);
    updateDate();
}

QString DateProvider::getCurrentDate() const {
    return m_currentDate;
}

void DateProvider::updateDate(){

    QDateTime currentDateTime = QDateTime::currentDateTime();
    QDate currentDate = currentDateTime.date();

    //Get the day, month, and year
    QString dayOfWeek = currentDate.toString("dddd");
    QString monthName = currentDate.toString("MMMM");
    int day = currentDate.day();
    int year = currentDate.year();

    QString ordinalSuffix = "";

    switch (day % 10){
    case 1: ordinalSuffix = "st";
    case 2: ordinalSuffix = "nd";
    case 3: ordinalSuffix = "rd";
    default: ordinalSuffix = "th";
    }


    QString formattedDate = QString("%1, %2 %3%4 %5")
                                .arg(dayOfWeek)
                                .arg(monthName)
                                .arg(day)
                                .arg(ordinalSuffix)
                                .arg(year);

    QString newDate = formattedDate;

    if (newDate != m_currentDate){
        m_currentDate = newDate;
        emit currentDateChanged();
    }
}
