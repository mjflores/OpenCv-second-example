
//==========================================
//  Tecnologias I&H
//
// Programa para:
// 1. Captura imagenes unicamara 
// 2. Captura imagenes estereo 
//==========================================

#include <stdio.h>
#include <iostream>

#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void monocamara();
void bicamara();

#define DIR "/home/deee/Documentos/Mi Software/Mis Programas OpenCv/CapturaEstereo/Imagenes/"

int main(void)
{

//    monocamara();
   bicamara();	

    return 0;
}



void monocamara(void)
{

//    VideoCapture cap(CV_CAP_ANY); // open the default camera
    VideoCapture cap(1); // open the default camera

    if(!cap.isOpened())  // check if we succeeded
        exit(-1);
    
    namedWindow("Imagen",1);
    moveWindow("Imagen", 450, 150);

    char nomImagen[150];
    int k=1;
    for(;;)
    {
	Mat frame;
        cap >> frame; // get a new frame from camera	

       sprintf(nomImagen,DIR"%d.jpg",k);        
       imwrite(nomImagen,frame);

        imshow("Imagen", frame);

        if(cv::waitKey(1) ==27) 
	  break;
        k++;

    }

    // the camera will be deinitialized automatically in VideoCapture destructor
    destroyAllWindows();
}


void bicamara(void)
{
//    VideoCapture cap(CV_CAP_ANY); // open the default camera
    VideoCapture capDer(1); // open the default camera
    VideoCapture capIzq(2); // open the default camera

    if(!capDer.isOpened() || !capIzq.isOpened())  // check if we succeeded
        exit(-1);
    
    namedWindow("ImgDer",1);
    moveWindow("ImgDer",1250 , 150);

    namedWindow("ImgIzq",1);
    moveWindow("ImgIzq", 450, 150);


    char nomImagen1[150];
    char nomImagen2[150];
    int k=1;
    for(;;)
    {
	Mat frameDer;
        capDer>>frameDer; // get a new frame from camera	

	Mat frameIzq;
        capIzq>>frameIzq; // get a new frame from camera

       sprintf(nomImagen1,DIR"Der_%d.jpg",k);
       sprintf(nomImagen2,DIR"Izq_%d.jpg",k);        
        
       imwrite(nomImagen1,frameDer);
       imwrite(nomImagen2,frameIzq);

       imshow("ImgDer", frameDer);
       imshow("ImgIzq", frameIzq);

        if(cv::waitKey(1) ==27) 
	  break;
if(k>100)
	break;
        
k++;

    }

    // the camera will be deinitialized automatically in VideoCapture destructor
    destroyAllWindows();
}


