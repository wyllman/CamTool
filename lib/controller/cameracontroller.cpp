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
#include "../view/consoleview.h"

#include <iostream>
using namespace std;


/**
 * @brief CameraController::CameraController
 */
CameraController::CameraController() {
   _numberAvCams = -1;
   _isCheckedAvCams = false;
   _avCams = NULL;

   _numberSlCams = -1;
   _isCheckedSlCams = false;
   _slCams = NULL;
}

/**
 * @brief CameraController::~CameraController
 */
CameraController::~CameraController() {
   releaseAvCams ();
}

/**
 * @brief CameraController::checkingCameras
 * @param numCams
 * @param listCams
 * @param isCheck
 */
void CameraController::checkingCameras (int numCams, camInfoS** listCams, bool &isCheck) {
   bool checkTmp = false;

   if (numCams > 0 && listCams != NULL) {
      for (int i = 0; i < numCams; ++i) {
         checkTmp = false;
         if (listCams[i]->theCam->isOpened()) {
            checkTmp = true;
         } else {
            listCams[i]->theCam->open(listCams[i]->index);
            if (listCams[i]->theCam->isOpened()) {
               checkTmp = true;
            } else {
               isCheck = false;
            }
         }
         if ((checkTmp) &&
            (listCams[i]->resWidth  == listCams[i]->theCam->get(CV_CAP_PROP_FRAME_WIDTH)) &&
            (listCams[i]->resHeight  == listCams[i]->theCam->get(CV_CAP_PROP_FRAME_HEIGHT))) {
            isCheck = true;
            listCams[i]->theCam->release();
         } else {
            isCheck = false;
         }
      }
   } else {
      isCheck = false;
   }
}

/**
 * @brief CameraController::checkingCameras
 */
void CameraController::checkingAvCameras () {
   checkingCameras(_numberAvCams, _avCams, _isCheckedAvCams);
}

/**
 * @brief CameraController::obtainCameras
 * @param numCams
 * @param listCams
 * @param isCheck
 */
void CameraController::obtainCameras (int &numCams, camInfoS** &listCams, bool &isCheck) {
   bool continueW = true;
   int numCamsTmp = 0;
   cv::VideoCapture* tempCam = NULL;

   //releaseAvCams();
   releaseCams (numCams, listCams, isCheck);

   if (listCams == NULL) {
      listCams = new camInfoS* [MAX_CAMS];
      for (int i = 0; i < MAX_CAMS; ++i) {
         listCams[i] = new camInfoS;
      }
   }

   while (continueW && (numCamsTmp < MAX_CAMS)) {
      tempCam = new cv::VideoCapture(numCamsTmp);

      if(tempCam->isOpened()) {
         listCams[numCamsTmp]->index = numCamsTmp;
         listCams[numCamsTmp]->theCam = tempCam;
         listCams[numCamsTmp]->resWidth = tempCam->get(CV_CAP_PROP_FRAME_WIDTH);
         listCams[numCamsTmp]->resHeight = tempCam->get(CV_CAP_PROP_FRAME_HEIGHT);
         ++numCamsTmp;
         tempCam->release();
      } else {
         continueW = false;
         delete tempCam;
      }
   }
   numCams = numCamsTmp;

   // Eliminamos de memoria los structs sobrantes
   if (numCamsTmp < MAX_CAMS) {
      for (int i = numCamsTmp; i < MAX_CAMS; ++i) {
         releaseAvCams(i);
      }
      camInfoS** camsTmp = NULL;
      if (numCamsTmp > 0) camsTmp = new camInfoS* [numCamsTmp];
      for (int i = 0; i < numCamsTmp; ++i) {
         camsTmp[i] = listCams[i];
      }
      if (camsTmp != NULL) {
         isCheck = true;
      }
      delete[] listCams;
      listCams = camsTmp;
   } else {
      isCheck = true;
   }
}

/**
 * @brief CameraController::obtainCameras
 */
void CameraController::obtainAvCameras () {
   obtainCameras (_numberAvCams, _avCams, _isCheckedAvCams);
}

/**
 * @brief CameraController::obtainCamerasInfo
 * @param numCams
 * @param listCams
 * @param isCheck
 * @return
 */
std::string CameraController::obtainCamerasInfo (int numCams, camInfoS** listCams, bool isCheck) {
   std::string result = "";

   if (numCams > 0 && isCheck) {
      result += " - Hay un total de " + ConsoleView::to_s(numCams) + " cámaras. \n";
      for (int i = 0; i < numCams; ++i) {
         result += "   - Cámara " + ConsoleView::to_s(i) + ": \n";
         result += "      - Resolución: " + ConsoleView::to_s(listCams[i]->resWidth) +
                   "x" + ConsoleView::to_s(listCams[i]->resHeight) + "\n";

      }
   } else if (numCams == 0) {
      result += " - No se encuentran cámaras conectadas";
   } else if (numCams == -1) {
      result += " - Sistema de cámaras sin iniciar(llame a la función obtainCameras(...)";
   } else if (!isCheck) {
      result += " - Se necesita actualizar el estado de las cámaras(llame a obtainCameras(...)";
   }

   return result;
}

/**
 * @brief CameraController::obtainCamerasInfo
 * @return
 */
std::string CameraController::obtainAvCamerasInfo () {
   return obtainCamerasInfo(_numberAvCams, _avCams, _isCheckedAvCams);
}

/**
 * @brief CameraController::releaseCams
 * @param numCams
 * @param listCams
 * @param isCheck
 * @param index
 */
void CameraController::releaseCams (int &numCams, camInfoS** &listCams, bool &isCheck, int index) {
   if (listCams != NULL) {
      if (index == -1) {
         for (int i = 0; i < numCams; ++i) {
            releaseAvCam (listCams[i]);
            delete listCams[i];
         }
         delete[] listCams;
         listCams = NULL;
         numCams = -1;
         isCheck = false;

      } else { // Para vaciar la memoria de los strucs sobrantes.
         releaseAvCam (listCams[index]);
         delete listCams[index];
         listCams[index] = NULL;
      }
   }
}

/**
 * @brief CameraController::releaseAvCams
 * @param index
 */
void CameraController::releaseAvCams (int index) {
   releaseCams (_numberAvCams, _avCams, _isCheckedAvCams, index);
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
