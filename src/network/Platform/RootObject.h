#ifndef PLATFORM_ROOTOBJECT_H
#define PLATFORM_ROOTOBJECT_H

namespace Quazal {
    class RootObject {
    public:
        static void *operator new(unsigned long);
        static void *operator new(unsigned long, char *, unsigned int);
        static void *operator new[](unsigned long);
        static void *operator new[](unsigned long, char *, unsigned int);
        static void operator delete(void *);
        static void operator delete[](void *);
    };
}

#endif
