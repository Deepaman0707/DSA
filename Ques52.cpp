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

void solve()
{
    string str1, str2, str3;
    int flag = 0, j = 0;
    cin >> str1 >> str2 >> str3;

    if ((str1 + str2).length() != str3.length())
    {
        cout << "False" << endl;
        return;
    }
    string result = str1 + str2;
    sort(result.begin(), result.end());
    sort(str3.begin(), str3.end());
    for (int i = 0; i < str3.length(); i++)
        if (str3[i] != result[i])
        {
            cout << "False" << endl;
            return;
        }

    cout << "True" << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}