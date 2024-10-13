#include<bits/stdc++.h>
using namespace std;
//Stack implementation using array
class Stack{
    int nextIndex;
    vector<int>data;
    public:
    Stack(){
        nextIndex=0;
    }
    int getSize(){
        return nextIndex;
    }
    int top(){
        if(!isEmpty())
            return data[nextIndex-1];
        else return -1;

    }
    int pop(){

        if(!isEmpty()){
            nextIndex--;
            return data[nextIndex];
        }else return -1;

    }
    bool isEmpty(){
        return nextIndex==0;
    }
    void push(int element){
        if(nextIndex<data.size()){
            data[nextIndex]=element;
            nextIndex++;
        }else{
            data.push_back(element);
            nextIndex++;
        }
    }

};
//Queue Implementation using vector and LinkedList



//Hashmap Implementation
int main(){
    
    return 0;
}