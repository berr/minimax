#ifndef _CONNECT_4_H_
#define _CONNECT_4_H_

#include "minimax.h"

#include <vector>
#include <list> 

using std::vector;
using std::list;

struct State {

  vector<vector <MiniMax::Player>* > board;
  int height;
  int width;

  State(int height, int width) : height(height) , width(width) { 
    for (int i = 0; i < width; ++i) {
      board.push_back(new vector<MiniMax::Player>(height));
    }
  } 

  State(const State& s) : height(s.height), width(s.width) {
    for (int i = 0; i < width; ++i) {
      board.push_back(new vector<MiniMax::Player>(*(s.board[i])));
    }
  }

  State* play(int column, MiniMax::Player p);
  

};


list<const State*>* next_states(const State*, MiniMax::Player p);

int utility_function(const State*);


class ConnectFour {

  int current_state;
  std::vector<State*> states;
  MiniMax::Player current_player;
  
public:

  ConnectFour();

  const State* play(int column);
  const State* back();
  const State* forward();
  
  const State* reset(int width, int height);

};

#endif
