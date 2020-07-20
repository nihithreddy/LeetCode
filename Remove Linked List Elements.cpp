/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL){
            return head;
        }
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            if(temp->val==val){
                if(prev==NULL){
                    head=temp->next;
                    temp=head;
                }
                else{
                    prev->next=temp->next;
                    temp=temp->next;
                }
            }
            else{
                prev=temp;
                temp=temp->next;
            }
        }
        return head;
    }
};