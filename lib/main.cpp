/**
 * @file main.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date   Noviembre, 2014
 * @brief Conjunto de herramientas para webCams
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de ejecución principal. Se encarga de
 * discernir si ejecutar o no los test implementados.
 * Cargar la interfaz de QT y mostrar o no la ventana
 * principal del programa.
 */
#include <QApplication>
#include "view/mainwindow.h"

#include <opencv2/opencv.hpp>
#include <iostream>

#include "globalConf.h"

#if TEST_CHECKING
   #include <cppunit/TestSuite.h>
   #include <cppunit/Test.h>
   #include <cppunit/ui/text/TestRunner.h>

   #include "../test/view/mainwindow_spec.h"
#else

#endif

using namespace std;
using namespace cv;

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
   int result = 0;
   cout << "****************************************************************" << endl;
   cout << "* Iniciado CamTool.                                            *" << endl;
   cout << "****************************************************************" << endl;

#if TEST_CHECKING
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "* Modo testeo activado.                                        *" << endl;
   cout << "*    + Iniciando test...                                       *" << endl;

   CppUnit::TextUi::TestRunner codeTester; /* Crear el objeto de CppUnit que ejecutará las pruebas */
   codeTester.addTest(mainwindow_spec::suite());
   codeTester.run();
#else
   cout << "*--------------------------------------------------------------*" << endl;
   cout << "* Sin modo testeo.                                             *" << endl;
   cout << "*    + Iniciando ejecución...                                  *" << endl;

   QApplication qtApp(argc, argv);
   //MainWindow w;
   //w.show();

   cvNamedWindow("Camera_Output", 1); //Create window
   CvCapture* capture = cvCaptureFromCAM(CV_CAP_ANY); //Capture using any camera connected to your system
   char key;

   while(1){ //Create infinte loop for live streaming
      IplImage* frame = cvQueryFrame(capture); //Create image frames from capture
      cvShowImage("Camera_Output", frame); //Show image frames on created window
      key = cvWaitKey(10); //Capture Keyboard stroke
      if (char(key) == 27){
         break; //If you hit ESC key loop will break.
      }
   }
   cvReleaseCapture(&capture); //Release capture.
   cvDestroyWindow("Camera_Output"); //Destroy Window

   //result = qtApp.exec();
#endif

   cout << "*--------------------------------------------------------------*" << endl;
   cout << "* Finalizando CamTool...                                       *" << endl;
   cout << "****************************************************************" << endl;

   return result; //a.exec();
}
