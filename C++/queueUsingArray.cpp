// #include<iostream>
// using namespace std;
// template<typename T>
// class Queue{
//     T* data;
//     int nextIndex;
//     int firstIndex;
//     int size;
//     int capacity;//hold the size of array ,input taken by user
//     public:
//     Queue(int s){
//         data=new T[s];
//         nextIndex=0;
//         firstIndex=-1;
//         size=0;
//         capacity=s;//capacity is created here to use the size of array globally
//     }
//     int getSize(){
//         return size;
//     }
//     bool isEmpty(){
//         return size==0;
//     }
//     //insertion 
//     void enqueue(T element){
//         if(size==capacity){
//             cout<<"Queue is Full\n";
//             return;
//         }
//         data[nextIndex]=element;
//         nextIndex=(nextIndex+1)%capacity;
//         if (firstIndex==-1)
//         {
//             firstIndex=0;
//         }
//         size++;
        

//     }
//     T front(){
//         // if (isEmpty())
//         // {
//         //     cout<<"Queue is Empty\n";
//         // }
//         if (firstIndex==-1)
//         {
//             cout<<"Queue is Empty\n";
//             return 0;
//         }
//         return data[firstIndex];
//     }
//     T dequeue(){
//         if (isEmpty())
//         {
//             cout<<"Queue is Empty\n";
//         }
//         T ans=data[firstIndex];
//         firstIndex=(firstIndex+1)%capacity;
//         size--;
//         if (size==0)
//         {
//             firstIndex=-1;
//             nextIndex=0;
//         }
        
//         return ans;
//     }


// };
// int main(){
//     Queue<int> q(5);
//     q.enqueue(10);
//     q.enqueue(20);
//     q.enqueue(30);
//     q.enqueue(40);
//     cout<<q.getSize()<<endl;
//     cout<<q.front()<<endl;
//     cout<<q.isEmpty()<<endl;
//     q.enqueue(50);
//     q.enqueue(60);
//     cout<<q.dequeue()<<endl;
//     cout<<q.front()<<endl;
//     cout<<q.getSize()<<endl;
   


    
//     return 0;
// }

// Queue using Dynamic Array,to improve the limitation
// of size(max is equal to capacity)
 #include<iostream>
 using namespace std;
 template<typename T>
 class Queue{
     T* data;
     int nextIndex;
     int firstIndex;
     int size;
     int capacity;//hold the size of array ,input taken by user
     public:
     Queue(int s){
         data=new T[s];
         nextIndex=0;
         firstIndex=-1;
         size=0;
         capacity=s;//capacity is created here to use the size of array globally
     }
     int getSize(){
         return size;
     }
     bool isEmpty(){
         return size==0;
     }
     //insertion
     void enqueue(T element){
         if(size==capacity){
             T* newData=new T[2* capacity];
             int j=0;
             for (int i = firstIndex; i <capacity ; i++)
             {
                newData[j]=data[i];
                j++;
             }
             for (int i = 0; i < firstIndex; i++)
             {
                newData[j]=data[i];
                j++;
             }
             delete [] data;//delete first the data array then data sbould point to newData
             data=newData;
             firstIndex=0;
             nextIndex=capacity;
             capacity *=2;
             
             
         }
         data[nextIndex]=element;
         nextIndex=(nextIndex+1)%capacity;
         if (firstIndex==-1)
         {
             firstIndex=0;
         }
         size++;

    }
    T front(){
        // if (isEmpty())
        // {
        //     cout<<"Queue is Empty\n";
        // }
        if (firstIndex==-1)
        {
            cout<<"Queue is Empty\n";
            return 0;
        }
        return data[firstIndex];
    }
    T dequeue(){
        if (isEmpty())
        {
            cout<<"Queue is Empty\n";
        }
        T ans=data[firstIndex];
        firstIndex=(firstIndex+1)%capacity;
        size--;
        if (size==0)
        {
            firstIndex=-1;
            nextIndex=0;
        }

        return ans;
    }

};
int main(){
    Queue<int> q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    cout<<q.getSize()<<endl;
   q.enqueue(60);
   cout << q.getSize() << endl;

   // cout<<q.getSize()<<endl;
   // cout<<q.front()<<endl;
   // cout<<q.isEmpty()<<endl;
   // q.enqueue(50);
   // q.enqueue(60);
   // cout<<q.dequeue()<<endl;
   // cout<<q.front()<<endl;
   // cout<<q.getSize()<<endl;
}
