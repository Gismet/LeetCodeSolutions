#include <iostream>

// given a non-negative intetger n, find the squared root of n rounded down to nearest integer.
// We should avoid using built-in functions such as sqrt(), pow() or any other built-in functions

// let's see how we can do this. Now we have to find sqrt(n), which is some integer number x in our case.
// Let's raise sqrt(n) to second power, so we n = x^2. Let's say n is 36
// then our equation becomes x^2 = 36. We need to find the root of this equation.
// in this case the root will be 6, which is the square root of 36. Then the question becomes
// how we can find the root of this equation ? Yeah, math stuff, we can use one of those root finding
// methods taught in numberical methods. Bisection method !. This method is actually an adaption of
// binary search. While binary search on an array works with discerete finite values, bisection method
// works with infinite real numbers. Let's me walk you through an example to better understand this method.
// Let's take our equation x^2 = 36 and rewrite it in this form x^2 - 36 = 0 just to make it look more like an equation.
// just as with binary search, we need low and high boundries with bisection method. Since we know that given number n is
// non-negative we can take the low bountry as 1. For the high boundry we can take n/2 since square root of any number
// will be less than or equal to its half (except for 0 and 1). Now how are we going to find the root.
// Let's take n = 36. Then low = 1 and high = 18. It is intutive that the square root of 36 is somewhere between 1 and 18.
// Now it looks more like binary search. We find the middle values of our interval. It is (1 + 18) / 2 = 9 (we are dealing with integers)
// So now let's check if the condition 9 * 9 > 36 ? True, so we can make our high boundry mid - 1 since all numbers greater than
// 9 will also be greater than 36. So high = 9 - 1 = 8 and low = 1. Let's find the middle again. (8 + 1) / 2 = 4.
// Check if 4 * 4 > 36 ? False, then we make low boundry mid + 1 because all numbers less than 4 will also be less than 36.
// So low = 5 and high = 8. Find the middle again. (5 + 8)/2 = 6. Check if 6 * 6 > 36 ? False, actually this is the answer.
// low boundry becomes mid + 1, which is 7. Now low is 7 and high is 8. Find the middle again. (7 + 8) / 2 = 7
// Check if 7 * 7 > 36 ? True, then high becomes mid - 1 = 6. Now low is 7 and high is 6, which terminates the while loop.
// at the end we got our answer. high = 6

int sqrt(int x)
{
    if (x < 2)
        return x; // if x is 0 or 1 whose square roots are the same as them. just return the number

    int low = 1;
    int high = x / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if ((long)mid * mid > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return high;
}

int main()
{
    int n = 36;
    std::cout << sqrt(n);
    return 0;
}