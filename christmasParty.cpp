//----> HARE KRISHNA <----// 

// a permutation of the elements of a set in which no element appears in its original position.
// called dearrangement
// d[n] = ( d[n-1] * d[n-2] ) * (n-1)

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

void solve()
{
    ll n ;
    cin >> n ;
    
    ll d[n+1]{} ;
    d[0] = 1 ;
    
    for( ll i = 2 ; i <= n ; i++ ){
        d[i] = add( d[i-1] , d[i-2] ) ;
        d[i] = mul( d[i] , i-1 ) ;
    }
    
    cout << d[n] << "\n";
    
}

int main(){
    fast() ;
    ll t = 1 ;
    // cin >> t ;
    while(t--){
        solve() ;
    }
}    
