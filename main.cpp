#include<vector>
#include<fstream>
#include"rcode.h"
#include"disassembler.h"
#include"findl.h"

int main()
{
    std::vector<int> code;

    while( !code_of_skript( code ) );

    std::vector<std::string> skript;
    std::map<int, std::string> link;

    find_link( code, link );

    disassembler( code, skript, link );

    std::ofstream fskript( "skript.txt" );

    if( !fskript.is_open() )
    {
        std::cout << "The file for writing did not open" << std::endl;
        return 1;
    }

    for( size_t i = 0; i < skript.size(); ++i )
        fskript << skript[ i ] << "\n";

    fskript.close();

    system( "notepad.exe skript.txt" );
    return 0;
}
