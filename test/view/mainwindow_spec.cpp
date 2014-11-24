/**
 * @file    mainwindow_spec.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Espectativas Ventana Principal QT
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
   cout << endl;
   //cout << "*--------------------------------------------------------------*" << endl;
   cout << "*--mainwindow--------------------------------------------------*" << endl;
}

/**
 * @brief mainwindow_spec::tearDown
 */
void mainwindow_spec::tearDown() {
   cout << " - " << _numPassTest << " test realizados con éxito";
}

/**
 * @brief mainwindow_spec::testInitClass
 */
void mainwindow_spec::testInitClass() {
   cout << "* 1. Test: Inicialización de la clase.                         *" << endl;


   // Comprobando el uso del constructor por defecto.
   CPPUNIT_ASSERT_NO_THROW_MESSAGE ("Llamando al constructor por defecto de MainWindow ()"
                                    , _dummyObject = new MainWindow (););
   addPassTest ();
   CPPUNIT_ASSERT_MESSAGE ("Comprobando que el constructor por defecto no retorne NULL"
                           , _dummyObject != NULL);
   addPassTest ();

   //CPPUNIT_ASSERT (true);
   //addPassTest ();
}

/**
 * @brief mainwindow_spec::testAtributes()
 */
void mainwindow_spec::testAtributes() {
   cout << "* 2. Test: Atributos de la clase.                              *" << endl;
   CPPUNIT_ASSERT (true);
   addPassTest ();
}

/**
 * @brief mainwindow_spec::testMethods()
 */
void mainwindow_spec::testMethods() {
   cout << "* 3. Test: Uso de los métodos de la clase.                     *" << endl;
   CPPUNIT_ASSERT (true);
   addPassTest ();
}

/**
 * @brief mainwindow_spec::addPassTest
 */
void mainwindow_spec::addPassTest () {
   ++_numPassTest;
   cout << ".";
}
