#include <cstddef>
#include "Graph_Node.h"
#include <iostream>

Graph_Node::~Graph_Node() {

    Graph_Edge* current = head_list_edge;
    while( current !=NULL)
    {
        Graph_Edge* next =current->Get_Next_Edge();
        delete current;
        current = next;
    }




    Next_Node =NULL ;
      Prev_Node = NULL ;
      _parent = NULL;
      DegIn = 0;
     DegOut = 0;
     _distance = 0;
     tail_to_list_edge = NULL;
     head_to_list_edge = NULL;





}

void Graph_Node::Insert_Edge(Graph_Edge* new_edge, from_to_list list_option) {

    if(list_option == from_list)
    {

        if (tail_list_edge == NULL)
        {

            head_list_edge = new_edge;
            tail_list_edge = new_edge;
            new_edge ->Set_Prev_Edge(NULL);
        }
        else
        {
            tail_list_edge->Set_Next_Edge(new_edge);
            new_edge->Set_Prev_Edge(tail_list_edge);
            tail_list_edge = new_edge;
        }

    }
    if(list_option == to_list)
    {
        if (tail_to_list_edge == NULL)
        {

            head_to_list_edge = new_edge;
            tail_to_list_edge = new_edge;
            new_edge ->Set_Prev_Edge_To_List(NULL);
        }
        else
        {
            tail_to_list_edge->Set_Next_Edge_To_List(new_edge);
            new_edge->Set_Prev_Edge_To_List(tail_to_list_edge);
            tail_to_list_edge = new_edge;
        }

    }



}

void Graph_Node::Delete_Edge(Graph_Edge* edge,from_to_list list_option) {

    if(list_option == from_list)
    {
        if (head_list_edge==NULL && edge == NULL)
        {
            return;
        }
        // first edge
        if(head_list_edge == tail_list_edge)
        {
            head_list_edge = NULL;
            tail_list_edge = NULL;

        }
        else if( edge == head_list_edge){
            head_list_edge = head_list_edge->Get_Next_Edge();
            if(head_list_edge){
                head_list_edge->Set_Prev_Edge(NULL);
            }
        } else if(edge == tail_list_edge){
            tail_list_edge = tail_list_edge->Get_Prev_Edge();
            if(tail_list_edge){
                tail_list_edge->Set_Next_Edge(NULL);
            }

        }else{
            edge->Get_Next_Edge()->Set_Prev_Edge(edge->Get_Prev_Edge());
            edge->Get_Prev_Edge()->Set_Next_Edge(edge->Get_Next_Edge());

        }

    }
    if(list_option == to_list) {
        if (head_to_list_edge==NULL && edge == NULL){
            return;
        }
        // first edge
        if(head_to_list_edge == tail_to_list_edge){
            head_to_list_edge = NULL;
            tail_to_list_edge = NULL;

        }
        else if( edge == head_to_list_edge){
            head_to_list_edge = head_to_list_edge->Get_Next_Edge_To_List();
            if(head_to_list_edge){
                head_to_list_edge->Set_Prev_Edge_To_List(NULL);
            }
        } else if(edge == tail_to_list_edge){
            tail_to_list_edge = tail_to_list_edge->Get_Prev_Edge_To_List();
            if(tail_to_list_edge){
                tail_to_list_edge->Set_Next_Edge_To_List(NULL);
            }

        }else{
            edge->Get_Next_Edge_To_List()->Set_Prev_Edge_To_List(edge->Get_Prev_Edge_To_List());
            edge->Get_Prev_Edge_To_List()->Set_Next_Edge_To_List(edge->Get_Next_Edge_To_List());
        }
    }
}
void Graph_Node::Set_color(color set_color) {
    _color = set_color;
}

void Graph_Node::Set_parent(Graph_Node *parent) {
    _parent = parent;
}

void Graph_Node::Set_distance(int new_distance) {

_distance = new_distance;
}

