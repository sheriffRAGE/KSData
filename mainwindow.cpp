#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: grey; font-weight: bold;");
}

void MainWindow::on_kerbinButton_toggled(bool checked) //radio button sensor
{
    if(checked)     //changes to Kerbit layout
    ui->distanceLabel->setText("Maximum distance from Kerbin:");
    ui->deltaLabel->setText("Δv:");
    ui->seriesLabel->setText("Flight of the series:");
    ui->velocityLabel->setText("Maximum escape velocity(m/s):");

    ui->deltaEdit->setText("N/A");  //reset fields when either option is selected to avoid clutter from old values
    ui->distanceEdit->setText("N/A");
    ui->velocityEdit->setText("N/A");
    ui->vehicleEdit->setText("N/A");
    ui->seriesEdit->setText("N/A");
    ui->missionEdit->setText("");
    ui->notesEdit->setText("");

    ui->label->setText(""); //reset "Saved!" display from previous saves to allow for seamless continued logging
}

void MainWindow::on_otherButton_toggled(bool checked)
{
    if(checked)     //changes to other layout
    ui->deltaLabel->setText("Total time elapsed:");
    ui->distanceLabel->setText("Current orbit:");
    ui->seriesLabel->setText("Nearest planetary body:");
    ui->velocityLabel->hide();

    ui->deltaEdit->setText("N/A");  //reset fields when either option is selected to avoid clutter from old values
    ui->distanceEdit->setText("N/A");
    ui->velocityEdit->hide();
    ui->vehicleEdit->setText("N/A");
    ui->seriesEdit->setText("N/A");
    ui->missionEdit->setText("");
    ui->notesEdit->setText("");

    ui->label->setText(""); //reset "Saved!" display from previous saves to allow for seamless continued logging
}

void MainWindow::on_saveButton_clicked()
{

    QString deltatext = ui->deltaEdit->text();      //converting text values enter by user to QStrings
    QString distancetext = ui->distanceEdit->text();
    QString velocitytext = ui->velocityEdit->text();
    QString vehicletext = ui->vehicleEdit->text();
    QString seriestext = ui->seriesEdit->text();
    QString missiontext = ui->missionEdit->text() + "" + ui->seriesEdit->text();
    QString offmissiontext = ui->missionEdit->text();
    QString notestext = ui->notesEdit->toPlainText();

    if(ui->kerbinButton->isChecked()) {     //save in this format if Kerbin layout is selected
    QString filename = missiontext+".txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
    QTextStream stream(&file);
    stream << "Vehicle: ";
    stream << vehicletext << "\n";
    stream << "Flight of the series: ";
    stream << seriestext << "\n";
    stream << "Delta-v: ";
    stream << deltatext << "\n";
    stream << "Maximum distance: ";
    stream << distancetext << "\n";
    stream << "Maximum Velocity: ";
    stream << velocitytext << "\n";
    stream << "Notes: ";
    stream << notestext << endl;

    ui->label->setText("Saved!");
    }
  }

    if(ui->otherButton->isChecked()) {      //save in this format if other layout is selected
    QString filename = offmissiontext+".txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
    QTextStream stream(&file);
    stream << "Vehicle: ";
    stream << vehicletext << "\n";
    stream << "Nearest Planetry Body: ";
    stream << seriestext << "\n";
    stream << "Total Time Elapsed: ";
    stream << deltatext << "\n";
    stream << "Current Orbit: ";
    stream << distancetext << "\n";
    stream << "Notes: ";
    stream << notestext << endl;

    ui->label->setText("Saved!");
    }
  }
}

MainWindow::~MainWindow()
{
    delete ui;
}
