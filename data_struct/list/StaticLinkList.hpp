/**
 *  @brief: 静态链表
 */

#ifndef _STATICLINKLIST_HPP_
#define _STATICLINKLIST_HPP_

#include "LinkList.hpp"

namespace dsalcpp
{

template < typename T, int N >
class StaticLinkList : public LinkList<T>
{

protected:
    typedef typename LinkList<T>::Node Node;

    struct SNode : public Node {
        void* operator new(size_t size, void* loc) {
            (void)size;
            return loc;
        }
    };

    unsigned char space_[sizeof(SNode) * N];
    int used_[N];

    Node* create() {
        SNode* ret = NULL;

        for(int i = 0; i < N; i++) {
            if( !used_[i] ) {
                ret = reinterpret_cast<SNode*>(space_) + i;
                ret = new(ret)SNode();
                used_[i] = 1;
                break;
            }
        }

        return ret;
    }

    void destory(Node* pn) {
        SNode* space = reinterpret_cast<SNode*>(space_);
        SNode* psn = dynamic_cast<SNode*>(pn);

        for(int i = 0; i < N; i++) {
            if( psn == (space + i) ) {
                used_[i] = 0;
                psn->~SNode();
                break;
            }
        }
    }

public:
    StaticLinkList() {
        for(int i = 0; i < N; i++) {
            used_[i] = 0;
        }
    }

    int capacity() {
        return N;
    }

    ~StaticLinkList() {
        this->header_.next = NULL;
    }
};

}

#endif