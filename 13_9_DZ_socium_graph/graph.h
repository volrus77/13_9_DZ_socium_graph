#pragma once
#include <string>
#include <vector>
using namespace std;

const int  SIZE = 16; // максимальное число вершин - людей
const int VERYBIGINT = 1000000000; // очень большое число

class Graph {
public:
    // Social Graph
    // Vertex is Human, Edge is social connection
    Graph();
    // добавление вершины
    //void addVertex(int vnumber);
    void addVertex(const string& name);
    // добавление ребра
    void addEdge(const string& name1, const string& name2, int weight = 1);
    // удаление вершины
    //void delVertex(int vnumber);
    //// удаление ребра
    //void delEdge(int v1, int v2);
   
    void findMinDistancesFloyd();
    
private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(const string& name);

    int matrix[SIZE][SIZE]; // матрица смежности
    vector <std::string> userArr; // хранилище имён
    int vertexCount; // количество добавленных имён
};