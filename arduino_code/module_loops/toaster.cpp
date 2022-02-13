#include <Arduino.h>
//global variables for toaster functions
typedef struct{
    unsigned int task_1ms : 1;
    unsigned int task_5ms : 1;
    unsigned int task_10ms : 1;
    unsigned int task_100ms : 1;
    unsigned int task_1000ms: 1;
  
}tasks_t;

tasks_t tasks;


unsigned int ms_count = 0; // count associated with 
void set_ms_flags(){
  ms_count++;
  if (ms_count % 1 == 0)
  {  
    tasks.task_1ms = 1;
  }
  if (ms_count % 5 == 0)
  {
    tasks.task_5ms = 1;
  }
  if (ms_count % 10 == 0)
  {
    tasks.task_10ms = 1;
  }
  if (ms_count % 100 == 0)
  {
    tasks.task_100ms = 1;
  }
  if (ms_count % 1000 == 0)
  {
    tasks.task_1000ms = 1;
    ms_count = 0;  
  }
}
