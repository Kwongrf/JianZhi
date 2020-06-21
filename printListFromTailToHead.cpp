/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* current = head;
        stack<int>stk;
        vector<int>result;
        while(current)
        {
            stk.push(current->val);
            current = current->next;
        }
        while(!stk.empty())
        {
            result.push_back(stk.top());
            stk.pop();
        }
        return result;
    }
};
