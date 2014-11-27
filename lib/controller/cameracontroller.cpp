/**
 * @file    cameracontroller.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Controlador para el uso de cámaras.
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de código fuente para la clase de la
 * ventana principal en QT.
 */
#include "lib/controller/cameracontroller.h"



/**
 * @brief CameraController::CameraController
 */
CameraController::CameraController() {
   _numberAvCams = -1;
   _avCams = NULL;
}

/**
 * @brief CameraController::~CameraController
 */
CameraController::~CameraController() {}

/**
 * @brief CameraController::checkingCameras
 */
void CameraController::checkingCameras () {}

/**
 * @brief CameraController::obtainCamerasInfo
 */
void CameraController::obtainCamerasInfo () {
   bool continueW = true;
   int numCams = 0;
   cv::VideoCapture* tempCam;

   while (continueW) {
      tempCam = new cv::VideoCapture(numCams);
      if(tempCam->isOpened()) {
         ++numCams;
      } else {
         continueW = false;
      }

   }
   _numberAvCams = numCams;

}
