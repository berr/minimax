#include "connect4.h"

State* State::play(int column, MiniMax::Player p) {
  State* s = new State(*this);  
  s->board[column]->push_back(p);
  s->show();
  return s;
}

list<const State*>* next_states(const State* s, MiniMax::Player p){
  list<const State*>* states = new list<const State*>();
  bool has_children = false;

  for(int i = 0; i < s->width; ++i) {
    if (s->board[i]->size() >= s->height)
      continue; // out of bounds
    State* new_s = new State(*s);
    new_s->play(i, p);
    states->push_back(new_s);
    has_children = true;
  }

  if(not has_children) {
    delete states;
    states = 0;
  }
  return states;  
}

ConnectFour::ConnectFour() : current_state(0) {
  states.push_back(new State(7,7));
}

const State* ConnectFour::play(int column){  
  State* s = states[current_state]->play(column, current_player());
  states.push_back(s);
  current_state++;

  return s;
}

const State* ConnectFour::back(){
  current_state--;
  return states[current_state];
}

const State* ConnectFour::forward(){
  current_state++;
  return states[current_state];
}

const State* ConnectFour::reset(int width, int height){
  State* first_state =  new State(width, height);
  states.clear();
  
  current_state = 0;
  states.push_back(first_state);  

  return first_state;
}

MiniMax::Player ConnectFour::current_player() const {
  if (current_state % 2 == 0)
    return MiniMax::MAX;
  return MiniMax::MIN;
}

void State::show() {  
  for (unsigned int i = 0; i < board.size(); ++i) {
    for(unsigned int j = 0; j < board[i]->size(); ++j){
      std::cout << board[i]->at(j) << " ";
    }
    for(unsigned int j = board[i]->size(); j < height; ++j){
      std::cout << MiniMax::NONE << " ";
    }
    std::cout << std::endl;
  }
}
