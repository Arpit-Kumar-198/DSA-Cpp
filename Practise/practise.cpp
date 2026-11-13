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

void transpose(vector<vector<int>>& arr){
    int n = arr.size();
   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            swap(arr[i][j], arr[j][i]);
    }

    return;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }
    transpose(arr);
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    return 0;
} 