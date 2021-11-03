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
    cout << a[i] << " "

#define rep(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n; i >= 0; i--)
#define fep(i, a, b) for (int i = a; i < b; i++)

void solve()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    cin(a, n);
    sort(a, a + n);
    int small = a[0] + k, large = a[n - 1] - k, minh = 0, maxh = 0, ans = a[n - 1] - a[0];
    for (int i = 1; i < n; i++)
        if (a[i] >= k)
        {
            minh = min(small, (a[i] - k));
            maxh = max(large, (a[i - 1] + k));
            ans = min(ans, (maxh - minh));
        }
    cout << ans << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}