/*
 *  @author 707<707472783@qq.com>
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
    private:
        int num1 = 0;
        int num2 = 0;
        int sum = 0;
    public:
        ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
            while (l1 != NULL) {
                num1 = l1->val * 10 + num1;
                l1 = l1->next;
            }
            num1 /= 10;
            while (l2 != NULL) {
                num2 = l2->val * 10 + num1;
                l2 = l2->next;
            }
            num2 /= 10;
            sum = num1 + num2;

            ListNode* listSum = new ListNode(sum % 10);
            ListNode* listTmp = listSum;
            sum /= 10;
            while (sum % 10 != 0) {
                ListNode* node = new ListNode(sum % 10);
                listTmp->next = node;
                listTmp = node;
                sum /= 10;
            }
};
