//  =========================================
//  Node.h - Declares behavior for Node class
//
//  Version: 1.1.0
//  Date: 6/3/17
//  By: Colten Sullivent
//  =========================================

//  ============
#pragma once
//  ============

//  ============
class Node {
    friend class SinglyLinkedList;

public:
    Node();
    Node(int, Node*);

    ~Node();
private:
    double     value;
    Node*   next;
}; // class Node
//  ================