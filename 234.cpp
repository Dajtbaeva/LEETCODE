// 234. Palindrome Linked List
// https://leetcode.com/problems/palindrome-linked-list/

class Solution {
public:
    ListNode* temp;
    
    bool check(ListNode* head) {
        if (NULL == head) return true;
        bool res = check(head->next) & (temp->val == head->val);
        temp = temp->next;
        return res;
    }
    
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
};


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
    ListNode * reversed(ListNode* root){
        vector<int> rave;
        ListNode * cur = root;
        while(cur != nullptr){
            rave.push_back(cur -> val);
            cur = cur -> next;
        }
        cur = root;
        int i = rave.size() - 1;
        while(cur != nullptr){
            cur -> val = rave[i];
            cur = cur -> next;
            i--;
        }
        return cur;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode * temp = reversed(head);
        bool ok = true;
        while(temp != NULL && head != NULL){
            if(head->val != temp->val){
                return false;
            }
            temp = temp->next;
            head = head->next;
        }
        return true;
    }
};