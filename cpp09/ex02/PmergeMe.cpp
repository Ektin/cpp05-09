/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: EktinOpUrims <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 14:31:54 by EktinOpUrims      #+#    #+#             */
/*   Updated: 2025/03/28 07:20:39 by EktinOpUrims     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const & src)
{
	*this = src;
}

PmergeMe&	PmergeMe::operator=(PmergeMe const & src)
{
	if (this != &src)
	{
	}
	return (*this);
}

PmergeMe::PmergeMe(std::vector<std::string> const & vect) : 
		_is_input_ok(1), 
		_are_negative_allowed(NEGATIVES_ARE_ALLOWED),
		_cmp_cnt_vect(0)
{
	if (_are_negative_allowed != 1)
		_are_negative_allowed = 0;
	try
	{
		initialize_vect(vect);
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
	}
	if (_is_input_ok)
	{
		std::cout << "Input numbers : ";
		std::cout  << *this << std::endl;
	}
	initialize_list_via_vect(_vect);
}

void	PmergeMe::initialize_vect(std::vector<std::string> const & vect)
{
	int	num;

	if (vect.empty())
		_is_input_ok = 0;
	for (unsigned int i = 0; i < vect.size(); ++i)
	{
		if (1 != is_int_num(vect[i]))
		{
			_is_input_ok = 0;
			std::cerr << "Error: problem with input element "
				"on position " << i << " equal to [" 
				<< vect[i] << "]" << std::endl;
			return ;
		}
		num = get_num(vect[i]);
		if (num < 0 && 0 == _are_negative_allowed)
		{
			_is_input_ok = 0;
			std::cerr << "Error: negative number detected "
				"on position " << i << " equal to "
				<< vect[i] << std::endl;
			std::cerr << "Compile with flag "
				"-D NEGATIVES_ARE_ALLOWED=1"
				<< " to allow negative numbers" << std::endl;
			return ;
		}
		_vect.push_back(num);
	}
}

void	PmergeMe::initialize_list_via_vect(std::vector<int> const & vect)
{
	if (0 != _list.size())
	{
		std::cerr << "Error : List is already non empty, "
				"how you initialize it?" << std::endl;
		return ;
	}
	_list.insert(_list.begin(), vect.begin(), vect.end());
}

std::ostream &	operator<<(std::ostream & os, PmergeMe const & obj)
{
	unsigned int	limit;
	int		part_only;

	part_only = 0;
	if (obj.get_vect_size() <= 100)
	{
		limit = obj.get_vect_size();
	}
	else
	{
		limit = 10;
		part_only = 1;
	}

	for (unsigned int i = 0; i < limit; ++i)
	{
		os << obj.get_vect_elem(i) << " ";
	}
	if (1 == part_only)
	{
		os << "[...]";
	}
	os << std::endl;
	return (os);
}

int	PmergeMe::get_is_input_ok() const
{
	return (_is_input_ok);
}

unsigned int	PmergeMe::get_vect_size() const
{
	return (_vect.size());
}

int	PmergeMe::get_vect_elem(unsigned i) const
{
	if (i > _vect.size())
	{
		std::cerr << "Error : out of range : size " << _vect.size()
			<< " required pos : " << i << std::endl; 
		throw (OutOfBoundsException());
	}
	return (_vect[i]);
}

int	PmergeMe::is_digit(char ch)
{
	if (ch <= '9' && '0' <= ch)
		return (1);
	return (0);
}

// [start, end)
int	PmergeMe::are_there_only_digits(std::string const & str, int start, int end)
{
	if (start > end || start < 0 || end > (int)str.length())
	{
		std::cerr << "are_there_only_digits called wrong" 
			<< str << "; " << start << ", " << end << std::endl;
		return (-1);
	}
	for (int i = start; i < end; ++i)
	{
		if (0 == is_digit(str[i]))
			return (0);
	}
	return (1);
}
 
int	PmergeMe::is_int_num(std::string const & num)
{
	if (num.empty())
		return (0);

	int	start;

	start = 0;
	if ('-' == num[0] || '+' == num[0])
		start = 1; 
	if (1 == start && 1 == num.length())
		return (0);
	for (unsigned int i = start; i < num.length(); ++i)
	{
		if (0 == is_digit(num[i]))
			return (0);
	}
	return (1);
}

int	PmergeMe::get_num(std::string const & num)
{
	if (1 != is_int_num(num))
	{
		std::cerr << "Wrong number : " << num << std::endl;
		throw (WrongInputException());
	}

	std::istringstream	is;
	int			res;

	is.clear();
	is.str(num);
	is >> res;
	return (res);
}

char const *	PmergeMe::WrongInputException::what() const throw()
{
	return ("Error : Wrong input");
}

char const *	PmergeMe::OutOfBoundsException::what() const throw()
{
	return ("Error : Array out of range");
}

char const *	PmergeMe::SwapException::what() const throw()
{
	return ("Error : swap corrupted");
}

char const *	PmergeMe::CopyElementsException::what() const throw()
{
	return ("Error : copy elements corrupted");
}

char const *	PmergeMe::BinarySearchException::what() const throw()
{
	return ("Error : binary search exception");
}

char const *	PmergeMe::NotSortedException::what() const throw()
{
	return ("Error : not sorted exception");
}

char const *	PmergeMe::AdvanceException::what() const throw()
{
	return ("Error : walked too much in advance()");
}

char const *	PmergeMe::AdvanceConstIteratorException::what() const throw()
{
	return ("Error : walked too much in advance()");
}

char const *	PmergeMe::AdvanceBackException::what() const throw()
{
	return ("Error : walked too much in advance()");
}

char const *	PmergeMe::CopyElementsAdvanceException::what() const throw()
{
	return ("Error : walked too much in advance()");
}

char const *	PmergeMe::CopyElementsConstIteratorAdvanceException::what() const throw()
{
	return ("Error : walked too much in advance()");
}

void	PmergeMe::display_vect(std::vector<int> const & vect)
{

	unsigned int	limit;
	int		part_only;

	part_only = 0;
	if (vect.size() <= 100)
	{
		limit = vect.size();
	}
	else
	{
		limit = 10;
		part_only = 1;
	}

	for (unsigned int i = 0; i < limit; ++i)
	{
		std::cout << vect[i] << " ";
	}
	if (1 == part_only)
	{
		std::cout << "[...]";
	}
	std::cout << std::endl;
}

void	PmergeMe::display_list(std::list<int> const & list)
{
	std::list<int>::const_iterator	it;

	for (it = list.begin(); it != list.end();  ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::display_list(\
		std::list<std::list<int>::iterator> \
				const & list_of_iterators, \
		std::list<int> const & list)
{
	std::list<std::list<int>::iterator>::const_iterator	it;

	for (it = list_of_iterators.begin(); \
			it != list_of_iterators.end();  \
				++it)
	{
		if (*it != list.end())
			std::cout << *(*it) << " ";
		else
			std::cout << "[end of list]";
	}
	std::cout << std::endl;
}

/////////////////
// sort vector //
/////////////////

void	PmergeMe::sort_vector()
{
	clock_t	start;
	clock_t	end;
	double	time_taken;

	start = clock();
	try
	{
		_cmp_cnt_vect = sort(_vect, 1, _cmp_cnt_vect);
		end = clock();
		std::cout << "Sorted        : ";
		std::cout << *this << std::endl;
		if (0 == is_sorted(_vect, 1))
		{
			std::cerr << "Error : the vector is not actually sorted"
				<< std::endl;
		}
		std::cout << "Sorting vector<int> required " << _cmp_cnt_vect 
				<< " comparisons" << " and took ";
		time_taken = (double)(end-start) / (double)(CLOCKS_PER_SEC);
		std::cout << time_taken << std::setprecision(5) 
			<< " secs" << std::endl; 
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	PmergeMe::sort_nearby_pairs(std::vector<int> & vect, \
			unsigned int width, int & cmp_cnt_vect)
{
	int N_of_pairs;

	N_of_pairs = (vect.size() / width) >> 1;
	if (0 == N_of_pairs)
		return (cmp_cnt_vect);
	for (int i = 0; i < N_of_pairs; ++i)
	{
		++cmp_cnt_vect;
		if (vect[(2 * i + 1) * width - 1] > vect[(2 * i + 2) * width - 1])
		{
			swap(vect, 2*i*width, (2*i+1)*width, \
				(2*i+1)*width, (2*i+2)*width);
		}
	}
	return (cmp_cnt_vect);
}

// swaps [b1, e1) with [b2, e2)
void	PmergeMe::swap(std::vector<int> & vect, \
	unsigned int b1, unsigned int e1, unsigned int b2, unsigned int e2)
{
	int	error;

	error = 0;
	if (b1 > e1 || b2 > e2 || b1 == b2 || e1 == e2)
		error = 1;
	else if (e1 > vect.size() || e2 > vect.size())
		error = 1;
	else if (b1 < b2 && e1 > b2)
		error = 1;
	else if (b2 < b1 && e2 > b1)
		error = 1;
	else if (b1 - e1 != b2 - e2)
		error = 1;
	if (b1 == e1)
	{
		std::cout << "\n\nWARNING : swap : size : " 
		<< vect.size() << "["
		<< b1 << ", " << e1 << ") <--> ["
		<< b2 << ", " << e2 << ")\n\n" << std::endl;
	}
	if (error)
	{
		std::cerr << "Error : swap : size : " << vect.size() << "["
			<< b1 << ", " << e1 << ") <--> ["
			<< b2 << ", " << e2 << ")" << std::endl;
		throw (SwapException());
	}

	int	tmp;

	for (unsigned int i = 0; i < e1 - b1; i++)
	{
		tmp = vect[b1 + i];
		vect[b1 + i] = vect[b2 + i];
		vect[b2 + i] = tmp;
	}
}

void	PmergeMe::copy_elements(std::vector<int> & to,
		std::vector<int> const & from, unsigned int b, unsigned int e)
{
	if (b > e || e > from.size())
	{
		std::cout << "ERROR : copy_elements : size to : "
			<< to.size()
			<< ", size from : " << from.size()
			<< " [" << b << ", " << e << ")" << std::endl;
		display_vect(to);
		throw(CopyElementsException());
	}
	if (b == e)
	{
		std::cout << "WARNING : copy_elements : size to : "
			<< to.size()
			<< ", size from : " << from.size()
			<< " [" << b << ", " << e << ")" << std::endl;
	}
	for (unsigned int i = b; i < e; ++i)
	{
		to.push_back(from[i]);
	}
}

int	PmergeMe::is_sorted(std::vector<int> const & vect, unsigned int width)
{
	if ((vect.size() / width) * width != vect.size())
	{
		std::cerr << "Error : is_sorted : " << vect.size()
			<< ", " << width << std::endl;
		throw(BinarySearchException());
	}
	for (unsigned int i = 0; i + 1 < vect.size() / width; ++i)
	{
		if (vect[(i + 1) * width - 1] > vect[(i + 2) * width - 1])
			return (0);
	}
	return (1);
}

// [begin .. end)
unsigned int	PmergeMe::find_pos_binary_search(int num, \
		std::vector<int> const & vect,\
		unsigned int width, unsigned int begin, unsigned int end, \
		int & cmp_cnt_vect)
{
	unsigned int	pos;
	unsigned int	middle;

	if (end > vect.size() || begin > end)
	{
		std::cerr << "Error : binary search out of range: "
			"vect.size(): " << vect.size() << 
			", width : " << width << " ["
			<< begin << ", " << end << ")";
		throw (BinarySearchException());
	}
	else if ((vect.size() / width) * width != vect.size() ||
		(begin / width) * width != begin ||
		(end / width) * width != end)
	{
		std::cerr << "Error : binary search, not dividable: "
			"vect.size() : " 
			<< vect.size() << "; width : " << width
			<< "[" << begin 
			<< ", " << end << ")" << std::endl;
		throw (BinarySearchException());
	}
	if (0 == is_sorted(vect, width))
	{
		std::cerr << "Error: not sorted, width: " << width << "vect: "; 
		display_vect(vect);
		throw(NotSortedException());
	}
	if (begin == end)
		return (begin);
	middle = (((begin / width) + (end / width)) / 2) * width;

	++cmp_cnt_vect;
	if (num < vect[middle + width - 1])
		pos = find_pos_binary_search(num, vect, width, \
					begin, middle, cmp_cnt_vect);
	else if (num > vect[middle + width - 1])
	{
		pos = find_pos_binary_search(num, vect, width, \
				middle + width, end, cmp_cnt_vect);
	}
	else
	{
		pos = middle;
	}
	return (pos);
}

// mt_cnt : main thread count
// cons_cnt: consequent count in main thread
int	PmergeMe::merge_threads(std::vector<int> & vect, unsigned int width, \
						int & cmp_cnt_vect)
{
	int	N_of_elem;
	int	cons_cnt;
	int	mt_cnt;
	std::vector<int>	main_thread;
	std::vector<int>	other_thread;
	std::vector<int>	addresses;
	int	num;
	int	pos;

	N_of_elem = vect.size() / width;
	if (N_of_elem <= 2)
	{
		return (cmp_cnt_vect);
	}
	cons_cnt = 1;
	mt_cnt = 3;
	copy_elements(main_thread, vect, 0, cons_cnt * width);
	for (; main_thread.size() / width < vect.size() / width;)
	{
		if (other_thread.size() != 0 || addresses.size() != 0)
		{
			std::cerr << "Error: not empty other_thread,addresses";
			display_vect(other_thread);
			display_vect(addresses);
			other_thread.clear();
			addresses.clear();
		}
		for (int i = 0; \
			i < mt_cnt - cons_cnt && \
			(cons_cnt + 2 * i + 1) * width <= vect.size(); \
			++i)
		{
			copy_elements(main_thread, vect, \
				(cons_cnt + 2 * i) * width, \
				(cons_cnt + 2 * i + 1) * width);
			
		}
		for (int i = 0; \
			i < mt_cnt - cons_cnt && \
			(cons_cnt + 2 * i + 2) * width <= vect.size(); \
			++i)
		{
			copy_elements(other_thread, vect, \
				(cons_cnt + 2 * i + 1) * width, \
				(cons_cnt + 2 * i + 2) * width);
			addresses.push_back((cons_cnt + i + 1) * width);
			
		}

		// insert other thread elements to main thread, reverse order
		while (other_thread.size() > 0)
		{
			num = other_thread.back();
			pos = find_pos_binary_search(num, main_thread, \
				width, 0, addresses.back(), cmp_cnt_vect);
			addresses.pop_back();
			// updating addresses 
			for (unsigned j = 0; j < addresses.size(); ++j)
			{
				if (addresses[j] >= pos)
					addresses[j] += width;
			}

			// insert the element
			main_thread.insert(main_thread.begin() + pos, \
				other_thread.end() - width, other_thread.end());
			for (unsigned int j = 0; j < width; ++j)
				other_thread.pop_back();
		}

		// update mt_cnt, cons_cnt
		mt_cnt <<= 1;
		++mt_cnt;
		cons_cnt = mt_cnt - cons_cnt - 1;
	}

	// adding remaining elements from vect to main_thread, 
	// then reassigning main_thread to vect
	main_thread.insert(main_thread.end(), \
		vect.end() - (vect.size() - main_thread.size()), \
		vect.end());
	vect = main_thread;
	return (cmp_cnt_vect);
}

int	PmergeMe::sort(std::vector<int> & vect, unsigned int width, \
						int & cmp_cnt_vect)
{
	if (vect.size() < (width << 1))
		return (cmp_cnt_vect);
	cmp_cnt_vect = sort_nearby_pairs(vect, width, cmp_cnt_vect);

	cmp_cnt_vect = sort(vect, 2 * width, cmp_cnt_vect);

	cmp_cnt_vect = merge_threads(vect, width, cmp_cnt_vect);

	return (cmp_cnt_vect);
}

///////////////
// sort list //
///////////////

void	PmergeMe::sort_list()
{
	clock_t	start;
	clock_t	end;
	double	time_taken;
	int	cmp_cnt;

	try
	{
		cmp_cnt = 0;
		start = clock();
		sort(_list, 1, cmp_cnt);
		end = clock();
		if (0 == is_sorted(_list, 1))
		{
			std::cerr << "Error : the list is not actually sorted"
				<< std::endl;
		}
		std::cout << "Sorting list<int>   required " << cmp_cnt 
				<< " comparisons and took ";
		time_taken = (double)(end-start) / (double)(CLOCKS_PER_SEC);
		std::cout << time_taken << std::setprecision(5) 
			<< " secs" << std::endl; 
	}
	catch (std::exception const & e)
	{
		std::cerr << e.what() << std::endl;
	}
}

std::list<int>::iterator	PmergeMe::advance(std::list<int> const & list, \
		std::list<int>::iterator it, unsigned step)
{
	if ((int)step < 0)
	{
		std::cerr << "WARNING: too big or negative step in advance."
				"Aborting" << std::endl;
		return (it);
	}
	for (unsigned i = 0; i < step; ++i)
	{
		if (it == list.end())
		{
			std::cerr << "Error: i = " << i << ", step:" << step
				<< ", size: " << list.size() << "; ";
			display_list(list);
			throw (AdvanceException());
		}
		++it;
	}
	return (it);
}

std::list<int>::const_iterator	PmergeMe::advance(std::list<int> const & list, \
		std::list<int>::const_iterator it, unsigned step)
{
	if ((int)step < 0)
	{
		std::cerr << "WARNING: too big or negative step in advance."
				"Aborting" << std::endl;
		return (it);
	}
	for (unsigned i = 0; i < step; ++i)
	{
		if (it == list.end())
			throw (AdvanceConstIteratorException());
		++it;
	}
	return (it);
}

std::list<int>::iterator	PmergeMe::advance_back(\
		std::list<int> const & list, \
		std::list<int>::iterator it, unsigned step)
{
	if ((int)step < 0)
	{
		std::cerr << "WARNING: too big or negative step in "
				"advance back. Aborting" << std::endl;
		return (it);
	}
	for (unsigned i = 0; i < step; ++i)
	{
		if (it == list.begin())
			throw (AdvanceBackException());
		--it;
	}
	return (it);
}

void	PmergeMe::sort_nearby_pairs(std::list<int> & list, \
			unsigned int width, int & cmp_cnt)
{
	int N_of_pairs;
	std::list<int>::iterator	it_left_beg;
	std::list<int>::iterator	it_left_end;
	std::list<int>::iterator	it_right_beg;
	std::list<int>::iterator	it_right_end;

	it_left_beg = list.begin();
	N_of_pairs = (list.size() / width) >> 1;
	if (0 == N_of_pairs)
		return ;
	for (int i = 0; i < N_of_pairs; ++i)
	{
		if (0 != i)
			it_left_beg = advance(list, it_right_beg, width);
		it_left_end = advance(list, it_left_beg, width);
		it_right_beg = advance(list, it_left_beg, width);
		it_right_end = advance(list, it_right_beg, width);
		++cmp_cnt;
		if (*(--it_left_end) > *(--it_right_end))
		{
			swap(list, it_left_beg, ++it_left_end, \
				it_right_beg, ++it_right_end);
		}
	}
	return ;
}

// swaps [b1, e1) with [b2, e2)
void	PmergeMe::swap(std::list<int> & list, \
	std::list<int>::iterator left_beg,
	std::list<int>::iterator left_end,
	std::list<int>::iterator right_beg,
	std::list<int>::iterator right_end)
{
	for (; left_beg != left_end; ++left_beg, ++right_beg)
	{
		std::swap(*left_beg, *right_beg);
	}
	if (right_beg != right_end)
	{
		throw(SwapException());
	}
	(void)list;
}

void	PmergeMe::copy_elements(std::list<int> & to, \
		std::list<int> const & from, \
		std::list<int>::iterator beg,
		std::list<int>::iterator end)
{
	if (beg == end)
	{
		std::cout << "WARNING : copy_elements : size to : "
			<< to.size()
			<< " [" << *beg << ", " << *end << ")" << std::endl;
	}
	for (; beg != end; ++beg)
	{
		if (beg == from.end())
			throw (CopyElementsAdvanceException());
		to.push_back(*beg);
	}
}

void	PmergeMe::copy_elements(std::list<int> & to, \
		std::list<int> const & from, \
		std::list<int>::const_iterator beg,
		std::list<int>::const_iterator end)
{
	if (beg == end)
	{
		std::cout << "WARNING : copy_elements : size to : "
			<< to.size()
			<< " [" << *beg << ", " << *end << ")" << std::endl;
	}
	for (; beg != end; ++beg)
	{
		if (beg == from.end())
			throw (CopyElementsConstIteratorAdvanceException());
		to.push_back(*beg);
		std::cout << "    copied : " << *beg << std::endl;
	}
}

int	PmergeMe::is_sorted(std::list<int> const & list, unsigned int width)
{
	if ((list.size() / width) * width != list.size())
	{
		std::cerr << "Error : is_sorted list : " << list.size()
			<< ", " << width << std::endl;
		throw(BinarySearchException());
	}
	std::list<int>::const_iterator	it(list.begin());
	std::list<int>::const_iterator	it_next;

	if (list.end() == it)
		return (1);
	it = advance(list, it, width);
	if (list.end() == it)
		return (1);
	it_next = advance(list, it, width);
	for (unsigned i = 0; i + 1 < list.size() / width; ++i)
	{
		if (*(--it) > *(--it_next))
			return (0);
		++it;
		if (i + 2 < list.size() / width)
		{
			it = advance(list, it, width);
			it_next = advance(list, it, width);
		}
	}
	return (1);
}

int	PmergeMe::get_val_list(std::list<int> const & list, \
		std::list<int>::iterator it, unsigned width)
{
	std::list<int>::iterator tmp_it;

	tmp_it = advance(list, it, width - 1);
	return (*tmp_it);
}

int	PmergeMe::get_val_list(std::list<int> const & list, \
			std::list<int>::const_iterator it, unsigned width)
{
	std::list<int>::const_iterator tmp_it;

	tmp_it = advance(list, it, width - 1);
	return (*tmp_it);
}

// [begin .. end)
std::list<int>::iterator	PmergeMe::find_pos_binary_search(int num, \
		std::list<int> const & list, \
		unsigned int width, \
		std::list<int>::iterator begin, \
		std::list<int>::iterator end, \
		int & cmp_cnt)
{
	unsigned int			distance;
	std::list<int>::iterator	pos;
	std::list<int>::iterator	middle;
	int			val_middle;

	distance = std::distance(begin, end);
	if ((distance / width) * width != distance)
	{
		std::cerr << "Error : binary search, not dividable: "
			<< "; width : " << width
			<< "[" << *begin 
			<< ", " << *(--end) << ")" << std::endl;
		++end;
		throw (BinarySearchException());
	}
	if (0 == is_sorted(list, width))
	{
		std::cerr << "Error: not sorted, width: " << width << "list: "; 
		display_list(list);
		throw(NotSortedException());
	}
	if (begin == end)
	{
		return (begin);
	}
	
	middle = advance(list, begin, ((distance / width) / 2) * width);
	val_middle = get_val_list(list, middle, width);

	++cmp_cnt;
	if (num < val_middle)
		pos = find_pos_binary_search(num, list, width, \
					begin, middle, cmp_cnt);
	else if (num > val_middle)
	{
		pos = find_pos_binary_search(num, list, width, \
				advance(list, middle, width), end, cmp_cnt);
	}
	else
	{
		pos = middle;
	}
	return (pos);
}

// mt_cnt : main thread count
// cons_cnt: consequent count in main thread
void	PmergeMe::merge_threads(std::list<int> & list, unsigned int width, \
						int & cmp_cnt)
{
	int		N_of_elem;
	int		cons_cnt;
	int		mt_cnt;
	int		i;
	std::list<int>	main_thread;
	std::list<int>	other_thread;
	std::list<std::list<int>::iterator>	addresses;
	int		num;
	std::list<int>::iterator	pos;
	std::list<int>::iterator	it_beg;
	std::list<int>::iterator	it_end;
	std::list<int>::iterator	it_main_thread;

	N_of_elem = list.size() / width;
	if (N_of_elem <= 2)
	{
		return ;
	}
	cons_cnt = 1;
	mt_cnt = 3;
	it_beg = list.begin();
	if (it_beg != list.end())
		it_end = advance(list, it_beg, cons_cnt * width);
	else
		std::cout << "Error: move in the end?0" << std::endl;
	copy_elements(main_thread, list, it_beg, it_end);
	for (; main_thread.size() / width < list.size() / width;)
	{
		if (0 != other_thread.size() || 0 != addresses.size())
		{
			std::cerr << "Error: not empty other_thread,addresses";
			display_list(other_thread);
			display_list(addresses, main_thread);
			other_thread.clear();
			addresses.clear();
		}
		it_main_thread = advance_back(main_thread, main_thread.end(), width);
		it_beg = it_end;
		if (it_beg != list.end())
			it_end = advance(list, it_beg, width);
		else
			std::cout << "Err:How you move in the end?1" << std::endl;
		copy_elements(main_thread, list, it_beg, it_end);
		if (it_main_thread != main_thread.end())
		{
			it_main_thread = advance(main_thread, \
					it_main_thread, width);
		}
		else
		{
			std::cout << "ERROR: Again moving forward" << std::endl;
		}
		for (i = 0; \
			i + 1 < mt_cnt - cons_cnt && \
			(cons_cnt + 2 * (i + 1) + 1) * width <= list.size(); \
			++i)
		{
			it_beg = it_end;
			if (it_beg != list.end())
				it_end = advance(list, it_beg, width);
			else
			{
				std::cout << "ERROR: Not good to walk "
					"in the end" << std::endl;
			}
			copy_elements(other_thread, list, it_beg, it_end);
			it_beg = it_end;
			if (it_beg != list.end())
				it_end = advance(list, it_beg, width);
			else
				std::cout << "Error: Nice move" << std::endl;
			copy_elements(main_thread, list, it_beg, it_end);
			if (main_thread.end() == it_main_thread)
				std::cout << "Error: could not happen";
			it_main_thread = advance(main_thread, \
					it_main_thread, width);
			addresses.push_back(it_main_thread);
		}
		if ((cons_cnt + 2 * i + 2) * width <= list.size())
		{
			it_beg = it_end;
			if (it_beg != list.end())
				it_end = advance(list, it_beg, width);
			else
				std::cout << "Very nice move" << std::endl;
			copy_elements(other_thread, list, it_beg, it_end);
			addresses.push_back(main_thread.end());
		}
		while (other_thread.size() > 0)
		{
			num = other_thread.back();
			pos = find_pos_binary_search(num, main_thread, width, \
				main_thread.begin(), addresses.back(), cmp_cnt);
			addresses.pop_back();
			// updating addresses : not needed for lists
			main_thread.insert(pos, \
				advance_back(other_thread, \
					other_thread.end(), width), \
				other_thread.end());
			for (unsigned int j = 0; j < width; ++j)
				other_thread.pop_back();
		}
		// update mt_cnt, cons_cnt
		mt_cnt <<= 1;
		++mt_cnt;
		cons_cnt = mt_cnt - cons_cnt - 1;
	}
	// adding remaining elements from list to main_thread, 
	// then reassigning main_thread to list
	main_thread.insert(main_thread.end(), \
		advance_back(list, list.end(), \
			(list.size() - main_thread.size())), \
		list.end());
	list = main_thread;
	return ;
}

void	PmergeMe::sort(std::list<int> & list, unsigned int width, \
						int & cmp_cnt)
{
	if (list.size() < (width << 1))
		return ;
	sort_nearby_pairs(list, width, cmp_cnt);

	sort(list, 2 * width, cmp_cnt);

	merge_threads(list, width, cmp_cnt);

	return ;
}
