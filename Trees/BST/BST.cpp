#include <iostream>

#define DEBUG false

struct t_Node
{
    int node_data;
    t_Node *left;
    t_Node *right;
    t_Node(int newdata) : node_data(newdata), left(nullptr), right(nullptr) {}
};

class tree
{
private:
public:
    t_Node *root;
    tree();
    t_Node *insert(int, t_Node *);
};

tree::tree()
{
    root = nullptr;
}

t_Node *tree::insert(int newdata, t_Node *ptr)
{
    DEBUG == true ? std::cout << __FUNCTION__ << std::endl : std::cout;

    if (!ptr)
    {
        DEBUG == true ? std::cout << " creating new node with " << newdata << std::endl : std::cout;
        return new t_Node(newdata);
    }

    if (newdata < ptr->node_data)
    {
        DEBUG == true ? std::cout << " new data is smaller " << newdata << std::endl : std::cout;
        
        ptr->left = insert(newdata, ptr->left);
    }

    else //(newdata > ptr->node_data)
    {
        DEBUG == true ? std::cout << " new data is bigger " << newdata << std::endl : std::cout;
        
        ptr->right = insert(newdata, ptr->right);
    }

    return ptr;
}

int main()
{
    tree obj;

    DEBUG == true ? std::cout << "  insert 2 " << std::endl : std::cout;
        
    obj.root = obj.insert(2, obj.root);
    DEBUG == true ? std::cout << "  insert 1 " << std::endl : std::cout;
    obj.root = obj.insert(1, obj.root);
    DEBUG == true ? std::cout << "  insert 3 " << std::endl : std::cout;
    obj.root = obj.insert(3, obj.root);

    std::cout << obj.root->node_data << std::endl;
    std::cout << obj.root->left->node_data << std::endl;
    std::cout << obj.root->right->node_data << std::endl;

    return 0;
}