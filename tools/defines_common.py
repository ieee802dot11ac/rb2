# Game versions
DEFAULT_VERSION = 0
VERSIONS = [
    "SZAE69",    # 0
]

# Include paths
cflags_includes = [
    # C/C++ stdlib
    # STLport requires that it comes first in the include path list
    "-i src/system/stlport",
    "-i src/sdk/PowerPC_EABI_Support/MSL/MSL_C",
    # Not included since it's all wrapped by stlport
    # "-i src/sdk/PowerPC_EABI_Support/MSL/MSL_C++",

    # To allow referring directly to the MSL SDK instead of going through STLport
    "-i src/sdk/PowerPC_EABI_Support/MSL",

    # SDK
    "-i src/sdk",
    "-i src/sdk/RVL_SDK",

    # Libraries
    "-i src/libs",
    "-i src/system/speex/include",

    # Project source
    "-i src",
    "-i src/network",
    "-i src/system",
    "-i src/band2",
]
