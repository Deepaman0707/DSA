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
    int a[] = {3, 1, 3, 4, 2};
    int size = sizeof(a) / sizeof(int);
    int freq[size] = {0};
    for (int i = 0; i < size; i++)
        freq[a[i]]++;

    for (int i = 1; i < size; i++)
        if (freq[i] >= 2)
            cout << i;
}

int main()
{
    fast;
    solve();
    return 0;
}