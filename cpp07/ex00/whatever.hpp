// ╔──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╗
// 		 Templates
//		 ✩ swap: Swaps the values of two given arguments. Does not return anything ->&
//       ✩ min:  Compares the two values, returns the smallest
//              If they are equal, returns the second one.
//       ✩ max: Compares the two values, returns the greatest one.
//              If they are equal, returns the second one.
//       ✩ can be called with any type of argument
//       ✩ must support all the comparison operators
//       ✩ Templates must be defined in the header files
// ╚──────────────────────────────────────────────¤◎¤──────────────────────────────────────────────╝

#ifndef WHATEVER_HPP
# define WHATEVER_HPP
#define RESET_COLOR		"\033[0m"
#define GREEN			"\033[0;92m"
#define LIGHT_GREEN		"\033[1;32m"
#define LIGHTPURPLE		"\033[1;35m"
#define BLUE            "\033[1;34m"
#define LIGHT_MAGENTA	"\033[0;95m"
#define CYAN	        "\033[1;36m"
#define MAGENTA		  	"\033[0;35m"
#define LILAC		   	"\033[0;94m"
#define LIGHT_BLUE		"\033[0;34m"
#define LIGHT_TURCOI    "\033[0;36m"
#define LIGHT_RED	  	"\033[0;91m"
#define SOFT_GREEN		"\033[0;32m"
#define DARK_BLUE	    "\033[0;94m"
#define PEACH		    "\033[0;93m"
#define LIGHT_CYAN      "\033[0;36m"
#define BOLD		    "\033[1m"
#define ENDL            std::endl

template< typename T >
void	swap(T &x, T &y)
{
	T	temp = x;
	x = y;
	y = temp;
}

template< typename T >
T	const & max(T const &x, T const &y)
{
	if (x > y)
		return (x);
	return (y);
}

template< typename T >
T	const & min(T const &x, T const &y)
{
	if (x < y)
		return (x);
	return (y);
}
#endif