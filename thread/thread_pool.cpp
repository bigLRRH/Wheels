#include <iostream>
#include <thread>
#include <chrono>

void sleep(int seconds)
{
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

auto get_now()
{
    return std::chrono::high_resolution_clock::now();
}

int main()
{
    auto start = get_now();
    std::thread t1(
        [&]()
        {
            auto start_t1 = get_now();
            std::cout << "start_t1 - start" << std::chrono::duration<double, std::milli>(start_t1 - start).count() << std::endl;
            sleep(5);
            std::cout << "t1 sleep 5" << std::endl;
            auto end_t1 = get_now();
            std::cout << "end_t1 - start_t1:" << std::chrono::duration<double, std::milli>(end_t1 - start_t1).count() << std::endl;
            std::cout << "end_t1 - end_t1" << std::chrono::duration<double, std::milli>(end_t1 - end_t1).count() << std::endl;
        });
    std::thread t2(
        [&]()
        {
            auto start_t2 = get_now();
            std::cout << "start_t2 - start" << std::chrono::duration<double, std::milli>(start_t2 - start).count() << std::endl;
            sleep(7);
            std::cout << "t2 sleep 7" << std::endl;
            auto end_t2 = get_now();
            std::cout << "end_t2 - start_t2:" << std::chrono::duration<double, std::milli>(end_t2 - start_t2).count() << std::endl;
            std::cout << "end_t2 - end_t2" << std::chrono::duration<double, std::milli>(end_t2 - end_t2).count() << std::endl;
        });
    sleep(3);
    std::cout << "main sleep 3" << std::endl;
    std::cout << "main sleep 3 - start" << std::chrono::duration<double, std::milli>(get_now() - start).count() << std::endl;
    sleep(6);
    std::cout << "main sleep 9 = 3 + 6" << std::endl;
    std::cout << "main sleep 9 - start" << std::chrono::duration<double, std::milli>(get_now() - start).count() << std::endl;
    sleep(1);
    std::cout << "main sleep 10 = 9 + 1" << std::endl;
    std::cout << "main sleep 10 - start" << std::chrono::duration<double, std::milli>(get_now() - start).count() << std::endl;
    return 0;
}