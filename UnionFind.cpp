// UnionFind.cpp : This file contains the 'main' function. Program execution begins and ends there.
// author: Stanley Lalanne

#include <iostream>
#include <vector>
using namespace std;

void addEdge(int source, int dest, vector<int> &v);

int findRoot(int v, const vector<int> &graph);

void unionMerge(int v1, int v2, vector<int> &graph);

bool isConnected(int v1, int v2, const vector<int> &graph);

int main()
{
    vector<int> graph{ 0,1,2,3,4,5,6,7,8,9 };

    addEdge(0, 1, graph);
    addEdge(0, 2, graph);
    addEdge(4, 8, graph);
    addEdge(5, 6, graph);
    addEdge(1, 3, graph);
    addEdge(5, 7, graph);


    cout << isConnected(0, 5, graph) << endl;

    unionMerge(0, 5, graph);

    cout << isConnected(0, 5, graph) << endl;

    cout << isConnected(0, 6, graph) << endl;

    cout << isConnected(0, 3, graph) << endl;

    cout << isConnected(0, 4, graph) << endl;


    unionMerge(0, 4, graph);

    cout << isConnected(0, 4, graph) << endl;
}


void addEdge(int source, int dest, vector<int> &graph) {
    graph[dest] = source;
}

int findRoot(int v, const vector<int>& graph) {
    if (graph[v] == v) return v;

    return findRoot(graph[v], graph);
}

void unionMerge(int v1, int v2, vector<int>& graph) {
    int v1root = findRoot(v1, graph);
    int v2root = findRoot(v2, graph);

    if (v1root != v2root) graph[v2root] = graph[v1root];
}

bool isConnected(int v1, int v2, const vector<int>& graph) {
    return (findRoot(v1, graph) == findRoot(v2, graph));
}