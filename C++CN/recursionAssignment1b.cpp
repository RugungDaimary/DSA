//REPLACE PI
// #include <iostream>
// #include <string>
// using namespace std;
// string replacePi(const string &str, int index = 0)
// {
//     // Base case: if the string is empty or we have reached the end
//     // of the string, return an empty string.
//     if (index >= str.length())
//     {
//         return "";
//     }

//     if (str[index] == 'p' && index + 1 < str.length() && str[index + 1] == 'i')
//     {
//         return "3.14" + replacePi(str, index + 2);
//     }
//     else
//     {
//         return str[index] + replacePi(str, index + 1);
//     }
// }

// int main()
// {
//     string str;
//     cout << "Enter a string: ";
//     cin >> str;
//     cout << replacePi(str) << endl;

//     return 0;
// }

//OR

// #include <cstring>
// void replacePi(char input[])
// {
//     // Write your code here
//     int l = strlen(input);
//     if (input[0] == 'p' && input[1] == 'i')
//     {
//         for (int j = l; j > 1; j--)
//             input[j + 2] = input[j];
//         input[0] = '3';
//         input[1] = '.';
//         input[2] = '1';
//         input[3] = '4';
//         replacePi(input + 4);
//     }
//     else if (input[1] != '\0')
//         replacePi(input + 1);
//     else
//         return;
// }
// int main(){
//         char input[]={};
//         for(int i=0;i<=input.size();i++){
//             cin>>input[i];
//         }
//         replacePI(s);
//         for(int i=0;i<s.length()-1;i++){
//             cout<<s[i];
//         }


//         // char input[10000];
//         // cin.getline(input, 10000);
//         // replacePi(input);
//         // cout << input << endl;

//         return 0;
// }

//REMOVE x
#include<iostream>
#include <cstring>
using namespace std;
void removeX(char input[])
{
    int l = strlen(input);
    if (input[0] == 'x')
    {
        for (int i = 0; i < l; i++){
            input[i] = input[i + 1];
        }    
        removeX(input);
    }
    else if (input[1] != '\0')
        removeX(input + 1);
    else
        return;
}
int main(){
    char input[100];
    cout<<"Enter string\n";
    cin.getline(input, 100);
    removeX(input);
    cout << input << endl;
   
    return 0;
}




//TOWER of HANOI
// #include<iostream>
// using namespace std;
// int 
// int main(){
    
//     return 0;
// }