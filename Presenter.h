#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include "Tests.h"
#include "tsp.h"
#include "BFS.h"

using namespace std;


class Presenter {
private:
	int size;
	Graph* graph;
	Graph_new* g;
	

public:	
	void CreateRandom(int size);
	void CreateGraph(int size);
	void AddEdge(int mas[100]);
	void AddEdgeOriented(int mas[100]);
	vector<int> OnBFS(int v);
	vector<int>  SearchTown();
	map<pair<int, int>, int> PrintGraph();
	string getTestRes();
	
};