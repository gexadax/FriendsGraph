#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    string names[] = { "Олег", "Никита", "Настя", "Ваня", "Женя" };
    int** adj = new int* [n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
        for (int j = 0; j < n; j++) {
            adj[i][j] = INT_MAX / 2;
        }
        adj[i][i] = 0;

        pair<string, string> edges[] = { {"Олег", "Никита"}, {"Никита", "Настя"}, {"Настя", "Ваня"}, {"Ваня", "Женя"} };
        int m = sizeof(edges) / sizeof(edges[0]);
        for (int i = 0; i < m; i++) {
            int u = -1, v = -1;
            for (int j = 0; j < n; j++) {
                if (names[j] == edges[i].first) u = j;
                if (names[j] == edges[i].second) v = j;
            }
            if (u != -1 && v != -1) {
                adj[u][v] = adj[v][u] = 1;
            }
        }


        return 0;
    }
