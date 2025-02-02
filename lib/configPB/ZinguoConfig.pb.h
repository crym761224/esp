/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.9.4 at Thu Dec 12 22:22:08 2019. */

#ifndef PB_ZINGUOCONFIG_PB_H_INCLUDED
#define PB_ZINGUOCONFIG_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _ZinguoConfigMessage {
    bool dual_motor;
    bool dual_warm;
    uint8_t delay_blow;
    uint8_t linkage;
    uint8_t max_temp;
    uint8_t close_warm;
    uint8_t close_ventilation;
    bool beep;
    bool reverse_led;
/* @@protoc_insertion_point(struct:ZinguoConfigMessage) */
} ZinguoConfigMessage;

/* Struct field encoding specification for nanopb */
extern const pb_field_t ZinguoConfigMessage_fields[10];

/* Maximum encoded size of messages (where known) */
#define ZinguoConfigMessage_size                 38

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define ZINGUOCONFIG_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
