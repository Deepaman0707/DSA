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
    int n;
    cin >> n;
    int a[n];
    cin(a, n);
    int low = 0, high = n - 1;
    for (int i = 0; i <= high; i++)
    {
        if (a[i] == 0)
        {
            swap(a[low], a[i]);
            low++;
        }
        else if (a[i] == 2)
        {
            swap(a[i], a[high]);
            high--;
            i--;
        }
    }
    cout(a, n);
}

int main()
{
    fast;
    solve();
    return 0;
}