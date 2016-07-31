#include "graphs.h"

UndirectedGraph* ugraph_create(const int v) {
  UndirectedGraph* g =
      malloc(sizeof(UndirectedGraph) + sizeof(struct neighbor*) * v);
  assert(g);

  g->v = v;
  g->e = 0;

  for (int i = 0; i < v; ++i) {
    g->adjacency_list[i] = malloc(sizeof(struct neighbors));
    assert(g->adjacency_list[i]);

    g->adjacency_list[i]->count = 0;
    g->adjacency_list[i]->capacity = 0;
  }

  return g;
}

void ugraph_destroy(UndirectedGraph* g) {
  for (int i = 0; i < g->v; ++i) {
    free(g->adjacency_list[i]);
  }
  free(g);
}

void ugraph_add_edge(UndirectedGraph* g, const int src, const int dest) {
  assert(src >= 0);
  assert(dest >= 0);
  assert(src != dest);
  assert(src < g->v);
  assert(dest < g->v);

  _ugraph_append_edge(g, src, dest);
  _ugraph_append_edge(g, dest, src);
}

void _ugraph_append_edge(UndirectedGraph* g, const int src, const int dest) {
  // resizes array if needed
  if (g->adjacency_list[src]->count == g->adjacency_list[src]->capacity) {
    g->adjacency_list[src]->capacity = g->adjacency_list[src]->capacity * 2 + 1;

    g->adjacency_list[src] = realloc(g->adjacency_list[src], sizeof(struct neighbors) + sizeof(int) * g->adjacency_list[src]->capacity);
  }

  g->adjacency_list[src]->list[g->adjacency_list[src]->count++] = dest;

  g->e++;
}

void ugraph_print_debug(UndirectedGraph* g) {
  int visited[g->v];
  memset(visited, 0, sizeof(visited));

  ugraph_dfs(g, visited, 0);
}

void ugraph_dfs(UndirectedGraph* g, int visited[], const int vertex) {
  visited[vertex] = 1;
  printf("%d -> ", vertex);

  for (int e = 0; e < g->adjacency_list[vertex]->count; ++e) {
    int u = g->adjacency_list[vertex]->list[e];

    if (visited[u] == 0) {
      ugraph_dfs(g, visited, u);
    }
  }

  putchar('\n');
}

