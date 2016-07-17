/*
 *  @author 707<707472783@qq.com>
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
    public:
        ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
            int num1 = 0;
            int num2 = 0;
            int carry = 0;
            ListNode* listSum = new ListNode(0);
            ListNode* listTmp = listSum;
            while (l1 != nullptr || l2 != nullptr) {
                if (l1 != nullptr) {
                    num1 = l1->val;
                    l1 = l1->next;
                } else {
                    num1 = 0;
                }
                if (l2 != nullptr) {
                    num2 = l2->val;
                    l2 = l2->next;
                } else {
                    num2 = 0;
                }
                int sum = num1 + num2 + carry;
                if (sum >= 10) {
                    carry = 1;
                } else {
                    carry = 0;
                }
                ListNode* node = new ListNode(sum % 10);
                listTmp->next = node;
                listTmp = node;
            }
            if (carry) {
                ListNode* node = new ListNode(1);
                listTmp->next = node;
            }
            ListNode* del = listSum;
            listSum = listSum->next;
            delete del;
            return listSum;
        }
};

ListNode * initList(int num) {
    ListNode* list = new ListNode(num % 10);
    ListNode* tmp = list;
    num /= 10;
    while (num != 0) {
        ListNode* node = new ListNode(num % 10);
        tmp->next = node;
        tmp = node;
        num /= 10;
    }
    return list;
}

int main() {
    ListNode* l1 = initList(9);
    ListNode* l2 = initList(9999991);
    Solution s;
    ListNode* sum = s.addTwoNumbers(l1, l2);
    return 0;
}
