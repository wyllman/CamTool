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
#include "../../lib/view/consoleview.h"

#include <iostream>

using namespace std;

/**
 * @brief mainwindow_spec::mainwindow_spec
 */
mainwindow_spec::mainwindow_spec(): Base_spec ("MainWindow") {
   _dummyObject = NULL;
}

/**
 * @brief mainwindow_spec::~mainwindow_spec
 */
mainwindow_spec::~mainwindow_spec() {
   if (_dummyObject != NULL) {
      delete (_dummyObject);
      _dummyObject = NULL;
   }
}

/**
 * @brief mainwindow_spec::suite
 * @return
 */
CppUnit::Test* mainwindow_spec::suite() {
   Base_spec::BaseSuit *suiteOfTests = new Base_spec::BaseSuit( "Main Window Test Suit" );

   //CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "Main Window Test Suit" );

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
 * @brief mainwindow_spec::testInitClass
 */
void mainwindow_spec::testInitClass() {
   ConsoleView::showLine(' ', " 1. Test: Inicialización de la clase.");
   startTest ();

   // Comprobando el uso del constructor por defecto.
   CPPUNIT_ASSERT_NO_THROW_MESSAGE ("Llamando al constructor por defecto de MainWindow ()"
                                    , _dummyObject = new MainWindow (););
   addPassTest ();
   CPPUNIT_ASSERT_MESSAGE ("Comprobando que el constructor por defecto no retorne NULL"
                           , _dummyObject != NULL);
   addPassTest ();
   finishTest();
}

/**
 * @brief mainwindow_spec::testAtributes()
 */
void mainwindow_spec::testAtributes() {
   ConsoleView::showLine(' ', " 2. Test: Atributos de la clase.");
   startTest ();

   CPPUNIT_ASSERT (true);
   addPassTest ();
   finishTest();
}

/**
 * @brief mainwindow_spec::testMethods()
 */
void mainwindow_spec::testMethods() {
   ConsoleView::showLine(' ', " 3. Test: Uso de los métodos de la clase.");
   startTest ();

   CPPUNIT_ASSERT (true);
   addPassTest ();
   finishTest();
}
