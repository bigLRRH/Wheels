#include <iostream>
#include <chrono>

int main()
{

    {
        auto t1 = std::chrono::high_resolution_clock::now();

        double result = 0.0;

        auto t2 = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> ms = t2 - t1;
        std::cout << std::fixed << "result " << result
                  << " took " << ms.count() << " ms" << std::endl;
    }
}