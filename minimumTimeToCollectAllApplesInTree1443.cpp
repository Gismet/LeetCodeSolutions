#include <iostream>
#include <vector>

int DFS(int node, std::vector<std::vector<int>> &adj, std::vector<bool> &hasApple, std::vector<bool> &visited)
{
    int totalTime = 0, childTime = 0;
    visited[node] = true;
    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            childTime = DFS(child, adj, hasApple, visited);
            if (childTime > 0 || hasApple[child])
                totalTime += childTime + 2;
        }
    }
    return totalTime;
}

int minTime(int n, std::vector<std::vector<int>> &edges, std::vector<bool> &hasApple)
{
    std::vector<std::vector<int>> adj(n);
    std::vector<bool> visited(n);
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    return DFS(0, adj, hasApple, visited);
}

int main()
{
    int n = 7;
    std::vector<bool> hasApple = {false, false, true, false, true, true, false};
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};

    std::cout << minTime(n, edges, hasApple);
}
