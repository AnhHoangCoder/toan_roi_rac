// Cho đồ thị vô hướng có trọng số G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận trọng số.

// Yêu cầu:

// (1) Xác định bậc các đỉnh của G;

// (2) Biểu diễn G dưới dạng danh sách cạnh với trọng số.

// Dữ liệu: Vào từ tệp DT.INP:

// - Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.

// - Dòng thứ hai chứa số nguyên dương n không vượt quá 100 là số đỉnh của G.

// - Trong n dòng tiếp theo, mỗi dòng thứ i (1 £ i £ n) chứa n số tự nhiên c[i][j] (1 £ j £ n) mô tả ma trận trọng số của G. Trong đó, với hai đỉnh i, j (i khác j) có cạnh nối thì 0 < c[i][j] £ 50, nếu không có cạnh nối thì c[i][j] = 10000 và c[i][i] = 0.

// Kết quả: Ghi ra tệp DT.OUT:

// - Nếu t = 1 thì ghi ra một dòng gồm n số tự nhiên tương ứng là bậc của n đỉnh.

// - Nếu t = 2 thì ghi ra theo qui cách:

// + Dòng đầu ghi ra hai số tự nhiên n và m là số đỉnh và số cạnh của G.

// + Trong m dòng tiếp theo, mỗi dòng thứ i (1 £ i £ m) ghi ba số ui, vi, wi là đỉnh đầu, đỉnh cuối và trọng số của cạnh ei. Các cạnh của G được đánh số theo thứ tự từ điển.

// Ví dụ:

// DT.INP

// DT.OUT

// Giải thích

// 1

// 4

// 0 1 10000 2

// 1 0 3 10000

// 10000 3 0 0

// 2 10000 10000 0

// 2 2 1 1

// Bậc của đỉnh 1 và 2 là 2, bậc của đỉnh 3 và 4 là 1.

// 2

// 4

// 0 1 10000 2

// 1 0 3 10000

// 10000 3 0 0

// 2 10000 10000 0

// 4 3

// 1 2 1

// 1 4 2

// 2 3 3

// Đồ thị có 3 cạnh (1,2), (1,4) và (2,3) với trọng số tương ứng là 1, 2, 3.

#include <iostream>
#include <cstdio>
#include <vector>
#include <tuple>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("DT.INP" , "r" , stdin);
    freopen("DT.OUT" , "w" , stdout);

    const int tmp = 10000;
    int t , n;
    cin >> t >> n;
    vector<vector<int>> c(n+1 , vector<int> (n+1 , 0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> c[i][j];
        }
    }

    if(t == 1){
        for(int i=1;i<=n;i++){
            int deg = 0;
            for(int j=1;j<=n;j++){
                if(i != j && c[i][j] != tmp && c[i][j] != 0){
                    deg++;
                }
            }
            cout << deg << " ";
        }
    }
    else{
        vector<tuple<int,int,int>> edges;

        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(c[i][j] != tmp && c[i][j] != 0){
                    edges.push_back({i , j , c[i][j]});
                }
            }
        }

        cout << n << " " << edges.size() << endl;
        for(auto [u , v , w] : edges){
            cout << u << " " << v << " " << w << endl;
        }
    }
    return 0;
}