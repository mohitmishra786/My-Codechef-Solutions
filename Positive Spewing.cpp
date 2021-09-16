/**
 *    author:  immadmohit      
**/

#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ff first
#define ss second
#define vec vector
#define pb push_back
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll,ll>
#define pi pair<int,int>
#define mod(a,b) (a%b+b)%b
#define ceil(a,b) ((a+b-1)/b)
#define flushout cout.flush();
#define sz(x) ((int) (x).size())
#define __lcm(a,b) (a*b)/__gcd(a,b)
#define all(x) (x).begin(), (x).end()
#define vin(a) for(auto &ii : a)cin>>ii
#define f(i,a,b) for(int i=(a);i<(b);i++)
#define fr(i,a,b) for(int i=(b-1);i>=(a);i--)
#define dbg(x) cout<<'>'<< #x <<':'<< x <<endl;
#define pout(x,n) cout<<fixed<<setprecision(x)<<n
#define vout(v) for(auto ii:v)cout<<ii<<' ';cout<<endl;
const int M = 1000000007;

/* CODE STARTS HERE */

void init_code(){
    #ifndef Mohit_Mishra
        freopen("Input.txt", "r", stdin);
        freopen("Output.txt", "w", stdout);
        freopen("Error.txt", "w", stderr);
    #endif
}

void use_this_for_prime_generator(){
    bool prime[100];
    for(int i = 2; i < 100 ; i++){
        prime[i] = true;
        for(int j = 2 ; j * j <= i ; j++){
            if(i % j == 0){
                prime[i] = false;
            }
        }
    }
}


void solve(){
    //Why it has to be me
    ll n , k;cin >> n >> k;
    assert(n >= 3);
    vll arr(n);
    vll time(n);
    for(auto &e : arr){
    	cin >> e;
    }
    ll sum = accumulate(arr.begin(), arr.end() , 0LL);
    if(sum == 0){
    	cout << 0 << endl;
    	return;
    }
    ll L = -n;
    ll R = 2 * n;
    for(ll i = n - 1 ; i >= 0 ; i--){
    	if(arr[i] > 0){
    		L = -(n - i);
    		break;
    	}
    }
    for(ll i = 0 ; i < n ; i++){
    	if(arr[i] > 0){
    		L = i;
    	}
    	time[i] = i - L;
    }

    for(ll i = 0 ; i < n ; i++){
    	if(arr[i] > 0){
    		R = n + i;
    		break;
    	}

    }
    for(ll i = n - 1 ; i >= 0 ; i--){
    	if(arr[i] > 0){
    		R = i;
    	}
    	time[i] = min(time[i] , R - i);
    }
    ll ans = sum;
    for(ll i = 0 ; i < n ; i++){
    	ans+= 2 * max(0LL ,k - time[i]);
    }

    cout << ans << endl;
    
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
  //  init_code();

    int t;
    cin >> t;
    while(t--){
        solve();
    }

}
