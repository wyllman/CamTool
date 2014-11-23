/**
 * @file    cameracontroller_spec.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Espectativas Controlador interno para las cámaras.
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de código fuente para las espectativas
 * de la clase CameraController
 */
#include "test/controller/cameracontroller_spec.h"

#include <iostream>

using namespace std;

/**
 * @brief CameraController_spec::CameraController_spec
 */
CameraController_spec::CameraController_spec() {}

/**
 * @brief CameraController_spec::suite
 * @return
 */
CppUnit::Test* CameraController_spec::suite() {
   CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "Camera Controller test suit" );

   suiteOfTests->addTest( new CppUnit::TestCaller<CameraController_spec>(
                                  "Init Test",
                                  &CameraController_spec::testInitClass ) );
   suiteOfTests->addTest( new CppUnit::TestCaller<CameraController_spec>(
                                  "Test Atrib",
                                  &CameraController_spec::testAtributes ) );
   suiteOfTests->addTest( new CppUnit::TestCaller<CameraController_spec>(
                                  "Test Meth",
                                  &CameraController_spec::testMethods ) );
   return suiteOfTests;
 }

/**
 * @brief CameraController_spec::setUp
 */
void CameraController_spec::setUp() {
   cout << endl;
   cout << "*--CameraController--------------------------------------------*" << endl;
}

/**
 * @brief CameraController_spec::tearDown
 */
void CameraController_spec::tearDown() {}

/**
 * @brief CameraController_spec::testInitClass
 */
void CameraController_spec::testInitClass() {
   cout << "* 1. Test: Inicialización de la clase.                         *" << endl;
   CPPUNIT_ASSERT(true);
}

/**
 * @brief CameraController_spec::testAtributes()
 */
void CameraController_spec::testAtributes() {
   cout << "* 2. Test: Atributos de la clase.                              *" << endl;
   CPPUNIT_ASSERT(true);
}

/**
 * @brief CameraController_spec::testMethods()
 */
void CameraController_spec::testMethods() {
   cout << "* 3. Test: Uso de los métodos de la clase.                     *" << endl;
   CPPUNIT_ASSERT(true);
}

