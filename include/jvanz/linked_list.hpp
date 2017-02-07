
#include <container.hpp>

namespace jvanz
{

/**
 * A simple LinkedList implementation
 */
template<typename T>
class LinkedList: public Container<T>
{
	public:
		LinkedList();
		LinkedList(const LinkedList&); // copy constructor
		LinkedList(LinkedList&&); // move constructor
		LinkedList& operator=(const LinkedList&); // copy assignment
		LinkedList& operator=(LinkedList&&); // move assignment
		~LinkedList();

		virtual std::iterator_traits<T> begin() override;
		virtual std::iterator_traits<T> end() override;
		virtual std::iterator_traits<T> cbegin() override;
		virtual std::iterator_traits<T> cend() override;
		virtual bool operator==(const LinkedList&) override;
		virtual bool operator!=(const LinkedList&) override;
		virtual void swap(unsigned int a, unsigned int b) override;
		virtual size_t size() override;
		virtual size_t max_size() override;
		virtual bool empty() override;
};

} // jvanz namespace
