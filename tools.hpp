// file: tools.hpp
// Author: Dr. Alice Fischer, UNH
// Edited by: Dr. Ted Markowitz, UNH
// Last update: 02/27/13

// ---------------------------------------------------------------------------
// Header file for the UNH ECECS Data Structures "tools" library.
// Local definitions and portability code.
// ---------------------------------------------------------------------------

#pragma once

// Please enter your own system type, name + UNH ID, class #, and semester.
// #define NAME    	"<Your name and UNH ID goes here>"
// #define CLASS   	"<Your course #, e.g., CS226 or CS620 goes here>"
// #define SEMESTER   	"<Semester, e.g., Spring 2013, goes here>"
#define NAME    	"Jake A. Cole ID: 000236138"
#define CLASS   	"CS226"
#define SEMESTER   	"Spring 2013"
#define UNIX

// Include all the standard C++ libs
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <random>
#include <algorithm>
#include <iterator>
#include <functional>
#include <limits>
#include <vector>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <stdexcept>	// standard exception handling

// and other standard C libs
#include <cstring>
#include <cstdio>      // for NULL
#include <cstdlib>     // for malloc() and calloc()
#include <cmath>
#include <ctime>
#include <cctype>      // for isspace() and isdigit()
#include <climits>     // for INT_MAX
#include <cfloat>      // for DOUBLE_MAX, etc.
#include <cstdarg>     // for functions with variable # of arguments
#include <cassert>

using namespace std;

// ---------------------------------------------------------------------------
// Macros for debugging.
// ---------------------------------------------------------------------------
#define DUMPp(p) "\n" << "    " #p " @ " << &p << "    value = " << p <<"    " #p " --> " << *p
#define DUMPv(k) "\n" << "    " #k " @ " << &k << "    value = " << k

// ---------------------------------------------------------------------------
// I/O Extension. ------------------------------------------------------------
// ---------------------------------------------------------------------------
istream&  flush( istream& is );        // Use: cin >> x >> flush;
ostream&  general( ostream& os );       // Use: cout << fixed << x << general << y;

// ---------------------------------------------------------------------------
// Routine screen and process management.-------------------------------------
// ---------------------------------------------------------------------------
void     fbanner( ostream& fout );
void     banner();
void     bye( void );
void     hold( void );
void     say( const char* format, ... );
void     delay( int );

// ---------------------------------------------------------------------------
// Error handling. -----------------------------------------------------------
// ---------------------------------------------------------------------------
void    fatal( const char* format, ... );
void    cleanline( istream ff );

// ---------------------------------------------------------------------------
// time and date. -------------------------------------------------------------
// ---------------------------------------------------------------------------
void   	when( char* date, char* hour );
char*  	today( char* date );
char*  	oclock( char* hour );

// ---------------------------------------------------------------------------
// Menu handling.
// ---------------------------------------------------------------------------
int	menu( char* title, int n, const char* menu[] );
char    menu_c( char* title, int n, const char* menu[], char* valid );

// ---------------------------------------------------------------------------
// Miscellaneous utility routines
// ---------------------------------------------------------------------------

