//*****************************************************************************************************
//
//		File:			    driver.cpp
//
//		Student:			Muazuddin Mohammed
//
//		Assignment:	 	    Program  #12
//
//		Course Name:		Data Structures II
//
//		Course Number:		COSC 3100 - Z1
//
//		Due:			    May 3, 2025
//
//
//		This file implements search algorithms including Dijkstra.
//
//
//*****************************************************************************************************

#include <iostream>
#include <vector>
using namespace std;
#include "Graph.h"

int main()
{

    Graph<char> graph;
    unordered_map<char, bool> visited_bfs;

    graph.addEdge('B', 'A', 50);
    graph.addEdge('A', 'C', 15);
    graph.addEdge('A', 'E', 95);
    graph.addEdge('C', 'E', 70);
    graph.addEdge('E', 'D', 50);
    graph.addEdge('E', 'F', 40);
    graph.addEdge('F', 'D', 25);
    graph.addEdge('D', 'D', 0);
    graph.addEdge('C', 'C', 0);
    graph.addEdge('F', 'F', 0);

    graph.BFS('A', visited_bfs);
    graph.DFS('A');
    graph.dijkstra('B', 'D');

    return 0;
}

//*****************************************************************************************************

/*
Breadth-First Search (starting from A): A -> C -> E -> D -> F
Depth-First Search (starting from A): A -> E -> F -> D -> D -> C
Shortest path from B to D: B -> A -> C -> E -> D, Cost: 185
 */