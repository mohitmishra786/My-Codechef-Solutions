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

ll kadane(vll v){
    ll max_till_now = 0;
    ll cme = INT_MIN;

    for(int i = 0; i < v.size();i++){
    	cme += v[i];

    	if(cme > max_till_now){
    		max_till_now = cme;
    	}
    	if(cme  < 0){
    		cme = 0;
    	}
    }

    return max_till_now;

}

ll maxSubArraySum(vll v , int k){
	ll kadaneSum = kadane(v);
	if(k == 1){
		return kadaneSum;
	}
	
	ll curprefsum = 0 ; ll cursuffsum = 0;
	ll maxprefsum = INT_MIN ; ll maxsuffsum = INT_MIN;

	for(int i = 0 ; i< v.size() ; i++){
		curprefsum += v[i];
		maxprefsum = max(curprefsum, maxprefsum);
	}
	ll totalsum = curprefsum;


	for(int i = 0 ; i < v.size() ; i++){
		cursuffsum += v[i];
		maxsuffsum = max(cursuffsum, maxsuffsum);
	}
	ll ans;
	if(kadaneSum < 0){
		ans =  max(maxprefsum + maxsuffsum , kadaneSum);
	}
	else{
		ans =  max(maxprefsum + maxsuffsum  + totalsum * (k-2) , kadaneSum);
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);int tc=1;
	int t;
	cin >> t;
	while(t--){
		int n , k;
		cin >> n >> k;
		vll v;
		int z;
		while(n--){
			cin >> z ;
			v.push_back(z);
		}
		ll sol = maxSubArraySum(v , k);

		cout << sol << endl;
	}
}