#include<iostream>
#include<list>
using namespace std;

class Graph 
{
  int numVertices;
  list<int>* adjLists;
  bool* visited;

  public:
    Graph(int V);
    void addEdge(int src, int dest);
    void DFS(int vertex);
    void BFS(int startVertex);
};

//create graph
Graph::Graph(int vertices) {
  numVertices = vertices;
  adjLists = new list<int>[vertices];
  visited = new bool[vertices];
}

//add edges
void Graph::addEdge(int src, int dest) {
  adjLists[src].push_front(dest);
}

//DFS
void Graph::DFS(int vertex) {
  visited[vertex] = true;
  list<int> adjList = adjLists[vertex];

  cout << vertex << " ";

  list<int>::iterator i;
  for (i = adjList.begin(); i != adjList.end(); ++i)
    if (!visited[*i])
      DFS(*i);
}

//BFS
void Graph::BFS(int startVertex) 
{
  visited = new bool[numVertices];
  for (int i = 0; i < numVertices; i++)
    visited[i] = false;

  list<int> queue;

  visited[startVertex] = true;
  queue.push_back(startVertex);

  list<int>::iterator i;

  while (!queue.empty()) 
  {
    int currVertex = queue.front();
    cout << "visited " << currVertex << " ";
    queue.pop_front();

    for (i = adjLists[currVertex].begin(); i != adjLists[currVertex].end(); ++i) 
    {
      int adjVertex = *i;
      if (!visited[adjVertex]) 
      {
        visited[adjVertex] = true;
        queue.push_back(adjVertex);
      }
    }
  }
}

int main() 
{
  Graph g(4);
  g.addEdge(0, 1);
  g.addEdge(0, 2);
  g.addEdge(1, 2);
  g.addEdge(2, 0);
  g.addEdge(2, 3);
  g.addEdge(3, 3);

  cout << "BFS" << endl;
  g.BFS(2);
  cout << endl << "DFS" << endl;
  g.DFS(2);

  return 0;
}