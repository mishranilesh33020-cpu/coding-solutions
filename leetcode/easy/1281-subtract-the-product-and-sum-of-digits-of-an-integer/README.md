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

**Language:** Java  
**Runtime:** 0 ms  
**Memory:** 41.6 MB  
**Submitted:** 2026-10-22T08:58:03.239Z  

```java
class Solution {
    public int subtractProductAndSum(int n) {
      int prod=1;
      int sum=0;
      int diff;
      while(n>0){
        n = n%10;
        prod = prod * n;
        sum = sum + n;
        n /= 10;
      }
      diff = prod - sum;
      return diff;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/)