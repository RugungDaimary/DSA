//unordered maps
// #include<iostream>
// #include<unordered_map>
// #include<string>
// using namespace std;
// int main(){
//     unordered_map<string,int>myMap;
//     //for insertion
//      myMap.insert(make_pair("abc",1));
//      pair<string,int>p("xyz",6);
//      myMap.insert(p);
//      myMap["pqr"]=5;
//      //findig or accessing
//      cout<<myMap["abc"]<<endl;
//      cout<<myMap.at("abc")<<endl;

//      //size function
//      cout<<"Size -> "<<myMap.size()<<endl;
//      //erase function
//      myMap.erase("pqr");
//      cout << "Size -> " << myMap.size() << endl;

//      return 0;
// }





//iterator
/*
#include<iostream>
#include<unordered_map>
#include<string>
#include<vector>
using namespace std;
int main(){
    unordered_map<int,string>myMap;
    myMap[1]="a";
    myMap[2]="b";
    myMap[3]="c";
    myMap[4]="d";
    myMap[5]="e";
    myMap[6]="f";
    cout<<"No order is followed in printing here \n";
    unordered_map<int,string>:: iterator it=myMap.begin();
    while (it!=myMap.end())
    {
        cout<<"Key : "<<it->first<<" "<<"Value : "<<it->second<<endl;
        it++;
    }
    //find
    cout<<endl;
    unordered_map<int,string>:: iterator it1=myMap.find(4);
    myMap.erase(it1);
    myMap.erase(it1,it1+4);
    

    cout<<endl<<"Iterator in vector\n";
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    vector<int>::iterator i=v.begin();
    while (i!= v.end())
    {
        cout<<*i<<endl;
        i++;
    }
    
    
    
    return 0;
}
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<typename V>
class MapNode{
    public:
    string key;
    V value;
    MapNode* next;
    MapNode(string key,V value){
        this->key=key;
        this->value=value;
        this->next=NULL;
    }
    ~MapNode(){
        delete next;
    }
};
template<typename V>
class MAP{
    MapNode<V>** buckets;
    int count;
    int numBuckets;
    public:
    MAP(){
        count=0;
        numBuckets=5;
        buckets=new MapNode<V>*[numBuckets];
        for(int i=0;i<numBuckets;i++){
            buckets[i]=NULL;
        }
    }
    ~MAP(){
        for(int i=0;i<numBuckets;i++){
            delete buckets[i];//deleting each linked list first
        }
        delete []buckets;//deleting entire array
    }

    int size(){
        return count;
    }
    private:
    int getBucketIndex(string key){
        int hashCode=0;
        int currentCoeff=1;
        for (int i = key.length()-1; i >=0; i--)
        {
           hashCode+=key[i]*currentCoeff;
           hashCode=hashCode%numBuckets;
           currentCoeff*=37;
           currentCoeff=currentCoeff%numBuckets;
        }
        return hashCode%numBuckets;
    }
    public:
    double getLoadFactor(){
        return (1.0*count)/numBuckets;
    }
    void insert(string key,V value){
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=buckets[bucketIndex];
        while (head!=NULL)//searching for same key 
        {
            if(head->key==key){
                head->value=value;
                return;
            }
            head=head->next;
        }
        //means ,same key is not found
        head=buckets[bucketIndex];//resetting head
        MapNode<V>* node=new MapNode<V>(key,value);//creating a new node
        node->next=head;
        buckets[bucketIndex]=node;
        count++;
        // REHASHING CONCEPT
        double loadFactor = (1.0) * count / numBuckets;
        if (loadFactor > 0.7)
        {
            rehash();
        }
    }
    V getValue(string key){
        int bucketIndex = getBucketIndex(key);
        MapNode<V> *head = buckets[bucketIndex];
        while (head!=NULL)
        {   
            if(head->key==key){
                return head->value;
            }
            head=head->next;
        }
        return 0;//if key is not found//default  
    }
    V remove(string key){
        int bucketIndex=getBucketIndex(key);
        MapNode<V>* head=buckets[bucketIndex];
        MapNode<V>* prev=NULL;
        while (head!=NULL)
        {
            if(head->key==key){
                if(prev==NULL){
                    buckets[bucketIndex]=head->next;

                }else{
                    prev->next=head->next;

                }
                V value=head->value;
                head->next=NULL;
                delete head;
                count--;
                return value;
            }
            prev=head;
            head=head->next;
            
        }
        return 0;//if not found
    }

    //REHASHING CONCEPT
    private:
    void rehash(){
        MapNode<V>* *temp=buckets;
        buckets=new MapNode<V>*[2*numBuckets];
        for (int i = 0; i < 2*numBuckets; i++)
        {
            buckets[i]=NULL;
        }
        int oldBucketCount=numBuckets;
        numBuckets*=2;//resetting all values
        count=0;
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V>* head=temp[i];
            while (head!=NULL)
            {
                string key=head->key;
                V value=head->value;
                insert(key,value);
                head=head->next;
            }
        }
        //for deleting the old bucket
        for (int i = 0; i < oldBucketCount; i++)
        {
            MapNode<V> * head=temp[i];
            delete head;
        }
        delete [] temp;   
    }
    
};
int main(){
    MAP<int> map;
    //initially bucket size is 5;
    for (int i = 0; i < 10; i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=1+i;
        map.insert(key,value);
        cout<<map.getLoadFactor()<<endl;

    }
    cout<<endl;
    cout << "Size : " << map.size() << endl;
    cout<<endl;
    map.remove("abc2");//default value is inserted after removed
    map.remove("abc7");
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        
        cout << key<<" : "<<map.getValue(key)<< endl;
    }
    cout<<endl;
    cout<<"Size : "<<map.size()<<endl;

    return 0;
}