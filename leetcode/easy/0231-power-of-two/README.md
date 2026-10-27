# Power of Two

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Qualcomm
Snap
Google
Nvidia
Meta

Given an integer `n`, return  *`true` if it is a power of two. Otherwise, return `false`*.

An integer `n` is a power of two, if there exists an integer `x` such that `n == 2x`.

 

 **Example 1:** 

```
Input: n = 1
Output: true
Explanation: 20 = 1

```

 **Example 2:** 

```
Input: n = 16
Output: true
Explanation: 24 = 16

```

 **Example 3:** 

```
Input: n = 3
Output: false

```

 

 **Constraints:** 

- -231 <= n <= 231 - 1

 

 **Follow up:**  Could you solve it without loops/recursion?

## Solution

**Language:** C++  
**Runtime:** 0 ms  
**Memory:** 7.5 MB  
**Submitted:** 2026-10-27T04:26:07.119Z  

```cpp
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n<=0) return false;
        int x=1;
        while(x<=n){
            if(x==n){
                return true;
            }
            x=x*2;
        }
        return false;
    
    }
};
```

---

[View on LeetCode](https://leetcode.com/problems/power-of-two/)