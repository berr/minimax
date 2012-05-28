#ifndef PLAY_WIDGET_H
#define PLAY_WIDGET_H

#include <QWidget>
#include <QFrame>

class PlayWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlayWidget(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);

signals:

public slots:

};

#endif // PLAY_WIDGET_H
