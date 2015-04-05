#-------------------------------------------------
#
# Project created by QtCreator 2014-11-22T04:24:11
#
#-------------------------------------------------

# Creado para el uso de la plataforma Travis CI

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = CamTool
TEMPLATE = app


SOURCES  += lib/main.cpp\
            lib/view/mainwindow.cpp\
            test/view/mainwindow_spec.cpp\
            lib/controller/cameracontroller.cpp\
            test/controller/cameracontroller_spec.cpp\
            test/base_spec.cpp\
            lib/view/consoleview.cpp\
            lib/controller/executioncontroller.cpp\
            test/controller/executioncontroller_spec.cpp\
            lib/controller/playercontroller.cpp\
            lib/view/selectorcamaras.cpp

HEADERS  += lib/view/mainwindow.h\
            lib/globalConf.h\
            test/view/mainwindow_spec.h\
            lib/controller/cameracontroller.h\
            test/controller/cameracontroller_spec.h\
            test/base_spec.h\
            lib/view/consoleview.h\
            lib/controller/executioncontroller.h\
            test/controller/executioncontroller_spec.h\
            lib/controller/playercontroller.h\
            lib/view/selectorcamaras.h

FORMS    += lib/view/mainwindow.ui\
            lib/view/selectorcamaras.ui


# Dependencias
#   - OpenCV (Travis: using: sudo apt-get install libopencv-dev):
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_objdetect
INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include

#   - CppUnit:
LIBS += -lcppunit
