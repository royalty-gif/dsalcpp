/**
 *  @brief: 树节点类模板
 */

#include "Object.hpp"

namespace dsalcpp
{

template < typename T >
class TreeNode : public Object
{
protected:
    bool flag_;

    TreeNode(const TreeNode<T>&);
    TreeNode<T>& operator=(const TreeNode<T>&);

    void* operator new(size_t size) {
        return Object::operator new(size);
    }

public:
    T value;
    TreeNode<T>* parent;

    TreeNode(bool flag = false) {
        this->flag_ = flag;
        this->parent = NULL;
    }

    bool flag() {
        return this->flag_;
    }

    virtual ~TreeNode() = 0;
};

template < typename T >
TreeNode<T>::~TreeNode() {}

}