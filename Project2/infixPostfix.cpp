
//  inFixPostfix.cpp
//  Project
//
//  Created by Noah Krill on 2/18/20.
//  Copyright 2020 Noah Krill. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <cmath>
#include <iomanip>
#include <stdlib.h>

void menu();
void validate(int &);
void infixToPost(const std::string &);
bool isDigit(const char &);
bool isSpace(const char &);
bool isOperator(const char &);
bool priority(const char &, const char &);
void evalPost(const std::string &);
double math(const double &,const double &, const char &);
double scanNum(const char &);

int main()
{
    std::stack<int> testStack;
    testStack.push(5);
    testStack.push(4);
    std::cout << testStack.top() << std::endl;
    testStack.pop();
    std:: cout << testStack.top() << std::endl;
    std::cout << std::endl;
    testStack.pop();

    menu();
    return 0;
}
//This is a function for the user to pick if they want to evelaute postfix or infix
void menu()
{
    std::string postin;
    int choice=1;
    while (choice!=0)
    {
        std::cout << "0. Exit" << std::endl;
        std::cout << "1. Postfix evaluation" << std::endl;
        std::cout << "2. Infix to postfix" << std::endl;
        std::cin >> choice;
        validate(choice);
        if (choice==1)
        {
            std::cout <<"Please enter a postfix expression to evalute: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
            getline(std::cin, postin);
            evalPost(postin);
        }
        else if (choice==2)
        {
            std::cout << "Please enter an infix expression: " << std::endl;
            std::cin.clear();
            std::cin.ignore();
            getline(std::cin, postin);
            infixToPost(postin);
        }
    }
}
//This function is a validation function for the users choice
void validate(int &choice)
{
    while (std::cin.fail() || choice < 0 || choice > 2)
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Please enter a number in the range of [0,2]" <<std::endl;
        std::cin >> choice;
    }
}

//This function does the majority of the work translating the infix to post fix
//It does most of the parsing
void infixToPost(const std::string& inpost)
{
    std::stack<char> StackOP;
    std::string post;
    auto iter = inpost.begin();
    
    while(iter!=inpost.end())
    {
        if(*iter== '(')
        {
            StackOP.push(*iter);
            ++iter;
        }
        //function for digits and period to be pushed onto a new string
        else if(isDigit(*iter)||*iter =='.')
        {
            if(((*(iter - 1) != '.') && (*(iter + 1) == ' ')) || ((*(iter - 1) != '.') && ((iter + 1) == inpost.end())))
            {
                post+= *iter;
                post+= ".0";
                ++iter;
            }
            else
            {
                post+=*iter;
                ++iter;
            }
        }
        //determining if the parsed character is a space
        else if (isSpace(*iter))
        {
            //if the character before the space is an operator dont push it onto the string
            if(isOperator(*(iter-1)))
            {
                ++iter;
            }
            else
            {
                post+=*iter;
                ++iter;
            }
        }
        //determines if the character is an operator.
        else if (isOperator(*iter))
        {
            //if the operator on the stack is greater then the operator being read in push the operator
            //onto the string and pop it off the stack
            while((!StackOP.empty() && StackOP.top()!='(') && (priority(StackOP.top() ,*iter)))
            {
                post+= StackOP.top();
                post+= ' ';
                StackOP.pop();
            }
            //push the onto the stack and continue foward
            StackOP.push(*iter);
            ++iter;
        }
        else if(*iter== ')')
        {
            //pop all operators off the operator stack until '(' is popped off and add those operators to postFix
            while(!StackOP.empty() && StackOP.top() != '(')
            {
                post += StackOP.top();
                StackOP.pop();
            }
            StackOP.pop();
            ++iter;
        }
        else
        {
            ++iter;
        }
    }
    //While the stack is not empty push the values onto the string and pop off the stack
    while (!StackOP.empty())
        {
            if(StackOP.top() == '(')
               StackOP.pop();
            else
            {
                post += ' ';
                post += StackOP.top();
                StackOP.pop();
            }
        }
        //clear the expression string and then add postFix to the expression to be passed by reference
    std::cout <<"The postfix expression is: " <<std::endl;
    std::cout << post << std::endl;
    evalPost(post);
}
//This function returns true if the value is a number
bool isDigit(const char &c)
{
    if (c>='0' && c<='9')
    {
        return true;
    }
    else
    {
        return false;
    }
}
//This function returns true if the value is a space
bool isSpace(const char &c)
{
    if (c==' ')
    {
        return true;
    }
    else
    {
        return false;
    }
}
//This function returns treu if the value is an operator
bool isOperator(const char &c)
{
    if(c == '+' || c=='-' || c=='*' || c=='^' || c =='/')
    {
        return true;
    }
    else
    {
        return false;
    }
}
//This function is the priorities for the operators to determine when they will be used
bool priority(const char &a, const char &b)
{
    if ((a== '*' && b == '-') || (a=='/' && b =='-')||(a=='*' && b == '+')
        ||(a=='/' && b =='+') || (a== '^' && b == '-') || (a== '^' && b == '+')
        || (a== '^' && b == '/')|| (a== '^' && b == '*')||(a == '^' && b== '(')
        || (a== '+' && b == '-') || (a== '-' && b== '+') || (a==b))
    {
        return true;
    }
    else
    {
        return false;
    }
}

//This function does the majority of the evaluating for postfix
//This function will parse the postfix and do the math to gain the right answer
void evalPost(const std::string &post)
{
    std::stack<double> Stack;
    double top1 =0, top2 =0;
    int counterOp=0, counterNum=0;
    std::string::const_iterator iter = post.begin();
    
    while (iter!=post.end())
    {
        //if the character that is being parsed is a space move past it.
        if (isSpace(*iter)||(*iter == '.' && *(iter+1) == '0') || ((*(iter-1)=='.') && (*iter=='0')))
        {
            ++iter;
        }
        else if(isDigit(*iter))
        {
        //if the character that is being parsed in the first number and is not part of the .0
            Stack.push(scanNum(*iter));
            if(*(iter-1)!='.' && *iter!='0')
            {
               ++counterNum;//adding one number to the amount of numbers
            }
            ++iter;
        }
        //if the parsed character is an operator if the stack is not empty
        //store the characters/numbers value into the variable and pop it off the stack
        //then proform the math on them with the math function
        else if(isOperator(*iter))
        {
            if(!Stack.empty())
            {
            top1=Stack.top();
            Stack.pop();
            }
            if(!Stack.empty())
            {
            top2=Stack.top();
            Stack.pop();
            Stack.push(math(top1, top2, *iter));
            }
            ++iter;
            ++counterOp;
        }
    }
    //determine if there are too few or to many operators
     if (counterOp+1<counterNum)
        {
            std::cerr<< "This is not a valid postfix expression: too few operators." <<std::endl;
        }
        else if (counterOp+1>counterNum)
        {
            std::cout<< "This is not a valid postfix expression: too many operators." <<std::endl;
        }
        else
        {
        std::cout << "This evaluates to: " << std::fixed << std::setprecision(1) << Stack.top() << std::endl;
        }
}

//This is the computation part of the postfix portion
double math(const double &top1, const double &top2, const char &iter)
{
    if(iter=='+')
    {
        return top2+top1;
    }
    else if(iter=='-')
    {
        return top2-top1;
    }
    else if(iter=='*')
    {
        return top2*top1;
    }
    else if(iter=='/')
    {
        return top2/top1;
    }
    else if(iter=='^')
    {
        return pow(top2, top1);
    }
    else
    {
        exit(1);
    }
}
//This just returns the numerical value
double scanNum(char const &ch)
{
   double value=ch;
   return double(value-'0');
}
