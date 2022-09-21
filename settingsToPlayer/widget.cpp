#include "widget.h"
#include "ui_widget.h"

#include "QFileDialog"
#include "QTextStream"
#include "QFile"


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QStringList list_file_read_data;
    list_file_read_data << "C:/Program Files/VOVAVIDEOPLAYER/playlist1.txt";
    list_file_read_data << "C:/Program Files/VOVAVIDEOPLAYER/playlist2.txt";
    list_file_read_data << "C:/Program Files/VOVAVIDEOPLAYER/playlist3.txt";
    list_file_read_data << "C:/Program Files/VOVAVIDEOPLAYER/playlist4.txt";
    list_file_read_data << "C:/Program Files/VOVAVIDEOPLAYER/playlist5.txt";
    QFile file_read_data;
    QStringList line;

    for(int y = 0; y < 5; y++){
        file_read_data.setFileName(list_file_read_data[y]);
        QTextStream cin(&file_read_data);
        if(file_read_data.open(QIODevice::ReadOnly)){
            for(int i = 0; i < 3; i++) line << cin.readLine();
            file_read_data.close();
        }
    }

    if(!line[0].isEmpty()) ui->lineEdit_videofile_1->setText(line[0]);
    if(!line[1].isEmpty()) ui->lineEdit_time_1->setText(line[1]);
    if(!line[2].isEmpty()) ui->label_path_1->setText(line[2]);

    if(!line[3].isEmpty()) ui->lineEdit_videofile_2->setText(line[3]);
    if(!line[4].isEmpty()) ui->lineEdit_time_2->setText(line[4]);
    if(!line[5].isEmpty()) ui->label_path_2->setText(line[5]);

    if(!line[6].isEmpty()) ui->lineEdit_videofile_3->setText(line[6]);
    if(!line[7].isEmpty()) ui->lineEdit_time_3->setText(line[7]);
    if(!line[8].isEmpty()) ui->label_path_2->setText(line[8]);

    if(!line[9].isEmpty()) ui->lineEdit_videofile_4->setText(line[9]);
    if(!line[10].isEmpty()) ui->lineEdit_time_4->setText(line[10]);
    if(!line[11].isEmpty()) ui->label_path_2->setText(line[11]);

    if(!line[12].isEmpty()) ui->lineEdit_videofile_5->setText(line[12]);
    if(!line[13].isEmpty()) ui->lineEdit_time_5->setText(line[13]);
    if(!line[14].isEmpty()) ui->label_path_2->setText(line[14]);
}

Widget::~Widget()
{
    delete ui;
}



void Widget::on_pushButton_set_1_clicked()
{
    QString open_folder_1 = QFileDialog::getExistingDirectory(this, tr("Найти папку с видеофайлами"),"C:/",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!open_folder_1.isEmpty()) ui->label_path_1->setText(open_folder_1);
}

void Widget::on_pushButton_set_2_clicked()
{
    QString open_folder_2 = QFileDialog::getExistingDirectory(this, tr("Найти папку с видеофайлами"),"C:/",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!open_folder_2.isEmpty()) ui->label_path_2->setText(open_folder_2);
}

void Widget::on_pushButton_set_3_clicked()
{
    QString open_folder_3 = QFileDialog::getExistingDirectory(this, tr("Найти папку с видеофайлами"),"C:/",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!open_folder_3.isEmpty()) ui->label_path_3->setText(open_folder_3);
}

void Widget::on_pushButton_set_4_clicked()
{
    QString open_folder_4 = QFileDialog::getExistingDirectory(this, tr("Найти папку с видеофайлами"),"C:/",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!open_folder_4.isEmpty()) ui->label_path_4->setText(open_folder_4);
}

void Widget::on_pushButton_set_5_clicked()
{
    QString open_folder_5 = QFileDialog::getExistingDirectory(this, tr("Найти папку с видеофайлами"),"C:/",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if(!open_folder_5.isEmpty()) ui->label_path_5->setText(open_folder_5);
}

void Widget::on_pushButton_creat_1_clicked()
{
    QString str_path = ui->label_path_1->text();
    if(str_path.contains("папка с видеофайлами не задана")) return;
    QString str_vidf = ui->lineEdit_videofile_1->text();
    QString str_time = ui->lineEdit_time_1->text();

    if(str_vidf.isEmpty()){
        str_vidf = "1";
        ui->lineEdit_videofile_1->setText("1");
    }
    if(str_time.isEmpty()){
        str_time = "0";
        ui->lineEdit_time_1->setText("0");
    }

    QFile mFile("C:/Program Files/VOVAVIDEOPLAYER/playlist1.txt");
    QTextStream stream(&mFile);

    QDir di(str_path);
    QStringList lis;
    recursiveSearchFilesDirectory(di, lis);

    if (mFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << str_vidf << endl << str_time << endl << str_path << endl;
        foreach(QString st, lis) stream << st << endl;
        mFile.close();
    }
}

void Widget::on_pushButton_creat_2_clicked()
{
    QString str_path = ui->label_path_2->text();
    if(str_path.contains("папка с видеофайлами не задана")) return;
    QString str_vidf = ui->lineEdit_videofile_2->text();
    QString str_time = ui->lineEdit_time_2->text();

    if(str_vidf.isEmpty()){
        str_vidf = "1";
        ui->lineEdit_videofile_2->setText("1");
    }
    if(str_time.isEmpty()){
        str_time = "0";
        ui->lineEdit_time_2->setText("0");
    }

    QFile mFile("C:/Program Files/VOVAVIDEOPLAYER/playlist2.txt");
    QTextStream stream(&mFile);

    QDir di(str_path);
    QStringList lis;
    recursiveSearchFilesDirectory(di, lis);

    if(mFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << str_vidf << endl << str_time << endl << str_path << endl;
        foreach(QString st, lis) stream << st << endl;
        mFile.close();
    }
}

void Widget::on_pushButton_creat_3_clicked()
{
    QString str_path = ui->label_path_3->text();
    if(str_path.contains("папка с видеофайлами не задана")) return;
    QString str_vidf = ui->lineEdit_videofile_3->text();
    QString str_time = ui->lineEdit_time_3->text();

    if(str_vidf.isEmpty()){
        str_vidf = "1";
        ui->lineEdit_videofile_3->setText("1");
    }
    if(str_time.isEmpty()){
        str_time = "0";
        ui->lineEdit_time_3->setText("0");
    }

    QFile mFile("C:/Program Files/VOVAVIDEOPLAYER/playlist3.txt");
    QTextStream stream(&mFile);

    QDir di(str_path);
    QStringList lis;
    recursiveSearchFilesDirectory(di, lis);

    if (mFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << str_vidf << endl << str_time << endl << str_path << endl;
        foreach(QString st, lis) stream << st << endl;
        mFile.close();
    }
}

void Widget::on_pushButton_creat_4_clicked()
{
    QString str_path = ui->label_path_4->text();
    if(str_path.contains("папка с видеофайлами не задана")) return;
    QString str_vidf = ui->lineEdit_videofile_4->text();
    QString str_time = ui->lineEdit_time_4->text();

    if(str_vidf.isEmpty()){
        str_vidf = "1";
        ui->lineEdit_videofile_4->setText("1");
    }
    if(str_time.isEmpty()){
        str_time = "0";
        ui->lineEdit_time_4->setText("0");
    }

    QFile mFile("C:/Program Files/VOVAVIDEOPLAYER/playlist4.txt");
    QTextStream stream(&mFile);

    QDir di(str_path);
    QStringList lis;
    recursiveSearchFilesDirectory(di, lis);

    if (mFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << str_vidf << endl << str_time << endl << str_path << endl;
        foreach(QString st, lis) stream << st << endl;
        mFile.close();
    }
}

void Widget::on_pushButton_creat_5_clicked()
{
    QString str_path = ui->label_path_5->text();
    if(str_path.contains("папка с видеофайлами не задана")) return;
    QString str_vidf = ui->lineEdit_videofile_5->text();
    QString str_time = ui->lineEdit_time_5->text();

    if(str_vidf.isEmpty()){
        str_vidf = "1";
        ui->lineEdit_videofile_5->setText("1");
    }
    if(str_time.isEmpty()){
        str_time = "0";
        ui->lineEdit_time_5->setText("0");
    }

    QFile mFile("C:/Program Files/VOVAVIDEOPLAYER/playlist5.txt");
    QTextStream stream(&mFile);

    QDir di(str_path);
    QStringList lis;
    recursiveSearchFilesDirectory(di, lis);

    if (mFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        stream << str_vidf << endl << str_time << endl << str_path << endl;
        foreach(QString st, lis) stream << st << endl;
        mFile.close();
    }
}

void Widget::on_pushButton_delete1_clicked()
{
    QFile mFile_delete("C:/Program Files/VOVAVIDEOPLAYER/playlist1.txt");
    mFile_delete.remove();
    QFile mFile_create("C:/Program Files/VOVAVIDEOPLAYER/playlist1.txt");
    mFile_create.open(QIODevice::WriteOnly);
    mFile_create.close();
    ui->lineEdit_videofile_1->setText("");
    ui->lineEdit_time_1->setText("");
    ui->label_path_1->setText("папка с видеофайлами не задана");
}

void Widget::on_pushButton_delete2_clicked()
{
    QFile mFile_delete("C:/Program Files/VOVAVIDEOPLAYER/playlist2.txt");
    mFile_delete.remove();
    QFile mFile_create("C:/Program Files/VOVAVIDEOPLAYER/playlist2.txt");
    mFile_create.open(QIODevice::WriteOnly);
    mFile_create.close();
    ui->lineEdit_videofile_2->setText("");
    ui->lineEdit_time_2->setText("");
    ui->label_path_2->setText("папка с видеофайлами не задана");
}

void Widget::on_pushButton_delete3_clicked()
{
    QFile mFile_delete("C:/Program Files/VOVAVIDEOPLAYER/playlist3.txt");
    mFile_delete.remove();
    QFile mFile_create("C:/Program Files/VOVAVIDEOPLAYER/playlist3.txt");
    mFile_create.open(QIODevice::WriteOnly);
    mFile_create.close();
    ui->lineEdit_videofile_3->setText("");
    ui->lineEdit_time_3->setText("");
    ui->label_path_3->setText("папка с видеофайлами не задана");
}

void Widget::on_pushButton_delete4_clicked()
{
    QFile mFile_delete("C:/Program Files/VOVAVIDEOPLAYER/playlist4.txt");
    mFile_delete.remove();
    QFile mFile_create("C:/Program Files/VOVAVIDEOPLAYER/playlist4.txt");
    mFile_create.open(QIODevice::WriteOnly);
    mFile_create.close();
    ui->lineEdit_videofile_4->setText("");
    ui->lineEdit_time_4->setText("");
    ui->label_path_4->setText("папка с видеофайлами не задана");
}

void Widget::on_pushButton_delete5_clicked()
{
    QFile mFile_delete("C:/Program Files/VOVAVIDEOPLAYER/playlist5.txt");
    mFile_delete.remove();
    QFile mFile_create("C:/Program Files/VOVAVIDEOPLAYER/playlist5.txt");
    mFile_create.open(QIODevice::WriteOnly);
    mFile_create.close();
    ui->lineEdit_videofile_5->setText("");
    ui->lineEdit_time_5->setText("");
    ui->label_path_5->setText("папка с видеофайлами не задана");
}

void Widget::recursiveSearchFilesDirectory(const QDir &dir, QStringList &all_pat)
{
    QApplication::processEvents();
    QStringList listFiles = dir.entryList(QString("*.mp4 *.avi *.mkv").split(" "), QDir::Files);
    foreach (QString file, listFiles) all_pat << dir.absoluteFilePath(file);
    QStringList listDir = dir.entryList(QDir::Dirs);
    foreach (QString subdir, listDir) {
        if (subdir == "." || subdir == "..") continue;
        recursiveSearchFilesDirectory(QDir(dir.absoluteFilePath(subdir)), all_pat);
    }
}
