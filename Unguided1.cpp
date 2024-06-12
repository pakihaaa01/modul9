#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <string>
#include <iomanip>

using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int dest;
    int weight;
};

class Graph {
    unordered_map<string, int> cityIndex;
    vector<string> cities;
    vector<vector<int>> adjMatrix;

public:
    void addCity(const string &name) {
        if (cityIndex.find(name) == cityIndex.end()) {
            cityIndex[name] = cities.size();
            cities.push_back(name);
            for (auto &row : adjMatrix) {
                row.push_back(INF);
            }
            adjMatrix.push_back(vector<int>(cities.size(), INF));
        }
    }

    void addEdge(const string &from, const string &to, int weight) {
        addCity(from);
        addCity(to);
        adjMatrix[cityIndex[from]][cityIndex[to]] = weight;
        adjMatrix[cityIndex[to]][cityIndex[from]] = weight;  // Assuming undirected graph
    }

    void printAdjMatrix() {
        cout << setw(10) << " ";
        for (const auto &city : cities) {
            cout << setw(10) << city;
        }
        cout << endl;

        for (size_t i = 0; i < cities.size(); ++i) {
            cout << setw(10) << cities[i];
            for (size_t j = 0; j < cities.size(); ++j) {
                if (adjMatrix[i][j] == INF) {
                    cout << setw(10) << "INF";
                } else {
                    cout << setw(10) << adjMatrix[i][j];
                }
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph;
    int NIM_2311102048;

    cout << "Silakan masukan jumlah simpul: ";
    cin >> NIM_2311102048;

    vector<string> cityNames(NIM_2311102048);
    for (int i = 0; i < NIM_2311102048; ++i) {
        cout << "Simpul " << i + 1 << ": ";
        cin >> cityNames[i];
        graph.addCity(cityNames[i]);
    }

    cout << "Silakan masukkan bobot antar simpul" << endl;
    for (int i = 0; i < NIM_2311102048; ++i) {
        for (int j = 0; j < NIM_2311102048; ++j) {
            int weight;
            if (i == j) {
                weight = 0;
            } else {
                cout << cityNames[i] << "--> " << cityNames[j] << ": ";
                cin >> weight;
            }
            graph.addEdge(cityNames[i], cityNames[j], weight);
        }
    }

    cout << endl;
    graph.printAdjMatrix();

    return 0;
}
