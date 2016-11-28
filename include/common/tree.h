#pragma once

#include <preprocessor.h>
#include <vector>

namespace reboot{
    template <class T>
    struct REBOOT_API Tree{
        T item;
        Tree* parent;
        std::vector<Tree<T>*> children;
        void addChild(T child){
            Tree<T> *t = new Tree();
            t->item=child;
            t->parent=this;
        }
        T getItem(unsigned index){
            return children.size()<index?children[index]->item: nullptr;
        }
        void removeItem(unsigned index){
            if(children.size()<index){
                children.erase(children.begin()+index);
            }
        }
    };
}