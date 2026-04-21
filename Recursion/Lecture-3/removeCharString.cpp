// remove all a from string

#include<iostream>
#include<string>
using namespace std;
void removeChar(string ans, string original, int idx)
{
    if(idx == original.length())
    {
        cout << ans;
        return;
    }
    char ch = original[idx];
    if(ch == 'a') removeChar(ans, original, idx+1);
    else removeChar(ans+ch,original, idx+1);
}
int main()
{
    string s;
    cin >> s;
    removeChar("",s, 0);
    return 0;
}