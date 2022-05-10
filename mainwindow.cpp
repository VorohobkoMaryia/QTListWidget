#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString students[20] = {"Ворохобко","Фурса","Шибко","Лушакова","Айана","Гонтаренко","Хейлик","Кривонос","Капитанов","Шмат","Шушкевич","Юрчик","Касинский","Борычев","Косяк","Лытня","Халимов","Несытых","Антонченко","Харитончик"};
    for(auto i = 0; i < 10; i++) {
      ui->WindowLeft->addItem(students[i]);
      ui->WindowRight->addItem(students[i+10]);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::MoveFromOneToTheOther(QListWidget*first_list,QListWidget*second_list)
{
 QList<QListWidgetItem*> selItems = first_list->selectedItems();

    if(selItems.empty())
    {
        QMessageBox error;
        error.setIcon(QMessageBox::Warning);
        error.setWindowTitle("Ошибка :_(");
        error.setText("Не выбрана фамилия из нужного списка!!!");
        error.exec();
    }

    foreach(QListWidgetItem* fItem, selItems)//for
    {
        second_list->addItem(fItem->text());
        first_list->takeItem(first_list->row(fItem));
        delete fItem;
    }

};

void MainWindow::on_ButtonSortAscending_clicked()
{
    ui->WindowLeft->sortItems(Qt::AscendingOrder);
}

void MainWindow::on_ButtonSortDescending_clicked()
{
    ui->WindowRight->sortItems(Qt::DescendingOrder);
}

void MainWindow::on_ButtonToRight_clicked()
{
   MoveFromOneToTheOther(ui->WindowLeft,ui->WindowRight);
}

void MainWindow::on_ButtonToLeft_clicked()
{
    MoveFromOneToTheOther(ui->WindowRight,ui->WindowLeft);
}




