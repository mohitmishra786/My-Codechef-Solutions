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
char getChars(int i){
	return (char)(i + 97);
}


void palindrome_permutation(string s){
	map<char,vector<int>> mp;


	for(int i=0; i<s.length(); i++){
		mp[s[i]].push_back(i);
	}

	int arr[s.length()];
	int start = 0;
	int end = s.length() - 1;
	int odd_freq = 0;
	for(int i = 0 ; i < 26 ; i++){
		if((mp[getChars(i)].size() % 2) != 0 ){
			odd_freq++;
		}
	}

	if(odd_freq >= 2){
		cout << "-1" ;
		return;
	}

	for(int i = 0 ; i < 26 ; i++){
		char char_getter = getChars(i);
		for(int j = 0 ; j < mp[char_getter].size(); j+= 2){
			if((mp[char_getter].size() - j) == 1){
				arr[s.length()/2] = mp[char_getter][j];
				continue;
			}

			arr[start] = mp[char_getter][j];
			arr[end] = mp[char_getter][j+1];
			start++;
			end--;

		}
	}

	for(int i = 0 ;i <s.length() ; i++){
		cout << arr[i] + 1 << " ";
	}
	return;
}
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	init_code();

	int t;
	cin >> t;

	while(t--){
		string s;
		cin >> s;
		palindrome_permutation(s);
		cout << endl;
	}
	
}