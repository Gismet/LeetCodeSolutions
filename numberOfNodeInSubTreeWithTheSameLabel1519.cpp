#include <iostream>
#include <vector>
#include <string>

void DFS(int node, std::vector<std::vector<int>> &adj, std::string labels, std::vector<int> &ans, std::vector<bool> &visited)
{
    visited[node] = true;
    for (auto child : adj[node])
    {
        if (!visited[child])
        {
            DFS(child, adj, labels, ans, visited);
            if (labels[child] == labels[node])
            {
                ans[node] += ans[child];
            }
        }
    }
}

std::vector<int> countSubTrees(int n, std::vector<std::vector<int>> &edges, std::string labels)
{
    std::vector<std::vector<int>> adj(n);
    std::vector<int> ans(n, 1);
    std::vector<bool> visited(n);
    for (auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    DFS(0, adj, labels, ans, visited);
    return ans;
}

int main()
{
    int n = 7;
    std::vector<std::vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    std::string labels = "abaedcd";

    std::vector<std::vector<int>> edges2 = {{0, 1}, {1, 2}, {0, 3}}; // [0,1],[1,2],[0,3]
    std::string labels2 = "bbbb";
    int n2 = 4;

    // n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
    int n3 = 5;
    std::vector<std::vector<int>> edges3 = {{0, 1}, {0, 2}, {1, 3}, {0, 4}};
    std::string labels3 = "aabab";

    std::vector<int> ans = countSubTrees(n3, edges3, labels3);

    for (int i : ans)
    {
        std::cout << i << " ";
    }

    return 0;
}