#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max_size 10

typedef struct graph
{
  int nodes;
  bool a[max_size][max_size];
} graph;

graph *create(int x)
{
  graph *m = malloc(sizeof(graph));
  m->nodes = x;
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < x; j++)
    {
      m->a[i][j] = false;
    }
  }
  return m;
}
void delete_graph(graph *g)
{
  free(g);
}

void display(graph *g)
{
  for (int i = 0; i < (g->nodes); i++)
  {
    for (int j = 0; j < (g->nodes); j++)
    {
      if (g->a[i][j])
      {
        printf("1  ");
      }
      else
      {
        printf("0  ");
      }
    }
    printf("\n");
  }
  printf("\n");
}
void create_edge(graph *g, int i, int j)
{
  g->a[i][j] = true;
}

void Traverse_BFS(graph *g, int s)
{
  printf("BFS OF THE GRAPH IS : \n");
  bool visited[max_size];
  for (int i = 0; i < g->nodes; i++)
  {
    visited[i] = false;
  }

  // QUEUE
  int queue[max_size];
  int front = 0, rear = 0;

  visited[s] = true;
  queue[rear++] = s;

  while (front != rear)
  {
    s = queue[front++];
    printf("%c  ", s + 65);

    for (int ad = 0; ad < g->nodes; ad++)
    {
      if (g->a[s][ad] && !visited[ad])
      {
        visited[ad] = true;
        queue[rear++] = ad;
      }
    }
  }
  printf("\n-----------------\n\n");
}
void Traverse_DFS(graph *g, int r)
{
  printf("DFS OF THE GRAPH IS : \n");
  bool visited[max_size];
  for (int i = 0; i < g->nodes; i++)
  {
    visited[i] = false;
  }
  // STACK
  int stack[max_size];
  int top = -1;

  stack[++top] = r;

  while (top != -1)
  {
    r = stack[top--];
    if (!visited[r])
    {
      printf("%c  ", r + 65);
      visited[r] = true;
    }
    for (int ad = 0; ad < g->nodes; ad++)
    {
      if (g->a[r][ad] && !visited[ad])
      {
        stack[++top] = ad;
      }
    }
  }
  printf("\n-----------------\n\n");
}
int main()
{
  graph *G;
  G = create(6);
  display(G);
  create_edge(G, 0, 1);
  create_edge(G, 0, 2);
  create_edge(G, 1, 2);
  create_edge(G, 2, 0);
  create_edge(G, 2, 3);
  create_edge(G, 3, 3);
  printf("\n\n");
  display(G);
  printf("\n\n");
  Traverse_BFS(G, 2);
  delete_graph(G);
  /* BFS TRAVERSAL */
  G = create(6);
  display(G);
  create_edge(G, 1, 0);
  create_edge(G, 0, 2);
  create_edge(G, 2, 1);
  create_edge(G, 0, 3);
  create_edge(G, 1, 4);
  create_edge(G, 3, 5);
  display(G);
  Traverse_DFS(G, 0);

  return 0;
}