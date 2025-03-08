#include <gtest/gtest.h>
#include "net/ip_maths.h"

TEST(IPMathsTest, get_broadcast_address_case1) {
    char ip_addr[] = "192.168.2.10";
    char mask = 24;
    char output_buffer[16];

    get_broadcast_address(ip_addr, mask, output_buffer);

    EXPECT_STREQ(output_buffer, "192.168.2.255");
}

TEST(IPMathsTest, get_broadcast_address_case2) {
    char ip_addr[] = "10.1.23.10";
    char mask = 20;
    char output_buffer[16];

    get_broadcast_address(ip_addr, mask, output_buffer);

    EXPECT_STREQ(output_buffer, "10.1.31.255");
}

TEST(IPMathsTest, get_ip_integer_equivalent_case1) {
    char ip_addr[] = "192.168.2.10";
    unsigned int expected = 0xC0A8020A;

    unsigned int result = get_ip_integer_equivalent(ip_addr);

    EXPECT_EQ(result, expected);
}

TEST(IPMathsTest, get_ip_integer_equivalent_case2) {
    char ip_addr[] = "10.1.23.10";
    unsigned int expected = 0x0A01170A;

    unsigned int result = get_ip_integer_equivalent(ip_addr);

    EXPECT_EQ(result, expected);
}

TEST(IPMathsTest, get_abcd_ip_format_case1) {
    unsigned int ip_address = 0xC0A8020A;
    char output_buffer[16];

    get_abcd_ip_format(ip_address, output_buffer);

    EXPECT_STREQ(output_buffer, "192.168.2.10");
}

TEST(IPMathsTest, get_abcd_ip_format_case2) {
    unsigned int ip_address = 0x0A01170A;
    char output_buffer[16];

    get_abcd_ip_format(ip_address, output_buffer);

    EXPECT_STREQ(output_buffer, "10.1.23.10");
}

TEST(IPMathsTest, get_network_id_case1) {
    char ip_addr[] = "192.168.2.10";
    char mask = 20;
    char output_buffer[16];

    get_network_id(ip_addr, mask, output_buffer);

    EXPECT_STREQ(output_buffer, "192.168.0.0");
}

TEST(IPMathsTest, get_network_id_case2) {
    char ip_addr[] = "192.168.2.10";
    char mask = 24;
    char output_buffer[16];

    get_network_id(ip_addr, mask, output_buffer);

    EXPECT_STREQ(output_buffer, "192.168.2.0");
}

TEST(IPMathsTest, get_subnet_cardinality_case1) {
    char mask_value = 24;
    unsigned int expected = 254;

    unsigned int result = get_subnet_cardinality(mask_value);

    EXPECT_EQ(result, expected);
}

TEST(IPMathsTest, get_subnet_cardinality_case2) {
    char mask_value = 20;
    unsigned int expected = 4094;

    unsigned int result = get_subnet_cardinality(mask_value);

    EXPECT_EQ(result, expected);
}

TEST(IPMathsTest, check_ip_subnet_membser_ship_case1) {
    char network_id[] = "192.168.2.0";
    char mask = 24;
    char check_ip[] = "192.168.2.10";

    int result = check_ip_subnet_membser_ship(network_id, mask, check_ip);

    EXPECT_EQ(result, 0); // Expect 0 because 192.168.2.10 is in the subnet 192.168.2.0/24
}

TEST(IPMathsTest, check_ip_subnet_membser_ship_case2) {
    char network_id[] = "192.168.2.0";
    char mask = 24;
    char check_ip[] = "192.168.3.10";

    int result = check_ip_subnet_membser_ship(network_id, mask, check_ip);

    EXPECT_EQ(result, -1); // Expect -1 because 192.168.3.10 is not in the subnet 192.168.2.0/24
}

TEST(IPMathsTest, check_ip_subnet_membser_ship_case3) {
    char network_id[] = "10.1.16.0";
    char mask = 20;
    char check_ip[] = "10.1.23.10";

    int result = check_ip_subnet_membser_ship(network_id, mask, check_ip);

    EXPECT_EQ(result, 0); // Expect 0 because 10.1.23.10 is in the subnet 10.1.16.0/20
}

TEST(IPMathsTest, check_ip_subnet_membser_ship_case4) {
    char network_id[] = "10.1.16.0";
    char mask = 20;
    char check_ip[] = "10.1.31.255";

    int result = check_ip_subnet_membser_ship(network_id, mask, check_ip);

    EXPECT_EQ(result, 0); // Expect 0 because 10.1.31.255 is in the subnet 10.1.16.0/20
}

TEST(IPMathsTest, check_ip_subnet_membser_ship_case5) {
    char network_id[] = "10.1.16.0";
    char mask = 20;
    char check_ip[] = "10.1.32.1";

    int result = check_ip_subnet_membser_ship(network_id, mask, check_ip);

    EXPECT_EQ(result, -1); // Expect -1 because 10.1.32.1 is not in the subnet 10.1.16.0/20
}
