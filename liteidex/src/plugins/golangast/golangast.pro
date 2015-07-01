TARGET = golangast
TEMPLATE = lib

include (../../liteideplugin.pri)
include (../../api/golangastapi/golangastapi.pri)
include (../../utils/symboltreeview/symboltreeview.pri)
include (../../utils/fileutil/fileutil.pri)
include (../../3rdparty/qtc_editutil/qtc_editutil.pri)

DEFINES += GOLANGAST_LIBRARY

SOURCES += golangastplugin.cpp \
    golangast.cpp \
    golangasticon.cpp \
    astwidget.cpp

HEADERS += golangastplugin.h\
        golangast_global.h \
    golangast.h \
    golangasticon.h \
    astwidget.h \
    golangastitem.h

RESOURCES += \
    golangast.qrc
