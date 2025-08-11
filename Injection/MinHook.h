#pragma once

// Minimal stub for the MinHook library.
// Allows the project to compile even when the real
// MinHook NuGet package is not available.

#ifdef MINHOOK_USE_LIB
#include <MinHook.h>
#else
// Basic status code used by MinHook.
typedef int MH_STATUS;
#ifndef MH_OK
#define MH_OK 0
#endif

#ifdef __cplusplus
extern "C" {
#endif

static inline MH_STATUS WINAPI MH_Initialize(void) { return MH_OK; }
static inline MH_STATUS WINAPI MH_CreateHookApiEx(
    LPCWSTR, LPCSTR, LPVOID, LPVOID*, LPVOID*) {
    return MH_OK;
}
static inline MH_STATUS WINAPI MH_EnableHook(LPVOID) { return MH_OK; }

#ifdef __cplusplus
}
#endif

#endif // MINHOOK_USE_LIB