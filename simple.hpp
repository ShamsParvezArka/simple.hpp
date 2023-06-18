/*
 * simple.hpp
 * 
 * Copyright 2023 Shams Parvez Arka <parvez6826@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#ifndef SIMPLE_HPP_
#define SIMPLE_HPP_ 1

// standard libraries
#include <iostream>
#include <vector>
#include <random>
#include <array>
#include <map>
#include <list>
#include <unordered_map>
#include <type_traits>

#define UNUSED __attribute__((unused)) auto

namespace simple {
	namespace numbers {
		float randf(float min, float max);
	}

	std::vector<std::string> split(std::string raw, std::string delimiter);

	namespace pprint {
		template<typename T, typename A>
		void vector(std::vector<T> const& container);

		template<typename T, size_t A>
		void array(std::array<T, A> const& container);

		template<typename K, typename V>
		void map(std::map<K, V> const& container);

		template<typename K, typename V>
		void hash_map(std::unordered_map<K, V> const& container);

		template<typename T>
		void list(std::list<T> const& container);
	}
}

#ifndef SIMPLE_IMPLEMENTATION_
namespace simple {
	namespace numbers {
		float randf(float min, float max) {
			std::random_device random_device;
			std::mt19937 random_engine{random_device()};
			std::uniform_real_distribution<float> distribution(min, max);

			return distribution(random_engine);
		}
	}

	std::vector<std::string> split(std::string raw, std::string const& delimiter) {
		std::vector<std::string> vec {};

		std::string token;
		size_t pos = 0;

		while ((pos = raw.find(delimiter)) != std::string::npos) {
			token = raw.substr(0, pos);
			vec.push_back(token);
			raw.erase(0, pos + delimiter.length());
		}
		vec.push_back(raw);

		return vec;
	}

	namespace pprint {
		template<typename T>
		void vector(std::vector<T> const& container) {
			std::cout << "Container: Vector\n";
			for (auto i = container.begin(); i < container.end(); i++) {
				if (i == container.begin())
					std::cout << "[";
				if (i == std::prev(container.end()))
					std::cout << *i << "]\n";
				else
					std::cout << *i << ", ";
			}
		}

		template<typename T, size_t A>
		void array(std::array<T, A> const& container) {
			std::cout << "Container: Standard Array\n";
			for (auto i = container.begin(); i < container.end(); i++) {
				if (i == container.begin())
					std::cout << "[";
				if (i == std::prev(container.end()))
					std::cout << *i << "]\n";
				else
					std::cout << *i << ", ";
			}
		}

		template<typename K, typename V>
		void map(std::map<K, V> const& container) {
			std::cout << "Container: Hash Map\n[\n";
			for (auto const& i: container) {
				std::cout << "  [" << i.first << ", " << i.second << "],\n";
			}
			std::cout << "]\n";
		}

		template<typename K, typename V>
		void unordered_map(std::unordered_map<K, V> const& container) {
			std::cout << "Container: Hash Map\n[\n";
			for (auto const& i: container) {
				std::cout << "  [" << i.first << ", " << i.second << "],\n";
			}
			std::cout << "]\n";
		}

		template <typename T>
		void list(std::list<T> const& container) {
			std::cout << "Container: List\n";
			for (auto i = container.begin(); i != container.end(); i++) {
				if (i == container.begin())
					std::cout << "[";
				if (i == std::prev(container.end()))
					std::cout << *i << "]\n";
				else
					std::cout << *i << ", ";
			}
		}
	}
}
#endif //SIMPLE_IMPLEMENTSTION_

#endif //SIMPLE_HPP_
