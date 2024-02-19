#ifndef EVENTO_H
#define EVENTO_H


#include <QObject>
#include <QDate>
#include <QTime>
#include <QString>

class Evento: public QObject
{
    Q_OBJECT
public:
    Evento(QObject *parent = nullptr); // Declaration only

    // Setters
    void setName(const QString &val);
    void setDireccion(const QString &val);
    void setParticipantes(const QString &val);
    void setFechaInicio(const QDate &val);
    void setFechaFin(const QDate &val);
    void setHoraInicio(const QTime &val);
    void setHoraFin(const QTime &val);

    // Getters
    QString getName() const;
    QString getDireccion() const;
    QString getParticipantes() const;
    QDate getFechaInicio() const;
    QDate getFechaFin() const;
    QTime getHoraInicio() const;
    QTime getHoraFin() const;



private:
    QString name;
    QString direccion;
    QString participantes;
    QDate fechaInicio;
    QDate fechaFin;
    QTime horaInicio;
    QTime horaFin;

};


#endif // EVENTO_H
