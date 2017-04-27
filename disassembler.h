#ifndef DISASSEMBLER_H
#define DISASSEMBLER_H
#include<iostream>
#include<vector>
#include"key.h"

//!
//! \brief Arg puts in compliance \param code string
//! \param code
//! \return the corresponding line
//!
std::string Arg( int code )
{
    switch ( code )
    {
        case CODE_X0:
            return STR_X0;
            break;
        case CODE_X1:
            return STR_X0;
            break;
        case CODE_X2:
            return STR_X0;
            break;
        default:
            return std::to_string( code );
            break;
    }
}

bool disassembler( const std::vector<int>& code, std::vector<std::string>& skript, std::map<int, std::string>& link )
{
    size_t i = 0;

    while ( i < code.size() )
    {
        auto it = link.find( i );
        if( it != link.end() )
            skript.push_back( link[ i ] );

        switch ( code[ i ] ) {
        case CODE_END:
            skript.push_back( STR_END );
            break;
        case CODE_PUSH:
            skript.push_back( STR_PUSH );
            skript.push_back( Arg( code[ ++i ] ) );
            break;
        case CODE_POP:
            skript.push_back( STR_POP );
            break;
        case CODE_ADD:
            skript.push_back( STR_ADD );
            break;
        case CODE_SUB:
            skript.push_back( STR_SUB );
            break;
        case CODE_DIV:
            skript.push_back( STR_DIV );
            break;
        case CODE_MULT:
            skript.push_back( STR_MULT );
            break;
        case CODE_POW:
            skript.push_back( STR_POW );
            skript.push_back( std::to_string( code[ ++i ] ) );
            break;
        case CODE_JMP:
            skript.push_back( STR_JMP + " :" + std::to_string( code[ ++i ] ) );
            break;
        case CODE_CALL:
            skript.push_back( STR_CALL + " :" + std::to_string( code[ ++i ] ) );
            break;
        case CODE_RET:
            skript.push_back( STR_RET );
            break;
        case CODE_JE:
            skript.push_back( STR_JE );
            break;
        case CODE_JA:
            skript.push_back( STR_JA );
            break;
        case CODE_JAE:
            skript.push_back( STR_JAE );
            break;
        case CODE_JB:
            skript.push_back( STR_JB );
            break;
        case CODE_JBE:
            skript.push_back( STR_JBE );
            break;
        case CODE_JNE:
            skript.push_back( STR_JNE );
            break;
        default:
            std::cout << "Incorrect code of command - line: " << i << " Code: " << code[ i ] << std::endl;
            return false;
            break;
        }
        i++;
    }
    return true;
}



#endif // DISASSEMBLER_H
