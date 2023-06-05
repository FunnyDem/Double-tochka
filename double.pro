QT += core testlib

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

target.path = $$[QT_INSTALL_EXAMPLES]/double
INSTALLS += target

SOURCES += \
    main.cpp
TARGET = main
QT -= core
TEMPLATE = app
CONFIG += console

OTHER_FILES += \
    ../myProg-build-desktop-Qt_4_7_4_for_Desktop_-_MinGW_4_4__Qt_SDK__Debug/main.exe

HEADERS +=

DISTFILES +=
