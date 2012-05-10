#ifndef _MINIMAX_H_
#define _MINIMAX_H_

#include <list>
#include <exception>
#include <limits>

namespace MiniMax {

  enum Player {

    MAX, MIN,

  };


  template <class MiniMaxNode>
  const MiniMaxNode* minimax(
    const MiniMaxNode* start, 
    Player starting_player,
    std::list<const MiniMaxNode*>* (next_nodes) (const MiniMaxNode*, int player),
    int (helper_function) (const MiniMaxNode*),
    int depth) {

    std::list<const MiniMaxNode*>* children = next_nodes(start, 0);
    if (children == 0)  {
      return start;
    }
    
    
    
    if (starting_player == MAX) {
      return minimax_max(start, next_nodes, helper_function, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), depth);
    } else {
      return minimax_min(start, next_nodes, helper_function, std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), depth);
    }
  

  }


  template <class MiniMaxNode>
  const MiniMaxNode* minimax_min(
    const MiniMaxNode* start, 
    std::list<const MiniMaxNode*>* (next_nodes) (const MiniMaxNode*, int player),
    int (helper_function) (const MiniMaxNode*),
    int alpha,
    int beta, 
    int depth) {
    
    if (depth == 0) {
      start->rank(helper_function(start));
      return start;
    }

    std::list<const MiniMaxNode*>* children = next_nodes(start, MIN);
    if (children == 0) {
      return start;
    }    

    int next_depth;
    if (depth < 0)
      next_depth = -1;
    else
      next_depth = depth - 1;

    const MiniMaxNode* best_child = 0;

    typename std::list<const MiniMaxNode*>::const_iterator it = children->begin();
    for(; it != children->end(); ++it) {
      const MiniMaxNode* child = minimax_min(*it, next_nodes, helper_function, alpha, beta, next_depth);
      if (child->rank() < beta) {
	beta = child->rank();
	if (best_child) delete best_child;
	best_child = child;
      }
      if (alpha >= beta) {
	best_child = *it;
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

  template <class MiniMaxNode>
  const MiniMaxNode* minimax_max(
    const MiniMaxNode* start, 
    std::list<const MiniMaxNode*>* (next_nodes) (const MiniMaxNode*, int player),
    int (helper_function) (const MiniMaxNode*),
    int alpha,
    int beta, 
    int depth) {
  
    if (depth == 0) {
      start->rank(helper_function(start));
      return start;
    }

    std::list<const MiniMaxNode*>* children = next_nodes(start, MAX);
    if (children == 0) {
      return start;
    }    

    int next_depth;
    if (depth < 0)
      next_depth = -1;
    else
      next_depth = depth - 1; 


    const MiniMaxNode* best_child = 0;

    typename std::list<const MiniMaxNode*>::const_iterator it = children->begin();
    for(; it != children->end(); ++it) {
      const MiniMaxNode* child = minimax_max(*it, next_nodes, helper_function, alpha, beta, next_depth);
      if (child->rank() > alpha) {
	alpha = child->rank();
	delete best_child;
	best_child = child;
      }
      if (alpha >= beta) {
	best_child = *it;
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

};
#endif
