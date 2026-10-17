//inserting a node into a slorted doubly linked list
DoublyLinkedListNode *sortedInsert(DoublyLinkedListNode *llist, int data)
{
    DoublyLinkedListNode *newNode = new DoublyLinkedListNode(data);

    if (llist == nullptr)
        return newNode;
        
    if (data <= llist->data)
    {
        newNode->next = llist;
        llist->prev = newNode;
        return newNode;
    }
    
    DoublyLinkedListNode *curr = llist;
    while (curr->next != nullptr && curr->next->data <= data) {
        curr = curr->next;
    }
    
    newNode->next = curr->next;
    newNode->prev = curr;
    
    if (curr->next != nullptr) {
        curr->next->prev = newNode;
    }
    curr->next = newNode;
    
    return llist;
}