Полный код C++ с несколькими тестами
  
cpp
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<int> vertexCoverGreedy(vector<pair<int, int>>& edges, int numVertices) {
    set<int> cover;
    vector<pair<int, int>> remainingEdges = edges;
    
    while (!remainingEdges.empty()) {
        // Выбираем первое ребро
        int u = remainingEdges[0].first;
        int v = remainingEdges[0].second;
        
        // Добавляем обе вершины в покрытие
        cover.insert(u);
        cover.insert(v);
        
        // Удаляем все ребра, инцидентные u или v
        vector<pair<int, int>> newEdges;
        for (auto& edge : remainingEdges) {
            if (edge.first != u && edge.first != v && 
                edge.second != u && edge.second != v) {
                newEdges.push_back(edge);
            }
        }
        remainingEdges = newEdges;
    }
    
    return cover;
}

void runTest(const string& testName, vector<pair<int, int>> edges, int numVertices) {
    cout << "=== " << testName << " ===" << endl;
    cout << "Входные данные:" << endl;
    cout << "Количество вершин: " << numVertices << endl;
    cout << "Ребра: ";
    for (auto& edge : edges) {
        cout << "(" << edge.first << "," << edge.second << ") ";
    }
    cout << endl;
    
    set<int> cover = vertexCoverGreedy(edges, numVertices);
    
    cout << "Выходные данные:" << endl;
    cout << "Размер покрытия: " << cover.size() << endl;
    cout << "Покрытие: ";
    for (int vertex : cover) {
        cout << vertex << " ";
    }
    cout << endl << endl;
}

int main() {
    // Тест 1: Цикл из 10 вершин
    vector<pair<int, int>> edges1 = {{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, 
                                    {5,6}, {6,7}, {7,8}, {8,9}, {9,0}};
    runTest("Цикл C10", edges1, 10);
    
    // Тест 2: Полный граф K4
    vector<pair<int, int>> edges2 = {{0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3}};
    runTest("Полный граф K4", edges2, 4);
    
    // Тест 3: Дерево
    vector<pair<int, int>> edges3 = {{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}};
    runTest("Дерево", edges3, 7);
    
    // Тест 4: Граф с двумя компонентами
    vector<pair<int, int>> edges4 = {{0,1}, {1,2}, {3,4}, {4,5}};
    runTest("Граф с двумя компонентами", edges4, 6);
    
    // Тест 5: Звезда
    vector<pair<int, int>> edges5 = {{0,1}, {0,2}, {0,3}, {0,4}};
    runTest("Звезда K1,4", edges5, 5);
    
    return 0;
}
