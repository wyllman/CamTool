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
            test/view/mainwindow_spec.cpp

HEADERS  += lib/view/mainwindow.h\
            lib/globalConf.h\
            test/view/mainwindow_spec.h

FORMS    += lib/view/mainwindow.ui


# Dependencias
#   - OpenCV (Travis: using: sudo apt-get install libopencv-dev):
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgproc -lopencv_highgui -lopencv_objdetect
INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include

#   - CppUnit:
LIBS += -lcppunit
