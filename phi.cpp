vector<int> phi(n+1);
for(int i = 1; i <= n; i++){
    phi[i] += i;
    for(int j = 2*i; j <= n; j += i){
        phi[j] -= phi[i];
    }
}
