#include "play_widget.h"
#include <QPainter>
#include <QMouseEvent>

PlayWidget::PlayWidget(MiniMax::Player p, int column, QWidget *parent) :
  QWidget(parent), column(column), _clicked(false)
{  
  this->setAutoFillBackground(true);

  if (p == MiniMax::MAX) {
    circle_color = QColor(255,0,0);
  } else if (p == MiniMax::MIN) {
    circle_color = QColor(0,0,255);
  } else {
    circle_color = QColor(255,255,255);
  }
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

  QBrush brush(circle_color);
  QPalette pallete(this->palette());
  pallete.setColor(QPalette::Background, QColor(255,255,255));

  this->setPalette(pallete);
  painter.setBackgroundMode(Qt::OpaqueMode);
  painter.setPen(circle_color);
  painter.setBrush(brush);

  painter.drawEllipse(width_difference / 2, height_difference / 2, width, height);

}

void PlayWidget::mouseDoubleClickEvent(QMouseEvent *){
  emit clicked(column);
}

void PlayWidget::mousePressEvent(QMouseEvent* e) {
  last_point_clicked = e->pos();
}

void PlayWidget::mouseReleaseEvent(QMouseEvent* e) {
  if (e->pos().x() >= 0 && e->pos().x() <= width() &&
      e->pos().y() >= 0 && e->pos().y() <= height()){
    emit clicked(column);
  }
}
