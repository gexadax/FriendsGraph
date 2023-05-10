#include "header.h"

Vertex::Vertex(int n) : number(n) {}

std::list<Vertex*> findAdjacentsByName(std::list<Vertex*>& graph, std::string name) {
    std::list<Vertex*> result;
    for (Vertex* v : graph) {
        if (v->name == name) {
            result = v->adjacents;
            break;
        }
    }
    return result;
}

void dijkstra(std::list<Vertex*>& graph, int src, int dest) {

}