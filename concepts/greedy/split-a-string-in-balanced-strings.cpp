// Balanced strings are those that have an equal quantity of 'L' and 'R' characters.

// Given a balanced string s, split it into some number of substrings such that :

//     Each substring is balanced.

//     Return the maximum number of balanced strings you can obtain.

#include <iostream>
#include <string>

int balancedStringSplit(std::string s)
{
    int count = 0;
    int balance = 0;

    for (char c : s)
    {
        if (c == 'R')
        {
            balance++;
        }
        else
        {
            balance--;
        }

        if (balance == 0)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    std::string s = "RLRRRLLRLL";
    int result = balancedStringSplit(s);
    std::cout << "Number of balanced strings: " << result << std::endl;

    return 0;
}