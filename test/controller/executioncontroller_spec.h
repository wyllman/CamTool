/**
 * @file    executioncontroller_spec.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Expectativas Controlador de ejecución del programa.
 *
 * @section DESCRIPTION
 * @details
 *
 */
#ifndef EXECUTIONCONTROLLER_SPEC_H
#define EXECUTIONCONTROLLER_SPEC_H

#include "../base_spec.h"

#include "../../lib/controller/executioncontroller.h"

class ExecutionController;

/**
 * @class ExecutionController_spec
 * @brief The ExecutionController_spec class
 */
class ExecutionController_spec: public Base_spec {
   public:
      ExecutionController_spec();
      ~ExecutionController_spec();

      static CppUnit::Test* suite();

      //void setUp();

   protected:
      void testInitClass();
      void testAtributes();
      void testMethods();

   private:
      ExecutionController* _dummyObject;
};

#endif // EXECUTIONCONTROLLER_SPEC_H
