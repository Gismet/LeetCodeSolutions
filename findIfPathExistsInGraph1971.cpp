#include <iostream>
#include <vector>
#include <queue>

// we have a list of edges represented as a 2D array edges,
// where each edge[i] represents a bi-directional edge between vertices u and v.
// There is no duplicate edge nor self-edge.
// Let's say we edges = [[0,1],[1,2],[2,0]], then edges[0] = [0,1] means there is an edges between vertex 0 and vertex 1
// we have n vertices labeled from 0 to n - 1 inclusive
// for example, for n = 3, we vertices 0, 1, 2
// we want to find out if there is a valid path from source to destiantion

bool BFS(std::vector<std::vector<int>> adjList, int source, int destination, std::vector<bool> &visited)
{
    // if the source is equal to destiantion, then return true
    if (source == destination)
        return true;

    // we need a queue to process the vertices
    std::queue<int> q;
    visited[source] = true; // mark the source as true to indicate it was visited
    q.push(source);         // push the vertex into the queue

    while (!q.empty()) // as long as the queue is not empty, do the following
    {
        source = q.front(); // take the vertex from the queue, this will be the last element added to the queue.
        q.pop();            // pop the vertex off the queue

        // for each adjacent vertex of source, do the following
        for (int v : adjList[source])
        {
            if (v == destination) // if the current vertex is equal to destiantion, then return true
                return true;
            if (!visited[v]) // otherwise, add the vertex to the queue (if not visited before) and repeat the process for each vertex
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    // if destiantion was not found, return false
    return false;
}

int main()
{
    std::vector<std::vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int n = 3;
    int source = 0;
    int destination = 2;
    std::vector<std::vector<int>> adjList; // adjacency list for the graph
    adjList.resize(n);

    for (auto &edge : edges) // build the adjacency matrix by adding vertices
    {
        adjList[edge[0]].push_back(edge[1]);
        adjList[edge[1]].push_back(edge[0]);
    }

    std::vector<bool> visited; // we need an array to track the visited vertices so that we don't revisited them
    visited.resize(n);         // this basically makes room for n element, each of which is initialized to false by default in this case.

    std::cout << BFS(adjList, source, destination, visited); // call the BFS function

    return 0;
}
