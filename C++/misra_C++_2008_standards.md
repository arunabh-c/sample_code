  MISRA08_0-1-10 - Published Standards\MISRA-C++ 2008\0-1-10 All defined functions called
  
  MISRA08_0-1-11 - Published Standards\MISRA-C++ 2008\0-1-11 A There shall be no unused parameters (named or unnamed) in non-virtual functions
  
  MISRA08_0-1-12 - Published Standards\MISRA-C++ 2008\0-1-12 There shall be no unused parameters (named or unnamed) in the set of parameters for a virtual function and all the functions that override it
  
  MISRA08_0-1-4 - Published Standards\MISRA-C++ 2008\0-1-4 A project shall not contain non-volatile POD variables having only one use.
  
  MISRA08_0-1-5 - Published Standards\MISRA-C++ 2008\0-1-5 A project shall not contain unused type declarations
  
  MISRA08_0-1-7 - Published Standards\MISRA-C++ 2008\0-1-7 The value returned by a function having a non-void return type that is not an overloaded operator shall always be used
  
  MISRA08_0-1-8 - Published Standards\MISRA-C++ 2008\0-1-8 All functions with void return type shall have external side effect(s)
  
  MISRA08_0-3-1 - Published Standards\MISRA-C++ 2008\0-3-1 Minimization of run-time failures shall be ensured by the use of static analysis tools
  
  MISRA08_10-1-1 - Published Standards\MISRA-C++ 2008\10-1-1 Classes should not be derived from virtual bases
  
  MISRA08_10-1-2 - Published Standards\MISRA-C++ 2008\10-1-2 A base class shall only be declared virtual if it is used in a diamond hierarchy
  
  MISRA08_10-1-3 - Published Standards\MISRA-C++ 2008\10-1-3 An accessible base class shall not be both virtual and non-virtual in the same hierarchy
  
  MISRA08_10-3-1 - Published Standards\MISRA-C++ 2008\10-3-1 There shall be no more than one definition of each virtual function on each path through the inheritance hierarchy

  MISRA08_10-3-2 - Published Standards\MISRA-C++ 2008\10-3-2 Each overriding virtual function shall be declared with the virtual keyword.
  
  MISRA08_10-3-3 - Published Standards\MISRA-C++ 2008\10-3-3 A virtual function shall only be overridden by a pure virtual function if it is itself declared as pure virtual
  
  MISRA08_11-0-1 - Published Standards\MISRA-C++ 2008\11-0-1 Member data in non-POD class types shall be private
  
  MISRA08_12-1-1 - Published Standards\MISRA-C++ 2008\12-1-1 An object's dynamic type shall not be used from the body of its constructor or destructor
  MISRA08_12-1-2 - Published Standards\MISRA-C++ 2008\12-1-2 All constructors of a class should explicitly call a constructor for all of its immediate base classes and all virtual base classes
  MISRA08_12-1-3 - Published Standards\MISRA-C++ 2008\12-1-3 All constructors that are callable with a single argument of fundamental type shall be declared explicit.
  MISRA08_12-8-1 - Published Standards\MISRA-C++ 2008\12-8-1 A copy constructor shall only initialize its base classes and the non-static members of the class of which it is a member
  MISRA08_14-5-2 - Published Standards\MISRA-C++ 2008\14-5-2 A copy constructor shall be declared when there is a template constructor with a single parameter that is a generic parameter
  MISRA08_14-5-3 - Published Standards\MISRA-C++ 2008\14-5-3 A copy assignment operator shall be declared when there is a template assignment operator with a parameter that is a generic parameter
  MISRA08_14-7-1 - Published Standards\MISRA-C++ 2008\14-7-1 All class templates, function templates, class template member functions and class template static members shall be instantiated at least once
  MISRA08_14-8-1 - Published Standards\MISRA-C++ 2008\14-8-1 Overloaded function templates shall not be explicitly specialized
  MISRA08_15-0-2 - Published Standards\MISRA-C++ 2008\15-0-2 An exception object should not have pointer type
  MISRA08_15-1-1 - Published Standards\MISRA-C++ 2008\15-1-1 The assignment-expression of a throw statement shall not itself cause an exception to be thrown
  MISRA08_15-1-2 - Published Standards\MISRA-C++ 2008\15-1-2 NULL shall not be thrown explicitly
  MISRA08_15-1-3 - Published Standards\MISRA-C++ 2008\15-1-3 An empty throw (throw;) shall only be used in the compound-statement of a catch handler
  MISRA08_15-3-1 - Published Standards\MISRA-C++ 2008\15-3-1 Exceptions shall be raised only after start-up and before termination of the program
  MISRA08_15-3-2 - Published Standards\MISRA-C++ 2008\15-3-2 There should be at least one exception handler to catch all otherwise unhandled exceptions
  MISRA08_15-3-3 - Published Standards\MISRA-C++ 2008\15-3-3 Handlers of a function-try-block implementation of a class constructor or destructor shall not reference nonstatic members from this class or its bases
  MISRA08_15-3-5 - Published Standards\MISRA-C++ 2008\15-3-5 A class type exception shall always be caught by reference
  MISRA08_15-3-6 - Published Standards\MISRA-C++ 2008\15-3-6 Where multiple handlers are provided in a single try-catch statement or function-try-block for a derived class and some or all of its bases, the handlers shall be ordered most-derived to base class
  MISRA08_15-3-7 - Published Standards\MISRA-C++ 2008\15-3-7 Where multiple handlers are provided in a single try-catch statement or function-try-block, any ellipsis (catch-all) handler shall occur last
  MISRA08_15-4-1 - Published Standards\MISRA-C++ 2008\15-4-1 If a function is declared with an exception-specification, then all declarations of the same function (in other translation units) shall be declared with the same set of type-ids
  MISRA08_15-5-1 - Published Standards\MISRA-C++ 2008\15-5-1 A class destructor shall not exit with an exception
  MISRA08_15-5-2 - Published Standards\MISRA-C++ 2008\15-5-2 Where a function's declaration includes an exception specification, the function shall only be capable of throwing exceptions of the indicated type(s)
  MISRA08_16-0-1 - Published Standards\MISRA-C++ 2008\16-0-1 #include directives in a file shall only be preceded by other preprocessor directives or comments
  MISRA08_16-0-2 - Published Standards\MISRA-C++ 2008\16-0-2 Macros shall only be #define'd or
#undef'd in the global namespace
  MISRA08_16-0-3 - Published Standards\MISRA-C++ 2008\16-0-3 #undef shall not be used
  MISRA08_16-0-4 - Published Standards\MISRA-C++ 2008\16-0-4 Function-like macros shall not be defined
  MISRA08_16-0-5 - Published Standards\MISRA-C++ 2008\16-0-5 Arguments to a function-like macro shall not contain tokens that look like preprocessing directives
  MISRA08_16-0-6 - Published Standards\MISRA-C++ 2008\16-0-6 In the definition of a function-like macro, each instance of a parameter shall be enclosed in parentheses, unless it is used as the operand of # or ##
  MISRA08_16-0-7 - Published Standards\MISRA-C++ 2008\16-0-7 Undefined macro identifiers shall not be used in #if or #elif preprocessor directives, except as operands to the defined operator
  MISRA08_16-0-8 - Published Standards\MISRA-C++ 2008\16-0-8 If the # token appears as the first token on a line, then it shall be immediately followed by a preprocessing token
  MISRA08_16-1-1 - Published Standards\MISRA-C++ 2008\16-1-1 The defined preprocessor operator shall only be used in one of the two standard forms
  MISRA08_16-1-2 - Published Standards\MISRA-C++ 2008\16-1-2 All #else, #elif and #endif preprocessor directives shall reside in the same file as the #if or #ifdef directive to which they are related
  MISRA08_16-2-1 - Published Standards\MISRA-C++ 2008\16-2-1 The pre-processor shall only be used for file inclusion and include guards
  MISRA08_16-2-2 - Published Standards\MISRA-C++ 2008\16-2-2 C++ macros shall only be used for include guards, type qualifiers, or storage class specifiers
  MISRA08_16-2-3 - Published Standards\MISRA-C++ 2008\16-2-3 Include guards shall be provided
  MISRA08_16-2-4 - Published Standards\MISRA-C++ 2008\16-2-4 The ', ", /* or // characters shall not occur in a header file name.
  MISRA08_16-2-5 - Published Standards\MISRA-C++ 2008\16-2-5 The backslash character should not occur in a header file name
  MISRA08_16-2-6 - Published Standards\MISRA-C++ 2008\16-2-6 The #include directive shall be followed by either a <filename> or filename sequence
  MISRA08_16-3-1 - Published Standards\MISRA-C++ 2008\There shall be at most one occurrence of the #
or ## operators in a single macro definition
  MISRA08_16-3-2 - Published Standards\MISRA-C++ 2008\16-3-2 The # and ## operators should not be
used
  MISRA08_17-0-1 - Published Standards\MISRA-C++ 2008\17-0-1 Reserved identifiers, macros and functions in the standard library shall not be defined, redefined or undefined
  MISRA08_17-0-2 - Published Standards\MISRA-C++ 2008\17-0-2 The names of standard library macros and objects shall not be reused
  MISRA08_17-0-3 - Published Standards\MISRA-C++ 2008\17-0-3 The names of standard library functions shall not be overridden
  MISRA08_17-0-5 - Published Standards\MISRA-C++ 2008\17-0-5 The setjmp macro and the longjmp function shall not be used
  MISRA08_18-0-1 - Published Standards\MISRA-C++ 2008\18-0-1 The C library shall not be used
  MISRA08_18-0-2 - Published Standards\MISRA-C++ 2008\18-0-2 The library functions atof, atoi and atol from library <cstdlib> shall not be used
  MISRA08_18-0-3 - Published Standards\MISRA-C++ 2008\18-0-3 The library functions abort, exit, getenv and system from library <cstdlib> shall not be used
  MISRA08_18-0-4 - Published Standards\MISRA-C++ 2008\18-0-4 The time handling functions of library <ctime> shall not be used
  MISRA08_18-0-5 - Published Standards\MISRA-C++ 2008\Unbounded Functions of &lt;cstring&gt;
  MISRA08_18-2-1 - Published Standards\MISRA-C++ 2008\18-2-1 The macro offsetof shall not be used.
  MISRA08_18-4-1 - Published Standards\MISRA-C++ 2008\18-4-1 Dynamic heap memory allocation shall not be used.
  MISRA08_18-7-1 - Published Standards\MISRA-C++ 2008\18-7-1 The signal handling facilities of
&lt;csignal&gt; shall not be used
  MISRA08_19-3-1 - Published Standards\MISRA-C++ 2008\19-3-1 The error indicator "errno" shall
not be used.
  MISRA08_2-10-1 - Published Standards\MISRA-C++ 2008\2-10-1 Different identifiers shall be typographically unambiguous
  MISRA08_2-10-2 - Published Standards\MISRA-C++ 2008\2-10-2 An identifier declared in an inner scope shall not hide an identifier declared in an outer scope
  MISRA08_2-10-3 - Published Standards\MISRA-C++ 2008\2-10-3 A typedef name shall be a unique identifier
  MISRA08_2-10-4 - Published Standards\MISRA-C++ 2008\2-10-4 A class, union or enum name (including qualification, if any) shall be a unique identifier
  MISRA08_2-10-5 - Published Standards\MISRA-C++ 2008\2-10-5 The identifier name of a non-member object or function with static storage duration should not be reused
  MISRA08_2-13-1 - Published Standards\MISRA-C++ 2008\2-13-1 escape sequences are standardized
  MISRA08_2-13-2 - Published Standards\MISRA-C++ 2008\2-13-2 Octal constants (other than zero) and octal escape sequences (other than "&#92;0" ) shall not be used.
  MISRA08_2-13-3 - Published Standards\MISRA-C++ 2008\2-13-3 A "U" suffix shall be applied to all octal or hexadecimal integer literals of unsigned type.
  MISRA08_2-13-4 - Published Standards\MISRA-C++ 2008\2-13-4 Literal suffixes shall be upper case
  MISRA08_2-13-5 - Published Standards\MISRA-C++ 2008\2-13-5 Narrow and wide string literals shall not be concatenated
  MISRA08_2-3-1 - Published Standards\MISRA-C++ 2008\2-3-1 Trigraphs shall not be used
  MISRA08_2-5-1 - Published Standards\MISRA-C++ 2008\2-5-1 Digraphs shall not be used
  MISRA08_2-7-1 - Published Standards\MISRA-C++ 2008\2-7-1 The character sequence &#47;* shall not be used within a C-style comment.
  MISRA08_2-7-2 - Published Standards\MISRA-C++ 2008\2-7-2 Sections of code should not be
"commented out"
  MISRA08_27-0-1 - Published Standards\MISRA-C++ 2008\27-0-1 The stream input/output library <cstdio> shall not be used
  MISRA08_3-1-1 - Published Standards\MISRA-C++ 2008\3-1-1 It shall be possible to include any header file in multiple translation units without violating the One Definition Rule
  MISRA08_3-1-2 - Published Standards\MISRA-C++ 2008\3-1-2 Functions shall not be declared at block scope
  MISRA08_3-1-3 - Published Standards\MISRA-C++ 2008\3-1-3 When an array is declared, its size shall either be stated explicitly or defined implicitly by initialization
  MISRA08_3-2-1 - Published Standards\MISRA-C++ 2008\3-2-1 All declarations of an object or function shall have compatible types
  MISRA08_3-2-2 - Published Standards\MISRA-C++ 2008\3-2-2 The One Definition Rule shall not be violated
  MISRA08_3-2-3 - Published Standards\MISRA-C++ 2008\3-2-3 A type, object or function that is used in multiple translation units shall be declared in one and only one file
  MISRA08_3-2-4 - Published Standards\MISRA-C++ 2008\3-2-4 An identifier with external linkage shall have exactly one definition
  MISRA08_3-3-1 - Published Standards\MISRA-C++ 2008\3-3-1 Objects or functions with external linkage shall be declared in a header file
  MISRA08_3-3-2 - Published Standards\MISRA-C++ 2008\3-3-2 If a function has internal linkage then all redeclarations shall include the static storage class specifier
  MISRA08_3-4-1 - Published Standards\MISRA-C++ 2008\3-4-1 An identifier declared to be an object or type shall be defined in a block that minimizes its visibility
  MISRA08_3-9-1 - Published Standards\MISRA-C++ 2008\3-9-1 The types used for an object, a function return type, or a function parameter shall be token-for-token identical in all declarations and re-declarations
  MISRA08_3-9-2 - Published Standards\MISRA-C++ 2008\3-9-2 Typedefs that indicate size and signedness should be used in place of the basic numerical types
  MISRA08_3-9-3 - Published Standards\MISRA-C++ 2008\3-9-3 The underlying bit representations of floating-point values shall not be used
  MISRA08_4-10-1 - Published Standards\MISRA-C++ 2008\4-10-1 NULL shall not be used as an integer value
  MISRA08_4-10-2 - Published Standards\MISRA-C++ 2008\4-10-2 Literal zero (0) shall not be used as the null-pointer-constant.
  MISRA08_4-5-1 - Published Standards\MISRA-C++ 2008\4-5-1 Expressions with type bool shall not be used as operands to built-in operators other than the assignment operator =, the logical operators &&, ||, !, the equality operators == and !=, the unary & operator, and the conditional operator
  MISRA08_4-5-2 - Published Standards\MISRA-C++ 2008\4-5-2 Expressions with type enum shall not be used as operands to built-in operators other than the subscript operator [ ], the assignment operator =, the equality operators == and !=, the unary & operator, and the relational operators <, <=, >, >=
  MISRA08_4-5-3 - Published Standards\MISRA-C++ 2008\4-5-3 Expressions with type (plain) char and wchar_t shall not be used as operands to built-in operators other than the assignment operator =, the equality operators == and !=, and the unary & operator
  MISRA08_5-0-1 - Published Standards\MISRA-C++ 2008\5-0-1 The value of an expression shall be the same under any order of evaluation that the standard permits
  MISRA08_5-0-10 - Published Standards\MISRA-C++ 2008\5-0-10 If the bitwise operators ~ and &lt;&lt; are applied to an operand with an underlying type of unsigned char or unsigned short, the result shall be immediately cast to the underlying type of the operand
  MISRA08_5-0-11 - Published Standards\MISRA-C++ 2008\5-0-11 The plain char type shall only be used for the storage and use of character values
  MISRA08_5-0-12 - Published Standards\MISRA-C++ 2008\5-0-12 Signed char and unsigned char type shall only be used for the storage and use of numeric values
  MISRA08_5-0-14 - Published Standards\MISRA-C++ 2008\5-0-14 The first operand of a conditional-operator shall have type bool
  MISRA08_5-0-17 - Published Standards\MISRA-C++ 2008\5-0-17 Subtraction between pointers shall only be applied to pointers that address elements of the same array
  MISRA08_5-0-18 - Published Standards\MISRA-C++ 2008\5-0-18 &gt;, &gt;=, &lt;, &lt;= shall not be applied to objects of pointer type, except where they point to the same array
  MISRA08_5-0-19 - Published Standards\MISRA-C++ 2008\5-0-19 The declaration of objects shall contain no more than two levels of pointer indirection
  MISRA08_5-0-2 - Published Standards\MISRA-C++ 2008\5-0-2 Limited dependence should be placed on C++ operator precedence rules in expressions
  MISRA08_5-0-20 - Published Standards\MISRA-C++ 2008\5-0-20 Non-constant operands to a binary bitwise operator shall have the same underlying type
  MISRA08_5-0-21 - Published Standards\MISRA-C++ 2008\5-0-21 Bitwise operators shall only be applied to operands of unsigned underlying type
  MISRA08_5-0-3 - Published Standards\MISRA-C++ 2008\5-0-3 A cvalue expression shall not be implicitly converted to a different underlying type
  MISRA08_5-0-4 - Published Standards\MISRA-C++ 2008\5-0-4 An implicit integral conversion shall not change the signedness of the underlying type
  MISRA08_5-0-5 - Published Standards\MISRA-C++ 2008\5-0-5 There shall be no implicit floating-integral conversions
  MISRA08_5-0-6 - Published Standards\MISRA-C++ 2008\5-0-6 An implicit integral or floating-point conversion shall not reduce the size of the underlying type
  MISRA08_5-0-7 - Published Standards\MISRA-C++ 2008\5-0-7 There shall be no explicit floating-integral conversions of a cvalue expression
  MISRA08_5-0-8 - Published Standards\MISRA-C++ 2008\5-0-8 An explicit integral or floating-point conversion shall not increase the size of the underlying type of a cvalue expression
  MISRA08_5-0-9 - Published Standards\MISRA-C++ 2008\5-0-9 An explicit integral conversion shall not change the signedness of the underlying type of a cvalue expression
  MISRA08_5-2-10 - Published Standards\MISRA-C++ 2008\5-2-10 The increment (++) and decrement (--) operators shall not be mixed with other operators in an expression
  MISRA08_5-2-11 - Published Standards\MISRA-C++ 2008\5-2-11 The comma operator, && operator and the || operator shall not be overloaded
  MISRA08_5-2-12 - Published Standards\MISRA-C++ 2008\5-2-12 An identifier with array type passed as a function argument shall not decay to a pointer
  MISRA08_5-2-3 - Published Standards\MISRA-C++ 2008\5-2-3 Casts from a base class to a derived class should not be performed on polymorphic types
  MISRA08_5-2-5 - Published Standards\MISRA-C++ 2008\5-2-5 A cast shall not remove any const or volatile qualification from the type of a pointer or reference
  MISRA08_5-2-6 - Published Standards\MISRA-C++ 2008\5-2-6 A cast shall not convert a pointer to a function to any other pointer type, including a pointer to function type
  MISRA08_5-2-8 - Published Standards\MISRA-C++ 2008\5-2-8 An object with integer type or pointer to void type shall not be converted to an object with pointer type.
  MISRA08_5-2-9 - Published Standards\MISRA-C++ 2008\5-2-9 A cast shall not convert a pointer type to an integral type.
  MISRA08_5-3-1 - Published Standards\MISRA-C++ 2008\5-3-1 Each operand of the ! operator, the logical && or the logical || operators shall have type bool
  MISRA08_5-3-3 - Published Standards\MISRA-C++ 2008\5-3-3 The unary & operator shall not be overloaded
  MISRA08_5-3-4 - Published Standards\MISRA-C++ 2008\5-3-4 Evaluation of the operand to the sizeof operator shall not contain side effects
  MISRA08_5-8-1 - Published Standards\MISRA-C++ 2008\5-8-1 The right hand operand of a shift operator shall lie between zero and one less than the width in bits of the underlying type of the left hand operand.
  MISRA08_6-2-2 - Published Standards\MISRA-C++ 2008\6-2-2 Floating-point expressions shall not be
directly or indirectly tested for equality or inequality.
  MISRA08_6-2-3 - Published Standards\MISRA-C++ 2008\6-2-3 Before preprocessing, a null statement shall only occur on a line by itself; it may be followed by a comment, provided that the first character following the null statement is a white-space character
  MISRA08_6-3-1 - Published Standards\MISRA-C++ 2008\6-3-1 The statement forming the body of a switch, while, do ... while or for statement shall be a compound statement
  MISRA08_6-4-1 - Published Standards\MISRA-C++ 2008\6-4-1 An if ( condition ) construct shall be followed by a compound statement. The else keyword shall be followed by either a compound statement, or another if statement
  MISRA08_6-4-2 - Published Standards\MISRA-C++ 2008\6-4-2 All if ... else if constructs shall be terminated with an else clause
  MISRA08_6-4-4 - Published Standards\MISRA-C++ 2008\6-4-4 A switch-label shall only be used when the most closely-enclosing compound statement is the body of a switch statement
  MISRA08_6-4-5 - Published Standards\MISRA-C++ 2008\6-4-5 An unconditional throw or break statement shall terminate every non-empty switch-clause
  MISRA08_6-4-6 - Published Standards\MISRA-C++ 2008\6-4-6 The final clause of a switch statement shall be the default-clause
  MISRA08_6-4-8 - Published Standards\MISRA-C++ 2008\6-4-8 Every switch statement shall have at least one case clause
  MISRA08_6-5-1 - Published Standards\MISRA-C++ 2008\6-5-1 A for loop shall contain a single loop-counter which shall not have floating type
  MISRA08_6-5-2 - Published Standards\MISRA-C++ 2008\6-5-2 If loop-counter is not modified by -- or ++, then, within condition, the loop-counter shall only be used as an operand to <=, <, > or >=
  MISRA08_6-5-3 - Published Standards\MISRA-C++ 2008\6-5-3 The loop-counter shall not be modified within condition or statement
  MISRA08_6-5-4 - Published Standards\MISRA-C++ 2008\6-5-4 The loop-counter shall be modified by one of: --, ++, -= n, or += n; where n remains constant for the duration of the loop
  MISRA08_6-5-5 - Published Standards\MISRA-C++ 2008\6-5-5 A loop-control-variable other than the loop-counter shall not be modified within condition or expression
  MISRA08_6-5-6 - Published Standards\MISRA-C++ 2008\6-5-6 A loop-control-variable other than the loop-counter which is modified in statement shall have type bool
  MISRA08_6-6-1 - Published Standards\MISRA-C++ 2008\6-6-1 Any label referenced by a goto statement shall be declared in the same block, or in a block enclosing the goto statement
  MISRA08_6-6-2 - Published Standards\MISRA-C++ 2008\6-6-2 The goto statement shall jump to a label declared later in the same function body
  MISRA08_6-6-4 - Published Standards\MISRA-C++ 2008\6-6-4 For any iteration statement there shall be no more than one break or goto statement used for loop termination
  MISRA08_6-6-5 - Published Standards\MISRA-C++ 2008\6-6-5 A function shall have a single point of exit at the end of the function
  MISRA08_7-1-1 - Published Standards\MISRA-C++ 2008\7-1-1 A variable which is not modified shall be const qualified
  MISRA08_7-1-2 - Published Standards\MISRA-C++ 2008\7-1-2 A pointer or reference parameter in a function shall be declared as pointer to const or reference to const if the corresponding object is not modified
  MISRA08_7-2-1 - Published Standards\MISRA-C++ 2008\7-2-1 An expression with enum underlying type shall only have values corresponding to the enumerators of the enumeration
  MISRA08_7-3-1 - Published Standards\MISRA-C++ 2008\7-3-1 The global namespace shall only contain main, namespace declarations and extern "C" declarations
  MISRA08_7-3-2 - Published Standards\MISRA-C++ 2008\7-3-2 The identifier main shall not be used for a function other than the global function main
  MISRA08_7-3-3 - Published Standards\MISRA-C++ 2008\7-3-3 There shall be no unnamed namespaces in header files.
  MISRA08_7-3-4 - Published Standards\MISRA-C++ 2008\7-3-4 Using-directives shall not be used.
  MISRA08_7-3-5 - Published Standards\MISRA-C++ 2008\7-3-5 Multiple declarations for an identifier in the same namespace shall not straddle a using-declaration for that identifier
  MISRA08_7-3-6 - Published Standards\MISRA-C++ 2008\7-3-6 using-directives and using-declarations (excluding class scope or function scope using-declarations) shall not be used in header files.
  MISRA08_7-4-2 - Published Standards\MISRA-C++ 2008\7-4-2 Assembler instructions shall only be introduced using the asm declaration.
  MISRA08_7-4-3 - Published Standards\MISRA-C++ 2008\7-4-3 Assembly language shall be encapsulated and isolated.
  MISRA08_7-5-1 - Published Standards\MISRA-C++ 2008\7-5-1 A function shall not return a reference or a pointer to an automatic variable (including parameters), defined within the function.
  MISRA08_7-5-2 - Published Standards\MISRA-C++ 2008\7-5-2 The address of an object with automatic storage shall not be assigned to another object that may persist after the first object has ceased to exist.
  MISRA08_7-5-4 - Published Standards\MISRA-C++ 2008\7-5-4 Functions should not call themselves, either directly or indirectly.
  MISRA08_8-0-1 - Published Standards\MISRA-C++ 2008\8-0-1 An init-declarator-list or a member-declarator-list shall consist of a single init-declarator or member-declarator respectively.
  MISRA08_8-3-1 - Published Standards\MISRA-C++ 2008\8-3-1 Parameters in an overriding virtual function shall either use the same default arguments as the function they override, or else shall not specify any default arguments.
  MISRA08_8-4-1 - Published Standards\MISRA-C++ 2008\8-4-1 Functions shall not be defined using the ellipsis notation
  MISRA08_8-4-2 - Published Standards\MISRA-C++ 2008\8-4-2 Use the same identifier in definition and declaration of functions.
  MISRA08_8-4-3 - Published Standards\MISRA-C++ 2008\8-4-3 All exit paths from a function with non-void return type shall have an explicit return statement with an expression.
  MISRA08_8-4-4 - Published Standards\MISRA-C++ 2008\8-4-4 A function identifier shall either be used to call the function or it shall be preceded by &
  MISRA08_8-5-1 - Published Standards\MISRA-C++ 2008\8-5-1 All variables shall have a defined value before they are used
  MISRA08_8-5-3 - Published Standards\MISRA-C++ 2008\8-5-3 The = construct in enumerator list shall only be used on either the first item alone, or all items explicitly.
  MISRA08_9-3-1 - Published Standards\MISRA-C++ 2008\9-3-1 Const member functions shall not return non-const pointers or references to class-data
  MISRA08_9-3-2 - Published Standards\MISRA-C++ 2008\9-3-2 Member functions shall not return non-const handles to class-data
  MISRA08_9-3-3 - Published Standards\MISRA-C++ 2008\9-3-3 If a member function can be made static then it shall be made static, otherwise if it can be made const then it shall be made const
  MISRA08_9-5-1 - Published Standards\MISRA-C++ 2008\9-5-1 Unions shall not be used
  MISRA08_9-6-2 - Published Standards\MISRA-C++ 2008\9-6-2 Bit-fields shall be either bool type or an explicitly unsigned or signed integral type.
  MISRA08_9-6-3 - Published Standards\MISRA-C++ 2008\9-6-3 Bit-fields shall not have enum type.
  MISRA08_9-6-4 - Published Standards\MISRA-C++ 2008\( Fuzzy parser ) 9-6-4 Named bit-fields with signed integer type shall have a length of more than one bit
