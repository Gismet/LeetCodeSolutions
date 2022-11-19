#include <iostream>
#include <vector>
/* given an array of height, representing the height of vertical lines drawn such that
 two ends of the ith line is (i, 0) and (i, height[i])

 find the maximum amount of water a container can store

 */

/* In this problem our container is limited by the sortest line.
Here we can use two pointers approach. We start with the widest container.
set two pointers left and right to the first and the last entry of the array.
let's take this array of heights => heights = [1,8,6,2,5,4,8,3,7]
the amount of water that containter formed by the 0th(technically first line) and 8th line is 1 * (8 - 0) = 8;
Our containter is formed based on the shortest line. That's why we ignore the longest line.
We find the amount of water the current container can hold and update our maximum.
If the left line is short, we increment left pointer, otherwise we decrement right pointer.
Keep repeating this process as long as left pointer is less than right pointer
*/

int maxArea(std::vector<int> &heights)
{
    // set two pointers
    int l = 0;
    int r = heights.size() - 1;
    int max = -1;
    // as long as left pointer is less than right pointer
    while (l < r)
    {
        // if left line is short, then it forms a container
        if (heights[l] < heights[r])
        {
            // update max
            if (max < heights[l] * (r - l))
            {
                max = heights[l] * (r - l);
            }
            l++; // move left pointer one position to the right.
        }
        else
        { // otherwhise
            // update max
            if (max < heights[r] * (r - l))
            {
                max = heights[r] * (r - l);
            }
            r--; // move the right pointer one position to the left
        }
    }
    return max;
}

// Note: You can come up with a brute force approach where you simply check each possible container, updating max veriable accordingly

int main()
{
    std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    std::cout << maxArea(heights);

    return 0;
}
