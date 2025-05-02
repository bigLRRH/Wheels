#include <iostream>
#include <filesystem>
#include <thread>
#include <chrono>
#include <string>

int main()
{
    long long i(0ll);
    int grow(1);
    std::chrono::seconds _1s(1); // 1秒
    while (true)
    {
        std::cout << ".\n";
        for (long long j = 0ll; j < grow; ++j)
        {
            std::filesystem::create_directory("boom" + std::to_string(i));
            ++i;
        }
        ++grow;
        std::this_thread::sleep_for(_1s);
    }
}