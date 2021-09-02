

#include "Graph_Edge.h"


Graph_Node* Graph_Edge::Get_From_Node()
{
    return  from_node;
}

Graph_Node* Graph_Edge::Get_To_Node()
{
    return  to_node;
}

Graph_Edge::~Graph_Edge() {
     Next_Edge = NULL;
     Prev_Edge =  NULL;
     from_node = NULL;
     to_node= NULL;

     Next_Edge_To_List = NULL;
     Prev_Edge_To_List = NULL;
}

void Graph_Edge::Set_From_Node(Graph_Node* from) {
    from_node = from;
}

void Graph_Edge::Set_To_Node( Graph_Node* to) {
    to_node = to;
}

