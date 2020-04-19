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

#define int 			long long
#define fastio 			{ios_base::sync_with_stdio(false); cin.tie(NULL);}
#define ff				first
#define ss 				second
#define tt 				third
#define pb				push_back
#define pqmax           priority_queue<ll>
#define pqmin           priority_queue<ll,vector<ll>,greater<ll> >
#define setbits(x)      __builtin_popcountll(x)
#define firstLeftBitIdx(x) 32-__builtin_clz(x)
#define mod             1000000007
#define PI 				3.1415926535897932384626
#define inf             1e18
#define N             	1e6
#define ps(x,y)         fixed<<setprecision(y)<<x
#define FOR(i, a, b) 	for(int i =(a); i <=(b); ++i)
#define FORR(i, a, b) 	for(int i = (a); i >= (b); --i)
#define FORZ(i, n) 		for(int i = 0;i <(n); ++i)
#define FORO(i, n) 		FOR(i, 1, n)
#define ALL(x) 			(x).begin(), (x).end()
#define SZ(x) 			((int)(x).size())


using namespace std;

typedef long long ll;
typedef long double LD;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VLL;
typedef vector<pair<int, int> > VPII;
typedef vector<pair<ll, ll> > VPLL;
typedef Triple<int, int, int> TIII;

template<class T1> ostream& operator<< (ostream &out, vector<T1> vec){	for(auto e: vec)	out<<e<<" ";	return out<<"\n";}
template<class T1, class T2> ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
template<class A, class B, class C> struct Triple { 
	A first; B second; C third;
	bool operator<(const Triple& t) const { if (st != t.st) return st < t.st; if (nd != t.nd) return nd < t.nd; return rd < t.rd; }
};
template<class A, class B, class C> ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.st << ", " << t.nd << ", " << t.rd << ")"; }

ll min(ll a, ll b){
	if(a<b)	return a;
	return b;
}
ll max(ll a, ll b){
	if(a>b) return a;
	return b;
}

void solve(){
	
}

int32_t main(){
	fastio;
	ll testCases;	cin>>testCases;
	for(int i=1; i<=testCases; i++){
		// cout<<i<<" ";
		solve();
	}	
	return 0;
}