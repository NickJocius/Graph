/*********************************
Name: Nick Jocius
Graphs
File: main.cpp
Purpose: Create a working 
bi-directional weighted graph class
with all the standard methods for 
a data structure of that type.
**********************************/

#include "main.h"

int main()
{

    srand(time(NULL));
    int srcV;
    int srcD;
    int edgeW;
    vector<pair<int, int>> tests;

    cout << "***** Creating Graph *****" << endl;
    Graph mygraph;
    cout << "Graph Creation.... Done" << endl
         << endl;

    cout << "***** Empty Graph Tests *****" << endl
         << endl;

    cout << "Num Verts: " << mygraph.getNumVertices() << endl;
    cout << "Num Edges: " << mygraph.getNumEdges() << endl;

    cout << "***** Adding Test Data *****"
         << "\n"
         << endl;

    for (int i = 0; i < MAX_VERTS - 1; ++i)
    {
        srcV = rand() % MAX_VERTS;
        srcD = rand() % MAX_VERTS;
        edgeW = rand() % MAX_WEIGHT;

        if (mygraph.addEdge(srcV, srcD, edgeW))
        {
            cout << "Added Edge: "
                 << "(" << srcV << ", " << srcD << ", " << edgeW << ")" << endl
                 << endl;
            tests.push_back(make_pair(srcV, srcD));
        }
        else
        {
            cout << "Error Adding Edge: "
                 << "(" << srcV << ", " << srcD << ")"
                 << "\n"
                 << endl;
        }
    }

    cout << "***** Display Full Graph *****" << endl
         << endl;
    cout << "Num Verts: " << mygraph.getNumVertices() << endl;
    cout << "Num Edges: " << mygraph.getNumEdges() << "\n"
         << endl;
    mygraph.displayGraph();

    cout << "***** Depth First Traversal *****" << endl
         << endl;

    mygraph.depthFT(0);
    cout << "\n"
         << endl;

    cout << "***** Breadth First Traversal *****" << endl
         << endl;

    mygraph.breadthFT(0);
    cout << "\n"
         << endl;

    cout << "***** Find Random Edge Weight *****" << endl
         << endl;

    for (int i = 0; i < 5; ++i)
    {
        int index = rand() % 5;
        srcV = tests[index].first;
        srcD = tests[index].second;

        if (mygraph.getEdgeWeight(&edgeW, srcV, srcD))
        {
            cout << "Edge weight "
                 << "(" << srcV << ", " << srcD << "): " << edgeW << endl
                 << endl;
        }
        else
        {
            cout << "Edge weight error" << endl;
        }
    }

    cout << "***** Random Removal *****" << endl
         << endl;

    int rm = rand() % 5;
    for (int i = 0; i < rm; ++i)
    {
        int index = rand() % MAX_VERTS;
        srcV = tests[index].first;
        srcD = tests[index].second;

        if (mygraph.removeEdge(srcV, srcD))
        {
            cout << "Removed Edge: "
                 << "(" << srcV << ", " << srcD << ")" << endl
                 << endl;
        }
        else
        {
            cout << "Error Removing Edge: "
                 << "(" << srcV << ", " << srcD << ")" << endl
                 << endl;
        }
    }

    cout << "***** Display Adjusted Graph *****" << endl
         << endl;
    cout << "Num Verts: " << mygraph.getNumVertices() << endl;
    cout << "Num Edges: " << mygraph.getNumEdges() << "\n"
         << endl;
    mygraph.displayGraph();
    cout << "\n"
         << endl;

    return 0;
}