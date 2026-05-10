#ifndef HLK_LEXER
#define HLK_LEXER

#define __string std::string_view

static bool entry_point_count = 0;

namespace hlk{
    struct LinePos;
    class LEX;
    enum class Tokens;
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
    GTHAN_EQUAL
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
    L_SQUARE_BRACKET = 0x41,
    R_SQUARE_BRACKET = 0x43,
    BACK_SLASH = 0x42,
    
};

struct Token{
    TokenType* token_type;
    LinePos* lnpos;
    Operators* op;
    MultiCharOperators* multi_ln_op;
};

class LEX{
    Token* token;
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

};

#endif