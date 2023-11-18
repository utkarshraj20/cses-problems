//----> HARE KRISHNA <----// 

// number of valid bracket sequences 
// dp[n] = from i = 0 to n-1 ( dp[i] * dp[n-1-i] )
// (nCn/2)*(1/n+1)*k^n where k is number of types of brackets 

// if initially K backets are open that we have to close and n denotes remaining pair ,
// Number of ways = ((k+1)/(n+k+1)) * (2*n+k)Cn

#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ff first 
#define ss second
const ll mod = 1e9+7 , N = 2e6+10 ;
     
void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll add(ll x, ll y)
{
    return ((x + y) % mod + mod) % mod;
}

ll mul(ll x, ll y)
{
    return x * 1ll * y % mod ;   
}

ll binpow(ll x, ll y)
{
    ll z = 1;
    while(y)
    {
        if(y % 2 == 1) z = mul(z, x);
        x = mul(x, x);
        y /= 2;
    }
    return z;
}

ll inv(ll x)
{
    return binpow(x, mod - 2);    
}

ll divide(ll x, ll y)
{
    return mul(x, inv(y));
}

void solve()
{
    vector<ll> fact(N,1) ;
    for( ll i = 2 ; i < N ; i++ ){
        fact[i] = mul( fact[i-1] , i ) ;
    }
    
    ll n ;
    cin >> n ;
    
    if( n&1 ){
        cout << 0 << "\n" ;
        return ;
    }
    
    ll ans = fact[n] ;
    
    n /= 2 ;
    
    ans = divide( ans , fact[n] ) ;
    
    ans = divide( ans , fact[n] ) ;
    
    ans = divide( ans , n+1 ) ;
    
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
