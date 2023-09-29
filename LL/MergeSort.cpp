Node* mergeLists(Node* first, Node* second, bool isAscending) {
    if (first == nullptr) {
        return second;
    }
    if (second == nullptr) {
        return first;
    }

    if ((first->data < second->data && isAscending) || (first->data > second->data && !isAscending)) {
        first->next = mergeLists(first->next, second, isAscending);
        first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = mergeLists(first, second->next, isAscending);
        second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}
struct Node *sortDoubly(struct Node *head , bool isAscending = 1)
{
  if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* fastPtr = head->next;
    Node* slowPtr = head;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
    }

    Node* secondHalf = slowPtr->next;
    slowPtr->next = nullptr;
    secondHalf->prev = nullptr;

    Node* firstHalfSorted = sortDoubly(head, isAscending);
    Node* secondHalfSorted = sortDoubly(secondHalf, isAscending);

    return mergeLists(firstHalfSorted, secondHalfSorted, isAscending);
}
