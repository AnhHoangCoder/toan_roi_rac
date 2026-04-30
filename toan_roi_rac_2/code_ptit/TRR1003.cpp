// Cho đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề.

// Yêu cầu:

// (1) Xác định bậc các đỉnh của G;

// (2) Biểu diễn G dưới dạng ma trận liên thuộc.

// Dữ liệu: Vào từ tệp DT.INP:

// - Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.

// - Dòng thứ hai chứa số nguyên dương n không vượt quá 100 là số đỉnh của G.

// - Trong n dòng tiếp theo, mỗi dòng chứa n số 0 hoặc 1 mô tả ma trận kề của G.

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

// 4

// 0 1 0 1

// 1 0 1 0

// 0 1 0 0

// 1 0 0 0

// 2 2 1 1

// Bậc của đỉnh 1 và 2 là 2, bậc của đỉnh 3 và 4 là 1.

// 2

// 4

// 0 1 0 1

// 1 0 1 0

// 0 1 0 0

// 1 0 0 0

// 4 3

// 1 1 0

// 1 0 1

// 0 0 1

// 0 1 0

// Đồ thị có 4 đỉnh và 3 cạnh (1,2), (1,4) và (2,3).

#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main(){
    freopen("DT.INP" , "r" , stdin);
    freopen("DT.OUT" , "w" , stdout);

    int t , n;
    cin >> t >> n;
    
    vector<vector<int>> a(n+1 , vector<int> (n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
        }
    }

    if(t == 1){
        for(int i=1;i<=n;i++){
            int deg = 0;
            for(int j=1;j<=n;j++){
                if(a[i][j] == 1){
                    deg++;
                }
            }
            cout << deg << " ";
        }
    }
    else{
        vector<pair<int , int>> b;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(a[i][j] == 1){
                    b.push_back({i , j});
                }
            }
        }

        int m = b.size();
        cout << n << " " << m << endl;

        vector<vector<int>> res(n+1 , vector<int> (m+1 , 0));
        for(int i=0;i<m;i++){
            int u = b[i].first;
            int v = b[i].second;

            res[u][i] = 1;
            res[v][i] = 1;
        }

        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j++){
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    cout << endl;
    return 0;
}