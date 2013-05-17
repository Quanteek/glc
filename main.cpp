#include <iostream>

int factorial(const int n){
	if (n == 1)
		return 1;
	return n * factorial(n-1);
}

int main(){
	std::cout << factorial(5) << std::endl;

        std::vector<double> v(4,0);
        v[0] = 0;
        v[1] = 6.4;
        v[2] = 3.5;
        v[3] = 5.7;
        //utilisation d'un predicat more_than_3
        std::find_if(v.begin(), v.end(), );
}

