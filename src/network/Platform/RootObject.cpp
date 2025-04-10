#include "Platform/RootObject.h"
#include "Platform/MemoryManager.h"

namespace Quazal {

    void *RootObject::operator new(unsigned long ul) {
        return MemoryManager::Allocate(ul, MemoryManager::_InstType3);
    }

    void *RootObject::operator new(unsigned long ul, char *cc, unsigned int ui) {
        void *v = MemoryManager::Allocate(
            MemoryManager::GetDefaultMemoryManager(), ul, cc, ui, MemoryManager::_InstType3
        );
        return v;
    }

    void *RootObject::operator new[](unsigned long ul) {
        return MemoryManager::Allocate(ul, MemoryManager::_InstType4);
    }

    void *RootObject::operator new[](unsigned long ul, char *cc, unsigned int ui) {
        void *v = MemoryManager::Allocate(
            MemoryManager::GetDefaultMemoryManager(), ul, cc, ui, MemoryManager::_InstType4
        );
        return v;
    }

    void RootObject::operator delete(void *v) {
        MemoryManager::Free(
            MemoryManager::GetDefaultMemoryManager(), v, MemoryManager::_InstType3
        );
    }

    void RootObject::operator delete[](void *v) {
        MemoryManager::Free(
            MemoryManager::GetDefaultMemoryManager(), v, MemoryManager::_InstType4
        );
    }

}
