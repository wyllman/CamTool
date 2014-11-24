/**
 * @file    cameracontroller_spec.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Expectativas Controlador interno para las cámaras.
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de código fuente para las expectativas
 * de la clase CameraController
 */
#include "test/controller/cameracontroller_spec.h"
#include "../../lib/view/consoleview.h"

#include <cppunit/extensions/TypeInfoHelper.h>
#include <iostream>

using namespace std;

/**
 * @brief CameraController_spec::CameraController_spec (constructor)
 */
CameraController_spec::CameraController_spec (): Base_spec ("CameraController") {
   _dummyObject = NULL;
}

/**
 * @brief CameraController_spec::~CameraController_spec
 */
CameraController_spec::~CameraController_spec () {
   if (_dummyObject != NULL) {
      delete (_dummyObject);
      _dummyObject = NULL;
   }
}
/**
 * @brief CameraController_spec::suite (creador de conjuntos de tests)
 * @return CppUnit::Test* (conjunto de tests creado)
 *
 * @details
 * Creador del conjunto de test de CppUnit para la clase
 * CameraController.
 */
CppUnit::Test* CameraController_spec::suite() {
   Base_spec::BaseSuit *suiteOfTests = new Base_spec::BaseSuit ("Camera Controller test suit");

   suiteOfTests->addTest (new CppUnit::TestCaller<CameraController_spec>(
                                  "Init Test",
                                  &CameraController_spec::testInitClass));
   suiteOfTests->addTest (new CppUnit::TestCaller<CameraController_spec>(
                                  "Test Atrib",
                                  &CameraController_spec::testAtributes));
   suiteOfTests->addTest (new CppUnit::TestCaller<CameraController_spec>(
                                  "Test Meth",
                                  &CameraController_spec::testMethods));
   return suiteOfTests;
 }

/**
 * @brief CameraController_spec::testInitClass
 */
void CameraController_spec::testInitClass() {
   ConsoleView::showLine(' ', " 1. Test: Inicialización de la clase.");
   startTest ();

   // Comprobando el uso del constructor por defecto.
   CPPUNIT_ASSERT_NO_THROW_MESSAGE ("Llamando al constructor por defecto de CameraController"
                                    , _dummyObject = new CameraController (););
   addPassTest ();
   //_dummyObject = NULL;
   CPPUNIT_ASSERT_MESSAGE ("Comprobando que el constructor por defecto no retorne NULL"
                           , _dummyObject != NULL);
   addPassTest ();

   // Expectativas inicialización de atributos:
   //   - Crear struct para guardar el objeto CvCapture y la resolución
   //     de una de las cámaras disponibles en el sistema. (cameraDevice)
   //CPPUNIT_ASSERT_NO_THROW (objetoDePrueba;);

   finishTest();
}

/**
 * @brief CameraController_spec::testAtributes()
 */
void CameraController_spec::testAtributes() {
   ConsoleView::showLine(' ', " 2. Test: Atributos de la clase.");
   startTest ();

   CPPUNIT_ASSERT(true);
   addPassTest ();
   finishTest();
}

/**
 * @brief CameraController_spec::testMethods()
 */
void CameraController_spec::testMethods() {
   ConsoleView::showLine(' ', " 3. Test: Uso de los métodos de la clase.");
   startTest ();

   CPPUNIT_ASSERT(true);
   addPassTest ();
   finishTest();
}
