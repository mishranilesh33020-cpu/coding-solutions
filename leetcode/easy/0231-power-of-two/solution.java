class Solution {
    public boolean isPowerOfTwo(int n) {
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
}