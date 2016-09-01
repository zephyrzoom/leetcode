struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* tmp = head;
        if (tmp != nullptr) {   // 注意判断指针是否为空，为空的话tmp->next会报错
            while (tmp->next) {
                if (tmp->val == tmp->next->val) {
                    ListNode* del = tmp->next;
                    tmp->next = del->next;
                    delete del;
                } else {
                    tmp = tmp->next;
                }
            }
        }
        return head;
    }
};
