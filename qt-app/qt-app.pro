TEMPLATE += app

INCLUDEPATH += src

QT += widgets
QT += network

CONFIG += c++17

SOURCES += src/main.cpp \
          src/views/auth/sign_in_window.cpp \
          src/views/auth/sign_up_window.cpp\
          src/views/base_window.cpp \
					src/views/account/account_window.cpp \
          src/views/base_widget.cpp \
          src/components/line_edit.cpp \
          src/components/push_button.cpp \
          src/components/error_frame.cpp \
          src/components/clickable_label.cpp \
					src/utils/router.cpp \
					src/utils/window.cpp

HEADERS += src/views/auth/sign_in_window.h \
          src/views/auth/sign_up_window.h \
          src/views/base_window.h \
					src/views/account/account_window.h \
          src/views/base_widget.h \
          src/components/line_edit.h \
          src/components/push_button.h \
          src/components/error_frame.h \
          src/components/clickable_label.h \
					src/utils/router.h \
					src/utils/window.h 

CONFIG += qt warn_on debug
