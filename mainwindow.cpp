#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    labelview = new LabelView();
    index = 0;
    ui->open->setShortcut(Qt::Key_O);
    ui->process->setShortcut(Qt::Key_P);
    ui->prev->setShortcut(Qt::Key_Left);
    ui->next->setShortcut(Qt::Key_Right);
    fealist = new QString[NUM];
    const char *fea[]={"ProjectArea",
              "VisSurfaceArea",
              "ViewpointEntropy",
              "SilhouetteLength",
              "silhouetteCurvature",
              "silhouetteCurvatureExtrema",
              "MaxDepth",
              "DepthDistribute",
              "MeanCurvature",
              "GaussianCurvature",
              "MeshSaliency",
              "AbovePreference"};
    for(int i=0;i<NUM;i++)
        fealist[i] = QString(fea[i]);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,
                   tr("Open 3df"),".",
                   tr("3df Files(*.3df)"));
//    qDebug()<<fileName<<endl;
    if(fileName == NULL)
        ui->fileInfo->setText("fail to load");
    else
    {
        ui->fileInfo->setText(fileName);
        labelview->readin(fileName);
        showImage(index);
    }

}

void MainWindow::on_process_clicked()
{
    QString path;
//    qDebug()<<fileName<<endl;
    int pos = fileName.lastIndexOf('/');
    path = fileName.left(pos+1);
//    qDebug()<<path<<endl;

    labelview->proc(path,fealist);
    showImage(index);
}

void MainWindow::showImage(int index)
{
    QImage img = labelview->getImg(index);
    QPixmap pixmap = QPixmap::fromImage(img);
    ui->label->setPixmap(pixmap);
    ui->fileInfo->setText(fealist[index]);
}



void MainWindow::on_prev_clicked()
{
    index--;
    if(index < 0)
        index += NUM;
    showImage(index);
}



void MainWindow::on_next_clicked()
{
    index++;
    index = index % NUM;
    showImage(index);
}
