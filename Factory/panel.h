#ifndef PANEL_H
#define PANEL_H

#include <QObject>
#include <QWidget>
#include <QDebug>

#include <QPainter>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QSlider>
#include <QTabWidget>
#include <QListWidget>

#include <QRect>
#include <QPoint>
#include <QFont>
#include <QValidator>
#include <QPen>

#include <iostream>
#include <vector>
#include "algorithmarea.h"

class Panel : public QWidget
{
    Q_OBJECT
public:
    explicit Panel(QWidget *parent = nullptr);
    ~Panel();

    void setAlArea(AlgorithmArea* alArea);

    void updatePanel();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void generateArray();
    void startAlgorithm();
    void changeSpeed(int s);
    void setNumOfAlg(QListWidgetItem*);

private:
    void init();
    void connecting();
    void changPosition();
    void clear();
    void addTabs();
    void disable();
    void enable();

    void changeSize(int w, int h);      //This, in width, size = parent.width - OFFSET.
    void changeSize(QRect rect);        //This, in width, size = parent.width - OFFSET.
    void paintRectangle(QPainter* p);

    QWidget* parent;

    AlgorithmArea* alArea = nullptr;

    QLabel* sizeArrLBL;
    QLabel* sliderValueLBL;
    QPushButton* startPB;
    QPushButton* resetPB;
    QLineEdit* inputSizeLE;
    QSlider* sliderSpeedSl;
    QListWidget* sortingListW;

    QFont* font;
    QFontMetrics* fontMetrics = nullptr;

    const unsigned OFFSET = 200;
    const unsigned OFFSET_LOCAL = 30;

    double widthPanel;
    double heightPanel;

    bool onceAddTabs;
};

#endif // PANEL_H
