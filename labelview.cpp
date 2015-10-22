#include "labelview.h"

LabelView::LabelView()
{
    images = new Mat[NUM];
    colorImg = new Mat[NUM];

    for(int i=0;i<256;i++)
        colorTable.push_back( qRgb(i,i,i) );
}

void LabelView::readin(QString fileName)
{
    freopen(fileName.toStdString().c_str(),"r",stdin);

    // initial
    int num = NUM_PIX*NUM_PIX;
    array = new double*[NUM];
    for(int i=0;i<NUM;i++)
        array[i] = new double[num];

    double tmp;
    for(int t = 0;t < num;t++)
    {
        // read the index num
        scanf("%lf",&tmp);
        for(int i=0;i<NUM;i++)
            scanf("%lf",&array[i][t]);
    }

    for(int i=0;i<NUM;i++)
    {
        images[i] = Mat(Size(NUM_PIX,NUM_PIX),CV_64FC1,array[i]);
//        cvConvertImage();
    }

    fclose(stdin);
}

void LabelView::proc()
{
    for(int i=0;i<NUM;i++)
    {
        normalize(images[i],images[i],0,255,NORM_MINMAX,CV_64FC1,Mat());
        // Interpolation
        resize(images[i],images[i],Size(LEN,LEN));

        images[i].convertTo(images[i],CV_8UC1);
        // colormap
        applyColorMap(images[i], colorImg[i], COLORMAP_JET);

        cvtColor(colorImg[i],colorImg[i],CV_BGR2RGB);

    }

}

QImage LabelView::getImg(int index)
{
    if(colorImg[index].channels() == 3)
    {
        QImage dest = QImage((const uchar *)colorImg[index].data,
                             colorImg[index].cols,
                             colorImg[index].rows,
                             colorImg[index].step,
                             QImage::Format_RGB888);
        dest.bits();
        return dest;
    }
    else
    {
        QImage dest = QImage((const uchar *)colorImg[index].data,
                             colorImg[index].cols,
                             colorImg[index].rows,
                             colorImg[index].step,
                             QImage::Format_Indexed8);
        dest.setColorTable(colorTable);
        dest.bits();
        return dest;
    }
}

