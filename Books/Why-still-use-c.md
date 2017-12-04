---
title: Why are you still using C?
author: James W. Grenning
---

# C++:
- If you don't use it, I won't pay for it. 
- With great power comes the responsability.
- C++ does not cause bad programs, bad programming does

# Beneficts
## Encapsulation: 
- Encapsulation is the packaging of hidden data and the functions that operate on that data.  You can practice encapsulation in C, but few people do. In C++ encapsulation is part of the language: basic building block **class**.

-  Encapsulation has a cost.  It is not generally regarded as high, but it does have a cost.  Each call to a member function has a hidden additional parameter, the pointer to the encapsulated data structure (a.k.a. the ‘this’ pointer).  Keep in mind that you are probably  already paying this cost when you pass the pointer to a data structure around.   
## Object Oriented Design:
- OO is an engineering tool.  It allows the software engineer to create a loosely coupled software system.  The idea of reducing coupling has been talked about for decades in the computer science field.
- It is possible to create interfaces to parts of the system as a mechanism to decouple one part of the system from another.  Then those parts can be varied independently.
- First law of software evolution: system must be continually adapted or it becomes progressively less satisfactory
- Open-Close principle: open for extention (interface implementation), but close for modification (interfaces) 

## Cost of polymorphism
- Direct call:  When you call a function in C, the compiler and linker determine the address of the function to be called. 
- Virtual function: addresses are bound at runtime

```c 
class CallSwitch  
{ 
 public: 
  virtual void Connect(User* a, User* b) = 0; 
}; 
``` 

- To summarize the costs of using virtual functions: 
    - Execution time overhead for the polymorphic call 
    - A virtual table is needed for each class that has virtual methods 
    - There is a slot in the virtual table for each virtual function 
    - A virtual function call takes more bytes than a direct call 

## Avoiding shooting yourself in the foot with c++
- Objects can be passed by value and by pointer.  So to reduce overhead, use the latter one.
- Do not let the compiler  create the default copy constructor. It is better to define one in the private area of the class.
    - No one can call it
    - And if there is no implementation, it means no space
- Do not let the compiler create an assigment operator

```c
class ClassName { 
    public: 
        ClassName(); //the default constructor 
 
    private: 
        //Degenerate copy and assignment 
        ClassName(const Classname&); 
        ClassName& operator=(const ClassName&) 
}; 
```

## Other trade-off
- Disable exceptions:  
Exceptions have both a memory cost and an execution cost.  This varies by compiler but 
some measurements put the memory overhead between 3-13% with an execution 
overhead between 4-6%. Exceptions can be turned off (zero-overhead principle). 
- Use in-line functions when possible

