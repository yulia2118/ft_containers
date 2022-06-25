/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:53:02 by fdarrin           #+#    #+#             */
/*   Updated: 2021/07/05 19:53:04 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include "utils.hpp"

namespace ft {

	template <class T>
	class vector_iterator {

	public:
		typedef typename ft::iterator_traits<T>::value_type value_type;
		typedef typename ft::iterator_traits<T>::reference reference;
		typedef typename ft::iterator_traits<T>::const_reference
		const_reference;
		typedef typename ft::iterator_traits<T>::pointer pointer;
		typedef typename ft::iterator_traits<T>::const_pointer const_pointer;
		typedef typename ft::iterator_traits<T>::difference_type
		difference_type;

	protected:
		pointer	_p;

	public:
		vector_iterator(const vector_iterator &src) {
			this->_p = src._p;
		}

		vector_iterator &operator=(const vector_iterator &rhs) {
			this->_p = rhs._p;
			return *this;
		}

		virtual ~vector_iterator() {
		}

		vector_iterator operator++(int) {
			vector_iterator result(*this);
			++(this->_p);
			return (result);
		}

		vector_iterator &operator++() {
			++(this->_p);
			return (*this);
		}

		pointer base() {
			return _p;
		}

		const_pointer base() const {
			return _p;
		}

		bool operator==(const vector_iterator &rhs) const {
			return (this->_p == rhs._p);
		}

		bool operator!=(const vector_iterator &rhs) const {
			return (!this->operator==(rhs));
		}

		virtual reference operator*() {
			return *(this->_p);
		}

		virtual const_reference operator*() const {
			return *(this->_p);
		}

		virtual pointer operator->() {
			return this->_p;
		}

		virtual const_pointer operator->() const {
			return this->_p;
		}

		vector_iterator() {
			this->_p = NULL;
		}

		vector_iterator operator--(int) {
			vector_iterator result(*this);
			--(this->_p);
			return (result);
		}

		vector_iterator &operator--() {
			--(this->_p);
			return (*this);
		}

		vector_iterator operator+(int n) {
			vector_iterator result(*this);
			result._p += n;
			return result;
		}

		vector_iterator operator-(int n) {
			vector_iterator result(*this);
			result._p -= n;
			return result;
		}

		difference_type operator-(const vector_iterator &rhs) const {
			return (this->_p - rhs._p);
		}

		bool operator<(const vector_iterator &rhs) const {
			return (this->_p < rhs._p);
		}

		bool operator>(const vector_iterator &rhs) const {
			return (rhs < *this);
		}

		bool operator<=(const vector_iterator &rhs) const {
			return (!(*this > rhs));
		}

		bool operator>=(const vector_iterator &rhs) const {
			return (!(*this < rhs));
		}

		vector_iterator &operator+=(int n) {
			this->_p += n;
			return (*this);
		}

		vector_iterator &operator-=(int n) {
			this->_p -= n;
			return (*this);
		}

		reference operator[](size_t n) {
			return *(this->_p + n);
		}

		const_reference operator[](size_t n) const {
			return *(this->_p + n);
		}

		explicit vector_iterator(pointer p) {
			this->_p = p;
		}

		pointer getP() const {
			return this->_p;
		}

		template<typename cT>
		vector_iterator(vector_iterator<cT> const &const_src): _p(const_cast<T*>(const_src.getP())) {

		}
	};

	template<typename T>
	vector_iterator<T> operator+(unsigned int lhs, vector_iterator<T>& rhs) {
		return (rhs + lhs);
	}

	template <class T>
	class reverse_iterator: public vector_iterator<T> {

	public:
		using typename vector_iterator<T>::difference_type;
		using typename vector_iterator<T>::value_type;
		using typename vector_iterator<T>::pointer;
		using typename vector_iterator<T>::const_pointer;
		using typename vector_iterator<T>::reference;
		using typename vector_iterator<T>::const_reference;

		reverse_iterator(): vector_iterator<T>() {

		}

		reverse_iterator(const vector_iterator<T> &src): vector_iterator<T>(src) {

		}

		reverse_iterator(const reverse_iterator &src): vector_iterator<T>(src._p) {

		}

		reverse_iterator(const pointer p): vector_iterator<T>(p) {

		}

		reverse_iterator &operator=(const reverse_iterator &rhs) {
			this->_p = rhs._p;
			return *this;
		}

		reference operator*() {
			vector_iterator<T> result(*this);
			return (*(--result));
		}

		reverse_iterator operator++(int) {
			reverse_iterator result(*this);
			--(this->_p);
			return (result);
		}

		reverse_iterator &operator++() {
			--(this->_p);
			return (*this);
		}

		reverse_iterator operator--(int) {
			reverse_iterator result(*this);
			++(this->_p);
			return (result);
		}

		reverse_iterator &operator--() {
			++(this->_p);
			return (*this);
		}

		reverse_iterator operator+(difference_type n) {
			return reverse_iterator(this->_p - n);
		}
		reverse_iterator &operator+=(difference_type n) {
			this->_p -= n;
			return (*this);
		}

		difference_type operator-(const reverse_iterator &rhs) const {
			return (rhs._p - this->_p);
		}

		reverse_iterator operator-(difference_type n) {
			return reverse_iterator(this->_p + n);
		}

		reverse_iterator &operator-=(difference_type n) {
			this->_p += n;
			return (*this);
		}

		bool operator<(const reverse_iterator &rhs) const {
			return (this->_p > rhs._p);
		}

		bool operator>(const reverse_iterator &rhs) const {
			return (rhs < *this);
		}

		bool operator<=(const reverse_iterator &rhs) const {
			return (!(*this > rhs));
		}

		bool operator>=(const reverse_iterator &rhs) const {
			return (!(*this < rhs));
		}

		pointer operator->() {
			vector_iterator<T> result(*this);
			return (&*(--result));
		}

		const_pointer operator->() const {
			vector_iterator<T> result(*this);
			return (&*(--result));
		}

		vector_iterator<T> base() const {
			return vector_iterator<T>(this->_p);
		}

		reference operator[](size_t n) {
			return *(this->_p - n - 1);
		}

		const_reference operator[](size_t n) const {
			return *(this->_p - n - 1);
		}

		template<typename cT>
		reverse_iterator(reverse_iterator<cT> const &const_src) {
			this->_p = const_cast<T*>(const_src.getP());
		}
	};

	template<typename T>
	reverse_iterator<T> operator+(unsigned int lhs, reverse_iterator<T>& rhs) {
		return (rhs + lhs);
	}

}

#endif
