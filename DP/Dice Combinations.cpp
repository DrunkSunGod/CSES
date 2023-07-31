
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int countWays( int n, vector<int>&dp){
    if( n < 0 )
        return 0 ; 
    if( n == 0 || n == 1 )
        return 1 ; 
    if( dp[n] != -1 )
        return dp[n] ;
    int ans = 0 ; 
    for( int curr = 1 ; curr <= 6 ; curr++ ){
        ans += countWays(n - curr, dp)%MOD ;
        ans = ans%MOD ; 
    }
    return dp[n] = ans%MOD ; 
}
int main()
{   
    int n ; cin >> n ; 
    vector<int>dp(n+1, -1) ; 
    cout << countWays(n,dp) << endl ; 
    return 0;
}
