#include <bits/stdc++.h>
using namespace std;

vector<int> toBinary(int no) {
    vector<int> ans;
    if(no == 0) return {0};
    while(no > 0){
        ans.push_back(no & 1);
        no >>= 1;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int toDecimal(vector<int> Binary) {
    int ans = 0;
    int n = Binary.size();
    for (int i = 0; i < n; ++i) {
        ans += Binary[i] * pow(2, n - 1 - i);
    }
    return ans;}
    
//for 10^9 no of bits required is  30
//for 10^18 no of bits required is 60
int BitLength(int n) {
    int length = 0;
    while (n > 0) {
        n >>= 1;
        length++;
    }
    return length;
}