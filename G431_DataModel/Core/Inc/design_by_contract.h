#pragma once
#include "custom_assert.h"

/**
 * @brief Postcondition condition which needs to be true after the function is called.
 * @param condition The condition to check
 */
#define POSTCONDITION(condition)                           \
    do                                                     \
    {                                                      \
        if (!(condition))                                  \
        {                                                  \
            assert_failed(#condition, __FILE__, __LINE__); \
        }                                                  \
    } while (false)

/**
 * @brief Invariant condition which needs to be true during the execution of the program.
 * @param condition The condition to check
 */
#define INVARIANT(condition)                               \
    do                                                     \
    {                                                      \
        if (!(condition))                                  \
        {                                                  \
            assert_failed(#condition, __FILE__, __LINE__); \
        }                                                  \
    } while (false)

/**
 * @brief Precondition condition which needs to be true before the function is called.
 * @param condition The condition to check
 */
#define PRECONDITION(condition)                            \
    do                                                     \
    {                                                      \
        if (!(condition))                                  \
        {                                                  \
            assert_failed(#condition, __FILE__, __LINE__); \
        }                                                  \
    } while (false)
