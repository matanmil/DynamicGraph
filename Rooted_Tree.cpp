

#include "Rooted_Tree.h"
#include "T_Node.h"
#include "Queue.h"
using std::cout;
using std::endl;
using std::string;

Rooted_Tree::~Rooted_Tree() {
    size_tree = 0;
    clear_tree(root);



}

void Rooted_Tree::clear_tree(T_Node* node)
{
    if (node == NULL)
        return;

    // first on left subtree
    clear_tree(node->Get_Left_Child());

    // then on right subtree
    clear_tree(node->Get_Right_Sibling());

    // now the node
    delete node;
}

void Rooted_Tree::Print_By_Layer(std::ostream &stream) const {
    Queue<T_Node *> queCurr(size_tree);
    Queue<T_Node *> queNext(size_tree);
    T_Node* iter = NULL;

    queCurr.enqueue(root);
    while ((!queCurr.isEmpty()) || (!queNext.isEmpty()))
    {
        while (!queCurr.isEmpty())
        {
            iter = queCurr.peek();
            if(iter->Get_Left_Child()){
                queNext.enqueue(iter->Get_Left_Child());
                iter = iter->Get_Left_Child();
                while(iter){
                    iter = iter->Get_Right_Sibling();
                    if(iter){
                        queNext.enqueue(iter);
                    }
                }
            }
            stream  <<  queCurr.peek()->Get_Key();
            queCurr.dequeue();
            if (!queCurr.isEmpty())
            {
                stream << ",";
            }else if((!queCurr.isEmpty()) || (!queNext.isEmpty())){
                stream << endl;
            }
        }
        while (!queNext.isEmpty())
        {
            iter = queNext.peek();
            if(iter->Get_Left_Child()){
                queCurr.enqueue(iter->Get_Left_Child());
                iter = iter->Get_Left_Child();
                while(iter){
                    iter = iter->Get_Right_Sibling();
                    if(iter){
                        queCurr.enqueue(iter);
                    }
                }
            }
            stream  <<  queNext.peek()->Get_Key();
            queNext.dequeue();
            if (!queNext.isEmpty())
            {
                stream << ",";
            }else if((!queCurr.isEmpty()) || (!queNext.isEmpty())){
                stream << endl;
            }
        }
    }
}



void Rooted_Tree::Set_root(T_Node *source) {
    root = source;

}

void Rooted_Tree::Preorder_Print(std::ostream &stream) const {

    Preorder_Print_help(root);
    Preorder_Print_help2(root);


}
void Rooted_Tree::Preorder_Print_help(T_Node* x) const
{
    if (x==NULL)
    {
        return;
    }
    else
    {
        if (x->isVisited()==false)
        {
            if(x!=root)
            {
                std::cout << ",";
            }
            std::cout << x->Get_Key();
            x->Set_IsVisited(true);
        }

        if(x->Get_Left_Child()!=NULL)
        {
            Preorder_Print_help(x->Get_Left_Child());
        }

        while(x->Get_Right_Sibling()!=NULL)
        {
            Preorder_Print_help(x->Get_Right_Sibling());
            x = x->Get_Right_Sibling();

        }
    }
}
void Rooted_Tree::Preorder_Print_help2(T_Node* x) const
{
    if (x==NULL)
    {
        return;
    }
    else
    {
        if (x->isVisited()==true)
        {
            x->Set_IsVisited(false);
        }

        if(x->Get_Left_Child()!=NULL)
        {
            Preorder_Print_help2(x->Get_Left_Child());
        }

        while(x->Get_Right_Sibling()!=NULL)
        {
            Preorder_Print_help2(x->Get_Right_Sibling());
            x = x->Get_Right_Sibling();

        }
    }
}
