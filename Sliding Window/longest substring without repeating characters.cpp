// Given a string s, find the length of the longest substring without repeating characters.

#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    lli t, n, i, j, mx, cnt;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        n = s.size();
        i = 0;
        j = 0;
        mx = 0;
        cnt = 0;

        vector<bool> visited(256);
        while(i<n && j<n && i<=j){
            if(visited[s[j]] == true){
                visited[s[i]] = false;
                i++;
            }
            else{
                visited[s[j]] = true;
                cnt = j - i + 1;
                mx = max(mx, cnt);
                j++;
            }
        }
        cout << mx << endl;
    }
    return 0;
}
