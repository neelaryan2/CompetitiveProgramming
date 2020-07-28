/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#define node RandomListNode
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    if (A == NULL) return NULL;
    node* head = A;
    map<node*, int> id;
    int n = 0;
    vector<node*> a;
    while (head != NULL) {
        id[head] = n++;
        a.push_back(head);
        head = head->next;
    }
    head = new node(A->label);
    vector<node*> b(1, head);
    for (int i = 1; i < n; i++) {
        head->next = new node(a[i]->label);
        head = head->next;
        b.push_back(head);
    }
    for (int i = 0; i < n; i++) {
        node* c = a[i]->random;
        if (c == NULL) continue;
        int j = id[a[i]->random];
        b[i]->random = b[j];
    }
    return b[0];
}
