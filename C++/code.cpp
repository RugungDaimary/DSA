// #include <bits/stdc++.h>
// using namespace std;
// // count subarrays containing atleast k zeros
// // 1, 0, 3, 0, 2, 0, 0, 4, 5
// int subArrayCount(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     int count = 0; // subarray count will be stores here
//     int zero = 0;  // to count zeros
//     int left = -1; // first zero index;
//     if (k == 0)
//     { // total no of subarrays
//         return n * (n + 1) / 2;
//     }
//     vector<int> index(n, -1);
//     for (int i = 0; i < n; i++)
//     {
//         if (nums[i] == 0)
//         {
//             left = i;
//             break;
//         }
//     }
//     if (left == -1)
//         return 0; // no zero found
//     int right = left;
//     while (right < n)
//     {
//         if (nums[right] == 0)
//         {
//             zero++;
//         }
//         if (zero == k)
//         {
//             index[right] = left;
//         }
//         else if (zero > k)
//         { // jab zero count ek jada ho jayega
//             left++;
//             zero--;
//             while (nums[left] != 0)
//             {
//                 left++;
//             }
//             index[right] = left;
//         }
//         right++;
//     }



//     for (auto i : index)
//     {
//         if (i != -1)
//         {
//             count += (i + 1);
//         }
//     }
//     return count;
// }

// int main()
// {
//     vector<int> nums = {1, 0, 3, 0, 2, 0, 0, 4, 5};
//     int k = 2;
//     cout<<subArrayCount(nums,k)<<endl;
//     // 4 2 3 1
//     // 4 1 3 2
//     // 6 8 5 3

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;

long findMinGeneration(vector<int> &layers)
{
    int n = layers.size();
    int maxLayer = *max_element(layers.begin(), layers.end());

    int generations = 0;
    while (true)
    {
        int minLayer = *min_element(layers.begin(), layers.end());
        if (minLayer == maxLayer)
            break; // All layers have equal neurons

        generations++;
        if (generations % 2 == 1)
        { // Odd generation, add 1 neuron to a layer
            for (int i = 0; i < n; i++)
            {
                if (layers[i] == minLayer)
                {
                    layers[i]++; // Add 1 neuron
                    break;
                }
            }
        }
        else
        { // Even generation, add 2 neurons to a layer
            for (int i = 0; i < n; i++)
            {
                if (layers[i] == minLayer)
                {
                    layers[i] += 2; // Add 2 neurons
                    break;
                }
            }
        }
        maxLayer = *max_element(layers.begin(), layers.end());
    }

    return generations;
}

int main()
{
    int n;
    cin >> n; // Input number of layers
    vector<int> layers(n);

    // Input the number of neurons in each layer
    for (int i = 0; i < n; i++)
    {
        cin >> layers[i];
    }

    // Output the minimum number of generations
    cout << findMinGeneration(layers) << endl;

    return 0;
}
