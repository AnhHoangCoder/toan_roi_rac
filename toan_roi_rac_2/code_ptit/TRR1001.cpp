// Cho đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề.

// Yêu cầu:

// (1) Xác định bậc các đỉnh của G;

// (2) Biểu diễn G dưới dạng danh sách cạnh.

// Dữ liệu: Vào từ tệp DT.INP:

// - Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.

// - Dòng thứ hai chứa số nguyên dương n không vượt quá 100 là số đỉnh của G.

// - Trong n dòng tiếp theo, mỗi dòng chứa n số 0 hoặc 1 mô tả ma trận kề của G.

// Kết quả: Ghi ra tệp DT.OUT:

// - Nếu t = 1 thì ghi ra một dòng gồm n số tự nhiên tương ứng là bậc của n đỉnh.

// - Nếu t = 2 thì ghi ra theo qui cách:

// + Dòng đầu ghi ra hai số tự nhiên n và m là số đỉnh và số cạnh của G.

// + Trong m dòng tiếp theo, mỗi dòng thứ i (1 £ i £ m) ghi hai số ui, vi là đỉnh đầu và đỉnh cuối của cạnh ei. Các cạnh của G được đánh số theo thứ tự từ điển.

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

// 1 2

// 1 4

// 2 3

// Đồ thị có 3 cạnh (1,2), (1,4) và (2,3).

#include <iostream>
#include <vector>
#include <fstream>
#include <set>

using namespace std;

ifstream fin("DT.INP");
ofstream fout("DT.OUT");

vector<int> adj[101];
int n;

void theFirst(){
    for(int i=1;i<=n;i++){
        fout << adj[i].size() << " ";
    }
}

void theSecond(){
    set<pair<int,int>> s;
    
    for(int i=1;i<=n;i++){
        for(int x : adj[i]){
            int u = i , v = x;
            if(u > v) swap(u , v);
            s.insert({u , v});
        }
    }

    fout << n << " " << s.size() << endl;
    for(auto x : s){
        fout << x.first << " " << x.second << endl;
    }
}

void testCase(){
    int t;
    fin >> t >> n;

    vector<vector<int>> a(n+1 , vector<int> (n+1));

    for(int i=1;i<=n;i++){
        adj[i].clear();
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            fin >> a[i][j];
            
            if(a[i][j] == 1){
                adj[i].push_back(j);
            }
        }
    }

    if(t == 1){
        theFirst();
    }
    else if(t == 2){
        theSecond();
    }
}

int main(){
    int T = 1;
    while(T--){
        testCase();
    }
    return 0;
}