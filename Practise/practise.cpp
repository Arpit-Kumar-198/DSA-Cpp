#include<bits/stdc++.h>
using namespace std;
/*
    stack
    queue
    heap
    Binary tree
    BST
    Heap
*/
void func(string s, string temp, vector<string>& ans, int n){
    if(temp.size() == n) {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < s.size(); i++){
        string l = s.substr(0, i), r = s.substr(i + 1);
        func(l + r, temp + s[i], ans, n);
    }
}
int main(){
    string s = "abcdefghijk";
    vector<string> ans;
    string temp = "";
    func(s, temp, ans, s.size());
    for(auto ch : ans)
        cout << ch << endl;
    return 0;
}