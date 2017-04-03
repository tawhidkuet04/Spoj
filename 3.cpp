#include<bits/stdc++.h>
#define ll long long 
using namespace std ;
const int mx = 1000000+ 100 ;
ll mod = 1000000007 ;
ll fact [ mx ] ;
ll mod_inv[ mx ] ;

ll bigMod(ll n,ll power,ll MOD)
{
    if(power==0)
        return 1;
    if(power%2==0)
    {
        ll ret=bigMod(n,power/2,MOD);
        return ((ret%MOD)*(ret%MOD))%MOD;
    }
    else return ((n%MOD)*(bigMod(n,power-1,MOD)%MOD))%MOD;
}

ll modInverse(ll n,ll MOD)
{
    return bigMod(n,MOD-2,MOD);
}

void factorial ( ){
 
    fact[0]=1;
    mod_inv[0]=modInverse(fact[0],mod)%mod;
    for(ll i=1;i<= 1000000;i++)
    {
        fact[i]=(fact[i-1] * i)%mod;
        mod_inv[i]=modInverse(fact[i],mod)%mod;
    }
 
}
 

 
int main(int argc, char const *argv[])
{
    int t , l = 1 ;
    factorial();
    scanf("%d",&t);
    while ( t -- ){
        ll x1,x2,y1,y2;
        scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
        ll row = abs ( x1 - x2 ) + 1 ;
        ll col = abs ( y1 -y2 ) + 1 ;
        ll tot = row - 1 + col - 1 ;
        ll a = ( fact [ tot ] % mod * mod_inv[ row - 1 ] ) % mod ;
        a = ( a % mod * mod_inv [ col - 1 ] % mod ) % mod ;
        ll corno = min ( row , col ) - 1 ;
        for( ll i = corno ; i >= 1  ; i -- ){

            ll x = ( fact[ col - 1 - i + row - 1 - i + i  ] % mod * mod_inv [ row - 1 - i ] % mod ) % mod ;
            x= ( x % mod * mod_inv [ col - 1 - i ]  % mod ) % mod ;
            x = ( x % mod * mod_inv [ i ] % mod ) % mod ;
            a = (a %  mod + x % mod ) % mod ;
        }
        printf("Case %d: %lld\n", l ++ , ( a + mod ) % mod );
    }
 
    return 0;
} 