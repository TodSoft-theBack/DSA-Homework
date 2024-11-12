#include "LinkedList.h"
#include "inputUtils.h"

Node* insertNodeAtPosition(Node* llist, int data, int position) 
{
    Node* prev = nullptr;
    auto current = llist;
    
    while(position)
    {
        position--;
        prev = current;

        if(current)
            current = current->Next;
        else
            break;
    }

    auto dataNode = new Node(data);
    dataNode->Next = current;
    
    if(prev)
        prev->Next = dataNode;
    else
        return dataNode;

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

    std::string data_temp;
    getline(std::cin, data_temp);

    int data = stoi(ltrim(rtrim(data_temp)));

    std::string position_temp;
    getline(std::cin, position_temp);

    int position = stoi(ltrim(rtrim(position_temp)));

    Node* llist_head = insertNodeAtPosition(llist->Head, data, position);

    llist_head->Print(" -> ", std::cout);
    std::cout << std::endl;

    delete llist_head;
    delete llist;
}

