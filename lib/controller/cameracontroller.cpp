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

#include <iostream>
using namespace std;


/**
 * @brief CameraController::CameraController
 */
CameraController::CameraController() {
   _numberAvCams = -1;
   _isChecked = false;
   _avCams = NULL;
}

/**
 * @brief CameraController::~CameraController
 */
CameraController::~CameraController() {
   releaseAvCams ();
}

/**
 * @brief CameraController::checkingCameras
 */
void CameraController::checkingCameras () {
   bool checkTmp = false;

   if (_numberAvCams > 0 && _avCams != NULL) {
      for (int i = 0; i < _numberAvCams; ++i) {
         checkTmp = false;
         if (_avCams[i]->theCam->isOpened()) {
            checkTmp = true;
         } else {
            _avCams[i]->theCam->open(_avCams[i]->index);
            if (_avCams[i]->theCam->isOpened()) {
               checkTmp = true;
            } else {
               _isChecked = false;
            }
         }
         if ((checkTmp) &&
            (_avCams[i]->resWidth  == _avCams[i]->theCam->get(CV_CAP_PROP_FRAME_WIDTH)) &&
            (_avCams[i]->resHeight  == _avCams[i]->theCam->get(CV_CAP_PROP_FRAME_HEIGHT))) {
            _isChecked = true;
         } else {
            _isChecked = false;
         }
      }
   } else {
      _isChecked = false;
   }
}

/**
 * @brief CameraController::obtainCamerasInfo
 */
void CameraController::obtainCameras () {
   bool continueW = true;
   int numCams = 0;
   cv::VideoCapture* tempCam = NULL;

   releaseAvCams();

   if (_avCams == NULL) {
      _avCams = new camInfoS* [MAX_CAMS];
      for (int i = 0; i < MAX_CAMS; ++i) {
         _avCams[i] = new camInfoS;
      }
   }

   while (continueW && (numCams <= MAX_CAMS)) {
      tempCam = new cv::VideoCapture(numCams);

      if(tempCam->isOpened()) {
         _avCams[numCams]->index = numCams;
         _avCams[numCams]->theCam = tempCam;
         _avCams[numCams]->resWidth = tempCam->get(CV_CAP_PROP_FRAME_WIDTH);
         _avCams[numCams]->resHeight = tempCam->get(CV_CAP_PROP_FRAME_HEIGHT);
         ++numCams;
      } else {
         continueW = false;
      }
   }
   _numberAvCams = numCams;

   // Eliminamos de memoria los structs sobrantes
   if (numCams < MAX_CAMS) {
      for (int i = numCams; i < MAX_CAMS; ++i) {
         releaseAvCams(i);
      }
      camInfoS** camsTmp = NULL;
      if (numCams > 0) camsTmp = new camInfoS* [numCams];
      for (int i = 0; i < numCams; ++i) {
         camsTmp[i] = _avCams[i];
      }
      if (camsTmp != NULL) {
         _isChecked = true;
      }
      delete[] _avCams;
      _avCams = camsTmp;
   }
}

/**
 * @brief CameraController::obtainCamerasInfo
 * @return
 */
std::string CameraController::obtainCamerasInfo () {
   std::string result = "";




   return result;
}


/**
 * @brief CameraController::releaseAvCams
 * @param index
 */
void CameraController::releaseAvCams (int index) {
   if (_avCams != NULL) {

      if (index == -1) {
         for (int i = 0; i < _numberAvCams; ++i) {
            releaseAvCam (_avCams[i]);
            delete _avCams[i];
         }
         delete[] _avCams;
         _avCams = NULL;
         _numberAvCams = -1;
         _isChecked = false;

      } else { // Para vaciar la memoria de los strucs sobrantes.
         releaseAvCam (_avCams[index]);
         delete _avCams[index];
         _avCams[index] = NULL;
      }
   }
}

/**
 * @brief CameraController::releaseAvCam
 * @param theCamS
 */
void CameraController::releaseAvCam (camInfoS* theCamS) {
   if (theCamS->theCam != NULL) {
      if (theCamS->theCam->isOpened()) {
         theCamS->theCam->release();
      }
      delete theCamS->theCam;
      theCamS->theCam = NULL;
   }
}
