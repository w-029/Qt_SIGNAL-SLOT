#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void sig_sendMsg(string text);

public:
    void runInSubThread();
    void setMsg(string text);

private slots:
    void on_reciveMsg(string text);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
