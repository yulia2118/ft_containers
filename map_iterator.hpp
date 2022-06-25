/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdarrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 19:52:47 by fdarrin           #+#    #+#             */
/*   Updated: 2021/07/05 19:52:48 by fdarrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "utils.hpp"

namespace ft {

	template <typename Key, typename T, class Compare>
	class map_const_iterator;

	template <typename Key, typename T, class Compare>
	class map_iterator {

	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef AVLNode<Key, T, Compare>* node_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;

	protected:
		node_type _p;
		node_type _root;

	private:
		class OutOfRangeException : public std::exception {
			virtual const char * what() const throw() {
				return "map_iterator::OutOfRangeException";
			}
		};

	public:
		map_iterator(): _p(NULL), _root(NULL) {
		}

		map_iterator(node_type p, node_type root): _p(p), _root(root) {
		}

		map_iterator(const map_iterator &src): _p(src._p), _root(src._root) {
		}

		map_iterator(const map_const_iterator<Key, T, Compare> &src): _p(src.getP()), _root(src.getRoot()) {
		}

		virtual ~map_iterator() {
		}

		map_iterator &operator=(const map_iterator &rhs) {
			this->_p = rhs._p;
			this->_root = rhs._root;
			return *this;
		}

		bool operator==(const map_iterator &rhs) {
			return (this->_p == rhs._p);
		}

		bool operator==(const map_const_iterator<Key, T, Compare> &rhs) {
			return (this->_p == rhs.getP());
		}

		bool operator!=(const map_iterator &rhs) {
			return (this->_p != rhs._p);
		}

		bool operator!=(const map_const_iterator<Key, T, Compare> &rhs) {
			return (this->_p != rhs.getP());
		}

		reference operator*() {
			return *(this->_p->val);
		}

		const_reference operator*() const {
			return *(this->_p->val);
		}

		pointer operator->() {
			return this->_p->val;
		}

		const_pointer operator->() const {
			return this->_p->val;
		}

		map_iterator operator++(int) {
			if (this->_p == this->_root)
				throw OutOfRangeException();
			map_iterator result(*this);
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return result;
		}

		map_iterator &operator++() {
			if (this->_p == this->_root)
				throw OutOfRangeException();
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return (*this);
		}

		map_iterator operator--(int) {
			map_iterator result(*this);
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return result;
		}

		map_iterator &operator--() {
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return (*this);
		}

		const node_type getP() const {
			return this->_p;
		}

		const node_type getRoot() const {
			return this->_root;
		}
	};

	template <typename Key, typename T, class Compare>
	class map_const_iterator {

	public:
		typedef Key key_type;
		typedef T mapped_type;
		typedef ft::pair<const Key, T> value_type;
		typedef Compare key_compare;
		typedef AVLNode<Key, T, Compare>* node_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef value_type* pointer;
		typedef const value_type* const_pointer;

	protected:
		node_type _p;
		node_type _root;

	private:
		class OutOfRangeException : public std::exception {
			virtual const char * what() const throw() {
				return "map_const_iterator::OutOfRangeException";
			}
		};

	public:
		map_const_iterator(): _p(NULL), _root(NULL) {
		}

		map_const_iterator(node_type p, node_type root): _p(p), _root(root) {
		}

		map_const_iterator(const map_const_iterator &src): _p(src._p), _root(src._root) {
		};

		map_const_iterator(const map_iterator<Key, T, Compare> &src): _p(src.getP()), _root(src.getRoot()) {
		}

		virtual ~map_const_iterator() {
		}

		map_const_iterator &operator=(const map_const_iterator &rhs) {
			this->_p = rhs._p;
			this->_root = rhs._root;
			return *this;
		}

		bool operator==(const map_iterator<Key, T, Compare> &rhs) {
			return (this->_p == rhs.getP());
		}

		bool operator==(const map_const_iterator &rhs) {
			return (this->_p == rhs._p);
		}

		bool operator!=(const map_iterator<Key, T, Compare> &rhs) {
			return (this->_p != rhs.getP());
		}

		bool operator!=(const map_const_iterator &rhs) {
			return (this->_p != rhs._p);
		}

		const_reference operator*() const {
			return *(this->_p->val);
		}

		const_pointer operator->() const {
			return this->_p->val;
		}

		map_const_iterator operator++(int) {
			if (this->_p == this->_root)
				throw OutOfRangeException();
			map_const_iterator result(*this);
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return result;
		}

		map_const_iterator &operator++() {
			if (this->_p == this->_root)
				throw OutOfRangeException();
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return (*this);
		}

		map_const_iterator operator--(int) {
			map_const_iterator result(*this);
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return result;
		}

		map_const_iterator &operator--() {
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return (*this);
		}

		const node_type getP() const {
			return this->_p;
		}

		const node_type getRoot() const {
			return this->_root;
		}
	};

	template <typename Key, typename T, class Compare>
	class map_rev_iterator: public map_iterator<Key, T, Compare> {

	public:
		using typename map_iterator<Key, T, Compare>::key_type;
		using typename map_iterator<Key, T, Compare>::mapped_type;
		using typename map_iterator<Key, T, Compare>::value_type;
		using typename map_iterator<Key, T, Compare>::key_compare;
		using typename map_iterator<Key, T, Compare>::node_type;
		using typename map_iterator<Key, T, Compare>::reference;
		using typename map_iterator<Key, T, Compare>::const_reference;
		using typename map_iterator<Key, T, Compare>::pointer;
		using typename map_iterator<Key, T, Compare>::const_pointer;

	private:
		class OutOfRangeException : public std::exception {
			virtual const char * what() const throw() {
				return "map_rev_iterator::OutOfRangeException";
			}
		};

	public:
		map_rev_iterator(): map_iterator<Key, T, Compare>() {
		}

		map_rev_iterator(const map_iterator<Key, T, Compare> &src): map_iterator<Key, T, Compare>(src) {
		}

		map_rev_iterator(const map_rev_iterator &src): map_iterator<Key, T, Compare>(src._p, src._root) {
		}

		virtual ~map_rev_iterator() {
		}

		map_rev_iterator &operator=(const map_rev_iterator &rhs) {
			this->_p = rhs._p;
			this->_root = rhs._root;
			return *this;
		}

		reference operator*() {
			if (this->_p == this->_root)
				return *(this->_root->last()->val);
			return *(this->_p->prev()->val);
		}

		const_reference operator*() const {
			if (this->_p == this->_root)
				return *(this->_root->last()->val);
			return *(this->_p->prev()->val);
		}

		pointer operator->() {
			if (this->_p == this->_root)
				return this->_root->last()->val;
			return this->_p->prev()->val;
		}

		const_pointer operator->() const {
			if (this->_p == this->_root)
				return this->_root->last()->val;
			return this->_p->prev()->val;
		}

		map_rev_iterator operator--(int) {
			if (this->_p == this->_root)
				throw OutOfRangeException();
			map_rev_iterator result(*this);
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return result;
		}

		map_rev_iterator &operator--() {
			if (this->_p == this->_root)
				throw OutOfRangeException();
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return (*this);
		}

		map_rev_iterator operator++(int) {
			map_rev_iterator result(*this);
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return result;
		}

		map_rev_iterator &operator++() {
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else
			{
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return (*this);
		}

		const node_type getP() const {
			return this->_p;
		}

		const node_type getRoot() const {
			return this->_root;
		}

		map_iterator<Key, T, Compare> base() const {
			return map_iterator<Key, T, Compare>(this->_p, this->_root);
		}
	};

	template <typename Key, typename T, class Compare>
	class map_rev_const_iterator: public map_const_iterator<Key, T, Compare> {

	public:
		using typename map_const_iterator<Key, T, Compare>::key_type;
		using typename map_const_iterator<Key, T, Compare>::mapped_type;
		using typename map_const_iterator<Key, T, Compare>::value_type;
		using typename map_const_iterator<Key, T, Compare>::key_compare;
		using typename map_const_iterator<Key, T, Compare>::node_type;
		using typename map_const_iterator<Key, T, Compare>::reference;
		using typename map_const_iterator<Key, T, Compare>::const_reference;
		using typename map_const_iterator<Key, T, Compare>::pointer;
		using typename map_const_iterator<Key, T, Compare>::const_pointer;

	private:
		class OutOfRangeException : public std::exception {
			virtual const char * what() const throw() {
				return "map_rev_const_iterator::OutOfRangeException";
			}
		};

	public:
		map_rev_const_iterator(): map_const_iterator<Key, T, Compare>() {
		}

		map_rev_const_iterator(const map_const_iterator<Key, T, Compare> &src): map_const_iterator<Key, T, Compare>(src) {
		}

		map_rev_const_iterator(const map_rev_const_iterator &src): map_const_iterator<Key, T, Compare>(src._p, src._root) {
		}

		virtual ~map_rev_const_iterator() {
		}

		map_rev_const_iterator &operator=(const map_rev_const_iterator &rhs) {
			this->_p = rhs._p;
			this->_root = rhs._root;
			return *this;
		}

		const_reference operator*() const {
			if (this->_p == this->_root)
				return *(this->_root->last()->val);
			return *(this->_p->prev()->val);
		}

		const_pointer operator->() const {
			if (this->_p == this->_root)
				return this->_root->last()->val;
			return this->_p->prev()->val;
		}

		map_rev_const_iterator operator--(int) {
			if (this->_p == this->_root)
				throw OutOfRangeException();
			map_rev_const_iterator result(*this);
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return result;
		}

		map_rev_const_iterator &operator--() {
			if (this->_p == this->_root)
				throw OutOfRangeException();
			this->_p = this->_p->next();
			if (!(this->_p))
				this->_p = this->_root;
			return (*this);
		}

		map_rev_const_iterator operator++(int) {
			map_rev_const_iterator result(*this);
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else {
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return result;
		}

		map_rev_const_iterator &operator++() {
			if (this->_p == this->_root)
				this->_p = this->_root->last();
			else {
				this->_p = this->_p->prev();
				if (!(this->_p))
					throw OutOfRangeException();
			}
			return (*this);
		}

		const node_type getP() const {
			return this->_p;
		}

		const node_type getRoot() const {
			return this->_root;
		}

		map_const_iterator<Key, T, Compare> base() const {
			return map_const_iterator<Key, T, Compare>(this->_p, this->_root);
		}
	};
}

#endif
