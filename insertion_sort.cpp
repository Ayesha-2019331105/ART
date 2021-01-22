#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define maxn 2000000
ll arr[maxn];
void insertion_sort(ll n)
{
    for(ll i =1; i < n; i++)
    {
        ll j = i - 1;
        ll x = arr[i];
        while(j > -1 && arr[j] > x)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = x;
    }
}
int main()
{
    puts("Enter the number of elements.");
    ll n;
    cin >> n;
    puts("Enter the elements of the to be sorted.");
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    insertion_sort(n);
    for(ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
/**
10
11 13 7 12 16 9 24 5 10 3
*/
