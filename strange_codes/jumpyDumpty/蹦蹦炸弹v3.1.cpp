#include <iostream>
#include <filesystem>
#include <thread>
#include <array>
#include <chrono>
#include <format>
using namespace std;
void boom(int n)
{
    auto t = chrono::system_clock::now();
    while (true)
    {
        cout << ".\n";
        filesystem::create_directory(format("boom{}{}", n, t.time_since_epoch().count()));
    }
}
int main()
{
    array<thread, 4> threads;
    for (int i = 0; i < threads.size(); ++i)
    {
        threads[i] = thread(boom, i);
        threads[i].join();
    }
    //
    return 0;
}