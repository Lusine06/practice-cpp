//insert node at a specific position in a linked list
SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* llist, int data, int position) {
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    
    if (position == 0) {
        newNode->next = llist;
        return newNode; 
    }
    
    SinglyLinkedListNode* curr = llist;
    for (int i = 0; i < position - 1; i++) {
        curr = curr->next; // (where the node should be added) - 1
    }
    
    newNode->next = curr->next;
    curr->next = newNode;
    
    return llist;
}