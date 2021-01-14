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
        ListNode* curr = new ListNode();
        ListNode* ans = curr;
        while (l1 != nullptr || l2 != nullptr){
            if (l1 == nullptr){
                l1 = new ListNode();
            }
            if (l2 == nullptr){
                l2 = new ListNode();
            }
            curr->val += l1->val + l2->val;
            curr->next = new ListNode();
            if (curr->val >= 10){
                curr->val %= 10;
                curr->next->val += 1;
            }
            if (l1->next == nullptr && l2->next == nullptr && curr->next->val == 0){
                curr->next = nullptr;
            }
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        return ans;
    }
};