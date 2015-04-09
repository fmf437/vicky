/*
 *  This file is part of Vicky project
 *	name of file: Convert.cpp
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

#include "inc/Convert.hpp"

Convert::Convert()
{
    list.clear();
    program = "ffmpeg";
}

Convert::~Convert()
{
}

void Convert::run()
{
    for (int i = 0; i < list.size(); ++i)
    {
        list_of_file.append(list.at(i));
        second.append(list.at(i));
        second.append(".mp3");
        arguments << "-i" << list_of_file << "-acodec" << "libmp3lame" << "-ab" << "256k" << "-y" << second;
        mutex.lock();
        QProcess::execute(program, arguments);
        mutex.unlock();
        arguments.clear();
        list_of_file.clear();
        second.clear();
    }
    emit resultReady();
}

void Convert::setList(QStringList list_of_files)
{
    list = list_of_files;
    list_of_files.clear();
}
