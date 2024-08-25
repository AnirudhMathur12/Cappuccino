#include <string>

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
    int value;

public:
    IntegerLiteral(int val) : value(val) {}
    void accept(class Visitor& accept) override;
};

class VariableDeclaration : public Expression
{
    std::string data_type;
    std::string identifier_name;

public:
    void accept(class Visitor& accept) override;
    VariableDeclaration(std::string _data_type, std::string _iden_name)
        : data_type(_data_type), identifier_name(_iden_name)
    {
    }
};

class VariableDefinition : public Expression
{
    std::string identifier_name;
    ASTNodePtr expression;

public:
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
