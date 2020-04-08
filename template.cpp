/************ ALL HEADER FILE ***********/
/************ Created by Aditya Mudgil ***********/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <cstdio>

#define fastio 			{ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define ff				first
#define ss 				second
#define pb				push_back
#define pqmax           priority_queue<ll>
#define pqmin           priority_queue<ll,vector<ll>,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define mod             1000000007
#define PI 				3.1415926535897932384626
#define inf             1e18
#define N             	1e6
#define ps(x,y)         fixed<<setprecision(y)<<x

using namespace std;
using ll = long long;

ll min(ll a, ll b){
	if(a<b)	return a;
	return b;
}

void solve(){
	
}

int main(){
	fastio;
	ll testCases;	cin>>testCases;
	for(int i=1; i<=testCases; i++){
		// cout<<i<<" ";
		solve();
	}	
	return 0;
}