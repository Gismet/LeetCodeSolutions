#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>
#include <algorithm>

/**
 * LeetCode: Koko eating bananas 875
 * Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
 *
 */

// Let's consider the following input:
/*
    piles = [30, 11, 23, 4, 10] h = 5

    For Koko to eat all the bananas, she has to eat at least ceil(sum(piles) / h)
    bananas per hour. (sum(piles) is the sum of all the elements in the piles)
    Let's confirm that. Let's state a counterexample. For example, let's imagen
    that Koko eats 3 bananas per hour. Within 5 hours, Koko can eat at most 15 bananas
    If we have more than 15 bananas totally, then however the bananas are distributed
    among the piles, Koko can't eat them all. That's pretty clear. So that forms
    the lower bound of Koko's bananas per hour to eat. Okay now let's define the upper bound
    Examin the above input. If Koko decides to eat the maximum number
    of bananas out of all the piles, then it is sure that she can consume them all since
    the given time is more than or equal to the number of piles.
    So if she eats 30 bananas per hour, then she can all the bananas within 5 hours
    regardless of the distribution of bananas across the piles. So that is the upper bound

    Then what we are going to do is to find the minimum eating speed (k) within this interval.
    We can search the minimum eating speed k using binary search.

    1. Find the middle of the interval -> mid
    2. If Koko runs out of time, eating mid bananas, that means she can't eat less bananas
    than mid. So it is useless to search in left side of mid. Update the lower bound to mid + 1
    3. If Koko consumes all the bananas within the given time, then she can consider
    eating less than mid, that's why we discard the right side of mid but not mid because
    mid could be the solution. Basically we are homing in on the minimum number for k.


*/

int minEatingSpeed(std::vector<int> piles, int h)
{
    double sum = std::accumulate(piles.begin(), piles.end(), 0.0);

    double lowerBound = (std::ceil(sum / h));
    double upperBound = *(std::max_element(piles.begin(), piles.end()));

    while (lowerBound < upperBound)
    {
        sum = 0.0;
        double mid = std::floor((upperBound + lowerBound) / 2);
        for (int pile : piles)
            sum += std::ceil(pile / mid);
        if (sum > h)
        {
            lowerBound = mid + 1;
        }
        else
        {
            upperBound = mid;
        }
    }
    return lowerBound;
}

int main()
{
    std::vector<int> piles = {30, 11, 23, 4, 20};
    int h = 6;

    std::cout << minEatingSpeed(piles, h);

    return 0;
}