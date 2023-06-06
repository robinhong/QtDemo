#include "serverwidget.h"
#include "ui_serverwidget.h"

#include <QProcess>
#include <QDir>

ServerWidget::ServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ServerWidget)
{
    ui->setupUi(this);

    m_host = new QRemoteObjectHost(this);
    m_host->setHostUrl(QUrl("local:interfaces"));
    m_source = new PingPong(this);
    m_host->enableRemoting(m_source);
    connect(m_source,&PingPong::receive,this,[=](const QString &msg){
        ui->txtLog->insertPlainText(msg+"\n");
    });
}

ServerWidget::~ServerWidget()
{
    delete ui;
}

void ServerWidget::on_btnStartClient_clicked()
{
    QString appPath = QApplication::applicationDirPath();
    QString subProcessPath = QDir::cleanPath(appPath + QDir::separator() + "RoClient.exe");
    QProcess *subProcess = new QProcess(this);
    subProcess->start(subProcessPath);
}

void ServerWidget::on_btnSendMsg_clicked()
{
    emit m_source->pong(ui->txtMsg->text());
}
