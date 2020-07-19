#include "panel.h"

Panel::Panel(QWidget *parent) : QWidget(parent)
{
    this->parent = parent;

    this->init();
}

Panel::~Panel(){
    Algorithm::gone = false;
    this->clear();
}

void Panel::clear(){
    if(this->fontMetrics == nullptr) return;

    delete this->sizeArrLBL;
    delete this->sliderValueLBL;
    delete this->startPB;
    delete this->resetPB;
    delete this->sliderSpeedSl;
    delete this->inputSizeLE;
    delete this->sortingListW;

    delete this->fontMetrics;
    delete this->font;
}


//Initis
void Panel::init(){
    this->onceAddTabs = true;
    this->changeSize(this->parent->rect());

    this->font = new QFont ("Roboto", 10, QFont::Bold);
    this->fontMetrics = new QFontMetrics(*this->font);

    //First block
    this->sizeArrLBL = new QLabel("Size Array", this->parent);
    this->inputSizeLE = new QLineEdit(this->parent);
    this->inputSizeLE->setValidator(new QIntValidator(-100, 100, this));
    this->inputSizeLE->setText(QString(std::to_string(30).c_str()));

    //Second block
    this->sliderValueLBL = new QLabel("Time: 50", this->parent);
    this->sliderSpeedSl = new QSlider(Qt::Horizontal, this->parent);
    this->sliderSpeedSl->setMaximum(1000);
    this->sliderSpeedSl->setMinimum(0);
    this->sliderSpeedSl->setValue(100);

    //Third block
    this->resetPB = new QPushButton("Reset/Stop", this->parent);
    this->startPB = new QPushButton("Start", this->parent);

    //Fourth block
    this->sortingListW = new QListWidget(this->parent);


    //Set widgets on correct position
    this->changPosition();

    //Connect widget with slot
    this->connecting();
}


void Panel::connecting(){
    connect(this->resetPB, SIGNAL(clicked()), this, SLOT(generateArray()));
    connect(this->startPB, SIGNAL(clicked()), this, SLOT(startAlgorithm()));
    connect(this->sliderSpeedSl, &QSlider::valueChanged, this, &Panel::changeSpeed);
    connect(this->sortingListW, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(setNumOfAlg(QListWidgetItem*)));
}
//End inits


//Setters
void Panel::setAlArea(AlgorithmArea *alArea){
    this->alArea = alArea;
}
//End setters


//Events
void Panel::paintEvent(QPaintEvent *event){
    Q_UNUSED(event);
    QPainter p(this);

    if(!Algorithm::gone)
        this->enable();

    if(this->alArea == nullptr) return;
    this->paintRectangle(&p);           //Paint state of array
}
//End events


//Slots
void Panel::generateArray(){
    Algorithm::gone = false;
    this->enable();
    if(std::stoi(this->inputSizeLE->text().toStdString()) == 0 ||   this->inputSizeLE->text().length() == 0)
        return;
    this->alArea->generateArray(std::stoi(this->inputSizeLE->text().toStdString()));
    this->update();
}
void Panel::startAlgorithm(){
    this->alArea->execute();
    this->disable();
    this->update();
}
void Panel::changeSpeed(int s){
    this->sliderValueLBL->setText("Time: " + QString(std::to_string(s).c_str()));
    Algorithm::Time = s;
    this->update();
}
void Panel::setNumOfAlg(QListWidgetItem* name){
    this->alArea->setNumOfAlg(this->alArea->indexOf(name->text().toStdString()));
}
//End slots


//Paint
void Panel::paintRectangle(QPainter *p){
    p->setBrush(QBrush("#222"));
//    p->setPen(QPen(QBrush("#3c5abc"), 1, Qt::SolidLine));
    p->drawRect(0,0, this->widthPanel,this->heightPanel);                                       //Background

    p->translate(0, this->heightPanel / 2);

    p->setFont(*this->font);

    double widthRect = this->widthPanel / this->alArea->getSize();
    double xCord = 0;
    double yCord = this->heightPanel / 100;                                                        //Edge of height rectangles

    int* arr = this->alArea->getArr();
    int* selected = this->alArea->getSelected();
    int i;

    int j = 0;
    for (i = 0; i < this->alArea->getSize(); i++) {
        if(j < this->alArea->getSizeSelected() && selected[j] == i){
            j++;
            p->setBrush(QBrush("#74d7ff"));                                                     //Color of selected rectangles
        }
        else
            p->setBrush(QBrush("#3c5abc"));                                                     //Color of rectangles

        p->drawRect(xCord, 0, widthRect - 4, arr[i] * yCord / 2 * -1);                          //Representation of numbers as rectangles

        xCord += widthRect;

        p->setPen(Qt::black);
    }
}
//End paint


//Design
void Panel::updatePanel(){
    this->changeSize(this->parent->rect());
    this->changPosition();

    if(this->onceAddTabs)
        this->addTabs();

    this->update();
}

void Panel::changPosition(){
    //Some settings for blocks
    int offsetX = this->widthPanel + this->OFFSET / 2;
    int widthLE = 113;      //Local width of Line Edits
    int heightLE = 22;      //Local width of Line Edits


    //First block
    this->sizeArrLBL->setGeometry(offsetX - this->fontMetrics->horizontalAdvance("Size Array") - this->OFFSET_LOCAL,
                                  this->heightPanel * 15 / 100 - 40, this->fontMetrics->horizontalAdvance("Size Array"), 15);
    this->inputSizeLE->setGeometry(offsetX - widthLE/2 - this->OFFSET_LOCAL, this->heightPanel * 15 / 100 - heightLE, widthLE, heightLE);

    //Second block
    this->sliderValueLBL->setGeometry(offsetX - this->fontMetrics->horizontalAdvance(this->sliderValueLBL->text()) + 10 - this->OFFSET_LOCAL,
                                       this->heightPanel * 36 / 100 - 40, this->fontMetrics->horizontalAdvance(this->sliderValueLBL->text()) + 10, 15);
    this->sliderSpeedSl->setGeometry(offsetX - widthLE/2 - 4 - this->OFFSET_LOCAL, this->heightPanel * 36 / 100 - heightLE, 150, 20);

    //Third block
    this->resetPB->setGeometry(offsetX - widthLE/2 - this->OFFSET_LOCAL, this->heightPanel * 43 / 100 - heightLE, widthLE/1.5, heightLE);
    this->startPB->setGeometry(offsetX + 30 - this->OFFSET_LOCAL, this->heightPanel * 43 / 100 - heightLE, widthLE/2, heightLE);

    //Fourth block
    this->sortingListW->setGeometry(offsetX - widthLE/2 - this->OFFSET_LOCAL, this->heightPanel * 93 / 100 - 280, 140, 300);
}
void Panel::addTabs(){
    if(this->alArea == nullptr) return;

    std::vector<Algorithm*> v_alg = this->alArea->getV_SortAlgorithms();
    for(auto it: v_alg){
        this->sortingListW->addItem(it->name.c_str());
    }

    this->sortingListW->setCurrentRow(0);

    this->onceAddTabs = false;
}
void Panel::changeSize(int w, int h){
    this->widthPanel = w - this->OFFSET;
    this->heightPanel = h;
    this->resize(w - this->OFFSET, h);
}
void Panel::changeSize(QRect rect){
    this->widthPanel = rect.width() - this->OFFSET;
    this->heightPanel = rect.height();
    this->resize(rect.width() - this->OFFSET, rect.height());
}
void Panel::disable(){
    this->inputSizeLE->setDisabled(true);
    this->sortingListW->setDisabled(true);
    this->startPB->setDisabled(true);
}
void Panel::enable(){
    this->inputSizeLE->setEnabled(true);
    this->sortingListW->setEnabled(true);
    this->startPB->setEnabled(true);
}
//End design
