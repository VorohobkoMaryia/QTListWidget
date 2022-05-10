#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidget>
#include <QMainWindow>
#include "QMessageBox"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void MoveFromOneToTheOther(QListWidget* first_list, QListWidget* second_list);

private slots:
    void on_ButtonSortAscending_clicked();//возрастание
    void on_ButtonSortDescending_clicked();//убывание
    void on_ButtonToRight_clicked();
    void on_ButtonToLeft_clicked();

};
#endif // MAINWINDOW_H
