#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define maxn 200

ll arr[maxn],n;
ll find_max()
{
    ll x = INT32_MIN;
    for(ll i = 0; i < n; i++)
    {
        if(arr[i] > x)
            x = arr[i];
    }
    return x;
}
void cnt_sort(ll num)
{
    ll aux[n];
    ll i, cnt[10] = {0};
    for(i =0; i < n; i++)
    {
        cnt[(arr[i]/num)%10]++;
    }
    for(i = 1; i < 10; i++)
        cnt[i] += cnt[i-1];
    for(i = n-1; i >= 0; i--)
    {
        aux[cnt[(arr[i]/num)%10] - 1] = arr[i];
        cnt[(arr[i]/num)%10]--;
    }
    for(i =0; i < n; i++)
    {
        arr[i] = aux[i];//cout << arr[i] << " ";
    }
}
void radix_sort()
{
    ll m = find_max();
    for(ll x = 1; m/x > 0; x *= 10)
    {
        cnt_sort(x);
    }
}
int main()
{
    puts("Enter the number of elements.");
    cin >> n;
    puts("Enter the elements of the to be sorted.");
    for(ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    radix_sort();
    for(ll i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}
