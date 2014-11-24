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
# include <cppunit/extensions/TypeInfoHelper.h>
#include <iostream>

//#include <string>
//#include <cstdlib>


using namespace std;

/**
 * @brief CameraController_spec::CameraController_spec (constructor)
 */
CameraController_spec::CameraController_spec() {}

/**
 * @brief CameraController_spec::suite (creador de conjuntos de tests)
 * @return CppUnit::Test* (conjunto de tests creado)
 *
 * @details
 * Creador del conjunto de test de CppUnit para la clase
 * CameraController.
 */
CppUnit::Test* CameraController_spec::suite() {
   CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite ("Camera Controller test suit");

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
   _numPassTest = 0;
   _finishMethTest = false;
   cout << "\033[0m" << endl;
   cout << "*--CameraController--------------------------------------------*" << endl;
}

/**
 * @brief CameraController_spec::tearDown
 */
void CameraController_spec::tearDown() {
   if (!_finishMethTest) {
      cout << " - " << "Fallo en el test " << _numPassTest + 1 << endl;
   }
   if (_numPassTest > 0) {
      cout << "\033[0;32m";
   } else {
      cout << "\033[0m";
   }
   cout << " - " << _numPassTest << " test realizados con éxito";
   cout << "\033[0m";
}

/**
 * @brief CameraController_spec::testInitClass
 */
void CameraController_spec::testInitClass() {
   // \033[0m <- Por Defecto
   // \033[0;31m <- ROJO
   // \033[0;32m <- VERDE

   cout << "* 1. Test: Inicialización de la clase.                         *" << endl;
   cout << "\033[0;31m";

   // Comprobando el uso del constructor por defecto.
   CPPUNIT_ASSERT_NO_THROW_MESSAGE ("Llamando al constructor por defecto de CameraController"
                                    , _dummyObject = new CameraController (););
   addPassTest ();
   CPPUNIT_ASSERT_MESSAGE ("Comprobando que el constructor por defecto no retorne NULL"
                           , _dummyObject != NULL);
   addPassTest ();

   // Espectativas inicialización de atributos:
   //   - Crear struct para guardar el objeto CvCapture y la resolución
   //     de una de las cámaras disponibles en el sistema. (cameraDevice)
   //CPPUNIT_ASSERT_NO_THROW (objetoDePrueba;);

   _finishMethTest = true;
}

/**
 * @brief CameraController_spec::testAtributes()
 */
void CameraController_spec::testAtributes() {
   cout << "* 2. Test: Atributos de la clase.                              *" << endl;
   cout << "\033[0;31m";

   CPPUNIT_ASSERT(true);
   addPassTest ();

   _finishMethTest = true;
}

/**
 * @brief CameraController_spec::testMethods()
 */
void CameraController_spec::testMethods() {
   cout << "* 3. Test: Uso de los métodos de la clase.                     *" << endl;
   cout << "\033[0;31m";

   CPPUNIT_ASSERT(true);
   addPassTest ();

   _finishMethTest = true;
}

/**
 * @brief CameraController_spec::addPassTest
 */
void CameraController_spec::addPassTest () {
   ++_numPassTest;
   cout << "\033[0;32m";
   cout << ".";
   cout << "\033[0;31m";
}
