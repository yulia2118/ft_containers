/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:54:21 by fdarrin           #+#    #+#             */
/*   Updated: 2021/07/05 19:54:23 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include "vector.hpp"
#include "map.hpp"
#include "stack.hpp"
#include "utils.hpp"

void checkVector() {
	std::cout << "VECTOR" << std::endl;
	std::vector<int> standart;
	standart.push_back(1);
	standart.push_back(2);
	standart.push_back(3);
	standart.push_back(4);
	ft::vector<int> my;
	my.push_back(1);
	my.push_back(2);
	my.push_back(3);
	my.push_back(4);
	std::cout << "empty: " << std::endl;
	std::cout << "my: " << my.empty()  << " | std: " << standart.empty() <<
			  std::endl;
	std::cout << "max_size: " << std::endl;
	std::cout << "my: " << my.max_size()  << " | std: " << standart.max_size()
			  << std::endl;
	std::cout << "size: " << std::endl;
	std::cout << "my: " << my.size()  << " | std: " << standart.size() <<
			  std::endl;
	my.resize(10);
	standart.resize(10);
	std::cout << "resize: " << std::endl;
	std::cout << "my: " << my.size()  << " | std: " << standart.size() <<
			  std::endl;
	std::cout << "begin: " << std::endl;
	std::cout << "my: " << *my.begin()  << " | std: " << *standart.begin() <<
	std::endl;
	std::cout << "end: " << std::endl;
	std::cout << "my: " << *(my.end() - 1)  << " | std: " << *(standart.end()
	- 1) << std::endl;
	std::cout << "rbegin: " << std::endl;
	std::cout << "my: " << *my.rbegin()  << " | std: " << *standart.rbegin()
	<< std::endl;
	std::cout << "rend: " << std::endl;
	std::cout << "my: " << *(my.rend() - 1)  << " | std: " << *(standart.rend
	() - 1) << std::endl;
	std::cout << "capacity: " << std::endl;
	std::cout << "my: " << my.capacity()  << " | std: " << standart.capacity()
	<< std::endl;
	my.reserve(20);
	standart.reserve(20);
	std::cout << "reserve: " << std::endl;
	std::cout << "my: " << my.capacity()  << " | std: " << standart.capacity()
	<< std::endl;
	std::cout << "operator []: " << std::endl;
	std::cout << "my: " << my[1]  << " | std: " << standart[1] << std::endl;
	std::cout << "at: " << std::endl;
	std::cout << "my: " << my.at(2) << " | std: " << standart.at(2) <<
	std::endl;
	std::cout << "front: " << std::endl;
	std::cout << "my: " << my.front()  << " | std: " << standart.front() <<
	std::endl;
	std::cout << "back: " << std::endl;
	std::cout << "my: " << my.back()  << " | std: " << standart.back() <<
	std::endl;
	my.insert(my.begin(), 6);
	standart.insert(standart.begin(), 6);
	std::cout << "insert: " << std::endl;
	std::cout << "my: " << my[0]  << " | std: " << standart[0] << std::endl;
	my.erase(my.begin());
	standart.erase(standart.begin());
	std::cout << "erase: " << std::endl;
	std::cout << "my: " << my[0]  << " | std: " << standart[0] << std::endl;
	std::cout << "swap: " << std::endl;
	ft::vector<int> tmp(10, 7);
	ft::vector<int>::iterator it = tmp.begin();
	my.swap(tmp);
	std::cout << "tmp: " << tmp[1] << std::endl;
	std::cout << "my: " << my[1]<< std::endl;
	std::cout << "it tmp: " << (*(it + 1)) << std::endl;
	std::cout << "it my: " << (*(tmp.begin() + 1)) << std::endl;
	std::cout << "comparable it: " << std::endl;
	ft::vector<int>::const_iterator cit = tmp.begin() + 3;
	std::cout << "cit > it: " << ((tmp.begin() + 1) < cit) << std::endl;
	tmp.clear();
	standart.clear();
	std::cout << "clear: " << std::endl;
	std::cout << "my: " << tmp.size()  << " | std: " << standart.size() <<
	std::endl;
	std::cout << "my > tmp: " << (my > tmp) << std::endl;;
}

void checkMap() {
	std::cout << "MAP" << std::endl;
	std::map<std::string, int> standart;
	standart["one"] = 1;
	standart["two"] = 2;
	standart["three"] = 3;
	standart["four"] = 4;
	standart["five"] = 5;
	ft::map<std::string, int> my;
	my["one"] = 1;
	my["two"] = 2;
	my["three"] = 3;
	my["four"] = 4;
	my["five"] = 5;
	std::cout << "max_size: " << std::endl;
	std::cout << "my: " << my.max_size()  << " | std: " << standart.max_size()
			  << std::endl;
	std::cout << "begin: " << std::endl;
	std::cout << "my: " << (*my.begin()).first << " " << (*my.begin()).second
	<< " | std: " << (*standart.begin()).first << " " <<  (*standart.begin()).second << std::endl;
	std::cout << "end: " << std::endl;
	std::cout << "my: " << (*(--my.end())).first << " " << (*(--my.end()))
	.second  << " | std: " << (*(--standart.end())).first << " " <<  (*(--standart.end())).second << std::endl;
	std::cout << "rbegin: " << std::endl;
	std::cout << "my: " << (*my.rbegin()).first << " " << (*my.rbegin())
	.second  << " | std: " << (*standart.rbegin()).first << " " <<  (*standart.rbegin()).second << std::endl;
	std::cout << "rend: " << std::endl;
	std::cout << "my: " << (*(--my.rend())).first << " " << (*(--my.rend()))
	.second  << " | std: " << (*(--standart.rend())).first << " " <<  (*(--standart.rend())).second << std::endl;
	std::cout << "size: " << std::endl;
	std::cout << "my: " << my.size()  << " | std: " << standart.size() <<
	std::endl;
	std::cout << "insert: " << std::endl;
	my.insert(ft::pair<std::string, int >("six", 6));
	standart.insert(std::pair<std::string, int >("six", 6));
	std::cout << "my: " << my.size()  << " | std: " << standart.size() <<
	std::endl;
	std::cout << "operator []: " << std::endl;
	std::cout << "my: " << my["six"] <<  " | std: " << standart["six"] <<
	std::endl;
	std::cout << "empty: " << std::endl;
	std::cout << "my: " << my.empty() << " | std: " << standart.empty() <<
	std::endl;
	std::cout << "upper_bound: " << std::endl;
	std::cout << "my: " << (*my.upper_bound("three")).second  << " | std: " << (*standart.upper_bound("three")).second <<
	std::endl;
	std::cout << "lower_bound: " << std::endl;
	std::cout << "my: " << (*my.lower_bound("three")).second  << " | std: " << (*standart.lower_bound("three")).second <<
	std::endl;
	std::cout << "swap: " << std::endl;
	ft::map<std::string, int> tmp;
	tmp["fifteen"] = 15;
	ft::map<std::string, int>::iterator it = tmp.begin();
	my.swap(tmp);
	std::cout << "my: " << (*(it)).first << std::endl;
	std::cout << "tmp: " << (*(tmp.begin())).first << std::endl;
	my["two"] = 2;
	my.insert(ft::pair<std::string, int >("two", 2));
	std::cout << "tmp find: " << (*tmp.find("two")).second << std::endl;
	std::cout << "tmp count: " << tmp.count("two") << std::endl;
	std::cout << "clear: " << std::endl;
	tmp.clear();
	standart.clear();
	std::cout << "my: " << tmp.empty()  << " | std: " << standart.empty()
	<< std::endl;
	std::cout << "my > tmp: " << (my > tmp) << std::endl;;
}

void checkStack() {
	std::cout << "STACK" << std::endl;
	std::stack<int> standart;
	standart.push(21);
	standart.push(42);
	standart.push(7);
	standart.push(11);
	standart.push(99);
	ft::stack<int> my;
	my.push(21);
	my.push(42);
	my.push(7);
	my.push(11);
	my.push(99);
	std::cout << "top: " << std::endl;
	std::cout << "my: " << my.top()  << " | std: " << standart.top() <<
	std::endl;
	std::cout << "pop: " << std::endl;
	my.pop();
	standart.pop();
	std::cout << "my: " << my.top()  << " | std: " << standart.top() <<
	std::endl;
	std::cout << "size: " << std::endl;
	std::cout << "my: " << my.size()  << " | std: " << standart.size() <<
	std::endl;
	std::cout << "empty: " << std::endl;
	std::cout << "my: " << my.empty()  << " | std: " << standart.empty() <<
	std::endl;
}

int main() {
	checkVector();
	checkMap();
	checkStack();
	return 0;
}
