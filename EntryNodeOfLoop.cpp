/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        ListNode* curNode = pHead;
        map<ListNode*, bool>nodeMap;
        while(curNode)
        {
            if(nodeMap.find(curNode)==nodeMap.end())
            {
                nodeMap[curNode] = true;
                curNode = curNode->next;
            }
            else
                return curNode;
        }
        return NULL;
        
        /*大神解法 
        ListNode* p1 = pHead;
        ListNode* p2 = pHead;
        while(p2&&p2->next)
        {    
            p1 = p1->next;
            p2 = p2->next->next;
            if(p1==p2)
                break;   
        }
        if(!p2||!p2->next)
            return NULL;
        p1 = pHead;
        while(p1!=p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;*/ 
    }
};
