# Subtract the Product and Sum of Digits of an Integer

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Quora
tcs
Google
Bloomberg
Meta
Given an integer number `n`, return the difference between the product of its digits and the sum of its digits.

 

 **Example 1:** 

```
Input: n = 234
Output: 15 
Explanation: 
Product of digits = 2  *3*  4 = 24 
Sum of digits = 2 + 3 + 4 = 9 
Result = 24 - 9 = 15

```

 **Example 2:** 

```
Input: n = 4421
Output: 21
Explanation: 
Product of digits = 4  *4*  2 * 1 = 32 
Sum of digits = 4 + 4 + 2 + 1 = 11 
Result = 32 - 11 = 21

```

 

 **Constraints:** 

- 1 <= n <= 10^5

## Solution

**Language:** C++  
**Runtime:** 0 ms (beats 100.00%)  
**Memory:** 7.9 MB (beats 19.47%)  
**Submitted:** 2026-10-22T08:57:33.955Z  

```cpp

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1, sum = 0;

        while (n > 0) {
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n /= 10;
        }

        return product - sum;
    }
};

```

---

[View on LeetCode](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)