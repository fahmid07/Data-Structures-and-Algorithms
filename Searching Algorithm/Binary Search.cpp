#include<bits/stdc++.h>

using namespace std;

int binary_search(int ara[], int n, int x){
    sort(ara,ara+n);
    int left, right, mid;
    left = 0;
    right = n - 1;

    while(left <= right){
        mid = left + (right - left) / 2;
        if(ara[mid] == x) return mid;
        if(ara[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main()
{
    int ara[1007], n, x;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> ara[i];
    cin >> x;
    int check = binary_search(ara, n, x);
    if(check != -1) cout << x << " Found in index " << check << endl;
    else cout << x << " Not Found\n";
    return 0;
}
