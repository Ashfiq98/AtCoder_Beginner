/// Bismillahir Rahmanir Rahim
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

bool isPrime(ll n)
{
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
bool compare(pair<ll, pair<ll, ll>> p1, pair<ll, pair<ll, ll>> p2)
{
    if (p1.ff == p2.ff)
        return p1.ss.ff < p2.ss.ff;
    else
        return p1.ff < p2.ff;
}
vector<ll> v;
void div(ll n)
{
    ll sum = 0;
    n = n / 2;
    for (ll x = 1; x <= n; x++)
    {
        ll cnt = 0;
        for (ll i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                cnt++;
                // v.push_back(i);
                //  cout<<i<<endl;
                ll k;
                k = x / i;
                if (k != i)
                {
                    // cout<<k<<endl;
                    // v.push_back(k);
                    cnt++;
                }
            }
        }
        ++cnt;
        sum += cnt;
        // sort(v.begin(),v.end());
        // for(ll i=0;i<v.size();i++)
        // cout<<v[i]<<endl;
    }

    cout << sum << endl;
}
void sieve(ll n)
{
    ll flag[n + 1];
    vector<ll> prime;

    for (ll i = 1; i <= n; i++)
        flag[i] = 1;

    flag[1] = 0;

    for (ll i = 2; i * i <= n; i++)
    {
        if (flag[i] == 1)
        {
            for (ll j = i * i; j <= n; j = j + i)
                flag[j] = 0;
        }
    }
    for (ll i = 1; i <= n; i++)
    {
        if (flag[i] == 1)
        {
            prime.push_back(i);
            //        cout << i <<endl;
        }
    }
    sort(prime.begin(), prime.end());
    cout << prime.size() << endl;

    for (auto it : prime)
        cout << it << " ";
    cout << endl;
}

int main()
{
    // ll c=0;
    //      #ifndef ONLINE_JUDGE
    //     freopen("D:/Code_c++/input.txt", "r", stdin);
    //     freopen("D:/Code_c++/output.o", "w", stdout);
    //    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    // cin >> t;
    t = 1;
    vector<pair<ld, ld>> vpair;
    vector<ll> v;
    for (ll j = 1; j <= t; j++)
    {
        ll n,k;
        cin>>n>>k;
        priority_queue<ll> p; 
        vector<ll> v(n);       
        for(ll i=0;i<n;i++)
        {
          cin>>v[i];
          if(i<k)
          p.push(v[i]*(-1));
        }
        for(ll i=k;i<=n;i++)
        {
            cout<<p.top()*(-1)<<endl;
            if(v[i]>p.top()*-1)
            {
                p.pop();
              p.push(v[i]*-1);
            }
        }
        
    }
    return 0;
}