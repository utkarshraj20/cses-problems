//----> HARE KRISHNA <----// 

//number of ways in circular and distinct called Burnside’s Lemma
//  for( i = 1 ----->  n ) 
//     sum += (m^__gcd(i,n))/n 
        

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
    ll n , m ;
    cin >> n >> m ;
    
    ll ans = 0 ;
    
    for( ll i = 1 ; i <= n ; i++ ){
        ans = add( ans , divide( binpow( m , __gcd( i , n ) ) , n ) ) ;
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
