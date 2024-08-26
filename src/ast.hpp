#pragma once
#include <fstream>
#include <string>

namespace AbstractSyntaxTree
{

class ASTNode
{
public:
    virtual ~ASTNode() = default;

    virtual void accept(class Visitor& visitor) = 0;
};
using ASTNodePtr = std::unique_ptr<ASTNode>;

class Expression : public ASTNode
{
public:
    virtual ~Expression() = default;
};

class IntegerLiteral : public Expression
{
public:
    int value;

    IntegerLiteral(int val) : value(val) {}
    void accept(Visitor& accept) override;
};

class VariableDeclaration : public Expression
{
public:
    std::string data_type;
    std::string identifier_name;

    void accept(Visitor& accept) override;
    VariableDeclaration(std::string _data_type, std::string _iden_name)
        : data_type(_data_type), identifier_name(_iden_name)
    {
    }
};

class VariableDefinition : public Expression
{
public:
    std::string identifier_name;
    ASTNodePtr expression;

    void accept(class Visitor& accept) override;
    VariableDefinition(std::string _identifier_name, ASTNodePtr _expression)
        : identifier_name(_identifier_name), expression(std::move(_expression))
    {
    }
};

class Visitor
{
public:
    virtual void visit(IntegerLiteral& literal) = 0;
    virtual void visit(VariableDeclaration& literal) = 0;
    virtual void visit(VariableDefinition& literal) = 0;
};

class PrintVisitor : public Visitor
{
public:
    void visit(IntegerLiteral& literal) override;
    void visit(VariableDeclaration& decl) override;
    void visit(VariableDefinition& def) override;
};

class Emitter
{
public:
    Emitter(const Emitter&) = delete;
    static Emitter& GetInstance();

    template <typename T>
    void emit(T data);
    int stack_offset;
    int stack_alloc;
    std::ofstream asm_file;

private:
    Emitter();
};

class EmitVisitor : public Visitor
{
public:
    void visit(VariableDefinition& def) override;
    void visit(VariableDeclaration& decl) override;
    void visit(IntegerLiteral& literal) override;

private:
    Emitter& e_Instance = Emitter::GetInstance();
};

};  // namespace AbstractSyntaxTree
