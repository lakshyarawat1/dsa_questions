// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> mp;
        if (s.size() != t.size())
        {
            return false;
        }

        for (auto ch : s)
        {
            mp[ch]++;
        }

        for (auto ch : t)
        {
            mp[ch]--;
        }

        for (auto it : mp)
        {
            if (it.second != 0)
            {
                return false;
            }
        }
        return true;
    }
};