#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <QVector>
#include <stdlib.h>
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
//movie_ratings
QVector<QString>indexUsers_={"Patrick C","Heather","Bryan","Patrick T","Thomas","aaron","vanessa","greg","brian","ben","Katherine","Jonathan","Zwe","Erin","Chris","Zak","Matt","Chris","Josh","Amy","Valerie","Gary","Stephen","Jessica","Jeff"};
QVector<QString> indexMovies_={"Alien","Avatar","Blade Runner","Braveheart","Dodgeball","Forest Gump","Gladiator","Jaws","Kazaam","Lord of the Rings","Napolean Dynamite","Old School","Pootie Tang","Pulp Fiction","Scarface","Shawshank Redemption","Snakes on a Plane","Spiderman","Star Wars","The Dark Knight","The Happening","The Matrix","Toy Story","Village","You Got Mail"};
QVector<double>promedioUser_={3.61111,3.93333,3.36364,3.13333,3.68182,3.71429,3.2,4.05556,3.86957,3.75,4,4.05556,3.22727,3.41667,2.875,3.73684,2.66667,3.18182,4.18182,3.05882,3.3913,3.04762,3.33333,3.25,3.63636};
QVector<double>promedioMovie_={3.86111,3.74667,4.0303,4.05965,3.79437,4.3631,4.16842,3.42398,1.92935,3.625,2.875,4.22531,2.13636,4.20098,3.90625,4.8114,2.31111,3.63258,4.79051,4.58204,1.54891,4.21946,4.41333,2.75,1.97576};

QVector<QVector<double>>ratings_={
    {0,0,2,0,5,4,0,0,4,0,0,0,0,0,2,0,0,4,3,0,0,2,5,0,4},
    {4,5,5,4,2,0,4,3,0,3,5,4,4,4,1,5,0,0,4,3,2,1,4,0,4},
    {5,0,0,0,5,4,0,1,5,5,0,0,0,0,5,0,0,3,0,3,3,1,0,0,5},
    {4,0,5,0,4,4,3,4,4,0,3,4,3,4,2,5,0,4,0,3,4,5,5,0,4},
    {5,4,3,2,4,0,4,5,3,4,5,5,3,3,3,3,0,3,0,4,3,4,3,0,3},
    {4,5,4,3,3,0,4,5,5,5,5,5,5,5,3,5,4,5,4,4,5,4,1,4,4},
    {0,5,5,0,4,4,4,5,5,5,3,4,3,0,3,5,0,3,4,0,3,3,4,0,4},
    {0,5,4,0,4,0,2,3,3,1,0,3,2,3,2,0,0,5,5,3,2,4,2,3,5},
    {2,0,3,5,2,0,0,0,1,0,2,2,2,1,1,1,0,0,0,1,1,1,0,1,1},
    {4,4,3,2,0,5,2,3,5,2,4,4,3,4,3,4,1,4,0,0,5,3,5,3,3},
    {3,4,1,1,5,1,4,4,4,4,2,3,3,2,1,1,3,1,0,2,5,4,2,2,3},
    {3,0,4,5,5,0,3,5,4,4,0,5,4,0,5,5,0,4,0,3,3,5,0,2,3},
    {0,0,1,1,0,0,1,0,1,1,0,0,2,0,3,0,0,1,0,0,0,0,0,0,5},
    {0,0,4,0,4,3,0,4,5,4,0,5,4,0,5,5,0,5,0,4,3,3,3,4,3},
    {0,4,0,0,5,4,4,4,0,4,0,4,0,0,3,3,0,2,0,0,4,3,0,0,0},
    {5,0,5,0,0,5,0,5,5,5,0,0,4,0,4,0,0,4,0,2,5,5,0,0,0},
    {4,1,2,0,4,0,0,0,3,2,0,0,1,0,3,0,1,3,0,2,1,2,0,2,1},
    {4,3,4,4,5,3,0,4,4,4,5,3,4,3,2,3,3,2,4,3,5,2,3,3,4},
    {5,5,4,5,5,3,3,5,5,5,5,5,4,3,4,5,0,5,5,0,5,5,5,5,5},
    {4,5,5,4,4,0,0,4,4,5,0,5,5,0,3,5,0,4,4,4,5,0,4,5,5},
    {1,0,0,0,1,0,0,0,2,0,0,0,1,0,1,1,0,0,0,0,1,0,1,0,0},
    {3,4,3,5,4,4,4,4,5,4,4,5,4,4,4,5,0,2,5,5,4,2,5,0,5},
    {4,3,3,4,4,5,4,5,5,5,5,5,4,5,3,4,4,4,4,4,5,4,4,5,5},
    {0,2,3,1,1,0,2,0,4,3,0,0,4,0,3,4,0,1,4,0,2,0,2,0,2},
    {1,0,1,1,1,3,0,0,3,0,0,2,2,0,0,2,0,1,0,2,2,1,2,0,2}};

//end data movie_ratings
const float INF = numeric_limits<float>::infinity();
float resultado=0;//para resultado de distancias
string xlinea;
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

double MainWindow::fun_euclideana(QVector<double>data1,QVector<double>data2)
{
    resultado=0;
    for(int i=1;i<data1.size();i++){
        resultado=resultado+pow(data1[i]+data2[i],2);
    }
    resultado=pow(resultado,0.5);
    return resultado;
}
double MainWindow::fun_manhatan(QVector<double>data1,QVector<double>data2)
{
    resultado=0;
    for(int i=1;i<data1.size();i++){
        resultado=resultado+abs(data1[i]-data2[i]);
    }
    return resultado;
}
double MainWindow::fun_pearson(QVector<double>data1,QVector<double>data2)
{
    float suma1 = 0, suma2 = 0, suma3 = 0, suma4 = 0, suma5 = 0;
        float multi = 0, raiz1 = 0, raiz2 = 0, rpta = 0;
        for(int i = 1; i < data1.size(); ++i)
        {
            if(data1[i] != INF && data2[i] != INF)
            {
                suma1 += data1[i] * data2[i];
                suma2 += data1[i];
                suma3 += data2[i];
                suma4 += data1[i];
                suma5 += data2[i];
            }
        }
        suma4=pow(suma4,2);
        suma5=pow(suma5,2);
        multi += (suma2 * suma3)/data1.size();
        raiz1 += suma4 - (pow(suma2,2))/data1.size();
        raiz2 += suma5 - (pow(suma3,2))/data1.size();
        raiz1 = sqrt(raiz1);
        raiz2 = sqrt(raiz2);
        return rpta = (suma1 - multi)/(raiz1*raiz2);
}
int MainWindow::buscar(QVector<QString>data1,QString dato)
{
    int resultado=-1;
    for( int i = 0; i < data1.size(); i++ ) {
        if( data1[i]==dato)
            resultado=i;
     }
     if (resultado!=0)
         return resultado;
     else
         return -1;
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
        bool ok;
        QString user_1 = ui->user1->text();
        QString user_2 = ui->user2->text();
        int pos1=buscar(indexUsers_,user_1);
        int pos2=buscar(indexUsers_,user_2);

        if (pos1!=-1 && pos2!=-1){
            cout<<fun_manhatan(ratings_[pos1],ratings_[pos2])<<endl;
        }
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
    db.open("C:/Users/Manuel/Documents/GitHub/TBD-Grupo/MovieRatings/Movie_Ratings.csv");
    while(db.good()){
        getline(db,xlinea,',');

        }
    db.close();
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

double MainWindow::coseno_ajustar_mr(QVector<QVector<double>>ratings_,QVector<double>promedioUser_,int indexMovie1,int indexMovie2)
{
    double sumNum=0, sumDenMov1=0, sumDenMov2=0,result;
    for(int j=0;j<ratings_.size();j++){
        if(ratings_[indexMovie1][j]!=0 && ratings_[indexMovie2][j]!=0){
            sumNum += (ratings_[indexMovie1][j]-promedioUser_[j])*(ratings_[indexMovie2][j]-promedioUser_[j]);
            sumDenMov1 += pow(ratings_[indexMovie1][j]-promedioUser_[j],2);
            sumDenMov2 += pow(ratings_[indexMovie2][j]-promedioUser_[j],2);
        }
    }
    sumDenMov1 = sqrt(sumDenMov1);
    sumDenMov2 = sqrt(sumDenMov2);
    result=sumNum/(sumDenMov1*sumDenMov2);
    return result;
}
void MainWindow::on_cosenoAjustado_clicked()
{
    ui->listResultados->clear();

    //MOVIE RATINGS
    if(ui->dataBase->currentText()=="MovieRatings"){
    string indexUsers[25]={"Patrick C","Heather","Bryan","Patrick T","Thomas","aaron","vanessa","greg","brian","ben","Katherine","Jonathan","Zwe","Erin","Chris","Zak","Matt","Chris","Josh","Amy","Valerie","Gary","Stephen","Jessica","Jeff"};
    string indexMovies[25]={"Alien","Avatar","Blade Runner","Braveheart","Dodgeball","Forest Gump","Gladiator","Jaws","Kazaam","Lord of the Rings","Napolean Dynamite","Old School","Pootie Tang","Pulp Fiction","Scarface","Shawshank Redemption","Snakes on a Plane","Spiderman","Star Wars","The Dark Knight","The Happening","The Matrix","Toy Story","Village","You Got Mail"};

    double promedioUser[25]={3.61111,3.93333,3.36364,3.13333,3.68182,3.71429,3.2,4.05556,3.86957,3.75,4,4.05556,3.22727,3.41667,2.875,3.73684,2.66667,3.18182,4.18182,3.05882,3.3913,3.04762,3.33333,3.25,3.63636};
    double promedioMovie[25]={3.86111,3.74667,4.0303,4.05965,3.79437,4.3631,4.16842,3.42398,1.92935,3.625,2.875,4.22531,2.13636,4.20098,3.90625,4.8114,2.31111,3.63258,4.79051,4.58204,1.54891,4.21946,4.41333,2.75,1.97576};

    /*Calculo del promedio de puntaje dado por los usuarios
      int cont=0;
    for(int i=0;i<25;i++){
        cont=0;
        for(int j=0;j<25;j++){
            if(ratings[j][i]!=0){
                promedioUser[i]+=ratings[j][i];
                cont++;
            }
        }
        promedioUser[i]=promedioUser[i]/cont;
        cout<<promedioUser[i]<<",";
    }*/

    if(ui->tipoCosenoAjustado->currentText()=="prod"){
        string strmovie1 = ui->user1->text().toStdString();
        string strmovie2 = ui->user2->text().toStdString();
        int indexMovie1=-1,indexMovie2=-1;
        for(int i=0;i<25;i++){
            if(indexMovies[i]==strmovie1){
                indexMovie1=i;
            }
            if(indexMovies[i]==strmovie2){
                indexMovie2=i;
            }
        }

    if(indexMovie1!=-1 && indexMovie2!=-1){
        double sumNum=0, sumDenMov1=0, sumDenMov2=0,result;
        for(int j=0;j<25;j++){
            if(ratings[indexMovie1][j]!=0 && ratings[indexMovie2][j]!=0){
                sumNum += (ratings[indexMovie1][j]-promedioUser[j])*(ratings[indexMovie2][j]-promedioUser[j]);
                sumDenMov1 += pow(ratings[indexMovie1][j]-promedioUser[j],2);
                sumDenMov2 += pow(ratings[indexMovie2][j]-promedioUser[j],2);
            }
        }
        sumDenMov1 = sqrt(sumDenMov1);
        sumDenMov2 = sqrt(sumDenMov2);
        result=sumNum/(sumDenMov1*sumDenMov2);
        //cout<<result<<endl;
        //cout<<sumNum<<endl;
        //cout<<sumDenMov1<<endl;
        //cout<<sumDenMov2<<endl;
        ui->listResultados->addItem(QString::number(result));
    }
    else{
        ui->listResultados->addItem("No movie");
    }
    }

    if(ui->tipoCosenoAjustado->currentText()=="user"){

        string struser1 = ui->user1->text().toStdString();
        string struser2 = ui->user2->text().toStdString();
        int indexUser1=-1,indexUser2=-1;
        for(int i=0;i<25;i++){
            if(indexUsers[i]==struser1){
                indexUser1=i;
            }
            if(indexUsers[i]==struser2){
                indexUser2=i;
            }
        }

        if(indexUser1!=-1 && indexUser2!=-1){
            double sumNum=0, sumDenMov1=0, sumDenMov2=0,result;
            for(int i=0;i<25;i++){
                if(ratings[i][indexUser1]!=0 && ratings[i][indexUser2]!=0){
                    sumNum += (ratings[i][indexUser1]-promedioMovie[i])*(ratings[i][indexUser2]-promedioMovie[i]);
                    sumDenMov1 += pow(ratings[i][indexUser1]-promedioMovie[i],2);
                    sumDenMov2 += pow(ratings[i][indexUser2]-promedioMovie[i],2);
                }
            }
            sumDenMov1 = sqrt(sumDenMov1);
            sumDenMov2 = sqrt(sumDenMov2);
            result=sumNum/(sumDenMov1*sumDenMov2);
            //cout<<result<<endl;
            //cout<<sumNum<<endl;
            //cout<<sumDenMov1<<endl;
            //cout<<sumDenMov2<<endl;
            ui->listResultados->addItem(QString::number(result));
        }
        else{
            ui->listResultados->addItem("No user");
        }
    }
    }
    //LIBROS
    if(ui->dataBase->currentText()=="Libros"){
        string struser1;
        string struser2;
        char cadena[20];
        float ratingsuser1[2600];
        int indexuser1[2600],contuser1=0;
        float ratingsuser2[2600];
        int indexuser2[2600],contuser2=0;
        double promrating[2600];
        int indexprom[2600],contprom=0;
        string book, rating, user;
        string bookh;

        //obteniendo los ratings de user 1 y user 2
        struser1 = ui->user1->text().toStdString();
        struser2 = ui->user2->text().toStdString();
        db.open("E:/Proyectos/QT/TBD/TBD/Book/Ratings.csv");
        for(int i=0;i<433665;i++){//433665
            db>>cadena;
            user=cadena;
            db>>cadena;
            book=cadena;
            db>>cadena;
            rating=cadena;
            if(book==struser1){
                //dbs<<user<<" "<<rating<<endl;
                indexuser1[contuser1]=stoi(user);
                ratingsuser1[contuser1]=stof(rating);
                //ui->listResultados->addItem(QString::number(indexuser1[contuser1]));
                contuser1++;
            }
            if(book==struser2){
                indexuser2[contuser2]=stoi(user);
                ratingsuser2[contuser2]=stof(rating);
                //ui->listResultados->addItem(QString::number(indexuser2[contuser2]));
                contuser2++;

            }
        }
        db.close();
        //obteniendo de promedios necesarios
        for(int i=0;i<contuser1;i++){
            for(int j=0;j<contuser2;j++){
                if(indexuser1[i]==indexuser2[j]){
                    indexprom[contprom]=indexuser1[i];
                    contprom++;
                }
            }
        }

        //calculando promedios 0002005018  0887841740
        double sum=0;
        int contuserprom=0;
        for(int p=0;p<contprom;p++){
            db.open("E:/Proyectos/QT/TBD/TBD/Book/Ratings.csv");
            for(int i=0;i<1149766;i++){//1149766
                db>>cadena;
                user=cadena;
                db>>cadena;
                book=cadena;
                db>>cadena;
                rating=cadena;
                if(stoi(user)==indexprom[p]){

                    sum+=stof(rating);
                    contuserprom++;
                }
            }
            sum=sum/contuserprom;
            promrating[p]=sum;
            db.close();
        }

        //0002005018  0887841740    0425105334 0451524934
        //calculando el coseno ajustado
        double result=0;
        double sumNum=0;
        double sumDenMov1=0;
        double sumDenMov2=0;
        int contp=0;
        for(int i=0;i<contuser1;i++){
            for(int j=0;j<contuser2;j++){
                if(indexuser1[i]==indexuser2[j]){
                    sumNum += (ratingsuser1[i]-promrating[contp])*(ratingsuser2[j]-promrating[contp]);
                    sumDenMov1 += pow(ratingsuser1[i]-promrating[contp],2);
                    sumDenMov2 += pow(ratingsuser2[j]-promrating[contp],2);
                    //ui->listResultados->addItem(QString::number(indexuser1[i]));
                    contp++;
                }
            }
        }
        sumDenMov1 = sqrt(sumDenMov1);
        sumDenMov2 = sqrt(sumDenMov2);
        result=sumNum/(sumDenMov1*sumDenMov2);
        //cout<<result<<endl;
        //cout<<sumNum<<endl;
        //cout<<sumDenMov1<<endl;
        //cout<<sumDenMov2<<endl;
        ui->listResultados->addItem(QString::number(result));
    }
    //MOVIELENS
    if(ui->dataBase->currentText()=="MovieLensSmall"){
        db.open("E:/Proyectos/QT/TBD/TBD/MovieLens/ratingschange.csv");
        string strmovie1,strmovie2;
        strmovie1 = ui->user1->text().toStdString();
        strmovie2 = ui->user2->text().toStdString();
        char cadena[10];
        string user,movie,rating;
        int indexmovie1[2600],contmovie1=0;
        int indexmovie2[2600],contmovie2=0;
        int indexprom[2600],contprom=0;
        double ratingmovie1[2600],ratingmovie2[2600],promrating[2600];

        for(int i=0;i<100836;i++){
            db>>cadena;
            user=cadena;
            db>>cadena;
            movie=cadena;
            db>>cadena;
            rating=cadena;
            if(movie==strmovie1){
                //dbs<<user<<" "<<rating<<endl;
                indexmovie1[contmovie1]=stoi(user);
                ratingmovie1[contmovie1]=stof(rating);
                //ui->listResultados->addItem(QString::number(indexuser1[contuser1]));
                contmovie1++;
            }
            if(movie==strmovie2){
                indexmovie2[contmovie1]=stoi(user);
                ratingmovie2[contmovie1]=stof(rating);
                //ui->listResultados->addItem(QString::number(indexuser2[contuser2]));
                contmovie2++;
            }
        }
        db.close();
        //obteniendo cantidad de promedios necesarios
        for(int i=0;i<contmovie1;i++){
            for(int j=0;j<contmovie2;j++){
                if(indexmovie1[i]==indexmovie2[j]){
                    indexprom[contprom]=indexmovie1[i];
                    contprom++;
                }
            }
        }

        //calculando promedios
        double sum=0;
        int contuserprom=0;
        for(int p=0;p<contprom;p++){
            db.open("E:/Proyectos/QT/TBD/TBD/MovieLens/ratingschange.csv");
            for(int i=0;i<1149766;i++){//1149766
                db>>cadena;
                user=cadena;
                db>>cadena;
                movie=cadena;
                db>>cadena;
                rating=cadena;
                if(stoi(user)==indexprom[p]){
                    sum+=stof(rating);
                    contuserprom++;
                }
            }
            sum=sum/contuserprom;
            promrating[p]=sum;
            db.close();
        }
        //calculando el coseno ajustado
        double result=0;
        double sumNum=0;
        double sumDenMov1=0;
        double sumDenMov2=0;
        int contp=0;
        for(int i=0;i<contmovie1;i++){
            for(int j=0;j<contmovie2;j++){
                if(indexmovie1[i]==indexmovie2[j]){
                    sumNum += (ratingmovie1[i]-promrating[contp])*(ratingmovie2[j]-promrating[contp]);
                    sumDenMov1 += pow(ratingmovie1[i]-promrating[contp],2);
                    sumDenMov2 += pow(ratingmovie2[j]-promrating[contp],2);
                    //ui->listResultados->addItem(QString::number(indexuser1[i]));
                    contp++;
                }
            }
        }
        sumDenMov1 = sqrt(sumDenMov1);
        sumDenMov2 = sqrt(sumDenMov2);
        result=sumNum/(sumDenMov1*sumDenMov2);
        //cout<<result<<endl;
        //cout<<sumNum<<endl;
        //cout<<sumDenMov1<<endl;
        //cout<<sumDenMov2<<endl;
        //ui->listResultados->addItem(QString::number(contprom));
        ui->listResultados->addItem(QString::number(result));
    }
}

void MainWindow::on_Matriz_clicked()
{
    ui->listResultados->clear();
    if(ui->dataBase->currentText()=="MovieRatings"){
        double promedioUser[25]={3.61111,3.93333,3.36364,3.13333,3.68182,3.71429,3.2,4.05556,3.86957,3.75,4,4.05556,3.22727,3.41667,2.875,3.73684,2.66667,3.18182,4.18182,3.05882,3.3913,3.04762,3.33333,3.25,3.63636};
        double promedioMovie[25]={3.86111,3.74667,4.0303,4.05965,3.79437,4.3631,4.16842,3.42398,1.92935,3.625,2.875,4.22531,2.13636,4.20098,3.90625,4.8114,2.31111,3.63258,4.79051,4.58204,1.54891,4.21946,4.41333,2.75,1.97576};
        double matrizCoseno[300];//n(n-1)/2

        if(ui->tipoCosenoAjustado->currentText()=="prod"){
            ui->tableWidget->setRowCount(24);
            ui->tableWidget->setColumnCount(24);
            string indexMovies[25]={"Alien","Avatar","Blade Runner","Braveheart","Dodgeball","Forest Gump","Gladiator","Jaws","Kazaam","Lord of the Rings","Napolean Dynamite","Old School","Pootie Tang","Pulp Fiction","Scarface","Shawshank Redemption","Snakes on a Plane","Spiderman","Star Wars","The Dark Knight","The Happening","The Matrix","Toy Story","Village","You Got Mail"};
            QStringList moviesHorizontal;
            QStringList moviesVertical;
            for(int i=0;i<24;i++){
                moviesVertical<<QString::fromStdString(indexMovies[i]);
                moviesHorizontal<<QString::fromStdString(indexMovies[i+1]);
            }
            ui->tableWidget->setHorizontalHeaderLabels(moviesHorizontal);
            ui->tableWidget->setVerticalHeaderLabels(moviesVertical);
            int cont=0;
            double sumNum=0, sumDenMov1=0, sumDenMov2=0,result=0;
            for(int i=0;i<24;i++){
                for(int k=i+1;k<25;k++){
                    for(int j=0;j<25;j++){
                        if(ratings[i][j]!=0 && ratings[k][j]!=0){
                            sumNum += (ratings[i][j]-promedioUser[j])*(ratings[k][j]-promedioUser[j]);
                            sumDenMov1 += pow(ratings[i][j]-promedioUser[j],2);
                            sumDenMov2 += pow(ratings[k][j]-promedioUser[j],2);
                        }
                    }
                    sumDenMov1 = sqrt(sumDenMov1);
                    sumDenMov2 = sqrt(sumDenMov2);
                    result=sumNum/(sumDenMov1*sumDenMov2);
                    ui->tableWidget->setItem(i,k-1,new QTableWidgetItem(QString::number(result)));
                    //cout<<result<<",";
                    matrizCoseno[cont]=result;
                    cont++;
                    sumNum=0, sumDenMov1=0, sumDenMov2=0,result=0;
                }
                //cout<<endl;
            }

        }

        if(ui->tipoCosenoAjustado->currentText()=="user"){
            ui->tableWidget->setRowCount(24);
            ui->tableWidget->setColumnCount(24);
            string indexUsers[25]={"Patrick C","Heather","Bryan","Patrick T","Thomas","aaron","vanessa","greg","brian","ben","Katherine","Jonathan","Zwe","Erin","Chris","Zak","Matt","Chris","Josh","Amy","Valerie","Gary","Stephen","Jessica","Jeff"};
            QStringList usersVertical;
            QStringList usersHorizontal;
            for(int i=0;i<24;i++){
                usersVertical<<QString::fromStdString(indexUsers[i]);
                usersHorizontal<<QString::fromStdString(indexUsers[i+1]);
            }
            ui->tableWidget->setHorizontalHeaderLabels(usersHorizontal);
            ui->tableWidget->setVerticalHeaderLabels(usersVertical);
            int cont=0;
            double sumNum=0, sumDenMov1=0, sumDenMov2=0,result=0;
            for(int i=0;i<24;i++){
                for(int k=i+1;k<25;k++){
                    for(int j=0;j<25;j++){
                        if(ratings[j][i]!=0 && ratings[j][k]!=0){
                            sumNum += (ratings[j][i]-promedioMovie[j])*(ratings[j][k]-promedioMovie[j]);
                            sumDenMov1 += pow(ratings[j][i]-promedioMovie[j],2);
                            sumDenMov2 += pow(ratings[j][k]-promedioMovie[j],2);
                        }
                    }
                    sumDenMov1 = sqrt(sumDenMov1);
                    sumDenMov2 = sqrt(sumDenMov2);
                    result=sumNum/(sumDenMov1*sumDenMov2);
                    ui->tableWidget->setItem(i,k-1,new QTableWidgetItem(QString::number(result)));
                    //cout<<result<<",";
                    matrizCoseno[cont]=result;
                    cont++;
                    sumNum=0, sumDenMov1=0, sumDenMov2=0,result=0;
                }
                //cout<<endl;
            }
        }
    }
    if(ui->dataBase->currentText()=="MovieLensSmall"){

    }

}

void MainWindow::on_predecir_clicked()
{
    ui->listResultados->clear();
    if(ui->dataBase->currentText()=="MovieRatings"){
        //normalizar los puntajes
        double ratingsNorm[25][25];
        for (int i=0;i<25;i++){
            for(int j=0;j<25;j++){
                if(ratings[i][j]!=0){
                    ratingsNorm[i][j]=(2*(ratings[i][j]-1)-(4))/4;
                    //ui->listResultados->addItem(QString::number(ratingsNorm[i][j]));
                }
                else{
                    ratingsNorm[i][j]=-2;
                }
            }
        }
        //Matriz de similitud
        double matrizCoseno[25][25];//n(n-1)/2
        double promedioUser[25]={3.61111,3.93333,3.36364,3.13333,3.68182,3.71429,3.2,4.05556,3.86957,3.75,4,4.05556,3.22727,3.41667,2.875,3.73684,2.66667,3.18182,4.18182,3.05882,3.3913,3.04762,3.33333,3.25,3.63636};

        string indexUsers[25]={"Patrick C","Heather","Bryan","Patrick T","Thomas","aaron","vanessa","greg","brian","ben","Katherine","Jonathan","Zwe","Erin","Chris","Zak","Matt","Chris","Josh","Amy","Valerie","Gary","Stephen","Jessica","Jeff"};
        string indexMovies[25]={"Alien","Avatar","Blade Runner","Braveheart","Dodgeball","Forest Gump","Gladiator","Jaws","Kazaam","Lord of the Rings","Napolean Dynamite","Old School","Pootie Tang","Pulp Fiction","Scarface","Shawshank Redemption","Snakes on a Plane","Spiderman","Star Wars","The Dark Knight","The Happening","The Matrix","Toy Story","Village","You Got Mail"};

        int cont=0;
        double sumNum=0, sumDenMov1=0, sumDenMov2=0,result=0;
        for(int i=0;i<25;i++){
            for(int k=0;k<25;k++){
                for(int j=0;j<25;j++){
                    if(ratings[i][j]!=0 && ratings[k][j]!=0){
                        sumNum += (ratings[i][j]-promedioUser[j])*(ratings[k][j]-promedioUser[j]);
                        sumDenMov1 += pow(ratings[i][j]-promedioUser[j],2);
                        sumDenMov2 += pow(ratings[k][j]-promedioUser[j],2);
                    }
                }
                sumDenMov1 = sqrt(sumDenMov1);
                sumDenMov2 = sqrt(sumDenMov2);
                result=sumNum/(sumDenMov1*sumDenMov2);
                //ui->tableWidget->setItem(i,k,new QTableWidgetItem(QString::number(result)));
                //ui->tableWidget->setItem(k-1,i,new QTableWidgetItem(QString::number(result)));
                //cout<<result<<",";
                matrizCoseno[i][k]=result;
                cont++;
                sumNum=0, sumDenMov1=0, sumDenMov2=0,result=0;
            }
            //cout<<endl;
        }
        string struser = ui->user1->text().toStdString();
        string strmovie = ui->user2->text().toStdString();
        int indexUser=-1,indexMovie=-1;
        for(int i=0;i<25;i++){
            if(indexMovies[i]==strmovie){
                indexMovie=i;
            }
        }
        for(int i=0;i<25;i++){
            if(indexUsers[i]==struser){
                indexUser=i;
            }
        }
        if(indexUser>=0 && indexMovie>=0){
            double sumNumPred=0;
            double sumDenPred=0;
            double resultPred=0;
            for(int i=0;i<25;i++){
                if(ratingsNorm[i][indexUser]>-2){
                    sumNumPred += ratingsNorm[i][indexUser]*matrizCoseno[indexMovie][i];
                    sumDenPred += abs(matrizCoseno[indexMovie][i]);
                }
            }
            resultPred=sumNumPred/sumDenPred;
            //desnormalizar
            resultPred=((resultPred+1)*(4)/2)+1;
            ui->listResultados->addItem(QString::number(resultPred));

        }
        else{
            ui->listResultados->addItem("User o Movie no encontrados");
        }

    }

}
