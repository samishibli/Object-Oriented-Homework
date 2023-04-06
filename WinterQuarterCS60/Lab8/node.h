// A simple class (defined inline) for node: the building block of linked lists
// Sara Krehbiel, 2/27/23

#ifndef NODE_H
#define NODE_H

class node {
public:
    // constructors
    node(): data_(0), link_(nullptr){}
    node (int initdata, node *initlink) : data_(initdata), link_(initlink) {}

    // accessors
    int data() const { return data_; }
    node* link() const { return link_; }

    // mutators
    void set_data(int newdata) { data_ = newdata; }
    void set_link(node * newlink) { link_ = newlink; }

private:
    int data_;
    node * link_;
};

#endif // NODE_H
