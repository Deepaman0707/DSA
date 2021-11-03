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

// Linear Search for first occurrence and last occurrence.

void findPos(int a[], int n, int num)
{
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == num)
        {
            if (start == 0 && end == 0)
            {
                start = i;
                end = i;
            }
            else
                end = i;
        }

    cout << start << " " << end << endl;
}

// Binary Search for first occurrence and last occurrence.

int firstOccurrence(int a[], int start, int end, int num, int n)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if ((mid == 0 || num > a[mid - 1]) && a[mid] == num)
            return mid;
        else if (num > a[mid])
            return firstOccurrence(a, (mid + 1), end, num, n);
        else
            return firstOccurrence(a, start, (mid - 1), num, n);
    }
    return -1;
}

int lastOccurrence(int a[], int start, int end, int num, int n)
{
    if (end >= start)
    {
        int mid = start + (end - start) / 2;
        if ((mid == n - 1 || num < a[mid + 1]) && a[mid] == num)
            return mid;
        else if (num < a[mid])
            return lastOccurrence(a, start, mid - 1, num, n);
        else
            return lastOccurrence(a, mid + 1, end, num, n);
    }
    return -1;
}

void solve()
{
    int n, num;
    cin >> n;
    int a[n] = {0};
    cin(a, n);
    cin >> num;
    // findPos(a, n, num);
    cout << firstOccurrence(a, 0, n - 1, num, n) << " " << lastOccurrence(a, 0, n - 1, num, n) << endl;
}

int main()
{
    fast;
    solve();
    return 0;
}