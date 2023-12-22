#pragma once
#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

struct tnode {
    int data;
    struct tnode* left;
    struct tnode* right;
    tnode(): data(NULL), left(nullptr), right(nullptr) {}
    tnode(int data) : data(data), left(nullptr), right(nullptr) {}
};

ref class Tree
{
public:
    tnode* insertNode(tnode* root, int key)
    {
        if (root == nullptr) {
            return new tnode(key);
        }
        if (key < root->data) {
            root->left = insertNode(root->left, key);
        }
        else {
            root->right = insertNode(root->right, key);
        }
        return root;
    }

    tnode* getMinimumKey(tnode* curr)
    {
        while (curr->left != NULL) {
            curr = curr->left;
        }
        return curr;
    }

    void deleteNode(tnode* root, int key)
    {
        tnode* parent = nullptr;
        tnode* curr = root;
        searchKey(curr, key, parent);
        if (curr == nullptr) {
            return;
        }
        if (curr->left == nullptr && curr->right == nullptr)
        {
            if (curr != root)
            {
                if (parent->left == curr) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }
            }
            else {
                root = nullptr;
            }
            // освобождать память не требуется в управляемом коде
        }
        else if (curr->left && curr->right)
        {
            tnode* successor = getMinimumKey(curr->right);
            int val = successor->data;
            deleteNode(root, successor->data);
            curr->data = val;
        }
        else {
            tnode* child = (curr->left) ? curr->left : curr->right;
            if (curr != root)
            {
                if (curr == parent->left) {
                    parent->left = child;
                }
                else {
                    parent->right = child;
                }
            }
            else {
                root = child;
            }
            // освобождать память не требуется в управляемом коде
        }
    }

    void searchKey(tnode*& curr, int key, tnode*& parent)
    {
        while (curr != nullptr && curr->data != key)
        {
            parent = curr;
            if (key < curr->data) {
                curr = curr->left;
            }
            else {
                curr = curr->right;
            }
        }
    }

    string depthSearch(tnode* root) {
        stack<tnode*> nodeStack;
        string result = "";
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            root = nodeStack.top();
            result += to_string(root->data) + " ";
            nodeStack.pop();
            if (root->right)
                nodeStack.push(root->right);
            if (root->left)
                nodeStack.push(root->left);
        }
        return result;
    }

    string widthSearch(tnode* root) {
        queue<tnode* > nodeQueue;
        nodeQueue.push(root);
        string result = "";
        while (!nodeQueue.empty()) {
            root = nodeQueue.front();
            result += to_string(root->data) + " ";
            nodeQueue.pop();
            if (root->left != nullptr)
                nodeQueue.push(root->left);
            if (root->right != nullptr)
                nodeQueue.push(root->right);
        }
        return result;
    }
};