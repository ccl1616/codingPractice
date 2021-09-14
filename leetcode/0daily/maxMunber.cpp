#include <bits/stdc++.h>
using namespace std;

// maximum number of balloons

// O(N) approach
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // balloon, 
        // 0 1 2 3 4
        // b a l o n
        vector<int> arr = {0, 0, 0, 0, 0};
        for(int i = 0; i < text.size(); i ++) {
            if(text[i] == 'b') arr[0] ++;
            else if(text[i] == 'a') arr[1] ++;
            else if(text[i] == 'l') arr[2] ++;
            else if(text[i] == 'o') arr[3] ++;
            else if(text[i] == 'n') arr[4] ++;
        }
        arr[2] = arr[2] / 2;
        arr[3] = arr[3] / 2;
        int min = *min_element(arr.begin(), arr.end());
        return min;
    }
};