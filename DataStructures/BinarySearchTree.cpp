#include<iostream>

class BST
{
public:
    BST();
    BST(const BST& other);
    ~BST();
    bool contains(int toFind) const;
    bool insert(int toAdd);
    bool remove(int toDelete);
private:
    struct Node
    {
        int data;
        Node* left;
        Node* right;
        Node(const int& data) : data(data), left(nullptr), right(nullptr){}
    };
    Node* root = nullptr;

    Node** getMin(Node** curr)
    {
        while((*curr)->left)
        {
            curr = &(*curr)->left;
        }
        return curr;
    }

    void free(Node* root);
    Node* copyFrom(const Node* root);
};

BST::BST() : root(nullptr){}

BST::BST(const BST& other)
{
    root = copyFrom(other.root);
}

BST::~BST()
{
    free(root);
    root = nullptr;
}

bool BST::contains(int toFind) const
{
    Node* curr = root;

    while(curr)
    {
        if(curr->data == toFind)
        {
            return true;
        }
        else if(toFind < curr->data)
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }
    return false;
}

/*
       5
    3     8
  1   2  6  15
*/
bool BST::insert(int toAdd)
{
    Node** curr = &root;

    while(*curr)
    {
        if((*curr)->data == toAdd)
        {
            return false;
        }
        else if (toAdd < (*curr)->data)
        {
            curr = &(*curr)->left;
        }
        else
        {
            curr = &(*curr)->right;
        }  
    }
    *curr = new Node(toAdd);
    return true;
}

bool BST::remove(int toDelete)
{
    Node** curr = &root;

    while(*curr)
    {
        if((*curr)->data == toDelete)
        {
            if(!(*curr)->left && !(*curr)->right) // if leaf
            {
                delete* curr;
                *curr = nullptr;
                return true;
            }
            else if(!(*curr)->right) //if el has only left child
            {
                Node* toDeleteNode = *curr;
                *curr = (*curr)->left;
                delete toDeleteNode;
                return true;
            }
            else if(!(*curr)->left) //if el has only right child
            {
                Node*  toDeleteNode = *curr;
                *curr = (*curr)->right;
                delete toDeleteNode;
                return true;
            }
            else //if el has left and right child
            {
                Node** minFromRight = getMin(&(*curr)->right); // minFromRight or maxFromLeft

                Node* toDelete = *curr;
                Node* replacement = *minFromRight;

                replacement->left = toDelete->left;
                (*minFromRight) = replacement->right;

                replacement->right = toDelete->right;
                (*curr) = replacement;
                delete toDelete;
                return true;
            }
        }
        else if(toDelete < (*curr)->data)
        {
            curr = &(*curr)->left;
        }
        else
        {
            curr = &(*curr)->right;
        }
    }
    return false;
}

void BST::free(Node* root)
{
    if(!root)
        return;
    
    free(root->left);
    free(root->right);
    delete root;
}

BST::Node* BST::copyFrom(const Node* root)
{
    if(!root)
    {
        return nullptr;
    }

    Node* result = new Node(root->data);
    result->left = copyFrom(root->left);
    result->right = copyFrom(root->right);

    return result;
}
int main()
{
    std::cout << "No examples :(";

}