#include <cstddef>

#ifndef MATAN_DYNAMIC_GRAPH_H
#define MATAN_DYNAMIC_GRAPH_H


#include "Graph_Node.h"
#include "Graph_Edge.h"
#include <iostream>
#include "Rooted_Tree.h"
#include "Queue.h"
#include "T_Node.h"
#include "Stack.h"


class Dynamic_Graph {
     Graph_Node* head_adjList ;
     Graph_Node* tail_adjList ;
     unsigned num_node;
    Dynamic_Graph (Dynamic_Graph& dynamic_graph){};

public:
    Dynamic_Graph(): head_adjList(NULL), tail_adjList(NULL),num_node(0U){};
    ~Dynamic_Graph();
    void Set_head_adjList(Graph_Node* list_head){head_adjList = list_head;
        std::cout <<"&&&&&!!!"<<Get_head();
    };
    void Set_tail_adjList(Graph_Node* list_tail){tail_adjList = list_tail;};
    Graph_Node* Get_head(){return head_adjList;};
    Graph_Node* Get_tail(){return tail_adjList;};

    Graph_Node* Insert_Node(unsigned node_key);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);
    void Inc_num_node(){ num_node++;};
    void Dc_num_node(){num_node--;};
    Rooted_Tree* BFS(Graph_Node* source) const;
    void Delete_Node(Graph_Node* node);
    Rooted_Tree* SCC() const;
    Stack<Graph_Node*>&  DFS_Queue(Stack<Graph_Node*>& node_que,Queue<Graph_Node*>&
            node_DFS,Graph_Node* tail)const;
    Rooted_Tree* DFS(Queue<Graph_Node*>& node_que,Rooted_Tree* tree,Stack<Graph_Node*>&
            scc_node_que,Queue<T_Node*>&
    tree_que_test)const;
    Stack<Graph_Node*>&  DFS_Visited(Graph_Node* u_node,unsigned time_step,
            Stack<Graph_Node*>& node_que,Graph_Node* v_g,Queue<Graph_Node*>& node_DFS)const;

   Rooted_Tree* DFS_Visited_trans(Graph_Node *u_node, unsigned time_step,
                                                Queue<Graph_Node*>& node_que,Rooted_Tree* tree,
                                                Graph_Node* v_g ,T_Node* u_t,T_Node*
                                                v_t,Queue<T_Node*>&
   tree_que_test) const;



    void BFS_Initialization(Graph_Node *source) const;
};


#endif //MATAN_DYNAMIC_GRAPH_H
