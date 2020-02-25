//
//  Assign1.cpp
//  Assign1
//
//  Created by Noah Krill on 2/3/20.
//  Copyright © 2020 Noah Krill. All rights reserved.
//

#include <iostream>
int validate(int);
void algo1(int,const int);
void algo2(int,const int);
void algo3(int,const int);
void algo4(int,const int);
void algo5(int,int,const int);
void algo6(int,int,const int);

int main() {
    
    clock_t start, stop;
    int n=0,x=0,sum=0;
    n=validate(n);
    algo1(sum,n);
    algo2(sum,n);
    algo3(sum,n);
    algo4(sum,n);
    algo5(sum,x,n);
    algo6(sum,x,n);
 
    return 0;
}

//function for validating number
int validate(int num)
{
bool valid = false;

while (!valid)
{
    valid = true;

    std::cout << "Enter an integer value: " ;
    std::cin >> num;

    if(std::cin.fail()||num<0)
                
                
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Please enter an positive integer only." << std::endl;
        valid = false;
    }

}
    return num;
}
void algo1(int sum, const int n)
{
    clock_t start, stop;
    start = clock ();
       //This algorithm will run super efficiently
       for(int i=0 ; i<n;++i)
       {
           ++sum;
       }
       stop = clock ();
       std::cout << "Runtime for algorithm 1 "<< static_cast<double>(stop-start)/CLOCKS_PER_SEC << std::endl;
}
//This algorithm below wont run on N=1,000,000 within a resonable amount of time
void algo2(int sum, const int n)
{
    clock_t start, stop;
    start = clock ();
    sum = 0;
    for (int i=0; i<n; ++i)
        for(int j=0; j<n;++j)
        {
            ++sum;
        }
    stop = clock ();
    std::cout << "Runtime for algorithm 2 "<< static_cast<double>(stop-start)/CLOCKS_PER_SEC<< std::endl;
}
void algo3(int sum, const int n)
{
    clock_t start, stop;
    //This algorithm below wont run on N=10000 within a resonable amount of time
      sum = 0;
      start = clock ();
      for (int i=0; i<n; ++i)
          for(int j=0; j<n*n;++j)
          {
              ++sum;
          }
      stop = clock ();
      
      std::cout << "Runtime for algorithm 3 "<< static_cast<double>(stop-start)/CLOCKS_PER_SEC<< std::endl;
}
void algo4(int sum, const int n)
{
     clock_t start, stop;
    //This algorithm below wont run on N=1,000,000 within a resonable amount of time
    start = clock ();
    sum = 0;
    for (int i=0; i<n; ++i)
        for(int j=0; j<i;++j)
        {
            ++sum;
        }
    stop = clock ();
    std::cout << "Runtime for algorithm 4 "<< static_cast<double>(stop-start)/CLOCKS_PER_SEC<< std::endl;
}

void algo5(int sum, int x, const int n)
{
        clock_t start, stop;
     //This algorithm wont run on the 1st N =1000 within a resonible time
       start = clock ();
       sum = 0;
       for (int i=0; i<n; ++i)
           for(int j=0; j<i*i; ++j)
               for(int k=0; k<j; ++k)
               {
                  
                   x=1;
               }
          stop = clock ();
          std::cout << "Runtime for algorithm 5 "<< static_cast<double>(stop-start)/CLOCKS_PER_SEC<< std::endl;
    
}
 
void algo6(int sum, int x, const int n)
{
    clock_t start, stop;
    //This algorithm wont run on the 1st N =1000 within a resonible time
      start = clock ();
      sum = 0;

      for (int i=1; i<n; ++i)
      {
          for(int j=1; j<i*i;++j)
          {
              if(j % i==0)
              {
                  for(int k=0; k <j; ++k)
                  {
                      x=0;
                  }
              }
          }
      }
      stop = clock ();
      std::cout << "Runtime for algorithm 6 "<< static_cast<double>(stop-start)/CLOCKS_PER_SEC<< std::endl;
      
}
