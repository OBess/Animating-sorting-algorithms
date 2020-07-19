QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AbstractClasses/algorithm.cpp \
    AbstractClasses/sortingalgoritms.cpp \
    Factory/algorithmarea.cpp \
    Factory/panel.cpp \
    SortingAlgorithms/bogosort.cpp \
    SortingAlgorithms/bubblesort.cpp \
    SortingAlgorithms/cocktailsort.cpp \
    SortingAlgorithms/combsort.cpp \
    SortingAlgorithms/gnomesort.cpp \
    SortingAlgorithms/heapsort.cpp \
    SortingAlgorithms/insertionsort.cpp \
    SortingAlgorithms/mergesort.cpp \
    SortingAlgorithms/pancakesorting.cpp \
    SortingAlgorithms/quicksort.cpp \
    SortingAlgorithms/selectionsort.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    AbstractClasses/algorithm.h \
    AbstractClasses/sortingalgoritms.h \
    Factory/algorithmarea.h \
    Factory/panel.h \
    SortingAlgorithms/bogosort.h \
    SortingAlgorithms/bubblesort.h \
    SortingAlgorithms/cocktailsort.h \
    SortingAlgorithms/combsort.h \
    SortingAlgorithms/gnomesort.h \
    SortingAlgorithms/heapsort.h \
    SortingAlgorithms/insertionsort.h \
    SortingAlgorithms/mergesort.h \
    SortingAlgorithms/pancakesorting.h \
    SortingAlgorithms/quicksort.h \
    SortingAlgorithms/selectionsort.h \
    mainwindow.h \

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
