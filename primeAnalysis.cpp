//----> HARE KRISHNA <----// 

// number given in form of (x,k) x is a prime and k is its power

// number of factors = (k1+1)*(k2+1)*..........................

// sum of products = ( x^0 + x^1 + .......... + x^k ) * ( x1^0 + x1^1 + ....... + x1^k1 ) * ...........................
                   = (( x^(k+1) )-1)/(x-1) + (( x1^(k1+1) )-1)/(x1-1) + ............................

// product of products = ( number ) ^ ( d( number )/2 )



#include <bits/stdc++.h>

using namespace std;

#define ll long long 
#define ff first 
#define ss second
const ll mod = 1e9+7 , mod1 = mod-1 ;
     
void fast(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

ll power(ll a, ll b)
{
    if(b==0)
        return 1;
    if(b==1)
        return a;
    if(b%2 == 1)
        return (power(a,b-1)*a)%mod;
    ll q = power(a,b/2);
    return (q*q)%mod;
}

ll add(ll x, ll y)
{
    return ((x + y) % mod + mod) % mod;
}

int mul(ll x, ll y)
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
    ll n ;
    cin >> n ;
    
    vector<pair<ll, ll>> vp ;
    
    ll totFac = 1 ;
    ll sum = 1 ;
    
    for( ll i = 0 ; i < n ; i++ ){
        ll x , k ;
        cin >> x >> k ;
        vp.push_back({x,k}) ;
        totFac = ( totFac%mod * (k+1)%mod ) %mod ;
        ll tmp = power( x , k+1 ) - 1 ;
        
        tmp = divide( tmp , x-1 ) ;
        
        sum = ( sum%mod * tmp%mod ) % mod ;
    }
    
    cout << totFac << " " << sum << " " ;
    
    ll ans = 1 ;
    ll num1 = 1 ;
    bool f = 1 ;
    for( ll i = 0 ; i < n ; i++ ){
        if( vp[i].ss&1 && f ){
            num1 *= (vp[i].ss+1)/2 ;
            num1 %= mod1 ;
            f = 0 ;
        }
        else{
            num1 *= (vp[i].ss+1) ;
            num1 %= mod1 ;
        }
    }
    
    if( f ){
        for( ll i = 0 ; i < n ; i++ ){
            vp[i].ss /= 2 ;
        }
    }
    
    ll number = 1 ;
    
    for( ll i = 0 ; i < n ; i++ ){
        number *= power( vp[i].ff , vp[i].ss ) ;
        number %= mod ;
    }
    
    ans = power( number , num1 ) ;
    
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
