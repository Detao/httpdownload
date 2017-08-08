QT += core
QT -= gui

CONFIG += c++11

TARGET = testapp
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    main.c \
    ../liboal/oal/oal_httpdownload/HTTPClient.c \
    ../liboal/oal/oal_httpdownload/HTTPClientAuth.c \
    ../liboal/oal/oal_httpdownload/HTTPClientString.c \
    ../liboal/oal/oal_httpdownload/HTTPClientWrapper.c \
    ../liboal/oal/oal_httpdownload/oal_httpdownload.c

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
INCLUDEPATH += ../liboal/win32
INCLUDEPATH += ../liboal
INCLUDEPATH +=../liboal/oal/oal_httpdownload

LIBS += -L../liboal -loal
LIBS += -lws2_32 -lwinmm -lwininet -liphlpapi


HEADERS += \
    ../liboal/oal/oal_httpdownload/HTTPClient.h \
    ../liboal/oal/oal_httpdownload/HTTPClientAuth.h \
    ../liboal/oal/oal_httpdownload/HTTPClientCommon.h \
    ../liboal/oal/oal_httpdownload/HTTPClientString.h \
    ../liboal/oal/oal_httpdownload/HTTPClientWrapper.h \
    ../liboal/oal_httpdownload.h \
    ../liboal/oal_thread.h \
    ../liboal/oal_string.h \
    ../liboal/oal_cmdline.h \
    ../liboal/oal_type.h \
    ../liboal/oal_stringex.h \
    ../liboal/oal_event.h \
    ../liboal/oal_httpdownload.h
