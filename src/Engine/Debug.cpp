#include "Debug.h"

void AppGenerateBlackBox(const std::string &outputFile, char *errMsg)
{
    FILE *fileStream = UTF8Path::fopen(outputFile, "wt");
    
    if (!fileStream)
    {
        return;
    }

    fprintf(fileStream, "=========================\n");
    fprintf(fileStream, "=   BLACK BOX REPORT    =\n");
    fprintf(fileStream, "=========================\n\n");
    
    if (errMsg)
    {
        fprintf(fileStream, "ERROR : \'%s\'\n", errMsg);
    }

    fprintf(fileStream, "\n");
    fprintf(fileStream, "=========================\n");
    fprintf(fileStream, "=      STACKTRACE       =\n");
    fprintf(fileStream, "=========================\n\n");
    fflush(fileStream);
    
    backtrace_symbols_fd(backtrace(), fileno(fileStream));

    fclose(fileStream);
}

void AppDebugOut(const char *msg, ...)
{
    va_list va;
    char s[10248];

    Debug::mutex->Lock();
    
    va_start(va, msg);
    vsnprintf(s, 10240, msg, va);
    
    // if (!dword_14B839C)
    fputs(s, stderr);
    
    if (Debug::outFile)
    {
        FILE *fileStream = UTF8Path::fopen(Debug::outFile, "a");

        if (!fileStream)
        {
            Debug::outFile = NULL;
            Debug::mutex->Unlock();
            AppDebugOut("Failed to open '%s' file for writing\n", Debug::outFile);
            return;
        }

        fprintf(fileStream, "%s", s);
        fclose(fileStream);
    }

    // Weird loop thing which appends data onto some global variable.
    /*
        if (dword_14B839C > 0)
        {
            v1 = 0LL;
            v2 = 0;

            do
            {
                v3 = *(qword_14B8390 + v1);
                v4 = &s[strlen(s)];
                if (v4 - s > (0x7FFFFFFFFFFFFFFFLL - *(v3 + 8)))
                {
                    std::__throw_length_error("basic_string::append");
                }

                std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char>>::_M_append(
                    v3,
                    s,
                    v4 - s);
                ++v2;
                v1 += 8LL;
            }
            while (v2 < dword_14B839C);
        }
    */

    Debug::mutex->Unlock();
}

void AppDebugOutRedirect(const std::string &outputFile)
{
    Debug::mutex->Lock();

    if (outputFile)
    {
        Debug::outFile = NULL;
        Debug::mutex->Unlock();
        return;
    }
    
    Debug::outFile = new std::string(*outputFile);
    FILE *fstream = UTF8Path::fopen(Debug::outFile, "w");
    
    if (fstream)
    {
        fclose(fstream);
    }
    else
    {
        Debug::outFile = NULL;
        AppDebugOut("Failed to open %s for writing\n", *outputFile);
    }

    Debug::mutex->Unlock();
}

void AppReleaseAssert(bool assertion, const char *msg, ...)
{
    // Make sure it's successful first.
    if (assertion)
    {
        return;
    }

    va_list va;
    char errMsg[520];

    va_start(va, msg);
    vsprintf(512, msg, va);
    Debug::AppDebugOut("FATAL ERROR : %s\n", errMsg);
    fputs(errMsg, stderr);

    std::string outputPath = App::GetAppSaveFolder();

    if (outputPath)
    {
        outputPath.append("blackbox.txt");
        AppGenerateBlackBox(outputPath, errMsg);
        abort();
    }
}

/*
    void Debug::AppDebugOutData(void *a1, int a2)
    {
        int64_t v2; // rbx
        int64_t v3; // r12
        int64_t v4; // rsi

        if (a2 > 0)
        {
            v2 = 0LL;
            v3 = (a2 - 1) + 1LL;
            
            do
            {
                if ((v2 & 31) == 0)
                {
                    AppDebugOut("\n");
                }

                AppDebugOut("%02x ", *(a1 + v2++));
            } while (v2 != v3);
        }

        AppDebugOut("\n\n");
    }

    void Debug::AppDebugOutData(void *a1, int a2, int a3, signed int a4)
    {
        int64_t v5; // r14
        int64_t v6; // rbp
        int v7;     // er12
        int v8;     // er15
        int64_t v9; // rsi
        bool v11;   // [rsp+0h] [rbp-40h]

        if (a2 > 0)
        {
            v5 = (a2 - 1) + 1LL;
            v6 = 0LL;
            v7 = 0;
            
            while (true)
            {
                if ((v6 & 31) == 0)
                {
                    v8 = 0;
                    
                    AppDebugOut("\n");

                    if (a3 > 0)
                    {
                        while (a3 != ++v8);
                        {
                            AppDebugOut("    ");
                        }
                    }

                    v7 += 32;

                    if (a4 >= 0 && v7 > a4)
                    {
                        break;
                    }
                }

                AppDebugOut("%02x ", *(a1 + v6++));

                if (v6 == v5)
                {
                    AppDebugOut("\n\n");
                }
            }

            AppDebugOut("(truncated to %d bytes)\n", a4);
        }

        AppDebugOut("\n\n");
    }

    void Debug::AppDebugOutDataShort(void *a1, int a2)
    {
        char *v2;                // rbx
        char *v3;                // rbp
        unsigned int64_t result; // rax
        int64_t v5;              // rsi

        if (a2 > 0)
        {
            v2 = a1;
            v3 = a1 + (a2 - 1);

            AppDebugOut("%02x ", *a1);
            
            do
            {
                if (v2 == v3)
                {
                    break;
                }

                AppDebugOut("%02x ", *++v2);
            } while (v2 != a1 + 8);
        }
    }
*/