#include "main_window.h"
#include "ui_interface.h"
#include "play_widget.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) { 
  ui->setupUi(this);
  on_reset_button_clicked();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_forward_button_clicked() {
  std::cout << "forward" << std::endl;
}

void MainWindow::on_back_button_clicked() {
  std::cout << "back" << std::endl;
}

void MainWindow::on_reset_button_clicked() {
  int height = ui->table_height_sp->value();
  int width = ui->table_width_sp->value();

  game.reset(width, height);

  reset_table(width, height);
}

void MainWindow::on_play_button_clicked() {
  std::cout << "play" << std::endl;
}

void MainWindow::reset_table(int width, int height) {
  QLayout* old_layout = ui->table_frame->layout();
  if (old_layout)
    delete old_layout;

  QGridLayout* layout = new QGridLayout(ui->table_frame);
  layout->setSpacing(0);
  layout->setVerticalSpacing(0);

  for(int i = 0; i < width; ++i){
    for(int j = 0; j < height; ++j){
      layout->addWidget(new PlayWidget(), j, i);
    }
  }
}

