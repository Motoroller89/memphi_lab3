#include "Presenter.h"


void Presenter::CreateRandom(int size) {
	this->size = size;
	graph = new Graph(size, 0, true);
}

map<pair<int, int>, int> Presenter::PrintGraph() {
	map<pair<int, int>, int> it;
	it = graph->showGraph();
	return it;
}

void Presenter::CreateGraph(int size) {
	this->size = size;
	graph = new Graph(size, 0);
	g = new Graph_new(size);
}

void Presenter::AddEdge(int mas[100]){
	try {
		graph->addEdge(mas[0], mas[1], mas[2]);
	}
	catch (int myNum) {
		cout << "";
	}
	g->addEdges(mas[0], mas[1]);
}

void Presenter::AddEdgeOriented(int mas[100]) {
	graph->addEdgeOrient(mas[0], mas[1], mas[2]);

}

vector<int> Presenter::OnBFS(int v) {
	vector<int> vec;
	vec = g->BFS(v);
	return vec;
}



vector<int> Presenter::SearchTown() {
	Genetic genetic(graph, 10, 1000, 5, true);
	vector<int> vec = genetic.run();
	return vec;
}

string Presenter::getTestRes() {
	return startTests();
}

