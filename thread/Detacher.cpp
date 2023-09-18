#include <thread>
#include <vector>

// https://medium.com/@vgasparyan1995/let-me-detach-those-threads-for-you-2de014b26394

class Detacher
{
public:
    template <typename Function, typename... Args>
    void createDetachedTask(Function &&func, Args &&...args)
    {
        m_threads.emplace_back(std::forward<Function>(func), std::forward<Args>(args)...);
    }

    Detacher() = default;
    Detacher(const Detacher &) = delete;
    Detacher &operator=(const Detacher &) = delete;
    Detacher(Detacher &&) = delete;
    Detacher &operator=(Detacher &&) = delete;

    ~Detacher()
    {
        for (auto &thread : m_threads)
            thread.join();
    }

private:
    std::vector<std::thread> m_threads;
};