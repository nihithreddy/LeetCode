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
    ListNode* getMidNode(ListNode* head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *slow = head,*fast=head->next;
        while(fast!=NULL&&fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode *prev=NULL,*cur=head,*next=head;
        while(cur!=NULL){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return;
        }
        ListNode* head1 = head;
        ListNode* mid = getMidNode(head1);
        ListNode* head2 = reverseList(mid->next);
        mid->next=NULL;
        head = new ListNode(0);
       while(head1!=NULL||head2!=NULL){
           if(head1){
               //cout<<head1->val<<" ";
               head->next = head1;
               head = head->next;
               head1=head1->next;
           }
           if(head2){
               //cout<<head2->val<<" ";
               head ->next = head2;
               head = head->next;
               head2=head2->next;
           }
       }
    }
};