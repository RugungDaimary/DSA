//STL=Standard Template Library

//**SEQUENCE CONTAINER****

//**ARRAY STL***
#include<iostream>
#include<array>
using namespace std;
int main(){
    //int basic[]={1,4,6};
    array<int,4>a={1,9,7,4};
    int size=a.size();
    cout<<size<<"\n";
    for (int i=0; i<size; i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"Element at index 2 : "<<a.at(2)<<endl;//accessing the elements
    cout<<"Empty or Not -->: "<<a.empty()<<endl;
    cout<<"First element: "<<a.front()<<endl;
    cout<<"Last element: "<<a.back()<<endl;

    return 0;
}


//**VECTOR**
//#include<iostream>
//#include <vector>
//using namespace std;
//int main(){
//    vector<int>v;
//
//    cout<<"Capacity -> "<<v.capacity()<<endl;
//    cout<<"Size  -> "<<v.size()<<endl;
//    v.push_back(1);//to insert element in vector
//    cout<<"Capacity  -> "<<v.capacity()<<endl;
//    cout<<"Size  -> "<<v.size()<<endl;
//    v.push_back(2);
//    cout<<"Capacity -> "<<v.capacity()<<endl;
//    v.push_back(3);
//    cout<<"Capacity  -> "<<v.capacity()<<endl;
//    cout<<"Size  -> "<<v.size()<<endl;
//    cout<<"Element at 2nd Index : "<<v.at(2)<<endl;//means like={1,2,3}
//    cout<<"First element: "<<v.front()<<endl;
//    cout<<"Last element: "<<v.back()<<endl;
//
//
//    cout<<"Before pop\n";
//    for (int i:v) {
//        cout<<i<<" ";
//    }
//    cout<<endl;
//    v.pop_back();//used to remove last element
//
//    cout<<"After pop\n";
//    for (int i:v) {
//        cout<<i<<" ";
//    }
//    cout<<endl;
//
//    cout<<"Before clear,size : ";
//    cout<<v.size()<<endl;
//    cout<<"Before clear,capacity : ";
//    cout<<v.capacity()<<endl;
//    v.clear();
//    cout<<"After clear,size : ";
//    cout<<v.size()<<endl;
//    cout<<"After clear,capacity: ";//ie,capacity remains same after clearing the vector
//    cout<<v.capacity()<<endl;
//
//    v.begin();
//
//    //initializing vector
//    vector<int>a(5,1);
//    cout<<"Printing a \n";
//    for (int i:a) {
//        cout<<i<<" ";
//    }
//    cout<<endl;
//
//    vector<int>last(a);//coping 'a' to 'last' vector
//    cout<<"Pringting last\n";
//    for (int i:last) {
//        cout<<i<<" ";
//    }
//
//    return 0;
//}
//

//***DEQUE***
//#include<iostream>
//#include<deque>
//using namespace std;
//int main(){
//    deque<int>d;
//    d.push_back(1);
//    d.push_front(2);
//    for (int i:d) {
//        cout<<i<<" ";
//    }
////    cout<<endl;
////    d.pop_back();
////    for (int i:d) {
////        cout<<i<<" ";
////    }
////    cout<<endl;
////    d.pop_front();//now no elements left
////    for (int i:d) {
////        cout<<i<<" ";//will print space
////    }
//    cout<<endl;
//    cout<<"Element at 0th index "<<d.at(0)<<endl;
//    cout<<"First element "<<d.front()<<endl;
//    cout<<"Last element "<<d.back()<<endl;
//    cout<<"Empty or Not --> "<<d.empty()<<endl;//will print 0-->false
//    cout<<"Before erase "<<d.size()<<endl;
//    d.erase(d.begin(),d.begin()+2);//First 2 elements will be erased
//    //d.erase(d.end(),d.end()+2);//removing last 2 elements
//    cout<<"After erase "<<d.size()<<endl;
//
//
//
//    return 0;
//}
//


//***LIST****
//#include<iostream>
//#include <list>
//using namespace std;
//int main(){
//    list<int>l;
//    l.push_front(1);
//    l.push_back(2);
//
//    for (int i:l) {
//        cout<<i<<" ";
//    }
//    cout<<endl;
////    cout<<"Element at index  0 th "<<l.at(0)<<endl;//Random access is not possible in case of List
//    cout<<"Before erased,Size --> "<<l.size()<<endl;
//    l.erase(l.begin());
//    cout<<"After erased,Size --> "<<l.size()<<endl;
//    //l.erase(l.end()); This operation is not allowed
//    for (int i:l) {
//        cout<<i<<" ";
//    }
//    cout<<endl;
//    l.pop_back();//last element is removed
//    cout<<"Size of list "<<l.size()<<endl;
//
//
//    list<int>n(5,3);
//    for (int i:n) {
//        cout<<i<<" ";
//    }
//    cout<<endl;
//
//    list<int>x(n);//copying n in x
//    for (int i:x) {
//        cout<<i<<" ";
//    }
//    cout<<endl;
//    return 0;
//}

//// CPP program to show the implementation of List
//#include <iostream>
////#include <iterator>
//#include <list>
//using namespace std;
//
//// function for printing the elements in a list
//void showlist(list<int> g)
//{
//    list<int>::iterator it;
//    for (it = g.begin(); it != g.end(); ++it)
//        cout << '\t' << *it;
//    cout << '\n';
//}
//
//// Driver Code
//int main()
//{
//
//    list<int> gqlist1, gqlist2;
//
//    for (int i = 0; i < 10; ++i) {
//        gqlist1.push_back(i * 2);
//        gqlist2.push_front(i * 3);
//    }
//    cout << "\nList 1 (gqlist1) is : ";
//    showlist(gqlist1);
//
//    cout << "\nList 2 (gqlist2) is : ";
//    showlist(gqlist2);
//
//    cout << "\ngqlist1.front() : " << gqlist1.front();
//    cout << "\ngqlist1.back() : " << gqlist1.back();
//
//    cout << "\ngqlist1.pop_front() : ";
//    gqlist1.pop_front();
//    showlist(gqlist1);
//
//    cout << "\ngqlist2.pop_back() : ";
//    gqlist2.pop_back();
//    showlist(gqlist2);
//
//    cout << "\ngqlist1.reverse() : ";
//    gqlist1.reverse();
//    showlist(gqlist1);
//
//    cout << "\ngqlist2.sort(): ";
//    gqlist2.sort();
//    showlist(gqlist2);
//
//    return 0;
//}
//
//

//**CONTAINER ADAPTORS***

//**STACK**-->Last In First Out(LIFO)//like plates in wedding ceremony
//#include<iostream>
//#include <stack>
//using namespace std;
//
//int main(){
//    stack<string>s;
//    s.push("Mr.");
//    s.push("Rugung");
//    s.push("Daimary");//last In means lies on top
//    cout<<"Top element--> "<<s.top()<<endl;
//    s.pop();
//    cout<<"Top element--> "<<s.top()<<endl;
//    cout<<"Size --> "<<s.size()<<endl;
//    cout<<"Empty or not : "<<s.empty()<<endl;//0->true/1->false
//
////    stack<int> stack;
////    stack.push(21);
////    stack.push(22);
////    stack.push(24);
////    stack.push(25);
////
////    stack.pop();
////    stack.pop();
////
////    while (!stack.empty()) {
////        cout << ' ' << stack.top();
////        stack.pop();
////    }
//
//
//
//
//
//    return 0;
//}
//
//

//**QUEUE***
//#include<iostream>
//#include <queue>
//using namespace std;//queue means like a line(FIFO)
//int main(){
//    queue<string>q;
//    q.push("Mr.");//first element
//    q.push("Rugung");
//    q.push("Daimary");
//    cout<<"First Element : "<<q.front()<<endl;
//    cout<<"Size before pop : "<<q.size()<<endl;
//    q.pop();
//    cout<<"SIze after pop : "<<q.size()<<endl;
//
//    cout<<"First Element : "<<q.front()<<endl;
//
//
//
//
//    return 0;
//}
//
//// CPP code to illustrate Queue in
//// Standard Template Library (STL)
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//// Print the queue
//void showq(queue<int> gq)
//{
//    queue<int> g = gq;
//    while (!g.empty()) {
//        cout << '\t' << g.front();
//        g.pop();
//    }
//    cout << '\n';
//}
//
//// Driver Code
//int main()
//{
//    queue<int> gquiz;
//    gquiz.push(10);
//    gquiz.push(20);
//    gquiz.push(30);
//
//    cout << "The queue gquiz is : ";
//    showq(gquiz);
//
//    cout << "\ngquiz.size() : " << gquiz.size();
//    cout << "\ngquiz.front() : " << gquiz.front();
//    cout << "\ngquiz.back() : " << gquiz.back();
//
//    cout << "\ngquiz.pop() : ";
//    gquiz.pop();
//    showq(gquiz);
//
//    return 0;
//}


//// CPP code to illustrate Queue operations in STL
//// Divyansh Mishra --> divyanshmishra101010
//#include <iostream>
//#include <queue>
//
//using namespace std;
//
//// Print the queue
//void print_queue(queue<int> q)
//{
//    queue<int> temp = q;
//    while (!temp.empty()) {
//        cout << temp.front()<<" ";
//        temp.pop();
//    }
//    cout << '\n';
//}
//
//// Driver Code
//int main()
//{
//    queue<int> q1;
//    q1.push(1);
//    q1.push(2);
//    q1.push(3);
//
//    cout << "The first queue is : ";
//    print_queue(q1);
//
//    queue<int> q2;
//    q2.push(4);
//    q2.push(5);
//    q2.push(6);
//
//    cout << "The second queue is : ";
//    print_queue(q2);
//
//
//    q1.swap(q2);
//
//    cout << "After swapping, the first queue is : ";
//    print_queue(q1);
//    cout << "After swapping the second queue is : ";
//    print_queue(q2);
//
//    cout<<q1.empty(); //returns false since q1 is not empty
//
//    return 0;
//}



//****Priority Queue*****
//#include<iostream>
//#include<queue>
//using namespace std;
//int main(){
//    priority_queue<int>maxi;//max heap
//
//    maxi.push(1);
//    maxi.push(3);
//    maxi.push(5);
//    maxi.push(0);
//    cout<<"Size-> "<<maxi.size()<<endl;
//    int n=maxi.size();
//    for (int i=0; i<n; i++) {
//        cout<<maxi.top()<<" ";
//        maxi.pop();
//
//    }
//    cout<<endl;
//
//    priority_queue<int,vector<int>,greater<int> >mini;//min-heap
//    mini.push(1);
//    mini.push(3);
//    mini.push(5);
//    mini.push(0);
//    cout<<"Size-> "<<mini.size()<<endl;
//    int k=mini.size();
//    for (int i=0; i<k; i++) {
//        cout<<mini.top()<<" ";
//        mini.pop();
//
//    }
//    cout<<endl;
//
//    cout<<"Empty or not "<<mini.empty()<<endl;//Not empty
//    return 0;
//}
//

// CPP Program to demonstrate Priority Queue
//#include <iostream>
//#include <queue>
//using namespace std;
//
//void showpq(priority_queue<int> gq)
//{
//    priority_queue<int> g = gq;
//    while (!g.empty()) {
//        cout << '\t' << g.top();
//        g.pop();
//    }
//    cout << '\n';
//}
//
//// Driver Code
//int main()
//{
//    priority_queue<int> gquiz;
//    gquiz.push(10);
//    gquiz.push(30);
//    gquiz.push(20);
//    gquiz.push(5);
//    gquiz.push(1);
//
//    cout << "The priority queue gquiz is : ";
//    showpq(gquiz);
//
//    cout << "\ngquiz.size() : " << gquiz.size();
//    cout << "\ngquiz.top() : " << gquiz.top();
//
//    cout << "\ngquiz.pop() : ";
//    gquiz.pop();
//    showpq(gquiz);
//
//    return 0;
//}
//
//// C++ program to demonstrate min heap for priority queue
//#include <iostream>
//#include <queue>
//using namespace std;
//
//void showpq(
//    priority_queue<int, vector<int>, greater<int> > gq)
//{
//    priority_queue<int, vector<int>, greater<int> > g = gq;
//    while (!g.empty()) {
//        cout << '\t' << g.top();
//        g.pop();
//    }
//    cout << '\n';
//}
//
//// Driver Code
//int main()
//{
//    priority_queue<int, vector<int>, greater<int> > gquiz;
//    gquiz.push(10);
//    gquiz.push(30);
//    gquiz.push(20);
//    gquiz.push(5);
//    gquiz.push(1);
//
//    cout << "The priority queue gquiz is : ";
//    showpq(gquiz);
//
//    cout << "\ngquiz.size() : " << gquiz.size();
//    cout << "\ngquiz.top() : " << gquiz.top();
//
//    cout << "\ngquiz.pop() : ";
//    gquiz.pop();
//    showpq(gquiz);
//
//    return 0;
//}
//
//// CPP Program to demonstrate Priority Queue having min element at top
//#include <iostream>
//#include <queue>
//using namespace std;
//
//int main()
//{
//    int arr[]={1,2,3};
//
//    priority_queue<int> pq1(arr, arr+3);     // creating priority queue using array
//
//    cout<<"Max priority queue: ";
//    while(pq1.empty()==false){
//    cout<<pq1.top()<<" ";
//    pq1.pop();
//    }
//    cout<<endl;
//
//
//    for(int i=0; i<3; i++){
//    arr[i]=-arr[i];             // multiplying each array element by -1
//    }
//
//    priority_queue<int> pq2(arr, arr+3);
//
//    cout<<"Min priority queue: ";
//    while(pq2.empty()==false){
//    cout<<-pq2.top()<<" ";
//    pq2.pop();
//    }
//
//}
//


//****SET***-->Used to store unique element(if 1's is taken five times in an array,but only 1 time it will be stored in SET
//-->can't modify the inserted element,only insertion or deletion is allowed
//-->elements are returned in sorted order
//time complexity is O(logN)
//#include<iostream>
//#include <set>
//using namespace std;
//int main(){
//    set<int>s;
//    s.insert(5);
//    s.insert(5);
//    s.insert(5);
//    s.insert(5);
//    s.insert(5);
//    s.insert(7);
//    s.insert(7);
//    s.insert(1);
//    s.insert(1);
//    s.insert(0);
//    for (auto i:s) {
//        cout<<i<<endl;
//    }
//    cout<<endl;
//    //s.erase(s.begin());
//    set<int>::iterator it=s.begin();
//    it++;
//    s.erase(it);
//    for (auto i:s) {
//        cout<<i<<endl;
//    }
//    cout<<endl;
//    cout<<"9 is present or not -> "<<s.count(9)<<endl;//Check 9 is present or not
//    cout<<endl;
//    set<int>::iterator itr=s.find(0);//'find' fn checks a number,if found returns its iterator(address)(ie.gives reference),with this we can print the number and its onward numbers
//   // cout<<"Value at itr-> "<<itr<<endl;
//    for (auto it=itr; it!=s.end(); it++) {
//        cout<<*it<<" ";
//    }
//    
//    cout<<endl;
//
//    return 0;
//}
//

//***MAP***-->each element has a key & a mapped value.No two mapped values can have the same key values.
//#include<iostream>
//#include <map>
//using namespace std;
//int main(){
//    map<int,string>m;//this is ordered map
//    m[1]="Mr";
//    m[2]="Rugung";
//    m[13]="Daimary";
//    m.insert({5,"Bheem"});//inserting string in map
//    cout<<"Before Erase\n";
//    for (auto i:m) {
//        cout<<i.first<<" : "<<i.second<<endl;//will print in ordered manner
//    }
//    cout<<"Finding 13 --> "<<m.count(13)<<endl;//checking 13 is present or not
//    cout<<"Finding -13 --> "<<m.count(-13)<<endl;//checking -13 is present or not
//    m.erase(13);//erasing value in key 13th
//    cout<<"After erase\n";
//    for (auto i:m) {
//        cout<<i.first<<" : "<<i.second<<endl;//will print in ordered manner
//    }
//
//
//    auto  it=m.find(2);//finding iterator
//    for (auto i=it; i!=m.end(); i++) {
//        cout<<(*i).first<<endl;
//
//    }
//    return 0;
//}
//


//*** ALGORITHM ***
//#include<iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;//binary search-->array must be sorted
//int main(){
//    vector<int>v;
//    v.push_back(1);
//    v.push_back(2);
//    v.push_back(3);
//    v.push_back(6);
//    v.push_back(7);
//    v.push_back(9);
//    cout<<"Finding 3 using Binary Search --> "<<binary_search(v.begin(),v.end(),3)<<endl;;//gives 1 if present otherwise 0 if false
//    cout<<"Lower bound "<<lower_bound(v.begin(), v.end(), 6)-v.begin()<<endl;
//    cout<<"Upper bound "<<upper_bound(v.begin(), v.end(), 6)-v.begin()<<endl;
//    int a=2;
//    int b=5;
//    cout<<"max ->"<<max(a,b)<<endl;
//    cout<<"min ->"<<min(a,b)<<endl;
//    cout<<a<<" "<<b<<endl;
//    swap(a, b);
//    cout<<a<<" "<<b<<endl;
//    string ABCD="abcd";
//    cout<<"Original String-> "<<ABCD<<endl;
//    reverse(ABCD.begin(), ABCD.end());
//    cout<<"Reversed String-> "<<ABCD<<endl;
//    rotate(v.begin(), v.begin()+3, v.end());
//    cout<<"after rotate "<<endl;
//    for (int i:v) {
//        cout<<i<<" ";
//    }
//
//
//    return 0;
//}

