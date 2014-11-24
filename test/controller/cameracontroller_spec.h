/**
 * @file    cameracontroller_spec.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Expectativas Controlador interno para las cámaras.
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de cabecera para la clase de las
 * expectativas de la clase CameraController
 */
#ifndef CAMERACONTROLLER_SPEC_H
#define CAMERACONTROLLER_SPEC_H

#include "../base_spec.h"

#include "../../lib/controller/cameracontroller.h"

class CameraController;

/**
 * @class CameraController_spec
 * @brief The CameraController_spec class
 */
class CameraController_spec: public Base_spec {
   public:
      CameraController_spec();
      ~CameraController_spec();

      static CppUnit::Test* suite();

   protected:
      void testInitClass();
      void testAtributes();
      void testMethods();

   private:
      CameraController* _dummyObject;


};

#endif // CAMERACONTROLLER_SPEC_H
