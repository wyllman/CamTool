/**
 * @file    main.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Conjunto de herramientas para webCams
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de ejecución principal. Se encarga de
 * discernir si ejecutar o no los test implementados.
 * Cargar la interfaz de QT y mostrar o no la ventana
 * principal del programa.
 */
#include "globalConf.h"
#include "./view/consoleview.h"

#if TEST_CHECKING
   #include <cppunit/TestSuite.h>
   #include <cppunit/Test.h>
   #include <cppunit/ui/text/TestRunner.h>

   #include "../test/view/mainwindow_spec.h"
   #include "./test/controller/cameracontroller_spec.h"
#else
   #include "view/mainwindow.h"
   #include <opencv2/opencv.hpp>

   using namespace cv;
#endif

#include <QApplication>

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
   QApplication qtApp(argc, argv);
   int result = 0;

   ConsoleView::showHeader ();

#if TEST_CHECKING
   ConsoleView::showHeaderTest ();

   CppUnit::TextUi::TestRunner codeTester; /* Crear el objeto de CppUnit que ejecutará las pruebas */
   codeTester.addTest(mainwindow_spec::suite());
   codeTester.addTest(CameraController_spec::suite());
   int res2 = codeTester.run();
   result = res2 - 1;
#else
   ConsoleView::showHeaderExec ();

   //QApplication qtApp(argc, argv);
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

   ConsoleView::showFooter ();
   return result;
}
