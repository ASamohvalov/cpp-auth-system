TEMPLATE += app

INCLUDEPATH += src

QT += widgets
CONFIG += c++17

SOURCES += src/main.cpp \
          src/views/base_window.cpp \
          src/views/auth/sign_in_window.cpp \
          src/views/base_widget.cpp \
          src/components/line_edit.cpp \
          src/components/push_button.cpp \
          src/components/error_frame.cpp

HEADERS += src/views/auth/sign_in_window.h \
          src/views/base_window.h \
          src/views/base_widget.h \
          src/components/line_edit.h \
          src/components/push_button.h \
          src/components/error_frame.h


CONFIG += qt warn_on debug