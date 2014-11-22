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

/**
 * @brief mainwindow_spec::mainwindow_spec
 */
mainwindow_spec::mainwindow_spec() {
}

CppUnit::Test* mainwindow_spec::suite() {
   CppUnit::TestSuite *suiteOfTests = new CppUnit::TestSuite( "CamTool Test Suit" );

   suiteOfTests->addTest( new CppUnit::TestCaller<mainwindow_spec>(
                                  "Test Sum",
                                  &mainwindow_spec::testSum ) );
   suiteOfTests->addTest( new CppUnit::TestCaller<mainwindow_spec>(
                                  "Test Subtraction",
                                  &mainwindow_spec::testSub ) );
   return suiteOfTests;
 }
