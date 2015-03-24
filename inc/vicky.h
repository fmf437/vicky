/*
 *  This file is part of Vicky project
 *	name of file: vicky.h
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

#ifndef VICKY_H
#define VICKY_H

#include <QMainWindow>
#include <QVector>
#include <QStringList>
#include <QString>
#include <QProcess>
#include <QMessageBox>
#include <QFileDialog>
//#include <QDebug>
#include <QObject>
#include <QDir>
#include <QFile>

namespace Ui
{
class Vicky;
}

// classe Vicky herda a classe QMainWindow
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
    void on_pushButton_3_clicked();
    //void on_pushButton_4_clicked();

private:
    Ui::Vicky *ui;
    QVector<QString> list_of_files_mp4;
    int convert(QVector<QString> list_of_files_mp4);
    void open_dialog();
    QStringList file;
    QProcess *myprocess;
};

#endif // VICKY_H
