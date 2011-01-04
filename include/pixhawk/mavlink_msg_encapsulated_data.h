// MESSAGE ENCAPSULATED_DATA PACKING

#define MAVLINK_MSG_ID_ENCAPSULATED_DATA 171

typedef struct __mavlink_encapsulated_data_t 
{
	uint16_t seqnr; ///< sequence number (starting with 0 on every transmission)
	uint8_t data[253]; ///< image data bytes

} mavlink_encapsulated_data_t;

#define MAVLINK_MSG_ENCAPSULATED_DATA_FIELD_DATA_LEN 253


/**
 * @brief Send a encapsulated_data message
 *
 * @param seqnr sequence number (starting with 0 on every transmission)
 * @param data image data bytes
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_encapsulated_data_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, uint16_t seqnr, const uint8_t* data)
{
	uint16_t i = 0;
	msg->msgid = MAVLINK_MSG_ID_ENCAPSULATED_DATA;

	i += put_uint16_t_by_index(seqnr, i, msg->payload); //sequence number (starting with 0 on every transmission)
	i += put_array_by_index((int8_t*)data, sizeof(uint8_t)*253, i, msg->payload); //image data bytes

	return mavlink_finalize_message(msg, system_id, component_id, i);
}

static inline uint16_t mavlink_msg_encapsulated_data_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_encapsulated_data_t* encapsulated_data)
{
	return mavlink_msg_encapsulated_data_pack(system_id, component_id, msg, encapsulated_data->seqnr, encapsulated_data->data);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_encapsulated_data_send(mavlink_channel_t chan, uint16_t seqnr, const uint8_t* data)
{
	mavlink_message_t msg;
	mavlink_msg_encapsulated_data_pack(mavlink_system.sysid, mavlink_system.compid, &msg, seqnr, data);
	mavlink_send_uart(chan, &msg);
}

#endif
// MESSAGE ENCAPSULATED_DATA UNPACKING

/**
 * @brief Get field seqnr from encapsulated_data message
 *
 * @return sequence number (starting with 0 on every transmission)
 */
static inline uint16_t mavlink_msg_encapsulated_data_get_seqnr(const mavlink_message_t* msg)
{
	generic_16bit r;
	r.b[1] = (msg->payload)[0];
	r.b[0] = (msg->payload)[1];
	return (uint16_t)r.s;
}

/**
 * @brief Get field data from encapsulated_data message
 *
 * @return image data bytes
 */
static inline uint16_t mavlink_msg_encapsulated_data_get_data(const mavlink_message_t* msg, uint8_t* r_data)
{

	memcpy(r_data, msg->payload+sizeof(uint16_t), sizeof(uint8_t)*253);
	return sizeof(uint8_t)*253;
}

static inline void mavlink_msg_encapsulated_data_decode(const mavlink_message_t* msg, mavlink_encapsulated_data_t* encapsulated_data)
{
	encapsulated_data->seqnr = mavlink_msg_encapsulated_data_get_seqnr(msg);
	mavlink_msg_encapsulated_data_get_data(msg, encapsulated_data->data);
}
