#include<iostream>

using namespace std;

//백준 회문수 참고 

int main()
{

}

//Bessie and Elsie are playing a game with a pile of stones that initially contains S
//stones(1≤S < 10^10^5).The two cows alternate turns, with Bessie going first.When it is a cow's turn, she must remove x
//	stones from the pile, where x
//	is any positive integer palindrome of the cow's choosing. If the pile is empty when a cow's turn starts, that cow loses.
//
//	Definition: A positive integer is a palindrome if it reads the same forwardand backward; examples of palindromes include 1, 121, and 9009. Leading zeros are not allowed; e.g., 990 is * not*a palindrome.
//
//	There are T(1≤T≤10) independent test cases.For each test case, print who wins the game if both cows play optimally.
//
//	INPUT FORMAT(input arrives from the terminal / stdin):
//		The first line contains T, the number of test cases.The next T
//		lines describe the test cases, one line per test case.
//		Each test case is specified by a single integer S
//			.
//
//		OUTPUT FORMAT(print output to the terminal / stdout):
//		For each test case, output B if Bessie wins the game under optimal play starting with a pile of stones of size S
//		, or E otherwise, on a new line.
//		SAMPLE INPUT :
//		3
//		8
//		10
//		12
//		
//      SAMPLE OUTPUT :
//		B
//	    E
//	    B
//		
//      For the first test case, Bessie can remove all the stones on her first move, since 8
//		is a palindrome, guaranteeing her win.
//
//		For the second test case, 10
//		is not a palindrome, so Bessie cannot remove all the stones on her first move.Regardless of how many stones Bessie removes on her first move, Elsie can always remove all remaining stones on her second move, guaranteeing her win.
//
//		For the third test case, it can be proven that Bessie wins under optimal play.