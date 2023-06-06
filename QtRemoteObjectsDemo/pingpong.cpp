#include "pingpong.h"

PingPong::PingPong(QObject *parent) : PingPongSource(parent)
{

}

void PingPong::ping(const QString &msg)
{
    emit receive(msg);
    //接收完反馈回客户端
    emit pong("ping from server:");
}
