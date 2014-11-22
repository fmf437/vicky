/*
*	name of file: vicky.cpp
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

#include "vicky.h"
#include "vicky_dialog.h"
#include "ui_vicky.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <QObject>

#include <iostream>

using namespace std;

// constructor
Vicky::Vicky(QWidget *parent) : QMainWindow(parent), ui(new Ui::Vicky)
{
    ui->setupUi(this);
    ui->label->setText("Default extension for music files: mp3");
    this->setMaximumSize(673,342);
    this->setMinimumSize(673,342);
    this->setWindowTitle("Vicky converter version 1.0.0.");
    this->connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);

    ui->pushButton->setText("&Add file");
    ui->pushButton->setShortcut(Qt::CTRL | Qt::Key_A);

    ui->pushButton_2->setText("&Convert");
    ui->pushButton_2->setShortcut(Qt::CTRL | Qt::Key_C);

    ui->pushButton_3->setText("Clear &List");
    ui->pushButton_3->setShortcut(Qt::CTRL | Qt::Key_L);

    ui->statusBar->showMessage(tr("Ready"),10000);
}

// destructor
Vicky::~Vicky()
{
    delete ui;
}

// add file button
void Vicky::on_pushButton_clicked()
{
    QStringList file = QFileDialog::getOpenFileNames(this,tr("Open File"),"/home/","Video files (*.mp4)");
    if (file.isEmpty())
    {
        file.clear();
    }
    else
    {
        //list_of_files_mp4.append(file);
        ui->listWidget->addItems(file);
        ui->lcdNumber->display(ui->listWidget->count());
    }
}

// convert button
void Vicky::on_pushButton_2_clicked()
{
    int fg;
    if (ui->listWidget->count() == 0)
    {
        QMessageBox::warning(this,tr("Files not found!"),tr("You need to put some files!"));
    }
    else
    {
        ui->lcdNumber->display(ui->listWidget->count());
        // the animation of progressbar
        ui->pushButton->setDisabled(true);
        ui->pushButton_2->setDisabled(true);
        ui->pushButton_3->setDisabled(true);
        if (ui->listWidget->count() >= 7)
        {
            fg = (ui->listWidget->count())*14;
            ui->progressBar->setValue(fg);
            ui->progressBar->setValue(60);
        }
        else if (ui->listWidget->count() == 7)
        {
            fg = (ui->listWidget->count())*14;
            ui->progressBar->setValue(fg);
            ui->progressBar->setValue(50);
        }
        else if (ui->listWidget->count() <= 7)
        {
            fg = (ui->listWidget->count())*14;
            ui->progressBar->setValue(fg);
            ui->progressBar->setValue(40);
        }
        ui->progressBar->setValue(80);
        this->convert(list_of_files_mp4);
        ui->progressBar->setValue(100);
        ui->pushButton->setDisabled(false);
        ui->pushButton_2->setDisabled(false);
        ui->pushButton_3->setDisabled(false);
        ui->statusBar->showMessage(tr("Finished successfully!!!"),10000);
    }
}

// int convert method
int Vicky::convert(QVector <QString> list_of_files_mp4)
{
    QStringList arguments;
    QProcess *myproc = new QProcess(this);
    QString program = "ffmpeg";
    QString list_of_files;
    if (list_of_files_mp4.empty())
    {
        delete myproc;
        return 0;
    }
    else
    {
        for (int i = 0; i < list_of_files_mp4.size(); i++)
        {
            //qDebug() << list_of_files_mp4.at(i);
            list_of_files.append(list_of_files_mp4.at(i));
            list_of_files.append(".mp3");
            //qDebug() << list_of_files;
            arguments << "-i" << list_of_files_mp4.at(i) << "-acodec" << "libmp3lame" << "-ab" << "256k" << "-y" << list_of_files;
            myproc->execute(program, arguments);
            list_of_files_mp4.remove(i);
            // method recursion
            this->convert(list_of_files_mp4);
        }
    }
    delete myproc;
    return 0;
}

// About - Vicky
void Vicky::on_actionVicky_triggered()
{
    Vicky_dialog vd;
    vd.setModal(true);
    vd.exec();
}

// clear button
void Vicky::on_pushButton_3_clicked()
{
    ui->listWidget->clear();
    ui->lcdNumber->display(0);
    ui->progressBar->setValue(0);
}
