#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
//Finding the position in set of an element;
int position(set<int>&st,int element){
    cout<<"Hii\n";
    auto it = lower_bound(st.begin(), st.end(), element);
    if (it != st.end() && *it == element)
    {
        int pos=distance(st.begin(), it);//this itself takes O(n) time for calculating distance,we can use PBDS
        return pos;
    }
    else
    {
       return -1;
    }
}

int main()
{
    // cout<<"Hii\n";
   set<int>st={1,3,6,9};
   int element = 9;

   cout << position(st, element) << endl;
   st.erase(10);//is elemet is not present ,it does nothing ,no error

   return 0;
}
