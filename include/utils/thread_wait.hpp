#ifndef UTILS_THREAD_WAIT_HPP
#define UTILS_THREAD_WAIT_HPP

#include <ratio>
#include <chrono>

/**
 * @brief Class to handle Thread wait occurrences.
 */
class ThreadWait {
private:
	const int _microseconds = 1e6;
	std::chrono::steady_clock::time_point _start_time;
	std::chrono::duration<long long, std::micro> _duration;
public:
    /**
     * @brief Constructor.
     * @param fps Integer value used in calculating the duration of the wait.
     */
	ThreadWait(int fps = 60) :

		_start_time(std::chrono::steady_clock::now()),
		_duration(std::chrono::duration<long long, std::micro>(_microseconds /fps))
	{}

    /**
     * @brief The wait method of the Thread.
     */
    void wait() const
	{
		bool wait = true;
		while (wait)
		{
			std::chrono::steady_clock::time_point now = std::chrono::steady_clock::now();
			const auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(now - _start_time);

			if (elapsed.count() > _duration.count())
				wait = false;
		}
	}
};

#endif // UTILS_THREAD_WAIT_HPP