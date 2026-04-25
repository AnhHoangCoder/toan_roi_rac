// Cho đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng ma trận kề.

// Yêu cầu:

// (1) Xác định bậc các đỉnh của G;

// (2) Biểu diễn G dưới dạng danh sách kề.

// Dữ liệu: Vào từ tệp DT.INP:

// - Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.

// - Dòng thứ hai chứa số nguyên dương n không vượt quá 100 là số đỉnh của G.

// - Trong n dòng tiếp theo, mỗi dòng chứa n số 0 hoặc 1 mô tả ma trận kề của G.

// Kết quả: Ghi ra tệp DT.OUT:

// - Nếu t = 1 thì ghi ra một dòng gồm n số tự nhiên tương ứng là bậc của n đỉnh.

// - Nếu t = 2 thì ghi ra theo qui cách:

// + Dòng đầu ghi ra số tự nhiên n là số đỉnh của G.

// + Trong n dòng tiếp theo, mỗi dòng thứ i (1 £ i £ n) ghi số tự nhiên k là số lương đỉnh kề với đỉnh i và k số tự nhiên theo thứ tự tăng v1, …, vk là số hiệu các đỉnh kề tương ứng.

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

// 4

// 2 2 4

// 2 1 3

// 1 2

// 1 1

// Đỉnh 1 có 2 đỉnh kề là 2 và 4.

// Đỉnh 2 có 2 đỉnh kề là 1 và 3.

// Đỉnh 3 có 1 đỉnh kề là 2.

// Đỉnh 4 có 1 đỉnh kề là 1.

#include <iostream>
#include <fstream>
#include <vector>

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
    for(int i=1;i<=n;i++){
        fout << adj[i].size() << " ";
        for(int x : adj[i]){
            fout << x << " ";
        }
        fout << endl;
    }    
}

void testCase(){
    int t;
    fin >> t >> n;

    for(int i=1;i<=n;i++){
        adj[i].clear();
    }    

    vector<vector<int>> a(n + 1 , vector<int> (n + 1));
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
        fout << n << endl;
        theSecond();
    }
}

int main(){
    testCase();
    return 0;
}