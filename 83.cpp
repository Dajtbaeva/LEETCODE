83. Remove Duplicates from Sorted List
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

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
    ListNode* deleteDuplicates(ListNode* head){
    ListNode* curr = head;
    while(curr != NULL){
        if((curr->next != NULL) && curr->val == curr->next->val) curr->next = curr->next->next;
        // if next element exists then we check if current and next values equal we set this element to the next element; 
        else curr = curr->next; // if these two elements not equal we set current element to the next
    }
    return head;       
    }
};

