#include <stdio.h>
#define INF 999
#define size 5

void print_graph(int graph[][size])
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (graph[i][j] == INF)
      {
        printf(" ∞ ");
      }
      else
      {
        printf(" %d ", graph[i][j]);
      }
    }
    printf("\n");
  }
  printf("\n\n");
}

void print_edges(int graph[][size])
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      printf("%c -> %c ==> ", i + 65, j + 65);
      if (graph[i][j] == INF)
      {
        printf(" ∞\n");
      }
      else
      {
        printf(" %d \n", graph[i][j]);
      }
    }
  }
  printf("\n\n");
}

int floyd_warshall(int graph[][size])
{
  int graph1[size][size], i, j, k;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      graph1[i][j] = graph[i][j];
    }
  }
  for (int k = 0; k < size; k++)
  {
    for (int i = 0; i < size; i++)
    {
      for (int j = 0; j < size; j++)
      {
        if ((graph1[i][k] + graph1[k][j]) < graph1[i][j])
        {
          graph1[i][j] = graph1[i][k] + graph1[k][j];
        }
      }
    }
  }
  print_graph(graph1);
  print_edges(graph1);
}

int main()
{
  int graph[size][size] = {
      {0, 11, 4, INF, INF},
      {INF, 0, 5, 3, 4},
      {4, INF, 0, 2, INF},
      {INF, 4, INF, 0, 9},
      {INF, INF, INF, 2, 0}};
  print_graph(graph);
  print_edges(graph);

  floyd_warshall(graph);

  return 0;
}