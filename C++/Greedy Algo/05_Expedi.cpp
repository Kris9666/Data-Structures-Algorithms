// Expedi (Expedition)
// A group of cows grabbed a truck and ventured on an expedition deep into the jungle.
// The truck leaks one unit of fuel every unit of distance it travel. 
// To repair the truck, the cows need to drive to the nearest town(we move than 10^6 units distance).
// On this road, between the town and the current location, there are N(1<=N<=10^5) fuels stops
// where the coes can stop to acquire additional fuels (1......100 units at each stop)
// The cows want to make the minimum possible number of stops for fuels on the way to town.
// Initial units of Fuel: P (1<=P<=10^6)
// Initial distance from towm: L 
// Determine the minimum number of stops to reach the town. 
// Input : 1 
//         4
//         4 4 
//         5 2 
//         11 5
//         15 10
//         25 10
// Output : 2


#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<pair<int,int> > a(n);
        for (int i=0; i<n; i++){
            cin>>a[i].first>>a[i].second;
        }
        int l,p;
        cin>>l>>p;
        for (int i=0; i<n; i++){
            a[i].first = l-a[i].first;
        }
        sort(a.begin(), a.end());

        int ans = 0;
        int curr = p;
        priority_queue<int, vector<int> > pq;
        bool flag = 0;
        for (int i=0; i<n; i++){
            if (curr >= l){
                break;
            }
            while(curr < a[i].first){
                if (pq.empty()){
                    flag = 1;
                    break;
                }
                ans++;
                curr += pq.top();
                pq.pop(); 
            }
            if (flag){
                break;
            }
            pq.push(a[i].second);
        }
        if (flag){
            cout<<"-1"<<endl;
            continue;
        }
        while(!pq.empty() && curr<l){
            curr += pq.top();
            pq.pop();
            ans++;
        }
        if (curr < l){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
}