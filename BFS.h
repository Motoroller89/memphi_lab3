#pragma once
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph_new {
    int numVertices;
    list<int>* adjLists;
    bool* visited;

public:
    Graph_new(int vertices);
    void addEdges(int src, int dest);
    vector<int> BFS(int startVertex);
};

