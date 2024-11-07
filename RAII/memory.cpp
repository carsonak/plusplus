#include <iostream>
#include <vector>

/*!
 * @brief print a vector to standard output.
 * @param stream an output stream.
 * @param vec reference to the vector to print.
 */
void print_vec(std::ostream& stream, const std::vector<int>& vec)
{
	stream << "{";
	for (std::size_t i = 0; i < vec.size(); ++i)
	{
		stream << vec[i];
		if (i < vec.size() - 1) stream << ", ";
	}

	stream << "}";
}

/*!
 * @brief write a range of numbers to an int array.
 * @param array pointer to an int array.
 * @param len length of the array.
 * @param start first number in the array.
 * @param step difference between the numbers in the range.
 */
void fill_array(
	int* array, const std::size_t len, int start, const int step = 1
)
{
	for (std::size_t i = 0; i < len; i++)
	{
		array[i] = start;
		start += step;
	}
}

/*!
 * @brief print contents of an int array to an output stream.
 * @param stream an output stream.
 * @param arr an array of ints to print.
 * @param len length of the array.
 */
void print_array(std::ostream& stream, const int* arr, const std::size_t len)
{
	stream << "[";
	for (std::size_t i = 0; i < len; ++i)
	{
		stream << arr[i];
		if (i < len - 1) stream << ", ";
	}

	stream << "]";
}

/*!
 * @brief entry point.
 * @return 0 always.
 */
int main(void)
{
	constexpr std::size_t arr_len = 10;
	int* arr = new int[arr_len];

	std::cout << "Uninitialised array:\n";
	print_array(std::cout, arr, arr_len);
	fill_array(arr, arr_len, 0);
	std::cout << "\nInitialised array:\n";
	print_array(std::cout, arr, arr_len);
	std::cout << "\n";
	delete[] arr;

	std::vector<int> vec(arr_len);

	std::cout << "Uninitialised vector:\n";
	print_vec(std::cout, vec);
	vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::cout << "\nInitialised vector:\n";
	print_vec(std::cout, vec);
	std::cout << "\n";
}
