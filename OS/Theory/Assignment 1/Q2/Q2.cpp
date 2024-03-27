#include <iostream>
#include "getch.h"
using namespace std;

enum opcode
{
    ADD,
    SUB,
    MUL,
    LOAD,
    STORE,
    AND,
    OR,
    XOR,
    STOREREG
};

class instruct
{
public:
    opcode op;
    int operand1;
    int loc;
    instruct(opcode o, int mem, int oper1)
    {
        op = o;
        loc = mem;
        operand1 = oper1;
    }
    void print()
    {
        cout << "Opcode : " << op << endl;
        cout << "Location : " << loc << endl;
        cout << "Operand 1 : " << operand1 << endl;
    }
};

void process(instruct ins, int *memory, int &reg)
{
    switch (ins.op)
    {
    case STORE:
        memory[ins.loc] = ins.operand1;
        break;
    case STOREREG:
        memory[ins.loc] = reg;
        break;
    case ADD:
        reg = memory[ins.loc] + reg;
        break;
    case SUB:
        reg = memory[ins.loc] - reg;
        break;
    case MUL:
        reg = memory[ins.loc] * reg;
        break;
    case AND:
        reg = memory[ins.loc] & reg;
        break;
    case OR:
        reg = memory[ins.loc] | reg;
        break;
    case XOR:
        reg = memory[ins.loc] ^ reg;
        break;
    case LOAD:
        reg = memory[ins.loc];
        break;
    default:
        break;
    }
}
void view_memory(int *mem)
{
    for (int i = 0; i < 20; i++)
    {
        if (i % 10 == 0)
        {
            cout << endl;
        }
        cout << mem[i] << " ";
    }
}
int main()
{
    int memory[20] = {0};

    int Register = 0;

    // instruct preintr[5] = {{STORE, 0, 5}, {STORE, 1, 6},{LOAD,0,-1},{ADD,1,-1},{STOREREG,2,-1}};
    instruct preintr[5] = {{STORE, 0, 5}, {STORE, 1, 6},{LOAD,0,-1},{AND,1,-1},{STOREREG,2,-1}};

    for (int pc = 0; pc < 5; pc++)
    {
        process(preintr[pc],memory,Register);
        view_memory(memory);
        cout<<endl<<"Registor Value : "<<Register<<endl<<endl;
        getch();
    }

    return 0;
}