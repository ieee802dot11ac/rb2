/*
    Compile unit: C:\rockband2\system\src\obj\Data.h
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x805F41C8 -> 0x805F41EC
*/
// Range: 0x805F41C8 -> 0x805F41EC

namespace Hmx {
    class Object;
}

enum DataType {
    kDataInt = 0,
    kDataFloat = 1,
    kDataVar = 2,
    kDataFunc = 3,
    kDataObject = 4,
    kDataSymbol = 5,
    kDataUnhandled = 6,
    kDataArray = 16,
    kDataCommand = 17,
    kDataString = 18,
    kDataProperty = 19,
    kDataGlob = 20,
    kDataIfdef = 7,
    kDataElse = 8,
    kDataEndif = 9,
    kDataDefine = 32,
    kDataInclude = 33,
    kDataMerge = 34,
    kDataIfndef = 35,
    kDataAutorun = 36,
    kDataUndef = 37,
};

class DataNode {
    // total size: 0x8
    union /* @class$5318App_cpp */ {
        const char *symbol; // offset 0x0, size 0x4
        int integer; // offset 0x0, size 0x4
        float real; // offset 0x0, size 0x4
        class DataArray *array; // offset 0x0, size 0x4
        class DataNode *var; // offset 0x0, size 0x4
        DataNode (*func)(class DataArray *); // offset 0x0, size 0x4
        Hmx::Object *object; // offset 0x0, size 0x4
    } mValue; // offset 0x0, size 0x4
    enum DataType mType; // offset 0x4, size 0x4
};

class DataNode &DataArray::Evaluate() {}
