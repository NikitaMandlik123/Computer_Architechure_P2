# Project 2: CAO: CS520-02: Pipeline Simulator

## AIM: Develop the simulated pipeline with an instruction decoder.

Pipeline follow three stages are as follows-

1. 1 stage for fetch (IF)
2. 1 stage for decode (ID)
3. 1 stage for execution (EX)

The pipeline supports 4B fixed-length instructions, which stands 1B for opcode, 1B for destination and 2B for two operands. The destination and left operands are always registers. The right operand can be either register or an immediate value.

## Output for the pipeline which updates the register values (Number of registers=16), total execution cycles and IPC.

Registers:

R0: 8 | R1: 808

R2: 161 | R3: 696

R4: 404 | R5: 707

R6: 957 | R7: 2443

R8: 772 | R9: 1468

R10: 104 | R11: 2241

R12: 1534 | R13: 315

R14: 89 | R15: 425

Total execution cycles: 152

IPC: 0.986842


