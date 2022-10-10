Euler Tour

Flattening the tree to apply RQU(range query update)

given = input taken by user (array)
   		1 0 3 1 1 2 3 0 1 (1-based)

   		1 2 3 4 5 6 7 8 9
start   1 2 7 3 4 8 9 5 6
end     9 6 9 3 6 8 9 5 6
-------------------------------
trav    1 2 4 5 8 9 3 6 7
final   1 0 1 1 0 1 3 2 3 (array to be used in the segTree)


query -> update the 5-th idx


   EQUATION           EQ ka MTLB
trav[trav[1]] = 1  => trav[1] = 1
trav[trav[2]] = 2  => trav[2] = 2
trav[trav[3]] = 3  => trav[4] = 3
trav[trav[4]] = 4  => trav[5] = 4
trav[trav[5]] = 5  => trav[8] = 5
trav[trav[6]] = 6  => trav[9] = 6
trav[trav[7]] = 7  => trav[3] = 7
trav[trav[8]] = 8  => trav[6] = 8
trav[trav[9]] = 9  => trav[7] =

FOR 1 to N => trav[trav[i]] = i





1 2 3 4 5 6 7 8 9
1 2 4 5 8 9 3 6 7


//0-based
int tym = 0
void dfs(int s, int p){
	start[s] = tym++;
	trav.push_back(s);
	for(auto i:adj[s])
		if(i != p)
			dfs(i, s);
	end[s] = tym-1;
}

//1-based
int tym = 0
void dfs(int s, int p){
	start[s] = ++tym;
	for(auto i:adj[s])
		if(i != p)
			dfs(i, s);
	end[s] = tym;
}



while(query--){
	string q;
	cin >> q;
	if(q == "update"){
		cin >> idx >> val; 
		--idx; //making it 0-based
		idx = trav[idx];
		Update(0, n-1, 0, idx, val);
	}
	if(q == "Query-sum"){
		cin >> l >> r;
		--l , --r;
		cout << Query(0, n-1, 0, l, r);
	}
}
