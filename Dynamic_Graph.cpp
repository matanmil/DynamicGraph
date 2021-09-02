
#include "Dynamic_Graph.h"
Dynamic_Graph::~Dynamic_Graph() {

    Graph_Node* current = head_adjList;
    while( current !=NULL)
    {
        Graph_Node* next =current->Get_Next_Node();
        delete current;
        current = next;
    }
    head_adjList =NULL;
    tail_adjList =NULL;
    num_node = 0;

}

Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key) {
    Graph_Node* new_node = new Graph_Node(node_key);
    new_node->Set_Next_Node(NULL);

    if (tail_adjList == NULL)
    {
        head_adjList = new_node;
        tail_adjList = new_node;
        new_node ->Set_Prev_Node(NULL);

    }
    else
    {
        tail_adjList->Set_Next_Node(new_node);

        new_node->Set_Prev_Node(tail_adjList);
        tail_adjList = new_node;

    }

    Inc_num_node();
    return new_node;
}
void Dynamic_Graph::Delete_Node(Graph_Node* node){
    if (head_adjList!=NULL && node != NULL) {
        unsigned get_in;
        unsigned get_out;
        get_out = node-> Get_out_Degree();
        get_in= node->Get_in_Degree();
        if ((get_out ==0) && (get_in == 0)) {

            // first node
            if (head_adjList == tail_adjList) {
                head_adjList = NULL;
                tail_adjList = NULL;

            } else if (node == head_adjList) {
                head_adjList = head_adjList->Get_Next_Node();
                if (head_adjList) {
                    head_adjList->Set_Prev_Node(NULL);
                }
            } else if (node == tail_adjList) {
                tail_adjList = tail_adjList->Get_Prev_Node();
                if (tail_adjList) {
                    tail_adjList->Set_Next_Node(NULL);
                }
                node->Set_Next_Node(NULL);
            } else {
                node->Get_Next_Node()->Set_Prev_Node(node->Get_Prev_Node());
                node->Get_Prev_Node()->Set_Next_Node(node->Get_Next_Node());
            }
            Dc_num_node();
            delete node;
        }
    }
}


Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to) {
    Graph_Edge* new_edge = new Graph_Edge(from,to);
    new_edge->Set_Next_Edge(NULL);
    from->Inc_Out_Degree();
    to->Inc_In_Degree();
    from->Insert_Edge(new_edge,from_list);
    to->Insert_Edge(new_edge,to_list);
    return new_edge;
}

void Dynamic_Graph::Delete_Edge(Graph_Edge* edge) {
    Graph_Node* from_node_to_delete = edge->Get_From_Node();
    Graph_Node* to_node_to_delete = edge->Get_To_Node();
    from_node_to_delete->Delete_Edge(edge,from_list);
    to_node_to_delete->Delete_Edge(edge,to_list);

    if (edge !=NULL){
        edge->Get_From_Node()->Dc_Out_Degree();
        edge->Get_To_Node()->Dc_In_Degree();
        delete edge;
    }
}

void Dynamic_Graph::BFS_Initialization(Graph_Node* source)const {
    Graph_Node* clearance = head_adjList;
    while ((clearance != NULL))
    {
        clearance->Set_color(white);
        clearance->Set_distance(-1);
        clearance->Set_parent(NULL);
        clearance = clearance->Get_Next_Node();
    }
    source->Set_color(gray);
    source->Set_distance(0);
    source->Set_parent(NULL);
}

Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source)const {
    Rooted_Tree* new_rooted_tree = new Rooted_Tree(num_node);
    Queue<Graph_Node*> graph_que(num_node);
    Queue<T_Node*> tree_que(num_node);

    new_rooted_tree->Set_root(new T_Node(source->Get_key()));//initialize root of the Rooted_Tree
    new_rooted_tree->Get_root()->origenNode = source;
    BFS_Initialization(source);
    graph_que.enqueue(source);
    tree_que.enqueue(new_rooted_tree->Get_root());

    Graph_Node* u_g = NULL;
    T_Node* u_t = NULL;
    Graph_Node* v_g = NULL;
    T_Node* v_t = NULL;
    Graph_Edge* pointer = NULL;

    while(!graph_que.isEmpty()){
        u_g = graph_que.peek();
        graph_que.dequeue();

        u_t = tree_que.peek();
        tree_que.dequeue();

        pointer = u_g->Get_tail_list_edge();
        while(pointer != NULL)
        {
            v_g = pointer->Get_To_Node();
            if (v_g->Get_color()== white){
                v_t = new T_Node(v_g->Get_key());
                v_t->origenNode = v_g;
                v_t->Set_Parent(u_t);
                if(u_t->Get_Left_Child()){
                    T_Node* rightSibCheck = u_t->Get_Left_Child();
                    while(rightSibCheck->Get_Right_Sibling()){
                        rightSibCheck = rightSibCheck->Get_Right_Sibling();
                    }
                    rightSibCheck->Set_Right_Sibling(v_t);
                }else{
                    u_t->Set_Left_Child(v_t);
                    // T_Node_que.enqueue(u_t);
                }
                v_g->Set_color(gray);
                v_g->Set_distance((u_g->Get_distance())+1);
                v_g->Set_parent(u_g);
                graph_que.enqueue(v_g);
                tree_que.enqueue(v_t);
            }
            pointer = pointer->Get_Prev_Edge();

        }
    }
    return new_rooted_tree;
}

Stack<Graph_Node*>& Dynamic_Graph::DFS_Queue(Stack<Graph_Node*>& node_que,
        Queue<Graph_Node*>& node_DFS,Graph_Node* tail)const
{
    unsigned time_step =0;
    Graph_Node *source = tail;
    source->Set_color(gray);// source->Set_distance(0);
    source->Set_parent(NULL);
    node_DFS.enqueue(source);

    Graph_Node* v_g = NULL;
    T_Node* u_t = NULL;


    node_que = DFS_Visited(source,time_step, node_que,v_g,node_DFS);

    return node_que;

}
Rooted_Tree* Dynamic_Graph::DFS(Queue<Graph_Node*>& node_que,Rooted_Tree* tree,
                                Stack<Graph_Node*>& scc_node_que,Queue<T_Node*>&
                                        tree_que_test)const {

    Graph_Node* clearance = head_adjList;

    unsigned time_step =0;
    while ((clearance != NULL))
    {
        clearance->Set_color(white);
        clearance->Reset_Dis_Time();
        clearance->Reset_Re_Time();
        clearance->Set_parent(NULL);
        clearance = clearance->Get_Next_Node();
    }
    //Graph_Node *source = tail_adjList;
    unsigned zero =0;
    // Graph_Node* root(zero);

    tree->Set_root(new T_Node(zero));
    Graph_Node *source = scc_node_que.peek();

    source->Set_color(gray);
    source->Set_distance(0);
    Graph_Node* root(0);

    source->Set_parent(root);
    Graph_Node* v_g = NULL;
    T_Node* u_t = NULL;

    while (!scc_node_que.isEmpty()) {

        while  ((!scc_node_que.isEmpty())&&(scc_node_que.peek()->Get_color() == black)
        ) {
            scc_node_que.pop();
        }
        if (scc_node_que.isEmpty())
        {
            break;
        }

        while(!node_que.isEmpty())
        {
            node_que.dequeue();
            tree_que_test.dequeue();
        }

        source=scc_node_que.peek();
        T_Node* source_T = new T_Node(tree->Get_root());
        source_T ->Set_Key(source->Get_key());
        node_que.enqueue(source);
        tree_que_test.enqueue(source_T);
        if(tree->Get_root()->Get_Left_Child()){
            T_Node* rightSibCheck = tree->Get_root()->Get_Left_Child();
            while(rightSibCheck->Get_Right_Sibling()){
                rightSibCheck = rightSibCheck->Get_Right_Sibling();
            }
            rightSibCheck->Set_Right_Sibling(source_T);

        }else{
            tree->Get_root()->Set_Left_Child(source_T);

        }
        tree = DFS_Visited_trans(source, time_step, node_que, tree, v_g, u_t,
                                      source_T,tree_que_test);

    }
    return tree;

}

Stack<Graph_Node*>& Dynamic_Graph::DFS_Visited(Graph_Node* u_node, unsigned time_step,
        Stack<Graph_Node*>& node_que,Graph_Node* v_g,Queue<Graph_Node*>& node_DFS)const {
    time_step = time_step +1;

    Graph_Edge* pointer = NULL;
    pointer = u_node->Get_tail_list_edge();
    u_node->Set_Dis_Time(time_step);

    u_node->Set_color(gray);

    while(pointer != NULL)
    {
        v_g = pointer->Get_To_Node();

        if(v_g->Get_color() == white) {
            node_DFS.enqueue(u_node);
            node_que = DFS_Visited(v_g, time_step, node_que,v_g,node_DFS);
        }

        pointer = pointer->Get_Prev_Edge();
    }

    u_node->Set_color(black);

    time_step = time_step +1;
    u_node->Set_Re_Time(time_step);
    node_que.push(u_node);
    node_DFS.dequeue();
    return node_que;
}
Rooted_Tree* Dynamic_Graph::DFS_Visited_trans(Graph_Node *u_node, unsigned time_step,
                                                   Queue<Graph_Node*>& node_que,Rooted_Tree* tree,
                                                   Graph_Node* v_g ,T_Node* u_t,T_Node*
                                                   v_t,Queue<T_Node*>&
tree_que_test) const{
    time_step = time_step +1;


    Graph_Edge* pointer = NULL;
    pointer = u_node->Get_tail_to_list_edge();
    u_node->Set_Dis_Time(time_step);

    u_node->Set_color(gray);
    u_t =  v_t;

    while(pointer != NULL)
    {
        v_g = pointer->Get_From_Node();

        if(v_g->Get_color() == white) {
            node_que.enqueue(u_node);

            v_t = new T_Node(v_g->Get_key());
            v_t->Set_Parent(u_t);
            tree_que_test.enqueue(v_t);
            if (u_t->Get_Left_Child()) {
                T_Node *rightSibCheck = u_t->Get_Left_Child();
                while (rightSibCheck->Get_Right_Sibling()) {
                    rightSibCheck = rightSibCheck->Get_Right_Sibling();
                }
                rightSibCheck->Set_Right_Sibling(v_t);

            } else {
                u_t->Set_Left_Child(v_t);
            }

            tree = DFS_Visited_trans(v_g, time_step, node_que,tree, v_g, u_t, v_t,tree_que_test);

        }

        pointer = pointer->Get_Prev_Edge_To_List();

    }

    u_node->Set_color(black);
    time_step = time_step +1;
    u_node->Set_Re_Time(time_step);
    node_que.dequeue();
    tree_que_test.dequeue();
    return tree;

}

Rooted_Tree* Dynamic_Graph::SCC() const
{

    Rooted_Tree* new_rooted_tree = new Rooted_Tree(num_node+1);
    Stack<Graph_Node*> scc_node_que(num_node);
    Queue<Graph_Node*>node_que(num_node);
    Queue<T_Node*> tree_que_test(num_node);
    Graph_Node* clearance = head_adjList;
    unsigned time_step =0;
    while ((clearance != NULL))
    {
        clearance->Set_color(white);
        clearance->Reset_Dis_Time();
        clearance->Reset_Re_Time();
        clearance->Set_parent(NULL);
        clearance = clearance->Get_Next_Node();
    }





    Graph_Node* linkednotes =tail_adjList;


    while((linkednotes!=NULL) ) {
        if (linkednotes->Get_color()==white) {
            scc_node_que = DFS_Queue(scc_node_que, node_que, linkednotes);
        }
        Graph_Node* next = linkednotes->Get_Prev_Node();
                linkednotes = next;

    }


    new_rooted_tree = DFS(node_que,new_rooted_tree,scc_node_que,tree_que_test);
    return new_rooted_tree;

}
