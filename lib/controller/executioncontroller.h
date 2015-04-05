/**
 * @file    executioncontroller.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Controlador para la ejecución del programa.
 *
 * @section DESCRIPTION
 * @details
 *
 */
#ifndef EXECUTIONCONTROLLER_H
#define EXECUTIONCONTROLLER_H

#include "../globalConf.h"

#if TEST_CHECKING
   #include "../../test/controller/executioncontroller_spec.h"
#endif

#include <QApplication>
#include "../view/consoleview.h"

#if TEST_CHECKING
   #include <cppunit/TestSuite.h>
   #include <cppunit/Test.h>
   #include <cppunit/ui/text/TestRunner.h>

   #include "../../test/view/mainwindow_spec.h"
   #include "../../test/controller/cameracontroller_spec.h"
   #include "../../test/controller/executioncontroller_spec.h"
#else

   #include "../view/mainwindow.h"
   #include "../controller/cameracontroller.h"

   #include <opencv2/opencv.hpp>

   #include <QtGui>
   #include<QTimer>
   #include <QSplashScreen>

   #include <string>

   using namespace cv;

#endif

#include "../view/selectorcamaras.h"

/**
 * @class ExecutionController
 * @brief The ExecutionController class
 */
class ExecutionController {
   public:
      ExecutionController();
      ~ExecutionController();

      void cargar(int argc, char *argv[]);
      int ejecutar ();


   private:
      QApplication* qtApp_;

      void vaciarMemoria();
      void salir();
      bool comprobarEstado();

#if TEST_CHECKING
      CppUnit::TextUi::TestRunner* codeTester_;
      friend class ExecutionController_spec;
#else
      MainWindow* qtVentanaPrincipal_;
      QSplashScreen* qtSplash_;
      SelectorCamaras* qtSelecCam_;

      CameraController* controladorCamara_;
      VideoCaptureW* camaraActual_;

#endif
};




#endif // EXECUTIONCONTROLLER_H
