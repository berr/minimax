#ifndef _CONNECT_4_H_
#define _CONNECT_4_H_

#include "minimax.h"

#include <vector>
#include <list> 

using std::vector;
using std::list;

#include <iostream>

struct State {

  vector<vector <MiniMax::Player>* > board;
  int height;
  int width;
  mutable int _rank;

  State(int width, int height) : height(height) , width(width), _rank(-1) {
    for (int i = 0; i < width; ++i) {
      board.push_back(new vector<MiniMax::Player>());
    }
  } 

  State(const State& s) : _rank(-1){
    height = s.height;
    width = s.width;
    for (int i = 0; i < width; ++i) {
      board.push_back(new vector<MiniMax::Player>());
      for (unsigned int j = 0; j < s.board[i]->size(); ++j){
        board[i]->push_back(s.board.at(i)->at(j));
      }
    }
  }

  State* play(int column, MiniMax::Player p) const;
  
  void show();

  int rank() const {
    if (_rank < 0)
      return _rank + 1;
    return _rank; }
  void rank(int r) const { _rank = r; }
};

namespace ConnectFourUtils{

  list<const State*>* next_states(const State*, MiniMax::Player p);

  int utility_function(const State*);

}


class ConnectFour {

  int _current_state;
  std::vector<State*> states;
  
public:

  ConnectFour();

  const State* play(int column);
  const State* back();
  const State* forward();
  
  const State* reset(int width, int height);

  const State* current_state() const;
  MiniMax::Player current_player() const;


};

#endif
