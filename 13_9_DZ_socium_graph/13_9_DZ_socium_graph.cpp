// 13_9_DZ_socium_graph.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.

#include "graph.h"
#include <iostream>


int main()
{
    setlocale(LC_ALL, "");

    Graph g;

    g.addVertex("Олег");
    g.addVertex("Никита");
    g.addVertex("Настя");
    g.addVertex("Ваня");
    g.addVertex("Женя");


    g.addEdge("Олег", "Никита");
    g.addEdge("Никита", "Настя");
    g.addEdge("Настя", "Ваня");
    g.addEdge("Ваня", "Женя");

    g.findMinDistancesFloyd();

    return 0;
}
