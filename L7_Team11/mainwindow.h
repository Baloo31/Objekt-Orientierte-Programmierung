#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "Controller.h"
using namespace controller;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_managerSelectButton_clicked();

    void on_exitButton_clicked();

    void on_clientSelectButton_clicked();

    void on_fugeEin_clicked();

    void on_losche_clicked();

    void on_aktualisiere_clicked();

    void on_sucheMarke_clicked();

    void on_sucheModell_clicked();

    void on_fugeZurFavoritenEin_clicked();

    void on_save_clicked();

    void on_filterAlter_clicked();

    void on_filterKilometer_clicked();

    void on_zeigeNachPreisSortiert_clicked();

    void on_zeigeFavoriten_clicked();

private:
    Ui::MainWindow *ui;
    Controller* controller;
};
#endif // MAINWINDOW_H
