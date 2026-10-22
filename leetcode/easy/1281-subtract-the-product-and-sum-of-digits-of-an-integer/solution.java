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