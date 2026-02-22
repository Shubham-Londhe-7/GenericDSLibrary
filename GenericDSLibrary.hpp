////////////////////////////////////////////////////////////////////////////////////////////////////////
//  Generalised Data Structure Library
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

// Sorting order macros
#define INC_ORDER 1
#define DEC_ORDER 2

////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Array using Generic Approach
////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Class Name :        ArrayX
//      Description :       Generic Array class supporting searching & sorting operations
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class ArrayX 
{
    public :
        T *Arr;        
        int iSize;     
        bool Sorted;   

        ArrayX(int);
        ~ArrayX();                                                                        

        void Accept();     
        void Display();    

        bool CheckSorted();

        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T); 

        void BubbleSort();
        void BubbleSortEfficient();
        void BubbleSortEfficientX(int iOption = INC_ORDER);

        void SelectionSort();
        void InsertionSort();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     ArrayX
//      Description :       Allocate memory for array
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
ArrayX <T> :: ArrayX(int no)
{
    cout<<"Inside Constructor"<<endl;
    iSize = no;
    Arr = new T[iSize];
    Sorted = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     ~ArrayX
//      Description :       Deallocate array memory
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
ArrayX <T> :: ~ArrayX()
{
    cout<<"Inside Destructor"<<endl;
    delete [] Arr;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Accept
//      Description :       Accept elements and detect sorted state
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX <T> :: Accept()
{
    int iCnt = 0;
    cout<<"Enter the elements :"<<endl;
    
    cin>>Arr[iCnt];
    for(iCnt = 1; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];

        if(Arr[iCnt-1] > Arr[iCnt])
        {
            Sorted = false;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Display
//      Description :       Display array elements
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX <T> :: Display()
{
    cout<<"Elements of the array are :"<<endl;

    for(int iCnt = 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     LinearSearch
//      Description :       Perform linear search on array
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool ArrayX <T> :: LinearSearch(T iNo)
{
    for(int i = 0; i < iSize; i++)
    {
        if(Arr[i] == iNo)
            return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     BidirectionalSearch
//      Description :       Search element from both ends simultaneously
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool ArrayX <T> :: BidirectionalSearch(T iNo)
{
    for(int iStart = 0, iEnd = iSize-1; iStart <= iEnd; iStart++, iEnd--)
    {
        if(Arr[iStart] == iNo || Arr[iEnd] == iNo)
            return true;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     CheckSorted
//      Description :       Check whether array is sorted
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool ArrayX <T> :: CheckSorted()
{
    for(int i = 0; i < iSize - 1; i++)
    {
        if(Arr[i] > Arr[i+1])
            return false;
    }
    return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     BinarySearch
//      Description :       Perform binary search (fallback to bidirectional if unsorted)
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
bool ArrayX <T> :: BinarySearch(T iNo)
{
    if(!Sorted)
        return BidirectionalSearch(iNo);

    int iStart = 0, iEnd = iSize-1;

    while (iStart <= iEnd)
    {
        int iMid = iStart + ((iEnd - iStart) / 2);

        if(Arr[iMid] == iNo) return true;
        else if(iNo < Arr[iMid]) iEnd = iMid - 1;
        else iStart = iMid + 1;
    }
    return false;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     BubbleSort
//      Description :       Perform basic bubble sort
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX <T> :: BubbleSort()
{
    if(Sorted) return;

    T temp;
    int Pass = 0, Time = 0;

    for(int i = 0; i < iSize-1; i++, Pass++)
    {
        for(int j = 0; j < iSize-1-i; j++, Time++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
            }
        }
    }
    cout<<"Number of passes : "<<Pass<<"\n";
    cout<<"Iterations : "<<Time<<"\n";
    Sorted = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     BubbleSortEfficient
//      Description :       Optimized bubble sort using swap flag
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX <T> :: BubbleSortEfficient()
{
    T temp;
    bool bFlag = true;
    int i;

    for(i = 0; (i < iSize-1) && bFlag; i++)
    {
        bFlag = false;
        for(int j = 0; j < iSize-1-i; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                bFlag = true;
            }
        }
    }
    cout<<"Total passes : "<<i<<"\n";
    Sorted = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     BubbleSortEfficientX
//      Description :       Bubble sort with sorting order control
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX <T> :: BubbleSortEfficientX(int iOption)
{
    if(iOption != INC_ORDER && iOption != DEC_ORDER)
    {
        cout<<"Invalid option\n";
        return;
    }

    T temp;
    bool bFlag = true;
    int i;

    for(i = 0; (i < iSize-1) && bFlag; i++)
    {
        bFlag = false;
        for(int j = 0; j < iSize-1-i; j++)
        {
            if((iOption == INC_ORDER && Arr[j] > Arr[j+1]) ||
               (iOption == DEC_ORDER && Arr[j] < Arr[j+1]))
            {
                temp = Arr[j];
                Arr[j] = Arr[j+1];
                Arr[j+1] = temp;
                bFlag = true;
            }
        }
    }
    cout<<"Total passes : "<<i<<"\n";
    Sorted = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     SelectionSort
//      Description :       Perform selection sort
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX <T> :: SelectionSort()
{
    T temp;
    for(int i = 0; i < iSize-1; i++)
    {
        int min_index = i;
        for(int j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
                min_index = j;
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
    Sorted = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertionSort
//      Description :       Perform insertion sort
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void ArrayX <T> :: InsertionSort()
{
    for(int i = 1; i < iSize; i++)
    {
        T Selected = Arr[i];
        int j;
        for(j = i-1; (j >= 0) && (Arr[j] > Selected); j--)
        {
            Arr[j+1] = Arr[j];
        }
        Arr[j+1] = Selected;
    }
    Sorted = true;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Singly Linear LinkedList using Generic Approach
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T>* next;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     SinglyLLLnode (Constructor)
//      Description :       Initialize node with data
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = nullptr;
        }
};

template <class T>
class SinglyLLL
{
    private:
        SinglyLLLnode<T>* first;
        int iCount;

    public:

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     SinglyLLL (Constructor)
//      Description :       Initialize Singly Linear Linked List
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
        SinglyLLL()
        {
            cout<<"Object of SinglyLL gets created."<<endl;
            this->first = nullptr;
            this->iCount = 0;
        }

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertFirst
//      Description :       Insert node at first position
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T>* newn = new SinglyLLLnode<T>(no);
    newn->next = this->first;
    this->first = newn;
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertLast
//      Description :       Insert node at last position
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T>* newn = new SinglyLLLnode<T>(no);

    if(this->first == nullptr)
    {
        this->first = newn;
    }
    else
    {
        SinglyLLLnode<T>* temp = this->first;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteFirst
//      Description :       Delete first node
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    if(this->first == nullptr)
        return;

    SinglyLLLnode<T>* temp = this->first;
    this->first = this->first->next;
    delete temp;
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteLast
//      Description :       Delete last node
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteLast()
{
    if(this->first == nullptr)
        return;

    if(this->first->next == nullptr)
    {
        delete this->first;
        this->first = nullptr;
    }
    else
    {
        SinglyLLLnode<T>* temp = this->first;
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertAtPos
//      Description :       Insert node at specified position
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"INVALID POSITION"<<endl;
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        SinglyLLLnode<T>* newn = new SinglyLLLnode<T>(no);
        SinglyLLLnode<T>* temp = this->first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteAtPos
//      Description :       Delete node from specified position
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"INVALID POSITION"<<endl;
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        SinglyLLLnode<T>* temp = this->first;
        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        SinglyLLLnode<T>* target = temp->next;
        temp->next = target->next;
        delete target;
        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Display
//      Description :       Display Singly Linear Linked List
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::Display()
{
    SinglyLLLnode<T>* temp = this->first;
    while(temp != nullptr)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Count
//      Description :       Return number of nodes in list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Doubly Linear LinkedList using Generic Approach
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyLLLnode
{
    public:
        T data;
        DoublyLLLnode<T>* next;
        DoublyLLLnode<T>* prev;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DoublyLLLnode (Constructor)
//      Description :       Initialize doubly node with data
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T>* first;
        int iCount;

    public:

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DoublyLLL (Constructor)
//      Description :       Initialize Doubly Linear Linked List
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
        DoublyLLL()
        {
            cout<<"Object DoublyLLL gets created"<<endl;
            this->first = nullptr;
            this->iCount = 0;
        }

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Display();
        int Count();  
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertFirst
//      Description :       Insert node at first position
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T>* newn = new DoublyLLLnode<T>(no);

    if(this->first == nullptr)
    {
        this->first = newn;
    }
    else
    {
        newn->next = this->first;
        this->first->prev = newn;
        this->first = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertLast
//      Description :       Insert node at last position
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T>* newn = new DoublyLLLnode<T>(no);

    if(this->first == nullptr)
    {
        this->first = newn;
    }
    else
    {
        DoublyLLLnode<T>* temp = this->first;
        while(temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertAtPos
//      Description :       Insert node at specified position
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"INVALID POSITION"<<endl;
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        DoublyLLLnode<T>* newn = new DoublyLLLnode<T>(no);
        DoublyLLLnode<T>* temp = this->first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteFirst
//      Description :       Delete first node
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if(this->first == nullptr)
        return;

    if(this->first->next == nullptr)
    {
        delete this->first;
        this->first = nullptr;
    }
    else
    {
        DoublyLLLnode<T>* temp = this->first;
        this->first = this->first->next;
        this->first->prev = nullptr;
        delete temp;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteLast
//      Description :       Delete last node
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteLast()
{
    if(this->first == nullptr)
        return;

    if(this->first->next == nullptr)
    {
        delete this->first;
        this->first = nullptr;
    }
    else
    {
        DoublyLLLnode<T>* temp = this->first;
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
    }
    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteAtPos
//      Description :       Delete node at specified position
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > this->iCount)
    {
        cout<<"INVALID POSITION"<<endl;
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        DeleteLast();
    }
    else
    {
        DoublyLLLnode<T>* temp = this->first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        DoublyLLLnode<T>* target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        this->iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Display
//      Description :       Display Doubly Linear Linked List
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::Display()
{
    DoublyLLLnode<T>* temp = this->first;

    cout<<"NULL <=> ";
    while(temp != nullptr)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Count
//      Description :       Return node count
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Singly Circular LinkedList using Generic Approach
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T>* next;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     SinglyCLLnode (Constructor)
//      Description :       Initialize circular node with data
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = nullptr;
        }
};

template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T>* first;
        SinglyCLLnode<T>* last;
        int iCount;

    public:

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     SinglyCLL (Constructor)
//      Description :       Initialize Singly Circular Linked List
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
        SinglyCLL()
        {
            cout<<"Object of SinglyCL gets Created\n";
            this->first = nullptr;
            this->last = nullptr;
            this->iCount = 0;
        }

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int);
        void InsertAtPos(T, int);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertFirst
//      Description :       Insert node at first position in circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T>* newn = new SinglyCLLnode<T>(no);

    if(first == nullptr && last == nullptr)
    {
        first = last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertLast
//      Description :       Insert node at last position in circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T>* newn = new SinglyCLLnode<T>(no);

    if(first == nullptr && last == nullptr)
    {
        first = last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteFirst
//      Description :       Delete first node from circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == nullptr && last == nullptr)
        return;

    if(first == last)
    {
        delete first;
        first = last = nullptr;
    }
    else
    {
        SinglyCLLnode<T>* temp = first;
        first = first->next;
        delete temp;
        last->next = first;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteLast
//      Description :       Delete last node from circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    if(first == nullptr && last == nullptr)
        return;

    if(first == last)
    {
        delete first;
        first = last = nullptr;
    }
    else
    {
        SinglyCLLnode<T>* temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertAtPos
//      Description :       Insert node at given position in circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
        InsertFirst(no);
    else if(pos == iCount + 1)
        InsertLast(no);
    else
    {
        SinglyCLLnode<T>* newn = new SinglyCLLnode<T>(no);
        SinglyCLLnode<T>* temp = first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteAtPos
//      Description :       Delete node at given position in circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
        DeleteFirst();
    else if(pos == iCount)
        DeleteLast();
    else
    {
        SinglyCLLnode<T>* temp = first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        SinglyCLLnode<T>* target = temp->next;
        temp->next = target->next;
        delete target;
        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Display
//      Description :       Display Singly Circular Linked List
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::Display()
{
    if(first == nullptr)
        return;

    SinglyCLLnode<T>* temp = first;

    cout<<"-> ";
    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    } while(temp != first);

    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Count
//      Description :       Return node count of circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Doubly Circular LinkedList using Generic Approach
////////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T>* next;
        DoublyCLLnode<T>* prev;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DoublyCLLnode (Constructor)
//      Description :       Initialize doubly circular node with data
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T>* first;
        DoublyCLLnode<T>* last;
        int iCount;

    public:

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DoublyCLL (Constructor)
//      Description :       Initialize Doubly Circular Linked List
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
        DoublyCLL()
        {
            cout<<"Object of DoublyCL gets created."<<endl;
            this->first = nullptr;
            this->last = nullptr;
            this->iCount = 0;
        }

        void InsertFirst(T);
        void InsertLast(T);
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T, int);
        void DeleteAtPos(int);
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertFirst
//      Description :       Insert node at first position in doubly circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T>* newn = new DoublyCLLnode<T>(no);

    if(first == nullptr && last == nullptr)
    {
        first = last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertLast
//      Description :       Insert node at last position in doubly circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T>* newn = new DoublyCLLnode<T>(no);

    if(first == nullptr && last == nullptr)
    {
        first = last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;
        last = newn;
    }

    last->next = first;
    first->prev = last;
    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteFirst
//      Description :       Delete first node from doubly circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(first == nullptr && last == nullptr)
        return;

    if(first == last)
    {
        delete first;
        first = last = nullptr;
    }
    else
    {
        DoublyCLLnode<T>* temp = first;
        first = first->next;
        delete temp;

        first->prev = last;
        last->next = first;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteLast
//      Description :       Delete last node from doubly circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(first == nullptr && last == nullptr)
        return;

    if(first == last)
    {
        delete last;
        first = last = nullptr;
    }
    else
    {
        DoublyCLLnode<T>* temp = last;
        last = last->prev;
        delete temp;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     InsertAtPos
//      Description :       Insert node at given position in doubly circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertAtPos(T no, int pos)
{
    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
        InsertFirst(no);
    else if(pos == iCount + 1)
        InsertLast(no);
    else
    {
        DoublyCLLnode<T>* newn = new DoublyCLLnode<T>(no);
        DoublyCLLnode<T>* temp = first;

        for(int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     DeleteAtPos
//      Description :       Delete node at given position in doubly circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
        DeleteFirst();
    else if(pos == iCount)
        DeleteLast();
    else
    {
        DoublyCLLnode<T>* temp = first;

        for(int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Display
//      Description :       Display Doubly Circular Linked List
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::Display()
{
    if(first == nullptr)
        return;

    DoublyCLLnode<T>* temp = first;

    cout<<"<=> ";
    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != first);

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Count
//      Description :       Return node count of doubly circular list
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Stack using Generic Approach
////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Class Name :        Stacknode
//      Description :       Node structure for generic stack
//      Author :            Shubham Tanaji Londhe
//      Date :              22/02/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T>* next;

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Stacknode (Constructor)
//      Description :       Initialize stack node
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
        Stacknode(T no)
        {
            this->data = no;
            this->next = nullptr;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Class Name :        Stack
//      Description :       Generic Stack implementation using Singly Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Stack
{
    private:
        Stacknode<T>* first;   // Top of stack
        int iCount;            // Number of elements
    
    public:

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Stack (Constructor)
//      Description :       Initialize stack
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
        Stack()
        {
            cout<<"Object of Stack gets created"<<endl;
            this->first = nullptr;
            this->iCount = 0;
        }

        void push(T);
        T pop();
        T peep();
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     push
//      Description :       Insert element at top of stack
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::push(T no)
{
    Stacknode<T>* newn = new Stacknode<T>(no);
    newn->next = this->first;
    this->first = newn;
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     pop
//      Description :       Remove element from top
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>::pop()
{
    if(this->first == nullptr)
    {
        cout<<"Stack is empty"<<endl;
        return T();
    }

    Stacknode<T>* temp = this->first;
    T value = temp->data;

    this->first = this->first->next;
    delete temp;
    this->iCount--;

    return value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     peep
//      Description :       Return top element without removing
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Stack<T>::peep()
{
    if(this->first == nullptr)
    {
        cout<<"Stack is empty"<<endl;
        return T();
    }
    return this->first->data;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Display
//      Description :       Display stack elements (top → bottom)
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Stack<T>::Display()
{
    if(this->first == nullptr)
    {
        cout<<"Stack is empty"<<endl;
        return;
    }

    Stacknode<T>* temp = this->first;
    while(temp != nullptr)
    {
        cout<<"|\t"<<temp->data<<"\t|"<<endl;
        temp = temp->next;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Count
//      Description :       Return number of elements
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Stack<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//          Queue using Generic Approach
////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Class Name :        Queuenode
//      Description :       Node structure for generic queue
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T>* next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = nullptr;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Class Name :        Queue
//      Description :       Generic Queue implementation using Singly Linked List
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Queue
{
    private:
        Queuenode<T>* first;
        Queuenode<T>* last;
        int iCount;

    public:
        Queue()
        {
            cout<<"Object of Queue gets created"<<endl;
            this->first = nullptr;
            this->last = nullptr;
            this->iCount = 0;
        }

        void enqueue(T);
        T dequeue();
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     enqueue
//      Description :       Insert element at rear
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Queue<T>::enqueue(T no)
{
    Queuenode<T>* newn = new Queuenode<T>(no);

    if(first == nullptr && last == nullptr)
    {
        first = last = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
    }
    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     dequeue
//      Description :       Remove element from front
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Queue<T>::dequeue()
{
    if(first == nullptr && last == nullptr)
    {
        cout<<"Queue is empty"<<endl;
        return T();
    }

    Queuenode<T>* temp = first;
    T value = temp->data;

    first = first->next;

    if(first == nullptr)
        last = nullptr;

    delete temp;
    iCount--;

    return value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Display
//      Description :       Display queue elements
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Queue<T>::Display()
{
    Queuenode<T>* temp = first;

    if(first == nullptr)
    {
        cout<<"Queue is empty"<<endl;
        return;
    }

    while(temp != nullptr)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//      Function Name :     Count
//      Description :       Return number of elements
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Queue<T>::Count()
{
    return iCount;
}