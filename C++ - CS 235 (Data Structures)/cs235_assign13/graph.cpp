/***********************************************************************
 * Header:
 *    Graph
 * Summary:
 *    Graph Functions
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/

#include "graph.h"
#include <cassert>
#include <iostream>
using namespace custom;

/*********************************************************
* Graph :: Graph
* Non-default constructor
*********************************************************/
Graph::Graph(int vertices)
{
   this->vertices = vertices;
   this->edges = 0;
   if (vertices)
   {
      matrix = new bool[capacity()];
      for (int i = 0; i < capacity(); i++)
         matrix[i] = false;
   }
   else
   {      
      matrix = NULL;
      cout << "WARN: custom::Graph::Graph(): Creating an empty Graph (0 vertices)\n";
   }      
}

/*********************************************************
* Graph :: Graph
* Copy constructor
*********************************************************/
Graph::Graph(const Graph & rhs)
{
   matrix = NULL;
   *this = rhs;
}

/*********************************************************
* Graph :: Graph
* Destructor
*********************************************************/
Graph::~Graph()
{
   if (matrix)
   {
      delete [] matrix;
      matrix = NULL;
   }
}

/*********************************************************
* Graph :: Assignment Operator
* Clones rhs into this instance
*********************************************************/
Graph & custom::Graph::operator = (const Graph & rhs)
{
   this->vertices = rhs.vertices;
   this->edges = rhs.edges;
   if (matrix)
   {   
      delete [] matrix;
      matrix = NULL;
   }

   // We're done if there's no capacity anywhere               
   if (rhs.capacity() <= 0)
   {
      cout << "WARN: custom::Graph::operator=(): rhs.capacity() <= 0\n";   
      return *this;
   }

   // Create and fill the matrix   
   matrix = new bool[capacity()];
   if (rhs.matrix)   
      for (int i = 0; i < capacity(); i++)
         matrix[i] = rhs.matrix[i];
   else
   {
      cout << "WARN: custom::Graph::operator=(): rhs has capacity but no matrix; zeroing ours out\n";
      for (int i = 0; i < capacity(); i++)
         matrix[i] = false;
   }

   return *this;
}

/*********************************************************
* Graph :: Size
* Returns the number of vertices
*********************************************************/
int custom::Graph::size() const
{
   return vertices;
}

/*********************************************************
* Graph :: Capacity
* Returns the maximum possible number of edges
*********************************************************/
int custom::Graph::capacity() const
{
   return vertices * vertices;
}

/*********************************************************
* Graph :: Empty
* Return true if there are no vertices
*********************************************************/
bool custom::Graph::empty() const 
{
   return vertices == 0;
}

/*********************************************************
* Graph :: Clear
* Clears the contents of the Graph
*********************************************************/
void custom::Graph::clear()
{
   if (matrix)
   {
      for(int j = 0; j < capacity(); j++)
         matrix[j] = false;
   }

   edges = 0;
}

/*********************************************************
* Graph :: ADD
* A setter to add an edge between two vertices
*********************************************************/
void custom::Graph::add(const Vertex & v1, const Vertex & v2)
{
   assert((v1.index() < vertices) && (v2.index() < vertices));   
   if (matrix)
      matrix[(v1.index() * vertices) + v2.index()] = true;   
}

/*********************************************************
* Graph :: ADD (set)
* A setter to add edges between vertex and a set of other vertices
*********************************************************/
void custom::Graph::add(const Vertex & v1, const set<Vertex> & vSet)
{
   for (set<Vertex>::const_iterator it = vSet.cbegin(); it != vSet.cend(); ++it)
      add(v1, *it);
}

/*********************************************************
* Graph :: Is Edge
* Indicates whether an edge exists between 2 vertices
*********************************************************/
bool custom::Graph::isEdge(const Vertex & v1, const Vertex & v2) const
{
   assert((v1.index() < vertices) && (v2.index() < vertices));   
   return matrix[(v1.index() * vertices) + v2.index()];
}

/*********************************************************
* Graph :: Find Edges
* retrieves a set of all the edges relating to a given vertex
*********************************************************/  
set <Vertex> custom::Graph::findEdges(const Vertex & v)
{
   assert(v.index() < vertices);      
   set <Vertex> output;
   int vi = v.index() * vertices;
   
   for(int i = 0;i < vertices;i++)
   {      
      if(matrix[vi + i])
         output.insert(Vertex(i));
   }
   return output;
}

/*********************************************************
* Graph :: Find Path
* Returns a list of nodes leading from one vertex to another
*********************************************************/
list <Vertex> custom::Graph::findPath(const Vertex & v1, const Vertex & v2)
{

   assert((v1.index() < vertices) && (v2.index() < vertices));
   int distance = 0;
   list <Vertex> toVisit;
   list <Vertex> path;
   toVisit.push_back(v1);
   int distances[size()];
   for (int i = 0; i < size(); i++)
      distances[i] = -1;

   Vertex predecessor[size()];
   while(!toVisit.empty() && distances[v2.index()] == -1)
   {
      Vertex v = toVisit.front();
      toVisit.pop_front();

      if(distances[v.index()] > distance)
         distance++;
      
      set<Vertex> s = findEdges(v);
      for(set<Vertex>::iterator it = s.begin(); it != s.end(); it++)
      {
         if(distances[(*it).index()] == -1)
         {
            distances[(*it).index()] = distance + 1;
            predecessor[(*it).index()] = v;
            toVisit.push_back(*it);
         }
         distance++;         
      }
   }

   if(distances[v2.index()] == -1)
      cout << "Error in " << __FILE__ << ", line " << __LINE__ << endl;
   path.push_back(v2);
   
   list<Vertex>::iterator it = path.begin();
   for(int i = 0;i < distance;i++, it++)
      path.push_back(predecessor[(*it).index()]);
   
   return path;                                    
}
