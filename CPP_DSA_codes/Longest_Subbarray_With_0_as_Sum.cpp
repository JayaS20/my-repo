#include<bits/stdc++.h>
using namespace std;
int longestSubarrayWithSumZ(vector<int> a){
    int target=0;
    map<long long, int>preSum;
    long long sum=0;
    int maxLen=0;
    for(int i=0;i<a.size();i++){
        sum += a[i];
        if(sum == target){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - target;
        if(preSum.find(rem) != preSum.end()){
            int len = i - preSum[rem];
            maxLen = max(maxLen, len);
        }
        if(preSum.find(sum) == preSum.end()){ // if a particular sum is not present already, it gets inserted(here preSum.end() means "not found")
            preSum[sum] = i;
        }
    }
    return maxLen;
}
int main() {
    vector<int> a = {1, -1, 3, 2, -2, -3, 3}; 
    cout << "Longest subarray with sum 0: " << longestSubarrayWithSumZ(a) << endl;
    return 0;
}
//output is 6