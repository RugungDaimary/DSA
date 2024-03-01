//////strings-->1D char array
//#include<iostream>
//using namespace std;
//int length(char arr[ ]){//no need to pass size of string array
//    int count=1;
//    for (int i=1; arr[i]!='\0'; i++) {
//        count++;
//    }
//    return count;
//
//
//}
//int main(){
//
////    char name[200];
////    cin>>name;
////    cout<<name<<endl;
//
//    //finding length of string
//    char name[200];
//    cin>>name;
//    int ans=length(name);
//    cout<<ans<<endl;
//
//
//    return 0;
//}


//Qn) reverse a string
//#include<iostream>
//using namespace std;
//int getLength(char name[],int n){
//    int count=1;
//    for (int i=1; name[i]!='\0'; i++) {
//         count++;
//    }
//         return count;
//}
//void reverse(char name[ ],int n){
//    int s=0;
//    int e=n-1;
//    while (s<e) {
//        swap(name[s], name[e]);//yato is line pe 'swap(name[s++],name[e--])' karo
//        s++;
//        e--;
//    }
//
//}
//
//int main(){
//    char name[100];
//    cout<<"Enter your name\n";
//    cin>>name;
//    cout<<"Your name is "<<name<<endl;
//    int len=getLength(name,100);
//    cout<<"Lenght is "<<len<<endl;
//    reverse(name, len);//len must be equal to the length of string,otherwise return a wrong answer
//    cout<<name<<endl;
//
//
//    return 0;
//}



//Qn)Checking a string a palindrom or not//
//if the string is not case sensitive

//#include<iostream>
//using namespace std;
//char tolowerCase(char ch){
//    if (ch>='a'&& ch<='z') {
//        return ch;
//    }
//    else{
//        char temp=ch-'A'+'a';
//        return temp;
//    }
//}
//bool checkPalindrom(char ch[],int n){
//    int s=0;
//    int e=n-1;
//    while (s<=e) {
//        if (tolowerCase(ch[s])!=tolowerCase(ch[e])) {
//            return 0;
//        }
//        else{
//            s++;
//            e--;
//
//
//        }
//
//    }
//    return 1;
//
//}
//int main(){
//    char ch[50];
//    cout<<"Enter your name\n";
//    cin>>ch;
////    cout<<"Palindrom or Not: "<<checkPalindrom(ch, 4)<<endl;;
//    int result=checkPalindrom(ch, 9);
//    if (result==1) {
//        cout<<"Palindrom\n";
//    }
//    else{
//        cout<<"Not a Palindrom\n";
//    }
//    cout<<"character is : "<<tolowerCase('B')<<endl;//Uppercase is converted into lowercase character
//    cout<<"character is : "<<tolowerCase('c')<<endl;
//    return 0;
//}


//#include<iostream>
//using namespace std;
//int main(){
//    char ch[50]={'a','b','\0','c','d','\0'};
//    string str={'a','b','\0','c','d','\0'};
//    for (int i=0; i<7; i++) {
//        cout<<ch[i];
//    }
//    cout<<endl;
//    for (int i=0; i<7; i++) {
//        cout<<str[i];
//
//    }
//    cout<<endl;
//    cout<<str;
//    cout<<endl;
//    return 0;
//}
//


//Qn)Checking a string a palindrom or not//
//if the string is not case sensitive ,consider only numeric and alphabets ignore special symbols and whitespace


//#include <iostream>
//#include <string>
//using namespace std;
//bool valid(char ch)
//{
//    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
//        return true;
//    else
//        return false;
//}
//char tolower(char ch)
//{
//    if (ch >= 'a' && ch <= 'z')
//        return ch;
//    else
//    {
//        char temp = ch - 'A' + 'a';
//        return temp;
//    }
//}
//bool checkPalindrome(string S)
//{
//    int s = 0;
//    long /*int*/e = S.length() - 1;
//    while (s <= e)
//    {
//        if (!valid(S[s]))
//            s++;
//        else if (!valid(S[e]))
//            e--;
//        else if (tolower(S[s]) != tolower(S[e]))
//            return false;
//        else//if equals then
//        {
//            s++; e--;
//        }
//    }
//    return true;
//}
//int main()
//{
//    string name;
//    cout << "Enter any string to check whether it is palindrome or not\n";
//    //cin>>name;
//    getline(cin, name);         //*****use this syntax if user input string contains whitespace
//    cout << "Checking palindrome or not : " << checkPalindrome(name)<<endl;;
//    return 0;
//    //getch();
//}
//
//
//Qn)A phrase is a palindrom, if after converting all uppercase letter into lowercase letters and removing all non-alphanumeric characters,it reads the same forward and backward
//#include<string>
//#include<iostream>
////#include<vector>
//using namespace std;
//class Solution {
//private:
//    bool valid(char ch) {
//        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
//            return 1;
//        }
//
//        return 0;
//    }
//
//    char toLowerCase(char ch) {
//    if( (ch >='a' && ch <='z') || (ch >='0' && ch <='9') )
//        return ch;
//    else{
//        char temp = ch - 'A' + 'a';
//        return temp;
//    }
//    }
//    bool checkPalindrome(string a) {
//    int s = 0;
//    long e = a.length()-1;
//
//    while(s<=e) {
//        if(a[s] != a[e])
//        {
//            return 0;
//        }
//        else{
//            s++;
//            e--;
//        }
//    }
//    return 1;
//}
//public:
//    bool isPalindrome(string s) {
//
//        //faltu character hatado
//        string temp = "";
//
//        for(int j=0; j<s.length(); j++) {
//            if(valid(s[j])) {
//                temp.push_back(s[j]);
//            }
//        }
//
//        //lowercase me kardo
//        for(int j=0; j<temp.length(); j++) {
//            temp[j] = toLowerCase(temp[j]);
//        }
//
//        //check palindrome
//        return checkPalindrome(temp);
//
//    }
//};
//
//int main(){
//    return 0;
//}
//


//Qn)Reversing a string

//#include<iostream>
//#include<string>
//using namespace std;
//void reverse(string& str){
//    int s=0;
//    int e=str.length()-1;
//    while (s<e)
//    {
//        swap(str[s],str[e]);
//        s++;
//        e--;
//
//    }
//
//}
//
//
//int main(){
//    string str;
//    getline(cin,str);
//    reverse(str);
//
//    cout<<str<<endl;
//
//    return 0;
//}

//Qn) Gettting maximum occuring character in a string
#include<iostream>
using namespace std;
char getMaxOccCharacter(string s){
    int arr[26]={0};
    //create an array of count of characters
    for (int i=0; i<s.length(); i++) {
        char ch=s[i];
        //lowercase
        int number=0;
        if (ch>='a'&& ch<='z') {
            number=ch-'a';
        }else{
            //uppercase
            number=ch-'A';
        }
        arr[number]++;
    }
    //finding max occ characters
    int maxi=-1,ans=0;
    for (int i=0; i<26; i++) {
        if (maxi<arr[i]) {
            ans=i;
            maxi=arr[i];
        }
    }
    char finalAns='a'+ans;
    return finalAns;
}
int main(){
    string s;
    cin>>s;
    cout<<getMaxOccCharacter(s)<<endl;
    
    return 0;
}

