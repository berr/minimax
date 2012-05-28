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
  draw_state(game.forward());
}

void MainWindow::on_back_button_clicked() {
  draw_state(game.back());
}

void MainWindow::on_reset_button_clicked() {
  int height = ui->table_height_sp->value();
  int width = ui->table_width_sp->value();

  const State* s = game.reset(width, height);

  draw_state(s);
}

void MainWindow::on_play_button_clicked() {
  int depth;

  if (ui->full_search_cb->isChecked())
    depth = -1;
  else
    depth = ui->depth_sp->value();

  const State* play = MiniMax::minimax<State>(game.current_state(), game.current_player(), ConnectFourUtils::next_states, ConnectFourUtils::utility_function, depth);
  const State* current_state = game.current_state();

  int play_column = -1;

  play->show();

  for(int i = 0; i < play->width; ++i){
    if (play->board[i]->size() != current_state->board[i]->size()) {
      play_column = i;
      break;
    }
  }

  draw_state(game.play(play_column));
}

void MainWindow::draw_state(const State* s) {
  QLayout* old_layout = ui->table_frame->layout();
  if (old_layout)
    delete old_layout;

  QGridLayout* layout = new QGridLayout(ui->table_frame);
  layout->setMargin(0);
  layout->setSpacing(0);
  layout->setVerticalSpacing(0);

  for(unsigned int j = 0; j < s->board.size(); ++j){
    for(unsigned int i = 0; i < s->board[j]->size(); ++i){
      PlayWidget* w = new PlayWidget(s->board.at(j)->at(i), j);
      layout->addWidget(w, s->height - i, j);
      connect(w, SIGNAL(clicked(int)), this, SLOT(play(int)));
    }
    for(unsigned int i = s->board[j]->size(); i < s->height; ++i){
      PlayWidget* w = new PlayWidget(MiniMax::NONE, j);
      layout->addWidget(w, s->height - i, j);
      connect(w, SIGNAL(clicked(int)), this, SLOT(play(int)));
    }
  }

}

void MainWindow::play(int column) {
  draw_state(game.play(column));
}

