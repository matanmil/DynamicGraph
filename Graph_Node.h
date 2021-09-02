

#ifndef MATAN_GRAPH_NODE_H
#define MATAN_GRAPH_NODE_H


#include <cstddef>
#include "Graph_Edge.h"


typedef enum { white, gray, black} color;
typedef enum { from_list, to_list} from_to_list;
class Graph_Node {

private:
    unsigned node_key_;
    unsigned DegIn ;
    unsigned DegOut ;
    Graph_Node* Next_Node;
    Graph_Node* Prev_Node;

    Graph_Edge* head_list_edge;
    Graph_Edge* tail_list_edge;

    Graph_Edge* head_to_list_edge;
    Graph_Edge* tail_to_list_edge;

    color _color;
    int _distance;
    Graph_Node* _parent;
    unsigned discovery_time;
    unsigned retraction_time;
    Graph_Node (Graph_Node& graph_node){};

public:

    Graph_Node(unsigned node_key):node_key_(node_key),DegIn(0), DegOut(0),Next_Node
    (NULL),Prev_Node(NULL),head_list_edge(NULL),tail_list_edge(NULL),_color(white),
    _distance(0),_parent(NULL),discovery_time(0U),retraction_time(0U),head_to_list_edge
    (NULL),tail_to_list_edge(NULL){};

    ~Graph_Node();
    unsigned Get_out_Degree() const {return DegOut;};
    unsigned Get_in_Degree() const {return DegIn;};
    Graph_Edge* Get_head_list_edge()const {return head_list_edge;};
    Graph_Edge* Get_tail_list_edge()const {return tail_list_edge;};
    Graph_Edge* Get_head_to_list_edge()const {return head_to_list_edge;};
    Graph_Edge* Get_tail_to_list_edge()const {return tail_to_list_edge;};
    unsigned Get_key() const{return  node_key_;};
    void Inc_Out_Degree(){ DegOut++;};
    void Inc_In_Degree(){DegIn++;};
    void Set_Dis_Time(unsigned time){ discovery_time =time ;};
    void Set_Re_Time(unsigned time){retraction_time = time;};

    void Reset_Dis_Time(){discovery_time = 0;};
    void Reset_Re_Time(){retraction_time = 0;};
    unsigned Get_Dis_Time(){ return discovery_time;};
    unsigned Get_Retraction_Time(){ return retraction_time;};
    void Dc_Out_Degree(){DegOut--;};
    void Dc_In_Degree(){ DegIn--;};
    void Set_Next_Node(Graph_Node* to){Next_Node = to;};
    Graph_Node * Get_Next_Node()const {return Next_Node;};
    void Set_Prev_Node(Graph_Node* from){Prev_Node = from;};
    Graph_Node * Get_Prev_Node()const { return Prev_Node;};
    void Insert_Edge(Graph_Edge* new_edge, from_to_list list_option);
    void Delete_Edge (Graph_Edge* edge, from_to_list list_option);
    void Set_color(color set_color);
    color Get_color(){ return _color;};
    void Set_distance(int new_distance);
    unsigned Get_distance(){return _distance;};
    void Set_parent(Graph_Node* parent);
    Graph_Node * Get_parent()const{return _parent;};


};


#endif //MATAN_GRAPH_NODE_H
