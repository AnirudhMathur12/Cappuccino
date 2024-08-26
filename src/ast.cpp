#include "ast.hpp"

#include <iostream>

#include "tokenizer.hpp"

using namespace AbstractSyntaxTree;

void IntegerLiteral::accept(Visitor& accept) { accept.visit(*this); }
void VariableDeclaration::accept(Visitor& accept) { accept.visit(*this); }
void VariableDefinition::accept(Visitor& accept) { accept.visit(*this); }

void PrintVisitor::visit(IntegerLiteral& literal)
{
    std::cout << "Data: " << literal.value;
}
void PrintVisitor::visit(VariableDeclaration& decl)
{
    std::cout << "Data Type: " << decl.data_type
              << "\tIdentifier Name: " << decl.identifier_name << "\n";
}
void PrintVisitor::visit(VariableDefinition& def)
{
    std::cout << "Identifier Name: " << def.identifier_name << "\t";
    def.expression->accept(*this);
    std::cout << std::endl;
}

void EmitVisitor::visit(IntegerLiteral& literal)
{
    e_Instance.emit(literal.value);
}

void EmitVisitor::visit(VariableDefinition& def)
{
    e_Instance.emit("\tmov w8, #");
    def.expression->accept(*this);
    e_Instance.emit("\n");
    e_Instance.emit("\tstr w8, [sp, #");
    e_Instance.emit(e_Instance.stack_offset);
    e_Instance.emit("]\n");
}

void EmitVisitor::visit(VariableDeclaration& decl) {}

Emitter& Emitter::GetInstance()
{
    static Emitter e_Instance;
    return e_Instance;
}

template <typename T>
void Emitter::emit(T data)
{
    asm_file << data;
}

#include "parser.hpp"
Emitter::Emitter()
{
    n_Parser::Parser& inst = n_Parser::Parser::GetInstance();
    stack_alloc = 16 * (inst.GetByteCount() / 12 + 1);
    stack_offset = 16 * (inst.GetByteCount() / 12 + 1) - 4;
    asm_file.open("main.s");
    asm_file << ".global _main\n";
    asm_file << ".align 4\n";
    asm_file << "\n_main:\n";
    asm_file << "\tsub sp, sp, #" << stack_alloc << "\n";
    asm_file << "\tmov wzr, [sp, #" << stack_offset << "]\n";
}
