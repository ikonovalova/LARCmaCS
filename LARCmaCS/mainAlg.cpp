#include <iostream>
#include <windows.h>

#include <QtWidgets/QApplication>

using namespace std;

#include "message.h"
#include "mainAlg.h"

MainAlg::MainAlg(){}

MainAlg::~MainAlg()
{
    stop();
    thread.wait(100);
    thread.terminate();
    thread.wait(100);
}

void MainAlg::init()
{
    worker.moveToThread(&thread);
    cout << "Init mainAlg ok" << endl;
    connect(this, SIGNAL(wstart()), &worker, SLOT(start()));
    connect(this, SIGNAL(wstop()), &worker, SLOT(stop()));
    connect(&thread, SIGNAL(finished()), &worker, SLOT(deleteLater()));
}

void MainAlg::start()
{
    thread.start();
    cout << "Thread start" << endl;
    emit wstart();
}

void MainAlg::stop()
{
    emit wstop();
}
