#include<iostream>
#include<queue>
#include<stack>

class BT
{
private:
    struct Node
    {
        int data;
        Node* left;
        Node* right;
        Node(int _data) : data(_data), left(nullptr), right(nullptr){}
    };
    Node* root;

    void free(Node* root);
    Node* copyFrom(const Node* root);

    bool containsDFS(Node* node, int el) const;

public:
    BT();
    BT(const BT& other);
    ~BT();

    bool isEmpty() const;

    void insertLevelOrder(int el);
    bool contains(int el) const;

    class Iterator
    {
    private:
        std::stack<Node*> st;

        void pushLeft(Node* node)
        {
            while(node)
            {
                st.push(node);
                node = node->left;
            }
        }
    public:
        Iterator(Node* root = nullptr)
        {
            pushLeft(root);
        }

        int& operator*()
        {
            return st.top()->data;
        }

        Iterator& operator++()
        {
            Node* top = st.top();
            st.pop();
            if(top->right)
            {
                pushLeft(top->right);
            }
            return *this;
        }

        bool operator!=(const Iterator& other) 
        {
            if(st.empty() || other.st.empty())
                return st.empty() != other.st.empty();
            return st.top() != other.st.top();
        }
    };

    Iterator begin()
    {
        return Iterator(root);
    }
    Iterator end()
    {
        return Iterator(nullptr);
    }

};

void BT::free(Node* root)
{
    if(!root)
        return;
    
    free(root->left);
    free(root->right);
    delete root;
}

BT::Node* BT::copyFrom(const Node* root)
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

bool BT::containsDFS(Node* node, int el) const
{
    if(!node)
        return false;
    
    if(node->data == el)
        return true;

    return containsDFS(node->left, el) || containsDFS(node->right, el);
}

BT::BT() : root(nullptr){}

BT::BT(const BT& other)
{
    root = copyFrom(other.root);
}

BT::~BT()
{
    free(root);
    root = nullptr;
}

bool BT::isEmpty() const
{
    return root == nullptr;
}

void BT::insertLevelOrder(int el)
{
    Node* toAdd = new Node(el);
    if(isEmpty())
    {
        root = toAdd;
        return;
    }

    std::queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        Node* curr = q.front();
        q.pop();

        if(!curr->left)
        {
            curr->left = toAdd;
            return;
        }
        else
        {
            q.push(curr->left);
        }

        if(!curr->right)
        {
            curr->right = toAdd;
            return;
        }
        else
        {
            q.push(curr->right);
        }
    }
}

bool BT::contains(int el) const
{
    return containsDFS(root, el);
}

int main()
{
    BT t;

    t.insertLevelOrder(10);
    t.insertLevelOrder(5);
    t.insertLevelOrder(20);
    t.insertLevelOrder(3);
    t.insertLevelOrder(7);
    t.insertLevelOrder(15);


    std::cout << "contains(7) = " << t.contains(7) << "\n";
    std::cout << "contains(100) = " << t.contains(100) << "\n";

    std::cout << "Inorder iterator: ";
    for (auto it = t.begin(); it != t.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}