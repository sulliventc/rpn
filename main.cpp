//  ================================================================================
//  RPNCalculatorProjectA.cpp : Defines the entry point for the console application.
//  ================================================================================

//  ======================
//  Header File Inclusions
//  ======================
#include "stdafx.h"
#include <iostream>
#include <string>

#include "Stack.h"
// ==================

//  ====================
using namespace std;
//  ====================

//  ===================
//  Function Prototypes
//  ==============================
void Evaluate(Stack&, char);
bool IsOperator(string);
void QueryUser(string&);
bool GoAgain(string);
//  =======================

//  =============
int main( ) {

//      ================================
//      Variable and Object Declarations
//      ================================
    char   arithmeticOperator;
    double result;
    double number;
    string answer = "yes";
    string token;

    Stack  stack;
//      =============

    cout << "RPN Calculator Invoked." << endl << endl;

//      =========
//      User Loop
//      ===========================
    while ( GoAgain(answer) ) {

        stack.InitializeStack();

        cout << "Enter an RPN expression." << endl << endl;

//          =====================
//          Begin Calculator Loop
//          ====
        do {
            cin >> token;
            cout << "token = " << token << endl; // Debug code.

            if ( IsOperator( token ) ) {
                arithmeticOperator = token[0];
                Evaluate( stack, arithmeticOperator );
            }
            else {
//                  =========================================================
//                  Note: double atof ( const char * str ); The function atof 
//                  parses a C string and returns the string's value as a double.
//                  =============================================================
                number = atof( token.data() );
//                  ==============================

                stack.Push( number );
            } // else

        } while ( (cin.peek() != '\n') );
//          =================================
//          End Calculator Loop
//          ===================

        stack.Pop( result );
        if ( stack.StackEmpty() )
            cout << "The answer is " << result << endl;
        else
            cout << "Error state encountered." << endl;

        QueryUser( answer );
    } // while (User Loop)
//      ======================

    return 0;

} // Function main()
//  ====================

//  =================
//  Function Evaluate
//  ============================
void Evaluate( Stack& stack,
               char   op )
{
    double operand1;
    double operand2;

    stack.Pop( operand2 );
    stack.Pop( operand1 );

    switch( op ) {

        case '+' : stack.Push( operand1 + operand2 );
            break;
        case '-' : stack.Push( operand1 - operand2 );
            break;
        case '*' : stack.Push( operand1 * operand2 );
            break;
        case '/' :
            if (operand2 == 0) {
                cout << "Divide by zero error. Pushing 0 to stack in place of result." << endl;
                stack.Push(0);
            } else {
                stack.Push( operand1 / operand2 );
            }
    } // switch

} // Evaluate
//  =============

//  ===================
//  Function IsOperator
//  ===============================
bool IsOperator( string token )
{
    return
            (  ( token.length( ) == 1 ) &&
               ( ( token[0] == '+' ) ||
                 ( token[0] == '-' ) ||
                 ( token[0] == '*' ) ||
                 ( token[0] == '/' )
               )
            );
} // IsOperator
//  ===============

//  ==================
//  Function QueryUser
//
//  NOTES: 
//  1) The function QueryUser is not bullet proof.
//  ================================
void QueryUser( string& answer )
{
    cout << "Would you like to enter an expression? (yes/no)"
         << endl;
    cin  >> answer;

} // QueryUser
//  ==============

//  ================
//  Function GoAgain
//  =============================
bool GoAgain( string answer )
{
    return ( answer == "yes" );
} // GoAgain
//  ============


