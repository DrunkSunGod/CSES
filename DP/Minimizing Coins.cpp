#include <bits/stdc++.h>
using namespace std;
int minCoins(vector<int>&coins, int sum, vector<int>&dp){
    int n = coins.size() ; 
    if(sum == 0)
        return 0 ; 
    if( sum < coins[n-1] )
        return 1e9 ; 
    if( dp[sum] != -1 )
        return dp[sum] ; 
    int ans = 1e9 ; 
    for( int i = 0 ; i < n ; i++ ){
        if( sum >= coins[i] )
            ans = min( ans, 1 + minCoins(coins,sum-coins[i], dp) ) ; 
    }
    return dp[sum] = ans ; 
}
int main()
{   
   int n, x ; cin >> n >> x ; 
   vector<int>coins(n) ; 
   for( int i = 0 ; i < n ; i++ ){
       cin>>coins[i] ; 
   }
   sort(coins.rbegin(), coins.rend() ) ; 
   vector<int>dp(x+1, -1) ; 
   int ans = ( minCoins(coins,x,dp) >= 1e9 ) ? -1 : minCoins(coins,x, dp) ; 
   cout << ans << endl ; 
   return 0 ; 
}
