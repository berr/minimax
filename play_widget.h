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
    int column;
    QPoint last_point_clicked;
    bool _clicked;

public:
    explicit PlayWidget(MiniMax::Player, int column, QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);

signals:
    void clicked(int);

public slots:    

};

#endif // PLAY_WIDGET_H
