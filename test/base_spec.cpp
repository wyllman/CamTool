/**
 * @file    base_spec.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Clase base para el uso de expectativas.
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de código para la clase base de las
 * futuras clases de expectativas.
 */
#include "../lib/globalConf.h"
#include "../lib/view/consoleview.h"
#include "./test/base_spec.h"

#include <iomanip>
#include <string>

using namespace std;

/**
 * @brief Base_spec::Base_spec
 * @param name
 */
Base_spec::Base_spec(std::string name) {
   _className = name;
}

/**
 * @brief Base_spec::setUp
 */
void Base_spec::setUp() {
   _numPassTest = 0;
   _finishMethTest = false;
   cout << endl;
}

/**
 * @brief Base_spec::tearDown
 */
void Base_spec::tearDown() {
   string internalText;
   string formatText = "\033[0;31m";
   int lineWidth = CONSOLE_LINE_WITH - (_numPassTest + 1);

   if (!_finishMethTest) {
      lineWidth -= 1;
      cout << "\033[0m" << setw (lineWidth) << setfill (' ') << " " << "*" << endl;
      internalText = "   - Fallo en el test " + ConsoleView::to_s(_numPassTest + 1 );
      ConsoleView::showLine (' ', internalText, formatText);
   } else {
      cout << "\033[0m" << setw (lineWidth) << setfill (' ') << " " << "*" << endl;
   }
   if (_numPassTest > 0) {
      formatText = "\033[0;32m";
   }
   internalText = "   - " + ConsoleView::to_s(_numPassTest ) +  " test realizados con éxito";
   ConsoleView::showLine(' ', internalText, formatText, false);
}

void Base_spec::addPassTest () {
   ++_numPassTest;
   cout << "\033[0;32m";
   cout << ".";
   cout << "\033[0;31m";
}

void Base_spec::startTest () {
   cout << "* ";
}

void Base_spec::finishTest () {
   _finishMethTest = true;

}

void 	Base_spec::BaseSuit::run (CppUnit::TestResult *result) {
   //cout << endl;
   ConsoleView::showLine('-', "-- " + getName() + " ", "\033[0m", false);
   CppUnit::TestSuite::run(result);
   cout << endl;
}
