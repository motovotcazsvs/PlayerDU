#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QVideoWidget>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private:
    Ui::MainWindow *ui;

    QVideoWidget *videoWidget;
    QMediaPlaylist *playlist;
    QMediaPlayer *player;
    QTimer *timer;
    int playing_number;
    int playing_time;
    QStringList line;

private slots:
    void updateTime();
};

#endif // MAINWINDOW_H
