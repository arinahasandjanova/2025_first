#include <iostream>
#include <chrono>

int main(){

    int n, a, x, b, y;
    std::cin >> n >> a >> x >> b >> y;

    auto start = std::chrono::high_resolution_clock::now();

    if (x < y) {
        std::swap(a, b);    //наибольшее значение будет у а
        std::swap(x, y);
    }

    int alight = x * 2 + 1;
    int blight = y * 2 + 1;

    if(n > a*alight + b*blight){
        std::cout << "-1";
    } else {

        int covered = 0;

        while (covered < n) {
            int next = covered + 1; 
            int pos = -1, r = -1;

            if (a > 0) {
                pos = next + x;
                if (pos > n) pos = n;
                r = x;
                a--;
            }
            else if (b > 0) {
                pos = next + y;
                if (pos > n) pos = n;
                r = y;
                b--;
            }

            std::cout << pos << " " << r << std::endl;
            covered = pos + r;
        }
    }

    auto end = std::chrono::high_resolution_clock::now();  
    std::chrono::duration<double> diff = end - start;       

    std::cout << "\n" << diff.count();

    return 0;
}