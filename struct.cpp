#include "header.h"



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