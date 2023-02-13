#include "graph.h"
#include <iostream>

Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// добавление вершины
void Graph::addVertex(const string& name)
{
    userArr.push_back(name);
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(const string& name1, const string& name2, int weight)
{
    int v1{ 0 };
    int v2{ 0 };
    auto it1 = std::find(userArr.begin(), userArr.end(), name1);
    if (it1 != userArr.end())
        v1 = distance(userArr.begin(), it1);
    auto it2 = std::find(userArr.begin(), userArr.end(), name2);
    if (it2 != userArr.end())
        v2 = distance(userArr.begin(), it2);

    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}


//#define VERYBIGINT 1000000000 // очень большое число

void Graph::findMinDistancesFloyd()
{
    int weights[SIZE][SIZE]; // матрица путей
    // инициализаци матрицы
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // путь до самой себя равен 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // если ребра нет
                }
                else {
                    weights[i][j] = matrix[i][j]; // если ребро есть
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) // итерации по k
    {
        // возьмем номер вершины
        for (int i = 0; i < vertexCount; i++)
        {
            if (i == k)
                continue;

            for (int j = 0; j < vertexCount; j++)
            {
                if (j == k)
                    continue;

                if (weights[i][k] + weights[k][j] < weights[i][j]) {
                    // пересчет мматрицы путей
                    weights[i][j] = weights[i][k] + weights[k][j];
                }
            }
        }
    }

    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = i + 1; j < vertexCount; j++)
            // вывод всех путей меньше 4
        {
            if (weights[i][j] < 4 )
                std::cout << userArr[i] << "-" << userArr[j] << ": " << weights[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}