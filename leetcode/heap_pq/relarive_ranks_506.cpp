#include <bits/stdc++.h>
using namespace std;
// 1003, heap(priority queue)

// stupid af, runtime error
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> tmp = score;
        sort(tmp.begin(), tmp.end());
        vector<string> ret(n, 0);
        for(int i = 0; i < n; i ++) {
            if(score[i] == tmp[n-1]) ret[i] = "Gold Medal";
            else if(score[i] == tmp[n-2]) ret[i] = "Silver Medal";
            else if(score[i] == tmp[n-3]) ret[i] = "Bronze Medal";
            else {
                int j = n-4;
                for(j = n-4 ; j >= 0; j --) 
                    if(score[i] == tmp[j]) break;
                // string t = to_string( n-j );
                ret[i] = n-j;                       
            }
        }
        return ret;
    }
};

// sol, use PQ
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ret(n,"");
        // pq, time = heap build = O(n)
        priority_queue<pair <int, int>> que;
        for(int i = 0; i < n; i ++)
            que.push({score[i], i});
        // iterate pq
        for(int i = 0; i < n; i ++) {
            int val = que.top().first;
            int id = que.top().second;
            que.pop();

            if(i == 0) ret[id] = "Gold medal";
            else if(i == 1) ret[id] = "Silver Medal";
            else if(i == 2) ret[id] = "Bronze Medal";
            else ret[id] = to_string(i);
        }
        return ret;
    }
};