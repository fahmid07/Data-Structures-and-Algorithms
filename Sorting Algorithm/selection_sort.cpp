#include<bits/stdc++.h>

using namespace std;

void selection_sort(int ara[], int n){
    int i, j, min, temp;

    for(i = 0; i < n - 1; i++){
        min = i;
        for(j = i + 1; j<n; j++){
            if(ara[j] < ara[min]) min = j;
        }
        if(min != i){
            temp = ara[i];
            ara[i] = ara[min];
            ara[min] = temp;
        }
    }
}
void decending_selection_sort(int ara[], int n){
    int i, j, max, temp;

    for(i = 0; i < n - 1; i++){
        max = i;
        for(j = i + 1; j<n; j++){
            if(ara[j] > ara[max]) max = j;
        }
        if(max != i){
            temp = ara[i];
            ara[i] = ara[max];
            ara[max] = temp;
        }
    }
}
int main()
{
    int ara[1007], n, x;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> ara[i];
    decending_selection_sort(ara, n);
    for(int i = 0; i < n; i++) cout << ara[i] << " ";
    cout << endl;
    selection_sort(ara, n);
    for(int i = 0; i < n; i++) cout << ara[i] << " ";
    cout << endl;
    return 0;
}
