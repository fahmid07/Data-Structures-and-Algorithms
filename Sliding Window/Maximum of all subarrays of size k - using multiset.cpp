// Sliding Window Maximum
// Maximum of all subarrays of size k (using multiset)

#include<bits/stdc++.h>
using namespace std;
typedef int lli;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t, n, k, sum, mx, x, y;
    vector<lli> nums;
    vector<lli> vec;

    cin >> t;
    while(t--){
        cin >> n >> k;
        while(n--){
            cin >> x;
            nums.push_back(x);
        }
        multiset<lli> s;
        multiset<lli>::iterator it;
        for(llit i=0; i<k; i++){
            s.insert(nums[i]);
        }
        it = s.end();
        it--;
        vec.push_back(*it);
        for(lli i=k; i<nums.size(); i++){
            x = nums[i];
            y = nums[i - k];
            it = s.find(y);
            s.erase(it);
            s.insert(x);
            it = s.end();
            it--;
            vec.push_back(*it);
        }

        for(lli i=0; i<vec.size(); i++) cout << vec[i] << " ";
        cout << endl;
        nums.clear();
        vec.clear();
    }
    return 0;
}
