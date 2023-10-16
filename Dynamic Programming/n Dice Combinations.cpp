// 1155. Number of Dice Rolls With Target Sum
// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/


class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<long long> vec(target+7, 0);
        vec[0] = 1;
        while(n--){
            vector<long long> temp(target+7, 0);
            for(int i=1; i<=target; i++){
                for(int j=1; j<=k; j++){
                    if(j>i) break;
                    temp[i] += vec[i-j];
                    temp[i] %= 1000000007;
                }
            }
            vec = temp;
        }
        return vec[target];
    }
};