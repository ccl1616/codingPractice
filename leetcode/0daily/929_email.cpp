#include <bits/stdc++.h>
using namespace std;

//929. daily
int numUniqueEmails(vector<string>& emails) {
    unordered_set<string> set;
    for(auto i: emails) {
        string cleanEmail;
        for(char c: i) {
            if(c == '+' || c == '@') break; // things after +@ should be ignore
            if(c == '.') continue; // . should be ignore, goes to next iter
            cleanEmail += c;
        }
        cleanEmail += i.substr(i.find('@')); // + the string after @
        set.insert(cleanEmail);
    }
    return set.size();
}