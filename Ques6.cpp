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
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    cin(a, n);
    cin(b, m);
    int size = min(n, m);
    int size1 = n + m;
    int c[size], d[size1];
    for (int i = 0, j = 0, k = 0, l = 0; i < n || j < m;)
    {
        if (a[i] == b[j])
        {
            c[k] = a[i];
            d[l] = a[i];
            k++;
            i++;
            j++;
            l++;
            size = k;
            size1 = l;
        }
        else if (a[i] < b[j])
        {
            d[l] = a[i];
            l++;
            size1 = l;
            i++;
        }
        else
        {
            d[l] = b[j];
            l++;
            size1 = l;
            j++;
        }
    }
    cout(c, size);
    cout << endl;
    cout(d, size1);
}

int main()
{
    fast;
    solve();
    return 0;
}