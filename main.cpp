#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

int factorial(const int n){
    if (n == 1)
        return 1;
    return n * factorial(n-1);
}

struct more_than_u
{
    double m_u;

    more_than_u(double const & u) :	m_u(u)
    {
        std::cout << "initialize more_than_u at " << u << "\n";
    }

    bool operator()(double n)
    {
        return n > m_u;
    }

};


/* increment(T & t) n'existe pas
 * A titre d'exemple pour comprendre l'intérêt de ++i par rapport à i++
 * Il est préférable de toujours utiliser ++i
 */
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

int main(int argc, char** argv){
    std::cout << factorial(5) << std::endl;

    std::vector<double> v(4,0);
    v[0] = 0;
    v[1] = 6.4;
    v[2] = 2.1;
    v[3] = 5.7;
    //utilisation d'un predicat more_than_3
    more_than_u more_than = more_than_u(std::atof(argv[1]));
    //    std::vector<double>::iterator it = std::find_if(v.begin(), v.end(), more_than_u(std::atof(argv[1])));
    std::vector<double>::iterator it = std::find_if(v.begin(), v.end(), more_than);


    //Pourquoi boucle infinie de merde? Pourquoi la condition d'arrêt n'arrive jamais?
    for (; it != v.end(); ++it)
	{
            it = std::find_if(it, v.end(), more_than);
            std::cout << *(it) << "\n";
	}

    while (it != v.end())
	{
            std::cout <<  *(it) << "\n";
            it = std::find_if(++it, v.end(), more_than);
	}
}
