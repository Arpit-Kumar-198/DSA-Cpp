#include<iostream>
#include<vector>
using namespace std;
void subsequence(int idx, int k, vector<int>& arr, vector<int>& temp, vector<vector<int>>& res)
{
    if(temp.size() == k) res.push_back(temp);
    
    for (int i = idx; i < arr.size(); i++)
    {
        if(i > idx && arr[i] == arr[i-1]) continue;
        temp.push_back(arr[i]);
        subsequence(i + 1, k, arr, temp, res);
        temp.pop_back();
    }
}

/*
    print all increasing sequence of length k from first n natural numbers.  
    123 = [1,2], [1,3], [2,3] for k = 2
*/
   
// leetcode 78

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) arr[i] = i + 1;
    vector<int> temp;
    vector<vector<int>> res;
    subsequence(0, k, arr, temp, res);
    for(auto vec : res){
        for(int x : vec)
            cout << x << " ";
        cout << endl;
    }
    return 0;
}