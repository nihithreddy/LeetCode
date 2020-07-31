class Solution {
    public int climbStairs(int n) {
        int prev= 1,cur=2,next=0;
        if(n==1){
            return prev;
        }
        else if(n==2){
            return cur;
        }
        else{
            for(int i=3;i<=n;i++){
                next = prev+cur;
                prev = cur;
                cur  = next;
            }
            return next;
        }
    }
}