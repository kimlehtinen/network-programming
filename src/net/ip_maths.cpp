#include <cstdio>
#include <cstring>
#include "net/ip_maths.h"

void get_broadcast_address(char *ip_addr, char mask, char *output_buffer) {
    unsigned int ip_parts[4];
    sscanf(ip_addr, "%u.%u.%u.%u", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);

    unsigned int ip_integer = (ip_parts[0] << 24) | (ip_parts[1] << 16) | (ip_parts[2] << 8) | ip_parts[3];
    unsigned int mask_integer = (0xFFFFFFFF << (32 - mask)) & 0xFFFFFFFF;
    unsigned int broadcast_integer = ip_integer | ~mask_integer;

    unsigned int broadcast_parts[4];
    broadcast_parts[0] = (broadcast_integer >> 24) & 0xFF;
    broadcast_parts[1] = (broadcast_integer >> 16) & 0xFF;
    broadcast_parts[2] = (broadcast_integer >> 8) & 0xFF;
    broadcast_parts[3] = broadcast_integer & 0xFF;

    sprintf(output_buffer, "%u.%u.%u.%u", broadcast_parts[0], broadcast_parts[1], broadcast_parts[2], broadcast_parts[3]);
}

unsigned int get_ip_integer_equivalent(char *ip_address) {

}

void get_abcd_ip_format(unsigned int ip_address, char *output_buffer) {

}

void get_network_id(char *ip_address, char mask, char *output_buffer) {

}
/*
unsigned int get_subnet_cardinality(char mask_value){
   
}

int check_ip_subnet_membser_ship(char *network_id, 
                             char mask, 
                             char *check_ip){
}

*/
