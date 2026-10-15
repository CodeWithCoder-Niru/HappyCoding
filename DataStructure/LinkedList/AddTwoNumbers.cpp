/*https://leetcode.com/problems/add-two-numbers/description/*/

#include<bits/stdc++.h>


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
	    ListNode *temp = &dummy;
        
	    int carry =0;
	    while(L1 || L2 || carry) {
	    	int sum = carry;
        
	    	if(L1) {
	    		sum= sum +L1->data; //9
	    		L1 = L1->next; 
	    	}
	    	if(L2) {
	    		sum = sum +L2->data; //10
	    		L2 = L2->next;
	    	}
        
	    	carry = sum/10;
	    	temp->next = new ListNode(sum%10);
        
	    	temp = temp->next;
	    }
	    return dummy->next;
    }
};