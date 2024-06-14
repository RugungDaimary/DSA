// A bitset is an array of bools
// size must be known at compile time
#include <bits/stdc++.h>
#include <bitset>
using namespace std;
// indexing starts from rightmost bit(ie, 0 index);
int main()
{
    // declaring an uninitialized bitset object
    bitset<8> uninitializedBitset; // all bits will be set to 0
    cout << "Uninitialised : " << uninitializedBitset << endl;
    // initialization with decimal number
    bitset<8> decimalBitset(15); // decimal number in binary form.
    cout << "Decimal setBit : " << decimalBitset << endl;
    decimalBitset[7] = 1; // Set the bit value at the given index to 1(set)
    cout << decimalBitset << endl;
    decimalBitset[7] = 0; // Set the bit value at a given index to 0(reset)
    cout << decimalBitset << endl;

    // initialization with binary string
    bitset<8> stringBitset(string("1111"));
    cout << "string setBit : " << stringBitset << endl;

    int i = 0;
    long long ans = 0;
    while (i < 8)
    {
        if (decimalBitset[i] == 1)
        {
            ans += pow(2, i);
        }
        i++;
    }
    cout << ans << endl;

    // Fliping the bit at a given index
    i = 0;
    while (i < 8)
    {
        stringBitset.flip(i);
        i++;
    }
    // After Sliping all bits in stirngBitset
    cout << stringBitset << endl;
    cout << "Counting the no of set bits : ";
    stringBitset[0] = 1;
    cout << stringBitset.count() << endl;
    cout << "Size : " << stringBitset.size() << endl;

    // converting the setBits into stirng
    string sBits = stringBitset.to_string();
    cout << sBits << endl;

    // Use one bit to indicate the sign of the number
    // (0 for positive, 1 for negative),
    decimalBitset.to_ullong();
    cout << decimalBitset.to_ullong() << endl;

    // unsigned int unsignedInt = 1e9;
    // cout << unsignedInt << endl;

    // Now dealing with Bitwise Operators

    bitset<8> bitSet1(7);
    bitset<8> bitSet2(8);
    cout << "BitSet1: " << bitSet1 << endl;
    cout << "BitSet2: " << bitSet2 << endl;
    cout << bitSet1[1] << endl;
    cout << bitSet1[4] << endl;

    // AND operation
    //  bitSet1&=bitSet2;
    //  cout<<bitSet1<<endl;

    // OR operation
    //  bitSet1|=bitSet2;
    //  cout<<bitSet1<<endl;

    // XOR operation
    //  bitSet1^=bitSet2;
    //  cout << bitSet1 << endl;

    // RightShift(since the window size is fixed the bit shifted will be trancated)

    // bitSet1 >>= 3;//3 times right shift
    // cout << bitSet1 << endl;

    // LeftShift
    bitSet1 <<= 3;
    cout << bitSet1 << endl;

    return 0;
}