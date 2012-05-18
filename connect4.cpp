#include "connect4.h"

void State::play(int column, MiniMax::Player p) {
  board[column]->push_back(p);
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
