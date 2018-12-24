#-------------------------------------------------
#
# Project created by QtCreator 2018-12-02T15:42:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SQirreL
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        gui/mainwindow.cpp \
    models/repository/repository.cpp \
    models/router.cpp \
    gui/widgets/sql_editor_widget.cpp \
    gui/sql_syntax_highlighter.cpp \
    libs/json_parser/json.cpp \
    models/types/db_adapters/sqlite_adapter.cpp \
    models/types/collection.cpp \
    models/types/collection_item.cpp \
    models/utils/file_reader.cpp \
    models/services/open_collection_interactor.cpp

HEADERS += \
        gui/mainwindow.h \
    models/repository/repository.h \
    models/router.h \
    gui/widgets/sql_editor_widget.h \
    gui/sql_syntax_highlighter.h \
    libs/json_parser/json.h \
    models/types/db_adapters/sqlite_adapter.h \
    models/types/collection.h \
    models/types/collection_item.h \
    models/utils/file_reader.h \
    models/services/open_collection_interactor.h

FORMS += \
        gui/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
