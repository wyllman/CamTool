/**
 * @file mainwindow.cpp
 * @author  Wyllman <wyllman@gmail.com>
 * @version 0.0.1
 * @date   Noviembre, 2014
 * @brief Ventana Principal QT
 *
 * @section DESCRIPTION
 * @details
 *
 * Archivo de código fuente para la clase de la
 * ventana principal en QT.
 */
#include "mainwindow.h"
#include "ui_mainwindow.h"

/**
 * @brief MainWindow::MainWindow
 * @param parent
 */
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
   ui->setupUi(this);
}

/**
 * @brief MainWindow::~MainWindow
 */
MainWindow::~MainWindow() {
   delete ui;
}
