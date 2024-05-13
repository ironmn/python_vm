#pragma once
#include <stdio.h>

#define BUFFER_LEN 256

class BufferInputStream {
private:
    FILE *fp;
    char szBuffer[BUFFER_LEN];
    unsigned short index;
    void close() {
        if (fp != NULL) {
            fclose(fp);
            fp = NULL;
        }
    }

public:
    BufferInputStream(char const * filename) {
        fp = fopen(filename, "rb");
        fread(szBuffer, BUFFER_LEN * sizeof(char), 1, fp);
        index = 0;
    }

    ~BufferInputStream() {
        close();
    }

    char read() {
        if (index < BUFFER_LEN) {
            return szBuffer[index++];
        } else {
            index = 0;
            fread(szBuffer, BUFFER_LEN * sizeof(char), 1, fp);
            return szBuffer[index++];
        }
    }

    int read_int() {
        int b1 = read() & 0xff;
        int b2 = read() & 0xff;
        int b3 = read() & 0xff;
        int b4 = read() & 0xff;

        return b4 << 24 | b3 << 16 | b2 << 8 | b1;
    }

    void unread() {
        if (index == 0) {
            fseek(fp, -BUFFER_LEN, SEEK_CUR);
        }
        index--;
    }
};
