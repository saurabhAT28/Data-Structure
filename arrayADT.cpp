#include<iostream>
using namespace std;

class ArrayADT{
    int capacity;
    int lastIndex;
    int *ptr;
    public:
        // Constructor----->
        ArrayADT()
        {
            capacity=0;
            lastIndex=-1;
            ptr=NULL;
        }

        void createArray(int capacity);
        int getItem(int index);
        void setItem(int index,int value);
        void editItem(int index,int value);
        int countItems();
        void removeItem(int index);
        int searchItem(int value);
        void sortArray();
        void printArray();
        // "<<" overloading----->
        friend ostream & operator<<(ostream&,ArrayADT);

        // Destructor------>
        ~ArrayADT()
        {
            delete []ptr;
        }
        // Copy constructor------->
        ArrayADT(ArrayADT &list)
        {
            capacity=list.capacity;
            lastIndex=list.lastIndex;
            ptr=new int[capacity];
            for(int i=0;i<list.lastIndex;i++)
                ptr[i]=list.ptr[i];
        }

};

ostream& operator <<(ostream &dout,ArrayADT l)
{
    if(l.lastIndex==-1)
        cout<<"List is empty"<<endl;
    for(int i=0;l.countItems();i++)
        cout<<l.getItem(i)<<" ";
    return(dout);
}

void ArrayADT :: createArray(int capacity)
{
    this->capacity=capacity;
    lastIndex=-1;
    // Array
    ptr=new int[capacity];
}

int ArrayADT :: getItem(int index)
{
    if(lastIndex==-1){
        cout<<"List is empty"<<endl;
        return(-1);
    }
    if(index>lastIndex || index<0){
        cout<<"Invalid index"<<endl;
        return (-1);
    }
    return(ptr[index]);
}

void ArrayADT :: setItem(int index,int value)
{   
    int i;
    if(lastIndex==capacity-1)
        cout<<"Overflow"<<endl;
    else if(index>capacity-1 || index<0)
        cout<<"Invalid Index"<<endl;
    else if(index>lastIndex+1)
        cout<<"Invalid Index"<<endl;
    else if(index<=lastIndex){
        lastIndex++;
        i=lastIndex;
        while(i!=index){
            ptr[i]=ptr[i-1];
            i--;
        }
        ptr[index]=value;
    }
    else if(index==lastIndex+1){
        lastIndex++;
        ptr[index]=value;
    }
}

void ArrayADT :: editItem(int index,int value)
{
    if(index<0 || index>lastIndex)
        cout<<"Invalid Index"<<endl;
    else
        ptr[index]=value;
}

int ArrayADT :: countItems()
{
    return (lastIndex+1);
}

void ArrayADT :: removeItem(int index)
{   
    int i;
    if(index<0 || index>lastIndex)
        cout<<"Invalid index or underflow"<<endl;
    else if(index<lastIndex){
        i=index;
        while(i!=lastIndex){
            ptr[i]=ptr[i+1];
            i++;
        }
        lastIndex--;
    }
    else if(index==lastIndex)
        lastIndex--;
}

int ArrayADT :: searchItem(int value)
{
    if(lastIndex==-1){
        cout<<"List is empty"<<endl;
        return(-1);
    }
    int i;
    for(i=0;i<=lastIndex;i++){
        if(ptr[i]==value)
            return (i);
    }
    return(-1);
}

void ArrayADT :: sortArray()
{
    int r,i,t;
    // r ----> rounds
    for(r=1;r<countItems();r++){
        for(i=0;i<countItems()-r;i++)
            if(ptr[i]>ptr[i+1]){
                t=ptr[i];
                ptr[i]=ptr[i+1];
                ptr[i+1]=t;
            }
    }
}

void ArrayADT :: printArray()
{
    for(int i=0;i<lastIndex+1;i++)
        cout<<ptr[i]<<" ";
    cout<<endl;
}


int main(){
    ArrayADT a1;
    int l;
    a1.createArray(5);
    
    a1.setItem(0,10);
    a1.setItem(1,20);
    a1.setItem(2,30);
    a1.setItem(3,40);

    a1.printArray();

    cout << a1.getItem(2)<<endl;;

    a1.editItem(2,35);
    a1.printArray();

    cout<<a1.countItems()<<endl;

    a1.removeItem(2);
    a1.printArray();
    cout<<a1.countItems()<<endl;

    cout<<a1.searchItem(29)<<endl;
    cout<<a1.searchItem(40)<<endl;

    a1.setItem(3,30);
    a1.printArray();
    a1.sortArray();
    a1.printArray();

    return 0;
}