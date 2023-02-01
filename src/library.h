#ifndef ASTONIAMOD_LIBRARY_H
#define ASTONIAMOD_LIBRARY_H

#if defined(_WIN32) || defined(__WIN32__)
#  if defined(AstoniaMod_EXPORTS) // add by CMake
#    define  AstoniaMod_EXPORT extern "C" __declspec(dllexport)
#    define AstoniaMod_IMPORT extern "C" __declspec(dllimport)
#  else
#    define  AstoniaMod_EXPORT extern "C" __declspec(dllimport)
#  endif // AstoniaMod_EXPORTS
#elif defined(linux) || defined(__linux)
# define AstoniaMod_EXPORT
#endif

void hello();
AstoniaMod_EXPORT void amod_gamestart(void);

#endif //ASTONIAMOD_LIBRARY_H
