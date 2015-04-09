/*
 *  This file is part of Vicky project
 *	name of file: Vicky.cpp
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

#include "inc/Vicky.hpp"
#include "inc/VickyDialog.hpp"
#include "ui_Vicky.h"

// for debugging
//#include <iostream>
//using namespace std;

// constructor
Vicky::Vicky(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::Vicky)
{
    ui->setupUi(this);
    ui->label->setText(tr("Default extension for sound files: .mp3"));
    ui->label_3->setText(tr("Output file(s) in the directory:"));
    setMaximumSize(680,592);
    setMinimumSize(680,592);
    setWindowTitle("Vicky");

    conv = new Convert();
    conv->setParent(this);

    connect(conv, &Convert::resultReady, this, &Vicky::handleResults);
    connect(conv, &Convert::finished, conv, &QObject::deleteLater);

    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);

    ui->pushButton->setText("&Add file(s)");
    ui->pushButton->setShortcut(Qt::CTRL | Qt::Key_A);

    ui->pushButton_2->setText("&Convert");
    ui->pushButton_2->setShortcut(Qt::CTRL | Qt::Key_C);

    ui->statusBar->showMessage(tr("Ready"),10000);
}

// destructor
Vicky::~Vicky()
{
    delete ui;
}

// add file(s) button
void Vicky::on_pushButton_clicked()
{
    files = QFileDialog::getOpenFileNames(this, tr("Add File(s)"), "/home/", "Video files (*.mp4)");
    if (files.isEmpty())
        files.clear();
    else
    {
        ui->listWidget->addItems(files);
        ui->lcdNumber->display(ui->listWidget->count());
    }
}

// slot handleResults
void Vicky::handleResults()
{
    conv->wait(1000);
    if(conv->isFinished())
    {
        ui->progressBar->setValue(100);

        // show item converted in listWidget_2
        for(int j = 0; j < files.size(); ++j)
        {
            item.append(files.at(j));
            item.append(".mp3");
            ui->listWidget_2->addItem(item);
            item.clear();
        }
        QMessageBox::information(this, tr("Finished sucessfully !"), tr("The conversion finished successfully !"));
    }
}

// convert button
void Vicky::on_pushButton_2_clicked()
{
    if (ui->listWidget->count() == 0)
    {
        QMessageBox::warning(this, tr("Files not found!"), tr("You need to put some files!"));
    }
    else
    {
        ui->pushButton->setDisabled(true);
        ui->pushButton_2->setDisabled(true);

        // for debug
        //cout << file.size() << "\n";
        ui->progressBar->setValue(60);

        conv->setList(files);
        conv->start();
    }
}

// About - Vicky
void Vicky::on_actionVicky_triggered()
{
    Vicky_dialog vd;
    vd.setModal(true);
    vd.exec();
}
