class Solution {
public:
    int find_sum(int n){
        int sum = 0;
        while(n){
            sum += n%10;
            n/=10;
        }
        return sum;
    }
    int addDigits(int num) {
        if(num<=9){
            return num;
        }
        int digits = log10(num)+1;
        while(digits!=1){
            num = find_sum(num);
            digits = log10(num)+1;
        }
        return num;
    }
};