#ifndef mTree_h
#define mTree_h

#include <algorithm>

template<typename T> class AVLNode
{
public:
    AVLNode<T>* left, *right;
    std::size_t key;
    T data;
    int height;
    AVLNode(std::size_t _key = 0, T _data = T(), AVLNode<T>* _left = NULL, AVLNode<T>* _right = NULL, int _height = 1) : left(_left), right(_right), key(_key), data(_data), height(_height) {}
};

template<typename T> class AVLTree
{
public:
    AVLNode<T>* root = NULL;
    int getHeight(AVLNode<T>* root)
    {
        if (root != NULL) return root->height;
        else return 0;
    }
    int getBalanceFactor(AVLNode<T>* root)
    {
        if (root == NULL) return 0;
        else return (getHeight(root->left) - getHeight(root->right));
    }
    AVLNode<T>* leftrotate(AVLNode<T>* root)
    {
        AVLNode<T>* b = root->right;
        root->right = b->left;
        b->left = root;
        root->height = std::max(getHeight(root->left), getHeight(root->right) + 1);
        b->height = std::max(getHeight(b->left), getHeight(b->right) + 1);
        return b;
    }
    AVLNode<T>* rightrotate(AVLNode<T>* root)
    {
        AVLNode<T>* b = root->left;
        root->left = b->right;
        b->right = root;
        root->height = std::max(getHeight(root->left), getHeight(root->right) + 1);
        b->height = std::max(getHeight(b->left), getHeight(b->right) + 1);
        return b;
    }
    AVLNode<T>* insert(AVLNode<T>* root, std::size_t key, T data)
    {
        if (this->find(key) != NULL) return root;
        else
        {
            if (root == NULL) return new AVLNode<T>(key, data);
            if (key < root->key)
                root->left = insert(root->left, key, data);
            else
                root->right = insert(root->right, key, data);
            root->height = 1 + std::max((getHeight(root->left)), getHeight(root->right));
            int balancefactor = getBalanceFactor(root);
            if (balancefactor > 1)
                if (key < root->left->key)
                    root = rightrotate(root);
                else if (key > root->left->key)
                {
                    root->left = leftrotate(root->left);
                    root = rightrotate(root);
                }
            if (balancefactor < -1)
                if (key > root->right->key)
                    root = leftrotate(root);
                else if (key < root->right->key)
                {
                    root->right = rightrotate(root->right);
                    root = leftrotate(root);
                }
            return root;
        }
    }
    AVLNode<T>* remove(AVLNode<T>* root, std::size_t key)
    {
        if (this->find(key) == NULL) return NULL;
        else {
            if (root == NULL) return root;
            else {
                if (key < root->key)
                    root->left = remove(root->left, key);
                else if (key > root->key)
                    root->right = remove(root->right, key);
                else
                {
                    if (root->left == NULL || root->right == NULL)
                    {
                        AVLNode<T>* tmp;
                        if (root->left) tmp = root->left;
                        else tmp = root->right;
                        if (tmp == NULL) {
                            tmp = root;
                            root = NULL;
                        }
                        else *root = *tmp;
                        delete tmp;
                    }
                    else
                    {
                        AVLNode<T>* tmp = root->right;
                        while (tmp->left != NULL)
                            tmp = tmp->left;
                        root->key = tmp->key;
                        root->right = remove(root->right, tmp->key);
                    }
                }
            }
            if (root == NULL) return NULL;
            root->height = 1 + std::max(getHeight(root->left), getHeight(root->right));
            int balancefactor = getBalanceFactor(root);
            if (balancefactor > 1)
                if (getBalanceFactor(root->left) >= 0)
                    root = rightrotate(root);
                else
                {
                    root->left = leftrotate(root->left);
                    root = rightrotate(root);
                }
            if (balancefactor < -1)
                if (getBalanceFactor(root->right) <= 0)
                    root = leftrotate(root);
                else
                {
                    root->right = rightrotate(root->right);
                    root = leftrotate(root);
                }
            return root;
        }
    }
    AVLNode<T>* find(std::size_t key)
    {
        AVLNode<T>* temp = root;
        while (temp != NULL)
        {
            if (key < temp->key) temp = temp->left;
            else if (key > temp->key) temp = temp->right;
            else return temp;
        }
        return NULL;
    }
    void insertNode(std::size_t key, T data)
    {
        root = this->insert(root, key, data);
    }
    void deleteNode(std::size_t key)
    {
        root = this->remove(root, key);
    }
    AVLNode<T>* findNode(std::size_t key)
    {
        return find(key);
    }
};

#endif
