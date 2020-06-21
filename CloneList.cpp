/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        map<RandomListNode*, RandomListNode*> nodeMap;
        if(!pHead)
            return NULL;
        RandomListNode* current = pHead;
        while(current)
        {
            nodeMap[current] = new RandomListNode(current->label);
            current = current->next;
        }
        RandomListNode* current1 = pHead;
        while(current1)
        {
            nodeMap[current1]->random = nodeMap[current1->random];
            nodeMap[current1]->next = nodeMap[current1->next];
            current1 = current1->next;
        }
        return nodeMap[pHead];
    }
};
