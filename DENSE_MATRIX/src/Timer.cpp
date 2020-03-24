#include "Timer.hpp"

void Timer::Stop()
{
  auto endTimePoint = std::chrono::high_resolution_clock::now();
  
  auto start = 
  std::chrono::time_point_cast<std::chrono::microseconds>(m_StartTimepoint).time_since_epoch().count();
  auto end = 
  std::chrono::time_point_cast<std::chrono::microseconds>(endTimePoint).time_since_epoch().count();
  auto duration = (end - start);
  double ms = duration*0.001;
  printf("Time Measured: %.6f microsecs \n", ms);
}
