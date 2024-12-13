#include "timeprovider.h"
#include <QTimer>
#include <QDateTime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <QTimeZone>


TimeProvider::TimeProvider(QObject* parent) : QObject(parent), m_currentTime("") {

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &TimeProvider::updateTime);
    timer->start(10);
    updateTime();
}

QString TimeProvider::getCurrentTime() const {
    return m_currentTime;
}

void TimeProvider::updateTime(){
    int offset = -7 * 3600;

    long long epochMillis = QDateTime::currentMSecsSinceEpoch();

    // Split into seconds and milliseconds
    long long totalSeconds = epochMillis / 1000 + offset;
    int milliseconds = epochMillis % 1000;

    // Calculate hours, minutes, and seconds
    int seconds = totalSeconds % 60;
    long long totalMinutes = totalSeconds / 60;
    int minutes = totalMinutes % 60;
    long long totalHours = totalMinutes / 60;
    int hours = totalHours % 24;

    // Determine AM or PM
    bool isPM = hours >= 12;
    int hour12 = hours % 12;
    if (hour12 == 0) hour12 = 12; // Handle midnight and noon

    // Format the time
    std::ostringstream oss;
    oss << std::setfill('0') << std::setw(2) << hour12 << ":"
        << std::setfill('0') << std::setw(2) << minutes << ":"
        << std::setfill('0') << std::setw(2) << seconds << "."
        << std::setfill('0') << std::setw(2) << (milliseconds/=10) << " "
        << (isPM ? "PM" : "AM");


        QString newTime = QString::fromStdString(oss.str());
    if (newTime != m_currentTime){
        m_currentTime = newTime;
        emit currentTimeChanged();
    }
}
