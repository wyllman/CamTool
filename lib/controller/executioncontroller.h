/**
 * @file    executioncontroller.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Controlador para la ejecución del programa.
 *
 * @section DESCRIPTION
 * @details
 *
 */
#ifndef EXECUTIONCONTROLLER_H
#define EXECUTIONCONTROLLER_H

#include "../globalConf.h"

#if TEST_CHECKING
   #include "../../test/controller/executioncontroller_spec.h"
#endif


/**
 * @class ExecutionController
 * @brief The ExecutionController class
 */
class ExecutionController {
   public:
      ExecutionController();

   private:

#if TEST_CHECKING
      friend class ExecutionController_spec;
#endif
};

#endif // EXECUTIONCONTROLLER_H
