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
#define abs				llabs
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


template<class T> istream& operator>> (istream &cin, vector<T>& arr){	for(int i=0; i<arr.size(); i++)	cin>>arr[i];	return cin;}

template<class T> ostream& operator<< (ostream &cout, vector<T>& arr){	for(int i=0; i<arr.size(); i++)	cout<<arr[i]<<" ";	cout<<"\n";	return cout;}

// template<class T1> ostream& operator<< (ostream &out, vector<T1> vec){	for(auto e: vec)	out<<e<<" ";	return out<<"\n";}
// template<class T1, class T2> ostream& operator<< (ostream &out, pair<T1, T2> pair) { return out << "(" << pair.first << ", " << pair.second << ")";}
// template<class A, class B, class C> struct Triple { 
// 	A first; B second; C third;
// 	bool operator<(const Triple& t) const { if (ff != t.ff) return ff < t.ff; if (ss != t.ss) return ss < t.ss; return tt < t.tt; }
// };
// typedef Triple<int, int, int> TIII;
// template<class A, class B, class C> ostream& operator<< (ostream &out, Triple<A, B, C> t) { return out << "(" << t.ff << ", " << t.ss << ", " << t.tt << ")"; }

ll min(ll a, ll b){
	if(a<b)	return a;
	return b;
}
ll max(ll a, ll b){
	if(a>b) return a;
	return b;
}

class Graph{
private:
	int numVertex;
	int numEdge;
	vector<vector<int>> adjList;
	vector<vector<vector<int>>> numComponent;
	int n1, n2, n3;
public:
	Graph(){
	}
	void input(){
		cin>>numVertex>>numEdge;
		cin>>n1>>n2>>n3;
		adjList.resize(numVertex+1);
		for(int i=0; i<=numVertex; i++)	adjList[i] = vector<int>(0);
		for(int i=0; i<numEdge; i++){
			int u, v;	cin>>u>>v;
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
	}

	bool dfs(int src, vector<bool>& isVisit, vector<int>& color){
		if(color[src]==0)	color[src]=1;
		isVisit[src]=1;
		for(auto e: adjList[src]){
			if(isVisit[e] && color[src] == color[e])	return 0;
			else if(isVisit[e])	continue;
			color[e] = (color[src]%2) + 1;
			if(!dfs(e, isVisit, color))	return 0;
		}
		return 1;
	}

	void disp(){
		cout<<"Vertex: "<<numVertex<<"\tEdge: "<<numEdge<<"\n";
		for(int i=1; i<=numVertex; i++){
			cout<<"Vert: "<<i<<"\t -> ";
			for(int j=0; j<adjList[i].size(); j++){
				cout<<adjList[i][j]<<"\t";
			}
			cout<<"\n";
		}
		cout<<"Number of component: \t"<<numComponent.size()<<"\n";
		for(int i=0; i<numComponent.size(); i++){
			cout<<"Component: "<< i <<"\t Part1 size: "<<numComponent[i][0].size()<<"\t Part2 size: "<<numComponent[i][1].size()<<"\n";
		}
	}

	bool util(){
		vector<bool> isVisit(numVertex+1, 0);
		for(int i=1; i<=numVertex; i++){
			if(!isVisit[i]){
				vector<int> color(numVertex+1,0);
				if(!dfs(i, isVisit, color))	return 0;
				vector<vector<int>> temp = vector<vector<int>>(2, vector<int>(0));
				vector<int> part1, part2;
				for(int i=0; i<=numVertex; i++){
					if(color[i] == 1)	part1.pb(i);
					else if(color[i] == 2)	part2.pb(i);
				}
				temp[0] = part1;
				temp[1] = part2;
				numComponent.push_back(temp);
			}
		}
		return 1;
	}

	void dpUtil(){
		vector<vector<pair<int, int>>> dp(numComponent.size(), vector<pair<int, int>>(numVertex+1,{0,0}));
		for(int i=0; i<numComponent.size(); i++){
			if(i==0){
				dp[i][numComponent[i][0].size()] = {1, -1};
				dp[i][numComponent[i][1].size()] = {2, -1};
			}	
			else{
				for(int j=1; j<=numVertex; j++){
					if(dp[i-1][j].first>0){
						dp[i][j+numComponent[i][0].size()] = {1, j};
						dp[i][j+numComponent[i][1].size()] = {2, j};
					}
				}
			}		
		}
		if(dp[numComponent.size()-1][n2].first==0)	cout<<"NO\n";
		else{
			// backtrack
			int j=0;
			vector<int> ans(numVertex+1, 0);
			for(int i=numComponent.size()-1; i>=0; i--){
				if(i==numComponent.size()-1){
					j = dp[i][n2].second;
					if(dp[i][n2].first == 2){
						for(auto e: numComponent[i][1])	ans[e]=2;
					}
					else if(dp[i][n2].first == 1){
						for(auto e: numComponent[i][0])	ans[e]=2;
					}
				}
				else{
					if(dp[i][j].first == 2){
						for(auto e: numComponent[i][1])	ans[e]=2;
					}
					else if(dp[i][j].first == 1){
						for(auto e: numComponent[i][0])	ans[e]=2;
					}
					j = dp[i][j].second;
				}
			}
			for(int i=1; i<=numVertex; i++){
				if(ans[i]==0){
					if(n1>0){	ans[i]=1;	n1--;}
					else ans[i]=3;
				}
			}
			cout<<"YES\n";
			for(int i=1; i<=numVertex; i++)	cout<<ans[i]<<"";	cout<<"\n";
		}
	}

	void dpUtil2(){
		vector<unordered_map<int, pair<int, int>>> dp(numComponent.size());
		for(int i=0; i<numComponent.size(); i++){
			if(i==0){
				dp[i][numComponent[i][0].size()] = {1, -1};
				dp[i][numComponent[i][1].size()] = {2, -1};
			}	
			else{
				for(int j=1; j<=numVertex; j++){
					if(dp[i-1][j].first>0){
						dp[i][j+numComponent[i][0].size()] = {1, j};
						dp[i][j+numComponent[i][1].size()] = {2, j};
					}
				}
			}		
		}
		return;
		if(dp[numComponent.size()-1][n2].first==0)	cout<<"NO\n";
		else{
			// backtrack
			int j=0;
			vector<int> ans(numVertex+1, 0);
			for(int i=numComponent.size()-1; i>=0; i--){
				if(i==numComponent.size()-1){
					j = dp[i][n2].second;
					if(dp[i][n2].first == 2){
						for(auto e: numComponent[i][1])	ans[e]=2;
					}
					else if(dp[i][n2].first == 1){
						for(auto e: numComponent[i][0])	ans[e]=2;
					}
				}
				else{
					if(dp[i][j].first == 2){
						for(auto e: numComponent[i][1])	ans[e]=2;
					}
					else if(dp[i][j].first == 1){
						for(auto e: numComponent[i][0])	ans[e]=2;
					}
					j = dp[i][j].second;
				}
			}
			for(int i=1; i<=numVertex; i++){
				if(ans[i]==0){
					if(n1>0){	ans[i]=1;	n1--;}
					else ans[i]=3;
				}
			}
			cout<<"YES\n";
			for(int i=1; i<=numVertex; i++)	cout<<ans[i]<<"";	cout<<"\n";
		}
	}

	void solve(){
		input();
		if(!util()){	cout<<"NO\n";	return;}		
		// disp();
		dpUtil2();
	}
};

void solve(){
	Graph obj;
	obj.solve();
}

int32_t main(){
	fastio;
	// ll testCases;	cin>>testCases;
	// for(int i=1; i<=testCases; i++){
		// cout<<i<<" ";
		// cout<<solve()<<"\n";
		solve();
	// }	
	return 0;
}