/**
 * @file
 * @brief A program to check if a number is an [Armstrong](https://en.wikipedia.org/wiki/Narcissistic_number)
 *        or Narcissistic number in the decimal system.
 *
 * @details
 * An Armstrong (or Narcissistic) number is a number that is the sum of its own digits, 
 * each raised to the power of the number of digits in the number.
 * 
 * Example:
 * - For the number 153: 1^3 + 5^3 + 3^3 = 153, so 153 is an Armstrong number.
 * 
 * The formula for an Armstrong number is:
 * \f[F_b(n) = \sum_{i=0}^{k-1}d_i^k\f] 
 * where:
 * - \( k \) is the number of digits in the number \( n \),
 * - \( d_i \) is the ith digit of the number \( n \).
 *
 * @author [Neeraj Cherkara](https://github.com/iamnambiar)
 */

#include <cassert>   ///< for the assert function to verify test results
#include <cmath>     ///< for mathematical functions like std::pow
#include <iostream>  ///< for input/output operations

/**
 * @brief Function to calculate the number of digits in a number.
 *
 * @param num The number whose digits will be counted.
 * @return The total number of digits in the number.
 */
int number_of_digits(int num) {
    int digit_count = 0;
    
    // Count digits by dividing the number by 10 in each iteration
    while (num > 0) {
        num /= 10;
        ++digit_count;
    }
    return digit_count;
}

/**
 * @brief Function to check if a number is an Armstrong number.
 *
 * An Armstrong number is a number that is equal to the sum of its own digits, each raised to the power 
 * of the number of digits in the number.
 *
 * @param number The number to check.
 * @return `true` if the number is an Armstrong number, `false` otherwise.
 */
bool is_armstrong(int number) {
    // Edge case: Negative numbers can't be Armstrong numbers
    if (number < 0) {
        return false;
    }

    int sum = 0;
    int temp = number;
    
    // Calculate the number of digits in the number
    int num_digits = number_of_digits(number);

    // Process each digit in the number
    while (temp > 0) {
        int digit = temp % 10; // Extract the last digit
        // Add the digit raised to the power of the total digits
        sum += static_cast<int>(std::pow(digit, num_digits));
        temp /= 10; // Remove the last digit
    }

    // Return true if the sum of powered digits equals the original number
    return number == sum;
}

/**
 * @brief Run tests to validate the functionality of the Armstrong number check.
 *
 * This function runs a series of tests to verify the correctness of the `is_armstrong` function.
 * It uses assertions to ensure the expected results are returned for different test cases.
 *
 * @returns void
 */
static void run_tests() {
    // Test cases for Armstrong numbers
    assert(is_armstrong(370) == true);  ///< 370 is an Armstrong number
    assert(is_armstrong(153) == true);  ///< 153 is an Armstrong number
    assert(is_armstrong(0) == true);    ///< 0 is an Armstrong number
    assert(is_armstrong(-23) == false);///< Negative numbers are not Armstrong numbers
    assert(is_armstrong(225) == false);///< 225 is not an Armstrong number
    assert(is_armstrong(12) == false); ///< 12 is not an Armstrong number

    std::cout << "All tests passed successfully!\n";
}

/**
 * @brief Main function to run the Armstrong number test.
 *
 * The main function initiates the testing process and exits once all tests pass.
 *
 * @returns 0 on successful execution.
 */
int main() {
    run_tests();  ///< Execute the self-tests to validate the algorithm
    return 0;
}
