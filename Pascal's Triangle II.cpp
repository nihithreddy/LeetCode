#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> matrix(rowIndex+2);
        matrix[1].push_back(1);
        for(int i=2;i<=rowIndex+1;i++){
            matrix[i].push_back(1);
            for(int k=1;k<i-1;k++){
                if(k-1>=0&&k<i-1){
                    matrix[i].push_back(matrix[i-1][k-1]+matrix[i-1][k]);
                }
            }
            matrix[i].push_back(1);
        }
        return matrix[rowIndex+1];
    }
};