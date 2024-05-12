#include <stdbool.h>
#include <stdio.h>

#define MAX_VERTICES 100

int V;
int solutionCount = 0;

void printSolution(int color[])
{
    printf("\nSolution %d:\n Following are the assigned colors: \n", ++solutionCount);
    for (int i = 0; i < V; i++)
        printf(" %d ", color[i]);
    printf("\n");
}

bool isSafe(int v, bool graph[][MAX_VERTICES], int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[][MAX_VERTICES], int m, int color[], int v)
{
    if (v == V)
    {
        printSolution(color);
        return true;
    }

    bool res = false;
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(v, graph, color, c))
        {
            color[v] = c;
            res = graphColoringUtil(graph, m, color, v + 1) || res;
            color[v] = 0;
        }
    }

    return res;
}

void graphColoring(bool graph[][MAX_VERTICES], int m)
{
    int color[MAX_VERTICES] = {0};

    if (!graphColoringUtil(graph, m, color, 0))
    {
        printf("Solution does not exist");
    }
}

int main()
{
    int m;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    bool graph[MAX_VERTICES][MAX_VERTICES];

    printf("\nEnter the adjacency matrix (1 for edge, 0 for no edge):\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
        {
            int input;
            scanf("%d", &input);
            graph[i][j] = input == 1;
        }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    graphColoring(graph, m);

    return 0;
}
