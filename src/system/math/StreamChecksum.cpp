/*
    Compile unit: C:\rockband2\system\src\math\StreamChecksum.cpp
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x80630FCC -> 0x80631338
*/
// Range: 0x80630FCC -> 0x80631058
unsigned char
StreamChecksum::Begin(const char *file /* r30 */, unsigned char nameOnly /* r31 */) {
    // References
    // -> class Debug TheDebug;
    // -> const char * kAssertStr;
}

// Range: 0x80631058 -> 0x806310E4
void StreamChecksum::
    Update(const unsigned char *data /* r30 */, unsigned int len /* r31 */) {
    // References
    // -> class Debug TheDebug;
    // -> const char * kAssertStr;
}

// Range: 0x806310E4 -> 0x806310EC
void StreamChecksum::End() {}

// Range: 0x806310EC -> 0x80631144
unsigned char StreamChecksum::Validate() {
    // Local variables
    unsigned char buf[20]; // r1+0x8
}

// Range: 0x80631144 -> 0x80631198
void StreamChecksum::HandleError() {
    // References
    // -> class Debug TheDebug;
}

// Range: 0x80631198 -> 0x80631240
unsigned char StreamChecksum::SetFileChecksum(unsigned char nameOnly /* r31 */) {}

// Range: 0x80631240 -> 0x80631338
unsigned char StreamChecksum::ValidateChecksum(const unsigned char *hash /* r29 */) {
    // References
    // -> class Debug TheDebug;
    // -> const char * kAssertStr;
}
