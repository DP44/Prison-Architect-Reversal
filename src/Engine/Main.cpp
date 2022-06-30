#include "App.h"

void InitialiseDialogs()
{
    g_dialogManager = new DialogManager();

    if (g_preferences.field115_0x20d != false)
    {
        AttractScreen::Show();
    }
    
    g_app->ResetDialogs();
}

void AppMain()
{
    AppMainReal();
}

int main(int argc, char const *argv[])
{
    AppDebugOut("WindowManagerSDL2 :: Main\n");

    int bin_reloc_errcode;
    int bin_reloc_ret = br_init(&bin_reloc_errcode);

    if (bin_reloc_ret == 0)
    {
        printf("*** BinReloc failed to initialize. Error: %d\n", bin_reloc_errcode);
        return 1;
    }

    char *exe = br_find_exe(0);
    ChangeToProgramDir(exe);
    free(exe);
    
    // I don't know what datatype SDL_GetVersion returns, and I'm too lazy to look it up.
    int sdl_version;
    SDL_GetVersion(&sdl_version);
    
    printf("SDL Version: Compiled against %d.%d.%d, running with %d.%d.%d\n", 2, 0, 3, sdl_version);
    
    g_argv = argv;
    g_argc = argc;
    
    SDL_SetMainReady();
    
    AppMain();

    return 0;
}
