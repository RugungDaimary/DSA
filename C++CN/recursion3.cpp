// Strings
#include <iostream>
using namespace std;
int main()
{
    // string s;
    // cin>>s;
    // cout<<s<<endl;
    string s1;
    s1 = "rugung";
    cout << s1 << endl;
    // dynamically
    string *newstring = new string;
    *newstring = "Rdaimary";
    cout << newstring << endl;
    cout << *newstring << endl;
    // taking input in string breaks when a space is entered so,we use getline function
    string s2;
    getline(cin, s2);
    cout << s2 << endl;

    string s3 = s1 + s2; // concatinate
    // s2+=s1;
    cout << s3 << endl;
    // cout<<s2<<endl;
    cout << endl;

    cout << s2.size() << endl;

    // making substrings
    string s4=s1.substr(1);//here from that index to last
    cout<<s4<<endl;
    string s5=s1.substr(1,4);//from that index to that length
    cout<<s5<<endl;


    //finding any substring
    cout<<s1.find("pung")<<endl;//returns the index from where it starts

    return 0;
}
