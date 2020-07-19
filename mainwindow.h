#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Factory/panel.h"
#include "Factory/algorithmarea.h"

#include <QResizeEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent* event);

private:
    Ui::MainWindow *ui;
    Panel* panel;
    AlgorithmArea* alArea;
};
#endif // MAINWINDOW_H
