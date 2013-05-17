#include <iostream>
#include <vector>
#include <algorithm>

int factorial(const int n){
	if (n == 1)
		return 1;
	return n * factorial(n-1);
}

bool more_than_3(double n)
{
	return n > 3;
}


/* increment() n'existe pas */
template< typename T > T increment_before( T & t )
{
	return increment(t);
}

template< typename T > 
T increment_after( T & t )
{
	T tmp = t;
	increment(t);
	return tmp;
}

int main(){
	std::cout << factorial(5) << std::endl;

        std::vector<double> v(4,0);
        v[0] = 0;
        v[1] = 6.4;
        v[2] = 2.1;
        v[3] = 5.7;
        //utilisation d'un predicat more_than_3
        std::vector<double>::iterator it = std::find_if(v.begin(), v.end(), more_than_3);
	for (; it != v.end(); it++) 
	{
		std::cout << *(it) << std::endl;	
	}
}

