class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> map = new HashMap<>();
        for(String str : strs){
            char chArr[] = str.toCharArray();
            Arrays.sort(chArr);
            String s = new String(chArr);
            if(map.get(s) != null){
                List<String> value = map.get(s);
                value.add(str);
                map.put(s,value);
            }
            else{
                 List<String> value = new ArrayList<>();
                 value.add(str);
                 map.put(s,value);
            }
        }
        List<List<String>> groups = new ArrayList<>();
        for(String key: map.keySet()){
            groups.add(map.get(key));
        }
        return groups;
    }
}