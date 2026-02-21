//AJG23085 谷口香央
//Codespacesで採点お願いします。

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    const int N_NODE = 5;
    int graph[N_NODE][N_NODE] = {
        {0, 3, 1, 10000, 10000},
        {3, 0, 1, 3, 10000},
        {1, 1, 0, 2, 5},
        {10000, 3, 2, 0, 1},
        {10000, 10000, 5, 1, 0},
    };

    vector<int> T(N_NODE, -1);
    int s;
    cout << "Input node number (0-4): ";
    cin >> s;

    if (s < 0 || s >= N_NODE) {
        cout << "Invalid node number!" << endl;
        return 1;
    }

    vector<int> C(N_NODE, 10000);
    vector<bool> visited(N_NODE, false);

    C[s] = 0; 

    for (int j=0; j<N_NODE; j++) {
        int min_cost = 10000, u = -1;
        for (int i=0; i<N_NODE; i++) {
            if (!visited[i] && C[i] < min_cost) {
                min_cost = C[i];
                u = i;
            }
        }

        if (u == -1) break;

        visited[u] = true;

        for (int v=0; v<N_NODE; v++) {
            if (graph[u][v] != 10000 && !visited[v]) {
                if (C[v] > C[u] + graph[u][v]) {
                    C[v] = C[u] + graph[u][v];
                    T[v] = u;
                }
            }
        }
    }

    // 結果を出力
    for (int i = 0; i < N_NODE; i++) {
        if (i != s) {
            if (C[i] == 10000) {
                cout << "No route from node " << s << " to node " << i << endl;
            } else {
                cout << "Route from node " << s << " to node " << i << ": ";
                int current = i;
                while (current != -1) {
                    if(current==s){
                        cout << current;
                    }else{
                        cout << current << " <- ";
                    }
                    current = T[current];
                }
                cout << " cost = " << C[i] << endl;
            }
        }
    }

    return 0;
}
