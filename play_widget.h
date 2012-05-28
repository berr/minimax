#ifndef PLAY_WIDGET_H
#define PLAY_WIDGET_H

#include <QWidget>
#include <QFrame>
#include <QColor>
#include <QPainter>
#include "minimax.h"

class PlayWidget : public QWidget
{
    Q_OBJECT

private:
    QColor circle_color;
public:
    explicit PlayWidget(MiniMax::Player, QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:

};

#endif // PLAY_WIDGET_H
