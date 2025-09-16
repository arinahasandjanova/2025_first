#include <iostream>

int main(){
     long long a, b, c, d;
    std::cin >> a >> b >> c >> d;

    if (a > b) std::swap(a, b);
    if (b > c) std::swap(b, c);
    if (a > b) std::swap(a, b);

    long long k = abs(a + b - c);

    if(k <= d){
        std::cout << "0\n";
    } else {
        std::cout << k - d << std::endl;
    }

    return 0;
}