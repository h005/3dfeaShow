#ifndef LABELVIEW_H
#define LABELVIEW_H

#include <opencv.hpp>
#include <QString>
#include <QImage>
#include <QVector>
#include <QRgb>
#include <QDebug>

#define NUM 12
#define NUM_PIX 32
#define LEN 1024

using namespace cv;

class LabelView
{
public:
    LabelView();
    void readin(QString fileName);
    void proc(QString path,QString *fealist);
    QImage getImg(int index);

private:
    Mat *images;
    Mat *colorImg;
    double **array;
    QVector<QRgb> colorTable;
};

#endif // LABELVIEW_H
