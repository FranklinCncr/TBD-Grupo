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

    float fun_euclideana(QVector<float>,QVector<float>);
    float fun_manhatan(QVector<float>,QVector<float>);
    float fun_cosenoajustado(QVector<float>,QVector<float>);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
