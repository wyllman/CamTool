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

#include "../globalConf.h"

#if TEST_CHECKING
   #include "../../test/controller/cameracontroller_spec.h"
#endif

/**
 * @class CameraController
 * @brief The CameraController class
 */
class CameraController {
   public:
      CameraController();

#if TEST_CHECKING
      friend class CameraController_spec;
#endif
};

#endif // CAMERACONTROLLER_H
