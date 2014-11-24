/**
 * @file    mainwindow_spec.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Expectativas Ventana Principal QT
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de código fuente para las expectativas
 * de la clase mainwindow
 */
#include "test/view/mainwindow_spec.h"

#include <iostream>

using namespace std;

/**
 * @brief mainwindow_spec::mainwindow_spec
 */
mainwindow_spec::mainwindow_spec() {}

/**
 * @brief mainwindow_spec::suite
 * @return
 */
CppUnit::Test* mainwindow_spec::suite() {
   CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "Main Window Test Suit" );

   suiteOfTests->addTest( new CppUnit::TestCaller<mainwindow_spec>(
                                  "Init Test",
                                  &mainwindow_spec::testInitClass ) );
   suiteOfTests->addTest( new CppUnit::TestCaller<mainwindow_spec>(
                                  "Test Atrib",
                                  &mainwindow_spec::testAtributes ) );
   suiteOfTests->addTest( new CppUnit::TestCaller<mainwindow_spec>(
                                  "Test Meth",
                                  &mainwindow_spec::testMethods ) );
   return suiteOfTests;
 }

/**
 * @brief mainwindow_spec::setUp
 */
void mainwindow_spec::setUp() {
   _numPassTest = 0;
   _finishMethTest = false;
   cout << "\033[0m" << endl;
   //cout << "*--------------------------------------------------------------*" << endl;
   cout << "*--mainwindow--------------------------------------------------*" << endl;
}

/**
 * @brief mainwindow_spec::tearDown
 */
void mainwindow_spec::tearDown() {
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
 * @brief mainwindow_spec::testInitClass
 */
void mainwindow_spec::testInitClass() {
   cout << "* 1. Test: Inicialización de la clase.                         *" << endl;
   cout << "\033[0;31m";

   // Comprobando el uso del constructor por defecto.
   CPPUNIT_ASSERT_NO_THROW_MESSAGE ("Llamando al constructor por defecto de MainWindow ()"
                                    , _dummyObject = new MainWindow (););
   addPassTest ();
   CPPUNIT_ASSERT_MESSAGE ("Comprobando que el constructor por defecto no retorne NULL"
                           , _dummyObject != NULL);
   addPassTest ();
   _finishMethTest = true;
}

/**
 * @brief mainwindow_spec::testAtributes()
 */
void mainwindow_spec::testAtributes() {
   cout << "* 2. Test: Atributos de la clase.                              *" << endl;
   cout << "\033[0;31m";

   CPPUNIT_ASSERT (true);
   addPassTest ();
   _finishMethTest = true;
}

/**
 * @brief mainwindow_spec::testMethods()
 */
void mainwindow_spec::testMethods() {
   cout << "* 3. Test: Uso de los métodos de la clase.                     *" << endl;
   cout << "\033[0;31m";

   CPPUNIT_ASSERT (true);
   addPassTest ();
   _finishMethTest = true;
}

/**
 * @brief mainwindow_spec::addPassTest
 */
void mainwindow_spec::addPassTest () {
   ++_numPassTest;
   cout << "\033[0;32m";
   cout << ".";
   cout << "\033[0;31m";
}
