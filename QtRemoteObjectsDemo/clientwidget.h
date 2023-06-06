#ifndef CLIENTWIDGET_H
#define CLIENTWIDGET_H

#include <QWidget>
#include <QRemoteObjectNode>
#include "rep_pingpong_replica.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ClientWidget; }
QT_END_NAMESPACE

class ClientWidget : public QWidget
{
    Q_OBJECT

public:
    ClientWidget(QWidget *parent = nullptr);
    ~ClientWidget();

private slots:
    void on_btnSendMsg_clicked();

private:
    Ui::ClientWidget *ui;
    QRemoteObjectNode * m_node = nullptr;
    PingPongReplica * m_rep = nullptr;
};
#endif // CLIENTWIDGET_H
