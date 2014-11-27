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
 * @brief CameraController_spec::setUp
 */
void CameraController_spec::setUp() {
   _dummyObject = new CameraController ();
   Base_spec::setUp();
}


/**
 * @brief CameraController_spec::testInitClass
 */
void CameraController_spec::testInitClass() {
   ConsoleView::showLine(' ', " 1. Test: Inicialización de la clase.");
   startTest ();

   if (_dummyObject != NULL) {
      delete _dummyObject;
      _dummyObject = NULL;
   }
   // Comprobando el uso del constructor por defecto.
   CPPUNIT_ASSERT_NO_THROW_MESSAGE ("Llamando al constructor por defecto de CameraController"
                                    , _dummyObject = new CameraController (););
   addPassTest ();
   CPPUNIT_ASSERT_MESSAGE ("Comprobando que el constructor por defecto no retorne NULL"
                           , _dummyObject != NULL);
   addPassTest ();


   finishTest();
}

/**
 * @brief CameraController_spec::testAtributes()
 */
void CameraController_spec::testAtributes() {
   ConsoleView::showLine(' ', " 2. Test: Atributos de la clase.");
   startTest ();

   // Expectativas inicialización de atributos:
   CPPUNIT_ASSERT_MESSAGE ("Comprobando que el número de cámaras detectado sea -1(=>Sin iniciar)"
                           , _dummyObject->_numberAvCams == -1);
   addPassTest ();
   CPPUNIT_ASSERT_MESSAGE ("Comprobando que el array de cámaras disponibles sea NULL(=>Sin iniciar)"
                           , _dummyObject->_avCams == NULL);
   addPassTest ();

   finishTest();
}

/**
 * @brief CameraController_spec::testMethods()
 */
void CameraController_spec::testMethods() {
   ConsoleView::showLine(' ', " 3. Test: Uso de los métodos de la clase.");
   startTest ();

   CPPUNIT_ASSERT_NO_THROW_MESSAGE ("Comprobando el estado de las cámaras"
                                    , _dummyObject->obtainCamerasInfo (););
   addPassTest ();
   CPPUNIT_ASSERT_MESSAGE ("Comprobando que el número de cámaras detectado sea > -1"
                           , _dummyObject->_numberAvCams > -1);
   addPassTest ();
   CPPUNIT_ASSERT_MESSAGE ("Comprobando el array de cámaras detectadas no es NULL"
                           , _dummyObject->_avCams != NULL);
   addPassTest ();

   CPPUNIT_ASSERT_NO_THROW_MESSAGE ("Comprobando el estado de las cámaras"
                                    , _dummyObject->checkingCameras(););
   addPassTest ();


   finishTest();
}
