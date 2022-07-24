#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <algorithm>

template <typename Object>
class AvlTree
{
private:
    struct Node
    {
        Object elem;
        Node *left;
        Node *right;
        int height;

        Node() : left(nullptr), right(nullptr), height(0) {}
        Node(const Object &object) : elem(object), left(nullptr), right(nullptr), height(0) {}
    };
    Node *root;

public:
    AvlTree()
    {
        root = nullptr;
    }

    ~AvlTree()
    {
        clear();
    }

    AvlTree(const AvlTree &) = delete;
    AvlTree &operator=(const AvlTree &) = delete;

    void clear()
    {
        root = clear(root);
    }

    Node *find(const Object &object) const
    {
        return find(root, object);
    }

    Node *findMin() const
    {
        return findMin(root);
    }

    Node *findMax() const
    {
        return findMax(root);
    }

    void insert(const Object &object)
    {
        root = insert(root, object);
    }

    // Node *erase(Object object)
    // {
    // }

    Object at(Node *position) const
    {
        if (position == nullptr)
        {
            std::cout << "位置无效！" << std::endl;
            exit(0);
        }

        return position->elem;
    }

    void print() const
    {
        print(root);
    }

private:
    Node *clear(Node *tree)
    {
        if (tree != nullptr)
        {
            clear(tree->left);
            clear(tree->right);
            delete tree;
        }

        return nullptr;
    }

    int getHeight(Node *tree) const
    {
        if (tree == nullptr)
        {
            return -1;
        }
        else
        {
            return tree->height;
        }
    }

    Node *find(Node *tree, const Object &object) const
    {
        if (tree == nullptr)
        {
            return nullptr;
        }

        if (object < tree->elem)
        {
            return find(tree->left, object);
        }
        else if (object > tree->elem)
        {
            return find(tree->right, object);
        }
        else
        {
            return tree;
        }
    }

    Node *findMin(Node *tree) const
    {
        if (tree == nullptr)
        {
            return nullptr;
        }

        if (tree->left == nullptr)
        {
            return tree;
        }
        else
        {
            return findMin(tree->left);
        }
    }

    Node *findMax(Node *tree) const
    {
        Node *currentNode = tree;
        if (currentNode != nullptr)
        {
            while (currentNode->right != nullptr)
            {
                currentNode = currentNode->right;
            }
        }

        return currentNode;
    }

    Node *leftLeftRotate(Node *tree)
    {
        Node *currentNode = tree->left;
        tree->left = currentNode->right;
        currentNode->right = tree;

        tree->height = std::max(getHeight(tree->left), getHeight(tree->right)) + 1;
        currentNode->height = std::max(getHeight(currentNode->left), getHeight(currentNode->right)) + 1;

        return currentNode;
    }

    Node *leftRightRotate(Node *tree)
    {
        tree->left = rightRightRotate(tree->left);
        tree = leftLeftRotate(tree);

        return tree;
    }

    Node *rightLeftRotate(Node *tree)
    {

        tree->right = leftLeftRotate(tree->right);
        tree = rightRightRotate(tree);

        return tree;
    }

    Node *rightRightRotate(Node *tree)
    {
        Node *currentNode = tree->right;
        tree->right = currentNode->left;
        currentNode->left = tree;

        tree->height = std::max(getHeight(tree->left), getHeight(tree->right)) + 1;
        currentNode->height = std::max(getHeight(currentNode->left), getHeight(currentNode->right)) + 1;

        return currentNode;
    }

    Node *insert(Node *tree, const Object &object)
    {
        if (tree == nullptr)
        {
            tree = new Node(object);
        }
        else if (object < tree->elem)
        {
            tree->left = insert(tree->left, object);
            if (getHeight(tree->left) - getHeight(tree->right) == 2) // 失去平衡时
            {
                if (object < tree->left->elem)
                {
                    tree = leftLeftRotate(tree);
                }
                else
                {
                    tree = leftRightRotate(tree);
                }
            }
        }
        else if (object > tree->elem)
        {
            tree->right = insert(tree->right, object);
            if (getHeight(tree->right) - getHeight(tree->left) == 2) // 失去平衡时
            {
                if (object > tree->right->elem)
                {
                    tree = rightRightRotate(tree);
                }
                else
                {
                    tree = rightLeftRotate(tree);
                }
            }
        }
        // 如果待插入对象已存在，什么都不做

        tree->height = std::max(getHeight(tree->left), getHeight(tree->right)) + 1;

        return tree;
    }

    // Node *erase(Node *tree, Object object)
    // {

    //     return tree;
    // }

    void print(Node *tree) const
    {
        if (tree == nullptr)
        {
            return;
        }

        if (tree->left != nullptr)
        {
            print(tree->left);
        }
        std::cout << tree->elem << std::endl;
        if (tree->right != nullptr)
        {
            print(tree->right);
        }
    }
};

#endif