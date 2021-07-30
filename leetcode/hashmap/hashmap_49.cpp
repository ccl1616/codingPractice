#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <unordered_map>
  
using namespace std;

// my thoughts
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // word length
        // alphabet, # alphabet 
        vector<unordered_map<char, int>> d;
        vector<vector<string>> ret;
        for(int i = 0; i < strs.size(); i ++) {
            // if first string
            /* 
                put it into ret

                record this str by a map
                d.pish_back map
            */

            // else
            /*
                record this str by a map

                scan through d
                compare maps

                if same, push this string into ret

                if there's no matching pattern, d.pish_back map
            */
        }
    }
};

// sol 1, this is gooood
/*
    key: sort the string!!, use it as the key of map
    map value be an array, save all the anagrams
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Base case
		if(strs.size() == 1)
            return {{strs[0]}};
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> M; // key with string itself
        for(int  i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(strs[i].begin(), strs[i].end()); // Sorting the string by increasing order
            M[strs[i]].push_back(str);  // Sorted string is the key and the value is the initial string , 
            // put anagrams in vector!
        }
        for(auto i = M.begin(); i != M.end(); i++)
            ans.push_back(i -> second);  // get the vector, family of anagrams
        return ans;
    }
};