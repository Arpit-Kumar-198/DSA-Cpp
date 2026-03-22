// leetcode 78
#include<iostream>
#include<vector>
using namespace std;
void subset(int a[], int n, int idx, vector<int> ans, bool flag)
{
    if(idx == n)
    {
        for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
        cout << endl;
        return;
    }
    int ch = a[idx];
    int dh = a[idx+1];
    if(ch == dh)
    {
        if(flag == true) subset(a, n, idx+1, ans, true);    
        ans.push_back(a[idx]);
        subset(a, n, idx+1, ans, false);
    }
    else{
       if(flag == true)  subset(a, n, idx+1, ans, true);
        ans.push_back(a[idx]);
        subset(a, n, idx+1, ans, true);
    }
   
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> v;
    subset(a,n,0,v,true);
    return 0;
}