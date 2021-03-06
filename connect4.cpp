#include "connect4.h"
#include <stdexcept>
#include <limits>
#include <math.h>

#define MAX_INT std::numeric_limits<int>::max()
#define MIN_INT std::numeric_limits<int>::min()

State* State::play(int column, MiniMax::Player p) const{
  State* s = new State(*this);  
  s->board[column]->push_back(p);  
  return s;
}


MiniMax::Player State::at(int column, int row) const{
  MiniMax::Player result; 
  try {
    result = this->board[column]->at(row);
  } catch (std::out_of_range& oor) {
	result = MiniMax::NONE;
  }
  return result;
}

list<const State*>* ConnectFourUtils::next_states(const State* s, MiniMax::Player p){
  list<const State*>* states = new list<const State*>();
  bool has_children = false;

  for(int i = 0; i < s->width; ++i) {
    if (s->board[i]->size() >= s->height)
      continue; // out of bounds
    State* new_s = s->play(i,p);
    states->push_back(new_s);
    has_children = true;
  }

  if(not has_children) {
    delete states;
    states = 0;
  }

  return states;  
}


int ConnectFourUtils::utility_function(const State * s, MiniMax::Player p) {
  int score = 0;
  int count_player = 0;
  int count_opponent = 0;

  //vertical count
  for(int i = 0; i < s->width; i++) {
    for(int j = 0; j < s->board[i]->size(); j++) {
	  try {
	    if(s->at(i,j) == p) {
	      count_player++;
	      count_opponent = 0;
	    } else {
		  count_opponent++;
		  count_player = 0;
	    }
	  } catch (std::out_of_range& oor) {
	    count_player = 0;
		count_opponent = 0;
	  }
	}
    if(count_player > 0) {
	  if(count_player >= 4)
	    return MAX_INT;
	  score += pow(count_player,count_player);
	}
	if(count_opponent > 0) {
	  if(count_opponent >= 4)
	    return MIN_INT;
	  score -= pow(count_opponent,count_opponent);
	}
  }

  //missing horizontal, left and right diagonal counts
  return score;
}

ConnectFour::ConnectFour() : _current_state(0) {
  states.push_back(new State(7,7));
}

const State* ConnectFour::play(int column){  
  while(states.size() > _current_state + 1){
    State* back = states.back();
    states.pop_back();
    delete back;
  }

  State* s = states[_current_state]->play(column, current_player());
  states.push_back(s);
  _current_state++;

  return s;
}

const State* ConnectFour::back(){
  if(_current_state == 0)
    return current_state();

  _current_state--;
  return states[_current_state];
}

const State* ConnectFour::forward(){
  if(_current_state >= states.size() -1)
    return current_state();

  _current_state++;
  return states[_current_state];
}

const State* ConnectFour::reset(int width, int height){
  State* first_state =  new State(width, height);
  states.clear();
  
  _current_state = 0;
  states.push_back(first_state);  

  return first_state;
}

MiniMax::Player ConnectFour::current_player() const {
  if (_current_state % 2 == 0)
    return MiniMax::MAX;
  return MiniMax::MIN;
}

const State* ConnectFour::current_state() const {
  return states[_current_state];
}

void State::show() const {
  for (unsigned int i = height - 1; i > 0; --i) {
    for(unsigned int j = 0; j < width; ++j){
      if (board[j]->size() > i)
        std::cout << board[j]->at(i) << " ";
      else
        std::cout << "- ";
    }    
    std::cout << std::endl;
  }
  std::cout << std::endl;
}
