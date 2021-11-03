#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long int
#define fast ios_base::sync_with_stdio(NULL), cin.tie(0), cout.tie(0)
#define MOD 1e9 + 7
#define cin(a, n)               \
    for (int i = 0; i < n; i++) \
    cin >> a[i]

#define cout(a, n)              \
    for (int i = 0; i < n; i++) \
    cout << a[i]

#define rep(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n; i >= 0; i--)
#define fep(i, a, b) for (int i = a; i < b; i++)

string countAndSay(int n)
{
    // Base condition
    if (n == 1)
        return "1";

    // Main logic Statement
    string str = countAndSay(n - 1);
    string result;
    int count = 0;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == str[i + 1])
            count++;
        else
        {
            count++;
            result = result + (char)(count + '0') + str[i];
            count = 0;
        }
    }

    //Return statement
    return result;
}

void solve()
{
    int n;
    cin >> n;
    cout << countAndSay(n) << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}