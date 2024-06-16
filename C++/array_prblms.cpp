#include <iostream>
using namespace std;
void swapAlternate(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int print(int arr[], int n)
{
    int ans = 0;

    for (int i = 0; i < 5; i++)
    {
        ans = ans ^ arr[i];
    }
    cout << ans << endl;
    return ans;
}

int X(int arr[], int N)
{
    int ans = 0;
    // XORing all array elements
    for (int i = 0; i < N; i++)
    {
        ans = ans ^ arr[i];
    }
    // XORing [1,N-1] elements `
    for (int i = 1; i < N; i++)
    {
        ans = ans ^ i;
    }
    return ans;
}


void sortOne(int arr[], int n)
{

    int left = 0, right = n - 1;

    while (left < right)
    {

        while (arr[left] == 0 && left < right)
        {
            left++;
        }

        while (arr[right] == 1 && left < right)
        {
            right--;
        }

        // agar yha pohoch gye ho, iska matlab
        // arr[left]==1 and arr[right]==0
        if (left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
}

int main()
{

    int arr[8] = {1, 1, 0, 0, 0, 0, 1, 0};

    sortOne(arr, 8);

    return 0;
}
