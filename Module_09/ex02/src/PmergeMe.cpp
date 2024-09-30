/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:17:36 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/30 14:42:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Prev function overload to use it for C++98
template <typename BidirectionalIterator> BidirectionalIterator prev(BidirectionalIterator it,
	typename std::iterator_traits<BidirectionalIterator>::difference_type n = 1)
{
	std::advance(it, -n);
	return (it);
}

// Default constructor
PmergeMe::PmergeMe()
{
}

// Parametrized constructor
PmergeMe::PmergeMe(const std::vector<int> &numbers)
{
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++)
	{
		_listNumbers.push_back(*it);
		_vectorNumbers.push_back(*it);
	}
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe &other)
{
	*this = other;
}

// Assignment operator overload
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		_vectorNumbers = other._vectorNumbers;
		_listNumbers = other._listNumbers;
	}
	return (*this);
}

// Destructor
PmergeMe::~PmergeMe()
{
}

/**
 * @brief               Function that merges two vectors.
 *                      It takes three parameters: left, middle and right
 *                      and merges the two vectors.
 *                      It works in the following way:
 *                      1. Creates two vectors leftVector and rightVector
 *                      2. Fills leftVector with elements from left to middle
 *                      3. Fills rightVector with elements from middle
	+ 1 to right
 *                      (middle
	+ 1 because middle is already included in leftVector)

	*                      4. Merges the two vectors into the original vector _vectorNumbers
 * @param left          The left number of the vector
 * @param middle        The middle number of the vector
 * @param right         The right number of the vector
 */
void PmergeMe::vector_merge(num left, num middle, num right)
{
	num	sizeLeftVector;
	num	sizeRightVector;
	num	i = 0, j = 0, k;

	sizeLeftVector = middle - left + 1;
	sizeRightVector = right - middle;
	std::vector<int> leftVector;
	std::vector<int> rightVector;
	for (num i = 0; i < sizeLeftVector; i++)
	{
		leftVector.push_back(_vectorNumbers[left + i]);
	}
	for (num j = 0; j < sizeRightVector; j++)
	{
		rightVector.push_back(_vectorNumbers[middle + 1 + j]);
	}
	i = 0, j = 0, k = left;                             // index of leftVector, rightVector and _vectorNumbers
	while (i < sizeLeftVector && j < sizeRightVector)
	{ // merge
		if (leftVector[i] <= rightVector[j])
		{
			_vectorNumbers[k] = leftVector[i];
			i++;
		}
		else
		{
			_vectorNumbers[k] = rightVector[j];
			j++;
		}
		k++;
	}
	while (i < sizeLeftVector)
	{ // if leftVector is bigger
		_vectorNumbers[k] = leftVector[i];
		i++;
		k++;
	}
	while (j < sizeRightVector)                         // if rightVector is bigger     
	{ 
		_vectorNumbers[k] = rightVector[j];
		j++;
		k++;
	}
}

/**
 * @brief           Function that sorts the vector _vectorNumbers.
 *                  It works in the following way:
 *                  1. If the size of the vector is less than
 *                  or equal to THRESHOLD (5 in our case, see subject),
 *                  it uses the insert sort algorithm
 *                  that sorts the vector in ascending order.
 *                  2. If the size of the vector is bigger than THRESHOLD,
 *                  it uses the merge sort algorithm that sorts the vector
 *                  in ascending order also, but in a more efficient way
 *                  taking into account the size of the vector.
 * @param left      The left number of the vector
 * @param right     The right number of the vector
 */
void PmergeMe::vector_mergeSort(num left, num right)
{
	num	middle;

	if (left < right)
	{
		middle = (left + right) / 2;
		vector_mergeSort(left, middle);
		vector_mergeSort(middle + 1, right);
		vector_merge(left, middle, right);
	}
}

/**
 * @brief           Sorts the vector of numbers using
 *                  a hybrid sorting algorithm and measures
 *                  the time taken to perform the sorting operation.
 *                  It uses the getTimestamp() function to get the
 *                  current time in microseconds.
 * @return long     The time taken to sort the vector in milliseconds.
 * @see             getTimestamp()
 */
long PmergeMe::sortVector()
{
	long	start;
	num		j;
	num		left;
	num		right;
	long	end;

	start = getTimestamp();
	// up to 5 elements, use insert sort
	if (_vectorNumbers.size() <= THRESHOLD)
	{
		for (num i = 1; i < _vectorNumbers.size(); i++)
		{
			j = i;
			while (j > 0 && _vectorNumbers[j - 1] > _vectorNumbers[j])
			{
				std::swap(_vectorNumbers[j - 1], _vectorNumbers[j]);
				j--;
			}
		}
	}
	// more than 5 elements, use merge sort
	else
	{
		left = 0;
		right = _vectorNumbers.size() - 1;
		vector_mergeSort(left, right);
	}
	end = getTimestamp();
	return (end - start);
}

/**
 * @brief               Function that merges two lists.
 *                      It takes three parameters: left, middle and right
 *                      and merges the two lists.
 *                      It works in the following way:
 *                      1. Creates two lists leftList and rightList
 *                      2. Fills leftList with elements from left to middle
 *                      3. Fills rightList with elements from middle + 1 to right
 *                      (middle + 1 because middle is already included in leftList)
 *                      4. Merges the two lists into the original list _listNumbers
 * @param left          The left number of the list
 * @param middle        The number in the middle of the list
 * @param right         The right number of the list
 */
void PmergeMe::list_merge(num left, num middle, num right)
{
	num	sizeLeftList;
	num	sizeRightList;

	sizeLeftList = middle - left + 1;
	sizeRightList = right - middle;
	std::list<int> leftList;
	std::list<int> rightList;
	for (num i = 0; i < sizeLeftList; i++)
	{
		std::list<int>::iterator it = _listNumbers.begin();
		std::advance(it, left + i);
		leftList.push_back(*it);
	}
	for (num j = 0; j < sizeRightList; j++)
	{
		std::list<int>::iterator it = _listNumbers.begin();
		std::advance(it, middle + 1 + j);
		rightList.push_back(*it);
	}
	std::list<int>::iterator itLeft = leftList.begin();
	std::list<int>::iterator itRight = rightList.begin();
	std::list<int>::iterator it = _listNumbers.begin();
	std::advance(it, left);
	while (itLeft != leftList.end() && itRight != rightList.end())
	{
		if (*itLeft <= *itRight)
		{
			*it = *itLeft;
			itLeft++;
		}
		else
		{
			*it = *itRight;
			itRight++;
		}
		it++;
	}
	while (itLeft != leftList.end())
	{
		*it = *itLeft;
		itLeft++;
		it++;
	}
	while (itRight != rightList.end())
	{
		*it = *itRight;
		itRight++;
		it++;
	}
}

/**
 * @brief               This function implements the merge sort algorithm.
 *                      It recursively divides the list into two halves,
 *                      sorts each half, and then merges them back together.
 *
 * @param left          The left number of the list
 * @param right         The right number of the list
 */
void PmergeMe::list_mergeSort(num left, num right)
{
	num	middle;

	if (left < right)
	{
		middle = (left + right) / 2;
		list_mergeSort(left, middle);
		list_mergeSort(middle + 1, right);
		list_merge(left, middle, right);
	}
}

/**
 * @brief                   Function is designed to sort a list
 *                          of integers stored in the _listNumbers
 *                          member variable of the PmergeMe class.
 *
 * @return long             The time taken to sort the list in microseconds.
 */
long PmergeMe::sortList()
{
	long	start;
	num		left;
	num		right;
	long	end;

	start = getTimestamp();
	if (_listNumbers.size() <= THRESHOLD)
	{
		// up to 5 elements, use insert sort
		for (std::list<int>::iterator it = _listNumbers.begin(); it != _listNumbers.end(); it++)
		{
			std::list<int>::iterator it2 = it;
			while (it2 != _listNumbers.begin() && *::prev(it2) > *it2)
			{ // if prev is bigger
				std::swap(*::prev(it2), *it2);
				it2--;
			}
		}
	}
	else
	{
		// more than 5 elements, use merge sort
		left = 0;
		right = _listNumbers.size() - 1;
		list_mergeSort(left, right);
	}
	end = getTimestamp();
	return (end - start);
}

/**
 * @brief           This function prints the vector of numbers
 *                  stored in the _vectorNumbers member variable
 *                  using an iterator stored in the `it` variable.
 */
void PmergeMe::printVector()
{
	for (std::vector<int>::const_iterator it = _vectorNumbers.begin(); it != _vectorNumbers.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/**
 * @brief           Function to print the list of numbers
 *                  stored in the _listNumbers member variable.
 *                  Used to print `Before` and `After` states of the list.
 * 
 */
void PmergeMe::printList()
{
	for (std::list<int>::const_iterator it = _listNumbers.begin(); it != _listNumbers.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

/**
 * @brief           This function returns the current timestamp
 *                  in microseconds. It uses the gettimeofday function
 *                  to get the current time and converts it to microseconds.
 *
 * @return long     The current timestamp in microseconds.
 */
long PmergeMe::getTimestamp() const
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	long secondsInMicroseconds = tv.tv_sec * 1000000;
	long totalMicroseconds = secondsInMicroseconds + tv.tv_usec;
	return (totalMicroseconds);
}
