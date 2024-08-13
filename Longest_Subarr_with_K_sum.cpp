#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;
int lenOfLongestSubarr(vector<int>& a, int n, int K){
    unordered_map<int, int> sum_index_map;
    int maxLen = 0;
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum+=a[i];
        if(sum == K){
            maxLen+=1;
        }
        else if(sum_index_map.find(sum - K) != sum_index_map.end()){ // nếu (sum - K) có tồn tại trong map
            maxLen = max(maxLen, i - sum_index_map[sum - K]);
        }
        if(sum_index_map.find(sum) == sum_index_map.end()){ // nếu sum k tồn tại trong map
            sum_index_map[sum] = i;
        }
    }
    return maxLen;
}

int main(){
    int n, K;
    cin >> n >> K;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << lenOfLongestSubarr(a, n, K);
}
