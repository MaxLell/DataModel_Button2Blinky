#include "custom_assert.h"
// #include <iostream>
// #include <stdexcept>
// #include <cstdlib>

void assert_failed(const char *condition, const char *file, int line)
{
    // std::cerr << "\n\n"
    //           << "┌────────────────────────────────────────────────────────┐\n"
    //           << "│                                                        │\n"
    //           << "│                     ASSERT FAILED                      │\n"
    //           << "│                                                        │\n"
    //           << "└────────────────────────────────────────────────────────┘\n\n"
    //           << "----> Condition: (" << condition << ")\n\n"
    //           << "----> File: " << file << ":" << line << "\n"
    //           << std::endl;

    asm volatile("BKPT #0"); // Trigger a breakpoint
    
    while (true)
    {
        // Infinite loop to halt execution
    }
}
