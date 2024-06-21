#ifndef UNITY_ENGINE_HEADER
#define UNITY_ENGINE_HEADER

#include <stdint.h>

#include "utility/singleton.hh"

struct Resolution {
    int32_t m_Width = 0;
    int32_t m_Height = 0;
    int32_t m_RefreshRate = 0;
};

struct RefreshRate {
    int32_t numerator = 0;
    int32_t denominator = 0;
};

class Unity : public Singleton<Unity> {
public:
    void Init(void*);

    Resolution GetSystemExtImpl();
    Resolution GetResolution();
    void SetResolution(float);
    void SetFrameRate(int, bool);

private:
    using il2cpp_resolve_icall_f = void* (*)(const char*);
    using set_targetFrameRate_f = void (*)(int);
    using SetResolution_t = void (*)(int, int, int, int);
    using SetResolution_Injected_t = void (*)(int32_t, int32_t, int32_t, RefreshRate*);
    using get_currentResolution_t = void (*)(Resolution*);
    using GetSystemExtImpl_t = void (*)(void*, int*, int*);

    il2cpp_resolve_icall_f il2cpp_resolve_icall = nullptr;
    set_targetFrameRate_f set_targetFrameRate = nullptr;
    SetResolution_t SetResolution_Internal = nullptr;
    SetResolution_Injected_t SetResolution_Injected_Internal = nullptr;
    get_currentResolution_t get_currentResolution = nullptr;
    GetSystemExtImpl_t GetSystemExtImpl_Internal = nullptr;
};

#endif // unity_engine.hh
