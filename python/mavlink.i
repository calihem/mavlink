// partial python wrapper for mavlink library
%module mavlink

 // this goes into _wrap.c
%{
#define SWIG_FILE_WITH_INIT
#include "../include/huch/mavlink.h"
#include "mavlink-local.h"
%}

// this is advertised to the target language

// this could be used with swig  -I/usr/include -I/usr/include/linux -includeall
// but it produces errors

// #include "../include/huch/mavlink.h"
// #include "../include/protocol.h"
// #include "../include/mavlink_types.h"

// generic types
//typedef unsigned char uint8_t;
typedef signed short int16_t;
typedef int int32_t;


// %apply (char *STRING, int LENGTH) { (const void *, size_t)}
//%apply (char *STRING, int LENGTH) { (int8_t *, size_t)}

// mavlink types
//#include "../protocol.h"
#include "../mavlink_types.h"
#include "./mavlink_msg_huch_attitude.h"
#include "./mavlink_msg_huch_visual_navigation.h"
#include "./common/mavlink_msg_debug.h"
#include "./common/mavlink_msg_param_set.h"
// XXX: including protocol produces locale error
// #include "../include/protocol.h"
// #include "../include/huch/huch.h"

// typedef struct __mavlink_message {
// 	uint8_t len;     ///< Length of payload
// 	uint8_t seq;     ///< Sequence of packet
// 	uint8_t sysid;   ///< ID of message sender system/aircraft
// 	uint8_t compid;  ///< ID of the message sender component
// 	uint8_t msgid;   ///< ID of message in payload
// 	uint8_t payload[MAVLINK_MAX_PAYLOAD_LEN]; ///< Payload data, ALIGNMENT IMPORTANT ON MCU
// 	uint8_t ck_a;    ///< Checksum high byte
// 	uint8_t ck_b;    ///< Checksum low byte
// } mavlink_message_t;

// typedef struct __mavlink_status {
// 	uint8_t ck_a;                       ///< Checksum byte 1
// 	uint8_t ck_b;                       ///< Checksum byte 2
// 	uint8_t msg_received;               ///< Number of received messages
// 	uint8_t buffer_overrun;             ///< Number of buffer overruns
// 	uint8_t parse_error;                ///< Number of parse errors
// 	mavlink_parse_state_t parse_state;  ///< Parsing state machine
// 	uint8_t packet_idx;                 ///< Index in current packet
// 	uint8_t current_seq;                ///< Sequence number of last packet
// 	uint16_t packet_rx_success_count;   ///< Received packets
// 	uint16_t packet_rx_drop_count;      ///< Number of packet drops
// } mavlink_status_t;

// typedef struct __mavlink_huch_attitude_t 
// {
// 	int16_t xacc; ///< 
// 	int16_t yacc; ///< 
// 	int16_t zacc; ///< 
// 	int16_t zaccraw; ///< 
// 	int16_t xaccmean; ///< 
// 	int16_t yaccmean; ///< 
// 	int16_t zaccmean; ///< 
// 	int16_t xgyro; ///< 
// 	int16_t ygyro; ///< 
// 	int16_t zgyro; ///< 
// 	int32_t xgyroint; ///< 
// 	int32_t ygyroint; ///< 
// 	int32_t zgyroint; ///< 
// 	int16_t xmag; ///< 
// 	int16_t ymag; ///< 
// 	int16_t zmag; ///< 

// } mavlink_huch_attitude_t;

// custom functions
// mavlink_message_t* mavlink_message_from_data(mavlink_message_t* msg, char* data, int len);
void mavlink_message_from_data(mavlink_message_t* msg, char* data, int len);

// mavlink functions
static inline void mavlink_msg_huch_attitude_decode(const mavlink_message_t* msg, mavlink_huch_attitude_t* huch_attitude);
 
static inline uint8_t mavlink_parse_char(uint8_t chan, uint8_t c, mavlink_message_t* r_message, mavlink_status_t* r_mavlink_status);

// check param_set
void mavlink_param_set_param_id(mavlink_param_set_t* param, char* str);
char* mavlink_param_get_param_id(mavlink_param_set_t* param);

char* mavlink_msg_to_send_buffer_2(const mavlink_message_t* msg);
