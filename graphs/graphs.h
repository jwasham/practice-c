#include <assert.h>
#include <stdlib.h>

#ifndef PROJECT_GRAPHS_H
#define PROJECT_GRAPHS_H

typedef struct {
  int v; /* vertex count */
  int e; /* edge count */

  struct neighbors {
    int length;
    int list[];
  } * adjacency_list[];

} UndirectedGraph;

UndirectedGraph* ugraph_create(int v);

void ugraph_destroy(UndirectedGraph* g);

#endif  // PROJECT_GRAPHS_H
