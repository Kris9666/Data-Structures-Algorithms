// Min Subarray Size
//  For a given array and an integer X, find the minimum subarray size for which sum > X.
// Time Complexity = O(n); 

#include<iostream>
using namespace std;
int smallestSubarrayWithSum(int arr[], int n, int x){
    int sum=0, minLength = n+1, start=0, end=0;
    while(end < n){
        while(sum <= x && end < n){
            sum += arr[end++];
        }
        while(sum > x && start < n){
            if (end-start < minLength){
                minLength = end - start;
            }
            sum -= arr[start++];
        }
    }
    return minLength;
}
int main(){
    int arr[] = {1,4,45,6,10,19};
    int x = 51;
    int n = 6;
    int minLength = smallestSubarrayWithSum(arr,n,x);
    if (minLength == n+1){
        cout<<"No such subarrays exist"<<endl;
    }
    else {
        cout<<"Smallest length subarray is : "<<minLength<<endl;
    }
    return 0;
}