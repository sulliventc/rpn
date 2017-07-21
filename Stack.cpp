//  =====================================
//  Software Engineer: Donald D. Derkacht
//  Program:           CalculatorProject
//  Version:           1.0.0
//  Date:              8 May 2010
//  =============================

#include "stdafx.h"
#include "Stack.h"
#include <iostream>

using namespace std;

//  ==============================================================
//  For the Stack class, the default constructor is adequate. This
//  is becuase the Stack class makes use of a static array to hold
//  stack elements and its size is determined by a constant at compile
//  time, using the maxStackSize static constant.  If a dynamic array
//  were used, instead of a static one, then the user could actually
//  specify the size of the array holding stack elements, then the default
//  constructor would have to be modified to establish the size of the
//  array based on user input.
//  ====================
Stack::Stack( void )
{
    InitializeStack();
} // Default Constructor
//  ========================

//  ==================================================================
//  The destructor, since Stack object does not consist of any memeory
//  resources in the freestore (heap), does not have to
//  deallocate any resourses when Stack object is no longer needed.
//  ===================
Stack::~Stack(void) {

} // Destructor
//  ===============

//  ==================================================================
//  The philosophy embodied in DestroyStack goes beyond simply setting
//  the top = 0, but purging all values in the elements array and setting
//  them to zero.  InitializeStack simply leaves the values in place in
//  elements, but sets the top = 0.
//  ===========================
void Stack::DestroyStack( )
{
    InitializeStack();
} // DestroyStack
//  =================

//  ==============================
void Stack::InitializeStack( )
{
    elements.InitializeList();
} // InitializeStack
//  ====================

//  ===================================================================
//  This member function of the Stack class does not check to determine
//  if the stack is empty before attempting to pop a value.  That is the
//  job of the boolean member function StackEmpty().  It is the obligation
//  of the programmer to invoke StackEmpty() before popping an element from
//  a Stack instance to make sure a element is available.
//  ======================================
void Stack::Pop( double& poppedValue )
{
    elements.DeleteFirst(poppedValue);
} // Pop
//  ========

//  =================
//  Method PrintStack
//  =========================
void Stack::PrintStack( )
{
    cout << "Stack Top" << endl;

    if (StackEmpty()) {
        cout << "The stack is empty." << endl;
    } else {
        elements.Print();
    } // else

    cout << "Stack Bottom" << endl << endl;
} // method PrintStack (interface operator)
//  ===========================================

//  ======================================
void Stack::Push( double pushedValue )
{
    elements.InsertFirst(pushedValue);
} // Push
//  =========

//  =========================
bool Stack::StackEmpty( )
{
    return elements.IsEmpty();
} // StackEmpty
//  ===============

//  ========================
bool Stack::StackFull( )
{
    return (elements.Length() == maxStackSize);
} // StackFull
//  ==============



