Use the laundry analogy instead of completing one holw task start the first step of the 2nd task when the 1st task moves to second step.

A RISC processor pipeline operates in much the same way, although the stages in the pipeline are different. 
While different processors have different numbers of steps, they are basically variations of these five, used in the MIPS R3000 processor:

1. fetch instructions from memory

2. read registers and decode the instruction

3. execute the instruction or calculate an address

4. access an operand in data memory

5. write the result into a register

 Thus, the length of the pipeline is dependent on the length of the longest step.

**Bubbles**:

add $r3, $r2, $r1

add $r5, $r4, $r3

more instructions that are independent of the first two
In this example, the first instruction tells the processor to add the contents of registers r1 and r2 and store the result in register r3. 
The second instructs it to add r3 and r4 and store the sum in r5. We place this set of instructions in a pipeline. When the second 
instruction is in the second stage, the processor will be attempting to read r3 and r4 from the registers. Remember, though, that the 
first instruction is just one step ahead of the second, so the contents of r1 and r2 are being added, but the result has not yet been 
written into register r3. The second instruction therefore cannot read from the register r3 because it hasn't been written yet and must 
wait until the data it needs is stored. Consequently, the pipeline is stalled and a number of empty instructions (known as bubbles go 
into the pipeline. Data dependency affects long pipelines more than shorter ones since it takes a longer period of time for an instruction 
to reach the final register-writing stage of a long pipeline.

**Code reordering**:

MIPS' solution to this problem is code reordering. If, as in the example above, the following instructions have nothing to do with the first two,
the code could be rearranged so that those instructions are executed in between the two dependent instructions and the pipeline could 
flow efficiently. The task of code reordering is generally left to the compiler, which recognizes data dependencies and attempts to 
minimize performance stalls.

**Brance Prediction**:

Superpipelining refers to dividing the pipeline into more steps. The more pipe stages there are, the faster the pipeline is because each stage 
is then shorter. Ideally, a pipeline with five stages should be five times faster than a non-pipelined processor (or rather, a pipeline with 
one stage). The instructions are executed at the speed at which each stage is completed, and each stage takes one fifth of the amount of time
that the non-pipelined instruction takes. Thus, a processor with an 8-step pipeline (the MIPS R4000) will be even faster than its 5-step counterpart

For example:

Loop : add $r3, $r2, $r1

sub $r6, $r5, $r4

beq $r3, $r6, Loop

The example above instructs the processor to add r1 and r2 and put the result in r3, then subtract r4 from r5, storing the difference in r6. 
In the third instruction, beq stands for branch if equal. If the contents of r3 and r6 are equal, the processor should execute the instruction
labeled "Loop." Otherwise, it should continue to the next instruction. In this example, the processor cannot make a decision about which branch
to take because neither the value of r3 or r6 have been written into the registers yet.

The processor makes a guess about which path to take - if the guess is wrong, anything written into the registers must be cleared, and the pipeline 
must be started again with the correct instruction. Some methods of branch prediction depend on stereotypical behavior. Branches pointing backward 
are taken about 90% of the time since backward-pointing branches are often found at the bottom of loops. On the other hand, branches pointing forward,
are only taken approximately 50% of the time. Thus, it would be logical for processors to always follow the branch when it points backward, but not 
when it points forward. Other methods of branch prediction are less static: processors that use dynamic prediction keep a history for each branch 
and uses it to predict future branches. These processors are correct in their predictions 90% of the time.

**Pipelining Developments**:

Superpipelining refers to dividing the pipeline into more steps. The more pipe stages there are, the faster the pipeline is because each stage
is then shorter. Ideally, a pipeline with five stages should be five times faster than a non-pipelined processor (or rather, a pipeline with one stage).
The instructions are executed at the speed at which each stage is completed, and each stage takes one fifth of the amount of time that the non-pipelined
instruction takes. Thus, a processor with an 8-step pipeline (the MIPS R4000) will be even faster than its 5-step counterpart

**RISC**:

RISC, or Reduced Instruction Set Computer. is a type of microprocessor architecture that utilizes a small, highly-optimized set of instructions, 
rather than a more specialized set of instructions often found in other types of architectures.

Certain design features have been characteristic of most RISC processors:

**one cycle execution time**: RISC processors have a CPI (clock per instruction) of one cycle. This is due to the optimization of each instruction on the CPU and a technique called ;

**pipelining**: a techique that allows for simultaneous execution of parts, or stages, of instructions to more efficiently process instructions;

**large number of registers**: the RISC design philosophy generally incorporates a larger number of registers to prevent in large amounts of interactions with memory

CISC	               |     RISC

Emphasis on hardware |	Emphasis on software

Includes multi-clock | Single-clock,reduced instruction only

complex instructions |

Memory-to-memory:
"LOAD" and "STORE"
incorporated in instructions |	Register to register: "LOAD" and "STORE" are independent instructions

Small code sizes,
high cycles per second	Low cycles per second, | large code sizes
Transistors used for storing
complex instructions	Spends more transistors
on memory registers

**The CISC Approach**
The primary goal of CISC architecture is to complete a task in as few lines of assembly as possible. This is achieved by building processor hardware that is capable of understanding and executing a series of operations. For this particular task, a CISC processor would come prepared with a specific instruction (we'll call it "MULT"). When executed, this instruction loads the two values into separate registers, multiplies the operands in the execution unit, and then stores the product in the appropriate register. Thus, the entire task of multiplying two numbers can be completed with one instruction:


MULT 2:3, 5:2

MULT is what is known as a "complex instruction." It operates directly on the computer's memory banks and does not require the programmer to explicitly call any loading or storing functions. It closely resembles a command in a higher level language. For instance, if we let "a" represent the value of 2:3 and "b" represent the value of 5:2, then this command is identical to the C statement "a = a * b."

One of the primary advantages of this system is that the compiler has to do very little work to translate a high-level language statement into assembly. Because the length of the code is relatively short, very little RAM is required to store instructions. The emphasis is put on building complex instructions directly into the hardware.

**The RISC Approach**

RISC processors only use simple instructions that can be executed within one clock cycle. Thus, the "MULT" command described above could be divided into three separate commands: "LOAD," which moves data from the memory bank to a register, "PROD," which finds the product of two operands located within the registers, and "STORE," which moves data from a register to the memory banks. In order to perform the exact series of steps described in the CISC approach, a programmer would need to code four lines of assembly:


LOAD A, 2:3

LOAD B, 5:2

PROD A, B

STORE 2:3, A

At first, this may seem like a much less efficient way of completing the operation. Because there are more lines of code, more RAM is needed to store the assembly level instructions. The compiler must also perform more work to convert a high-level language statement into code of this form.

However, the RISC strategy also brings some very important advantages. Because each instruction requires only one clock cycle to execute, the entire program will execute in approximately the same amount of time as the multi-cycle "MULT" command. These RISC "reduced instructions" require less transistors of hardware space than the complex instructions, leaving more room for general purpose registers. Because all of the instructions execute in a uniform amount of time (i.e. one clock), pipelining is possible.

Separating the "LOAD" and "STORE" instructions actually reduces the amount of work that the computer must perform. After a CISC-style "MULT" command is executed, the processor automatically erases the registers. If one of the operands needs to be used for another computation, the processor must re-load the data from the memory bank into a register. In RISC, the operand will remain in the register until another value is loaded in its place.

**MIPS**

MIPS Architecture
Develop a processor whose architecture would represent the lowering of the compiler to the hardware level, as opposed to the raising of hardware to the software level, which had been a long running design philosophy in the hardware industry.

Instruction Set
The MIPS instruction set consists of about 111 total instructions, each represented in 32 bits. An example of a MIPS instruction is below:

add $r12, $r7, $r8

 addition instruction 
Above is the assembly (left) and binary (right) representation of a MIPS addition instruction. The instruction tells the processor to compute the sum of the values in registers 7 and 8 and store the result in register 12. The dollar signs are used to indicate an operation on a register. The colored binary representation on the right illustrates the 6 fields of a MIPS instruction. The processor identifies the type of instruction by the binary digits in the first and last fields. In this case, the processor recogizes that this instruction is an addition from the zero in its first field and the 20 in its last field.

The operands are represented in the blue and yellow fields, and the desired result location is presented in the fourth (purple) field. The orange field represents the shift amount, something that is not used in an addition operation.

The instruction set consists of a variety of basic instructions, including:


21 arithmetic instructions (+, -, *, /, %)
8 logic instructions (&, |, ~)
8 bit manipulation instructions
12 comparison instructions (>, <, =, >=, <=, ¬)
25 branch/jump instructions
15 load instructions
10 store instructions
8 move instructions
4 miscellaneous instructions

Thus, the MIPS processor implemented a smaller, simpler instruction set. Each of the instructions included in the chip design ran in a single clock cycle. The processor used a technique called pipelining to more efficiently process instructions.
Ref: https://cs.stanford.edu/people/eroberts/courses/soco/projects/risc/pipelining/index.html
https://cs.stanford.edu/people/eroberts/courses/soco/projects/risc/whatis/index.html
https://cs.stanford.edu/people/eroberts/courses/soco/projects/risc/mips/index.html
