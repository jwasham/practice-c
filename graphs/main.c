#include <stdio.h>
#include "graphs.h"

int main(int argc, char* argv[]) {
  const int u_vertices = 9;
  const int d_vertices = 9;

  UndirectedGraph* g = ugraph_create(u_vertices);

  printf("Undirected graph with %d vertices:\n", u_vertices);

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

  ugraph_print_dfs(g);

  ugraph_destroy(g);

  printf("\n\nDirected graph with %d vertices:\n", d_vertices);

  DirectedGraph* dg = digraph_create(d_vertices);

  digraph_add_edge(dg, 0, 1);
  digraph_add_edge(dg, 0, 5);
  digraph_add_edge(dg, 1, 2);
  digraph_add_edge(dg, 2, 4);
  digraph_add_edge(dg, 2, 6);
  digraph_add_edge(dg, 3, 2);
  digraph_add_edge(dg, 6, 5);
  digraph_add_edge(dg, 5, 8);
  digraph_add_edge(dg, 7, 5);

  digraph_print_dfs(dg);

  digraph_destroy(dg);

  return 0;
}
