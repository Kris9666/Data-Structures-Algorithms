// Max Sum Subarray 
// For a given array and integers K and X, find the maximum sum subarray of size K and 
// having sum less than X. 
// Time Complexity = O(n);

#include<iostream>
using namespace std;
void maxSubaaraySum(int arr[], int n, int k, int x){
    int sum = 0, ans = 0;
    for (int i=0; i<k; i++){
        sum += arr[i];
    }
    if (sum < x){
        ans = sum;
    }
    for  (int i=k; i<n; i++){
        sum = sum - arr[i-k];
        sum = sum + arr[i];

        if (sum < x){
            ans = max(ans, sum);
        }
    }
    cout<<ans<<" is the max subarray sum (<x)"<<endl;
}
int main(){
    int arr[] = {7,5,4,6,8,9};
    int k = 3;
    int x = 20;
    int n = 6;
    maxSubaaraySum(arr, n, k, x);
    return 0;
}