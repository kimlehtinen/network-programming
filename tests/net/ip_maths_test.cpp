#include <gtest/gtest.h>
#include "net/ip_maths.h"

TEST(IPMathsTest, get_broadcast_address) {
    char ip_addr[] = "192.168.2.10";
    char mask = 24;
    char output_buffer[16];

    get_broadcast_address(ip_addr, mask, output_buffer);

    EXPECT_STREQ(output_buffer, "192.168.2.255");
}

