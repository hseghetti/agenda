#ifndef _OPTIMIZE_H
#define _OPTIMEZE_H

#include <malloc.h>
#include "types.h"
#include "semantic.h"
#include "trees.h"

void optimizeTree ( Node * );
int  constantNode ( Node * );

#endif