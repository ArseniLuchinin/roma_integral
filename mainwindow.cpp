#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Trapezion_formule.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_3_editingFinished()
{

    QRegExp r{"[0-9]+"};

    if(!r.exactMatch(ui->lineEdit_3->text())){
        qDebug() << "Введённое значение не является числом, попробуйте снова";
        ui->lineEdit_3->clear();
    }
    else{
        n = ui->lineEdit_3->text().toInt();
    }
}


void MainWindow::on_lineEdit_editingFinished()
{
    QRegExp r{"[+-]?((\\d+\\.?\\d*)|(\\.\\d+))"};

    if(!r.exactMatch(ui->lineEdit->text())){
        qDebug() << "Введённое значение не является числом, попробуйте снова";
        ui->lineEdit->clear();
    }
    else{
        b = ui->lineEdit->text().toFloat();
    }
}


void MainWindow::on_lineEdit_2_editingFinished()
{
    QRegExp r{"[+-]?((\\d+\\.?\\d*)|(\\.\\d+))"};

    if(!r.exactMatch(ui->lineEdit_2->text())){
        qDebug() << "Введённое значение не является числом, попробуйте снова";
        ui->lineEdit_2->clear();
    }
    else{
        a = ui->lineEdit_2->text().toFloat();
    }
}


void MainWindow::on_pushButton_clicked()
{
    if(!ui->lineEdit->displayText().isEmpty()
            && !ui->lineEdit_2->displayText().isEmpty()
            && !ui->lineEdit_3->displayText().isEmpty()){
        ui->label_3->setText(
            QString::number(
                trapezoid_Method(a, b, n, [](float x){
                return 1.f/(sqrtf(x*x*x + 2.f));
            })
            )
        );
    }
}

