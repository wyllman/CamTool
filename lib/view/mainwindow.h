#ifndef MAINWINDOW_H
#define MAINWINDOW_H
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
 */
#include <QMainWindow>

namespace Ui {
   class MainWindow;
}

class MainWindow : public QMainWindow
{
      Q_OBJECT
      
   public:
      explicit MainWindow(QWidget *parent = 0);
      ~MainWindow();
      
   private:
      Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
