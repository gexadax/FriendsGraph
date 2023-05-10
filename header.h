#pragma once
#include <list>
#include <string>

class Vertex {
public:
	int number;
	std::string name;
	std::list<Vertex*> adjacents;
	Vertex(int n);
};

std::list<Vertex*> findAdjacentsByName(std::list<Vertex*>& graph, std::string name);

void dijkstra(std::list<Vertex*>& graph, int src, int dest);