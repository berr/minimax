#ifndef _MINIMAX_H_
#define _MINIMAX_H_

#include <list>
#include <exception>
#include <limits>
#include <iostream>


namespace MiniMax {

  enum Player {

    MAX=0, MIN=1, NONE=2,

  };

  template <class T>
  struct MiniMaxNode {
    int _rank;
    const T* el;

    MiniMaxNode(const T* el, int rank) : el(el), _rank(rank) { }

    int rank() const { return _rank; }
    void rank(int r) const { _rank = r; }
  };

  template <class T>
  const T* minimax(
    const T* start,
    Player starting_player,
    std::list<const T*>* (next_nodes) (const T*, Player player),
    long int (helper_function) (const T*, Player p),
    int depth) {

    std::list<const T*>* children = next_nodes(start, starting_player);
    if (children == 0)  {
      return start;
    }    
    
    if (starting_player == MAX) {
      return minimax_max(start, starting_player, next_nodes, helper_function, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), depth)->el;
    } else {
      return minimax_min(start, starting_player, next_nodes, helper_function, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), depth)->el;
    }
  

  }


  template <class T>
  MiniMaxNode<T>* minimax_min(
    const T* start,
    Player starting_player,
    std::list<const T*>* (next_nodes) (const T*, Player player),
    long int (helper_function) (const T*, Player p),
    int alpha,
    int beta, 
    int depth) {
    
    if (depth == 0) {
      return new MiniMaxNode<T>(start, helper_function(start, starting_player));
    }

    std::list<const T*>* children = next_nodes(start, MIN);
    if (children == 0) {
      return new MiniMaxNode<T>(start, helper_function(start, starting_player));
    }    

    int next_depth;
    if (depth < 0)
      next_depth = -1;
    else
      next_depth = depth - 1;

    MiniMaxNode<T>* best_child = 0;

    typename std::list<const T*>::const_iterator it = children->begin();
    for(; it != children->end(); ++it) {
      MiniMaxNode<T>* child = minimax_max(*it, starting_player, next_nodes, helper_function, alpha, beta, next_depth);
      if (child->rank() <= beta) {        
	beta = child->rank();
	if (best_child) delete best_child;
        best_child = new MiniMaxNode<T>(*it, child->rank());
      } else {
        delete *it;
      }
      if (alpha >= beta) {
        // if alpha >= beta, beta has changed on this iteration and
        // best_child has already been set
	++it;
	break; // pruning
      }
    }

    for(; it != children->end(); ++it) {
      // delete all remaining children
      delete *it;
    }

    delete children;    
    return best_child;

  }

  template <class T>
  MiniMaxNode<T>* minimax_max(
    const T* start,
    Player starting_player,
    std::list<const T*>* (next_nodes) (const T*, Player player),
    long int (helper_function) (const T*, Player p),
    int alpha,
    int beta, 
    int depth) {
  
    if (depth == 0) {
      return new MiniMaxNode<T>(start, helper_function(start, starting_player));
    }

    std::list<const T*>* children = next_nodes(start, MAX);
    if (children == 0) {
      return new MiniMaxNode<T>(start, helper_function(start, starting_player));
    }    

    int next_depth;
    if (depth < 0)
      next_depth = -1;
    else
      next_depth = depth - 1; 


    MiniMaxNode<T>* best_child = 0;

    typename std::list<const T*>::const_iterator it = children->begin();
    for(; it != children->end(); ++it) {
      const MiniMaxNode<T>* child = minimax_min(*it, starting_player, next_nodes, helper_function, alpha, beta, next_depth);
      if (child->rank() >= alpha) {
	alpha = child->rank();
        if(best_child) delete best_child;
        best_child = new MiniMaxNode<T>(*it, child->rank());
      } else {
        delete *it;
      }
      if (alpha >= beta) {
        // if alpha >= beta, beta has changed on this iteration and
        // best_child has already been set
	++it;
	break; // pruning
      }
    }

    for(; it != children->end(); ++it) {
      // delete all remaining children
      delete *it;
    }

    delete children;
    return best_child;  
  }

}

#endif
