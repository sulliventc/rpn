//  ==========================================
//  Node.cpp - Defines behavior for Node class
//
//  Version: 1.1.0
//  Date: 6/3/17
//  By: Colten Sullivent
//  ==========================================

//  ===================
#include <iostream>

#include "stdafx.h"
//  ===================

//  ====================
using namespace std;
//  ====================

//  ============================
//  constructors and destructors
//  ============================
Node::Node() {
    value = 0;
    next = NULL;
} // constructor

Node::Node(int listElement, Node *nodePtr) {
    value = listElement;
    next = nodePtr;
} // constructor

Node::~Node() {
} // destructor
//  ===============
