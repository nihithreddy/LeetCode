#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> sortedSquares(vector<int>& A) {
       int n = A.size();
       vector<int> squares(n);
       int l=0,h=n-1,index=n-1;
       while(l<=h){
          if(A[l]*A[l]>=A[h]*A[h]){
              squares[index]=A[l]*A[l];
              index--;
              l++;
          }
           else{
               squares[index]=A[h]*A[h];
               h--;
               index--;
           }
       }
       return squares;
    }
};