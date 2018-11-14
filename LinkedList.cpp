#include <iostream>
using namespace std;
#include "LinkedList.h"
#include <new>

        //List Constructor//
    //CREATES EMPTY LIST//

List::List()
:head(0), listSize(0)
    {
        cout << "List Created.." << endl << endl;
    }


        //List Destructor//
    //DELETES ALL NODES//

List::~List()
{
Node* ptr;

ptr=head;

head=NULL;

while(ptr)
{
   Node * deletePtr = ptr;
   ptr=ptr->next;
   delete deletePtr;
}

cout << "List has been deleted.." << endl << endl;
}

        //LIST FUNCTIONS//

    //TRAVERSE//
    //SEARCHES NODES FOR CERTAIN DATA//

void List::traverse(int data){
    int i=0;
    while(ptr!=0){
        if(ptr->data==data){
            cout << "Data found in index: " << i << endl << endl;
        }
        prevPtr=ptr;
        ptr=ptr->next;
        ++i;
    }
    reset();
}


//SHIFTS POINTER AND PREVPNTR RIGHT ONE INDEX//
void List::shiftPtr(){

        prevPtr=ptr;
        ptr=ptr->next;

}

//USES SHIFTPTR TO TRAVERSE TO SPECIFIC LOCATION//
void List::traversePos(int pos){
    int i;
    for(i=0; i < pos; ++i)
        {
            shiftPtr();
        }
}

//RESETS PTR AND prevPTR//
//USED AFTER FUNCTION CALLS TO SET THEM BACK//
void List::reset(){

    ptr=head;
    prevPtr=0;


}

//INSERT//
//INSERTS NODE AT SPECIFIED POSITION//
void List::insert(elementType data, int position){
        Node* newPtr = new Node(data, 0);

        traversePos(position);
        if(prevPtr!=0)
            {
                newPtr->next=prevPtr->next;
                prevPtr->next=newPtr;
                cout << "Inserted new node. Data: " << data << "  Index: " << position << endl << endl;
                    listSize+=1;
            }
        else
            {
                newPtr->next=head;
                head = newPtr;
                cout << "Inserted new node. Data: " << data << "  Index: " << position << endl << endl;
                cout << "Head pointing to: " << head << endl << endl;
                listSize+=1;

            }

            reset();



}

//DELETES ELEMENT AT SPECIFIC POSITION//
void List::deleteElem(int position){

    traversePos(position);
    Node * deletePtr =ptr;

    if(prevPtr  != 0)
    {
        ptr=ptr->next;
        prevPtr->next=ptr;
        delete deletePtr;

    }
    else
    {
        ptr=head;
        head=ptr->next;
    }
    cout << "Index: " << position << " has been deleted." << endl << endl;
    reset();
    listSize-=1;
}


//RETURNS 1 if empty, 0 if not empty
bool List::empty()const{

    return (listSize==0);

}


//PRINTS A FULL LIST//
void List::print(ostream & out){
    int i;

for(i=0; ptr != 0; ++i){

    out << "Index: " << i << endl;
    out << "-----" << endl;
    out << "Data: " << ptr->data << endl << endl;
    ptr=ptr->next;
}
reset();
}

//NODE FUNCTIONS//

List::Node::Node()
    :data(0), next(0)
    {
    }

List::Node::Node(int data, Node* next = 0)
            :data(data), next(next)
            {
            }



int List::getSize()const{

    return listSize;
}

//ITERATES TO NTH ELEMENT AND RETURNS DATA IN THAT INDEX//
elementType List::getNth(int nth){
    int length = listSize;
    elementType data;
    ptr=head;

    if(nth>(length-1)){
        cout << "Invalid index..." << endl << endl;
        return -1;
    }
    else if(ptr==0){
        cout << "List is empty..." << endl << endl;
        return -1;
    }

    else{
        for(int i=0; i <= (nth-1); ++i)
        {
            ptr=ptr->next;
        }

    }
    data=ptr->data;
    reset();
    return data;
}

//SPLITS LIST INTO 2//
void List::split()
{
    reset();
    int length=listSize;
    int loopLength=listSize;

    if(length==0) //case 1
    {
        cout << "No elements in list...." << endl << endl;
        return;
    }
    else if(length==1) //case 2
    {
        cout << "List only contains one element...." << endl << endl;
        return;
    }
    else if(length==2) //case 3
    {
        Node * unlink = head;
        ptr=ptr->next;
        List newList;
        newList.head=ptr;
        unlink->next = 0;
        reset();
        cout << "List has been split..." << endl;
        cout << "Printing lists..." << endl << endl;
        cout << "List 1: " << endl;
        cout << "------------------" << endl;
        print(cout);
        cout << "List 2: " << endl;
        cout << "------------------" << endl;
        newList.reset();
        newList.print(cout);
        return;


    }
    else //case 4
    {
        length=length%2;
        if(length==0)
        {
            loopLength=loopLength/2;
            Node * unlink = head;

            for(int i=0; i<loopLength; ++i)
            {
               ptr=ptr->next;

            }
            for(int i=1; i<loopLength; ++i){
                unlink=unlink->next;
            }

            List newList;
            newList.head = ptr;
            unlink->next=0;
            reset();
            newList.reset();
            cout << "List has been split..." << endl;
            cout << "Printing lists..." << endl << endl;
            cout << "List 1: " << endl;
             cout << "------------------" << endl;
            print(cout);
            cout << "List 2: " << endl;
            cout << "------------------" << endl;
            newList.print(cout);
        }
        if(length==1)
            {
              loopLength = (loopLength/2) + 1;   //same as for even numbers, except add one to loop length
              Node * unlink = head;

            for(int i=0; i<loopLength; ++i)
            {
               ptr=ptr->next;

            }
            for(int i=1; i<loopLength; ++i){
                unlink=unlink->next;
            }


            List newList;
            newList.head=ptr;
            unlink->next=0;
            reset();
            newList.reset();
            cout << "List has been split..." << endl;
            cout << "Printing lists..." << endl << endl;
            cout << "List 1: " << endl;
             cout << "------------------" << endl;
            print(cout);
            cout << "List 2: " << endl;
             cout << "------------------" << endl;
            newList.print(cout);


        }



    }
}

//ATTEMPT AT DEEP COPY CONSTRUCTOR//
List::List(const List & oldList)
{
    ptr=head;
    prevPtr=0;

if(oldList.head==0){
    head=0;
    cout << "Copy Constructor has created a new empty list.." << endl << endl;
}
else
{
   head=new Node(oldList.head->data, 0);
   Node * newL = head;
   Node * oldL = oldList.head;
   while(oldL)
    {
        newL->next = new Node();
        oldL=oldL->next;
        newL=newL->next;
        newL->data=oldL->data;
    }
    cout << "Copy Constructor created new list with elements.." << endl << endl;
}


}











ostream & operator<<(ostream & out, const List & L)
{

L.print(out);
return out;


}
*/

