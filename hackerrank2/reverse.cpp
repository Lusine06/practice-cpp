//reverse the list
DoublyLinkedListNode *reverse(DoublyLinkedListNode *llist) {
    DoublyLinkedListNode *current = llist;
    DoublyLinkedListNode *prevNode = nullptr;

    while (current != nullptr) {
        DoublyLinkedListNode *nextNode = current->next;

        current->next = prevNode;
        current->prev = nextNode;

        prevNode = current;
        current = nextNode;
    }

    return prevNode;
}