#ifndef IP_MATHS_H
#define IP_MATHS_H

void get_broadcast_address(char *ip_addr, char mask, char *output_buffer);
unsigned int get_ip_integer_equivalent(char *ip_address);
void get_abcd_ip_format(unsigned int ip_address, char *output_buffer);
void get_network_id(char *ip_address, char mask, char *output_buffer);

#endif // IP_MATHS_H