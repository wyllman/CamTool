/**
 * @file mainwindow_spec.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date   Noviembre, 2014
 * @brief Espectativas ventana Principal QT
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de cabecera para la clase de la
 * ventana principal en QT.
 */
#ifndef MAINWINDOW_SPEC_H
#define MAINWINDOW_SPEC_H

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>
#include "../../lib/view/mainwindow.h"

/**
 * @class mainwindow_spec
 * @brief The mainwindow_spec class
 */
class mainwindow_spec: public CppUnit::TestFixture {
   public:
      mainwindow_spec();

      static CppUnit::Test* suite();

      void setUp();
      void tearDown();

   protected:
      void testInitClass();
      void testAtributes();
      void testMethods();
};

#endif // MAINWINDOW_SPEC_H
