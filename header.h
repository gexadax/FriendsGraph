#pragma once

#include <string>

class Vertex {
public:
	int number;
	std::string name;
	std::list<Vertex*> adjacents;
	Vertex(int n);
};
