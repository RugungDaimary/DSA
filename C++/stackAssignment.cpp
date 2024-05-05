#include<iostream>
#include<stack>
using namespace std;
void reverseStack(stack<int> &s1, stack<int> &s2){
    if(s1.empty()){
        return;
    }
    int x=s1.top();
    s1.pop();
    reverseStack(s1,s2);
    while(!s1.empty()){
        int a=s1.top();
        s1.pop();
        if(s2.empty()){
            s2.push(x);
        }
        s2.push(a);
    }


}

int main(){
    stack<int>s1;
    stack<int>s2;
    s1.push(1);
    s1.push(2);
    s1.push(3);
    s1.push(4);
    s1.push(5);
    while(!s1.empty()){
        cout<<s1.top()<<endl;
        s1.pop();
    }
    reverseStack(s1, s2);
    cout<<endl<<endl;
    while (!s1.empty())
    {
        cout << s1.top() << endl;
        s1.pop();
    }

    return 0;
}