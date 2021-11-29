#include <bits/stdc++.h>
using namespace std;
// 1130
class Solution {
public:
    int target;
    vector<vector<int>> res;
    vector<int> tmp;
    void dfs(vector<vector<int>>& graph, int start = 0 ) {
        tmp.push_back(start);
        if(start == target) res.push_back(tmp);
        else {
            for(int node: graph[start])
                dfs(graph, node);
        }
        tmp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        target = graph.size() - 1;
        dfs(graph);
        return res;
    }
};