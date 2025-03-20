#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include <stdbool.h>

#define SAMPLE_RATE 44100
#define FREQ 300
#define AMPLITUDE 32767
#define BUFFER_SIZE 1024

typedef short buf_t;
#define BUFFER_BYTES (1024 * sizeof(buf_t))


void generate(buf_t* buffer)
{
    static double phase = 0.0;

    double plank_phase = (double)FREQ / SAMPLE_RATE;

    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        buffer[i] = (buf_t)(AMPLITUDE * sin(2.0 * M_PI * phase));
        phase += plank_phase;
        if (phase >= 1.0) phase = 0.0;
    }
}


int main()
{
    buf_t buffer[BUFFER_SIZE];
    while (true)
    {
        generate(buffer);
        write(STDOUT_FILENO, buffer, BUFFER_BYTES);
    }
}
