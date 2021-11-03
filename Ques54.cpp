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

bool isPalindrome(string str)
{
    for (int i = 0, j = str.length() - 1; i <= j; i++, j--)
        if (str[i] != str[j])
            return 0;

    return 1;
}

void solve()
{
    string str;
    cin >> str;
    string ans;

    for (int i = 0; i < str.length(); i++)
        for (int j = str.length(); j >= i; j--)

            if (isPalindrome(str.substr(i, (j - i))))
                if (ans.length() < (j - i))

                    ans = str.substr(i, (j - i));

    cout << ans << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}