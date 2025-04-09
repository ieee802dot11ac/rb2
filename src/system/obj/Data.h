#pragma once
/*
    Compile unit: C:\rockband2\system\src\obj\Data.h
    Producer: MW EABI PPC C-Compiler
    Language: C++
    Code range: 0x805F41C8 -> 0x805F41EC
*/
// Range: 0x805F41C8 -> 0x805F41EC

#include "utl/Symbol.h"
#include "types.h"

// forward declarations
class DataNode;
class DataArray;
class DataArrayPtr;
namespace Hmx {
    class Object;
}

/** A function which can be called by a script/command. */
typedef DataNode DataFunc(DataArray *);

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
        DataFunc *func; // offset 0x0, size 0x4
        Hmx::Object *object; // offset 0x0, size 0x4
    } mValue; // offset 0x0, size 0x4
    enum DataType mType; // offset 0x4, size 0x4

    DataNode() {
        mValue.integer = 0;
        mType = kDataInt;
    }

    DataNode(int i) {
        mValue.integer = i;
        mType = kDataInt;
    }

    DataNode(long l) {
        mValue.integer = l;
        mType = kDataInt;
    }

    DataNode(Symbol s) {
        mType = kDataSymbol;
        mValue.symbol = s.mStr;
    }

    DataNode(Hmx::Object *obj) {
        mValue.object = obj;
        mType = kDataObject;
    }

    DataNode(DataType ty, int i) {
        mType = ty;
        mValue.integer = i;
    }

    DataNode(DataType ty, const char *s) {
        mType = ty;
        mValue.symbol = s;
    }

    DataNode(float f) {
        mValue.real = f;
        mType = kDataFloat;
    }

    DataNode(const DataNode &);
    DataNode(const char *string);
    DataNode(const class String &string);
    DataNode(const void *glob, int size);
    DataNode(const DataArrayPtr &);
    DataNode(DataArray *array, DataType type);

    DataNode(DataNode *var) {
        mValue.var = var;
        mType = kDataVar;
    }

    DataNode(DataFunc *func) {
        mValue.func = func;
        mType = kDataFunc;
    }

    ~DataNode();

    DataType Type() const { return mType; }
    bool CompatibleType(DataType) const;
    DataNode &Evaluate() const;

    // these were implemented to match up in retail
    // please do not use these in regular code
    int UncheckedInt() const { return mValue.integer; }
    const char *UncheckedStr() const { return mValue.symbol; }
    Hmx::Object *UncheckedObj() const { return mValue.object; }
    DataArray *UncheckedArray() const { return mValue.array; }
    DataNode *UncheckedVar() const { return mValue.var; }
    DataFunc *UncheckedFunc() const { return mValue.func; }

    int Int(const DataArray *source = nullptr) const;
    int LiteralInt(const DataArray *source = nullptr) const;
    Symbol Sym(const DataArray *source = nullptr) const;
    Symbol LiteralSym(const DataArray *source = nullptr) const;
    Symbol ForceSym(const DataArray *source = nullptr) const;
    const char *Str(const DataArray *source = nullptr) const;
    const char *LiteralStr(const DataArray *source = nullptr) const;
    void *Glob(int *size, const DataArray *source = nullptr) const;
    float Float(const DataArray *source = nullptr) const;
    float LiteralFloat(const DataArray *source = nullptr) const;
    DataFunc *Func(const DataArray *source = nullptr) const;
    Hmx::Object *GetObj(const DataArray *source = nullptr) const;
    DataArray *Array(const DataArray *source = nullptr) const;
    DataArray *LiteralArray(const DataArray *source = nullptr) const;
    DataArray *Command(const DataArray *source = nullptr) const;
    DataNode *Var(const DataArray *source = nullptr) const;

    // for retrieving a Hmx::Object derivative from a DataNode
    template <class T>
    T *Obj(const DataArray *source = nullptr) const {
        return dynamic_cast<T *>(GetObj(source));
    }

    bool operator==(const DataNode &n) const;
    bool operator!=(const DataNode &n) const;
    bool NotNull() const;
    bool operator!() const { return !NotNull(); }
    DataNode &operator=(const DataNode &n);

    /** Print the DataNode's contents to the TextStream.
     * @param [in] s The TextStream to print to.
     * @param [in] b TODO: currently unknown
     */
    void Print(TextStream &s, bool) const;
    bool PrintUnused(TextStream &, bool) const;
    /** Saves this DataNode into a BinStream. */
    void Save(BinStream &d) const;
    /** Loads this DataNode from a BinStream. */
    void Load(BinStream &d);
};

class DataArray {};
