/*********************************
Name: Nick Jocius
Graphs
File: graph.h
Purpose: Create a working 
bi-directional weighted graph class
with all the standard methods for 
a data structure of that type.
**********************************/

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include "data.h"
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>
#include <list>
#include <stack>
#include <queue>

using std::make_pair;
using std::pair;
using std::queue;
using std::stack;
using std::vector;

class Graph
{

public:
    Graph();
    ~Graph();
    bool isEmpty();
    bool addVertex(int, int, int);
    bool addEdge(int, int, int);
    int getNumVertices();
    int getNumEdges();
    bool getEdgeWeight(int *, int, int);
    bool removeEdge(int, int);
    void depthFT(int);
    void breadthFT(int);
    void displayGraph();

protected:
    int totalVertices;
    int totalEdges;
    vector<Node *> adjList;
    bool contains(int);
    bool containEdge(int, int);
    void eraseVertex();
};

#endif //GRAPH_GRAPH_H