#ifndef AGENDA_H
#define AGENDA_H

#include <QMainWindow>
// Funcs
#include <QLineEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QPushButton>
#include <QList>
// Contactos
#include "contacto.h"
// Eventos
#include "evento.h"

namespace Ui {
class Agenda;
}

class Agenda : public QMainWindow
{
    Q_OBJECT

public:
    explicit Agenda(QWidget *parent = nullptr);
    ~Agenda();

private slots:
    void on_add_C_clicked();

    void on_backBTN_clicked();

    void on_my_C_clicked();

    void on_backBTN_2_clicked();

    void getContactMsg();

    void on_agregarContactoBTN_clicked();

    void on_search_C_clicked();

    void on_backBTN_3_clicked();

    void on_backBTN_4_clicked();

    void searchContact(const QString& keyword);

    void on_searchBTN_clicked();

    void on_add_Event_clicked();

    void on_backBTN_5_clicked();

    void on_agregarEventoBTN_clicked();

    void on_backBTN_6_clicked();

    void on_add_Event_2_clicked();

private:
    Ui::Agenda *ui;
    // Fields for contactos
    QLineEdit *nombreInput;
    QLineEdit *apellidoInput;
    QLineEdit *mailInput;
    QLineEdit *phoneInput;
    QLineEdit *addressInput;
    QDateEdit *fechaNacInput;
    // Add contacto button
    QPushButton *addContacto;

    // Field for search
    QLineEdit *searchQuery;
    // Search button
    QPushButton *search;

    // Fields for events
    QLineEdit *nombreEvento;
    QLineEdit *direccionEvento;
    QLineEdit *participantesEvento;
    QTimeEdit *horaInicioEvento;
    QTimeEdit *horaFinEvento;
    QDateEdit *fechaInicioEvento;
    QDateEdit *fechaFinEvento;
    // Add event button
    QPushButton *addEvent;


    // List for contactos
    QList<Contacto*> misContactos;
    // List for eventos
    QList<Evento*> misEventos;

};

#endif // AGENDA_H
