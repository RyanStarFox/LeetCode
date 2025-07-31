#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* current = head;
        int carry = 0;
        while(l1 != nullptr || l2 != nullptr) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = x+y+carry;
            carry = sum/10;
            sum%=10;
            ListNode* newNode = new ListNode(sum);
            current->next = newNode;
            current = current->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry > 0) {
            ListNode* newNode = new ListNode(carry);
            current->next = newNode;
        }
        return head->next;
    }
};