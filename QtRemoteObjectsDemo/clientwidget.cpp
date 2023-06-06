#include "clientwidget.h"
#include "ui_clientwidget.h"

ClientWidget::ClientWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientWidget)
{
    ui->setupUi(this);

    m_node = new QRemoteObjectNode(this);
    m_node->connectToNode(QUrl("local:interfaces"));
    m_rep = m_node->acquire<PingPongReplica>();
    connect(m_rep,&PingPongReplica::pong,this,[=](QString msg){
        ui->txtLog->insertPlainText(msg+"\n");
    });
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_btnSendMsg_clicked()
{
    m_rep->ping(ui->txtMsg->text());
}
