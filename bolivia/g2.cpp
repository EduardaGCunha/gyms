// ... sua struct SegTree inalterada ...

// 3. Mova a SegTree para o escopo global!
SegTree seg;

signed main(){
    fastio; // Não esqueça de chamar o fastio
    
    int n; cin >> n;
    vector<int> arr(n);
    // vector<vector<int>> fatores; // Não precisa mais disso!
    
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    seg.init(n, arr);

    int q; cin >> q;
    while(q--){
        int op; cin >> op;
        if(op == 1){
            int pos; cin >> pos;
            pos--;
            int v = seg.queryf(pos, pos);
            
            // 1. Proteção contra Segfault de vetor vazio
            if (v > 1) { 
                auto [p, sum] = factor(v);
                int x = p.back(); // Pega o maior fator
                v /= x; // Remove ele do valor base
                seg.update(pos, pos, v);
            }
        }else if(op == 2){
            int l, r; cin >> l >> r;
            l--, r--;
            cout << seg.querys(l, r) << endl;
        }else{
            int l, r, x; cin >> l >> r >> x;
            l--, r--;
            
            // 2. Passar o VALOR X direto, a SegTree cuida da fatoração
            seg.update(l, r, x); 
        }
    }
    
    return 0;
}