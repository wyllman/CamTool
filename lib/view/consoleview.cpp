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
#include <sstream>

using namespace std;

/**
 * @brief ConsoleView::showLine
 * @param separator
 * @param text
 */
void ConsoleView::showLine (char separator, string text) {
   showLine (separator, text, "\033[0m", true);
}

/**
 * @brief ConsoleView::showLine
 * @param separator
 * @param text
 * @param formatText
 */
void ConsoleView::showLine (char separator, string text, string formatText) {
   showLine (separator, text, formatText, true);
}

/**
 * @brief ConsoleView::showLine
 * @param separator
 * @param text
 * @param formatText
 * @param endLine
 */
void ConsoleView::showLine (char separator, string text, string formatText, bool endLine) {
   cout << "\033[0m*";
   cout << formatText << setw(CONSOLE_LINE_WITH) << setfill(separator) << setiosflags(ios::left)
        << text;
   cout << "\033[0m*";
   if (endLine) cout << endl;
}

/**
 * @brief ConsoleView::showMultipleLine
 * @param separator
 * @param text
 * @param formatText
 * @param endLine
 */
void ConsoleView::showMultipleLine(char separator, std::string text
                             , string formatText
                             , bool endLine) {
   istringstream text_ss(text);
   string token;

   cout << endl;

   while(getline(text_ss, token, '\n')) {
      showLine(separator, token);
   }
}

/**
 * @brief ConsoleView::showHeader
 */
void ConsoleView::showHeader () {
   showLine('*', "*");
   showLine(' ', " Iniciando CamTool ");
   showLine('*', "*");
}

/**
 * @brief ConsoleView::showHeaderTest
 */
void ConsoleView::showHeaderTest () {
   showLine('-', "-");
   showLine(' ', " Modo testeo activado.");
   showLine(' ', "    + Iniciando test...");
}

/**
 * @brief ConsoleView::showHeaderExec
 */
void ConsoleView::showHeaderExec () {
   showLine('-', "-");
   showLine(' ', " Sin modo testeo.");
   showLine(' ', "    + Iniciando ejecución...");
}

/**
 * @brief ConsoleView::showFooter
 */
void ConsoleView::showFooter () {
   showLine('-', "-");
   showLine(' ', " Finalizando CamTool...");
   showLine('*', "*");
}

/**
 * @brief ConsoleView::to_s
 * @param value
 * @return
 */
string ConsoleView::to_s (int value) {
   stringstream ss;
   ss << value;
   return (ss.str());
}
