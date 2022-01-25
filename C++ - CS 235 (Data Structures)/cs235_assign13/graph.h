/***********************************************************************
 * Header:
 *    Graph
 * Summary:
 *    
 * Author
 *    John Batty
 *    Jordon Thompson
 *    Brian Thompson
 *    Emmanuel Gatica
 *    Zach Caldwell
 ************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include "set.h"
#include "list.h"
#include "vertex.h"

namespace custom {
   class Graph
   {
      private:
         int vertices;
         int edges;
         bool * matrix;

      public:
         // constructors and destructors
         Graph(int vertices);
         Graph(const Graph & rhs);
         ~Graph();

         // asignment operator
         Graph & operator = (const Graph & rhs);

         // Standard Container Interfaces
         int size() const;
         int capacity() const;
         bool empty() const;
         void clear();

         // Graph methods
         void add(const Vertex & v1, const Vertex & v2);
         void add(const Vertex & v1, const set<Vertex> & vSet);
         bool isEdge(const Vertex & v1, const Vertex & v2) const;
         set <Vertex> findEdges(const Vertex & v);
         list <Vertex> findPath(const Vertex & v1, const Vertex & v2);
   };
}
#endif