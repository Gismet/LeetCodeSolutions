#include <iostream>
#include <vector>
#include <queue>

// prerequisite: Bread-first search

/* bread-first search on maze*/
int nearestExit(std::vector<std::vector<char>> &maze, std::vector<int> entrance)
{

    int row, col;
    int m = maze.size();    // get the length of maze row
    int n = maze[0].size(); // get the length of maze column as we need them when checking boundaries of maze

    // extract starting points from entrance as row and col
    row = entrance[0];
    col = entrance[1];
    /**BFS starts**/

    // mark current position in the maze as '+'. ('+' means we can not go to that cell, which simply could mean it is already visited)
    maze[row][col] = '+';

    // we need a queue to track our way in the maze
    std::queue<std::vector<int>> q;
    // push current position(indicis of maze) to the queue along with current distance from entrance
    q.push({row, col, 0});
    int distance = 0;

    while (!q.empty())
    {
        // again take next pair of points as row and col
        row = q.front()[0];
        col = q.front()[1];
        // and distance from the starting point(entrance)
        distance = q.front()[2];
        q.pop(); // pop it off the queue

        /** Here, we have to check if we can go to any of 4 directions from the current point in maze(up, down, right, left) **/

        // if we can go up
        if ((row - 1) >= 0 && maze[row - 1][col] != '+')
        {
            // if the point we get to is zero, then it is the exit since it is in the enge of maze
            //(Basically the idea here is that if either row or column index we are at is zero or other edge, then it is the exit)
            if (row - 1 == 0 || col == 0 || col == n - 1)
                return distance + 1; // increment distance from entrance and return it
            // otherwise, mark the position as visited(by making it a block '+') and push it to the queue
            maze[row - 1][col] = '+';
            q.push({row - 1, col, distance + 1});
        }
        if ((row + 1) < m && maze[row + 1][col] != '+') // checking going down
        {
            if (row + 1 == m - 1 || col == 0 || col == n - 1)
                return distance + 1;
            maze[row + 1][col] = '+';
            q.push({row + 1, col, distance + 1});
        }
        if ((col - 1) >= 0 && maze[row][col - 1] != '+') // checking going to the left
        {
            if ((col - 1) == 0 || row == 0 || row == m - 1)
                return distance + 1;
            maze[row][col - 1] = '+';
            q.push({row, col - 1, distance + 1});
        }
        if ((col + 1) < n && maze[row][col + 1] != '+') // checking going to the right
        {
            if (col + 1 == n - 1 || row == 0 || row == m - 1)
                return distance + 1;
            maze[row][col + 1] = '+';
            q.push({row, col + 1, distance + 1});
        }
    }
    return -1; // if there is no way out of maze
}

int main()
{
    std::vector<std::vector<char>> maze = {{'+', '+', '+'}, {'.', '.', '.'}, {'+', '+', '+'}};
    std::vector<int> entrance = {1, 0};

    std::cout << nearestExit(maze, entrance); // 2

    return 0;
}