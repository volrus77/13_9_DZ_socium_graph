#pragma once
#include <string>
#include <vector>
using namespace std;

const int  SIZE = 16; // ������������ ����� ������ - �����
const int VERYBIGINT = 1000000000; // ����� ������� �����

class Graph {
public:
    // Social Graph
    // Vertex is Human, Edge is social connection
    Graph();
    // ���������� �������
    //void addVertex(int vnumber);
    void addVertex(const string& name);
    // ���������� �����
    void addEdge(const string& name1, const string& name2, int weight = 1);
    // �������� �������
    //void delVertex(int vnumber);
    //// �������� �����
    //void delEdge(int v1, int v2);
   
    void findMinDistancesFloyd();
    
private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(const string& name);

    int matrix[SIZE][SIZE]; // ������� ���������
    vector <std::string> userArr; // ��������� ���
    int vertexCount; // ���������� ����������� ���
};