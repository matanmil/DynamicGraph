
#include "T_Node.h"

void T_Node::Set_Left_Child(T_Node *Node_Left_Child) {
    Left_Child = Node_Left_Child;

}

void T_Node::Set_Right_Sibling(T_Node *Node_Right_Sibling) {
    Right_Sibling = Node_Right_Sibling;

}

void T_Node::Set_Parent(T_Node *Node_Parent) {
    Parent = Node_Parent;

}

bool T_Node::isVisited() {
    return _visted;
}

void T_Node::Set_IsVisited(bool visted) {
    _visted = visted;
}

T_Node::~T_Node() {
    Left_Child = NULL;
    Right_Sibling = NULL;
    Parent = NULL;

}


