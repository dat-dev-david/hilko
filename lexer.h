#ifndef HLK_LEXER
#define HLK_LEXER

#define __string std::string_view

static bool entry_point_count = 0;

namespace hlk{
    struct LinePos;
    class LEX;
    enum class Tokens;
    __string keywords[] = {"bool", "break", "case", "char", "class", "continue", "default", "define", "defined", "else", "enum", "false", "if", "int", "jump", "long", "namespace", "return", "struct", "switch", "template", "true", "while"};
    
}

struct LinePos{
    int line{}, column{};
};

enum class TokenType{
    ID,
    KEYWORD,
    STRING_LITERAL,
    INT_LITERAL
};

enum class MultiCharOperators{
    ADD_ASSIGNMENT,
    SUB_ASSIGNMENT,
    MUL_ASSIGNMENT,
    DIV_ASSIGNMENT,
    LTHAN_EQUAL,
    GTHAN_EQUAL,
    INCREMENT,
    DECREMENT,
    COMMENT,
    MULTI_LINE_COMMENT,
    SCOPE,
    TERNARY,
    REAL_BACKSLASH,
    ESCAPE_SEQ,
    TETRATION
};

enum class Operators{
    EXCLIMATION = 0x21,
    QUOTE = 0x22,
    SHARP = 0x23,
    MODULO = 0x25,
    AND = 0x26,
    SINGLE_QUOTE = 0x27,
    L_PARENTH = 0x28,
    R_PARENTH = 0x29,
    ASTERISK = 0x2a,
    ADD = 0x2b,
    COMMA = 0x2c,
    SUB = 0x2d,
    DOT = 0x2e,
    FORWARD_SLASH = 0x2f,
    COLON = 0x3a,
    SEMICOLON = 0x3b,
    GTHAN = 0x3c,
    EQUALS = 0x3d,
    LTHAN = 0x3e,
    QUESTION = 0x3f,
    AT = 0x40,
    L_SQUARE_BRACKET = 0x5b,
    BACK_SLASH = 0x5c,
    R_SQUARE_BRACKET = 0x5d,
    CARET = 0x5e,
    L_CURLY_BRACKET = 0x7b,
    PIPE = 0x7c,
    R_CURLY_BRACKET = 0x7d,
    TILDE = 0x7e
};

struct Token{
    TokenType* token_type {new TokenType};
    LinePos* lnpos {new LinePos};
    Operators* op {new Operators};
    MultiCharOperators* multi_ln_op {new MultiCharOperators};
};

class LEX{
    Token* token {new Token};
    bool ISNUM(char& selection){
        if(selection <= '0' && selection >= '9'){
            return true;
        } else {
            return false;
        }
    }
//65-90 97-122
    bool ISCHAR(char& selection){
        if((selection >= 65 && selection <= 90) || (selection >= 97 && selection <= 122)){
            return true;
        } else {
            return false;
        }
    }

    bool ISIDENTIFIER(__string& src){
        size_t pos{0};
        char c = src.at(pos);
        if(ISCHAR(c)){
            ++pos;
        } else {
            return false;
        }
        while(pos != std::string::npos){
            c=src.at(pos);
            if(ISCHAR(c) && ISNUM(c) || (c == '$' || c == '_')){
                ++pos;
                continue;
            } else {
                return false;
            }
        }
        return true;
    }

    /*bool ISKEYWORD(){

    }*/

};

#endif