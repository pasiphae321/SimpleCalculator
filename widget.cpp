#include <QMessageBox>
#include "widget.h"
#include "./ui_widget.h"
#include "Handler.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_19_clicked()
{
    this->expression += "0";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_13_clicked()
{
    this->expression += "1";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_8_clicked()
{
    this->expression += "2";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_9_clicked()
{
    this->expression += "3";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_14_clicked()
{
    this->expression += "4";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_15_clicked()
{
    this->expression += "5";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_16_clicked()
{
    this->expression += "6";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_12_clicked()
{
    this->expression += "7";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_11_clicked()
{
    this->expression += "8";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_10_clicked()
{
    this->expression += "9";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_22_clicked()
{
    this->expression += ".";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_17_clicked()
{
    this->expression += "(";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_20_clicked()
{
    this->expression += ")";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_24_clicked()
{
    this->expression += "+";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_25_clicked()
{
    this->expression += "-";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_26_clicked()
{
    this->expression += "*";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_27_clicked()
{
    this->expression += "/";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_21_clicked()
{
    this->expression.chop(1);
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_18_clicked()
{
    this->expression = "";
    ui->lineEdit->setText(this->expression);
}


void Widget::on_pushButton_23_clicked()
{
    try {
        Handler handler1(this->expression);
        QString result = QString::number(handler1.calculate());
        this->expression = result;
        ui->lineEdit->setText(this->expression);  // 显示结果
    }
    catch (std::exception & exception1) {
        QMessageBox::warning(this, "错误", "非法表达式!");
        this->expression = "";
        ui->lineEdit->setText(this->expression);
    }
}

