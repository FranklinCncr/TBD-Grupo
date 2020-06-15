#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <vector>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_manhatan_clicked();

    void on_euclidiana_clicked();

    void on_minkowsky_clicked();

    void on_pearson_clicked();

    void on_coseno_clicked();

    void on_jaccard_clicked();

    void on_knn_clicked();

    void on_cosenoAjustado_clicked();

    void on_Matriz_clicked();

    int buscar(QVector<QString>, QString);
    double fun_euclideana(QVector<double>,QVector<double>);
    double fun_manhatan(QVector<double>,QVector<double>);
    double fun_pearson(QVector<double>,QVector<double>);
    double coseno_ajustar_mr(QVector<QVector<double>>,QVector<double>,int,int);
    QVector<double>Cos_matriz(QVector<QVector<double>>,QVector<double>);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
