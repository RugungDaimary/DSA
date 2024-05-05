#include<iostream>
#include<vector>
using namespace std;
int main(){
    
    vector<int> *vp=new vector<int>();//dynamically
    vector<int> v;//statically
    // cout<<v.capacity()<<endl;
    cout << "Size of Vector : " << v.size() << endl;
    v.push_back(19);
    v.push_back(9);
    v.push_back(39);

    //don't use [] this for inserting elements
    // v[3]=125;    
    // v[4]=120;         li
    v.push_back(7);  
    v.push_back(10);     
    v[1]=50;
    //for inserting elements using loop
    for (int i = 0; i < 20; i++)
    {
        v.push_back(i );
    }
    cout<<v.size()<<endl;
    
    // cout<<v[0]<<endl;
    // cout<<v[1]<<endl;
    // cout<<v[2]<<endl;
    // cout<<v[3]<<endl;
    // cout<<v[4]<<endl;
    // cout<<v[5]<<endl;
    // cout<<v[6]<<endl;
    // cout<<v[7]<<endl;
    // cout<<v.at(7)<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v.at(i)<<endl;
    }
    
    cout << "Size of Vector : " << v.size() << endl;
    //for deleting last element from vector
    v.pop_back();
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << endl;
    }

    return 0;
}