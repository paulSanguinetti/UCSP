#define min2(a, b) ( (a < b)? a : b )

#include <iostream>

template <typename T>
T min(T a, T b) {
	return ((a < b)? a : b);
}

int main()
{
	std::cout << min2('s','f') << "\n";
	std::cout << min<char>('i','p') << "\n";
	return 0;
}