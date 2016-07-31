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
    int length;
    int capacity;
    int list[];
  } * adjacency_list[];

} UndirectedGraph;

typedef struct {
  int v; /* vertex count */
  int e; /* edge count */

  struct targets {
    int length;
    int capacity;
    int list[];
  } * adjacency_list[];

} DirectedGraph;

UndirectedGraph* ugraph_create(int v);

void ugraph_destroy(UndirectedGraph* g);

void ugraph_add_edge(UndirectedGraph* g, const int src, const int dest);

void _ugraph_append_edge(UndirectedGraph* g, const int src, const int dest);

void ugraph_print_dfs(UndirectedGraph* g);

void ugraph_dfs(UndirectedGraph* g, int visited[], const int vertex);

DirectedGraph* digraph_create(const int v);

void digraph_destroy(DirectedGraph* g);

void digraph_add_edge(DirectedGraph* g, const int src, const int dest);

void digraph_print_dfs(DirectedGraph* g);

void digraph_dfs(DirectedGraph* g, int visited[], const int vertex);

#endif  // PROJECT_GRAPHS_H
