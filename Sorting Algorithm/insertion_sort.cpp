#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

void insertion_sort(int ara[], int n){
    int i, j, item;
    for(i = 1; i < n; i++){
        item = ara[i];
        j = i - 1;
        while(j >= 0 && ara[j] > item){
            ara[j+1] = ara[j];
            j--;
        }
        ara[j+1] = item;
    }
}

void decending_insertion_sort(int ara[], int n){
    int i, j, item;
    for(i = 1; i < n; i++){
        item = ara[i];
        j = i - 1;
        while(j >= 0 && ara[j] < item){
            ara[j+1] = ara[j];
            j--;
        }
        ara[j+1] = item;
    }
}
int main()
{
    int ara[1007], n, x;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> ara[i];
    decending_insertion_sort(ara, n);
    for(int i = 0; i < n; i++) cout << ara[i] << " ";
    cout << endl;
    insertion_sort(ara, n);
    for(int i = 0; i < n; i++) cout << ara[i] << " ";
    cout << endl;
    return 0;
}
