#ifndef UNITYWIDGET_H
#define UNITYWIDGET_H

#include <QWidget>
#include <QQuickView>
#include <QDebug>
#include<QQmlContext>
#include<QTimer>
#include"UnityWindow.h"
#include"comm_class.h"


QT_BEGIN_NAMESPACE
namespace Ui { class UnityWidget; }
QT_END_NAMESPACE

class UnityWidget : public QWidget
{
    Q_OBJECT

public:
    UnityWidget(QWidget *parent = nullptr);
    UnityWindow *unitywindow;
    ~UnityWidget();
    Comm_class *com_class=new Comm_class();
    QTimer *timer_axisright = new QTimer;
    QString value_qml;
    QStringList forwardModel={"Pole1 Forward","Pole2 Forward","Pole3 Forward","Pole4 Forward"};
    QStringList backwardModel={"Pole1 Backward","Pole2 Backward","Pole3 Backward","Pole4 Backward"};
    QStringList getForwardModel() const;
    void setForwardModel(const QStringList &newForwardModel);
    QStringList getBackwardModel() const;
    void setBackwardModel(const QStringList &newBackwardModel);

public slots:
    void datafromqml(QString val);
    void connectounity();
//    void startTimer_axisright();
    void stopTimer_axisright();
    void sendToData();

signals:
    void forwardModelChanged();

    void backwardModelChanged();

private:
    Ui::UnityWidget *ui;
    Q_PROPERTY(QStringList forwardModel READ getForwardModel WRITE setForwardModel NOTIFY forwardModelChanged)
    Q_PROPERTY(QStringList backwardModel READ getBackwardModel WRITE setBackwardModel NOTIFY backwardModelChanged)
};
#endif // UNITYWIDGET_H
