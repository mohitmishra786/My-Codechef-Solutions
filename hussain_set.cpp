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

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init_code();

	int a , b;
	cin >> a >> b;

	ll arr[a];
	for(int i = 0 ; i < a ;i++){
		cin>>arr[i];
	}
	sort(arr , arr + a);
	queue<ll> q;

	int end_p = a - 1;

	int count_m = 0;

	while(b--){
		int curr_m;
		cin >> curr_m;
		ll ans;
		for(; count_m < curr_m ; count_m++){
			if(end_p > 0 && (q.empty() || arr[end_p] >= q.front())){
				ans = arr[end_p];
				end_p--;
			}
			else{
				ans = q.front();
				q.pop();
			}
			q.push(ans/2);
		}

		cout << ans << endl;
	}

	
}