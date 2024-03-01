#include<iostream>
using namespace std;

/* Bad Practice-> gives warning
int& func(int n){
    int num=n;
    int& ans=num;
    return ans;

}
*/
void update2(int& n)

{ // pass by reference
    n++;
}
void update1(int n){//pass by value
    n++;

}
int main(){
   /*
    cout<<endl;
    cout<<"Reference Vriable\n";
    int i=5;
    int &j=i;//here j is reference variable//A variable having different different names
    cout << i << " " << j << endl;
    j++;
    cout << i << " " << j << endl;
    */

   int n=5;
   cout<<"Before "<<n<<endl;
   update2(n);

   cout<<"After "<<n<<endl;
   func(n);


    return 0;
}
