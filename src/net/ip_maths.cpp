#include <cstdio>
#include <cstring>
#include <math.h>
#include "net/ip_maths.h"

void get_broadcast_address(char *ip_addr, char mask, char *output_buffer) {
    unsigned int ip_integer = get_ip_integer_equivalent(ip_addr);
    unsigned int mask_integer = (0xFFFFFFFF << (32 - mask)) & 0xFFFFFFFF;
    unsigned int broadcast_integer = ip_integer | ~mask_integer;
    get_abcd_ip_format(broadcast_integer, output_buffer);
}

unsigned int get_ip_integer_equivalent(char *ip_address) {
    unsigned int ip_parts[4];
    sscanf(ip_address, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);

    return (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
}

void get_abcd_ip_format(unsigned int ip_address, char *output_buffer) {
    unsigned int ip_parts[4];
    ip_parts[0] = (ip_address >> 24) & 0xFF;
    ip_parts[1] = (ip_address >> 16) & 0xFF;
    ip_parts[2] = (ip_address >> 8) & 0xFF;
    ip_parts[3] = ip_address & 0xFF;

    sprintf(output_buffer, "%u.%u.%u.%u", ip_parts[0], ip_parts[1], ip_parts[2], ip_parts[3]);
}

void get_network_id(char *ip_address, char mask, char *output_buffer) {
    unsigned int ip_integer = get_ip_integer_equivalent(ip_address);
    unsigned int mask_integer = (0xFFFFFFFF << (32 - mask)) & 0xFFFFFFFF;
    unsigned int network_integer = ip_integer & mask_integer;
    get_abcd_ip_format(network_integer, output_buffer);
}

unsigned int get_subnet_cardinality(char mask_value) {
    return pow(2, MAX_MASK_LEN - mask_value) - 2;
}

int check_ip_subnet_membser_ship(char *network_id, char mask, char *check_ip) {
    unsigned int check_ip_integer = get_ip_integer_equivalent(check_ip);
    unsigned int mask_integer = (0xFFFFFFFF << (32 - mask)) & 0xFFFFFFFF;
    unsigned int calculated_nw_id = check_ip_integer & mask_integer;
    unsigned int network_id_integer = get_ip_integer_equivalent(network_id);

    if (network_id_integer == calculated_nw_id)
        return 0;
    return -1;
}
