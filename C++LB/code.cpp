#include <iostream>
#include <vector>
using namespace std;
int f1(vector<int> &A, int p1, int p2, int e)
{
    if (p1 == p2)
    {
        return A[p1];
    }
    else
    {
        int p = (p1 + p2) / 2;
        int a = f1(A, p1, p, e);
        int b = f1(A, p + 1, p2, e);
        if (a > b && e < 0)
        {
            return (a > b) ? a : b;
        }
        else
        {
            return (a < b) ? a : b;
        }
    }
}

int main()
{
    vector<int> A = {1, 1, 2, 4, 4, 12};
    int e; // Assume e is provided as input
    cout << f1(A, 0, A.size() - 1, e) << endl;
    return 0;
}