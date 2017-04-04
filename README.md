# Light C++ to C Converter

## Description
* Wright a C program that converts files from "Light C++" to C
* The converted C program will use the same name as the inutted file
* The converted C program will be compiled and run using "gcc inFileName.c"
* Your C program will be compiled using the ansi flag
* Restrictions: Extra libraries, use of regex is forbidden

## Program Requirements
### Convert Class to Structs
* Converts the classes to structs as C does not have classes.
  
  **Example**: `class Tst { ... };` becomes `struct Tst { ... };`
* All variable declarations must remain within the classes once changed to structs.
### Functions Within Classes
* Structs in C are unable to contain classes. Therefore a function pointer must be used for the struct to continue to reference the function as it previously did.
* Functions will be renamed using the following formula: Class Name + Function Name + First Letter of Every Function Parameter
* The class will be automatically sent in using the name sPtrNM. This is for any class variabes referenced in the function.

**Example**:
 
 ```
    class Tst {
        int a;
        void fn(int a, char b){ ... }
    };
```
  would be converted to:
 
 ```
      struct Tst{
          int a;
          void (*Tstfnsic) ();
      };
      void Tstfnsic(struct Tst * sPtrNM,int a, char b){ ... }
 ```
 ### Addition of Constructors
 * Due to the removal of the functions from the classes, constructors must be added to initilize the pointers. Therefore, wherever a class is declaired, a constructor must be placed after.
 
 **Example**: 
 
 ```
 class Tst {
        int a;
        void fn(int a, char b){ ... }
 }; 
 int main () {
     class Tst myTest;
     ...
 }
 ```
 
 would be converted to: 

 ```
      struct Tst{
          int a;
          void Tstfnsic(*Tstfnsic) ();
      };
      void Tstfn(struct Tst * sPtrNM,int a, char b){ ... }
      void constructorTst(struct Tst * sPtrNM) {
          sPtrNM->Tstfnsic = &Tstfnsic;
      }
      int main () {
        struct Tst myTest;
        constructorTst(&myTest);
        ...
      }
 ```
 * Constructor is formed using the formula: "constructor" + Class Name and sends in the memory address of the class.
 * The constructor is placed at the end of the functions that were once in the class.
 
 ## Class Function Variables
 

## Designed Program Restrictions
* Variables within the class are static only. Not Dynamic. (EG: int a; NOT int * a;)
* Double Variable Types (EG: long long, long double, long int)
* Class function calls inside of another class function.
* Struct variables as a function argument of another function. (EG: myA.add(myA.x,myA.y))
* Function calls inside of a function call. (EG: myA.add(myA.geta(),myA.getb()))
* Variable declarations and assignments within a class. (EG: int a = 1)
