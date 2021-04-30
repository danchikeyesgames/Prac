/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode * result = NULL,* finish = NULL;
    int x, y, c = 0;
    
    if (!l1 && !l2)
        return NULL;
    else if (!l1)
        return l2;
    else if (!l2)
        return l1;

    while(l1 || l2 || c)
    {

        if (l1)
            x = l1->val;
        else
            x = 0;
        
        if (l2)
            y = l2->val;
        else
            y = 0;
        if (!result) {
            result = malloc(sizeof(struct ListNode));
            finish = result;
        } else {
            result->next = malloc(sizeof(struct ListNode));
            result = result->next;
        }
        result->next = NULL;
        result->val = (x + y + c) % 10;
        c = (x + y + c) / 10;
        if (l1)
            l1 = l1->next;
        else
            l1 = NULL;
        
        if (l2)
            l2 = l2->next;
        else
            l2 = NULL;
        result->next = malloc(sizeof(struct ListNode));
        result = result->next;
        result->next = NULL;
    }
    return finish;
}
