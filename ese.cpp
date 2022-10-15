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
        ArrayADT(ArrayADT &b,ArrayADT &c)
        {
            capacity=0;
            lastIndex=-1;
            ptr=NULL;
        }

        void createArray(int capacity);
        int getItem(int index);
        void setItem(int index,int value);
        void editItem(int index,int value);
        void merge(ArrayADT b,ArrayADT c);
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
            capacity=list.capacity+capacity;
            // lastIndex=list.lastIndex;
            lastIndex=-1;
            ptr=new int[capacity];
            // for(int i=0;i<list.lastIndex;i++)
            //     ptr[i]=list.ptr[i];
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

void ArrayADT :: merge(ArrayADT b,ArrayADT c){
    int i=0,j=0,k=0;
    int n1=countItems();
    int n2=b.countItems();

    // c.createArray(n1+n2);
    cout<<"A"<<endl;
    while(i<n1 && j<n2){
        int x=getItem(i);
        int y=b.getItem(j);
        if(x<y){
            c.setItem(k,x);
            k++;
            i++;
        }
        else{
            c.setItem(k,y);
            k++;
            y++;
        }
    }
    while(i<n1){
        c.setItem(k,getItem(i));
        i++;
    }
    while(j<n2){
        c.setItem(k,b.getItem(j));
        j++;
    }
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
    ArrayADT a,b;
    a.createArray(6);

    a.setItem(0,11);
    a.setItem(1,15);
    a.setItem(2,71);
    a.setItem(3,10);
    a.setItem(4,11);
    a.setItem(5,1);

    a.printArray();
    a.sortArray();
    a.printArray();
    cout<<"B****"<<endl;
    b.createArray(5);
    b.setItem(0,91);
    b.setItem(1,5);
    b.setItem(2,71);
    b.setItem(3,10);
    b.setItem(4,21);

    b.printArray();
    b.sortArray();
    b.printArray();
    cout<<"******"<<endl;
    ArrayADT c;
    // cout<<"******"<<endl;
    int n1=a.countItems();
    int n2=b.countItems();
    // cout<<"******"<<endl;
    c.createArray(n1+n2);
    cout<<"******"<<endl;
    a.merge(b);
    cout<<"******"<<endl;
    // c.printArray();
    return 0;
}