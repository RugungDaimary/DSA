#include <iostream>
#include <cstring>
#include <algorithm>

char *restoreString(const char *s)
{
    int len = strlen(s);
    char *result = new char[len + 1];
    strcpy(result, s);

    // Remove all 'i's from the string
    int newLen = 0;
    for (int i = 0; i < len; i++)
    {
        if (result[i] != 'i')
        {
            result[newLen++] = result[i];
        }
    }
    result[newLen] = '\0';

    // Find the length of the repeated pattern at the end
    int patternLength = 0;
    for (int i = newLen - 1; i >= 0; i--)
    {
        if (strncmp(result + i, result + newLen - (newLen - i), newLen - i) == 0)
        {
            patternLength = newLen - i;
            break;
        }
    }

    // If no pattern found, return "notpossible"
    if (patternLength == 0)
    {
        strcpy(result, "notpossible");
        return result;
    }

    // Extract the original string
    result[newLen - patternLength] = '\0';

    // Verify the result
    char *test = new char[len + 1];
    strcpy(test, result);
    int testLen = 0;
    for (int i = 0; test[i]; i++)
    {
        if (test[i] != 'i')
        {
            test[testLen++] = test[i];
        }
    }
    strcat(test, result);

    if (strcmp(test, s) == 0)
    {
        delete[] test;
        return result;
    }
    else
    {
        delete[] test;
        strcpy(result, "notpossible");
        return result;
    }
}

int main()
{
    char input[1001]; // Assuming maximum input length is 1000
    std::cin >> input;
    char *output = restoreString(input);
    std::cout << output << std::endl;
    delete[] output; // Don't forget to free the allocated memory
    return 0;
}