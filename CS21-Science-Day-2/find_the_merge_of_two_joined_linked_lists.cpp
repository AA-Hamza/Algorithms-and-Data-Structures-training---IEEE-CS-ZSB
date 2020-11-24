/*
    Problem Link https://www.hackerrank.com/challenges/find-the-merge-point-of-two-joined-linked-lists/problem

    The problem stated strictly that I should only change the function findMergeNode
    
    Time Complexity = O(n) where n = max(node1_length, node2_length) 
*/

int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    // Step one find the length of each node
    int node1_length = 0, node2_length = 0;
    SinglyLinkedListNode *tmp;

    tmp = head1;
    while (tmp != NULL) {
        node1_length++;
        tmp = tmp->next;
    }

    tmp = head2;
    while (tmp != NULL) {
        node2_length++;
        tmp = tmp->next;
    }

    //Step two find the smaller length (the merge could be at least that)
    int smaller = min(node2_length, node1_length);
    
    //Now start iterating from backwords (starting from the smaller length)
    SinglyLinkedListNode *curr1 = head1, *curr2 = head2;
    for (int i = 0; i < (node1_length - smaller); ++i) {
        curr1 = curr1->next;
    }
    for (int i = 0; i < (node2_length - smaller); ++i) {
        curr2 = curr2->next;
    }

    //Step 3 now curr1 & curr2 are starting from equal length(smaller) from backword
    //So just compare addresses
    while (curr1 != curr2) {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }

    return curr1->data;
}
