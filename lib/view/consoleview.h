/**
 * @file    consoleview.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Mostrar texto por consola
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de cabecera para la clase
 * ConsoleView.
 */
#ifndef CONSOLEVIEW_H
#define CONSOLEVIEW_H

#include <string>


/**
 * @class ConsoleView
 * @brief The ConsoleView class
 */
class ConsoleView {
   public:
      static void showLine (char, std::string);
      static void showLine (char, std::string, std::string);
      static void showLine (char, std::string, std::string, bool);
      static void showMultipleLine(char separator, std::string text
                                   , std::string formatText = "\033[0m"
                                   , bool endLine = true);
      static void showHeader ();
      static void showHeaderTest ();
      static void showHeaderExec ();
      static void showFooter ();

      static std::string to_s (int);

};

#endif // CONSOLEVIEW_H
