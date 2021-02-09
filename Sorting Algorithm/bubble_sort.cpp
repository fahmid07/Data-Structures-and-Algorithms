#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void bubble_sort(int ara[], int n){
    int i, j, cnt = 0;
    for(i = 0; i < n; i++){
        for(j =0; j < n-i-1; j++){
            if(ara[j]>ara[j+1]) swap(ara[j], ara[j+1]);
        }
        if(is_sorted(ara, ara+n)) break;
    }
}

void decending_bubble_sort(int ara[], int n){
    int i, j, cnt = 0;
    for(i = 0; i < n; i++){
        for(j =0; j < n-i-1; j++){
            if(ara[j]<ara[j+1]) swap(ara[j], ara[j+1]);
        }
        if(is_sorted(ara, ara+n, greater<int>())) break;
    }
}

int main()
{
    int ara[1007], n, x;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> ara[i];
    decending_bubble_sort(ara, n);
    for(int i = 0; i < n; i++) cout << ara[i] << " ";
    cout << endl;
    bubble_sort(ara, n);
    for(int i = 0; i < n; i++) cout << ara[i] << " ";
    cout << endl;
    return 0;
}
