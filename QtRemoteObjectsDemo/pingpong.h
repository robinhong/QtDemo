#ifndef ROINTERFACE_H
#define ROINTERFACE_H

#include "rep_pingpong_source.h"
#include <QObject>

class PingPong : public PingPongSource
{
    Q_OBJECT
public:
    explicit PingPong(QObject *parent = nullptr);

public slots:
    void ping(const QString &msg) override;

signals:
    void receive(const QString &msg);

};

#endif // ROINTERFACE_H
