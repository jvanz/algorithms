
#include <iterator>

namespace jvanz
{

/**
 * An abstract class representing the Container C++ concept
 */
template<typename T>
class Container
{
	public:
		~Container() = 0; // destructor

		virtual std::iterator_traits<T> begin() = 0;
		virtual std::iterator_traits<T> end() = 0;
		virtual std::iterator_traits<T> cbegin() = 0;
		virtual std::iterator_traits<T> cend() = 0;
		virtual bool operator==(const Container&) = 0;
		virtual bool operator!=(const Container&) = 0;
		virtual void swap(unsigned int a, unsigned int b) = 0;
		virtual size_t size() = 0;
		virtual size_t max_size() = 0;
		virtual bool empty() = 0;



};

} // jvanz namespace
