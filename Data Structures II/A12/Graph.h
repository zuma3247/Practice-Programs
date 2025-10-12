//*****************************************************************************************************
//
//		File:			    Graph.h
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
//		This file defines search algorithms including Dijkstra.
//
//
//*****************************************************************************************************

#ifndef GRAPH_H
#define GRAPH_H

//*****************************************************************************************************

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <stack>
using namespace std;

//*****************************************************************************************************

template <typename T>
class Graph
{
private:
    unordered_map<T, vector<pair<T, int> > > adj;
public:
    void addEdge (T node, T neighbor, int weight);
    void DFS (const T& start);
    void BFS(const T& start, unordered_map<T, bool>& visited);
    void dijkstra (const T& source, const T& dest);
};

//*****************************************************************************************************

template <typename T>
void Graph<T> :: addEdge (T node, T neighbor, int weight)
{
    adj[node].push_back({neighbor,weight});
}

//*****************************************************************************************************

template <typename T>
void Graph<T> :: BFS(const T& start, unordered_map<T, bool>& visited)
{
    queue<T> q;

    visited[start] = true;
    q.push(start);

    cout << "Breadth-First Search (starting from " << start << "): ";

    while(!q.empty())
    {
        T curNode = q.front();
        q.pop();

        cout << curNode << " ";

        for (auto neighbor: adj[curNode])
        {
            if(!visited[neighbor.first])
            {
                visited[neighbor.first] = true;
                q.push(neighbor.first);

            }
        }

        if (!q.empty())
        {
            cout << "-> ";
        }
    }

    cout << endl;
}

//*****************************************************************************************************

template <typename T>
void Graph<T> :: DFS(const T& start)
{
    stack <T> nodesToVisit;
    unordered_map <T, bool> visited;
    nodesToVisit.push(start);

    cout << "Depth-First Search (starting from " << start << "): ";

    while(!nodesToVisit.empty())
    {
        T curNode = nodesToVisit.top();
        nodesToVisit.pop();

        cout << curNode << " ";

        if(!visited[curNode])
        {
            visited[curNode] = true;
        }

        for(auto neighbor: adj[curNode])
        {
            if(!visited[neighbor.first])
            {
                nodesToVisit.push(neighbor.first);
            }
        }

        if (!nodesToVisit.empty())
        {
            cout << "-> ";
        }
    }

    cout << endl;
}

//*****************************************************************************************************

template <typename T>
void Graph<T> :: dijkstra (const T& source, const T& dest)
{
    unordered_map<T, int> dist;
    unordered_map<T, T> parent;
    priority_queue <pair<int, T>, vector<pair<int, T>>, greater <pair<int,T>>> pq;

    for (auto node: adj)
    {
        dist[node.first] = INT_MAX;
    }

    pq.push({0, source});
    dist[source] = 0;
    parent[source] = source;

    while(!pq.empty())
    {
        int curDist = pq.top().first;
        T curNode = pq.top().second;
        pq.pop();

        for (auto neighbor: adj[curNode])
        {
            T nextNode = neighbor.first;
            int weight = neighbor.second;

            if(curDist + weight < dist[nextNode])
            {
                dist[nextNode] = curDist + weight;
                pq.push({dist[nextNode], nextNode});
                parent[nextNode] = curNode;
            }
        }
    }

    cout << "Shortest path from " << source << " to " << dest << ": ";

    T temp = dest;
    vector<T> path;

    while (temp != source)
    {
        path.push_back(temp);
        temp = parent[temp];
    }

    path.push_back(source);

    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i];
        if (i > 0)
            cout << " -> ";

    }

    cout << ", Cost: " << dist[dest] << endl;
    cout << endl;
}

//*****************************************************************************************************

#endif