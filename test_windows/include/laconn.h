#ifndef LACONN
#define LACONN

// Building DLL - LA_EXPORT_DLL
// Calling DLL - LA_IMPORT_DLL
// Otherwise static library

#if defined(LA_EXPORT_DLL)
#define LA_DLL __declspec(dllexport)
#elif defined(LA_IMPORT_DLL)
#define LA_DLL __declspec(dllimport)
#else
#define LA_DLL
#endif

LA_DLL void laconnect(char *);

#endif
