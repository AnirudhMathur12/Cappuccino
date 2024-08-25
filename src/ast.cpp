#include "ast.hpp"

#include <iostream>

using namespace AbstractSyntaxTree;

void IntegerLiteral::accept(Visitor& accept) { accept.visit(*this); }
void VariableDeclaration::accept(Visitor& accept) { accept.visit(*this); }
void VariableDefinition::accept(Visitor& accept) { accept.visit(*this); }

void PrintVisitor::visit(IntegerLiteral& literal)
{
    std::cout << literal.value;
}
void PrintVisitor::visit(VariableDeclaration& decl)
{
    std::cout << "Data Type: " << decl.data_type
              << "\nIdentifier Name: " << decl.identifier_name;
}
void PrintVisitor::visit(VariableDefinition& def)
{
    std::cout << "Identifier Name: " << def.identifier_name;
    def.expression->accept(*this);
}
