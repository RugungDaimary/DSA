// unordered HashMaps
// #include<iostream>
// #include<unordered_HashMap>
// #include<string>
// using namespace std;
// int main(){
//     unordered_HashMap<string,int>myHashMap;
//     //for insertion
//      myHashMap.insert(make_pair("abc",1));
//      pair<string,int>p("xyz",6);
//      myHashMap.insert(p);
//      myHashMap["pqr"]=5;
//      //findig or accessing
//      cout<<myHashMap["abc"]<<endl;
//      cout<<myHashMap.at("abc")<<endl;

//      //size function
//      cout<<"Size -> "<<myHashMap.size()<<endl;
//      //erase function
//      myHashMap.erase("pqr");
//      cout << "Size -> " << myHashMap.size() << endl;

//      return 0;
// }





//iterator
/*
#include<iostream>
#include<unordered_HashMap>
#include<string>
#include<vector>
using namespace std;
int main(){
    unordered_HashMap<int,string>myHashMap;
    myHashMap[1]="a";
    myHashMap[2]="b";
    myHashMap[3]="c";
    myHashMap[4]="d";
    myHashMap[5]="e";
    myHashMap[6]="f";
    cout<<"No order is followed in printing here \n";
    unordered_HashMap<int,string>:: iterator it=myHashMap.begin();
    while (it!=myHashMap.end())
    {
        cout<<"Key : "<<it->first<<" "<<"Value : "<<it->second<<endl;
        it++;
    }
    //find
    cout<<endl;
    unordered_HashMap<int,string>:: iterator it1=myHashMap.find(4);
    myHashMap.erase(it1);
    myHashMap.erase(it1,it1+4);
    

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

const int mod=1e9+7;
template <typename V>
class Node
{
public:
    string key;
    V value;
    Node *next;
    Node(string key, V value)
    {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
    ~Node()
    {
        delete next;
    }
};

template <typename V>
class HashMap
{
    vector<Node<V> *> buckets;
    int count;
    int numBuckets;

public:
    HashMap()
    {
        count = 0;
        numBuckets = 5;
        buckets.resize(numBuckets, NULL);
    }

    ~HashMap()
    {
        for (int i = 0; i < numBuckets; i++)
        {
            delete buckets[i]; // Deleting each linked list first
        }
    }

    int size()
    {
        return count;
    }

    int getBucketIndex(string key)
    {
        int hashCode = 0;
        int currentCoeff = 1;
        for (int i = key.length() - 1; i >= 0; i--)
        {
            hashCode += (key[i]-'0') * currentCoeff;
            hashCode = hashCode % numBuckets;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % mod;
        }
        return hashCode % numBuckets;
    }

    double getLoadFactor()
    {
        return (1.0 * count) / numBuckets;
    }

    void insert(string key, V value)
    {
        int bucketIndex = getBucketIndex(key);
        Node<V> *head = buckets[bucketIndex];
        while (head != NULL)
        { // Searching for same key
            if (head->key == key)
            {
                head->value = value;
                return;
            }
            head = head->next;
        }

        // Key not found, create a new node
        head = buckets[bucketIndex];                   // Resetting head
        Node<V> *node = new Node<V>(key, value); // Creating a new node
        node->next = head;
        buckets[bucketIndex] = node;
        count++;

        // Rehashing if load factor exceeds threshold
        if (getLoadFactor() > 0.7)
        {
            rehash();
        }
    }

    V getValue(string key)
    {
        int bucketIndex = getBucketIndex(key);
        Node<V> *head = buckets[bucketIndex];
        while (head != NULL)
        {
            if (head->key == key)
            {
                return head->value;
            }
            head = head->next;
        }
        return 0; // Return 0 if key is not found
    }

    V remove(string key)
    {
        int bucketIndex = getBucketIndex(key);
        Node<V> *head = buckets[bucketIndex];
        Node<V> *prev = NULL;
        while (head != NULL)
        {
            if (head->key == key)
            {
                if (prev == NULL)
                {
                    buckets[bucketIndex] = head->next;
                }
                else
                {
                    prev->next = head->next;
                }
                V value = head->value;
                head->next = NULL;
                delete head;
                count--;
                return value;
            }
            prev = head;
            head = head->next;
        }
        return 0; // Return 0 if key is not found
    }

    void rehash()
    {
        vector<Node<V> *> temp = buckets;
        numBuckets *= 2;
        buckets.clear();
        buckets.resize(numBuckets, NULL);
        count = 0;

        for (int i = 0; i < temp.size(); i++)
        {
            Node<V> *head = temp[i];
            while (head != NULL)
            {
                string key = head->key;
                V value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        // Deleting the old bucket list
        for (int i = 0; i < temp.size(); i++)
        {
            Node<V> *head = temp[i];
            delete head;
        }
    }
};

int main()
{
    HashMap<int> HashMap;
    // Initially bucket size is 5;
    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        int value = 1 + i;
        HashMap.insert(key, value);
        cout << HashMap.getLoadFactor() << endl;
    }

    cout << endl;
    cout << "Size : " << HashMap.size() << endl;
    cout << endl;

    HashMap.remove("abc2");
    HashMap.remove("abc7");

    for (int i = 0; i < 10; i++)
    {
        char c = '0' + i;
        string key = "abc";
        key = key + c;
        cout << key << " : " << HashMap.getValue(key) << endl;
    }

    cout << endl;
    cout << "Size : " << HashMap.size() << endl;

    return 0;
}
