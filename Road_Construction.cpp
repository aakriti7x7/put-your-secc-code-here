#include<bits/stdc++.h>
using namespace std;
int parent[100000];
int rank_arr[100000];
void makeSet(int n){
    int i;
    for(i=0;i<=n;i++){
        parent[i]=i;
        rank_arr[i]=1;
    }

}
int findpar(int node){
    if(node==parent[node]){
        return node;
    }
    return parent[node]=findpar(parent[node]);

}
int union_set(int u,int v){
    u=findpar(u);
    v=findpar(v);
    if(rank_arr[u]<rank_arr[v]){
        parent[u]=v;
        return rank_arr[v];
    }
    else if(rank_arr[v]<rank_arr[u]){
        parent[v]=u;
        return rank_arr[u];
    }
    else{
        parent[v]=u;
        rank_arr[u]++;
        return rank_arr[u];

    }
     
}
int merge(int a , int b){
	
	a = findpar(a);
	b = findpar(b);
	
	if(rank_arr[a] < rank_arr[b]) swap(a , b);
	
	parent[b] = a;
	rank_arr[a] += rank_arr[b];
	
	return rank_arr[a];
}
int main(){
   
    int n,m;
    cin>>n>>m;
    makeSet(n);
    int cc=n;
    int mx=1;
    while(m--){
        int a,b;
        cin>>a>>b;
        
        if(findpar(a)!=findpar(b)){
           mx=max(mx, merge(a,b));
           cc--;
        }
        cout<<cc<<" "<<mx<<endl;

    }
    }

