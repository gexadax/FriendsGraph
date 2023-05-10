#include <iostream> 
#include "header.h" 

int main() {
    std::setlocale(LC_ALL, "Russian");

    std::list<Vertex*> graph;

    Vertex* oleg = new Vertex(1);
    Vertex* nikita = new Vertex(2);
    Vertex* nastya = new Vertex(3);
    Vertex* vanya = new Vertex(4);
    Vertex* zhenya = new Vertex(5);

    oleg->name = "Олег";
    nikita->name = "Никита";
    nastya->name = "Настя";
    vanya->name = "Ваня";
    zhenya->name = "Женя";

    oleg->adjacents = { nikita, nastya,vanya };
    nikita->adjacents = { oleg, nastya,vanya, zhenya };
    nastya->adjacents = { nikita, vanya, oleg, zhenya };
    vanya->adjacents = { nastya, zhenya, nikita, oleg };
    zhenya->adjacents = { vanya,nastya,nikita };

    graph.push_back(oleg);
    graph.push_back(nikita);
    graph.push_back(nastya);
    graph.push_back(vanya);
    graph.push_back(zhenya);

    std::cout << "Выберете человека: ";
    for (Vertex* v : graph) {
        std::cout << v->number << " - " << v->name << ", ";
    }
    std::cout << "\n";

    std::cout << "Введите номер вершины: ";
    int number;
    std::cin >> number;

    std::string name;
    for (Vertex* v : graph) {
        if (v->number == number) {
            name = v->name;
            break;
        }
    }

    std::list<Vertex*> adjacents = findAdjacentsByName(graph, name);

    std::cout << name << " знаком с:";
    for (Vertex* v : adjacents) {
        std::cout << v->name << " ";
    }
    std::cout << "\n";

    return 0;
}