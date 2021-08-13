class Solution {
    public boolean canReorderDoubled(int[] arr) {
        int n = arr.length;
        Map<Integer,Integer> count = new HashMap<>();
        for(int i=0;i<n;i++){
            count.put(arr[i],count.getOrDefault(arr[i],0)+1);
        }
        Integer b[] = new Integer[n];
        for(int i=0;i<n;i++) b[i] = arr[i];
        Arrays.sort(b, Comparator.comparingInt(Math::abs));
        for(int num:b){ 
            if(count.get(num) == 0) continue;
            if(count.getOrDefault(2*num,0) == 0) return false;
            count.put(num,count.get(num)-1);
            count.put(2*num,count.get(2*num)-1);
        }
        return true;
    }
}