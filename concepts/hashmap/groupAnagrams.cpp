// Given an array of strings strs, group the anagrams together.You can return the answer in any order.

/*
Solution Description
We first sort all the strings in the array and store them in a hashmap. The key of the hashmap is the sorted string and the value is a vector of strings that are anagrams of the key. Finally, we iterate through the hashmap and store all the values in a vector of vectors.

Time Complexity : O(n * m * log(m))
n is the number of strings in the array and m is the length of the longest string. Sorting each string will take O(m * log(m)) time.

Space Complexity : O(n * m)
Extra space required for hashmap storage is O(n * m)

*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for(auto& str : strs){
            string key = str;
            sort(key.begin(), key.end());
            
            anagramGroups[key].emplace_back(str);
        }

        vector<vector<string>> groupedAnagrams;

        for(auto& pair: anagramGroups){
            groupedAnagrams.emplace_back(pair.second);
        }
        return groupedAnagrams;
    }
};