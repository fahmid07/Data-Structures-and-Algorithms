#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

vi quick_sort(vi vec, int l, int r)
{
    if(l<r){
        int p = l;
        int cmp = vec[p];
        int i = l+1, j = r;

        while(vec[i] < cmp) i++;
        while(vec[j] > cmp) j--;

        while(i < j){
            swap(vec[i], vec[j]);
            while(vec[i] < cmp) i++;
            while(vec[j] > cmp) j--;
        }
        swap(vec[j], vec[p]);

        vec = quick_sort(vec, l, j-1);
        vec = quick_sort(vec, j+1, r);
    }
    return vec;
}


int main()
{
    int n, t, x;
    vi vec;
    cin >> n;
    while(n--){
        cin >> x;
        vec.push_back(x);
    }
    n = vec.size();

    vec = quick_sort(vec, 0, n-1);

    for(auto i:vec) cout << i << " ";
    cout << "\n";

    return 0;
}


