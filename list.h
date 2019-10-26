#pragma once

namespace firefly::std {
    /**
     *                          Doubly linked list node
     * @param  <T>              The data's type
     */
    template <typename T>
    struct list_node {
        /**
         *                      Next node in the list
         */
        list_node<T>* next;

        /**
         *                      Previous node in the list
         */
        list_node<T>* prev;

        /**
         *                      Node data
         */
        T data;

        /**
         *                      Construct a new list
         */
        list_node() : next(this), prev(this) {}

        /**
         *                      Adds a node following this one
         * @param  nx           The new node to add
         */
        void add(list_node<T>* nx) {
            nx->next = next;
            nx->prev = this;
            next->prev = nx;
            next = nx;
        }

        /**
         *                      Removes this node from the list
         */
        void remove() {
            prev->next = next;
            next->prev = prev;
        }
    };
} // namespace firefly::std