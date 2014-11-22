/*
*	name of file: vicky_dialog.h
*
*	Copyright 2014 Filipe Marques <eagle.software3@gmail.com>
*
*	This program is free software; you can redistribute it and/or modify
*	it under the terms of the GNU General Public License as published by
*	the Free Software Foundation; either version 3 of the License, or
*	any later version.
*
*	This program is distributed in the hope that it will be useful,
*	but WITHOUT ANY WARRANTY; without even the implied warranty of
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*	GNU General Public License for more details.
*
*	You received a copy of the GNU General Public License
*	along with this program in License folder; if not, write to the Free Software
*	Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
*	MA 02110-1301, USA.
*
*/

#ifndef VICKY_DIALOG_H
#define VICKY_DIALOG_H

#include <QDialog>

namespace Ui
{
class Vicky_dialog;
}

class Vicky_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Vicky_dialog(QWidget *parent = 0);
    ~Vicky_dialog();

private:
    Ui::Vicky_dialog *ui;
};

#endif // VICKY_DIALOG_H
