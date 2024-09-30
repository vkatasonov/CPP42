/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:17:25 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/30 14:46:16 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<int> argsParseAndCheck(int argc, char **argv) {
  std::vector<int> numbers;
  try {
    for (int i = 1; i < argc; i++) {
      std::stringstream ss(argv[i]);
      long number;
      while (ss >> number) {
        if (ss.fail() || number < 0 || number > INT_MAX) {
          throw std::invalid_argument("Invalid argument");
        }
        numbers.push_back(number);
      }
    }
  } catch (std::exception &e) {
    std::cout << RED <<"Error: " << e.what() << RST << std::endl;
    exit(EXIT_FAILURE);
  }
  return numbers;
}

int main(int argc, char **argv) {
  if (argc == 1) {
    std::cout << RED << "Error: Invalid number of arguments." << RST << std::endl;
    std::cout << YELLOW << "Usage: ./PmergeMe <num1 num2 num3 etc.>" << RST<< std::endl;
    return EXIT_FAILURE;
  }

  {
    std::vector<int> numbers = argsParseAndCheck(argc, argv);
    PmergeMe pmergeMe(numbers);

    std::cout << BLUE << "Before: " << RST;
    pmergeMe.printVector();

    long duration = pmergeMe.sortVector();

    std::cout << BLUE << "After:  " << RST;
    pmergeMe.printVector();

    std::cout << BLUE << "Time to process range of " << numbers.size()
              << " elements with std::vector: " << RST << YELLOW << duration << " μs"
              << RST << std::endl;

    duration = pmergeMe.sortList();

    std::cout << BLUE << "Time to process range of " << numbers.size()
              << " elements with std::list: " << RST << YELLOW <<duration << " μs"
              << RST << std::endl;
  }

  return EXIT_SUCCESS;
}
