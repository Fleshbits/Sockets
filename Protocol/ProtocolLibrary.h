#pragma once

//--------------------------------------------------------------------------------------------------
#ifdef PROTOCOL_LIBRARY_EXPORTS
#define PROTOCOL_API __declspec(dllexport)
#else
#define PROTOCOL_API __declspec(dllimport)
// Specify the import library to link in for the DLL.
#pragma comment(lib, "Protocol.lib")
#endif

#pragma once
