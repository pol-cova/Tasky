#include "agenda.h"
#include "ui_agenda.h"
#include "mainwindow.h"
// Contacto
#include "contacto.h"
// Evento
#include "evento.h"
// Funcs
#include <QWidget>
#include <QString>
#include <QListWidgetItem>

Agenda::Agenda(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Agenda)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    connect(ui->add_C, &QPushButton::clicked, this, &Agenda::on_add_C_clicked);

    // Contactos func
    // Fields
    nombreInput = ui->nombreInput;
    apellidoInput = ui->apellidoInput;
    mailInput = ui->mailInput;
    phoneInput = ui->celularInput;
    addressInput = ui->addressInput;
    fechaNacInput = ui->fechaNac;
    // Add button
    addContacto = ui->agregarContactoBTN;
    // Signal
    connect(addContacto,  &QPushButton::clicked, this, &Agenda::on_agregarContactoBTN_clicked);

    // Search func
    // Field
    searchQuery = ui->searchInput;
    // Button
    search = ui->searchBTN;
    // Signal
    connect(search,  &QPushButton::clicked, this, &Agenda::on_searchBTN_clicked);

    // Eventos func
    // Fields
    nombreEvento = ui->nombreEventoInput;
    direccionEvento = ui->addressEventoInput;
    participantesEvento = ui->participantesInput;
    fechaInicioEvento = ui->fechaInicioInput;
    fechaFinEvento = ui->fechaFinInput;
    horaInicioEvento = ui->horaInicioInput;
    horaFinEvento = ui->horaFinInput;
    // Button
    addEvent = ui->add_Event;
    // Signal
    connect(search, &QPushButton::clicked, this, &Agenda::on_agregarEventoBTN_clicked);

}

Agenda::~Agenda()
{
    delete ui;
}

// Add contacto window
void Agenda::on_add_C_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

// Atras btn
void Agenda::on_backBTN_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// See contacto list window
void Agenda::on_my_C_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    // msg
    getContactMsg();
}

// Atras
void Agenda::on_backBTN_2_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}
// Get contactos
void Agenda::getContactMsg(){
    int contactosSize = misContactos.size();

    QWidget *misConcts = ui->MisConcts;
    QLabel *msgStatus = misConcts->findChild<QLabel *>("msgStatus");

    if (msgStatus){
        if(contactosSize > 0){
            msgStatus->setText(QString("Tienes: %1 contactos").arg(contactosSize));
            msgStatus->setStyleSheet("color: #1a1b25;");
            ui->contactList->setVisible(true);
        } else {
            msgStatus->setText(QString("Aun no tienes contactos agrega uno ahora!"));
            msgStatus->setStyleSheet("color: #d7263d");
            ui->contactList->setVisible(false);
        }
    }
}

// Agregar contacto
void Agenda::on_agregarContactoBTN_clicked()
{
    // Read input
    QString name = nombreInput->text();
    QString lastName = apellidoInput->text();
    QString mail = mailInput->text();
    QString phone = phoneInput->text();
    QString address = addressInput->text();
    QDate fechaNac = fechaNacInput->date();

    // Instance
    Contacto *contacto = new Contacto(parent());

    // Setter
    contacto->setName(name);
    contacto->setLastName(lastName);
    contacto->setMail(mail);
    contacto->setPhone(phone);
    contacto->setAddress(address);
    contacto->setBirthDate(fechaNac);

    // Check if any of the fields are empty
        if (name.isEmpty() || lastName.isEmpty() || mail.isEmpty() ||
            phone.isEmpty() || address.isEmpty() || !fechaNac.isValid()) {
            // Clear fields
            nombreInput->clear();
            apellidoInput->clear();
            mailInput->clear();
            phoneInput->clear();
            addressInput->clear();
            fechaNacInput->setDate(QDate::currentDate());
            return; // Exit the function without adding the contact to the list
        }

    // Add contacto
    misContactos.append(contacto);

    // Add to list
    ui->contactList->clear();

    for(int i = 0; i < misContactos.size(); ++i) {
        Contacto* contacto = misContactos.at(i);

        // Check if any of the fields are empty
        if (contacto->getName().isEmpty() ||
            contacto->getLastName().isEmpty() ||
            contacto->getMail().isEmpty() ||
            contacto->getPhone().isEmpty() ||
            contacto->getAddress().isEmpty() ||
            !contacto->getBirthDate().isValid()) {
            // Skip this contact if any field is empty
            continue;
        }

        // Construct the contact information string
        // Construct the contact information string
        QString contactInfo = QString("Nombre: %1, Apellido: %2, Email: %3, Celular: %4, Direccion: %5, Cumpleaños: %6")
                                  .arg(contacto->getName(), contacto->getLastName(), contacto->getMail(),
                                       contacto->getPhone(), contacto->getAddress(),
                                       contacto->getBirthDate().toString("yyyy-MM-dd")); // Assuming birthDate is a QDate object

        // Create a QListWidgetItem and add it to the list widget
        QListWidgetItem *item = new QListWidgetItem(contactInfo);
        ui->contactList->addItem(item);
    }

    // Clear fields
    nombreInput->clear();
    apellidoInput->clear();
    mailInput->clear();
    phoneInput->clear();
    addressInput->clear();
    fechaNacInput->setDate(QDate::currentDate());

}

// Search window
void Agenda::on_search_C_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    // Assuming you have a QLabel named "myLabel"

    // Set the color of the label's text
    ui->parameterQ->setStyleSheet("color: #1a1b25;"); // Change the color to red (#ff0000)

    ui->results->hide();
    // check size
    if (misContactos.size() == 0){
        // If misContactos is empty, display a message
        ui->results->show();
        ui->results->setText(QString("La lista de contactos está vacía!"));
        ui->results->setStyleSheet("color: #d7263d");
    }
}

// Atras
void Agenda::on_backBTN_3_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}

// Home btn

void Agenda::on_backBTN_4_clicked()
{
    MainWindow* home = new MainWindow(this);
    this->hide();
    home->show();
}


// Search action

void Agenda::on_searchBTN_clicked()
{
    // Read input
    QString query = searchQuery->text();

    // Search function
    searchContact(query);
}

// Search function
void Agenda::searchContact(const QString& keyword) {
    ui->searchResults->clear();

    // Check if misContactos has more than 0 contacts
    if (misContactos.size() > 0) {
        // Iterate over the list of contacts
        for (Contacto* contacto : misContactos) {
            if (contacto->getName().contains(keyword, Qt::CaseInsensitive) ||
                contacto->getLastName().contains(keyword, Qt::CaseInsensitive) ||
                contacto->getPhone().contains(keyword, Qt::CaseInsensitive)) {
                // If a match is found, add the contact to the list widget
                QString contactInfo = QString("Nombre: %1, Apellido: %2, Email: %3, Celular: %4, Direccion: %5, Cumpleaños: %6")
                                      .arg(contacto->getName(), contacto->getLastName(), contacto->getMail(),
                                           contacto->getPhone(), contacto->getAddress(),
                                           contacto->getBirthDate().toString("yyyy-MM-dd"));
                QListWidgetItem *item = new QListWidgetItem(contactInfo);
                ui->searchResults->addItem(item);
            }
        }

        // Check if search results are empty
        if (ui->searchResults->count() == 0) {
            ui->results->show();
            ui->results->setText(QString("No encontramos ningún contacto con ese nombre, apellido o celular!"));
            ui->results->setStyleSheet("color: #d7263d");
        } else {
            // Clear the message if search results are found
            ui->results->clear();
        }
    } else {
        // If misContactos is empty, display a message
        ui->results->show();
        ui->results->setText(QString("La lista de contactos está vacía!"));
        ui->results->setStyleSheet("color: #d7263d");
    }
}

// Evento section


// Add evento window
void Agenda::on_add_Event_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

// Atras
void Agenda::on_backBTN_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// Add event button action
void Agenda::on_agregarEventoBTN_clicked()
{
    // Read Input
    QString name = nombreEvento->text();
    QString direccion = direccionEvento->text();
    QString participantes = participantesEvento->text();
    QDate fechaInicio = fechaInicioEvento->date();
    QDate fechaFin = fechaFinEvento->date();
    QTime horaInicio = horaInicioEvento->time();
    QTime horaFin = horaFinEvento->time();

    // Instance
    Evento *evento = new Evento(this);

    // Setters
    evento->setName(name);
    evento->setDireccion(direccion);
    evento->setParticipantes(participantes);
    evento->setFechaInicio(fechaInicio);
    evento->setFechaFin(fechaFin);
    evento->setHoraInicio(horaInicio);
    evento->setHoraFin(horaFin);

    // Check if any of the fields are empty
    if (name.isEmpty() || direccion.isEmpty() || participantes.isEmpty() ||
        !fechaInicio.isValid() || !fechaFin.isValid() || !horaInicio.isValid() || !horaFin.isValid()) {
        // Clear fields
        nombreEvento->clear();
        direccionEvento->clear();
        participantesEvento->clear();
        fechaInicioEvento->setDate(QDate::currentDate());
        fechaFinEvento->setDate(QDate::currentDate());
        horaInicioEvento->setTime(QTime::currentTime());
        horaFinEvento->setTime(QTime::currentTime());
        return; // Exit the function without adding the event to the list
    }

    // Add event to list
    misEventos.append(evento);

    // Add to list
    ui->eventList->clear();

    for(int i = 0; i < misEventos.size(); ++i) {
        Evento* evento = misEventos.at(i);

        // Check if any of the fields are empty
        if (evento->getName().isEmpty() ||
            evento->getDireccion().isEmpty() ||
            evento->getParticipantes().isEmpty() ||
            !evento->getFechaInicio().isValid() ||
            !evento->getFechaFin().isValid() ||
            !evento->getHoraInicio().isValid() ||
            !evento->getHoraFin().isValid()) {
            // Skip this event if any field is empty
            continue;
        }

        // Construct the event information string
        QString eventInfo = QString("Nombre: %1, Direccion: %2, Participantes: %3, Fecha Inicio: %4, Fecha Fin: %5, Hora Inicio: %6, Hora Fin: %7")
                                  .arg(evento->getName(), evento->getDireccion(), evento->getParticipantes(),
                                       evento->getFechaInicio().toString("yyyy-MM-dd"),
                                       evento->getFechaFin().toString("yyyy-MM-dd"),
                                       evento->getHoraInicio().toString("hh:mm:ss"),
                                       evento->getHoraFin().toString("hh:mm:ss"));

        // Create a QListWidgetItem and add it to the list widget
        QListWidgetItem *item = new QListWidgetItem(eventInfo);
        ui->eventList->addItem(item);
    }
    // Clear fields
    nombreEvento->clear();
    direccionEvento->clear();
    participantesEvento->clear();
    fechaInicioEvento->setDate(QDate::currentDate());
    fechaFinEvento->setDate(QDate::currentDate());
    horaInicioEvento->setTime(QTime::currentTime());
    horaFinEvento->setTime(QTime::currentTime());

}

// Ver eventos
void Agenda::on_add_Event_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    int eventosSize = misEventos.size();

    QWidget *misEvent = ui->MisEvents;
    QLabel *msgStatus = misEvent->findChild<QLabel *>("msgStatus_2");

    if (msgStatus){
        if(eventosSize > 0){
            msgStatus->setText(QString("Tienes: %1 eventos").arg(eventosSize));
            msgStatus->setStyleSheet("color: #1a1b25;");
            ui->eventList->setVisible(true);
        } else {
            msgStatus->setText(QString("Aun no tienes eventos agrega uno ahora!"));
            msgStatus->setStyleSheet("color: #d7263d");
            ui->eventList->setVisible(false);
        }
    }
}


// atras
void Agenda::on_backBTN_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

