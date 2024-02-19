#include "contacto.h"

Contacto::Contacto(QObject *parent)
    : QObject(parent)
{
    // Constructor code here
}

void Contacto::setName(const QString &val)
{
    name = val;
}

void Contacto::setLastName(const QString &val)
{
    lastName = val;
}

void Contacto::setMail(const QString &val)
{
    mail = val;
}

void Contacto::setPhone(const QString &val)
{
    phone = val;
}

void Contacto::setAddress(const QString &val)
{
    address = val;
}

void Contacto::setBirthDate(const QDate &val)
{
    birthDate = val;
}

QString Contacto::getName() const
{
    return name;
}

QString Contacto::getLastName() const
{
    return lastName;
}

QString Contacto::getMail() const
{
    return mail;
}

QString Contacto::getPhone() const
{
    return phone;
}

QString Contacto::getAddress() const
{
    return address;
}

QDate Contacto::getBirthDate() const
{
    return birthDate;
}
