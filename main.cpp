#include "minimax.h"
#include <iostream>
#include <list>

#include <QtGui/QApplication>
#include "main_window.h"

class Node {

  mutable int _rank;


public:

  explicit Node() { }

  int rank() const { return _rank; }
  void rank(int r) const { _rank = r; }

};

int values_index = 0;

int mock_tree_helper_function(const Node* node) {
  int v = values_index;  
  values_index++;
  return v;
}


std::list<const Node*>* mock_tree_next_nodes(const Node* n, int player) {
  std::list<const Node*>* nodes = new std::list<const Node*>();
  nodes->push_back(new Node());
  nodes->push_back(new Node());
  return nodes;
}


#include "connect4.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();

  return 0;
}
