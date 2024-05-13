#include "binaryFileParser.hpp"

CodeObject *BinaryFileParser::parse()  
{
    int magic_number = file_stream->read_int();
    printf("magic number is 0x %x\n", magic_number);
    int bit_field = file_stream->read_int();
    printf("bit field is 0x %x\n", bit_field);
    int mod_date = file_stream->read_int();
    printf("mod date is 0x %x\n", mod_date);

    int file_size = file_stream->read_int();
    printf("file size is 0x %x\n", file_size);


    return nullptr;
}
