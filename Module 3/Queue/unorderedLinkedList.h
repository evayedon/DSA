#ifndef UNORDEREDLINKEDLIST_H
#define UNORDEREDLINKEDLIST_H

template <class Type>
class unorderedLinkedList
{
private:
    struct nodeType
    {
        Type info; 
        nodeType* link;
    };
    nodeType* first;
    nodeType* last; 
    int count; 
public:
    unorderedLinkedList(); 
    ~unorderedLinkedList(); 

    int getCount() const { return count; } 
    nodeType* getFirst() const { return first; } 
    nodeType* getLast() const { return last; } 
    void initializeList(); 
    bool isEmptyList() const;
    int length() const; 
    void print() const; 

    void insertFirst(const Type& newElement);
    void insertLast(const Type& newElement); 
    void deleteNode(const Type& deleteItem); 

    bool search(const Type& searchItem) const;
    void insertAt(int position, const Type& newElement); 
    void deleteAt(int position);  
};

#endif // UNORDEREDLINKEDLIST_H