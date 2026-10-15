#include <stdio.h>
#include <time.h>
#include <unistd.h>
#ifdef WIN32
#undef CONST
#include <windows.h>
#elif _POSIX_C_SOURCE >= 199309L
#include <time.h> // for nanosleep
#else
// #include <unistd.h> // for usleep
#endif

void Rte_Start(void);
void Rte_Stop(void);
void RegisterCallback(void (*func)(void), int time);
void sleep_ms(int milliseconds);

/**
 * @brief Cross-platform sleep function
 * @param milliseconds
 */
void sleep_ms(int milliseconds)
{
#ifdef WIN32
    Sleep(milliseconds);
#elif _POSIX_C_SOURCE >= 199309L
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000;
    nanosleep(&ts, NULL);
#else
    //     if (milliseconds >= 1000)
    //       sleep(milliseconds / 1000);
    //     usleep((milliseconds % 1000) * 1000);
#endif
}

typedef struct
{
    void (*func)(void);
    int cycleTime;
    int next;
} re_t;

#define numRe 2
re_t res[numRe];

static int index = 0;

// SWC Runnable configuration
void RegisterCallback(void (*func)(void), int time)
{

    res[index].func = func;
    res[index].cycleTime = time;
    res[index].next = 0;

    index++;
}

void Rte_Start(void)
{
    printf("Rte_Start\n");

    static int currentTime = 0;

    // call all periodic runnables
    while (1)
    {
        printf("TASK1 %d ", currentTime);

        int tillNext = 10000;

        for (int i = 0; i < numRe; i++)
        {
            // for (int i=0; i<1; i++) {
            if (currentTime == res[i].next)
            {

                (res[i].func)(); // actual call

                res[i].next = currentTime + res[i].cycleTime;
            }

            if (res[i].next - currentTime < tillNext)
                tillNext = res[i].next - currentTime;
        }

        sleep_ms(tillNext);
        currentTime += tillNext;
    }
}
void Rte_Stop(void)
{
    printf("Rte_Stop\n");
}

static void cbperiodic() {
    printf("Periodic time\n");
}

int main()
{

    RegisterCallback(&cbperiodic, 5);
    // Register Primary blade runnable
    //RegisterCallback(&R_Cyclic_10ms_SC_1431_VSS_Prim_XIX_Softwareblock_XIX_Driving_Blade_Primary, 10);
    Rte_Start();
    Rte_Stop();

    return 0;
}