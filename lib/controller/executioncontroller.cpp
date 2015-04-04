/**
 * @file    executioncontroller.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Controlador para la ejecución del programa.
 *
 * @section DESCRIPTION
 * @details
 *
 */
#include "./lib/controller/executioncontroller.h"

/**
 * @brief ExecutionController::ExecutionController
 */
ExecutionController::ExecutionController() {
   qtApp_ = NULL;

#if TEST_CHECKING
   codeTester_ = NULL;
#else
   qtVentanaPrincipal_ = NULL;
#endif
}

ExecutionController::~ExecutionController() {
   if (qtApp_ != NULL) {
      delete qtApp_;
   }
   qtApp_ = NULL;

#if TEST_CHECKING
   if (codeTester_ != NULL) {
      delete codeTester_;
   }
   codeTester_ = NULL;
#else
   if (qtVentanaPrincipal_ != NULL) {
      delete qtVentanaPrincipal_;
   }
   qtVentanaPrincipal_ = NULL;
#endif

}

int ExecutionController::ejecutar() {
   int result = 0;

#if TEST_CHECKING
   int res2 = codeTester_->run();
   result = res2 - 1;
#else

   ConsoleView::showHeaderExec ();

   //QApplication qtApp(argc, argv);
   //MainWindow w;
   //w.show();

   qtVentanaPrincipal_->show();

   //cvNamedWindow("Camera_Output", 1); //Create window
   //CvCapture* capture = cvCaptureFromCAM(CV_CAP_ANY); //Capture using any camera connected to your system
   //char key;

   /*while(1){ //Create infinte loop for live streaming
      IplImage* frame = cvQueryFrame(capture); //Create image frames from capture
      cvShowImage("Camera_Output", frame); //Show image frames on created window
      key = cvWaitKey(10); //Capture Keyboard stroke
      if (char(key) == 27){
         break; //If you hit ESC key loop will break.
      }
   }*/
   //cvReleaseCapture(&capture); //Release capture.
   //cvDestroyWindow("Camera_Output"); //Destroy Window

   result = qtApp_->exec();

#endif

   return result;

}

void ExecutionController::cargar(int argc, char *argv[]) {
   qtApp_ = new QApplication (argc, argv);

#if TEST_CHECKING
   codeTester_ = new CppUnit::TextUi::TestRunner();
   codeTester_->addTest(mainwindow_spec::suite());
   codeTester_->addTest(CameraController_spec::suite());
   codeTester_->addTest(ExecutionController_spec::suite());
#else

   qtVentanaPrincipal_ = new MainWindow();


#endif

}

void ExecutionController::vaciarMemoria() {

}

void ExecutionController::salir() {

}

bool ExecutionController::comprobarEstado() {

}
