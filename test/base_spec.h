/**
 * @file    base_spec.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Clase base para el uso de expectativas.
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de cabecera para la clase base de las
 * futuras clases de expectativas.
 */
#ifndef BASE_SPEC_H
#define BASE_SPEC_H

#include <cppunit/TestFixture.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestCaller.h>
#include <cppunit/TestSuite.h>


#include <string>

/**
 * @class Base_spec
 * @brief The Base_spec class
 */
class Base_spec: public CppUnit::TestFixture {
   public:
      Base_spec(std::string);

      void setUp();
      void tearDown();

   protected:
      std::string _className;
      int _numPassTest;
      bool _finishMethTest;

      void addPassTest ();
      void startTest ();
      void finishTest ();

      /**
       * @class BaseSuit
       * @brief Clase interna de Base_spec e hija de TestSuite usada
       *    como clase envolvente para añadirle funcionalidad a la
       *    función run(...)
       */
      class BaseSuit: public CppUnit::TestSuite {
         public:
            BaseSuit (const char* name): TestSuite(name) {}

            void 	run (CppUnit::TestResult *result);
      };
};

#endif // BASE_SPEC_H
