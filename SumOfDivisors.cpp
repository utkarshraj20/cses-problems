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

void solve()
{
    ll n ;
    cin >> n ;
    
    ll ans = 0 ;
    
    for( ll i = 1 ; i*i <= n ; i++ ){
        ll x = (n/i) ;
        ans = add( ans , x*i ) ;
        // ans = add( ans , mul(x,i) ) ;
    }

    ll l = sqrtl(n) ;
    
    for( ll i = l ; i >= 1 ; i-- ){
        ll r = (n/i) , sum = 0 ;
        ll t1 = 0 , t2 = 0 ;
        if( r&1 ){
            t1 = ( (r%mod) * (((r+1)/2)%mod) )%mod ;
        }
        else{
            t1 = ( ((r+1)%mod) * ((r/2)%mod) )%mod ;
        }
        if( l&1 ){
            t2 = ( (l%mod) * (((l+1)/2)%mod) )%mod ;
        }
        else{
            t2 = ( ((l+1)%mod) * ((l/2)%mod) )%mod ;
        }
        
        sum = ( sum%mod + t1%mod ) % mod ;
        sum = ( sum%mod - t2%mod + mod )%mod ;
        sum = ( sum%mod * i%mod  )%mod ;
        l = r ;
        ans = ( ans%mod + sum%mod )%mod ;
        
    }
    cout << ans << "\n" ;
}

int main(){
    fast() ;
    ll t = 1 ;
    // cin >> t ;
    while(t--){
        solve() ;
    }
}  
