/*********************************
Name: Nick Jocius
Graph C++
File: data.h
Purpose: Create a working 
bi-directional weighted graph class
with all the standard methods for 
a data structure of that type.
**********************************/

#ifndef GRAPHS_DATA_H
#define GRAPHS_DATA_H

#include <list>
#include <utility>

using std::list;
using std::pair;
struct Node
{
    int vertex;
    list<pair<int, int>> edges;
};

#endif //GRAPHS_DATA_H