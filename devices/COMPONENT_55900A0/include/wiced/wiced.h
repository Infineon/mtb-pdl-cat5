/*
 * $ Copyright 2016-YEAR Cypress Semiconductor $
 */
#pragma once

#include "wiced_data_types.h"
#include "wiced_result.h"
#include "stdint.h"

#define WICED_SUPPRESS_WARNINGS(m) if((m)){;}

/* Suppress unused variable warning */
#ifndef UNUSED_VARIABLE
#define UNUSED_VARIABLE(x) /*@-noeffect@*/ ( (void)(x) ) /*@+noeffect@*/
#endif

typedef unsigned int   wiced_bool_t;

#define WICED_FALSE 0
#define WICED_TRUE  1

#define WPRINT_BT_APP_INFO(info)   {printf info;}
