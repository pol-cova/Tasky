#ifndef CONTACTO_H
#define CONTACTO_H


#include <QObject>
#include <QDate>
#include <QString>

class Contacto: public QObject
{
    Q_OBJECT
public:
    Contacto(QObject *parent = nullptr); // Declaration only

    // Setters
    void setName(const QString &val);
    void setLastName(const QString &val);
    void setMail(const QString &val);
    void setPhone(const QString &val);
    void setAddress(const QString &val);
    void setBirthDate(const QDate &val);

    // Getters
    QString getName() const;
    QString getLastName() const;
    QString getMail() const;
    QString getPhone() const;
    QString getAddress() const;
    QDate getBirthDate() const;

private:
    QString name;
    QString lastName;
    QString mail;
    QString phone;
    QString address;
    QDate birthDate;
};

#endif // CONTACTO_H
