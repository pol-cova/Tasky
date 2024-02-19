// evento.cpp
#include "evento.h"

Evento::Evento(QObject *parent)
    : QObject(parent)
{
    // Constructor code here
}

void Evento::setName(const QString &val)
{
    name = val;
}

void Evento::setDireccion(const QString &val)
{
    direccion = val;
}

void Evento::setParticipantes(const QString &val)
{
    participantes = val;
}

void Evento::setFechaInicio(const QDate &val)
{
    fechaInicio = val;
}

void Evento::setFechaFin(const QDate &val)
{
    fechaFin = val;
}

void Evento::setHoraInicio(const QTime &val)
{
    horaInicio = val;
}

void Evento::setHoraFin(const QTime &val)
{
    horaFin = val;
}

QString Evento::getName() const
{
    return name;
}

QString Evento::getDireccion() const
{
    return direccion;
}

QString Evento::getParticipantes() const
{
    return participantes;
}

QDate Evento::getFechaInicio() const
{
    return fechaInicio;
}

QDate Evento::getFechaFin() const
{
    return fechaFin;
}

QTime Evento::getHoraInicio() const
{
    return horaInicio;
}

QTime Evento::getHoraFin() const
{
    return horaFin;
}
