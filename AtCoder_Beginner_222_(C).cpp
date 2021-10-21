///Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define ld long double
#define pll pair<ll, ll>
#define vpp vector<pair<ll, ll>>
#define pb push_back
#define ff first
#define ss second
#define case_(tc) cout << "Case " << tc << ": ";
#define mem(a, b) memset(a, b, sizeof(a))
#define all(vtor) vtor.begin(), vtor.end()
#define rall(vtor) vtor.rbegin(), vtor.rend()

#define pi 2 * acos(0.0)
#define tani(a) atan(a) / (pi / 180)
#define sini(a) asin(a) / (pi / 180)
#define cosi(a) cos(a) / (pi / 180)
#define cos(a) cos(a *pi / 180)
#define sin(a) sin(a *pi / 180)
#define tan(a) tan(a *pi / 180)
const ll mod = 1e9 + 7;

#define YES cout << "YES" << endl;
#define NO cout << "NO" << endl;

#define EPS 1e-13
#define maxii 32000
ll Pow(ll c, ll d)
{
    return d == 0 ? 1 : c * pow(c, d - 1);
}
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return ((a * b) / gcd(a, b)); }

ll egcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return gcd;
}
ll bigMod(ll a, ll b)
{
    a %= mod;
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

inline ll MOD(ll a) { return (a % mod + mod) % mod; }
inline ll modAdd(ll a, ll b) { return MOD(MOD(a) + MOD(b)); }
inline ll modSub(ll a, ll b) { return MOD(MOD(a) - MOD(b)); }
inline ll modMul(ll a, ll b) { return MOD(MOD(a) * MOD(b)); }
inline ll modInv(ll a) { return bigMod(a, mod - 2); }
inline ll modDiv(ll a, ll b)
{
    a = MOD(a);
    b = modInv(b);
    return (a * b) % mod;
}

vector<string> v;
map<char, ll> mp;

set<string> vs;

void permute(string str, string out)
{
    // When size of str becomes 0, out has a
    // permutation (length of out is n)
    if (str.size() == 0)
    {
        vs.insert(out);
        return;
    }

    // One be one move all characters at
    // the beginning of out (or result)
    for (int i = 0; i < str.size(); i++)
    {
        // Remove first character from str and
        // add it to out
        permute(str.substr(1), out + str[0]);

        // Rotate string in a way second character
        // moves to the beginning.
        rotate(str.begin(), str.begin() + 1, str.end());
    }
}
bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
ll ncr(ll nn, ll rr)
{
    if (rr > nn)
        return 0;
    if (rr == 0)
        return 1;
    if (rr == 1)
        return nn;
    if (nn == rr)
        return 1;
    return ncr(nn - 1, rr - 1) + ncr(nn - 1, rr);
}
bool compare(pair<ll, ll> p1, pair<ll, ll> p2)
{
    if(p1.ss==p2.ss)
    return p1.ff<p2.ff;
    else
    return p1.ss>p2.ss;
}
vector<ll>get(map<ll,ll>&mp)
{
    vpp vec;

    // in map 
    ///{player ID, number of wins}
    for(auto it: mp)
    vec.pb(it);
  
    sort(vec.begin(),vec.end(),compare);
    
    vector<ll>rank;
    for(auto it: vec)
    rank.pb(it.first);

    return rank;
}

int main()
{
    // ll c=0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll n,m;
    cin>>n>>m;
    string str[2*n+1];
    for(ll i=1;i<=2*n;i++)
    cin>>str[i];

    map<ll,ll>mp;
    for(ll i=1;i<=2*n;i++)
    mp[i] = 0;
    vpp vpair;
    for(ll i=1;i<=m;i++)
    {
        vector<ll>rank = get(mp);
        for(ll j=1;j<2*n;j+=2)
        {
            if(str[rank[j-1]][i-1]=='G' and str[rank[j]][i-1]=='P')
             {
                 mp[rank[j]]++;
             }
            else if(str[rank[j-1]][i-1]=='G' and str[rank[j]][i-1]=='C')
            {
                mp[rank[j-1]]++;
            }
            else if(str[rank[j-1]][i-1]=='P' and str[rank[j]][i-1]=='G')
            {
               mp[rank[j-1]]++;
            }
            else if(str[rank[j-1]][i-1]=='P' and str[rank[j]][i-1]=='C')
            {
                mp[rank[j]]++;
            }
            else if(str[rank[j-1]][i-1]=='C' and str[rank[j]][i-1]=='G')
            {
               mp[rank[j]]++;
            }
            else if(str[rank[j-1]][i-1]=='C' and str[rank[j]][i-1]=='P')
            {
              mp[rank[j-1]]++;
            }
            // else if(str[rank[j-1]][i-1]=='C' and str[rank[j]][i-1]=='C')
            // {
            //     mp[rank[j-1]]++;
            // }
            // else if(str[rank[j-1]][i-1]=='G' and str[rank[j]][i-1]=='G')
            // {
            //      mp[rank[j-1]]++;
            // }
            // else if(str[rank[j-1]][i-1]=='P' and str[rank[j]][i-1]=='P')
            // {
            //     mp[rank[j-1]]++;
            // }
        }
    }
    vector<ll>final_rank = get(mp);
    for(auto it: final_rank)
    cout<<it<<endl;
    
    
    
    return 0;
}
//1000000007
