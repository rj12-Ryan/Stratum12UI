#ifndef TIMEPROVIDER_H
#define TIMEPROVIDER_H

#include <QObject>
#include <QString>


class TimeProvider : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString currentTime READ getCurrentTime NOTIFY currentTimeChanged)

public:
    explicit TimeProvider(QObject* parent = nullptr);
        QString getCurrentTime() const;

signals:
    void currentTimeChanged();
public slots:
    void updateTime();
private:
    QString m_currentTime;
};

#endif // TIMEPROVIDER_H
