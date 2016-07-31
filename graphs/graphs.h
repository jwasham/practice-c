#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef PROJECT_GRAPHS_H
#define PROJECT_GRAPHS_H

typedef struct {
  int v; /* vertex count */
  int e; /* edge count */

  struct neighbors {
    int count;
    int capacity;
    int list[];
  } * adjacency_list[];

} UndirectedGraph;

typedef struct {
  int v; /* vertex count */
  int e; /* edge count */

  struct targets {
    int count;
    int capacity;
    int list[];
  } * adjacency_list[];

} DirectedGraph;

UndirectedGraph* ugraph_create(int v);

void ugraph_destroy(UndirectedGraph* g);

void ugraph_add_edge(UndirectedGraph* g, const int src, const int dest);

void _ugraph_append_edge(UndirectedGraph* g, const int src, const int dest);

void ugraph_print_debug(UndirectedGraph* g);

void ugraph_dfs(UndirectedGraph* g, int visited[], const int vertex);

DirectedGraph* digraph_create(int v);

void digraph_destroy(DirectedGraph* g);

void digraph_add_edge(DirectedGraph* g, const int src, const int dest);

void digraph_print_debug(DirectedGraph* g);

#endif  // PROJECT_GRAPHS_H
