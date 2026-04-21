#include<bits/stdc++.h>
using namespace std;
void solve(int idx, string s, string& t, vector<string>& res){
    res.push_back(t);

    for (int i = idx; i < s.size(); i++){
        if(i > idx && s[i] == s[i-1])
            continue;
        t.push_back(s[i]);
        solve(i + 1, s, t, res);
        t.pop_back();
    }
}
int main(){
    string s;
    cin >> s;
    vector<string> res;
    sort(s.begin(), s.end());
    string t = "";
    solve(0, s, t, res);
    for(string str : res)
        cout << str << endl;
    return 0;
}