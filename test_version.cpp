
#include "lib.h"
#include <gtest/gtest.h>

TEST(test_version, test_valid_version) { ASSERT_TRUE(version() > 0); }
struct Ip_v4_test : ::testing::Test {
  Ip_v4 ip{"192.168.2.15"};
};

TEST_F(Ip_v4_test, ip_v4_object_creation) {
  ASSERT_EQ(192, ip.get_part(0));
  ASSERT_EQ(168, ip.get_part(1));
  ASSERT_EQ(2, ip.get_part(2));
  ASSERT_EQ(16, ip.get_part(3));
}

TEST_F(ip_v4_tests, ip_v4_get_part) {
  ASSERT_EQ(192, ip.get_part(0));
  ASSERT_EQ();
}