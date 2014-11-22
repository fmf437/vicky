#-------------------------------------------------
#
# Project created by QtCreator 2014-02-13T17:48:53
#
#-------------------------------------------------
#
#	name of file: Vicky.pro
#
#	Copyright 2014 Filipe Marques <eagle.software3@gmail.com>
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

QT       += core gui

QT += widgets

TARGET = Vicky
TEMPLATE = app

SOURCES += main.cpp vicky.cpp vicky_dialog.cpp

HEADERS  += vicky.h vicky_dialog.h

FORMS    += vicky.ui vicky_dialog.ui

RESOURCES += vv.qrc

target.path = /opt/TARGET
INSTALLS += target
