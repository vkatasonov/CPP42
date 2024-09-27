/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkatason <vkatason@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 10:37:40 by vkatason          #+#    #+#             */
/*   Updated: 2024/09/27 13:11:57 by vkatason         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/**
 * @brief           Function to check if the date is valid
 *  
 * @param date      String with date in YYYY-MM-DD format
 * @return true     If the date is valid
 * @return false    If the date is invalid
 */
static bool isValidDate(const std::string &date) {
  if (date.size() != 11) {
    return false;
  }
  if (date[4] != '-' || date[7] != '-') {
    return false;
  }
  // Check if number in dates are digits
  for (int i = 0; i < 11; i++) {
    if (i == 4 || i == 7 || i == 10) {
      continue;
    }
    if (!isdigit(date[i])) {
      return false;
    }
  }
  return true;
}


/**
 * @brief           Function to check if the double is valid.
 *                  According to subject a valid value must be either 
 *                  a float or a positive integer, between 0 and 1000.
 * 
 * @param value     String with double value
 */
static void isValidDouble(const std::string &value) {
  int dotCount = 0;

  for (std::size_t i = 0; i < value.size(); i++) {
    if (value[i] == '.' && dotCount == 0) {
      dotCount++;
      continue;
    }
    if (!isdigit(value[i]) && value[0] != '-') {
      throw std::runtime_error(RED "Error: + bad input => " RST + value);
    }
  }

  double ret = strToDouble(value);
  if (ret < 0) {
    throw std::runtime_error(RED "Error: not a positive number." RST);
  } else if (ret > 1000) {
    throw std::runtime_error(RED "Error: too large as number." RST);
  }
}

int main(int argc, char **argv) {
  if (argc == 2) {
    try {
      BitcoinExchange btcExchange;
      std::ifstream file(argv[1]);

      // Check if the file is open
      if (!file.is_open()) {
        std::cerr << RED << "Input file not found" << RST << std::endl;
        return EXIT_FAILURE;
      }
      // Checks if the first line is valid
      {
        std::string line;
        std::getline(file, line);
        if (line != "date | value") {
          std::cerr << RED << "Invalid input file format" << RST << std::endl;
          return EXIT_FAILURE;
        }
      }
      // Iterate over the file calculating the new value and printing it
      {
        std::string line;
        while (getline(file, line)) {
          std::stringstream ss(line);
          std::string date, value;
          std::getline(ss, date, '|');
          if (isValidDate(date) == false) {
            std::cout << RED << "Error: bad input => " << RST << date << std::endl;
            continue;
          }
          date.erase(date.size() - 1);
          std::getline(ss, value, '|');
          value.erase(0, 1);
          try {
            isValidDouble(value);  // throw if invalid
          } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            continue;
          }
          double newValue =
              btcExchange.getExchangeRate(date) * strToDouble(value);
          std::cout << date << " => " << value << " = " << newValue
                    << std::endl;
        }
      }
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }
  std::cerr << YELLOW << "Usage: ./btc <input_file>" << RST << std::endl;
  return EXIT_FAILURE;
}
