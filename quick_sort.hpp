#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

// Pedro Escoboza
// A01251531
// 07/09/2020
// TC1031.501

#include <algorithm>

namespace sort {
	
	// Sorts random access iterator range by quick sort.
	// Time complexity: O(n*log(n))
	template<typename It>
	inline void quick_sort(It begin, It end) {
		if (end <= begin) return;
		It pivot{begin};
		It middle{begin+1};

		for (It i{ begin + 1 }; i != end; ++i) {
			if (*i < *pivot) {
				std::iter_swap(i, middle);
				++middle;
			}
		}
		std::iter_swap(begin, middle-1);
		quick_sort(begin, middle-1);
		quick_sort(middle, end);
	}
}

#endif // !QUICK_SORT_HPP