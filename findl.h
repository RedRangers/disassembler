#ifndef FINDL_H
#define FINDL_H
#include<iostream>
#include<vector>
#include<cassert>
#include"key.h"

#define CHECK
#undef CHEK

//!
//! \brief find_link creates a map of links \param link used in \param code
//! \param code code of skript
//! \param link result map of links
//!
void find_link( const std::vector<int>& code, std::map<int, std::string>& link )
{

//#ifdef CHECK
//    assert( code );
//    assert( link );
//#endif

    std::string s;
    for( size_t i = 1; i < code.size(); ++i )
        if( code[ i-1 ] == CODE_JMP || code[ i-1 ] == CODE_CALL )
        {
            s.clear();
            s = ":"+std::to_string( code[ i ] );
            link.insert( std::pair< int, std::string > ( code[ i ], s ) );
        }
}
#endif // FINDL_H
