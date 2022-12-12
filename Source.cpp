#include <iostream>
#include <vector>

using namespace std;

// ��������� ������ ��� �������� ����� Graph
struct Edge {
    int src, dest;
};

// ����� ��� ������������� graph�������� �������
class Graph
{
public:
    // ������ �������� ��� ������������� ������ ���������
    vector<vector<int>> adjList;

    // ����������� Graph�
    Graph(vector<Edge> const& edges, int n)
    {
        // �������� ������ �������, ����� �� �������� `n` ��������� ���� `vector<int>`
        adjList.resize(n);

        // ��������� ����� � ��������������� graph
        for (auto& edge : edges)
        {
            // ��������� � �����
            adjList[edge.src].push_back(edge.dest);

            // ���������������� ��������� ��� ��� ������������������ Graph
            // adjList[edge.dest].push_back(edge.src);
        }
    }
};

// ������� ��� ������ ������������� ������ ��������� Graph
void printGraph(Graph const& graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        // ������� ����� ������� �������
        cout << i << " ��> ";

        // ������� ��� �������� ������� ������� `i`
        for (int v : graph.adjList[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
}

// ���������� Graph � �������������� STL
int main()
{
    // vector ����� Graph �������� ����� ����.
    // �������� ��������, ��� vector ������������� � ����������� ���� ������� �����
    // ��������� �������� � C++11, C++14, C++17, �� �� �������� � C++98.
    vector<Edge> edges =
    {
        {0, 1}, {1, 2}, {2, 0}, {2, 1}, {3, 2}, {4, 5}, {5, 4}
    };

    // ����� ���������� ����� � Graph (�� 0 �� 5)
    int n = 6;

    // ��������� Graph
    Graph graph(edges, n);

    // ������� ������������� ������ ��������� Graph
    printGraph(graph, n);

    return 0;
}
