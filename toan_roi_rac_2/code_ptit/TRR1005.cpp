// Cho đồ thị vô hướng G = (V, E) gồm n đỉnh biểu diễn dưới dạng danh sách cạnh.

// Yêu cầu:

// (1) Xác định bậc các đỉnh của G;

// (2) Biểu diễn G dưới dạng danh sách kề.

// Dữ liệu: Vào từ tệp DT.INP:

// - Dòng đầu chứa số nguyên dương t nhận giá trị 1 hoặc 2.

// - Dòng thứ hai chứa hai số nguyên n là số đỉnh và m là số cạnh của G. Trong đó, 1 £ n £ 100 và 1 £ m £ n(n-1)/2.

// - Trong m dòng tiếp theo, mỗi dòng thứ i (1 £ i £ m) chứa hai số nguyên ui, vi là đỉnh đầu và đỉnh cuối của cạnh ei. Trong đó, 1 £ ui < vi £ n.

// Kết quả: Ghi ra tệp DT.OUT:

// - Nếu t = 1 thì ghi ra một dòng gồm n số tự nhiên tương ứng là bậc của n đỉnh.

// - Nếu t = 2 thì ghi ra n+1 dòng:

// + Dòng đầu ghi ra số tự nhiên n là số đỉnh của G.

// + Trong n dòng tiếp theo, mỗi dòng thứ i (1 £ i £ n) ghi số tự nhiên k là số lương đỉnh kề với đỉnh i và k số tự nhiên theo thứ tự tăng v1, …, vk là số hiệu các đỉnh kề tương ứng.

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

// 2 2 4

// 2 1 3

// 1 2

// 1 1

// Đỉnh 1 có 2 đỉnh kề là 2 và 4.

// Đỉnh 2 có 2 đỉnh kề là 1 và 3.

// Đỉnh 3 có 1 đỉnh kề là 2.

// Đỉnh 4 có 1 đỉnh kề là 1.

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("DT.INP" , "r" , stdin);
    freopen("DT.OUT" , "w" , stdout);

    int t , n , m;
    cin >> t >> n >> m;
    vector<int> a[101];
    while(m--){
        int u , v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    for(int i=1;i<=n;i++){
        sort(a[i].begin() , a[i].end());
    }    

    if(t == 1){
        for(int i=1;i<=n;i++){
            cout << a[i].size() << " ";
        }
    }
    else{
        cout << n << endl;
        for(int i=1;i<=n;i++){
            cout << a[i].size() << " ";
            for(int x : a[i]){
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}