

#ifndef DYNAMIC_202_T_NODE_H
#define DYNAMIC_202_T_NODE_H
#include <cstddef>
#include "Graph_Node.h"

class T_Node {
private:
    T_Node* Left_Child;
    T_Node* Right_Sibling;
    T_Node* Parent;
    unsigned T_Node_Key;
    bool _visted = NULL;
public:
    T_Node(T_Node* parent): Parent(parent),Right_Sibling(NULL),Left_Child(NULL),
    T_Node_Key(0U),_visted(false){};
    T_Node(unsigned T_Node_Key): Parent(NULL),T_Node_Key(T_Node_Key),Right_Sibling
    (NULL),Left_Child(NULL){};
    ~T_Node();
    void Set_Left_Child(T_Node* Node_Left_Child);
    T_Node * Get_Left_Child(){return Left_Child;};
    void Set_Right_Sibling(T_Node* Node_Right_Sibling);
    T_Node * Get_Right_Sibling(){return Right_Sibling;};
    void Set_Parent(T_Node* Node_Parent);
    T_Node * Get_Parent(){return Parent;};
    unsigned Get_Key(){return T_Node_Key;};
    bool isVisited();
    void Set_IsVisited(bool visted);
    void Set_Key(unsigned key){T_Node_Key = key;};
    Graph_Node* origenNode = NULL;

};


#endif //DYNAMIC_202_T_NODE_H
