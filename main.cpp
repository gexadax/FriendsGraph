#include <iostream>
using namespace std;

// ������� ������ ���� ��� ������, ����������� ���������� ����� �������� �� ��������� 3
// n - ���������� ������
// adj � ������� ��������� �����
void find_pairs(int n, int** adj, string* names) {
    // ��������� �������� ������-��������, ����� ����� ���������� ���������� ����� ����� ������ ������
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // ��������� ����������, ���� ��� ������ ����� ������� k
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
            }
        }
    }

    // ���������� ��� ��������� ���� ������
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // ���������, �� ��������� �� ���������� ����� ���� 3
            if (adj[i][j] <= 3) {
                // ������� ���� ������
                cout << names[i] << " " << names[j] << "\n";
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    string names[] = { "����", "������", "�����", "����", "����" };
    int** adj = new int* [n];
    for (int i = 0; i < n; i++) {
        adj[i] = new int[n];
        for (int j = 0; j < n; j++) {
            adj[i][j] = INT_MAX / 2;
        }
        adj[i][i] = 0;

        // ��������� �����
        pair<string, string> edges[] = { {"����", "������"}, {"������", "�����"}, {"�����", "����"}, {"����", "����"} };
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

        // ��������� �����, ��������� �� ������� ������
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

        // ������ ������
        for (int i = 0; i < n; i++) {
            delete[] adj[i];
        }
        delete[] adj;

        return 0;
    }
