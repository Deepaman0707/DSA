#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define pb push_back
#define pob pop_back
#define mp make_pair
#define all(a) (a).begin(), (a).end()
#define ff first
#define ss second
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
    int n;
    cin >> n;
    int a[n];
    cin(a, n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        a[i] = sum;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == a[i - 1] || a[i] == 0)
        {
            cout << "true" << endl;
            return;
        }
    }
    cout << "false" << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}