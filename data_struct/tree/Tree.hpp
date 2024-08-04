/**
 *  @brief: 树基类类模板
 */

#ifndef _TREE_H_
#define _TREE_H_

#include "TreeNode.hpp"
#include "SharedPointer.hpp"

namespace dsalcpp
{

template < typename T > 
class Tree : public Object
{
protected:
    TreeNode<T>* root_;

    Tree(const Tree<T>&);
    Tree<T>& operator=(const Tree<T>&);

public:
    Tree() { root_ = NULL; }
    virtual TreeNode<T>* insert(TreeNode<T>* node) = 0;
    virtual TreeNode<T>* insert(const T& value, TreeNode<T>* parent) = 0;
    virtual SharedPointer< Tree<T> > remove(const T& value) = 0;
    virtual SharedPointer<Tree<T>> remove(TreeNode<T>* node) = 0;
    virtual TreeNode<T>* find(const T& value) const;
    virtual TreeNode<T>* find(TreeNode<T>* node) const;
    virtual TreeNode<T>* root() const = 0;
    virtual int degree() const = 0;
    virtual int count() const = 0;
    virtual int height() const = 0;
    virtual void clear() = 0;
    virtual bool begin() = 0;
    virtual bool end() = 0;
    virtual bool next() = 0;
    virtual T current() = 0;

    Tree<T>& self() {
        return *this;
    }
};

}

#endif
