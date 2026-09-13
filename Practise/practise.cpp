#include<bits/stdc++.h>
using namespace std;
void factorial(int n, vector<int>& fact){
    int carry = 0;
    if(n == 0 || n == 1)
        return;

    for (int i = 2; i <= n; i++){
        for (int j = 0; j < fact.size(); j++){
            int x = fact[j] * i + carry;
            carry = x / 10;
            fact[j] = x % 10;
        }
        while(carry > 0){
            fact.push_back(carry % 10);
            carry /= 10;
        }
    }
    return;
}
int main(){
    cout << "Enter a number: ";
    int n;
    cin >> n;
    vector<int> fact;
    fact.push_back(1);
    factorial(n, fact);
    reverse(fact.begin(), fact.end());
    cout << "Factorial of " << n << ": ";
    for (int i = 0; i < fact.size(); i++)
        cout << fact[i];

        return 0;
} 