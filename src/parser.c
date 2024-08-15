#include "parser.h"
#include "tokenizer.h"

struct AST *parse(struct Token *head) {
    struct Token *iter = NULL;
    iter = head;
    int count = 0;
    while (iter->tok_type != TOK_NEWLINE) {
        count++;
        iter = iter->next;
    }
    struct AST *ast = (struct AST *)malloc(sizeof(struct AST));
    if (count == 2) {
        // it is a variable decl;
        ast->tag = AST_VARIABLE_DECLARATION;
        ast->data.AST_VARIABLE_DECLARATION = (struct AST_VARIABLE_DECLARATION){
            head->tok_name, (head = head->next)->tok_name};
    }
    return ast;
}
