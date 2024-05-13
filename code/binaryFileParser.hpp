#pragma once
#include "bufferInputStream.hpp"
#include "codeObject.hpp"

class BinaryFileParser {
private:
    BufferInputStream *file_stream;

public:
    BinaryFileParser(BufferInputStream *stream) {
        file_stream = stream;
    }

    CodeObject *parse();

};