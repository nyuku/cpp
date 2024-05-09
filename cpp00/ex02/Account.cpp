/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angela <angela@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 22:58:39 by angnguye          #+#    #+#             */
/*   Updated: 2024/05/09 23:10:34 by angela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>
# include <ctime>
# include "Account.hpp"

#define CYAN			"\033[0;36m"
#define LIGHTPURPLE		"\033[1;35m"
#define LIGHT_LILAC		"\033[1;34m"
#define RESET_COLOR 	"\033[0m"
#define PEACH			"\033[0;93m"
#define LIGHT_RED       "\033[0;91m"
#define BLUE			"\033[0;34m"
#define SOFT_GREEN      "\033[0;92m"

//init des infos STATIC general en dehors de la classe
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//---------------------------- CONSTRUCTOR - DESTRUCTOR ----------------------------
//	Account( int initial_deposit );
//	~Account( void );
	
//render:
	//[19920104_091532] index:0;amount:42;created
//variables:
	// int				_amount;
	// int				_accountIndex;
	// int				_nbDeposits;
	// int				_nbWithdrawals;
Account::Account( int initial_deposit ) : _amount(initial_deposit)//++total amount, ++ nbAccount
{
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout <<SOFT_GREEN<< "index:" << _accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std:: cout << "created" <<RESET_COLOR<< std::endl;
	// ++ static
	_totalAmount+=initial_deposit;
	_nbAccounts++;
}
//render : [19920104_091532] index:0;amount:47;closed
Account::~Account( void )
{
	_displayTimestamp();
	std::cout <<SOFT_GREEN << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" <<RESET_COLOR<< std::endl;
}

//---------------------------------- GETTERS -------------------------------------------
// static int	getNbAccounts( void );
// static int	getTotalAmount( void );
// static int	getNbDeposits( void );
// static int	getNbWithdrawals( void );
int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

//----------------------------------- PRINT - DISPLAY----------------------------------
// static void	displayAccountsInfos( void );
// void	displayStatus( void ) const;

//RENDER general, variable static
//	[19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout <<CYAN<< "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << RESET_COLOR<<std::endl;
}
//Render pour un account, variable privé: 
//	[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout <<LIGHTPURPLE<< "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals <<RESET_COLOR<< std::endl;
}



//----------------------------------- PRINT - Update----------------------------------
// void	makeDeposit( int deposit );
// bool	makeWithdrawal( int withdrawal );

// Render:
//	[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
void	Account::makeDeposit( int deposit )//++ amoubt, ++totalAmoubt, ++nbDeposit, ++ totalNbDeposit 
{
	_displayTimestamp();
	std::cout <<LIGHT_LILAC<< "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";";
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits <<RESET_COLOR<< std::endl;
}
// Render:
//	[19920104_091532] index:0;p_amount:47;withdrawal:refused
// 	[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout <<LIGHT_LILAC<< "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:"<< RESET_COLOR;
	
	if (_amount < withdrawal)
	{
		std::cout <<LIGHT_RED<< "refused" << RESET_COLOR <<std::endl;
		return (false);
	}
	
	std::cout <<LIGHT_LILAC<< withdrawal << ";";
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << _amount << ";";
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << _nbWithdrawals<< RESET_COLOR << std::endl;
	return (true);
}
//-------------------------------------- FONCTION static--------------------------------------
// static void	_displayTimestamp( void );
// format: [19920104_091532]
// [year/month/day __ hour/min/sec]

void Account::_displayTimestamp(void)
{
	const time_t	now = time(0);//temps actuel en secondes
	tm				*ltm = localtime(&now);//struct qui contient le temps décomposé

	std::cout << "[";
    std::cout << 1900 + ltm->tm_year; //commence a 0 en 1900, 2024 = 124
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mon + 1; // +1 ,janvier = 0;
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_mday;
    std::cout << "_";
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_hour;
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_min;
    std::cout << std::setfill('0') << std::setw(2) << ltm->tm_sec;
    std::cout << "] ";
}
//-------------------------------------- FONCTION membre--------------------------------------

// int	checkAmount( void ) const;

int		Account::checkAmount( void ) const
{
	return (_amount);
}
