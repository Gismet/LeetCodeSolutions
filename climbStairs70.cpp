// writing a helper function to solve the problem

/* when writing memoized solution , try to first write recursive solution to the problem. 
* After writing the recursive solution, convert the solution to memoized solution by storing the solution to overlapping subproblems
* I encourage you to write each recursive calls to subproblems on a paper so that you can see overlapping subproblems
* if there are no overlapping subproblems, no need to store any solutions to subproblems anyway(you might want to store them for another reason)
* if we solve the same subproblem more than once , then we can call this subproblem overlapping subproblem
* we store the solutions to overlapping subproblems in a data structure mainly an array so that we can use it later
* you can understand this property of dynamic programming investigating the fibonacci numbers(check it out)
*/


// Back to problem. Let's first characterize the structure of optimal solution .
/* Now suppose you are given n = 3 stairs to climb. Let's find out how many ways there are for you to climb to the top.
* you can climb 1 stair or 2 stairs at a time. If you can climb 1 stairs, which you can in this case, then there are 2 stairs left to climb
* suppose you know how many ways there are to climb 2 stairs by climbing either 1 or 2 stairs at a time. 
* there are 2 ways to climb to the top. you can take 1 step and then 1 step again. this is one way.
* or you can take 1 step and then 2 steps, arriving at the top. this is another way. total of 2 ways.
* remember you climbed 1 stair and you had 2 stairs left to climb but you somehow know how many steps it would take to climb to the top
* now you say , okay i have climed 1 stair and I can climb the rest of the 2 stairs in 2 ways.
* so there are 2 ways to climb to the top if I start climbing 1 stairs at first.
* Now let's suppose you climbed 2 stairs at fist, then you would have 1 stair left to climb. how many ways to climb 1 stair ? 
* that's easy. There is only 1 way to climb 1 stair. 
* now you say , okay i have climed 2 stairs and I can climb the rest of the 1 stair in 1 way
* Now you have tried all possible options for the first step of climbing.
* Option 1: If you started climbing 1 stair at first, then you would have 2 ways to climb to the top
* Option 2: If you started climbing 2 stairs at first, then you would have 1 way to climb to the top
* Now we combine the two solution from option 1 and option 2, getting a total of 3 ways to climb to the top a 3 stairs.
* So answer is 3
* In option 1 you climed 1 stair at first, then you had 2 stairs left to climb.
* think of climbing 2 stairs as a new problem. if you can find optimal solution to this problem, then you could know the optimal
* solution to climb 3 stairs. this 2-stair case is a subproblem of a 3-stair case. 
* If you know the optimal solution to subproblems, then you can find the optimal solution to original problem.
* In option 2 you climed 2 stairs at first, then you had 1 stairs left to climb.
* this 1-stair case is a subproblem of original problem. 
* then we combine the optimal solutions to subproblems to find out the optimal solution to original problem
*/

// now let's first write the recursive solution

// we need base case or cases. 
// what is the trivial problem to solve here ? 
// If there is 0 stairs, how many ways to climb to the top ? 
// 1 way. that sounds wrong. But it is not.  
// there is 1 way because we can climb 0 stairs by climbing no stairs at all. this is one way of doing it.
// I don't know if I could convince you of correctness of this.
// we have actually one subbase case which is when there is 1 stair. 
// If there is 1 stair , then 1 way to climb it. So return 1;



int recursiveClimbStairs(int n)
{
    // let's have the base cases
    if ( n == 0 || n == 1)
        return 1;
    int total = 0;
    
    // if n is greater than 0, then we can check option 1:  climbing 1  stair 
    total += recursiveClimbStairs(n - 1);
    
    // here we check option 2: climbing 2 stairs. 
    total += recursiveClimbStairs(n - 2);

    return total;  
}

// If you submit this solution to leetcode, you will get a time-limit-exceeded error

// let's now write memoized solution
//memoized solutions are generally referred to as top-down solutions
//dp solutions are referred to as bottom-up solutions. In that case you build your way up, solving smaller subproblems, starting with most trivial case.

int solve(int n, int memo[46])
{
    // first check if answer to the current problem is already in the memo array. If it is , return it without any more recursive calls
    if ( memo[n] != -1)
        return memo[n];
    int total = 0;
    // If the solution to the current problem is not in the memo array, then we solve even smaller subproblems
    
    if ( memo[n - 1] != -1) 
        total += memo[n - 1];
    else 
        total += climbStairs(n - 1, memo);

    if ( memo[n - 2] != -1)
        total += memo[n - 2];
    else 
        total += climbStairs(n , memo);
    }    
    
    // before returning the solution to the current problem, store it for further use
    memo[n] = total;
    return memo[n];
}
