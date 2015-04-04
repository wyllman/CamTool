/**
 * @file    cameracontroller.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.2
 * @date    Noviembre, 2014
 * @brief   Controlador para el uso de cámaras.
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de cabecera para la clase
 * controlador de cámaras.
 *
 * Interfaz de uso para detectar, seleccionar,
 * comprobar, etc la cámaras conectadas al
 * sistema. Se basa en el uso de las librerías
 * OpenCV y su clase VideoCapture.
 */
#ifndef CAMERACONTROLLER_H
#define CAMERACONTROLLER_H

/**
 * Se define la macro MAX_CAMS para determinar
 * el tamaño inicial del array de cámaras
 */
#define MAX_CAMS 5

#include "../globalConf.h"

#if TEST_CHECKING
   #include "../../test/controller/cameracontroller_spec.h"
#endif

#include <opencv2/opencv.hpp>
#include <string>


/**
 *
 */
class VideoCaptureW: public cv::VideoCapture {
   public:
      VideoCaptureW (int index): cv::VideoCapture (index) { index_ = index; };
      ~VideoCaptureW () {};

      void openCam () { this->open(index_); };

   private:
      int index_;
};


/**
 * @brief camInfoS: Struct contenedor de la información de las cámaras disponibles
 * @details
 *
 * Struct que mantiene accesible toda la información elemental
 * necesaria para el uso de las cámaras.
 */
struct camInfoS {
      camInfoS() { theCam = NULL; index = -1; slIndex = -1; resWidth = -1; resHeight = -1; }

      VideoCaptureW* theCam;
      unsigned int index;
      unsigned int slIndex;
      unsigned int resWidth;
      unsigned int resHeight;
};

/**
 * @class CameraController
 * @brief CameraController: Interfaz de uso para las cámaras con OpenCV.
 */
class CameraController {
   public:
      CameraController();
      ~CameraController();

      void checkingAvCameras ();
      void checkingSlCameras ();

      std::string obtainAvCamerasInfo ();
      std::string obtainSlCamerasInfo ();

      void obtainAvCameras ();
      int getNumberAvCams () { return _numberAvCams; };

      int getSlCamIndex (int index) { return _slCams[index]->index; };
      VideoCaptureW* getSlCam (int index);

      void addSlCam (int avCamIndex);


   private:
      int _numberAvCams;
      bool _isCheckedAvCams;
      camInfoS** _avCams;

      int _numberSlCams;
      bool _isCheckedSlCams;
      camInfoS** _slCams;

      void checkingCameras (int numCams, camInfoS** listCams, bool &isCheck);
      void obtainCameras (int &numCams, camInfoS** &listCams, bool &isCheck);
      void releaseCams (int &numCams, camInfoS** &listCams, bool &isCheck, int index = -1);
      std::string obtainCamerasInfo (int numCams, camInfoS** listCams, bool isCheck);

      void releaseAvCams (int index = -1);
      void releaseSlCams (int index = -1);
      void releaseCam (camInfoS*);


      friend class CameraController_spec;

};

#endif // CAMERACONTROLLER_H
