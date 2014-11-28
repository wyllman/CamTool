/**
 * @file    cameracontroller.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Controlador para el uso de cámaras.
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de cabecera para la clase
 * controlador de cámaras.
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

struct camInfoS {
      camInfoS() { theCam = NULL; index = -1; resWidth = -1; resHeight = -1; }

      cv::VideoCapture* theCam;
      unsigned int index;
      unsigned int resWidth;
      unsigned int resHeight;
};

/**
 * @class CameraController
 * @brief The CameraController class
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
      //cv::VideoCapture* getSlCam (int index); <- TODO
      //void addSlCam (int avCamIndex); <- TODO


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

#if TEST_CHECKING
      friend class CameraController_spec;
#endif
};

#endif // CAMERACONTROLLER_H
