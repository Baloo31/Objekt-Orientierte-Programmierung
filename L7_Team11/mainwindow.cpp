#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Controller.h"
#include <string>
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>

using namespace std;
using namespace controller;

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->controller = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_managerSelectButton_clicked()
{
    if (!this->controller){
    string password = this->ui->password->toPlainText().toLocal8Bit().constData();
    if (password == "s3cr3t") {
        try {
            string username = this->ui->username->toPlainText().toLocal8Bit().constData();
            if (username == "") {
                this->ui->operationStatus->setText("Username is invalid!");
                return;
            }
            this->controller = this->controller->getInstance(true, username);
            this->ui->status->setText("You selected : Manager");
            QString str = this->ui->username->toPlainText();
            this->ui->userLabel->setText(str);
            string datenFile = QFileDialog::getOpenFileName(this, "Choose a file to load the cars!",  "C://").toLocal8Bit().constData();
            string favoritenFile = QFileDialog::getOpenFileName(this, "Choose a file to load the favourite cars!",  "C://").toLocal8Bit().constData();
            this->controller->leseAusDateien(datenFile, favoritenFile);
        } catch (exception&) {
        }
    } else this->ui->operationStatus->setText("Password is incorrect!");
    }
}


void MainWindow::on_exitButton_clicked()
{
    this->close();
}


void MainWindow::on_clientSelectButton_clicked()
{
    if (!this->controller){
    string password = this->ui->password->toPlainText().toLocal8Bit().constData();
    if (password == "tr1ck") {
        try {
            string username = this->ui->username->toPlainText().toLocal8Bit().constData();
            if (username == "") {
                this->ui->operationStatus->setText("Username is invalid!");
                return;
            }
            this->controller = this->controller->getInstance(false, username);
            this->ui->status->setText("You selected : Client");
            QString str = this->ui->username->toPlainText();
            this->ui->userLabel->setText(str);
            string datenFile = QFileDialog::getOpenFileName(this, "Choose a file to load the cars!",  "C://").toLocal8Bit().constData();
            string favoritenFile = QFileDialog::getOpenFileName(this, "Choose a file to load the favourite cars!",  "C://").toLocal8Bit().constData();
            this->controller->leseAusDateien(datenFile, favoritenFile);
        } catch (exception&) {
        }
    } else this->ui->operationStatus->setText("Password is incorrect!");
    }
}


void MainWindow::on_fugeEin_clicked()
{
    if (this->controller){
        string modell = this->ui->inputModell->toPlainText().toLocal8Bit().constData();
        if (modell == ""){
            this->ui->operationStatus->setText("Modell Field is invalid! Operation failed!");
            return;
        }


        string marke = this->ui->inputMarke->toPlainText().toLocal8Bit().constData();
        if (marke == ""){
            this->ui->operationStatus->setText("Marke Field is invalid! Operation failed!");
            return;
        }


        string jahrStr = this->ui->inputJahr->toPlainText().toLocal8Bit().constData();
        int jahr;
        try {
            jahr = stoi(jahrStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Jahr Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", jahr, 1000, 50000, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Jahr Field is invalid! Operation failed!");
            return;
        }

        string kilometerStr = this->ui->inputKilometer->toPlainText().toLocal8Bit().constData();
        int kilometer;
        try {
            kilometer = stoi(kilometerStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Kilometer Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2011, kilometer, 50000, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Kilometer Field is invalid! Operation failed!");
            return;
        }


        string preisStr = this->ui->inputPreis->toPlainText().toLocal8Bit().constData();
        double preis;
        try {
            preis = stod(preisStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Preis Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2011, 1000, preis, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Preis Field is invalid! Operation failed!");
            return;
        }


        string leistungStr = this->ui->inputLeistung->toPlainText().toLocal8Bit().constData();
        int leistung;
        try {
            leistung = stoi(leistungStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Leistung Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2005, 1000, 50000, leistung, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Leistung Field is invalid! Operation failed!");
            return;
        }


        string treibstoff = this->ui->inputTreibstoff->toPlainText().toLocal8Bit().constData();
        if (treibstoff == ""){
            this->ui->operationStatus->setText("Treibstoff Field is invalid! Operation failed!");
            return;
        }


        if (this->controller->fugeEin(Auto(modell, marke, jahr, kilometer, preis, leistung, treibstoff))) {
            this->ui->operationStatus->setText("Added succesfully!");
            return;
        }
    }
    this->ui->operationStatus->setText("Only Managers can do that!");
}


void MainWindow::on_losche_clicked()
{
    if (this->controller){
        string modell = this->ui->inputModell->toPlainText().toLocal8Bit().constData();
        if (modell == ""){
            this->ui->operationStatus->setText("Modell Field is invalid! Operation failed!");
            return;
        }


        string marke = this->ui->inputMarke->toPlainText().toLocal8Bit().constData();
        if (marke == ""){
            this->ui->operationStatus->setText("Marke Field is invalid! Operation failed!");
            return;
        }


        string jahrStr = this->ui->inputJahr->toPlainText().toLocal8Bit().constData();
        int jahr;
        try {
            jahr = stoi(jahrStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Jahr Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", jahr, 1000, 50000, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Jahr Field is invalid! Operation failed!");
            return;
        }

        string kilometerStr = this->ui->inputKilometer->toPlainText().toLocal8Bit().constData();
        int kilometer;
        try {
            kilometer = stoi(kilometerStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Kilometer Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2011, kilometer, 50000, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Kilometer Field is invalid! Operation failed!");
            return;
        }


        string preisStr = this->ui->inputPreis->toPlainText().toLocal8Bit().constData();
        double preis;
        try {
            preis = stod(preisStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Preis Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2011, 1000, preis, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Preis Field is invalid! Operation failed!");
            return;
        }


        string leistungStr = this->ui->inputLeistung->toPlainText().toLocal8Bit().constData();
        int leistung;
        try {
            leistung = stoi(leistungStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Leistung Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2005, 1000, 50000, leistung, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Leistung Field is invalid! Operation failed!");
            return;
        }


        string treibstoff = this->ui->inputTreibstoff->toPlainText().toLocal8Bit().constData();
        if (treibstoff == ""){
            this->ui->operationStatus->setText("Treibstoff Field is invalid! Operation failed!");
            return;
        }


        if (this->controller->losche(Auto(modell, marke, jahr, kilometer, preis, leistung, treibstoff))) {
            this->ui->operationStatus->setText("Deleted succesfully!");
            return;
        } else {
            this->ui->operationStatus->setText("Operation failed!");
            return;
        }

    }
    this->ui->operationStatus->setText("Only Managers can do that!");
}


void MainWindow::on_aktualisiere_clicked()
{
    if (this->controller){
        string modell = this->ui->inputModell->toPlainText().toLocal8Bit().constData();
        if (modell == ""){
            this->ui->operationStatus->setText("Modell Field is invalid! Operation failed!");
            return;
        }


        string marke = this->ui->inputMarke->toPlainText().toLocal8Bit().constData();
        if (marke == ""){
            this->ui->operationStatus->setText("Marke Field is invalid! Operation failed!");
            return;
        }


        string jahrStr = this->ui->inputJahr->toPlainText().toLocal8Bit().constData();
        int jahr;
        try {
            jahr = stoi(jahrStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Jahr Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", jahr, 1000, 50000, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Jahr Field is invalid! Operation failed!");
            return;
        }

        string kilometerStr = this->ui->inputKilometer->toPlainText().toLocal8Bit().constData();
        int kilometer;
        try {
            kilometer = stoi(kilometerStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Kilometer Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2011, kilometer, 50000, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Kilometer Field is invalid! Operation failed!");
            return;
        }


        string preisStr = this->ui->inputPreis->toPlainText().toLocal8Bit().constData();
        double preis;
        try {
            preis = stod(preisStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Preis Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2011, 1000, preis, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Preis Field is invalid! Operation failed!");
            return;
        }


        string leistungStr = this->ui->inputLeistung->toPlainText().toLocal8Bit().constData();
        int leistung;
        try {
            leistung = stoi(leistungStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Leistung Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2005, 1000, 50000, leistung, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Leistung Field is invalid! Operation failed!");
            return;
        }


        string treibstoff = this->ui->inputTreibstoff->toPlainText().toLocal8Bit().constData();
        if (treibstoff == ""){
            this->ui->operationStatus->setText("Treibstoff Field is invalid! Operation failed!");
            return;
        }


        if (this->controller->aktualisiere(Auto(modell, marke, jahr, kilometer, preis, leistung, treibstoff))) {
            this->ui->operationStatus->setText("Update succesfully!");
            return;
        } else {
            this->ui->operationStatus->setText("Operation failed!");
            return;
        }

    }
    this->ui->operationStatus->setText("Only Managers can do that!");
}


void MainWindow::on_sucheMarke_clicked()
{
    if (this->controller){
    string marke = this->ui->inputMarke->toPlainText().toLocal8Bit().constData();
    if (marke == ""){
        this->ui->operationStatus->setText("Marke Field is invalid! Operation failed!");
        return;
    }
    if (this->controller->sucheMarke(marke)){
        this->ui->operationStatus->setText("Found!");
        return;
    } else {
        this->ui->operationStatus->setText("Not found!");
        return;
    }
    } this->ui->operationStatus->setText("You are not logged in!");
}


void MainWindow::on_sucheModell_clicked()
{
    if (this->controller){
    string modell = this->ui->inputModell->toPlainText().toLocal8Bit().constData();
    if (modell == ""){
        this->ui->operationStatus->setText("Modell Field is invalid! Operation failed!");
        return;
    }
    if (this->controller->sucheModell(modell)){
        this->ui->operationStatus->setText("Found!");
        return;
    } else {
        this->ui->operationStatus->setText("Not found!");
        return;
    }
    } this->ui->operationStatus->setText("You are not logged in!");
}


void MainWindow::on_fugeZurFavoritenEin_clicked()
{
    if (this->controller){
        string modell = this->ui->inputModell->toPlainText().toLocal8Bit().constData();
        if (modell == ""){
            this->ui->operationStatus->setText("Modell Field is invalid! Operation failed!");
            return;
        }


        string marke = this->ui->inputMarke->toPlainText().toLocal8Bit().constData();
        if (marke == ""){
            this->ui->operationStatus->setText("Marke Field is invalid! Operation failed!");
            return;
        }


        string jahrStr = this->ui->inputJahr->toPlainText().toLocal8Bit().constData();
        int jahr;
        try {
            jahr = stoi(jahrStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Jahr Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", jahr, 1000, 50000, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Jahr Field is invalid! Operation failed!");
            return;
        }

        string kilometerStr = this->ui->inputKilometer->toPlainText().toLocal8Bit().constData();
        int kilometer;
        try {
            kilometer = stoi(kilometerStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Kilometer Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2011, kilometer, 50000, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Kilometer Field is invalid! Operation failed!");
            return;
        }


        string preisStr = this->ui->inputPreis->toPlainText().toLocal8Bit().constData();
        double preis;
        try {
            preis = stod(preisStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Preis Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2011, 1000, preis, 200, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Preis Field is invalid! Operation failed!");
            return;
        }


        string leistungStr = this->ui->inputLeistung->toPlainText().toLocal8Bit().constData();
        int leistung;
        try {
            leistung = stoi(leistungStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Leistung Field is invalid! Operation failed!");
            return;
        }
        try {
            Auto a = Auto("a", "b", 2005, 1000, 50000, leistung, "a");
        } catch (exception&) {
            this->ui->operationStatus->setText("Leistung Field is invalid! Operation failed!");
            return;
        }


        string treibstoff = this->ui->inputTreibstoff->toPlainText().toLocal8Bit().constData();
        if (treibstoff == ""){
            this->ui->operationStatus->setText("Treibstoff Field is invalid! Operation failed!");
            return;
        }


        if (this->controller->fugeZurFavoritenEin(Auto(modell, marke, jahr, kilometer, preis, leistung, treibstoff))) {
            this->ui->operationStatus->setText("Added succesfully!");
            return;
        }
    }
    this->ui->operationStatus->setText("Operation failed!");
}


void MainWindow::on_save_clicked()
{
    if (this->controller){
        string datenFile = QFileDialog::getOpenFileName(this, "Choose a file to store the cars!",  "C://").toLocal8Bit().constData();
        string favoritenFile = QFileDialog::getOpenFileName(this, "Choose a file to store the favourite cars!",  "C://").toLocal8Bit().constData();
        this->controller->schreibeInDateien(datenFile, favoritenFile);
        this->ui->operationStatus->setText("Succesfully saved!");
    } else this->ui->operationStatus->setText("Not logged in!");
}


void MainWindow::on_filterAlter_clicked()
{
    if (this->controller){
        string jahrStr = this->ui->inputJahr->toPlainText().toLocal8Bit().constData();
        int jahr;
        try {
            jahr = stoi(jahrStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Jahr Field is invalid! Operation failed!");
            return;
        }

        string output = "";
        vector<Auto> autos = this->controller->filterAlter(jahr);
        for (int idx = 0; idx < autos.size(); idx++){
            output = output + "Auto" + to_string(idx+1)+ ": " + autos[idx].get_modell() + " / " + autos[idx].get_marke() + " / " +
                    to_string(autos[idx].get_erstzulassungsjahr()) + " / " + to_string(autos[idx].get_kilometer()) + " / " + to_string(autos[idx].get_preis()) + " / " +
                    to_string(autos[idx].get_leistung()) + " / " + autos[idx].get_treibstoff() + "\n";
        }
        QString qout = QString::fromStdString(output);
        QMessageBox::about(this, "Autos nach Alter gefiltert", qout);
        this->ui->operationStatus->setText("Succesfully done!");
    } else this->ui->operationStatus->setText("Not logged in!");
}


void MainWindow::on_filterKilometer_clicked()
{
    if (this->controller){
        string kilometerStr = this->ui->inputKilometer->toPlainText().toLocal8Bit().constData();
        int kilometer;
        try {
            kilometer = stoi(kilometerStr);
        } catch (exception&){
            this->ui->operationStatus->setText("Kilometer Field is invalid! Operation failed!");
            return;
        }

        string output = "";
        vector<Auto> autos = this->controller->filterKilometer(kilometer);
        for (int idx = 0; idx < autos.size(); idx++){
            output = output + "Auto" + to_string(idx+1)+ ": " + autos[idx].get_modell() + " / " + autos[idx].get_marke() + " / " +
                    to_string(autos[idx].get_erstzulassungsjahr()) + " / " + to_string(autos[idx].get_kilometer()) + " / " + to_string(autos[idx].get_preis()) + " / " +
                    to_string(autos[idx].get_leistung()) + " / " + autos[idx].get_treibstoff() + "\n";
        }
        QString qout = QString::fromStdString(output);
        QMessageBox::about(this, "Autos nach Kilometer gefiltert", qout);
        this->ui->operationStatus->setText("Succesfully done!");
    } else this->ui->operationStatus->setText("Not logged in!");
}


void MainWindow::on_zeigeNachPreisSortiert_clicked()
{
    if (this->controller){
        string output = "";
        vector<Auto> autos = this->controller->zeigeNachPreisSortiert();
        for (int idx = 0; idx < autos.size(); idx++){
            output = output + "Auto" + to_string(idx+1)+ ": " + autos[idx].get_modell() + " / " + autos[idx].get_marke() + " / " +
                    to_string(autos[idx].get_erstzulassungsjahr()) + " / " + to_string(autos[idx].get_kilometer()) + " / " + to_string(autos[idx].get_preis()) + " / " +
                    to_string(autos[idx].get_leistung()) + " / " + autos[idx].get_treibstoff() + "\n";
        }
        QString qout = QString::fromStdString(output);
        QMessageBox::about(this, "Autos nach Preis sortiert", qout);
        this->ui->operationStatus->setText("Succesfully done!");
    } else this->ui->operationStatus->setText("Not logged in!");
}


void MainWindow::on_zeigeFavoriten_clicked()
{
    if (this->controller){
        string output = "";
        vector<Auto> autos = this->controller->zeigeFavoriten();
        if (autos.size() > 0) {
        for (int idx = 0; idx < autos.size(); idx++){
            output = output + "Auto" + to_string(idx+1)+ ": " + autos[idx].get_modell() + " / " + autos[idx].get_marke() + " / " +
                    to_string(autos[idx].get_erstzulassungsjahr()) + " / " + to_string(autos[idx].get_kilometer()) + " / " + to_string(autos[idx].get_preis()) + " / " +
                    to_string(autos[idx].get_leistung()) + " / " + autos[idx].get_treibstoff() + "\n";
        }
        QString qout = QString::fromStdString(output);
        QMessageBox::about(this, "Favoriten Autos", qout);
        } else QMessageBox::about(this, "Lieblingsautos", "Der Benutzer hat keine Autos in seine Liste von Lieblingsautos,\noder er ist ein Manager!");
        this->ui->operationStatus->setText("Succesfully done!");
    } else this->ui->operationStatus->setText("Not logged in!");
}

