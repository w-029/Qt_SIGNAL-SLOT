#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* notice: This is necessary if you call setMsg() in a subThread */
    qRegisterMetaType<string>("string");

    /* err: QObject::connect: No such signal ... */
    connect(this, SIGNAL(sig_sendMsg(string text)), this, SLOT(on_reciveMsg(string text)));
    /* this is correct */
    connect(this, SIGNAL(sig_sendMsg(string)), this, SLOT(on_reciveMsg(string)));

    runInSubThread();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/* simulate run in subThread */
void MainWindow::runInSubThread()
{
    setMsg("This is a Label");
}

void MainWindow::setMsg(string text)
{
    /* this maybe run in a subThread */
    emit sig_sendMsg(text);
}

void MainWindow::on_reciveMsg(string text)
{
    /* this is run in UiThread */
    ui->label->setText(
        QString(QString::fromLocal8Bit(text.c_str()))
    );
}
