/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0){
            return NULL;
        }
        while(n>1){
            for(int i=0;i<n/2;i++){
                lists[i]=merge(lists[i],lists[n-i-1]);
            }
            if(n&1) n=n/2+1;
            else n=n/2;
        }
        return lists[0];
    }
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* temp = new ListNode(0);
        ListNode* head = temp;
        while(a!=NULL&&b!=NULL){
            if(a->val<b->val){
                head->next = a;
                head = head->next;
                a = a->next;
            }
            else{
                head->next = b;
                head = head ->next;
                b = b->next;
            }
        }
        while(a!=NULL){
            head->next = a;
            head = head->next;
            a = a->next;
        }
        while(b!=NULL){
            head->next = b;
            head = head->next;
            b = b->next;
        }
        return temp->next;
    }
};