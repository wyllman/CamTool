/**
 * @file    mainwindow.h
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Ventana Principal QT
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de cabecera para la clase de la
 * ventana principal en QT.
 */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../globalConf.h"

#if TEST_CHECKING
   #include "../../test/view/mainwindow_spec.h"
#else

#endif

#include "../controller/playercontroller.h"
#include "../controller/cameracontroller.h"

#include <opencv2/opencv.hpp>

using namespace cv;


#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
   class MainWindow;
}

/**
 * @class MainWindow
 * @brief The MainWindow class
 */
class MainWindow : public QMainWindow {
   Q_OBJECT
   public:
      explicit MainWindow(QWidget *parent = 0);
      ~MainWindow();

      void setPlayerController (VideoCaptureW *);

   private:
      Ui::MainWindow *ui;

      playerController* playerC_;

   private slots:
      //Display video frame in player UI
      void updatePlayerUI(QImage img);

      //Slot for the load video push button.
      void on_pushButton_clicked();

      // Slot for the play push button.
      void on_pushButton_2_clicked();


#if TEST_CHECKING
      friend class mainwindow_spec;
#endif
};

#endif // MAINWINDOW_H
