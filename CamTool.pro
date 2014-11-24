#-------------------------------------------------
#
# Project created by QtCreator 2014-11-22T04:24:11
#
#-------------------------------------------------

# Creado para uso personal (MacBook Air 10.6.8)

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET   = CamTool
TEMPLATE = app


SOURCES  += lib/main.cpp\
            lib/view/mainwindow.cpp \
            test/view/mainwindow_spec.cpp \
            test/controller/cameracontroller_spec.cpp \
            lib/controller/cameracontroller.cpp

HEADERS  += lib/view/mainwindow.h\
            lib/globalConf.h \
            test/view/mainwindow_spec.h \
            test/controller/cameracontroller_spec.h \
            lib/controller/cameracontroller.h

FORMS    += lib/view/mainwindow.ui

# Controlar otros archivos con el QT Creator
OTHER_FILES += README.md \
               doc/VERSION_LOG.md \
               .travis.yml \
               CamTool.travis.pro \
               Doxyfile \
               doc/MAIN.md \
               doc/HELP_INFO.md

# Dependencias
#   - OpenCV (MacBook Air 10.6.8)
win32:CONFIG(release, debug|release): LIBS += -L/opt/local/lib/release/ -lopencv_highgui
else:win32:CONFIG(debug, debug|release): LIBS += -L/opt/local/lib/debug/ -lopencv_highgui
else:symbian: LIBS += -lopencv_highgui
else:unix: LIBS += -L/opt/local/lib/ -lopencv_highgui

win32:CONFIG(release, debug|release): LIBS += -L/opt/local/lib/release/ -lopencv_core
else:win32:CONFIG(debug, debug|release): LIBS += -L/opt/local/lib/debug/ -lopencv_core
else:symbian: LIBS += -lopencv_core
else:unix: LIBS += -L/opt/local/lib/ -lopencv_core

win32:CONFIG(release, debug|release): LIBS += -L/opt/local/lib/release/ -lopencv_imgproc
else:win32:CONFIG(debug, debug|release): LIBS += -L/opt/local/lib/debug/ -lopencv_imgproc
else:symbian: LIBS += -lopencv_imgproc
else:unix: LIBS += -L/opt/local/lib/ -lopencv_imgproc

win32:CONFIG(release, debug|release): LIBS += -L/opt/local/lib/release/ -lopencv_objdetect
else:win32:CONFIG(debug, debug|release): LIBS += -L/opt/local/lib/debug/ -lopencv_objdetect
else:symbian: LIBS += -lopencv_objdetect
else:unix: LIBS += -L/opt/local/lib/ -lopencv_objdetect

INCLUDEPATH += /opt/local/include
DEPENDPATH += /opt/local/include

#   - CppUnit
LIBS += -lcppunit
