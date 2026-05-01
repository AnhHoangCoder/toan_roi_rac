// Cho đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng danh sách cạnh.

// Yêu cầu:

// (1) Xác định bậc các đỉnh của G;

// (2) Biểu diễn G dưới dạng ma trận kề.

// Dữ liệu: Vào từ tệp DT.INP:

// - Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.

// - Dòng thứ hai chứa hai số nguyên n là số đỉnh và m là số cạnh của G. Trong đó, 1 £ n £ 100 và 1 £ m £ n(n-1)/2.

// - Trong m dòng tiếp theo, mỗi dòng thứ i (1 £ i £ m) chứa hai số nguyên ui, vi là đỉnh đầu và đỉnh cuối của cạnh ei. Trong đó, 1 £ ui < vi £ n.

// Kết quả: Ghi ra tệp DT.OUT:

// - Nếu t = 1 thì ghi ra một dòng gồm n số tự nhiên tương ứng là bậc của n đỉnh.

// - Nếu t = 2 thì ghi ra n+1 dòng:

// + Dòng đầu ghi ra số tự nhiên n là bậc của ma trận kề.

// + Trong n dòng tiếp theo, mỗi dòng ghi n số 0 hoặc 1 mô tả ma trận kề tìm được.

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

// 4

// 0 1 0 1

// 1 0 1 0

// 0 1 0 0

// 1 0 0 0

// Đồ thị có 4 đỉnh và 3 cạnh (1,2), (1,4) và (2,3).

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

ifstream fin("DT.INP");
ofstream fout("DT.OUT");

void testCase(){
    int t , n , m;
    fin >> t >> n >> m;
    vector<vector<int>> a(n+1 , vector<int> (n+1 , 0));
    while(m--){
        int u , v;
        fin >> u >> v;
        a[u][v] = 1;
        a[v][u] = 1;
    }

    if(t == 1){
        for(int i=1;i<=n;i++){
            int res = 0;
            for(int j=1;j<=n;j++){
                if(a[i][j] == 1){
                    res++;
                }
            }
            fout << res << " ";
        }
    }
    else{
        fout << n << endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                fout << a[i][j] << " ";
            }
            fout << endl;
        }
    }
    fout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);

    int T = 1;
    while(T--){
        testCase();
    }
    return 0;
}