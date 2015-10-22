#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include "labelview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_open_clicked();

    void on_process_clicked();

    void on_prev_clicked();

    void on_next_clicked();

private:
    void showImage(int index);

private:
    Ui::MainWindow *ui;
    QString fileName;
    LabelView *labelview;
    int index;
    QString *fealist;

};

#endif // MAINWINDOW_H
