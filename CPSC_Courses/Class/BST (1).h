#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include <iostream>
using namespace std;

template <typename T>
class BST{
    public:
        BST();
        virtual ~BST();
        bool contains(T d);
        void insert(T d);
        void remove(T d);
        int getSize();
        void printTreeInOrder();
        void printTreePostOrder();
        void printTreePreOrder();
    private:
        int m_size;
        TreeNode<T>* m_root;
        void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
        bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
        void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
        TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);
        void printTreeInOrderHelper(TreeNode<T>* subTreeRoot);
        void printTreePostOrderHelper(TreeNode<T>* subTreeRoot);
        void printTreePreOrderHelper(TreeNode<T>* subTreeRoot);
};

template <typename T>
BST<T>::BST(){
    m_root = NULL;
    m_size = 0;
}

template <typename T>
BST<T>::~BST(){
    // if(m_root != NULL){
    //     delete m_root;
    // }
}

template <typename T>
int BST<T>::getSize(){
    return m_size;
}

template <typename T>
void BST<T>::insert(T d){
    TreeNode<T>* newNode = new TreeNode<T>(d);
    insertHelper(m_root, newNode);
    ++m_size;
}

template <typename T>
void BST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        subTreeRoot = newNode;
    }else if(newNode->m_data < subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_left, newNode);
    }else{
        insertHelper(subTreeRoot->m_right, newNode);
    }
}

template <typename T>
bool BST<T>::contains(T d){
    TreeNode<T>* newNode = new TreeNode<T>(d);
    return containsHelper(m_root, newNode);
}

template <typename T>
bool BST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        return false;
    }else if(newNode->m_data == subTreeRoot->m_data){
        return true;
    }else if(newNode->m_data < subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_left, newNode);
    }else{
        return containsHelper(subTreeRoot->m_right, newNode);
    }
}

template <typename T>
void BST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
    while(target != NULL && target->m_data != key){
        parent = target;
        if(key < target->m_data){
            target = target->m_left;
        }else{
            target = target->m_right;
        }
    }

}

template <typename T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* rightChild){
    while(rightChild->m_left != NULL){
        rightChild = rightChild->m_left;
    }
    return rightChild;
}

template <typename T>
void BST<T>::remove(T d){
    //check if empty
    TreeNode<T>* target = NULL;
    TreeNode<T>* parent = NULL;
    target = m_root;
    findTarget(d, target, parent);
    if(target == NULL){ //value wasn't in the tree, nothing to do
        return;
    }
    if(target->m_left == NULL && target->m_right == NULL){//no children, it's a leaf
        if(target == m_root){ //leaf is the root of the tree
            m_root = NULL;
        }else{ //it's not the root
            if(target == parent->m_left){
                parent->m_left = NULL;
            }else{
                parent->m_right = NULL;
            }
        }
        //delete target; 
    }else if(target->m_left != NULL && target->m_right != NULL){ //2 child case
        TreeNode<T>* suc = getSuccessor(target->m_right);
        T value = suc->m_data;
        remove(value);
        target->m_data = value;
    }else{//1 child
        TreeNode<T>* child;
        if(target->m_left != NULL){
            child = target->m_left;
        }else{
            child = target->m_right;
        }
        if(target == m_root){
            m_root = child;
        }else{
            if(target == parent->m_left){
                parent->m_left = child;
            }else{
                parent->m_right = child;
            }
        }
        //delete target;
    }
}

template <typename T>
void BST<T>::printTreeInOrder(){
  printTreeInOrderHelper(m_root);
}

template <typename T>
void BST<T>::printTreeInOrderHelper(TreeNode<T>* subTreeRoot){
    // TODO
}

template <typename T>
void BST<T>::printTreePostOrder(){
  printTreeInOrderHelper(m_root);
}

template <typename T>
void BST<T>::printTreePostOrderHelper(TreeNode<T>* subTreeRoot){
    // TODO
}

template <typename T>
void BST<T>::printTreePreOrder(){
  printTreePreOrderHelper(m_root);
}

template <typename T>
void BST<T>::printTreePreOrderHelper(TreeNode<T>* subTreeRoot){
    TreeNode<T>* parent = m_root;
    TreeNode<T>* current = m_root;
    cout << parent->m_data << " ";
    while (parent->m_left != NULL){
        current = parent->m_left;
        cout << current->m_data << " ";
        parent = current;
        if (parent->m_left = NULL){
            current = parent->m_right;
            cout << current->m_data << " ";
            parent = current;
        }
    }

     



}

#endif