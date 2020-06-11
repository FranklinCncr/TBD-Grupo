#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
