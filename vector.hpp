/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:53:02 by fdarrin           #+#    #+#             */
/*   Updated: 2021/07/05 19:53:04 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector_iterator.hpp"
#include "utils.hpp"

namespace ft {

	template <class T, class Allocator = std::allocator<T> >
	class vector {

	public:
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
		typedef ft::vector_iterator<T>	iterator;
		typedef ft::vector_iterator<const T> const_iterator;
		typedef ft::reverse_iterator<T>	reverse_iterator;
		typedef ft::reverse_iterator<const T> const_reverse_iterator;
		typedef typename allocator_type::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;

	private:
		pointer	_container;
		size_type _container_size;
		size_type _container_length;
		allocator_type _allocator;

	public:
		explicit vector(const allocator_type &alloc = allocator_type()):
		_container(NULL), _container_size(0), _container_length(0),
		_allocator(alloc){
		}

		vector(size_type n, const value_type &val = value_type(), const
		allocator_type &alloc = allocator_type()): _container(NULL),
		_container_size(n), _container_length(n), _allocator(alloc) {
			this->_container = this->_allocator.allocate(n);
			for (size_type i = 0; i < n; i++)
				_allocator.construct(_container + i, val);
		}

		template	<class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type
		&alloc = allocator_type(), typename
		ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0):
		_allocator(alloc) {
			_container_size = 0;
			for (InputIterator i = first; i != last; i++)
				_container_size++;
			_container_length = _container_size;
			_container = _allocator.allocate(_container_length);
			for (size_type i = 0; i < _container_size; i++, first++)
				_allocator.construct(_container + i, *first);
		}

		vector(const vector& x): _container(x._container), _container_size(x
		._container_size), _container_length(x._container_length), _allocator
		(x._allocator) {
			_container = _allocator.allocate(_container_length);
			pointer first = (pointer)x.begin().operator->();
			for (size_type i = 0; i < _container_size; i++, first++)
				_allocator.construct(_container + i, *first);
		}

		~vector() {
			for (size_type i = 0; i < _container_size; i++)
				_allocator.destroy(_container + i);
			_allocator.deallocate(_container, _container_length);
		}

		vector& operator=(const vector& x) {
			if (_container_length)
				clear();
			insert(begin(), x.begin(), x.end());
			return *this;
		}

		iterator begin() {
			return iterator(this->_container);
		}

		const_iterator begin() const {
			return const_iterator(this->_container);
		}

		iterator end() {
			return iterator(this->_container + this->_container_size);
		}

		const_iterator end() const {
			return const_iterator(this->_container + this->_container_size);
		}

		reverse_iterator rbegin() {
			return reverse_iterator(this->end());
		}

		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(this->end());
		}

		reverse_iterator rend() {
			return reverse_iterator(this->begin());
		}

		const_reverse_iterator rend() const {
			return const_reverse_iterator(this->begin());
		}

		size_type size() const {
			return this->_container_size;
		}

		size_type max_size() const {
			return _allocator.max_size();
		}

		void resize(size_type n, value_type val = value_type()) {
			if (n >= _container_size)
				insert(end(), n - _container_size,val);
			else
				erase(begin() + n, end());
		}

		size_type capacity() const {
			return this->_container_length;
		}

		bool empty() const {
			return (this->_container_size == 0);
		}

		void reserve(size_type n) {
			if (n <= _container_length || n == 0)
				return;
			pointer _container = _allocator.allocate(n);
			for (size_type i = 0; i < _container_size; i++){
				_allocator.construct(_container + i, this->_container[i]);
			}
			this->~vector();
			this->_container = _container;
			_container_length = n;
		}

		reference		operator[](size_type n) {
			return *(_container + n);
		}

		const_reference	operator[](size_type n) const {
			return *(_container + n);
		}

		reference		at(size_type n) {
			if (n < 0 || n >= size())
				throw std::out_of_range("Index is out of range");
			return *(_container + n);
		}

		const_reference	at(size_type n) const {
			if (n < 0 || n >= size())
				throw std::out_of_range("Index is out of range");
			return *(_container + n);
		}

		reference front() {
			return *begin();
		}

		const_reference front() const {
			return *begin();
		}

		reference back() {
			return *(end() - 1);
		}

		const_reference back() const {
			return *(end() - 1);
		}

		template	<class InputIterator>
		void assign(InputIterator first, InputIterator last, typename
		ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) {
			difference_type n = 0;
			for (InputIterator i = first; i != last; i++)
				n++;
			if (n)
			{
				clear();
				reserve(n);
				for (difference_type i = 0; i < n; i++, first++)
					this->_container[i] = *first;
			}
			_container_size = n;
		}

		void assign(size_type n, const value_type& val) {
			if (n)
			{
				clear();
				reserve(n);
				for (size_type i = 0; i < n; i++)
					this->_container[i] = val;
			}
			_container_size = n;
		}

		void push_back(const value_type &val) {
			insert(end(), val);
		}

		void pop_back() {
			erase(end() - 1);
		}

		iterator insert(iterator position, const value_type &val) {
			difference_type move = position - begin();
			size_type n = 1;
			if (_container_length < _container_size + n)
				reserve(std::max(_container_size * 2, _container_size + n));
			position = begin() + move;
			for (iterator ptr = end() + n - 1; ptr >= position + n; ptr--)
			{
				_allocator.construct(ptr.base(), *(ptr - n));
				_allocator.destroy(ptr.base() - n);
			}
			for (iterator ptr = position + n - 1; ptr >= position; --ptr)
				_allocator.construct(ptr.base(), val);
			_container_size += n;
			return position;
		}

		void insert(iterator position, size_type n, const value_type &val) {
			difference_type move = position - begin();
			if (n == 0 || move < 0)
				return;
			if (_container_length < _container_size + n)
				reserve(std::max(_container_size * 2, _container_size + n));
			position = begin() + move;
			for (iterator ptr = end() + n - 1; ptr >= position + n; ptr--)
			{
				_allocator.construct(ptr.base(), *(ptr - n));
				_allocator.destroy(ptr.base() - n);
			}
			for (iterator ptr = position + n - 1; ptr >= position; --ptr)
				_allocator.construct(ptr.base(), val);
			_container_size += n;
		}

		template	<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator
		last, typename ft::enable_if<!ft::is_integral<InputIterator>::value
		>::type * = 0) {
			size_t n = 0;
			InputIterator first_tmp = first;
			while (first_tmp != last)
			{
				n++;
				first_tmp++;
			}
			size_type target_index = 0;
			while (iterator(this->_container + target_index) != position && target_index < this->_container_size)
				target_index++;
			for (size_type index = 0; index < n; index++)
			{
				iterator begin = this->begin();
				this->insert(begin + target_index + index, *first);
				first++;
			}
		}

		iterator erase(iterator position) {
			return this->erase(position, position + 1);
		}

		iterator erase(iterator first, iterator last) {
			size_type n = last - first;
			iterator target = first;
			while (target + n != this->end())
			{
				*target = *(target + n);
				target++;
			}
			this->_container_size -= n;
			return first;
		}

		void swap(vector &x) {
			std::swap(this->_container, x._container);
			std::swap(this->_container_size, x._container_size);
			std::swap(this->_container_length, x._container_length);
			std::swap(this->_allocator, x._allocator);
		}

		void clear() {
			this->_container_size = 0;
		}
	};

	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs) {
		if (lhs.size() != rhs.size())
			return false;
		for (size_t index = 0; index < lhs.size(); index++)
		{
			if (lhs[index] != rhs[index])
				return false;
		}
		return true;
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs) {
		return (!(lhs == rhs));
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs) {
		return (rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs) {
		return (!(lhs > rhs));
	}

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc> &lhs, const vector<T,Alloc> &rhs) {
		return (!(lhs < rhs));
	}

	template <class T, class Alloc>
	void swap(vector<T,Alloc> &x, vector<T,Alloc> &y) {
		x.swap(y);
	}
}

#endif
