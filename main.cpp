#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <fstream>

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

void insert(std::vector<double> & v, int & length)
{
    for (int j = 1; j <= length; ++j )
        {
            double key = v[j];
            int i = j - 1;
            while (i >= 0 and v[i]>key)
                {
                    v[i + 1] = v[i];
                    i = i - 1;
                }
            v[i + 1] = key;
        }
}

void insertion_sort(std::vector<double> & v)
{
    for (int i = 1; i < v.size(); ++i)
        {
            insert(v, i);
        }
}

std::vector<double> quick_sort(std::vector<double> & v)
{
    if (v.empty())
        {
            return v;
        }
    else
        {
            double pivot = v[0];
            std::vector<double> inf, sup;
            for (int i = 1; i < v.size(); ++i)
                {
                    if (v[i] <= pivot)
                        {
                            inf.push_back(v[i]);
                        }
                    else
                        {
                            sup.push_back(v[i]);
                        }
                }
            inf = quick_sort(inf);
            sup = quick_sort(sup);
            inf.push_back(pivot);
            inf.insert(inf.end(), sup.begin(), sup.end());
            return inf;
        }
}

void hanoi(int n, std::vector<int> & d, std::vector<int> & b, std::vector<int> & i)
{
    if (n == 1)
        {
            b.push_back(d[0]);
            d.erase(d.begin());
        }
    else
        {
            hanoi(n-1, d, i, b);
            hanoi(1, d, b, i);
            hanoi(n-1, i, b, d);
        }
}

int main(int argc, char** argv){
    std::cout << factorial(5) << std::endl;

    std::vector<double> v(5,0);
    v[0] = 0;
    v[1] = 6.4;
    v[2] = 2.1;
    v[3] = 5.7;
    v[4] = -1;
    //utilisation d'un predicat more_than_3
    more_than_u more_than = more_than_u(std::atof(argv[1]));
    //Std::vector<double>::iterator it = std::find_if(v.begin(), v.end(), more_than_u(std::atof(argv[1])));
    std::vector<double>::iterator it = std::find_if(v.begin(), v.end(), more_than);



    //Pourquoi boucle infinie de merde? Pourquoi la condition d'arrêt n'arrive jamais?
    std::cout << "for" << std::endl;
    for (it = v.begin(); it != v.end(); ++it)
        {
            it = std::find_if(it, v.end(), more_than);
            if (it == v.end()) {break;}
            std::cout << "for :" << *(it) << "\n";
        }

    std::cout << "while" << std::endl;
    it = v.begin();
    while (it != v.end())
	{
            it = std::find_if(it, v.end(), more_than);
            if (it == v.end()) {break;}
            std::cout <<  *(it) << "\n";
            ++it;
	}

    std::cout << "quick sort \n";
    std::vector<double> sorted_v = quick_sort(v);
    //    std::copy(v.begin(), v.end(), std::ofstream_iterator<double>(std::cout,";"));
    for (int i = 0; i < sorted_v.size(); ++i)
        {
            std::cout << sorted_v[i] << "\n";
        }

    std::cout << "insertion sort \n";
    insertion_sort(v);
    //    std::copy(v.begin(), v.end(), std::ofstream_iterator<double>(std::cout,";"));
    for (int i = 0; i < v.size(); ++i)
        {
            std::cout << v[i] << "\n";
        }

    std::vector<int> d;
    d.push_back(1);
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);

    std::vector<int> b, i;
    hanoi(4, d, b, i);
    for (int i = 0; i < b.size(); ++i)
        {
            std::cout << "D(" << i << ") " << d[i] << "   B(" << i << ") " << b[i] << "\n";
        }


}
