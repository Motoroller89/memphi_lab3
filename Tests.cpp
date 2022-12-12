#include "Tests.h"

string startTests() {
	Graph* graph = new Graph(3, 0);
	graph->addEdgeOrient(0, 1, 2);
	graph->addEdgeOrient(0, 2, 7);
	graph->addEdgeOrient(1, 0, 2);
	graph->addEdgeOrient(1, 2, 4);
	graph->addEdgeOrient(2, 0, 7);
	graph->addEdgeOrient(2, 1, 4);
	Genetic genetic(graph, 10, 1000, 10, false);
	vector<int> vec = genetic.run();
	assert(vec[vec.size() - 1] == 13);
	assert(vec.size() == 5); 
	

	Graph* graph1 = new Graph(5, 1);
	graph1->addEdge(0, 1, 1);
	graph1->addEdge(0, 2, 6);
	graph1->addEdge(0, 3, 1);
	graph1->addEdge(0, 4, 8);
	graph1->addEdge(1, 2, 11);
	graph1->addEdge(1, 3, 2);
	graph1->addEdge(1, 4, 1);
	graph1->addEdge(2, 3, 6);
	graph1->addEdge(2, 4, 1);
	graph1->addEdge(3, 4, 7);
	
	Genetic genetic1(graph1, 10, 1000, 10, false);
	vector<int> vec1 = genetic1.run();
	assert(vec1[vec1.size() - 1] == 10);
	assert(vec1.size() == 7);

	string res = "All test OK";
	return res;
}
