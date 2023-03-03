// Maximum XOR of 2 numbers in an array 
// Input : 5 
//         3 10 5 15 2 
// Output : 15

#include<iostream>
#include<vector>
using namespace std;
class TrieNode{
public:
    TrieNode* next[2];
    TrieNode(){
        next[0] = NULL;
        next[1] = NULL;
    }
};
TrieNode* buildtrie(vector<int> &a){
    TrieNode* root = new TrieNode();
    int n = a.size();
    for(int i=0; i<n; i++){
        int num = a[i];
        TrieNode* curr = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(curr->next[bit] == NULL){
                curr->next[bit] = new TrieNode();
            }
            curr = curr->next[bit];
        }
    }
    return root;
}
int helper(TrieNode* root, vector<int> &a){
    int res = 0;
    for(int i=0; i<a.size(); i++){
        int num = a[i];
        TrieNode* it = root;
        int curr_max = 0;
        for(int i=31; i>=0; i--){
            int bit = ((num>>i) & 1)? 0:1;
            if(it->next[bit]){
                curr_max <<= 1;
                curr_max |= 1;
                it = it->next[bit];
            }
            else{
                curr_max <<= 1;
                curr_max |= 0;
                it = it->next[bit xor 1];
            }
        }
        res = max(res, curr_max);
    }
    return res;
}


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    TrieNode* root = buildtrie(a);
    int ans = helper(root,a);
    cout<<ans;
    return 0;
}











// Brute Force Method 
// #include<iostream>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0; i<n; i++){
//         cin>>arr[i];
//     }
//     int ans=0;
//     for(int i=0; i<n; i++){
//         for(int j=i+1; j<n; j++){
//             ans = max(ans, arr[i] xor arr[j]);
//         }
//     }
//     cout<<ans;
//     return 0;
// }