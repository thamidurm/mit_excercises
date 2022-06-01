#pragma once

#include <vector>

#ifdef SORTLIBRARY_EXPORTS
#define SORTLIBRARY_API __declspec(dllexport)
#else
#define SORTLIBRARY_API __declspec(dllimport)
#endif


extern "C" SORTLIBRARY_API void bubbleSort(std::vector<int>&toSort);
extern "C" SORTLIBRARY_API void quickSort(std::vector<int>& toSort);