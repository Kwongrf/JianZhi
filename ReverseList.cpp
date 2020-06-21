/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        stack<ListNode*> stk;
        if(pHead==NULL)
            return NULL;
        while(pHead)
        {
            stk.push(pHead);
            pHead = pHead->next;
        }
        
        
        ListNode* newList = stk.top();
        newList->next = NULL;
        
        ListNode* currNode = newList;
        stk.pop();
        
        while(!stk.empty())
        {
            currNode->next = stk.top();
            currNode = stk.top();
            stk.pop();   
        }
        currNode->next = NULL;
        return newList;
        
    }
};
