#ifndef DATEPROVIDER_H
#define DATEPROVIDER_H

#include <QObject>
#include <QString>


class DateProvider : public QObject {
    Q_OBJECT
    Q_PROPERTY(QString currentDate READ getCurrentDate NOTIFY currentDateChanged)

public:
    explicit DateProvider(QObject* parent = nullptr);
    QString getCurrentDate() const;

signals:
    void currentDateChanged();
public slots:
    void updateDate();
private:
    QString m_currentDate;
};

#endif // DATEPROVIDER_H
