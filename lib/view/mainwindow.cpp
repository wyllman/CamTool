/**
 * @file    mainwindow.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date    Noviembre, 2014
 * @brief   Ventana Principal QT
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de código fuente para la clase de la
 * ventana principal en QT.
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <iostream>

using namespace std;

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {

   playerC_ = new playerController();

   QObject::connect(playerC_, SIGNAL(processedImage(QImage)),
                    this, SLOT(updatePlayerUI(QImage)));



   ui->setupUi(this);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow() {
   delete playerC_;
   delete ui;
}

void MainWindow::updatePlayerUI(QImage img) {
   //cout << endl << "Actualizando imagen!!---------------" << endl;
   if (!img.isNull()) {
      ui->label->setAlignment(Qt::AlignCenter);
      ui->label->setPixmap(QPixmap::fromImage(img).scaled(ui->label->size(),
                           Qt::KeepAspectRatio, Qt::FastTransformation));
   }
}

void MainWindow::on_pushButton_clicked() {
   //QString filename = QFileDialog::getOpenFileName(this, tr("Open Video"), ".",
   //                                                tr("Video Files (*.avi *.mpg *.mp4)"));
   //if (!filename.isEmpty()){
   if (!playerC_->loadVideo("")) { // filename.toAscii().data())) {
         QMessageBox msgBox;
         msgBox.setText("The selected video could not be opened!");
         msgBox.exec();
   } else {

      //cout << endl << "Camara cargada!!---------------" << endl;

   }
   //}
}

void MainWindow::on_pushButton_2_clicked() {
   if (playerC_->isStopped()) {
      playerC_->Play();
      //cout << endl << "Pulsado Paly!!---------------" << endl;
      ui->pushButton_2->setText(tr("Stop"));
   } else {
      playerC_->Stop();
      ui->pushButton_2->setText(tr("Play"));
   }
}
