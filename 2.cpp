/*
 *  @author 707<707472783@qq.com>
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
    private:
        int num1 = 0;
        int num2 = 0;
        int sum = 0;
    public:
        ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
            int base = 1;
            while (l1 != nullptr) {
                num1 = l1->val * base + num1;
                l1 = l1->next;
                base *= 10;
            }
            base = 1;
            while (l2 != nullptr) {
                num2 = l2->val * base + num2;
                l2 = l2->next;
                base *= 10;
            }
            sum = num1 + num2;

            ListNode* listSum = new ListNode(sum % 10);
            ListNode* listTmp = listSum;
            sum /= 10;
            while (sum != 0) {
                ListNode* node = new ListNode(sum % 10);
                listTmp->next = node;
                listTmp = node;
                sum /= 10;
            }
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
    ListNode* l1 = initList(342);
    ListNode* l2 = initList(465);
    Solution s;
    ListNode* sum = s.addTwoNumbers(l1, l2);
    return 0;
}
