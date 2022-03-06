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
    cout << a[i]

#define rep(i, n) for (int i = 0; i < n; i++)
#define forr(i, n) for (int i = n; i >= 0; i--)
#define fep(i, a, b) for (int i = a; i < b; i++)

bool find3Numbers(int a[], int n, int x)
{
    sort(a, a + n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1, k = n - 1; j < k;)
        {
            if (a[i] + a[j] + a[k] == x)
                return 1;
            else if (a[i] + a[j] + a[k] <= x)
                j++;
            else
                k--;
        }

    return 0;
}

void solve()
{
    int n, x;
    cin >> n >> x;
    int a[n];
    cin(a, n);
    cout << find3Numbers(a, n, x) << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}