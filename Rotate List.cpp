/* Given a linked list, rotate the list to the right by k places, where k is non-negative. */
#include<bits/stdc++.h>
using namespace std;
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        int count = 0;
        ListNode* temp = head;
        ListNode* tail;
        while(temp!=NULL){
            tail=temp;
            temp=temp->next;
            count++;
        }
        k%=count;
        k=count-k;
        temp=head;
        while(k>0){
            tail->next=temp;
            tail=temp;
            temp=temp->next;
            k--;
        }
        head=temp;
        tail->next=NULL;
        return head;
    }
};