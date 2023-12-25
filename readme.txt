Qs 1:
**Coin-Change Problem:**

The Coin-Change Problem involves determining the minimum number of coins needed to make up a given total amount of money 
using a set of coins with varying denominations. The goal is to optimize the number of coins used for the given currency.

**Solutions:**

1. **Greedy Approach:**
   - The greedy approach involves selecting the largest denomination coin at each step until the remaining total becomes zero.
   - The algorithm iterates through the denominations in descending order and calculates the number of coins needed for each denomination.
   - If the denominations are multiples of each other, this approach guarantees an optimal solution.

2. **Dynamic Programming (DP):**
   - The DP approach uses dynamic programming to find the optimal solution by building a table to store subproblem solutions.
   - It creates an array `dp` where `dp[i]` represents the minimum number of coins needed to make up the amount `i`.
   - The algorithm iterates through each denomination and updates the `dp` array based on the optimal substructure of the problem.

**Asymptotic Upper Bound:**

1. **Greedy Approach:**
   - **Time Complexity:** O(n), where n is the number of denominations.
     - The algorithm iterates through the denominations once, performing constant-time operations at each step.
   - **Space Complexity:** O(1), as it uses a constant amount of space regardless of the size of the input.
   - **Optimality:** Greedy algorithms may not always provide the globally optimal solution, but they work well 
      for certain cases (e.g., denominations being multiples).

2. **Dynamic Programming:**
   - **Time Complexity:** O(nt), where t is the total amount and n is the number of denominations.
     - The nested loops iterate through all possible combinations of total amounts and denominations.
   - **Space Complexity:** O(t), as it uses an array of size `total + 1` to store subproblem solutions.
   - **Optimality:** Dynamic programming guarantees an optimal solution by considering all possible combinations and storing optimal solutions for subproblems.

**Code Description:**

- The provided C++ code reads denominations and their values from a file. (assumption : denominations in file are in descemding order)
- It checks if the denominations are multiples using the `areMultiples` function.
- Depending on whether the denominations are multiples, it applies either the Greedy Approach (`coinChangeGreedy`) or the Dynamic Programming Approach (`coinChangeDP`).
- The code outputs the denominations, prompts the user for the total amount, and prints the minimum number of coins required or indicates if a solution is not possible.




Qs 2:

---Longest-Common Subsequence (LCS) Problem

---Problem Description

The Longest Common Subsequence (LCS) problem involves finding the longest subsequence that is common to two given sequences,
denoted as s1 and s2. A subsequence is a sequence that can be derived from another sequence by deleting some or no elements
without changing the order of the remaining elements.

For the LCS problem:
- The common subsequence (denoted as Z) is not required to have consecutive positions within the original sequences.
- Z must be a strictly increasing sequence of indices of both s1 and s2.
- In a strictly increasing sequence, the indices of the chosen elements from the original sequences must be in ascending order in Z.

---Solutions

----Simple Recursion

The simple recursion approach involves recursively exploring all possible subsequences and finding the length of the LCS.
The recursive function compares characters of S1 and S2 and considers both possibilities: including the current character in the LCS or excluding it.

----Dynamic Programming

The dynamic programming approach is more efficient. It uses a 2D array (matrix) to store intermediate results.
The matrix is filled iteratively based on the lengths of common subsequences of prefixes of s1 and s2.
The final element of the matrix contains the length of the LCS.

---- Asymptotic Upper Bound

1. Simple Recursion:
   - **Time Complexity:** O(2^(m+n))
     - Exponential time complexity due to the recursive nature.
   - **Space Complexity:** O(m+n)
     - The recursion depth is proportional to the sum of the lengths of S1 and S2.

2. **Dynamic Programming:
   - Time Complexity: O(m * n)
     - Iterating through the lengths of S1 and S2.
   - Space Complexity: O(m * n)
     - Space required for the dynamic programming matrix.

--- Input

The program takes two input sequences, S1 and S2, for which the LCS needs to be found.

----Running the Code

1. Provide the first sequence, S1.
2. Provide the second sequence, S2.
3. The code will output the length of the LCS using both the simple recursion and dynamic programming approaches.

### Note

- The dynamic programming approach is recommended for larger input sequences due to its polynomial time complexity,
whereas the simple recursion approach may be impractical for larger inputs.