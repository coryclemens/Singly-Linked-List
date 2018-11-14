#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
using namespace std;
typedef int elementType;

class List
{


public:

    List(); //constructor
    List(const List & oldList); //copy constructor
    ~List(); //destructor
    bool empty()const;
    void insert(elementType data, int position);
    void print(ostream & out);
    void traverse(int value);
    void traversePos(int pos);
    void reset();
    void shiftPtr();
    void deleteElem(int position);
    int getSize()const;

   //PROGRAM FUNCTIONS FOR HOMEWORK//
    elementType getNth(int nth);
    void split();

private:

    //NODE//
    class Node{
    public:
        elementType data;
        Node * next;
        //NODE CONSTRUCTORS//
        Node();
        Node(elementType data, Node* next);


    };

    Node * head;
    int listSize;
    Node * ptr = head; //used in mostly each function, points to head used to go through each node
    Node * prevPtr = 0; //follows ptr one node behind, used for insertions






};
#endif
