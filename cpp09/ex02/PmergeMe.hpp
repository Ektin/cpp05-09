/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:31:28 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/28 06:09:55 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP_HPP
# define PMERGEME_TPP_HPP

# ifndef NEGATIVES_ARE_ALLOWED
#  define NEGATIVES_ARE_ALLOWED 0
# endif

# include <vector>
# include <list>
# include <string>
# include <iostream>
# include <sstream>
# include <bits/stdc++.h>

class PmergeMe
{
	private:
		std::vector<int>	_vect;
		std::list<int>		_list;

	private:
		int			_is_input_ok;
		int			_are_negative_allowed;
		int			_cmp_cnt_vect;

	public:
		int			get_is_input_ok() const;

	public:
		unsigned int		get_vect_size() const;
		int			get_vect_elem(unsigned i) const;

	private:
		PmergeMe();
		PmergeMe(PmergeMe const & src);
		PmergeMe &	operator=(PmergeMe const & src);

	public:
		~PmergeMe();
		PmergeMe(std::vector<std::string> const & vect);

	private:
		void	initialize_vect(std::vector<std::string> const & vect);
		void	initialize_list_via_vect(std::vector<int> const & vect);

	private:
		static int	is_digit(char ch);
		static int	are_there_only_digits(\
				std::string const & str, int start, int end);
		static int	is_int_num(std::string const & num);
		static int	get_num(std::string const & num);

	public:
		static void	display_vect(std::vector<int> const & vect);
		static void	display_list(std::list<int> const & list);
		static void	display_list(\
			std::list<std::list<int>::iterator> \
						const & list_of_iterators, \
			std::list<int> const & list);

	// sort vector<int>
	public:
		void		sort_vector();

	public:
	private:
		static int	sort(std::vector<int> & vect, \
					unsigned int width, int & cmp_cnt);
		static int	sort_nearby_pairs(std::vector<int> & vect, \
					unsigned int width, int & cmp_cnt);
		static void	swap(std::vector<int> & vect, \
					unsigned int b1, unsigned int e1, \
					unsigned int b2, unsigned int e2);
		static int	merge_threads(std::vector<int> & vect, \
					unsigned int width, int & cmp_cnt);
		static void	copy_elements(std::vector<int> & to, 
					std::vector<int> const & from, 
					unsigned int b, unsigned int e);
		static unsigned int	find_pos_binary_search(int num, \
					std::vector<int> const & vect, \
					unsigned int width, \
			unsigned int begin, unsigned int end, int & cmp_cnt);
		static int	is_sorted(std::vector<int> const & vect, \
					unsigned int width);
	
	// sort list<int>
	public:
		void		sort_list();

	public:
	private:
		void		sort(std::list<int> & list, \
					unsigned int width, int & cmp_cnt);
		static std::list<int>::iterator	advance(\
				std::list<int> const & list, \
				std::list<int>::iterator, unsigned step);
		static std::list<int>::const_iterator	advance(\
				std::list<int> const & list,\
				std::list<int>::const_iterator, unsigned step);
		static std::list<int>::iterator	advance_back(\
				std::list<int> const & list,\
				std::list<int>::iterator, unsigned step);
		/*static std::list<int>::const_iterator	advance_back(\
				std::list<int> const & list,\
				std::list<int>::const_iterator, unsigned step);*/
		static void	sort_nearby_pairs(std::list<int> & list, \
					unsigned int width, int & cmp_cnt);
		static void	swap(std::list<int> & list, \
				std::list<int>::iterator left_beg, \
				std::list<int>::iterator left_end, \
				std::list<int>::iterator right_beg, \
				std::list<int>::iterator right_end);
		static void	copy_elements(std::list<int> & to, \
					std::list<int> const & from, \
					std::list<int>::iterator beg, \
					std::list<int>::iterator end);
		static void	copy_elements(std::list<int> & to, \
					std::list<int> const & from, \
					std::list<int>::const_iterator beg, \
					std::list<int>::const_iterator end);
		static int	is_sorted(std::list<int> const & list, \
					unsigned int width);
		static int	get_val_list(std::list<int> const & list, \
					std::list<int>::iterator it, \
					unsigned width);
		static int	get_val_list(std::list<int> const & list, \
			std::list<int>::const_iterator it, unsigned width);
		/*static std::list<int>::iterator \
			find_pos_binary_search(int num, \
				std::list<int> const & list, \
				unsigned int width, \
				std::list<int>::iterator begin, \
				std::list<int>::iterator end, \
				int & cmp_cnt);*/
		static std::list<int>::iterator \
			find_pos_binary_search(int num, \
				std::list<int> const & list, \
				unsigned int width, \
				std::list<int>::iterator begin, \
				std::list<int>::iterator end, \
				int & cmp_cnt);
		static void	merge_threads(std::list<int> & list, \
					unsigned int width, int & cmp_cnt);

	public:
		class	WrongInputException : public std::exception
		{
			char const *	what() const throw();
		};

		class	OutOfBoundsException : public std::exception
		{
			char const *	what() const throw();
		};
		class	SwapException : public std::exception
		{
			char const *	what() const throw();
		};
		class	CopyElementsException : public std::exception
		{
			char const *	what() const throw();
		};
		class	BinarySearchException : public std::exception
		{
			char const *	what() const throw();
		};
		class	NotSortedException : public std::exception
		{
			char const *	what() const throw();
		};
		class	AdvanceException : public std::exception
		{
			char const *	what() const throw();
		};
		class	AdvanceConstIteratorException : public std::exception
		{
			char const *	what() const throw();
		};
		class	AdvanceBackException : public std::exception
		{
			char const *	what() const throw();
		};
		class	CopyElementsAdvanceException : public std::exception
		{
			char const *	what() const throw();
		};
		class	CopyElementsConstIteratorAdvanceException : public std::exception
		{
			char const *	what() const throw();
		};
};

std::ostream &	operator<<(std::ostream & os, PmergeMe const & obj);

#endif // PMERGEME_TPP_HPP
