/**
 * @file mainwindow.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date   Noviembre, 2014
 * @brief Ventana Principal QT
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de código fuente para las espectativas
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
   CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "CamTool Test Suit" );

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
   cout << endl;
   cout << "*--------------------------------------------------------------*" << endl;
}

/**
 * @brief mainwindow_spec::tearDown
 */
void mainwindow_spec::tearDown() {}

/**
 * @brief mainwindow_spec::testInitClass
 */
void mainwindow_spec::testInitClass() {
   cout << "* 1. Test: Inicialización de la clase.                         *" << endl;
   CPPUNIT_ASSERT(true);
}

/**
 * @brief testSum
 */
void mainwindow_spec::testAtributes() {
   cout << "* 2. Test: Atributos de la clase.                              *" << endl;
   CPPUNIT_ASSERT(true);
}

/**
 * @brief testSub
 */
void mainwindow_spec::testMethods() {
   cout << "* 3. Test: Uso de los métodos de la clase.                     *" << endl;
   CPPUNIT_ASSERT(true);
}
