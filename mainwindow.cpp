#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream db;
ifstream db2;
int user2;
int user1;
int p;
string str;
double d;
double d2;
char linea[10];
char linea2[10];

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_manhatan_clicked()
{
    ui->listResultados->clear();

    //calculo con la base de datos Jester
    if(ui->dataBase->currentText()=="Jester"){
    db.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    db2.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    bool ok;
    user1 = ui->user1->text().toInt(&ok);
    user2 = ui->user2->text().toInt(&ok);

    for(int i=1;i<=(user1-1)*101;i++){
        db>>linea;
    }
    for(int i=1;i<=(user2-1)*101;i++){
        db2>>linea2;
    }
    db>>linea;
    db2>>linea2;
    cout<<linea<<" "<<linea2<<endl;

    double r=0;
    for(int i = 0;i<101;i++){
        db>>linea;
        db2>>linea2;
        str=linea;
        d=atof(str.c_str());
        str=linea2;
        d2=atof(str.c_str());
        if(d!=0 && d2!=0){
            r+=abs(d - d2);
        }
    }
    ui->listResultados->addItem(QString::number(r));
    //ui->lineEdit->setText(QString::number(r));
    db.close();
    db2.close();
    r=0;
    }

    if(ui->dataBase->currentText()=="MovieRatings"){

    }

    if(ui->dataBase->currentText()=="MovieLensSmall"){

    }

    if(ui->dataBase->currentText()=="Libros"){

    }

}

void MainWindow::on_euclidiana_clicked()
{
    ui->listResultados->clear();

    //calculo con la base de datos Jester
    if(ui->dataBase->currentText()=="Jester"){
    db.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    db2.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    bool ok;
    user1 = ui->user1->text().toInt(&ok);
    user2 = ui->user2->text().toInt(&ok);

    for(int i=1;i<=(user1-1)*101;i++){
        db>>linea;
    }
    for(int i=1;i<=(user2-1)*101;i++){
        db2>>linea2;
    }
    db>>linea;
    db2>>linea2;

    double r=0;
    for(int i = 0;i<101;i++){
        db>>linea;
        db2>>linea2;
        str=linea;
        d=atof(str.c_str());
        str=linea2;
        d2=atof(str.c_str());
        if(d!=0 && d2!=0){
            r+=(d - d2)*(d - d2);
        }
    }
    r=sqrt(r);
    ui->listResultados->addItem(QString::number(r));
    //ui->lineEdit->setText(QString::number(r));
    db.close();
    db2.close();
    r=0;
    }

    if(ui->dataBase->currentText()=="MovieRatings"){

    }

    if(ui->dataBase->currentText()=="MovieLensSmall"){

    }

    if(ui->dataBase->currentText()=="Libros"){

    }
}

void MainWindow::on_minkowsky_clicked()
{
    ui->listResultados->clear();

    //calculo con la base de datos Jester
    if(ui->dataBase->currentText()=="Jester"){
    db.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    db2.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    bool ok;
    user1 = ui->user1->text().toInt(&ok);
    user2 = ui->user2->text().toInt(&ok);
    p = ui->valorMink->text().toInt(&ok);

    for(int i=1;i<=(user1-1)*101;i++){
        db>>linea;
    }
    for(int i=1;i<=(user2-1)*101;i++){
        db2>>linea2;
    }
    db>>linea;
    db2>>linea2;

    double r=0;
    for(int i = 0;i<101;i++){
        db>>linea;
        db2>>linea2;
        str=linea;
        d=atof(str.c_str());
        str=linea2;
        d2=atof(str.c_str());
        if(d!=0 && d2!=0){
            r+=pow(abs(d - d2),p);
        }
    }
    r=pow(r,1/double(p));
    ui->listResultados->addItem(QString::number(r));
    //ui->lineEdit->setText(QString::number(r));
    db.close();
    db2.close();
    r=0;
    }

    if(ui->dataBase->currentText()=="MovieRatings"){

    }

    if(ui->dataBase->currentText()=="MovieLensSmall"){

    }

    if(ui->dataBase->currentText()=="Libros"){

    }
}

void MainWindow::on_pearson_clicked()
{
    ui->listResultados->clear();

    //calculo con la base de datos Jester
    if(ui->dataBase->currentText()=="Jester"){
    db.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    db2.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    bool ok;
    user1 = ui->user1->text().toInt(&ok);
    user2 = ui->user2->text().toInt(&ok);

    for(int i=1;i<=(user1-1)*101;i++){
        db>>linea;
    }
    for(int i=1;i<=(user2-1)*101;i++){
        db2>>linea2;
    }
    db>>linea;
    db2>>linea2;
    double rd=0;
    double rn=0;
    double r=0;
    double pro=0;
    double sumx=0;
    double sumxx=0;
    double sumyy=0;
    double sumy=0;
    double n=0;
    for(int i = 0;i<101;i++){
        db>>linea;
        db2>>linea2;
        str=linea;
        d=atof(str.c_str());
        str=linea2;
        d2=atof(str.c_str());
        if(d!=0 && d2!=0){
            pro+=(d * d2);
            sumx+=d;
            sumy+=d2;
            sumxx+=d*d;
            sumyy+=d2*d2;
            n++;
        }
    }
    rd=sqrt(sumxx-((sumx*sumx)/n))*sqrt(sumyy-((sumy*sumy)/n));
    rn= pro-(sumx*sumy/n);
    if(rn==0){
        r=0;
    }else{
        r=rn/rd;
    }
    ui->listResultados->addItem(QString::number(r));
    //ui->lineEdit->setText(QString::number(r));
    db.close();
    db2.close();
    r=0;
    }

    if(ui->dataBase->currentText()=="MovieRatings"){

    }

    if(ui->dataBase->currentText()=="MovieLensSmall"){

    }

    if(ui->dataBase->currentText()=="Libros"){

    }
}

void MainWindow::on_coseno_clicked()
{
    ui->listResultados->clear();

    //calculo con la base de datos Jester
    if(ui->dataBase->currentText()=="Jester"){
    db.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    db2.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    bool ok;
    user1 = ui->user1->text().toInt(&ok);
    user2 = ui->user2->text().toInt(&ok);

    for(int i=1;i<=(user1-1)*101;i++){
        db>>linea;
    }
    for(int i=1;i<=(user2-1)*101;i++){
        db2>>linea2;
    }
    db>>linea;
    db2>>linea2;

    double rd=0;
    double r=0;
    double pro=0;
    double sumxx=0;
    double sumyy=0;
    double n=0;
    for(int i = 0;i<101;i++){
        db>>linea;
        db2>>linea2;
        str=linea;
        d=atof(str.c_str());
        str=linea2;
        d2=atof(str.c_str());
        if(d!=0 && d2!=0){
            pro+=(d * d2);
            sumxx+=d*d;
            sumyy+=d2*d2;
            n++;
        }
    }
    rd=sqrt(sumyy)*sqrt(sumxx);
    if(pro==0){
        r=0;
    }else{
        r=pro/rd;
    }
    ui->listResultados->addItem(QString::number(r));
    //ui->lineEdit->setText(QString::number(r));
    db.close();
    db2.close();
    r=0;
    }

    if(ui->dataBase->currentText()=="MovieRatings"){

    }

    if(ui->dataBase->currentText()=="MovieLensSmall"){

    }

    if(ui->dataBase->currentText()=="Libros"){

    }
}

void MainWindow::on_jaccard_clicked()
{
    ui->listResultados->clear();

    //calculo con la base de datos Jester
    if(ui->dataBase->currentText()=="Jester"){
    db.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    db2.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    bool ok;
    user1 = ui->user1->text().toInt(&ok);
    user2 = ui->user2->text().toInt(&ok);

    for(int i=1;i<=(user1-1)*101;i++){
        db>>linea;
    }
    for(int i=1;i<=(user2-1)*101;i++){
        db2>>linea2;
    }
    db>>linea;
    db2>>linea2;

    double r=0;
    double unio=0;
    double inte=0;
    for(int i = 0;i<101;i++){
        db>>linea;
        db2>>linea2;
        str=linea;
        d=atof(str.c_str());
        str=linea2;
        d2=atof(str.c_str());

            if(d!=0 || d2!=0){
                unio++;
            }
            if(d!=0 && d2!=0){
                inte++;
            }

    }
    r=inte/unio;
    ui->listResultados->addItem(QString::number(r));
    //ui->lineEdit->setText(QString::number(r));
    db.close();
    db2.close();
    r=0;
    }

    if(ui->dataBase->currentText()=="MovieRatings"){

    }

    if(ui->dataBase->currentText()=="MovieLensSmall"){

    }

    if(ui->dataBase->currentText()=="Libros"){

    }
}

void MainWindow::on_knn_clicked(){
    ui->listResultados->clear();

    //calculo con la base de datos Jester
    if(ui->dataBase->currentText()=="Jester"){
    if(ui->distancia->currentText()=="Pearson"){

    db.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    db2.open("E:/Proyectos/QT/TBD/TBD/Jester/jester.csv");
    QString strResult;
    double knn[1000];
    int kni[1000];
    double d[101];
    for(int i=0;i<1000;i++){
        knn[i]=0.0;
    }
    bool ok;
    user1 = ui->user1->text().toInt(&ok);
    int k = ui->valorK->text().toInt(&ok);
    double r=0;
    for(int i=1;i<=(user1-1)*101;i++){
        db>>linea;
    }
    for(int i=0;i<101;i++){
        db>>linea;
        str=linea;
        d[i]= atof(str.c_str());
    }

    for(int i=1;i<=73421;i++){
    db2>>linea2;
    double rd=0;
    double rn=0;

    double pro=0;
    double sumx=0;
    double sumxx=0;
    double sumyy=0;
    double sumy=0;
    double n=0;
    for(int i = 1;i<101;i++){
        db2>>linea2;
        str=linea2;
        d2=atof(str.c_str());
        if(d[i]!=0 && d2!=0){
            pro+=(d[i] * d2);
            sumx+=d[i];
            sumy+=d2;
            sumxx+=d[i]*d[i];
            sumyy+=d2*d2;
            n++;
        }
    }
    rd=sqrt(sumxx-((sumx*sumx)/n))*sqrt(sumyy-((sumy*sumy)/n));
    rn= pro-(sumx*sumy/n);
    if(rn==0){
        r=0;
    }else{
        r=rn/rd;
    }
    cout<<r<<endl;
    for(int j=0;j<k;j++){
                if(r>knn[j]){
                    knn[j]=r;
                    kni[j]=i;
                    r=0;
                }
    }

    }
    QString salida = "";
    for(int j=0;j<k;j++){
       salida += (QString::number(j))+","+(QString::number(knn[j]))+";";
       cout<<knn[j]<<","<<kni[j]<<endl;
       strResult=QString::number(knn[j])+","+QString::number(kni[j]);
       ui->listResultados->addItem(strResult);
    }
    db.close();
    db2.close();
    r=0;
    }
    }

    if(ui->dataBase->currentText()=="MovieRatings"){

    }

    if(ui->dataBase->currentText()=="MovieLensSmall"){

    }

    if(ui->dataBase->currentText()=="Libros"){

    }

}
