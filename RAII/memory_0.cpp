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
        if (i < vec.size() - 1)
            stream << ", ";
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
void fill_array(int *const array, const std::size_t len, int start,
                int (*gen_next)(const int))
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
        if (i < len - 1)
            stream << ", ";
    }

    stream << "]";
}

/*!
 * @brief entry point.
 * @return 0 always.
 */
int main(void)
{
    for (std::size_t arr_len = 5; arr_len <= 30; arr_len += 5)
    {
        int *arr = new int[arr_len];

        std::cout << "Len: " << arr_len << " ";
        print_array(std::cout, arr, arr_len);
        std::cout << "\n";
        fill_array(arr, arr_len, 100, [](const int x) -> int { return x + 1; });
        print_array(std::cout, arr, arr_len);
        std::cout << "\n\n";
        delete[] arr;
    }

    constexpr std::size_t arr_len = 10;
    std::vector<int> vec(arr_len);

    std::cout << "Uninitialised vector:\n";
    print_vec(std::cout, vec);
    vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "\nInitialised vector:\n";
    print_vec(std::cout, vec);
    std::cout << "\n";
}
