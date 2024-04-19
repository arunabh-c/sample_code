1. is a tool kit used to build and optimize compilers
2. llvm standardizes the extremely complex process of turning source code into machine code
3. Converts high level source code in a language agnostic code called Intermediate Representation (IR).

Compiler can be broken into 3 parts: Front, Middle, Back
Front ended parses source coded text and covnerts it into IR
Middle End analyzes and optimizes this generated code
Back End covnerts the IR into native machine code

1. First write lexer that scans raw source code and break it into collections of tokens like identifiers, operators, keywords
2. Next we need to define an Abstract syntax Tree to represent actual structure of the code. Have different tokens relate to each other which is accomplished by each node having its own class
3. Parser loops over each token and builds the AST

Import a bunch of llvm primitives to generate the the IR code.
each type in the AST is given a method called codegen which always returns an llvm value object used to represent a Single Assignment Register which is a variable for a compiler that can only be assigned once. IR primitives unlike assembly are independent of any machine architecture and that simplifies things for language developers who no longer need to match the language to a processor's instruction set.
 LLVM Optimizers analyze and optimizes generated code in multiple passes to generated optimized IR also removes dead code.
Back End is a module that takes IR as input that emits object code that can run on any architecture

Reference: https://www.youtube.com/watch?v=BT2Cv-Tjq7Q

**Difference between GCC & LLVM**

GCC is a big bag of software. The typical process, as I understand it, is for a GCC frontend to lex and parse the code, convert to GCC's internal Register Transfer Language (RTL), and then for a backend to write out native code.

So one typical flow is: **C code ---> GCC's C frontend ---> RTL ---> GCC's x86 backend ---> x86 machine code**

GCC supports several frontends: C, C++, Java, Objective C, Go, and Fortran.

GCC supports several backends: **32-bit x86, 64-bit x86, little endian ARM, big endian ARM, MIPS, SPARC, PowerPC**, etc.

**Frontends convert text to RTL, backends convert RTL to machine code of some sort**.

**LLVM is a middle-layer machine-agnostic computation representation, similar in concept to GCC's RTL**. It is its own type system and instruction set called LLVM Intermediate Representation (IR). 
If I understand correctly, LLVM's IR is richer, more expressive, and much more flexible than GCC's RTL, which serves many benefits. 
Compiler front-ends for LLVM for many different languages can all compile down to LLVM IR. This can be used for 'conventional' languages like C, C++, Java, etc, but it can also be used for 
'unconventional' programming tasks like GPU shaders or sql queries

LLVM is, perhaps, two things then. LLVM-the-machine, which is the type system and instruction set, which is probably better referred to as "LLVM IR"; and LLVM-the-API, which is software for
manipulating code in the LLVM IR, such as the LLVM JIT compiler, or perhaps the LLVM x86 machine code backend.

Clang is a front-end for LLVM that processes C-family languages: C, C++, Objective C, Objective C++. Clang converts C/C++/etc to LLVM IR, LLVM performs optimizations on the IR, and the 
LLVM x86 backend writes out x86 machine code for execution.

Despite the name, LLVM is not a Virtual Machine in the traditional sense - it is a computation model and representation that lends itself well to the task of manipulating code.

Part of LLVM's popularity comes from the fact that it is a fully reified compiler API. It can be used for performing static analysis on code ("does this code ever accidentally use 
uninitialized memory?"), optimization, code parsing (such as for building IDEs). GCC's internals are very highly coupled, and so using GCC in this manner is incredibly difficult. 
One example is that GCC's frontends perform some optimizations during parsing, so it is not possible to always get a perfect representation of the code-as-typed, for eg, 
reporting errors and performing squiggle-line syntax highlighting, because some information might have been lost.

As I understand it, Clang preserves the unoptimized parsed syntax, making it possible for 3rd party tools to use its output and equate transformations back to the original text,
most notably, Clang's error messages are much more helpful because they can highlight the exact part of the line that is in question.

Reference: https://stackoverflow.com/questions/24836183/what-is-the-difference-between-clang-and-llvm-and-gcc-g
