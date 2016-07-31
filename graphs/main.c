#include "graphs.h"

int main(int argc, char* argv[]) {

  const int vertices = 9;

  UndirectedGraph* g = ugraph_create(vertices);

  ugraph_add_edge(g, 0, 1);
  ugraph_add_edge(g, 1, 2);
  ugraph_add_edge(g, 1, 7);
  ugraph_add_edge(g, 2, 3);
  ugraph_add_edge(g, 3, 4);
  ugraph_add_edge(g, 3, 5);
  ugraph_add_edge(g, 3, 7);
  ugraph_add_edge(g, 4, 5);
  ugraph_add_edge(g, 5, 6);
  ugraph_add_edge(g, 6, 7);
  ugraph_add_edge(g, 6, 8);
  ugraph_add_edge(g, 7, 8);

  ugraph_print_debug(g);

  ugraph_destroy(g);

  return 0;
}
