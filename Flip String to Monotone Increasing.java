class Solution {
    public int minFlipsMonoIncr(String s) {
        int n = s.length();
        int[] prefix = new int[n];
        int[] suffix = new int[n];
        for(int i=0;i<n;i++){
            if(s.charAt(i) == '1'){
                prefix[i] = 1;
            }
            if(s.charAt(n-i-1) == '0'){
                suffix[n-i-1] = 1; 
            }
        }
        for(int i=1;i<n;i++){
            prefix[i] += prefix[i-1];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i] += suffix[i+1];
        }
        int minFlips = Math.min(suffix[0],prefix[n-1]);
        for(int i=1;i<n-1;i++){
            minFlips = Math.min(minFlips,prefix[i]+suffix[i+1]);
        }
        return minFlips;
    }
}