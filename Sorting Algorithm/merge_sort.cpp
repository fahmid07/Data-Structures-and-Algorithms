#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;

vi _merge(vi left, vi right){
    vi vec(right.size() + left.size());
    int i=0, j=0, k=0;
    while (i < left.size() && j < right.size()){
        if (left[i] < right[j]){
            vec[k] = left[i];
            i++;
        }
        else{
            vec[k] = right[j];
            j++;
        }
        k++;
    }

    while(i<left.size()){
        vec[k] = left[i];
        i++;
        k++;
    }

    while(j<right.size()){
        vec[k] = right[j];
        j++;
        k++;
    }

    return vec;
}

vi merge_sort(vi vec)
{
    int m;
    if(vec.size()<=1) return vec;
    else m = vec.size() / 2;

    vi left(vec.begin(), vec.begin()+m);
    vi right(vec.begin()+m, vec.begin()+vec.size());

    left = merge_sort(left);
    right = merge_sort(right);

    vec = _merge(left, right);

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

    vec = merge_sort(vec);

    for(auto i:vec) cout << i << " ";
    cout << "\n";

    return 0;
}
