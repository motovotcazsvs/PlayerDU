#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile file_read_data("C:/Program Files/VOVAVIDEOPLAYER/playlist4.txt");
    QTextStream cin(&file_read_data);
    if(file_read_data.open(QIODevice::ReadOnly)){
        for(int i = 0; !cin.atEnd(); i++){
            line << cin.readLine();
        }
        file_read_data.close();
        QString str_to_int1(line[0]);
        QString str_to_int2(line[1]);
        bool ok_number;
        playing_number = str_to_int1.toInt(&ok_number);
        if(ok_number == false || playing_number < 1) playing_number = 0;
        else playing_number--;
        bool ok_time;
        playing_time = str_to_int2.toInt(&ok_time);
        if(ok_time == false || playing_time < 0) playing_time = 0;
        else playing_time *= 1000;
    }

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);

    videoWidget = new QVideoWidget(this);
    this->setCentralWidget(videoWidget);
    player = new QMediaPlayer(videoWidget);
    playlist = new QMediaPlaylist(player);
    int count_file = line.size();
    for(int i = 3; i < count_file; i++) playlist->addMedia(QUrl::fromLocalFile(line[i]));
    player->setPlaylist(playlist);
    player->setVideoOutput(videoWidget);
    playlist->setCurrentIndex(playing_number);
    playlist->setPlaybackMode(QMediaPlaylist::Loop);
    player->setVolume(50);
    player->setPosition(playing_time);
    player->play();


}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
}

void MainWindow::updateTime()
{
    playing_number = playlist->currentIndex();
    playing_time = player->position();
    QFile file_write_data("C:/Program Files/VOVAVIDEOPLAYER/playlist4.txt");
    QTextStream cout(&file_write_data);
    QString int_to_str1 = QString::number(++playing_number);
    if(playing_time > 999) playing_time = playing_time / 1000;
    else playing_time = 0;
    QString int_to_str2 = QString::number(playing_time);
    if(file_write_data.open(QIODevice::WriteOnly | QIODevice::Text)){
        cout << int_to_str1 << endl << int_to_str2 << endl << line[2] << endl;
        int count_file = line.size();
        for(int i = 3; i < count_file; i++) cout << line[i] << endl;
        file_write_data.close();
    }
}



