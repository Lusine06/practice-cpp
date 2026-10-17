// check if a linked list contains a cycle
bool has_cycle (Node* head) {
    if (head == nullptr) 
        return false; // if list is empty...

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast -> next != nullptr) {
        slow = slow -> next; // +1 step
        fast = fast -> next -> next; //+2 steps

        if (slow == fast)
            return true; // there is a cycle
    }
    
    return false; // no cycle
}