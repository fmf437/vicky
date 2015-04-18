#
#       This file is part of Vicky project
#	name of file: vicky.pro
#
#	Copyright (C) 2014 2015 Filipe Marques <eagle.software3@gmail.com>
#
#	This program is free software; you can redistribute it and/or modify
#	it under the terms of the GNU General Public License as published by
#	the Free Software Foundation; either version 3 of the License, or
#	any later version.
#
#	This program is distributed in the hope that it will be useful,
#	but WITHOUT ANY WARRANTY; without even the implied warranty of
#	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#	GNU General Public License for more details.
#
#	You received a copy of the GNU General Public License
#	along with this program in License folder; if not, write to the Free Software
#	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#	MA 02110-1301, USA.
#

QT       += core gui widgets

TARGET = Vicky
TEMPLATE = app
CONFIG += c++11
CONFIG += release

VERSION += 1.6.0

HEADERS +=  inc/Vicky.hpp \
            inc/VickyDialog.hpp \
            inc/Convert.hpp

SOURCES +=  src/main.cpp \
            src/Vicky.cpp \
            src/VickyDialog.cpp \
            src/Convert.cpp

RESOURCES += resource/vv.qrc

FORMS +=    ui/Vicky.ui \
            ui/VickyDialog.ui

# Installation on Linux
unix {
    target.path = /usr/bin/vicky

    desk.path = /usr/share/applications/vicky
    desk.files = vicky.desktop

    icon24.path = /usr/share/icons/vicky
    icon24.files = resource/icons/vicky24.png

    icon24_2.path = /usr/share/icons/hicolor/24x24/apps/vicky
    icon24_2.files = resource/icons/vicky24.png

    icon128.path = /usr/share/icons/hicolor/128x128/apps/vicky
    icon128.files = resource/icons/vicky128.png

    license.path = /usr/share/licenses/vicky/LICENSE
    license.files = LICENSE

    INSTALLS += target desk icon24 icon24_2 icon128 license
}
