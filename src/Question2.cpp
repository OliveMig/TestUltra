#include "Question2.h"
#include <algorithm>

bool Question2::discard_elements_above(uint32_t T, const std::vector<uint32_t>& I, std::vector<uint32_t>& elementsBelowT)
{
	for (size_t iElement = 0, elementsCount = I.size(); iElement < elementsCount; ++iElement)
	{
		uint32_t element = I[iElement];
		if (element < T)
			elementsBelowT.emplace_back(element);
		else if (element == T) // target value has been found
			return true;
	}
	return false;
}

bool Question2::split_elements(uint32_t T, const std::vector<uint32_t>& elements, std::vector<uint32_t>& elementsBelowTOver2, std::vector<uint32_t>& elementsAboveTOver2)
{
	bool isTEven = T%2 == 0;
	uint32_t pivotal = T/2;
	bool hasFoundPivotal = false;
	for (size_t iElement = 0, elementsCount = elements.size(); iElement < elementsCount; ++iElement)
	{
		uint32_t element = elements[iElement];
		if (isTEven && element == pivotal)
		{
			if (hasFoundPivotal) // two pivotal values have been found, the target has been reached
			{
				return true;
			}
			else
			{
				hasFoundPivotal = true;
			}
		}
		if (element > pivotal)
			elementsAboveTOver2.emplace_back(element);
		else
			elementsBelowTOver2.emplace_back(element);
	}
	return false;
}

void Question2::find_largest_sum_elements_below(uint32_t T, const std::vector<uint32_t> &I, std::vector<uint32_t> &M, uint32_t &S)
{
	std::vector<uint32_t> copyElementsBelowTOver2 = I;
	std::sort(copyElementsBelowTOver2.begin(), copyElementsBelowTOver2.end());
	for (int elementsCountBelow = copyElementsBelowTOver2.size(), iElementBelow = elementsCountBelow - 1; iElementBelow >= 0; --iElementBelow)
	{
		copyElementsBelowTOver2.pop_back();
		uint32_t elementBelow = copyElementsBelowTOver2[iElementBelow];
		uint32_t currentSum = 0;
		std::vector<uint32_t> currentSumElements;
		find_largest_sum(T - elementBelow, copyElementsBelowTOver2, currentSumElements, currentSum);
		currentSum += elementBelow;
		currentSumElements.emplace_back(elementBelow);
		if (currentSum > S)
		{
			S = currentSum;
			M = std::move(currentSumElements);
		}
		if (currentSum == T)
		{
			return;
		}
	}
}

void Question2::find_largest_sum(uint32_t T, const std::vector<uint32_t>& I, std::vector<uint32_t>& M, uint32_t& S)
{
	std::vector<uint32_t> elementsBelowT;
	std::vector<uint32_t> elementsBelowTOver2;
	std::vector<uint32_t> elementsAboveTOver2;
	if (I.empty()) // no elements
	{
		S = 0;
	}
	else if (discard_elements_above(T, I, elementsBelowT)) // if target is found, target is reached
	{
		S = T;
		M.emplace_back(T);
	}
	else if (split_elements(T, elementsBelowT, elementsBelowTOver2, elementsAboveTOver2)) // if target is even and half is found twice, target is reached
	{
		S = T;
		M.emplace_back(T/2);
		M.emplace_back(T/2);
	}
	else if (elementsBelowTOver2.empty()) // if no element below half of the target, then the sum of any element with each other is above the target, so we take the max
	{
		auto maxElement = std::max_element(elementsAboveTOver2.begin(), elementsAboveTOver2.end());
		if (maxElement != elementsAboveTOver2.end())
		{
			S = *maxElement;
			M.emplace_back(S);
		}
	}
	else if (elementsAboveTOver2.empty()) // if no element 
	{
		find_largest_sum_elements_below(T, elementsBelowTOver2, M, S);
	}
	else
	{
		std::sort(elementsAboveTOver2.begin(), elementsAboveTOver2.end());
		for (int elementsCountAbove = elementsAboveTOver2.size(), iElementAbove = elementsCountAbove - 1; iElementAbove >= 0; --iElementAbove)
		{
			uint32_t elementAbove = elementsAboveTOver2[iElementAbove];
			uint32_t currentSum = 0;
			std::vector<uint32_t> currentSumElements;
			find_largest_sum(T - elementAbove, elementsBelowTOver2, currentSumElements, currentSum);
			currentSum += elementAbove;
			currentSumElements.emplace_back(elementAbove);
			if (currentSum > S)
			{
				S = currentSum;
				M = std::move(currentSumElements);
			}
			if (currentSum == T)
			{
				return;
			}
		}
		{
			uint32_t currentSum = 0;
			std::vector<uint32_t> currentSumElements;
			find_largest_sum_elements_below(T, elementsBelowTOver2, currentSumElements, currentSum);
			if (currentSum > S)
			{
				S = currentSum;
				M = std::move(currentSumElements);
			}
		}
	}
}
