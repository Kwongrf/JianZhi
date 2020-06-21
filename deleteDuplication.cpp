#include<iostream>
#include<stdlib.h>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(!pHead)
            return NULL;
        ListNode* prevNode = NULL;
        ListNode* preprevNode = NULL;
        ListNode* curNode = pHead;
        int curVal;
        while(curNode)
        {
            bool flag = false;
            if(prevNode)
            {
                
                if(preprevNode)
                {
                    
                    while(curNode&&curVal==curNode->val)
                    {
                        flag = true;
                        preprevNode->next = curNode->next;
                        curNode = curNode->next;
                    }
                    if(flag)
                    {
                        prevNode = preprevNode;
                    }
                }
                else 
                {
                    while(curNode&&curVal==curNode->val)
                    {
                        flag = true;
                        curNode = curNode->next;
                    }
                    if(flag)
                    {
                    		pHead = curNode;
                    		prevNode = NULL;
                    		preprevNode = NULL;
					}
                }
            }
            if(!curNode)
            	break;
            preprevNode = prevNode;
            prevNode = curNode;
            curVal = curNode->val;
            curNode = curNode->next;
        }
        
        return pHead;
    }
};
void show(ListNode* pHead)
{
	while(pHead)
	{
		cout<<pHead->val<<" ";
		pHead = pHead->next;
	}
}
int main()
{
	Solution solution;
	ListNode* pHead = new ListNode(1);
	ListNode* curNode =pHead;
	curNode->next =  new ListNode(1);
	curNode = curNode->next;
	curNode->next =  new ListNode(3);
	curNode = curNode->next;
	curNode->next =  new ListNode(4);
	curNode = curNode->next;
	curNode->next =  new ListNode(4);
	curNode = curNode->next;
	curNode->next =  new ListNode(4);
	curNode = curNode->next;
	curNode->next =  new ListNode(5);
	curNode = curNode->next;
	
	show(solution.deleteDuplication(pHead));
	
}
