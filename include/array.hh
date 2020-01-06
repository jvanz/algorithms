#include <algorithm>
#include <vector>

namespace jvanz {
namespace array {

/**
 * Function to rotate the element within vector to left d times
 */
template <typename T>
std::vector<T> rotate_left(std::vector<T> a, size_t d) {
	if (d < 1)
		throw "Invalid rotate number";
	while (d--) {
		a.push_back(a.front());
		a.erase(a.begin());
	}
	return a;
}

}  // namespace array
}  // namespace jvanz
