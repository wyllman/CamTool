/**
 * @file mainwindow.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date   Noviembre, 2014
 * @brief Ventana Principal QT
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de cabecera para la clase de la
 * ventana principal en QT.
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../globalConf.h"

#if TEST_CHECKING
   #include "../../test/view/mainwindow_spec.h"
#endif

namespace Ui {
   class MainWindow;
}

/**
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow {
   Q_OBJECT
   public:
      explicit MainWindow(QWidget *parent = 0);
      ~MainWindow();

   private:
      Ui::MainWindow *ui;

#if TEST_CHECKING
      friend class mainwindow_spec;
#endif
};

#endif // MAINWINDOW_H
