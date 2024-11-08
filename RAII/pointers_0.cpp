#include <iostream>

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
	int *p1 = new int(7);

	std::cout << p1 << "(p1) -> " << *p1 << "\n";

	constexpr std::size_t arr_len = 7;
	int *p2 = new int[arr_len];

	fill_array(p2, arr_len, 1, [](const int x) { return x * 2; });
	std::cout << p2 << "(p2) -> ";
	print_array(std::cout, p2, arr_len);
	std::cout << "\n";

	int *p3 = p2;

	std::cout << p3 << "(p3) -> " << *p3 << "\n";
	p2 = p1;
	p2 = p3;
	std::cout << p1 << "(p1) -> " << *p1 << "\n";
	std::cout << p2 << "(p2) -> ";
	print_array(std::cout, p2, arr_len);
	std::cout << "\n";

	delete p1;
	delete[] p2;

	return (0);
}
