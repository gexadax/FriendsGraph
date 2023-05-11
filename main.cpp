#include <iostream>
using namespace std;

// Функция поиска всех пар вершин, минимальное расстояние между которыми не превышает 3
// n - количество вершин
// adj — матрица смежности графа
void find_pairs(int n, int** adj, string* names) {
    // Применяем алгоритм Флойда-Уоршалла, чтобы найти кратчайшее расстояние между всеми парами вершин
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Обновляем расстояние, если оно короче через вершину k
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    // Перебираем все возможные пары вершин
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Проверяем, не превышает ли расстояние между ними 3
            if (adj[i][j] <= 3) {
                // Выводим пару вершин
                cout << names[i] << " " << names[j] << "\n";
            }
        }
    }
}

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

        // Добавляем ребра
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

        // Добавляем ребра, указанные во входных данных
        pair<string, string> edges[] = { {"Oleg", "Nikita"}, {"Nikita", "Nastya"}, {"Nastya", "Vanya"}, {"Vanya", "Zhenya"} }; // Edges between them
        int m = sizeof(edges) / sizeof(edges[0]); // Number of edges
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

        
        find_pairs(n, adj, names);

        // Чистим память
        for (int i = 0; i < n; i++) {
            delete[] adj[i];
        }
        delete[] adj;

        return 0;
    }
