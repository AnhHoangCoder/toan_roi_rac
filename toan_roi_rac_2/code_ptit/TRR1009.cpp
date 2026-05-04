// Cho đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng danh sách kề.

// Yêu cầu:

// (1) Xác định bậc các đỉnh của G;

// (2) Biểu diễn G dưới dạng danh sách cạnh.

// Dữ liệu: Vào từ tệp DT.INP:

// - Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.

// - Dòng thứ hai chứa hai số nguyên n là số đỉnh của G. Trong đó, 1 £ n £ 100.

// - Trong n dòng tiếp theo, mỗi dòng thứ i (1 £ i £ n) chứa số tự nhiên k là số lương đỉnh kề với đỉnh i và k số tự nhiên theo thứ tự tăng v1, …, vk là số hiệu các đỉnh kề tương ứng. 

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

// 4

// 2 2 4

// 2 1 3

// 1 2

// 1 1

// 4 3

// 1 1 0

// 1 0 1

// 0 0 1

// 0 1 0

// Đồ thị có 4 đỉnh và 3 cạnh (1,2), (1,4) và (2,3).

#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t , n;
    cin >> t;
    cin >> n;

    vector<int> deg(n+1 , 0);
    set<pair<int,int>> st;    

    for(int i=1;i<=n;i++){
        int k;
        cin >> k;
        deg[i] = k;
        while(k--){
            int v;
            cin >> v;
            if(i == v) continue;
            st.insert({min(i , v) , max(i , v)});
        }
    }

    if(t == 1){
        for(int i=1;i<=n;i++){
            cout << deg[i] << " ";
        }
    }
    else{
        int m = st.size();
        cout << n << " " << m << endl;
        vector<vector<int>> res(n+1 , vector<int> (m+1 , 0));

        int idx = 1;
        for(auto x : st){
            int u = x.first;
            int v = x.second;

            res[u][idx] = 1;
            res[v][idx] = 1;
            idx++;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}