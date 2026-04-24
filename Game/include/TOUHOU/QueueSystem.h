#pragma once
#include <queue>
#include <functional>

class QueueSystem
{
public:
    void Enqueue(std::function<void()> func)
    {
        queue.push(func);
    }

    void Flush()
    {
        while (!queue.empty())
        {
            queue.front()();
            queue.pop();
        }
    }

private:
    std::queue<std::function<void()>> queue;
};
