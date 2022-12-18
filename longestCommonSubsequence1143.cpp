#include <iostream>
#include <string>

int max(int a, int b)
{
    return a > b ? a : b;
}

int total_calls;

int LCS(std::string str1, std::string str2, int str1Size, int str2Size)
{
    total_calls++;
    // base case or base cases
    if (str1Size == 0 || str2Size == 0)
        return 0;

    // recursive cases
    // if the last chars of the strings are a match, then we return 1 + lcs(str1.pop(), str2.pop())
    if (str1[str1Size - 1] == str2[str2Size - 1])
        return 1 + LCS(str1, str2, str1Size - 1, str2Size - 1);
    else
        return max(LCS(str1, str2, str1Size, str2Size - 1), LCS(str1, str2, str1Size - 1, str2Size));
    // if they don't match
}

// to write the memoized version of LCS, we need the following:
// define a memo array to store answers to subproblem
// do the necessary initialization for the memo array
// every time when LCS function gets called,
// check if you already have the answer for the current subproblem in memo array
// if you do, return it, else call the function on that subproblem to compute the answer
// and store the answer to that subproblem before returning it

int LCS_memoized(std::string str1, std::string str2, int str1Size, int str2Size, int memo[100][100])
{
    total_calls++;
    if (str1Size == 0 || str2Size == 0)
        return 0;
    if (memo[str1Size][str2Size] != -1)
        return memo[str1Size][str2Size];
    if (str1[str1Size - 1] == str2[str2Size - 1])
    {
        memo[str1Size][str2Size] = 1 + LCS_memoized(str1, str2, str1Size - 1, str2Size - 1, memo);
        return memo[str1Size][str2Size];
    }
    else
    {
        memo[str1Size][str2Size] = max(LCS_memoized(str1, str2, str1Size, str2Size - 1, memo), LCS_memoized(str1, str2, str1Size - 1, str2Size, memo));
        return memo[str1Size][str2Size];
    }
}

// dynamic programming implementation
int LCS_dp(std::string str1, std::string str2, int str1Size, int str2Size, int memo[100][100])
{
    for (int row = 1; row <= str1Size; row++)
    {
        for (int col = 1; col <= str2Size; col++)
        {
            if (str1[row - 1] == str2[col - 1])
            {
                memo[row][col] = 1 + memo[row - 1][col - 1];
            }
            else
            {
                memo[row][col] = max(memo[row - 1][col], memo[row][col - 1]);
            }
        }
    }
    return memo[str1Size][str2Size];
}

int main()
{
    std::string str1 = "babcdefde";
    std::string str2 = "acde";

    // to store the answer to subproblems to avoid recomputing them when needed
    int memo[100][100]; // the size of the array is hard-coded

    // needed initialization for memo array
    for (int i = 0; i < 100; i++)
    {
        memo[0][i] = 0;
    }
    for (int i = 0; i < 100; i++)
    {
        memo[i][0] = 0;
    }

    // this part is only needed for memoized version
    for (int row = 1; row < 100; row++)
    {
        for (int col = 1; col < 100; col++)
        {
            memo[row][col] = -1;
        }
    }

    // recursive implementation
    total_calls = 0;
    std::cout << LCS(str1, str2, str1.size(), str2.size()) << " in calls " << total_calls << std::endl;

    // memoized implementation
    total_calls = 0;
    std::cout << LCS_memoized(str1, str2, str1.size(), str2.size(), memo) << " in calls " << total_calls << std::endl;

    // dynamic programming implementation
    std::cout << LCS_dp(str1, str2, str1.size(), str2.size(), memo);

    return 0;
}