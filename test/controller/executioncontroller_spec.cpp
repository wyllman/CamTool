/**
 * @file    executioncontroller_spec.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Expectativas Controlador interno de la ejecución.
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de código fuente para las expectativas
 * de la clase ExecutionController
 */
#include "./test/controller/executioncontroller_spec.h"
#include "../../lib/view/consoleview.h"

#include <cppunit/extensions/TypeInfoHelper.h>
/**
 * @brief ExecutionController_spec::ExecutionController_spec
 */
ExecutionController_spec::ExecutionController_spec(): Base_spec ("ExecutionController") {
   _dummyObject = NULL;
}

ExecutionController_spec::~ExecutionController_spec() {
   if (_dummyObject != NULL) {
      delete (_dummyObject);
      _dummyObject = NULL;
   }
}

CppUnit::Test *ExecutionController_spec::suite() {
   Base_spec::BaseSuit *suiteOfTests = new Base_spec::BaseSuit ("Execution Controller test suit");

   suiteOfTests->addTest (new CppUnit::TestCaller<ExecutionController_spec>(
                                  "Init Test",
                                  &ExecutionController_spec::testInitClass));
   suiteOfTests->addTest (new CppUnit::TestCaller<ExecutionController_spec>(
                                  "Test Atrib",
                                  &ExecutionController_spec::testAtributes));
   suiteOfTests->addTest (new CppUnit::TestCaller<ExecutionController_spec>(
                                  "Test Meth",
                                  &ExecutionController_spec::testMethods));
   return suiteOfTests;
}


void ExecutionController_spec::testInitClass() {
   ConsoleView::showLine(' ', " 1. Test: Inicialización de la clase.");
   startTest ();

   // Test!!!

   finishTest();
}

void ExecutionController_spec::testAtributes() {
   ConsoleView::showLine(' ', " 2. Test: Atributos de la clase.");
   startTest ();

   finishTest();
}

void ExecutionController_spec::testMethods() {
   ConsoleView::showLine(' ', " 3. Test: Uso de los métodos de la clase.");
   startTest ();

   finishTest();
}
