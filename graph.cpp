/*********************************
Name: Nick Jocius
Graphs
File: graph.cpp
Purpose: Create a working 
bi-directional weighted graph class
with all the standard methods for 
a data structure of that type.
**********************************/
#include "graph.h"

Graph::Graph()
{
    totalVertices = 0;
    totalEdges = 0;

} // end constructor

Graph::~Graph()
{
    for (auto v : adjList)
    {
        delete v;
    }
    adjList.clear();

} // end destructor

bool Graph::addVertex(int src, int dest, int w)
{
    bool result = false;
    Node *newVptr = new Node;
    newVptr->vertex = src;
    newVptr->edges.push_back(make_pair(dest, w));
    totalEdges++;
    adjList.push_back(newVptr);
    result = true;
    return result;

} // end addVertex()

bool Graph::addEdge(int src, int dest, int w)
{
    bool result = false;
    if (!containEdge(src, dest) && src != dest)
    {
        if (!contains(src) && !contains(dest))
        {
            result = addVertex(src, dest, w);
            totalVertices++;
            result = addVertex(dest, src, w);
            totalVertices++;
        }
        else if (contains(src) && !contains(dest))
        {
            result = addVertex(dest, src, w);

            totalVertices++;
            for (auto v : adjList)
            {
                if (v->vertex == src)
                {
                    v->edges.push_back(make_pair(dest, w));
                    totalEdges++;
                }
            }
        }
        else if (contains(dest) && !contains(src))
        {
            result = addVertex(src, dest, w);
            totalVertices++;
            for (auto v : adjList)
            {
                if (v->vertex == dest)
                {
                    v->edges.push_back(make_pair(src, w));
                    totalEdges++;
                }
            }
        }
        else if (contains(dest) && contains(src))
        {
            for (auto v : adjList)
            {
                if (v->vertex == src)
                {
                    v->edges.push_back(make_pair(dest, w));
                    totalEdges++;
                }
            }
            for (auto v : adjList)
            {
                if (v->vertex == dest)
                {
                    v->edges.push_back(make_pair(src, w));
                    totalEdges++;
                }
            }
            result = true;
        }
    }

    return result;

} // end addEdge()

void Graph::eraseVertex()
{
    for (auto &v : adjList)
    {
        if (v->edges.empty())
        {
            delete v;
            v = nullptr;
        }
    }
    adjList.erase(remove(adjList.begin(), adjList.end(), nullptr), adjList.end());
    totalVertices--;
} // end eraseVertex()

bool Graph::removeEdge(int src, int dest)
{
    bool result = false;
    int temp;
    //check if vertex src exists
    if (contains(src) && src != dest)
    {
        for (int i = 0; i < adjList.size(); i++)
        {
            if (adjList[i]->vertex == src)
            {
                for (auto &e : adjList[i]->edges)
                {
                    if (e.first == dest)
                    {
                        temp = e.second;
                    }
                }
                adjList[i]->edges.remove(pair<int, int>(dest, temp));
                totalEdges--;
            }
            if (adjList[i]->vertex == dest)
            {
                for (auto &e : adjList[i]->edges)
                {
                    if (e.first == src)
                    {
                        temp = e.second;
                    }
                }
                adjList[i]->edges.remove(pair<int, int>(src, temp));
                totalEdges--;
            }
            result = true;
        }
        eraseVertex();
    }
    return result;
} // end removeEdge()

bool Graph::containEdge(int src, int dest)
{
    bool result = false;
    for (auto v : adjList)
    {
        if (v->vertex == src)
        {
            for (auto e : v->edges)
            {
                if (e.first == dest)
                {
                    result = true;
                }
            }
        }
    }
    return result;
} // end containEdge()

bool Graph::contains(int v1)
{
    bool result = false;
    for (int i = 0; i < adjList.size(); i++)
    {
        if (adjList[i]->vertex == v1)
        {
            result = true;
        }
    }

    return result;
} // end contains()

bool Graph::getEdgeWeight(int *w, int src, int dest)
{
    bool result = false;
    if (contains(src) && src != dest)
    {
        for (auto v : adjList)
        {
            if (v->vertex == src)
            {
                for (auto e : v->edges)
                    if (e.first == dest)
                    {

                        *w = e.second;
                        result = true;
                    }
            }
        }
    }
    else
    {
        *w = -1;
    }

    return result;
} // end getEdgeWeight()

int Graph::getNumEdges()
{
    return totalEdges;

} // end getNumEdges()

int Graph::getNumVertices()
{
    return totalVertices;
} // end getNumVertices()

void Graph::depthFT(int src)
{
    vector<bool> visited(totalVertices, false);
    stack<int> stack;
    stack.push(src);
    while (!stack.empty())
    {
        src = stack.top();
        stack.pop();
        if (!visited[src])
        {
            std::cout << src << " ";
            visited[src] = true;
        }
        for (auto i = adjList.begin(); i != adjList.end(); i++)
        {
            for (auto v : (*i)->edges)
            {
                if (!visited[v.first])
                {
                    stack.push(v.first);
                }
            }
        }
    }

} // end depthFT()

void Graph::breadthFT(int src)
{
    vector<bool> visited(totalVertices, false);
    queue<int> queue;
    std::cout << src << " ";
    visited[src] = true;
    queue.push(src);
    while (!queue.empty())
    {
        src = queue.front();
        for (auto i = adjList.begin(); i != adjList.end(); i++)
        {
            for (auto v : (*i)->edges)
            {
                if (!visited[v.first])
                {
                    visited[v.first] = true;
                    std::cout << v.first << " ";
                    queue.push(v.first);
                }
            }
        }
        queue.pop();
    }

} // end breadthFT()

void Graph::displayGraph()
{
    for (int i = 0; i < adjList.size(); i++)
    {
        std::cout << adjList[i]->vertex << ": ";
        for (auto v : adjList[i]->edges)
        {
            std::cout << "(" << adjList[i]->vertex << ", " << v.first << ", " << v.second << ")";
        }

        std::cout << std::endl;
    }
}