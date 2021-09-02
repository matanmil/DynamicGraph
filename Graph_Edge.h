
#ifndef MATAN_GRAPH_EDGE_H
#define MATAN_GRAPH_EDGE_H


#include <cstddef>
#include <iostream>
//#include "Graph_Node.h"
class Graph_Node;

class Graph_Edge {
private:
    Graph_Node* from_node;
    Graph_Node* to_node;

    Graph_Edge* Next_Edge;
    Graph_Edge* Prev_Edge;

    Graph_Edge* Next_Edge_To_List;
    Graph_Edge* Prev_Edge_To_List;


public:
    Graph_Edge(Graph_Node* from_node, Graph_Node* to_node): from_node(from_node), to_node
    (to_node),Next_Edge(NULL),Prev_Edge(NULL),Next_Edge_To_List(NULL),
    Prev_Edge_To_List(NULL){};

    ~Graph_Edge();
    Graph_Node* Get_From_Node();
    Graph_Node* Get_To_Node();
    void Set_From_Node( Graph_Node* from);
    void Set_To_Node( Graph_Node* to);
    Graph_Edge* Get_Next_Edge(){ return Next_Edge;};
    Graph_Edge* Get_Prev_Edge(){ return Prev_Edge;};
    void Set_Next_Edge(Graph_Edge* next_edge_){ Next_Edge = next_edge_;};
    void Set_Prev_Edge(Graph_Edge* prev_edge_){ Prev_Edge = prev_edge_;};

    Graph_Edge* Get_Next_Edge_To_List(){ return Next_Edge_To_List;};
    Graph_Edge* Get_Prev_Edge_To_List(){ return Prev_Edge_To_List;};
    void Set_Next_Edge_To_List(Graph_Edge* next_edge_to){ Next_Edge_To_List =
                                                                  next_edge_to;};
    void Set_Prev_Edge_To_List(Graph_Edge* prev_edge_to){ Prev_Edge_To_List = prev_edge_to;};

};


#endif
