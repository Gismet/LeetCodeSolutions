#include <iostream>
#include <vector>

// In this problem, we are given an m x n  image array as a representative of an image,
// where image[i][j] represents the pixel value of the image. We are also given sr, sc, color.
// here sr and sc are the starting row and starting column respectively
//  and color is the pixel value with which we will do replacement.
//  We have to perform a flood fill on the image starting from the pixel image[sr][sc]

// to perform a flood fill, consider the starting pixel and any pixels connected from 4 sides to the starting pixel
//, which have the same color as the staring pixel. Also consider any pixels connected from 4 sides to those pixels which
//  are connected from 4 sides to the starting pixel and so on. Replace the color of the mentioned pixels with color.

// we have to return the changed image after performing a flood fill.
// Note: for a visual example, check out the link https://leetcode.com/problems/flood-fill/

/*We can just run Depth-first Search or Breadth-first Search on image array.
Let's just use Depth-first search recursively.
We have to check adjacent cells to the current cell and change color code of those which has the same color as the current cell.
Potentially we will have at most 4 adjacent cell to the current cell.
These cells are the up, down, left, right cells of the currently considered cell.
If we have at least one such cell which has the same color as the current cell
and if its color code was not already changed, run DFS on that cell.*/

void DFS(std::vector<std::vector<int>> &image, int sr, int sc, int color)
{
    int scColor = image[sr][sc];
    image[sr][sc] = color;
    int m = image.size();
    int n = image[0].size();
    // check the up cell
    if ((sr - 1) >= 0 && image[sr - 1][sc] != color && image[sr - 1][sc] == scColor)
    {
        DFS(image, sr - 1, sc, color);
    }
    // check the down cell
    if ((sr + 1) < m && image[sr + 1][sc] != color && image[sr + 1][sc] == scColor)
    {
        DFS(image, sr + 1, sc, color);
    }
    // check the left cell
    if ((sc - 1) >= 0 && image[sr][sc - 1] != color && image[sr][sc - 1] == scColor)
    {
        DFS(image, sr, sc - 1, color);
    }

    // check the right cell
    if ((sc + 1) < n && image[sr][sc + 1] != color && image[sr][sc + 1] == scColor)
    {
        DFS(image, sr, sc + 1, color);
    }
}

std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>> image, int sr, int sc, int color)
{
    DFS(image, sr, sc, color);
    return image;
}

int main()
{
    std::vector<std::vector<int>> image = {{0, 0, 0}, {0, 0, 0}};
    int sr = 1, sc = 0, color = 2;

    image = floodFill(image, sr, sc, color);
    for (int i = 0; i < image.size(); i++)
    {
        for (int j = 0; j < image[i].size(); j++)
        {
            std::cout << image[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}