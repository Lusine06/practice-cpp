// find the merge node
int findMergeNode(SinglyLinkedListNode *head1, SinglyLinkedListNode *head2)
{
    SinglyLinkedListNode *ptr1 = head1;
    SinglyLinkedListNode *ptr2 = head2;
    
    while (ptr1 != ptr2)
    {
        ptr1 = ptr1->next;
        if (ptr1 == nullptr)
            ptr1 = head2;

        ptr2 = ptr2->next;
        if (ptr2 == nullptr)
            ptr2 = head1;
    }
    
    return ptr1->data; // or ptr2->data
}