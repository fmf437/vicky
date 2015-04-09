/*
 *  This file is part of Vicky project
 *	name of file: Vicky.hpp
 *
 *	Copyright (C) 2014 2015 Filipe Marques <eagle.software3@gmail.com>
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

#ifndef VICKY_HPP
#define VICKY_HPP

#include <QMainWindow>
#include <QStringList>
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QObject>
#include <QPointer>

#include "Convert.hpp"

namespace Ui
{
class Vicky;
}

class Vicky : public QMainWindow
{
    Q_OBJECT

public:
    explicit Vicky(QWidget *parent = 0);
    ~Vicky();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_actionVicky_triggered();
    void handleResults();

private:
    Ui::Vicky *ui;
    QStringList files;
    QString item;
    QPointer<Convert> conv;
};

#endif // VICKY_HPP
