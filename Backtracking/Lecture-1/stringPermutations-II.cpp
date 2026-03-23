#include<bits/stdc++.h>
using namespace std;
/*
    repeatition of characters is allowed
*/
void stringPermutations(string s, string temp, vector<string>& ans){
    if(s.size() == 0) {
        ans.push_back(temp);
        return;
    }
    unordered_set<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        string l = s.substr(0, i), r = s.substr(i + 1);
        if(!st.count(s[i])){
            stringPermutations(l + r, temp + s[i], ans);
            st.insert(s[i]);
        } 
    }
}
void stringPermutations2(string s, int i, vector<string>& ans2){
    if(i == s.size()) {
        ans2.push_back(s);
        return;
    }
    unordered_set<char> st;
    for (int idx = i; idx < s.size(); idx++){
        swap(s[idx], s[i]);
        if(!st.count(s[i])){
            stringPermutations2(s, i + 1, ans2);
            st.insert(s[idx]);
        }
        swap(s[i], s[idx]);
    }
}
int main(){
    string s = "aab";
    vector<string> ans;
    string temp = "";
    cout << "First method (not memory efficient) : " << endl;
    stringPermutations(s, temp, ans);
    for(auto str : ans) cout << str << endl;
    cout << endl;
    cout << "Second method (using backtracking memory efficient) : " << endl;
    vector<string> ans2;
    stringPermutations2(s,0,ans2);
    for (auto str : ans2)
        cout << str << endl;

    return 0;
}