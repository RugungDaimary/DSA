#include<bits/stdc++.h>
using namespace std;
void reachHome(int scr,int dest){//scr->source;dest->destination
    //base case
    cout<<"Source->"<<scr<<" "<<"Destination->"<<dest<<endl;
    if (scr==dest)
    {
        cout<<"Reached Home !\n";
        return;
    }
    //processing->ek step aage badh jao
    scr++;
    //recursive call
    reachHome(scr,dest);
    

}

int reachHome1(int s, int e)
{
    // base case
    cout << s << " " << e << " " << endl;
    if (s == e)
    {
        cout << "Reached Home in ";
        return 0;
    }
    // recursive call
    int smallSteps = reachHome1(s + 1, e);
    return smallSteps + 1;
}
// Qn)Say Digits
void sayDigits(string arr[], int n)
{

    // base case
    if (n == 0) // if number becomes zero after division
    {
        return;
    }
    // processing
    int digit = n % 10;
    n = n / 10;

    // recursive call
    sayDigits(arr, n);
    cout << arr[digit] << " ";
}
int main(){
    // int dest=10;
    // int scr=1;
    // cout<<endl;
    // reachHome(scr,dest);

    // int s = 1;
    // int e = 10;
    // cout << reachHome(s, e) << " steps" << endl;

    int n;
    cout << "Enter n\n";
    cin >> n;
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    cout << endl;
    sayDigits(arr, n);
    cout << endl;

    return 0;
}

