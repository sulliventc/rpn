//  =====================================
//  Software Engineer: Donald D. Derkacht
//  Program:           CalculatorProject
//  Version:           1.0.0
//  Date:              8 May 2010
//  =============================

#pragma once

class Stack
{
//  ==========
//  Constants:
//  ============================================================
//  maxStackSize is a static constant.  That is, maxStackSize is
//  constant that exists for as long as the program executes.
    const static int maxStackSize = 100;
//  ====================================

//  =======
public:
    Stack(void);
    ~Stack(void);
//  ================

//  ==========================
//  Stack Interface operators:
//  ============================
    void DestroyStack( );
    void InitializeStack( );
    void Pop( double& );
    void PrintStack( );
    void Push( double );
    bool StackEmpty( );
    bool StackFull( );
//  =========================

//  =================
//  Member variables:
//  ========
private:
    int    top;
    SinglyLinkedList elements;
//  ==================================

}; // class Stack




