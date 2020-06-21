/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
 #include <unordered_map>
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        unordered_map<ListNode*, bool> nodeMap;
        ListNode* curNode = pHead1;
        while(curNode)
        {
            nodeMap[curNode] = true;
            curNode = curNode->next;
        }
        curNode = pHead2;
        while(curNode)
        {
            if(nodeMap.find(curNode)!= nodeMap.end())
               return curNode;
            curNode = curNode->next;
        }
        return NULL;//笨蛋写法 
    }
    /*大神写法 
    ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1!=p2){
            p1 = (p1==NULL ? pHead2 : p1->next);
            p2 = (p2==NULL ? pHead1 : p2->next);
        }
        return p1;*/
};
