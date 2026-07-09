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
    ListNode* oddEvenList(ListNode* head) {
        vector<int> list;
        ListNode* temp = head;
        if (head == NULL) {
            return head;
        }
        while (temp != NULL && temp->next != NULL) {
            list.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp != NULL) {
            list.push_back(temp->val);
        }
        temp = head->next;
        while (temp != NULL && temp->next != NULL) {
            list.push_back(temp->val);
            temp = temp->next->next;
        }
        if (temp != NULL) {
            list.push_back(temp->val);
        }
        temp = head;
        for (int i = 0; i < list.size(); i++) {
            temp->val = list[i];
            temp = temp->next;
        }
        return head;
    }
};