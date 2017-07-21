//  =================================================================
//  SinglyLinkedList.h - Declares behavior for SinglyLinkedList class
//
//  Version: 1.0.0
//  Date: 6/3/17
//  By: Colten Sullivent
//  =================================================================

//  ============
#pragma once

#include "stdafx.h"
//  ===================

//  ========================
class SinglyLinkedList {
public:
    SinglyLinkedList();

    ~SinglyLinkedList();

    Node* GetFirst();
    void  InitializeList();
    void  DestroyList();
    void  InsertFirst(double);
    void  InsertLast(double);
    void  Insert(double, int);
    void  DeleteFirst(double &);
    void  DeleteLast(double &);
    void  Delete(double &, int);
    void  Print();
    void  ReversePrint(Node *);
    bool  IsEmpty();
    int   Length();
private:
    Node *first;
    Node *last;
}; // class SinglyLinkedList
//  ============================