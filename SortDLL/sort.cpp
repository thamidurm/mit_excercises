#include "pch.h"
#include "sort.h"
#include <iostream>

void bubbleSort(std::vector<int>& toSort)
{
	for (size_t i = 0; i < toSort.size() - 1; ++i)
	{
		for (size_t j = 0; j < toSort.size() - i - 1; ++j)
		{
			if (toSort[j] > toSort[j + 1])
			{
				int temp = toSort[j];
				toSort[j] = toSort[i];
				toSort[i] = temp;
			}
		}
	}
}

int partition(std::vector<int>& toSort, int low, int high)
{
	int pivot = toSort[high];
	int i = low - 1;

	for (int j = low; j <= high; ++j)
	{
		if (toSort[j] < pivot)
		{
			++i;
			int temp = toSort[i];
			toSort[i] = toSort[j];
			toSort[j] = temp;
		}
	}
	int temp = toSort[i + 1];
	toSort[i + 1] = toSort[high];
	toSort[high] = temp;
	return i + 1;
}

void quickSortHelper(std::vector<int>& toSort, int low, int high)
{
	if (low < high)
	{
		int pi = partition(toSort, low, high);
		quickSortHelper(toSort, low, pi - 1);
		quickSortHelper(toSort, pi + 1, high);
	}
}

void quickSort(std::vector<int>& toSort)
{
	quickSortHelper(toSort, 0, toSort.size() - 1);
}