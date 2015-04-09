/*
 *  This file is part of Vicky project
 *	name of file: Convert.hpp
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

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <QThread>
#include <QMutex>
#include <QVector>
#include <QString>
#include <QStringList>
#include <QProcess>

class Convert : public QThread
{
public:
    Convert();
    ~Convert();
    void setList(QStringList list_of_files);

signals:
    void resultReady();

private:
    Q_OBJECT
    void run() override;

    QMutex mutex;
    QStringList list, arguments;
    QString program, list_of_file, second;
};

#endif // CONVERT_HPP
