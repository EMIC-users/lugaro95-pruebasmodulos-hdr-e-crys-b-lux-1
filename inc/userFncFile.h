#ifndef USERFNCFILE_H
#define USERFNCFILE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// includes type definitions
#include "streamIn.h"
#include "streamOut.h"

/* Function Prototypes */
void onReset();
void emicFBe(char* TAG, const streamIn_t* const Message);

#endif /* USERFNCFILE_H */

