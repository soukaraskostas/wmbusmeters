#ifndef UTIL_H
#define UTIL_H

#include <cstring>
#include <ctime>

#ifdef _WIN32

// Dummy pthread_t typedef for Windows
typedef void* pthread_t;

// No-op wakeMeUpOnSigChld on Windows
inline void wakeMeUpOnSigChld(pthread_t t) { /* no-op */ }

// Minimal strptime stub for Windows (expand if needed)
inline char* strptime(const char* s, const char* f, struct tm* tm) {
    // This is a stub: does not parse properly, returns nullptr
    // You can improve this if needed or use a library
    (void)s; (void)f; (void)tm;
    return nullptr;
}

// Stub syslog macros for Windows
#define LOG_ERR 3
inline void syslog(int priority, const char* fmt, ...) {
    (void)priority; (void)fmt; 
    // no-op or implement Windows logging here
}

#else

#include <pthread.h>
#include <syslog.h>  // For syslog on Unix-like systems
void wakeMeUpOnSigChld(pthread_t t);

#endif

#endif // UTIL_H
