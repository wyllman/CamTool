/**
 * @file    mainwindow_spec.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Expectativas ventana Principal QT
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de cabecera para la clase de las
 * expectativas de la clase mainwindow
 */
#ifndef MAINWINDOW_SPEC_H
#define MAINWINDOW_SPEC_H

#include "../base_spec.h"

#include "../../lib/view/mainwindow.h"

class MainWindow;

/**
 * @class mainwindow_spec
 * @brief The mainwindow_spec class
 */
class mainwindow_spec: public Base_spec {
   public:
      mainwindow_spec();
      ~mainwindow_spec();

      static CppUnit::Test* suite();

   protected:
      void testInitClass();
      void testAtributes();
      void testMethods();

   private:
      MainWindow* _dummyObject;

};

#endif // MAINWINDOW_SPEC_H
