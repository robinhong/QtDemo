#ifndef SERVERWIDGET_H
#define SERVERWIDGET_H

#include <QWidget>
#include <QRemoteObjectHost>
#include "pingpong.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ServerWidget; }
QT_END_NAMESPACE

class ServerWidget : public QWidget
{
    Q_OBJECT

public:
    ServerWidget(QWidget *parent = nullptr);
    ~ServerWidget();

private slots:
    void on_btnStartClient_clicked();

    void on_btnSendMsg_clicked();

private:
    Ui::ServerWidget *ui;
    PingPong * m_source = nullptr;
    QRemoteObjectHost * m_host = nullptr;
};
#endif // SERVERWIDGET_H
