// Cho đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng danh sách cạnh.

// Yêu cầu:

// (1) Xác định bậc các đỉnh của G;

// (2) Biểu diễn G dưới dạng ma trận liên thuộc.

// Dữ liệu: Vào từ tệp DT.INP:

// - Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.

// - Dòng thứ hai chứa hai số nguyên n là số đỉnh và m là số cạnh của G. Trong đó, 1 £ n £ 100 và 1 £ m £ n(n-1)/2.

// - Trong m dòng tiếp theo, mỗi dòng thứ i (1 £ i £ m) chứa hai số nguyên ui, vi là đỉnh đầu và đỉnh cuối của cạnh ei. Trong đó, 1 £ ui < vi £ n; Các cạnh của G được liệt kê theo thứ tự từ điển.

// Kết quả: Ghi ra tệp DT.OUT:

// - Nếu t = 1 thì ghi ra một dòng gồm n số tự nhiên tương ứng là bậc của n đỉnh.

// - Nếu t = 2 thì ghi ra n+1 dòng:

// + Dòng đầu ghi ra hai số tự nhiên n và m là số hàng và số cột của ma trận liên thuộc.

// + Trong n dòng tiếp theo, mỗi dòng ghi m số 0 hoặc 1 mô tả ma trận liên thuộc tìm được. Các cạnh của G được đánh số theo thứ tự từ điển.

// Ví dụ:

// DT.INP

// DT.OUT

// Giải thích

// 1

// 4 3

// 1 2

// 1 4

// 2 3

// 2 2 1 1

// Bậc của đỉnh 1 và 2 là 2, bậc của đỉnh 3 và 4 là 1.

// 2

// 4 3

// 1 2

// 1 4

// 2 3

// 4 3

// 1 1 0

// 1 0 1

// 0 0 1

// 0 1 0

// Đồ thị có 4 đỉnh và 3 cạnh (1,2), (1,4) và (2,3).

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("DT.INP" , "r" , stdin);
    freopen("DT.OUT" , "w" , stdout);

    int t , n , m;
    cin >> t >> n >> m;
    vector<pair<int,int>> res;
    vector<int> a[101];
    while(m--){
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        res.push_back({u , v});
    }
    if(t == 1){
        for(int i=1;i<=n;i++){
            cout << a[i].size() << " ";
        }
    }
    else{
        cout << n << " " << res.size() << endl;
        vector<vector<int>> ans(n+1 , vector<int> (res.size() + 1 , 0));
        for(int k=0;k<res.size();k++){
            int u = res[k].first;
            int v = res[k].second;

            ans[u][k] = 1;
            ans[v][k] = 1;
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<res.size();j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}