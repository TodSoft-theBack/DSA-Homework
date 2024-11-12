#include <string>
#include <iostream>

class Node 
{
    public:
        int Data;
        Node *Next;

        explicit Node(int node_data);
        void Print(std::string sep, std::ostream& fout) const;
};

Node::Node(int node_data)
{
    this->Data = node_data;
    this->Next = nullptr;
}

void Node::Print(std::string sep, std::ostream& fout) const
{
    auto node = this;
    while (node) 
    {
        fout << node->Data;

        node = node->Next;

        if (node) 
            fout << sep;
    }
    fout << std::endl;
}

class LinkedList 
{
    private:
        size_t Count = 0;
        
    public:
        Node* Head;
        Node* Tail;

        LinkedList();
        void insert_node(int node_data);
        size_t Size() const;
        void Print(std::string sep, std::ostream& fout) const;
};

LinkedList::LinkedList() 
{
    Head = nullptr;
    Tail = nullptr;
}

size_t LinkedList::Size() const
{
    return Count;
}

void LinkedList::insert_node(int node_data) 
{
    Node* node = new Node(node_data);

    if (!Head) 
        Head = node;
    else 
        Tail->Next = node;

    Tail = node;
    Count++;
}

void LinkedList::Print(std::string sep, std::ostream& fout) const
{
    auto node = this->Head;
    while (node) 
    {
        fout << node->Data;

        node = node->Next;

        if (node) 
            fout << sep;
    }
}

