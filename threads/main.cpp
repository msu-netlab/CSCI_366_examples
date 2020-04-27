#include <iostream>
#include <thread>
#include <semaphore.h>
#include <sstream>
#include <mutex>
#include <inttypes.h>

/**
 * Threading examples:
 * 1. Start threads and wait for them to finish
 * 2. Solve stdout race conditions with a mutex
 * 3. Solve stdout race condition with printf
 * 4. Block on sleeping
 */


using namespace std;

/**
 * Examle 1: A thread function that sleeps for some amount of time
 * @param sleep_s
 */
void run_example1(int color){
   int sleep_s = 1;

   cout << "\033["<< color << "mThread " << this_thread::get_id() << " starting\033[0m" <<endl;

   for(int i=0; i<2; i++) {
      cout << "\033["<< color << "mThread " << this_thread::get_id() << " sleeping for " << sleep_s << " seconds\033[0m" << endl;
      std::this_thread::sleep_for(std::chrono::seconds(sleep_s));
   }

   cout << "\033["<< color << "mThread " << this_thread::get_id() << " exiting\033[0m" <<endl;
}

/**
 * Examle 2: A thread function that sleeps for some amount of time with synchronized output
 * @param sleep_s
 */
mutex mut;
void run_example2(int color){
   int sleep_s = 1;

   mut.lock();
   cout << "\033["<< color << "mThread " << this_thread::get_id() << " starting\033[0m" <<endl;
   mut.unlock();

   for(int i=0; i<2; i++) {
      mut.lock();
      cout << "\033["<< color << "mThread " << this_thread::get_id() << " sleeping for " << sleep_s << " seconds\033[0m" << endl;
      mut.unlock();
      std::this_thread::sleep_for(std::chrono::seconds(sleep_s));
   }

   mut.lock();
   cout << "\033["<< color << "mThread " << this_thread::get_id() << " exiting\033[0m" <<endl;
   mut.unlock();
}


/**
 * Examle 3: A thread function that sleeps for some amount of time with atomic output
 * @param sleep_s
 */
void run_example3(int color){
   int sleep_s = 1;

   // get thread id into a string and convert to an int
   std::stringstream ss;
   ss << std::this_thread::get_id();
   uint64_t id = std::stoull(ss.str());

   printf("\033[%dmThread %" PRIu64 " starting\033[0m\n", color, id);

   for(int i=0; i<2; i++) {
      printf("\033[%dmThread %" PRIu64 " sleeping for %d seconds\033[0m\n", color, id, sleep_s);
      std::this_thread::sleep_for(std::chrono::seconds(sleep_s));
   }

   printf("\033[%dmThread %" PRIu64 " exiting\033[0m\n", color, id);
}


/**
 * Examle 4: A thread function that blocks on sleeping
 * @param sleep_s
 */
void run_example4(int color, sem_t *sem){
   int sleep_s = 1;

   // get thread id into a string and convert to an int
   std::stringstream ss;
   ss << std::this_thread::get_id();
   uint64_t id = std::stoull(ss.str());

   printf("\033[%dmThread %" PRIu64 " starting\033[0m\n", color, id);

   // acquire the semaphore
   sem_wait(sem); // will proceed if can decrement the semaphore

   for(int i=0; i<2; i++) {
      printf("\033[%dmThread %" PRIu64 " sleeping for %d seconds\033[0m\n", color, id, sleep_s);
      std::this_thread::sleep_for(std::chrono::seconds(sleep_s));
   }

   // signal the semaphore
   sem_post(sem); // increment the semaphore for the other thread

   printf("\033[%dmThread %" PRIu64 " exiting\033[0m\n", color, id);
}

/**
 * Examle 5: A thread function using shared variables
 * @param sleep_s
 */
int global_var = 0; // create a global variable for sharing between threads - needs to be declared above its use in code
void run_example5(int color, sem_t *sem){
   int sleep_s = 1;

   static int static_var = 0; // create a static variable for sharing between threads
   int local_var = 0; // create a local variable for this thread

   // get thread id into a string and convert to an int
   std::stringstream ss;
   ss << std::this_thread::get_id();
   uint64_t id = std::stoull(ss.str());

   printf("\033[%dmThread %" PRIu64 " starting\033[0m\n", color, id);

   // acquire the semaphore
   sem_wait(sem); // will proceed if can decrement the semaphore

   for(int i=0; i<2; i++) {
      // increment variables and print out values
      global_var++;
      static_var++;
      local_var++;
      printf("\033[%dmThread %" PRIu64 " global_var=%d, static_var=%d, local_var=%d \033[0m\n", color, id, global_var, static_var, local_var);

      // sleep
      printf("\033[%dmThread %" PRIu64 " sleeping for %d seconds\033[0m\n", color, id, sleep_s);
      std::this_thread::sleep_for(std::chrono::seconds(sleep_s));
   }

   // signal the semaphore
   sem_post(sem); // increment the semaphore for the other thread

   printf("\033[%dmThread %" PRIu64 " exiting\033[0m\n", color, id);
}



int main() {

   thread threads[2]; //set up a pool of threads, so we can join them before exiting
   sem_t sem;         //set up a semaphore


   sem_init(&sem, 0, 1);

   // Example 1: start the threads with stdout race conditions
   printf("Starting threads\n");
   threads[0] = thread(run_example1, 31);
   threads[1] = thread(run_example1, 32);

//   // Example 2: start the threads with mutex control
//   printf("Starting threads\n");
//   threads[0] = thread(run_example2, 31);
//   threads[1] = thread(run_example2, 32);

//   // Example 3: start the threads with atomic print
//   printf("Starting threads\n");
//   threads[0] = thread(run_example3, 31);
//   threads[1] = thread(run_example3, 32);

//   // Example 4: start the threads with semaphore blocks
//   printf("Starting threads\n");
//   threads[0] = thread(run_example4, 31, &sem);
//   threads[1] = thread(run_example4, 32, &sem);

//   // Example 5: start the threads with shared variables
//   printf("Starting threads\n");
//   threads[0] = thread(run_example5, 31, &sem);
//   threads[1] = thread(run_example5, 32, &sem);

   // wait for the threads to finish
   for(int i=0; i<2; i++)
      threads[i].join();
   printf("Threads joined. Exiting.");

   return 0;
}
