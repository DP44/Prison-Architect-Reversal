#include <iostream>
#include "Mutex.h"

// TODO: AppDebugOutRedirectBuffer class.

namespace Debug
{
    Mutex *mutex;
    std::string outFile;
}

void AppGenerateBlackBox(const std::string &outputFile, char *errMsg);

// These don't have code in the release build.
// void AppPrintMemoryLeaks(const char *a1);
// void AppPrintAvailableMemory(const char *a1);

void AppDebugOut(const char *msg, ...);
void AppDebugOutRedirect(const std::string &outputFile);
void AppReleaseAssert(bool assertion, const char *msg, ...);

