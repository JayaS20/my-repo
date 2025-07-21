#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Leader(vector<int>& arr){
    int n = arr.size();
    vector<int> result;
    int maxRight = arr[n-1];
    result.push_back(maxRight);
    for(int i=arr[n-2];i>=0;i--){
        if(arr[i]>=maxRight){
            maxRight=arr[i];
            result.push_back(maxRight);
        }
    }
        reverse(result.begin(),result.end());
        return result;
    
}



int main() {
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> res = Leader(arr);
    for(int num : res){
        cout<<num<<" ";
    }
    cout<<"\n";
    return 0;
}
