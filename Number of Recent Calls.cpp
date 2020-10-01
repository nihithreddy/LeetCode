#include<bits/stdc++.h>
using namespace std;
class RecentCounter {
public:
    vector<int> requests;
    RecentCounter() {
        requests.clear();
    }
    int ping(int t) {
         requests.push_back(t);
         while(!requests.empty() && (t-requests.front())>3000){
             requests.erase(requests.begin());
         }
        return (int)requests.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */