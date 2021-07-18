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