/**
 * @file    consoleview.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Mostrar texto por consola
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de código fuente para la clase
 * ConsoleView.
 */
#include "lib/view/consoleview.h"
#include "../globalConf.h"
#include <iostream>
#include <iomanip>

using namespace std;

void ConsoleView::showLine (char separator, string text) {
   showLine (separator, text, "\033[0m", true);
}

void ConsoleView::showLine (char separator, string text, string formatText) {
   showLine (separator, text, formatText, true);
}

void ConsoleView::showLine (char separator, string text, string formatText, bool endLine) {
   cout << "\033[0m*";
   cout << formatText << setw(CONSOLE_LINE_WITH) << setfill(separator) << setiosflags(ios::left)
        << text;
   cout << "\033[0m*";
   if (endLine) cout << endl;
}
void ConsoleView::showHeader () {
   showLine('*', "*");
   showLine(' ', " Iniciando CamTool ");
   showLine('*', "*");
}

void ConsoleView::showHeaderTest () {
   showLine('-', "-");
   showLine(' ', " Modo testeo activado.");
   showLine(' ', "    + Iniciando test...");
}

void ConsoleView::showHeaderExec () {
   showLine('-', "-");
   showLine(' ', " Sin modo testeo.");
   showLine(' ', "    + Iniciando ejecución...");
}

void ConsoleView::showFooter () {
   showLine('-', "-");
   showLine(' ', " Finalizando CamTool...");
   showLine('*', "*");
}

string ConsoleView::to_s (int value) {
   stringstream ss;
   ss << value;
   return (ss.str());
}
