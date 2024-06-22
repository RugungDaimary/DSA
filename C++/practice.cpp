#include <bits/stdc++.h>
using namespace std;
int calculatePower(int n)
{
    int i = 0;
    while ((1 << i) <= n)
    {
        i++;
    }
    return i - 1;
}
int countSetBits(int n)
{
    if (n == 0)
        return 0;

    int power = calculatePower(n);
    int bitsTill2Pow = (1 << (power - 1)) * power; // counting set bits upto 2 power(pow)
    int leftMostbits = (n - (1 << power) + 1);
    return bitsTill2Pow + leftMostbits + countSetBits(n - (1 << power));
}
int main()
{
    cout << countSetBits(6) << endl;

    return 0;
}
