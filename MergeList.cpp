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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
        
        ListNode* newList;
        ListNode* curNode;
        if(pHead1->val <= pHead2->val)
        {
            newList = pHead1;
            pHead1 = pHead1->next;
        }    
        else
        {
            newList = pHead2;
            pHead2 = pHead2->next;
            
        }    
        curNode = newList;
        curNode->next = NULL;
        while(pHead1!=NULL and pHead2!=NULL)
        {
            if(pHead1->val <= pHead2->val)
            {
                curNode->next = pHead1;
                pHead1 = pHead1->next;
                
            } 
            else
            {
                curNode->next = pHead2;
                pHead2 = pHead2->next;
            }
            curNode = curNode->next;
            curNode->next = NULL;
        }
        if(pHead1==NULL)
            curNode->next = pHead2;
        if(pHead2==NULL)
            curNode->next = pHead1;
        
        return newList;
    }
};
