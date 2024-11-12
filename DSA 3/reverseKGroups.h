#include "inputUtils.h"
#include "LinkedList.h"

Node* ReverseList(LinkedList* linkedList) 
{ 
    Node* prev = nullptr; 
    Node* current = linkedList->Head; 
    Node* tail = current->Next; 
    
    while (current) 
    { 
        current->Next = prev;
        prev = current;
        current = tail;

        if(tail)
            tail = tail->Next;
    }

    return prev;
}

void ReverseKGroups(LinkedList* llist, size_t K)
{
    if (K <= 1 || !llist || !llist->Head) 
        return;

    auto size = llist->Size();

    Node* groupHead = nullptr;
    Node* prev = nullptr; 
    Node* current = llist->Head; 
    Node* tail = current->Next; 
    Node* groupTail = nullptr;
    auto pos = 0;
    auto isInit = true;

    while (size >= K) 
    { 
        if (!isInit && pos % K == 0)
        {
            size -= K;
            groupHead = current;
            std::cout << current->Data;
        }

        if(isInit)
            isInit = false;
        
        if(pos % K == (K - 1))
        {
            groupTail = current;
            std::cout << current->Data;
        }

        current->Next = prev;
        prev = current;
        current = tail;

        if(tail)
            tail = tail->Next;

        pos++;
    }

    llist->Head = prev;
}


void Input()
{
    auto llist = new LinkedList();

    int llist_count = 0;
    std::cin >> llist_count;

    for (int i = 0; i < llist_count; i++) 
    {
        int llist_item = 0;
        std::cin >> llist_item;
        llist->insert_node(llist_item);
    }

    size_t K = 0;
    std::cin >> K;

    ReverseKGroups(llist, K);

    llist->Head->Print(" -> ", std::cout);
    std::cout << std::endl;

    delete llist;
}
