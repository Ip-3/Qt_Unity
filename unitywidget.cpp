#include "unitywidget.h"
#include "ui_unitywidget.h"

UnityWidget::UnityWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UnityWidget)
{
    ui->setupUi(this);
    unitywindow=new UnityWindow("../Build_windows/My project.exe",this);
//    unitywindow=new UnityWindow("C:/Program Files/BraveSoftware/Brave-Browser/Application/brave.exe",this);
    QQuickView *views=new QQuickView;
    QWidget *container =QWidget::createWindowContainer(views,this);
    unitywindow->setMinimumSize(800,800);
    container->setMinimumSize(600,600);
    views->setSource(QUrl("qrc:/main.qml"));
    views->rootContext()->setContextProperty("myclass",this);
    ui->horizontalLayout->addWidget(unitywindow);
    ui->horizontalLayout->addWidget(container);
    connect(timer_axisright, SIGNAL(timeout()), this, SLOT(sendToData()));
}


UnityWidget::~UnityWidget()
{
    delete ui;
}

QStringList UnityWidget::getBackwardModel() const
{
    return backwardModel;
}

void UnityWidget::setBackwardModel(const QStringList &newBackwardModel)
{
    if (backwardModel == newBackwardModel)
        return;
    backwardModel = newBackwardModel;
    emit backwardModelChanged();
}

QStringList UnityWidget::getForwardModel() const
{
    return forwardModel;
}

void UnityWidget::setForwardModel(const QStringList &newForwardModel)
{
    if (forwardModel == newForwardModel)
        return;
    forwardModel = newForwardModel;
    emit forwardModelChanged();
}

void UnityWidget::datafromqml(QString val)
{
    qDebug()<<Q_FUNC_INFO<<val;
    value_qml=val;
    timer_axisright->start(20);

}

void UnityWidget::connectounity(){
    com_class->connect_to_unity();
}

void UnityWidget::stopTimer_axisright()
{
    timer_axisright->stop();
}

void UnityWidget::sendToData()
{
    com_class->data_from_qml(value_qml);

}



