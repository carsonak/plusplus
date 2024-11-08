#include <iostream>
#include <vector>

/*!
 * @brief print a vector to standard output.
 * @param stream an output stream.
 * @param vec reference to the vector to print.
 */
void print_vec(std::ostream &stream, const std::vector<int> &vec)
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
 * @brief fill an array with a sequence of numbers.
 * @param array pointer to an int array.
 * @param len length of the array.
 * @param start first number in the sequence.
 * @param gen_next pointer to a function that generates the next number in the
 * sequence.
 */
void fill_array(
	int *const array, const std::size_t len, int start,
	int (*gen_next)(const int)
)
{
	for (std::size_t i = 0; i < len; i++)
	{
		array[i] = start;
		start = gen_next(start);
	}
}

/*!
 * @brief print contents of an int array to an output stream.
 * @param stream an output stream.
 * @param arr an array of ints to print.
 * @param len length of the array.
 */
void print_array(std::ostream &stream, const int *arr, const std::size_t len)
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
	const int *p1 = new int[arr_len]{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

	std::cout << p1 << "(p1) -> ";
	print_array(std::cout, p1, arr_len);
	std::cout << "\n";

	int *p2 = new int[arr_len];

	for (std::size_t i = 0; i < arr_len; i++) p2[i] = p1[i];
	std::cout << p2 << "(p2) -> ";
	print_array(std::cout, p2, arr_len);
	std::cout << "\n";

	delete[] p1;
	delete[] p2;

	const std::vector<int> v1{1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

	std::cout << &v1 << "(v1) -> ";
	print_vec(std::cout, v1);
	std::cout << "\n";

	std::vector<int> v2(10);

	for (std::size_t i = 0; i < v1.size(); i++) v2[i] = v1[i];
	std::cout << &v2 << "(v2) -> ";
	print_vec(std::cout, v2);
	std::cout << "\n";
	return (0);
}
