#include "widget1.h"
#include "ui_widget1.h"
#include "string"
#include "iostream"
#include "math.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
using namespace std;

string equacao, b1, b2, binario1, binario2;

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Calculadora");

}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_zeroButton_clicked()
{
    if (strlen(equacao.data()) < 9){
       if (strlen(equacao.data()) < 4)
       {
            b1 = b1 + "0";
            equacao = b1 + b2;
       } else if(strlen(equacao.data()) > 4) {
            b2 = b2 + "0";
            equacao = b1 + "+" + b2;
       } else {
            b2 = b2 + "0";
            equacao = equacao + "+" + b2;
       }

       ui->textResult->setText(equacao.data());
    }


}

void Widget::on_oneButton_clicked()
{
      if (strlen(equacao.data()) < 9) {
        if (strlen(equacao.data()) < 4)
        {
             b1 = b1 + "1";
             equacao = b1 + b2;
        } else if(strlen(equacao.data()) > 4) {
             b2 = b2 + "1";
             equacao = b1 + "+" + b2;
        } else {
            b2 = b2 + "1";
            equacao = equacao + "+" + b2;
        }
        ui -> textResult -> setText(equacao.data());
      }

}

string decimalBinario(int decimal )
{
    int resto;
    long bin = 0;
    int i = 1;

    while( decimal != 0 )
    {
        resto = decimal % 2;
        decimal /=  2;
        bin += resto * i;
        i *= 10;
    }

    return to_string(bin);
}


int binarioDecimal(string binario){

    int i, tam, decimal = 0;
    tam = 4;

    for (i = tam-1; i >= 0; i--) {
        if ((int)binario.data()[i] == '1') {
            decimal += pow(2,tam-1-i);
        }
    }

    return decimal;
}

void Widget::on_Enter_clicked()
{
    int decimalN1 = binarioDecimal(b1.data());
    int decimalN2 = binarioDecimal(b2.data());

    equacao = equacao + "=" + decimalBinario(decimalN1 + decimalN2);;

    ui->textResult->setText(equacao.data());
}

void Widget::on_RefreshButton_clicked()
{

}
