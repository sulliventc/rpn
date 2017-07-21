//  ==================================================================
//  SinglyLinkedList.cpp - Defines behavior for SinglyLinkedList class
//
//  Version: 1.0.0
//  Date: 6/3/17
//  By: Colten Sullivent
//  ==================================================================

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
    SinglyLinkedList::SinglyLinkedList() {
        first = last = NULL;
    } // constructor

    SinglyLinkedList::~SinglyLinkedList() {
        DestroyList();
    } // destructor
//  ===============

//  ======================
//  accessors and mutators
//  ======================
    Node *SinglyLinkedList::GetFirst() {
        return first;
    } // accessor
//  =============

//  ======================
//  function DestroyList()
//  ======================================
    void SinglyLinkedList::DestroyList() {
        Node *temp;

//      =======================
        while (first != NULL) {
            temp = first;
            first = first->next;
            delete temp;
        } // while
//      ==========

        last = NULL;
    } // function DestroyList
//  =========================

//  =========================
//  function InitializeList()
//  =========================================
    void SinglyLinkedList::InitializeList() {
        DestroyList();
    } // function InitializeList()
//  ==============================

//  =========================
//  function InsertFirst(int)
//  ==============================================
    void SinglyLinkedList::InsertFirst(double data) {
        Node *newNode = new Node(data, first);

        first = newNode;

//      ===================
        if (last == NULL) {
            last = first;
        } // if
//      =======

    } // function InsertFirst(int)
//  ==============================

//  ========================
//  function InsertLast(int)
//  =============================================
    void SinglyLinkedList::InsertLast(double data) {

//      ======================
        if (this->IsEmpty()) {
            this->InsertFirst(data);
        } else {
            Node *newNodePtr = new Node(data, NULL);
            last->next = newNodePtr;
            last = newNodePtr;
        } // if/else
//      ============

    } // function InsertLast(int)
//  =============================

//  =========================
//  function Insert(int, int)
//  =======================================================
    void SinglyLinkedList::Insert(double data, int location) {
        int nodeCounter;
        Node *ptr;

//      ======================================================
        if ((location > this->Length() + 1) || location < 1) {
            cout << endl;
            cout << "=================================" << endl;
            cout << "Member-function Insert() invoked." << endl;
            cout << "Insertion location is invalid.   " << endl;
            cout << "Insert() terminating execution.  " << endl;
            cout << "=================================" << endl;
            cout << endl;
        } else {

//          ====================
            if (location == 1) {
                this->InsertFirst(data);
            } else if (location == this->Length() + 1) {
                this->InsertLast(data);
            } else {
                nodeCounter = 1;
                ptr = this->first;

//              ====================================
                while (nodeCounter < location - 1) {
                    ptr = ptr->next;
                    nodeCounter++;
                } // while
//              ==========

                Node *newNode = new Node(data, ptr->next);
                ptr->next = newNode;
            } // if/else
//          ============

        } // if/else
//      ============

    } // function Insert(int, int)
//  ==============================

//  ======================
//  function DeleteFirst()
//  ======================================
    void SinglyLinkedList::DeleteFirst(double &valueDeleted) {

//      ======================
        if (this->IsEmpty()) {
            cout << endl;
            cout << "======================================" << endl;
            cout << "Member-function DeleteFirst() invoked." << endl;
            cout << "List is empty.                        " << endl;
            cout << "DeleteFirst() terminating execution.  " << endl;
            cout << "======================================" << endl;
            cout << endl;
        } else {
            valueDeleted = first->value;
            Node *holder = first->next;
            delete first;
            first = holder;

//          ====================
            if (first == NULL) {
                last = NULL;
            } // if
//          =======

        } // if/else
//      ============

    } // function DeleteFirst()
//  ===========================

//  =====================
//  function DeleteLast()
//  =====================================
    void SinglyLinkedList::DeleteLast(double &valueDeleted) {

//      ======================
        if (this->IsEmpty()) {
            cout << endl;
            cout << "======================================" << endl;
            cout << "Member-function DeleteLast() invoked." << endl;
            cout << "List is empty.                        " << endl;
            cout << "DeleteLast() terminating execution.  " << endl;
            cout << "======================================" << endl;
            cout << endl;
        } else if (first == last) {
            DeleteFirst(valueDeleted);
        } else {
            Node *current;
            Node *previous;
            current = first;

//          ===============================
            while (current->next != NULL) {
                previous = current;
                current = current->next;
            } // while
//          ==========

            last = previous;
            last->next = NULL;
            valueDeleted = current->value;
            delete current;
        } // if/else
//      ============

    } // function DeleteLast()
//  ==========================

//  ====================
//  function Delete(int)
//  =============================================
    void SinglyLinkedList::Delete(double &valueDeleted, int location) {

//      ======================================================
        if ((location > this->Length() + 1) || location < 1) {
            cout << endl;
            cout << "=================================" << endl;
            cout << "Member-function Delete() invoked." << endl;
            cout << "Deletion location is invalid.    " << endl;
            cout << "Delete() terminating execution.  " << endl;
            cout << "=================================" << endl;
            cout << endl;
        } else {

//          ====================
            if (location == 1) {
                this->DeleteFirst(valueDeleted);
            } else if (location == this->Length() + 1) {
                this->DeleteLast(valueDeleted);
            } else {
                Node *current;
                Node *previous;

                current = first;

//              =======================================
                for (int ii = 1; ii < location; ii++) {
                    previous = current;
                    current = current->next;
                } // for
//              ========

                previous->next = current->next;
                valueDeleted = current->value;
                delete current;
            } // if/else
//          ============

        } // if/else
//      ============

    } // function Delete(int)
//  =========================

//  ==================
//  function IsEmpty()
//  ==================================
    bool SinglyLinkedList::IsEmpty() {
        return (first == NULL);
    } // function IsEmpty()
//  =======================

//  =================
//  function Length()
//  ================================
    int SinglyLinkedList::Length() {
        int nbNodes = 0;
        Node *ptr;

        ptr = this->first;

//      =====================
        while (ptr != NULL) {
            ptr = ptr->next;
            nbNodes++;
        } // while
//      ==========

        return nbNodes;
    } // function Length()
//  ======================

//  ================
//  function Print()
//  ================================
    void SinglyLinkedList::Print() {
        Node *current;

        cout << endl;
        cout << "=====================================" << endl;
        cout << "The list contains the following data." << endl;
        cout << endl;

//      ==========================
        if (this->Length() == 0) {
            cout << "The list is empty." << endl;
            cout << "==================" << endl;
            cout << endl;
        } else {
            cout << "  Beginning" << endl;
            current = first;

//          =========================
            while (current != NULL) {
                cout << "    " << current->value << endl;
                current = current->next;
            } // while
//          ==========

            cout << "  Ending" << endl;
            cout << "========" << endl;
            cout << endl;
        } // if/else
//      ============

    } // function Print()
//  =====================

//  =============================
//  function ReversePrint(Node *)
//  ========================================================
    void SinglyLinkedList::ReversePrint(Node *currentNode) {

//      ==========================
        if (currentNode != NULL) {
            ReversePrint(currentNode->next);
            cout << currentNode->value << endl;
        } // if
//      =======

    } // function ReversePrint(Node *)
//  ==================================