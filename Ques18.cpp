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
    int n;
    cin >> n;
    int a[n] = {0};
    cin(a, n);
    int element = 0, count = 0;
    cin >> element;
    sort(a, a + n);
    int start = 0, end = n - 1;
    while (start < end)
    {
        if (a[start] + a[end] < element)
            start++;
        else if (a[start] + a[end] > element)
            end--;
        else
        {
            cout << "(" << a[start] << ", " << a[end] << ")" << endl;
            start++;
        }
    }
}

int main()
{
    fast;
    solve();
    return 0;
}