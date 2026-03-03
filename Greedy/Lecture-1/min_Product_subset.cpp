#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int minProduct(vector<int>& arr){
    int n = arr.size(), cn = 0, cz = 0, cp = 0;
    int prod_pos = 1, prod_neg = 1, largestNeg = INT_MIN;

    for (int i = 0; i < n; i++){
        if(arr[i] < 0){
            cn++;
            prod_neg *= arr[i];
            largestNeg = max(largestNeg, arr[i]);
        }

        if(arr[i] == 0) cz++;
        if(arr[i] > 0){
            cp++;
            prod_pos *= arr[i];
        }
    }
    if(cn == 0){
        if(cz > 0) return 0;
        else{
            auto it = min_element(arr.begin(), arr.end());
            return *(it);
        }
    }
    else{
        if(cn%2 == 0) return (prod_neg / largestNeg);
        else return prod_pos *prod_neg;
    }
}
int main(){
    /*
        n numbers hai -ve +ve or zero 
        find product , product should be minimum possible from array
    */

    vector<int> arr = {0,-6,8};
    cout << minProduct(arr);
    return 0;
}