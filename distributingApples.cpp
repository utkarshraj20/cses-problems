//----> HARE KRISHNA <----// 

// distributing m identicals balls into n children 
// ( x1+x2+x3+.......+xn ) = m 
// for non-negative integrals solution = ( ( n + m - 1 )! / ((n-1)! * m!) ) 

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
    
    ll n , m ;
    cin >> n >> m ;
    
    ll ans = fact[n+m-1] ;
    
    ans = divide( ans , fact[n-1] ) ;
    
    ans = divide( ans , fact[m] ) ;
    
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
