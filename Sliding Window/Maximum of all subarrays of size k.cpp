// Sliding Window Maximum
// Maximum of all subarrays of size k

#include<bits/stdc++.h>
using namespace std;
typedef int lli;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t, n, k, sum, mx, x;
    vector<lli> nums;
    vector<lli> vec;

    cin >> t;
    while(t--){
        cin >> n >> k;
        while(n--){
            cin >> x;
            nums.push_back(x);
        }
        deque<lli> dq(k);
        for(lli i=0; i<k; i++){
            while(!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }
        vec.push_back(nums[dq.front()]);
        for(lli i=k; i<nums.size(); i++){
            while(!dq.empty() && dq.front() <= i-k) dq.pop_front();

            while(!dq.empty() && nums[i] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(i);
            vec.push_back(nums[dq.front()]);
        }

        for(lli i=0; i<vec.size(); i++) cout << vec[i] << " ";
        cout << endl;
        nums.clear();
        vec.clear();
    }
    return 0;
}
