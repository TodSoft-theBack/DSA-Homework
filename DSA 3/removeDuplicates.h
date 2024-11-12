#include "LinkedList.h"
#include "inputUtils.h"

Node* removeDuplicates(Node* llist) 
{
    if (!llist)
        return llist;

    auto prev = llist;
    auto current = llist->Next;

    while (current)
    {
        if (current->Data == prev->Data)
        {
            auto newCurrent = current->Next;
            prev->Next = newCurrent;
            delete current;
            current = newCurrent;
            continue;
        }
        else
            prev = current;

        if(!current)
            break;
            
        current = current->Next;
    }
    return llist;
    
}


void Input()
{
    LinkedList* llist = new LinkedList();

    std::string llist_count_temp;
    getline(std::cin, llist_count_temp);

    int llist_count = stoi(ltrim(rtrim(llist_count_temp)));

    for (int i = 0; i < llist_count; i++) 
    {
        std::string llist_item_temp;
        getline(std::cin, llist_item_temp);

        int llist_item = stoi(ltrim(rtrim(llist_item_temp)));

        llist->insert_node(llist_item);
    }


    Node* llist_head = removeDuplicates(llist->Head);

    llist_head->Print(" -> ", std::cout);
    std::cout << std::endl;

    delete llist_head;
    delete llist;
}
