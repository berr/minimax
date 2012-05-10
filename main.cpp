#include "minimax.h"
#include <iostream>
#include <list>

class Node {

  mutable int _rank;


public:

  explicit Node() { }

  int rank() const { return _rank; }
  void rank(int r) const { _rank = r; }

};

int values_index = 0;

int mock_tree_helper_function(const Node* node) {
  return values_index++;
}


std::list<const Node*>* mock_tree_next_nodes(const Node* n, int player) {
  std::list<const Node*>* nodes = new std::list<const Node*>();
  nodes->push_back(new Node());
  nodes->push_back(new Node());
  return nodes;
}




int main() {
  Node start;
  const Node* n = MiniMax::minimax<Node>(&start,MiniMax::MAX,mock_tree_next_nodes,mock_tree_helper_function, 2);

  std::cout << "rank=" << n->rank() << std::endl;

  return 0;
}
