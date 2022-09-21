#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include "QDir"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();


private slots:
    void on_pushButton_set_1_clicked();

    void on_pushButton_set_2_clicked();

    void on_pushButton_set_3_clicked();

    void on_pushButton_set_4_clicked();

    void on_pushButton_set_5_clicked();

    void on_pushButton_creat_1_clicked();

    void on_pushButton_creat_2_clicked();

    void on_pushButton_creat_3_clicked();

    void on_pushButton_creat_4_clicked();

    void on_pushButton_creat_5_clicked();

    void on_pushButton_delete1_clicked();

    void on_pushButton_delete2_clicked();

    void on_pushButton_delete3_clicked();

    void on_pushButton_delete4_clicked();

    void on_pushButton_delete5_clicked();

private:
    Ui::Widget *ui;

    void recursiveSearchFilesDirectory(const QDir &, QStringList &);
};

#endif // WIDGET_H
