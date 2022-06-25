/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:53:02 by fdarrin           #+#    #+#             */
/*   Updated: 2021/07/05 19:53:04 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include "vector.hpp"

namespace ft {

	template <class T, class Container = ft::vector<T> >
	class stack {

	public:
		typedef T value_type;
		typedef Container container_type;
		typedef size_t size_type;

	protected:
		container_type _c;

	public:
		explicit stack(const Container& c = Container()) {
			_c = c;
		}

		bool empty() const {
			return _c.empty();
		}

		size_type size() {
			return _c.size();
		}

		value_type& top() {
			return _c.back();
		}

		const value_type& top() const {
			return _c.back();
		}

		void push(const value_type &val) {
			_c.push_back(val);
		}

		void pop() {
			_c.pop_back();
		}

		template <class Tn, class ContainerN>
		friend bool operator== (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

		template <class Tn, class ContainerN>
		friend bool operator!= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

		template <class Tn, class ContainerN>
		friend bool operator< (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

		template <class Tn, class ContainerN>
		friend bool operator<= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

		template <class Tn, class ContainerN>
		friend bool operator> (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

		template <class Tn, class ContainerN>
		friend bool operator>= (const ft::stack<Tn, ContainerN>& lhs, const ft::stack<Tn, ContainerN>& rhs);

	};

}

#endif
