#include<iostream>
#include "GenericDSLibrary.hpp"
using namespace std;

int main()
{
    cout<<"================ ARRAY TEST ================\n";
    ArrayX<int> arr(5);
    arr.Accept();
    arr.Display();

    cout<<"Linear Search 10 : "<<arr.LinearSearch(10)<<endl;
    arr.BubbleSortEfficient();
    arr.Display();

    cout<<"\n================ SLL TEST ================\n";
    SinglyLLL<int> sll;
    sll.InsertFirst(30);
    sll.InsertFirst(20);
    sll.InsertLast(40);
    sll.InsertAtPos(25,2);
    sll.Display();
    sll.DeleteAtPos(2);
    sll.Display();
    cout<<"Count : "<<sll.Count()<<endl;

    cout<<"\n================ DLL TEST ================\n";
    DoublyLLL<int> dll;
    dll.InsertFirst(20);
    dll.InsertLast(30);
    dll.InsertAtPos(25,2);
    dll.Display();
    dll.DeleteLast();
    dll.Display();

    cout<<"\n================ SCLL TEST ================\n";
    SinglyCLL<int> scll;
    scll.InsertFirst(10);
    scll.InsertLast(20);
    scll.InsertLast(30);
    scll.Display();
    scll.DeleteFirst();
    scll.Display();

    cout<<"\n================ DCLL TEST ================\n";
    DoublyCLL<int> dcll;
    dcll.InsertFirst(5);
    dcll.InsertLast(15);
    dcll.InsertLast(25);
    dcll.Display();
    dcll.DeleteAtPos(2);
    dcll.Display();

    cout<<"\n================ STACK TEST ================\n";
    Stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.Display();
    cout<<"Pop : "<<stk.pop()<<endl;
    stk.Display();

    cout<<"\n================ QUEUE TEST ================\n";
    Queue<int> q;
    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.Display();
    cout<<"Dequeue : "<<q.dequeue()<<endl;
    q.Display();

    return 0;
}