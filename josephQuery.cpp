//----> HARE KRISHNA <----// 
 
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define ff first 
#define ss second
const ll mod = 1e9+7 ;
     
void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
ll getAns ( ll n , ll k )
{
    if(n&1){
        ll x = ((n+1)/2) ;
        if( k < x ){
            return (2*k)-1 ;
        }
        if( k == x ){
            return 0 ;
        }
        return 2*(getAns( n-x , k-x ) + 1)     ;
    }   
    else{
        ll x = (n/2) ;
        if( k <= x )  return 2*k - 1 ;
        return 2*getAns( n-x , k-x ) ;
    }
}
 
void solve()
{
    ll n , k ;
    cin >> n >> k ;
    ll ans = getAns( n , k ) ;
    cout << ans+1 << "\n" ;
}
 
int main(){
    fast() ;
    ll t = 1 ;
    cin >> t ;
    while(t--){
        solve() ;
    }
}   
