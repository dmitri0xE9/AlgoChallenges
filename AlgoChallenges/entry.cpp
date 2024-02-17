#include <Windows.h>
#include <iostream>

// @task: You are given an array of integers. Implement a function that takes
// this array as input and returns the sum of all elements.

#include <string>
#include <unordered_map>
#include <vector>

int sum_of_array( const std::vector<int>& arr )
{
	int sum{};
	for( const int num : arr )
	{
		sum += num;
	}

	return sum;
}

// @task: Write a C++ function that sorts an array of integers using the bubble sort method.
// Your function should take the size of the array and the array elements, and then print the sorted array

std::vector<int> sort_fn( size_t array_size, std::vector<int>& array_el )
{
	for( size_t i = 0; i < array_size; ++i )
	{
		for( size_t j = 0; j + 1 < array_size - i; ++j )
		{

			if( array_el[ j + 1 ] < array_el[ j ] )
				std::swap( array_el[ j ], array_el[ j + 1 ] );

		}
	}

	return array_el;
}

// @task: Given an integer x, return true if x is a palindrome, and false otherwise.

class Solution9 {
public:
	bool isPalindrome( int x ) {
		auto to_str = std::to_string( x );
		std::reverse( to_str.begin(), to_str.end() );

		printf( "\nx is: %s\n", to_str.c_str() );

		const auto res = strstr( std::to_string( x ).c_str( ), to_str.c_str( ) );
		if( res != nullptr )
			return true;

		return false;
	}

};

// @task: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

class Solution1 {
public:
	std::vector<int> twoSum( std::vector<int>& nums, int target ) {
		std::vector<int> temp_vec{};

		

		for( int i = 0; i < nums.size() - 1; i++ )
		{
			for( int j = i + 1; j < nums.size(); j++ )
			{
				if( nums[i ] + nums[j ] == target )
				{
					temp_vec.push_back( i );
					temp_vec.push_back( j );
				}
			}
		}

		return temp_vec;
	}
};

// @task: Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

class Solution13 {
public:
	int romanToInt( std::string s ) {
		std::unordered_map<char, int> romanMap = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000}
		};

		int result = 0;
		int n = s.length( );
		for( int i = 0; i < n; ++i ) {
			if( i < n - 1 && romanMap[ s[ i ] ] < romanMap[ s[ i + 1 ] ] ) {
				result -= romanMap[ s[ i ] ];
			}
			else {
				result += romanMap[ s[ i ] ];
			}
		}
		return result;
	}
};

int main( )
{
	// task 1
	const std::vector<int> arr = { 1, 2, 3, 4, 5  };
	const auto res = sum_of_array( arr );
	printf( "sum is: %d\n", res );

	// task 2
	std::vector<int> sort_array = {3, 38, 5, 44, 15, 36, 26, 27, 2, 44, 4, 19, 46, 47, 48, 50};
	const auto sorted_array = sort_fn( sort_array.size( ) , sort_array );

	for(const int val : sorted_array )
	{
		printf( "%d", val );
	}

	// task 3
	Solution9 sl_9{};
	const bool result = sl_9.isPalindrome( 121 );
	if( result )
		printf( "this val is palindrome\n" );


	Solution1 sl_1{};
	std::vector<int> two_sum = { 2,7,11,15 };
	auto two_sum_arr = sl_1.twoSum( two_sum, 9 );

	for( const int cur_val : two_sum_arr )
	{
		printf( "%d\n", cur_val );
	}

	Solution13 sl_13{};
	auto roman = sl_13.romanToInt( "III" );
	printf( "roman: %d\n", roman );
}