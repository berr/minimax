#include "play_widget.h"
#include <QPainter>

PlayWidget::PlayWidget(QWidget *parent) :
    QWidget(parent)
{  
  this->setAutoFillBackground(true);
}

void PlayWidget::paintEvent(QPaintEvent* event) {
  QWidget::paintEvent(event);

  QPainter painter(this);

  painter.setPen(QColor(0,0,0));
  painter.drawRect(0,0,width()-1, height()-1);

  int width = this->width() * .9;
  int width_difference = this->width() - width;
  int height = this->height() * .9;
  int height_difference = this->height() - height;

  QColor circle_color(255, 0 ,0);
  QBrush brush(circle_color);
  QPalette pallete(this->palette());
  pallete.setColor(QPalette::Background, QColor(255,255,255));

  this->setPalette(pallete);
  painter.setBackgroundMode(Qt::OpaqueMode);
  painter.setPen(circle_color);
  painter.setBrush(brush);

  painter.drawEllipse(width_difference / 2, height_difference / 2, width, height);

}
