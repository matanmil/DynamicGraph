

#ifndef DYNAMIC_GRAPH2_ROOTED_TREE_H
#define DYNAMIC_GRAPH2_ROOTED_TREE_H

#include <ostream>
#include <cstddef>
#include "T_Node.h"
#include "Queue.h"

class Rooted_Tree {
private:
    T_Node* root;
    unsigned size_tree;
    unsigned time_step;

public:
    Rooted_Tree(): root(NULL),size_tree(0U){};
    Rooted_Tree(unsigned size_tree): root(NULL),size_tree(size_tree),time_step(0U){};
    ~Rooted_Tree();
    void Set_root(T_Node* source);
    T_Node* Get_root(){return root;};
    void Print_By_Layer(std::ostream& stream) const;
    void Restet_Time_Step(){time_step = 0;};
    void Dec_Time_Step(){time_step--;};
    void In_Time_Step(){time_step--;};
    void Preorder_Print(std::ostream& stream) const;
    void Preorder_Print_help(T_Node* x)const;
    void Preorder_Print_help2(T_Node* x) const;
    void clear_tree(T_Node *x);

};


#endif //DYNAMIC_GRAPH2_ROOTED_TREE_H
