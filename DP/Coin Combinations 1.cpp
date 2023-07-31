#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int ways(vector<int>&coins, int sum, vector<int>&dp){
    if( sum == 0 )
        return 1 ; 
    if( sum < coins[0] )
        return 0 ; 
    if( dp[sum] != -1 )
        return dp[sum] ; 
    int ans = 0 ; 
    for( auto coin : coins ){
        if( sum >= coin )
            ans += (ways(coins,sum-coin,dp))%MOD ; 
            ans = ans%MOD; 
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
   sort(coins.begin(), coins.end() ) ; 
   vector<int>dp(x+1, -1) ; 
   int ans = ways(coins,x,dp) ; 
   cout << ans << endl ; 
   return 0 ; 
}
