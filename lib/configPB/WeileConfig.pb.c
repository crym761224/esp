/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.9.4 at Thu Dec 12 22:22:08 2019. */

#include "WeileConfig.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t WeileConfigMessage_fields[9] = {
    PB_FIELD(  1, UINT32  , SINGULAR, STATIC  , FIRST, WeileConfigMessage, jog_time, jog_time, 0),
    PB_FIELD(  2, UINT32  , SINGULAR, STATIC  , OTHER, WeileConfigMessage, start_interval, jog_time, 0),
    PB_FIELD(  3, UINT32  , SINGULAR, STATIC  , OTHER, WeileConfigMessage, weile_time, start_interval, 0),
    PB_FIELD(  4, UINT32  , SINGULAR, STATIC  , OTHER, WeileConfigMessage, screen_time, weile_time, 0),
    PB_FIELD(  5, UINT32  , SINGULAR, STATIC  , OTHER, WeileConfigMessage, close_power, screen_time, 0),
    PB_FIELD( 20, UINT32  , SINGULAR, STATIC  , OTHER, WeileConfigMessage, pin_rel, close_power, 0),
    PB_FIELD( 21, UINT32  , SINGULAR, STATIC  , OTHER, WeileConfigMessage, pin_led, pin_rel, 0),
    PB_FIELD( 22, UINT32  , SINGULAR, STATIC  , OTHER, WeileConfigMessage, pin_btn, pin_led, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
