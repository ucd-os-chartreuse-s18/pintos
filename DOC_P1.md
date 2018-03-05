

						+--------------------+  
						| PROJECT 1: THREADS |  
						|   DESIGN DOCUMENT  |  
						+--------------------+

**---- GROUP ----**  

Matthew Moltzau <matthew.moltzau@ucdenver.edu>  
Michael Hedrick <michael.hedrick@ucdenver.edu>

----------------------------------------------------------
## ALARM CLOCK

**---- DATA STRUCTURES ----**

##### A1: Copy here the declaration of each new or changed _struct_ or _struct_ member, global or static variable, _typedef_, or enumeration.  Identify the purpose of each in 25 words or less.

```c
/* The thread list holds threads that have called thread_sleep.
 * It is a global variable in timer.c.
 * */
struct list waiting_thread_list;

/* waiting_elem is the corresponding list element variable for
 * the waiting_thread_list. It is a member of thread.
 */
struct list_elem waiting_elem;

/* The thread_sema gets downed in thread_sleep, and gets upped
 * by timer.c's timer_interrupt method once the thread no longer
 * needs to be sleeping.
 */
struct semaphore thread_sema;


/* This is the value that the timer_interrupt checks against to
 * see if a thread needs to get woken up. TODO it should be used
 * to sort the waiting_thread_list.
 */
int64_t thread_wake_tick;
```

**---- ALGORITHMS ----**

##### A2: Briefly describe what happens in a call to timer_sleep(), including the effects of the timer interrupt handler.

In a call to timer sleep, the waking time of the
thread is calculated and stored in the current
thread, the thread is pushed into the waiting list,
and its semaphore is downed.

The `timer_interrupt()` method ups the semaphore
once the appropriate time has passed.

##### A3: What steps are taken to minimize the amount of time spent in the timer interrupt handler?

Those steps weren't taken. We could insert into the
list using `list_insert_ordered` (we would need a
new comparator function), and then return
once we passed a single thread that didn't need to
wake up.

**---- SYNCHRONIZATION ----**

##### A4: How are race conditions avoided when multiple threads call timer_sleep() simultaneously?

Interrupts are disabled when inserting into the `waiting_thread_list`.

##### A5: How are race conditions avoided when a timer interrupt occurs during a call to timer_sleep()?

The above solution should be sufficient for both cases. We never had
a problem with this at least.

**---- RATIONALE ----**

##### A6: Why did you choose this design?  In what ways is it superior to another design you considered?

We were just trying to get it working. There was no alternate design
that we had considered, but then discarded because the current design
was superior. (we can change this though)

----------------------------------------------------------
## PRIORITY SCHEDULING

**---- DATA STRUCTURES ----**

##### B1: Copy here the declaration of each new or changed _struct_ or _struct_ member, global or static variable, _typedef_, or enumeration.  Identify the purpose of each in 25 words or less.

```c
/* Each thread now has a list of donators that it will use to
 * determine its effective priority.
 */
struct list donators;

/* donor_elem is the corresponding list element variable for
 * the donators list. It is a member of thread.
 */
struct list_elem donor_elem;
```

##### B2: Explain the data structure used to track priority donation. Use ASCII art to diagram a nested donation.  (Alternately, submit a .png file.)

png

**---- ALGORITHMS ----**

##### B3: How do you ensure that the highest priority thread waiting for a lock, semaphore, or condition variable wakes up first?

We call `get_effective_priority()` on a thread, which will recursively
call that function until a found thread has no donators (base case).

The other case occurs when there are donators and for that we peek at
the front of the list to get the thread with the highest effective priority. It is expected that the list is sorted by effective priority.

Specifically, the `waiters` list of a semaphore is sorted
. Locks hold semaphores, so they have the same
ability.

##### B4: Describe the sequence of events when a call to lock_acquire() causes a priority donation.  How is nested donation handled?

If a thread fails in acquiring a lock, it will get added as a
donor to the holder of the lock's `donators` list.

At the same time, it will get added to the lock's waiting list
(via `sema_down()`).

After the thread is woken up by `sema_up()` (when the lock was
released), we transfer the waiters on the locks to the new
thread's `donators` list.

Nested donation:  
LOW acquires lock a  
MED donates to LOW for a  
MED acquires lock b  
HIGH donates to MED for b  
Nested donation is handled because...

##### B5: Describe the sequence of events when lock_release() is called on a lock that a higher-priority thread is waiting for.

On release, the waiters of the lock are removed as donators to
the current thread (these get picked back up in lock aquire
after `sema_down()` gets upped again) and the lock holder is
set to `NULL`. The semaphore is upped at _this_ point, and if
the thread no longer has the highest priority, becomes preempted.

**---- SYNCHRONIZATION ----**

##### B6: Describe a potential race in thread_set_priority() and explain how your implementation avoids it.  Can you use a lock to avoid this race?

I had not thought about a race condition in `thread_set_priority()`. A
lock would probably be helpful to avoid race conditions.

//TODO surround with interrupt disables? Would that be sufficient?

**---- RATIONALE ----**

##### B7: Why did you choose this design?  In what ways is it superior to another design you considered?

create 2 png images with my own scenario

----------------------------------------------------------
## ADVANCED SCHEDULER	  

**---- DATA STRUCTURES ----**

##### C1: Copy here the declaration of each new or changed _struct_ or _struct_ member, global or static variable, _typedef_, or enumeration.  Identify the purpose of each in 25 words or less.

```c
//TODO put code stuff here
```

**---- ALGORITHMS ----**

##### C2: Suppose threads A, B, and C have nice values 0, 1, and 2.  Each has a recent_cpu value of 0.  Fill in the table below showing the scheduling decision and the priority and recent_cpu values for each thread after each given number of timer ticks:

timer  recent_cpu    priority   thread
ticks   A   B   C   A   B   C   to run
-----  --  --  --  --  --  --   ------
 0
 4
 8
12
16
20
24
28
32
36

##### C3: Did any ambiguities in the scheduler specification make values in the table uncertain?  If so, what rule did you use to resolve them?  Does this match the behavior of your scheduler?

//TODO

##### C4: How is the way you divided the cost of scheduling between code inside and outside interrupt context likely to affect performance?

interrupts should be as small as possible, otherwise it may cut into the
timeslice of the next one? IDK what I'm talking about 100%, this is Matt
and I didn't implement this part.

**---- RATIONALE ----**

##### C5: Briefly critique your design, pointing out advantages and disadvantages in your design choices.  If you were to have extra time to work on this part of the project, how might you choose to refine or improve your design?  

//TODO

##### C6: The assignment explains arithmetic for fixed-point math in detail, but it leaves it open to you to implement it.  Why did you decide to implement it the way you did?  If you created an abstraction layer for fixed-point math, that is, an abstract data type and/or a set of functions or macros to manipulate fixed-point numbers, why did you do so?  If not, why not?

We implemented fixed-point the way the pintos documentation went over it.
Overall, the level of abstraction made the code easier to work with and
more reliable than it would have been without. However, implementing
floating point math without a struct would have probably made it faster.

----------------------------------------------------------
All-in-one Reference for me of what we added to thread:  
There might be other things we need to consider (remove
when finished).
```c
struct thread:
	
	/* ALARM */
	+ int64_t thread_wake_tick;
	+ struct list_elem waiting_elem;
	+ struct semaphore thread_sema;
	
	/* PRIORITY */
	+ struct list donators;
	+ struct list_elem donor_elem;
  
	/* MLFQs */
	+ int niceness;
	+ fixed_point recent_cpu;
	
```
