#ifndef ALGORITH_HPP
#define ALGORITHM_HPP

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

	template <typename It, typename K>
	inline It binary_search(It begin, It end, const K& key) {
		if (begin > end) {
			It middle{begin + (end-1)/2};

			if (*middle == key) return middle;

			if(key < *middle)
				return binary_search(begin, middle, key);

			return binary_search(middle, begin, key);
		}
		return end;
	}
}

#endif // !QUICK_SORT_HPP