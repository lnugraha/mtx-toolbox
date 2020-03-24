#ifndef TIMER_HPP_ 
#define TIMER_HPP_

#include <iostream>
#include <chrono>

class Timer{
  public:
	Timer(){
	  m_StartTimepoint = std::chrono::high_resolution_clock::now();
	};
	~Timer(){
	  Stop();
	};

	void Stop();

  private:
	std::chrono::time_point< std::chrono::high_resolution_clock > 
	m_StartTimepoint;
};

#endif
