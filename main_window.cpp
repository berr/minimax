#include "main_window.h"
#include "ui_interface.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) { 
  ui->setupUi(this);
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
  std::cout << "reset" << std::endl;
}

void MainWindow::on_play_button_clicked() {
  std::cout << "play" << std::endl;
}


