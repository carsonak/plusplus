#include "vector.h"

/*!
 * @brief tests.
 * @param
 * @return always 0.
 */
int main(void) {
  std::string a{"Eeh Mungu nguvu yetu,"};

  std::cout << a << "\nLength: " << a.length() << " Size: " << sizeof(a)
            << "\n\n";

  a += "\niilete baraka kwetu,";

  std::cout << a << "\nLength: " << a.length() << " Size: " << sizeof(a)
            << '\n';
  return (0);
}
