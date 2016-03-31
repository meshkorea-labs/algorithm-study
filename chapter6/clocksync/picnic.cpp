#include <stdio.h>
int n, m;
bool adj[12][12];
int partner[12];
int back(int p){
	if (p >= n){
		return 1;
	}
	if (partner[p] != -1) return back(p + 1);
	int ret = 0;
	for (int i = 0; i < n; i++){
		if (adj[p][i] && partner[i] == -1){
			partner[p] = i;
			partner[i] = p;
			ret += back(p + 1);
			partner[p] = partner[i] = -1;
		}
	}
	return ret;
}
int main(){
	int C;
	//freopen("input.txt", "r", stdin);
	scanf("%d", &C);
	for (int testcase = 0; testcase < C; testcase++){
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++){
			partner[i] = -1;
			for (int j = 0; j < n; j++) adj[i][j] = false;
		}
		for (int i = 0; i < m; i++){
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a][b] = adj[b][a] = true;
		}
		printf("%d\n", back(0));
	}
	return 0;
}
