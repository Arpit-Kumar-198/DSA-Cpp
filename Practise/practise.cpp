#include<bits/stdc++.h>
using namespace std;
void move(int n, vector<int>& arr){
    int i = 0, j = n - 1;
    while(i < j){
        if(arr[i] < 0) {
            swap(arr[j], arr[i]);
            j--;
        }
        else
            i++;
    }
    return;
}

void moveWithOrder(int n, vector<int>& arr){
    vector<int> pos, neg;
    for (int i = 0; i < n; i++){
        if(arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }
    int idx;
    for (idx = 0; idx < pos.size(); idx++)
    {
        arr[idx] = pos[idx];
    }
    for (int i = 0; i < neg.size(); i++){
        arr[idx++] = neg[i];
    }
        return;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    // move(n, arr);
    moveWithOrder(n, arr);

    for (auto num : arr)
        cout << num << " ";


    return 0;
} 