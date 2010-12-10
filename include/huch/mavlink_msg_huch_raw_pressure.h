// MESSAGE HUCH_RAW_PRESSURE PACKING

#define MAVLINK_MSG_ID_HUCH_RAW_PRESSURE 109

typedef struct __mavlink_huch_raw_pressure_t 
{
	uint64_t usec; ///< timestamp in microseconds
	int32_t pressure; ///< pressure in pascal

} mavlink_huch_raw_pressure_t;



/**
 * @brief Send a huch_raw_pressure message
 *
 * @param usec timestamp in microseconds
 * @param pressure pressure in pascal
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_huch_raw_pressure_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint64_t usec, int32_t pressure)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_HUCH_RAW_PRESSURE;

	i += put_uint64_t_by_index(usec, i, msg->payload); //timestamp in microseconds
	i += put_int32_t_by_index(pressure, i, msg->payload); //pressure in pascal

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_huch_raw_pressure_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_huch_raw_pressure_t* huch_raw_pressure)
{
	return mavlink_msg_huch_raw_pressure_pack(system_id, component_id, msg, huch_raw_pressure->usec, huch_raw_pressure->pressure);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_huch_raw_pressure_send(mavlink_channel_t chan, uint64_t usec, int32_t pressure)
{
	mavlink_message_t msg;
	mavlink_msg_huch_raw_pressure_pack(mavlink_system.sysid, mavlink_system.compid, &msg, usec, pressure);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE HUCH_RAW_PRESSURE UNPACKING

/**
 * @brief Get field usec from huch_raw_pressure message
 *
 * @return timestamp in microseconds
 */
static inline uint64_t mavlink_msg_huch_raw_pressure_get_usec(const mavlink_message_t* msg)
{
	generic_64bit r;
	r.b[7] = (msg->payload)[0];
	r.b[6] = (msg->payload)[1];
	r.b[5] = (msg->payload)[2];
	r.b[4] = (msg->payload)[3];
	r.b[3] = (msg->payload)[4];
	r.b[2] = (msg->payload)[5];
	r.b[1] = (msg->payload)[6];
	r.b[0] = (msg->payload)[7];
	return (uint64_t)r.ll;
}

/**
 * @brief Get field pressure from huch_raw_pressure message
 *
 * @return pressure in pascal
 */
static inline int32_t mavlink_msg_huch_raw_pressure_get_pressure(const mavlink_message_t* msg)
{
	generic_32bit r;
	r.b[3] = (msg->payload+sizeof(uint64_t))[0];
	r.b[2] = (msg->payload+sizeof(uint64_t))[1];
	r.b[1] = (msg->payload+sizeof(uint64_t))[2];
	r.b[0] = (msg->payload+sizeof(uint64_t))[3];
	return (int32_t)r.i;
}

static inline void mavlink_msg_huch_raw_pressure_decode(const mavlink_message_t* msg, mavlink_huch_raw_pressure_t* huch_raw_pressure)
{
	huch_raw_pressure->usec = mavlink_msg_huch_raw_pressure_get_usec(msg);
	huch_raw_pressure->pressure = mavlink_msg_huch_raw_pressure_get_pressure(msg);
}
