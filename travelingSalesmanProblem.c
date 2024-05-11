#include <stdio.h>
#include <limits.h>

#define V 4 // Number of vertices in the graph

int tsp(int graph[][V], int mask, int pos, int n, int dp[][V])
{
    // If all vertices have been visited
    if (mask == (1 << n) - 1)
    {
        return graph[pos][0]; // Return to the starting vertex
    }

    // If the solution for this subproblem has been previously calculated
    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    // Initialize answer for this subproblem
    int ans = INT_MAX;

    // Try all unvisited cities as the next city from the current city
    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0) // If the city has not been visited yet
        {
            // Calculate the cost of visiting the next city and recurse
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, n, dp);
            // Update the minimum cost
            ans = ans < newAns ? ans : newAns;
        }
    }

    // Memoize the result for future use
    return dp[mask][pos] = ans;
}

int main()
{
    int graph[V][V] = {
        {0, 1, 2, 3},
        {1, 0, 2, 3},
        {2, 2, 0, 3},
        {3, 3, 3, 0}};

    // Initialize the memoization table
    int dp[1 << V][V];
    for (int i = 0; i < (1 << V); i++)
    {
        for (int j = 0; j < V; j++)
        {
            dp[i][j] = -1;
        }
    }

    // Start with all vertices unvisited
    int minCost = tsp(graph, 0, 0, V, dp);
    printf("Minimum cost: %d\n", minCost);

    return 0;
}
