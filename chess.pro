QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ChessContorl.cpp \
    ChessPiece.cpp \
    main.cpp \
    Chessboard.cpp \
    player/ChessPlayer.cpp \
    strategy/PieceStrategy.cpp

HEADERS += \
    ChessContorl.h \
    ChessPiece.h \
    Chessboard.h \
    player/AbstractChessPlayer.h \
    player/ChessPlayer.h \
    strategy/PieceStrategy.h

msvc{
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
