#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>

template <typename Object>
class BinarySearchTree
{
private:
    struct Node
    {
        Object elem;
        Node *left;
        Node *right;

        Node() : left(nullptr), right(nullptr) {}
        Node(const Object &object) : elem(object), left(nullptr), right(nullptr) {}
    };
    Node *root;

public:
    BinarySearchTree()
    {
        root = nullptr;
    }

    ~BinarySearchTree()
    {
        clear();
    }

    BinarySearchTree(const BinarySearchTree &) = delete;
    BinarySearchTree &operator=(const BinarySearchTree &) = delete;

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

    void erase(const Object &object)
    {
        root = erase(root, object);
    }

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

private: // 递归操作辅助函数
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

    Node *insert(Node *tree, const Object &object)
    {
        if (tree == nullptr)
        {
            tree = new Node(object);
        }
        else if (object < tree->elem)
        {
            tree->left = insert(tree->left, object);
        }
        else if (object > tree->elem)
        {
            tree->right = insert(tree->right, object);
        }
        // 如果待插入对象已存在，什么都不做

        return tree;
    }

    Node *erase(Node *tree, const Object &object)
    {
        if (tree == nullptr)
        {
            std::cout << "此元素不存在！" << std::endl;
            exit(0);
        }

        if (object < tree->elem)
        {
            tree->left = erase(tree->left, object);
        }
        else if (object > tree->elem)
        {
            tree->right = erase(tree->right, object);
        }

        // 找到待删除对象
        else if (tree->left && tree->right) // 待删除结点有2个孩子
        {
            Node *tempNode = findMin(tree->right);
            tree->elem = tempNode->elem;
            tree->right = erase(tree->right, tree->elem);
        }
        else // 待删除结点有1个或者0个孩子
        {
            Node *tempNode = tree;
            if (tree->left == nullptr)
            {
                tree = tree->right;
            }
            else if (tree->right == nullptr)
            {
                tree = tree->left;
            }
            delete tempNode;
        }

        return tree;
    }

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