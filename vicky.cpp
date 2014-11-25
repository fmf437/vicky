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

// for debugging
#include <iostream>

using namespace std;

// constructor
Vicky::Vicky(QWidget *parent) : QMainWindow(parent), ui(new Ui::Vicky)
{
    ui->setupUi(this);
    ui->label->setText(tr("Default extension for music files: .mp3"));
    ui->label_3->setText(tr("Output file(s) in the directory:"));
    this->setMaximumSize(673,592);
    this->setMinimumSize(673,592);
    this->setWindowTitle("Vicky converter version 1.5.0.");

    this->connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setValue(0);

    ui->pushButton->setText("&Add file(s)");
    ui->pushButton->setShortcut(Qt::CTRL | Qt::Key_A);

    ui->pushButton_2->setText("&Convert");
    ui->pushButton_2->setShortcut(Qt::CTRL | Qt::Key_C);

    ui->pushButton_3->setText("Clear &List");
    ui->pushButton_3->setShortcut(Qt::CTRL | Qt::Key_L);

    //ui->pushButton_4->setText(tr("Ca&ncel"));
    //ui->pushButton_4->setShortcut(Qt::CTRL | Qt::Key_N);
    //ui->pushButton_4->setVisible(false);

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
    file = QFileDialog::getOpenFileNames(this,tr("Add Files"),"/home/filipe/C++/test_for_Vicky/","Video files (*.mp4)");
    if (file.isEmpty())
        file.clear();
    else
    {
        ui->listWidget->addItems(file);
        ui->lcdNumber->display(ui->listWidget->count());
    }
}

// convert button
void Vicky::on_pushButton_2_clicked()
{
    if (ui->listWidget->count() == 0)
    {
        QMessageBox::warning(this,tr("Files not found!"),tr("You need to put some files!"));
    }
    else
    {
        // for debug
        cout << file.size() << "\n";
        for (int i = 0; i < file.size(); ++i)
        {
            // for debug
            cout << file.at(i).toLocal8Bit().constData() << "\n";
            list_of_files_mp4.push_back(file.at(i));
        }
        this->convert(list_of_files_mp4);
    }
}

// operation of converting inside the method
// int convert method
int Vicky::convert(QVector <QString> files_mp4)
{
    QStringList arguments;
    QProcess *myprocess = new QProcess(this);
    QString program = "ffmpeg";
    QString list_of_files;
    QFile ff;
    if (files_mp4.empty())
    {
        delete myprocess;
        ui->progressBar->setValue(100);
        QMessageBox::information(this,tr("Finished successfully"),tr("Operation finished successfully !!!"));
        return 0;
    }
    else
    {
        for (int i = 0; i < files_mp4.size(); i++)
        {
            //qDebug() << list_of_files_mp4.at(i);
            list_of_files.clear();
            list_of_files.append(files_mp4.at(i));
            list_of_files.append(".mp3");
            //qDebug() << list_of_files;
            arguments << "-i" << files_mp4.at(i) << "-acodec" << "libmp3lame" << "-ab" << "256k" << "-y" << list_of_files;
            myprocess->execute(program, arguments);
            ui->progressBar->setValue(50);
            files_mp4.remove(i);
            if(ff.exists(list_of_files))
                ui->listWidget_2->addItem(list_of_files);
            // method recursion
            this->convert(files_mp4);
        }
    }
    delete myprocess;
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

//void Vicky::on_pushButton_4_clicked()
//{
//    myprocess->kill();
//}
