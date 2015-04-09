// TMP_Brown.cpp : Defines the entry point for the console application.
//


#include <type_traits>
#include <iostream>
using namespace std;
#ifdef _MSC_VER
template<class ...>
struct voider { using type = void; };
template<class ...T0toTN>
using void_t = typename voider<T0toTN ...>::type;
#else
template <class ...>
using void_t = void;
#endif
template <class, class = void>
struct has_type_member :
	false_type {};

template <class T>
struct  has_type_member<T,  void_t<typename T::type> > :
	 true_type
{
};
struct  testType
{
	using type = int;
};

struct testNoType{};

int main(int argc, char* argv[])
{
	auto hasType = has_type_member<testType>();
	auto hasnotype = has_type_member<testNoType>();
	cout << " has type =" << (bool)hasType << "; has no type = " << (bool)hasnotype << endl;
	return 0;
}

