/**
 * Description: Tarjan's Algorithm, generate SCCs in topological order. 
 * Time: O(N+M)
 * Source: KACTL
 	* https://github.com/kth-competitive-programming/kactl/blob/master/content/graph/SCC.h
 * Verification: https://cses.fi/problemset/task/1686/
 */

 template<int SZ> struct SCC {
	vi adj[SZ], allComp, st; 	
	int N, val[SZ], comp[SZ];
	void ae(int u, int v) { adj[u].pb(v); }
	int dfs(int u) {
		static int ti = 0; int low = val[u] = ++ti; st.pb(u);
		trav(i,adj[u]) if (comp[i] < 0) ckmin(low,val[i]?:dfs(i));
		if (low == val[u]) {
			allComp.pb(u); int x; 
			do { comp[x=st.bk] = u; st.pop_back(); } while (x!=u);
		}
		return val[u] = low;
	}
	void init(int _N) {
		N = _N; F0R(i,N) val[i] = 0, comp[i] = -1;
		F0R(i,N) if (comp[i] < 0) dfs(i);
		reverse(all(allComp));
	}
};