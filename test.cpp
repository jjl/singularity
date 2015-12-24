#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE singularity

#include <boost/test/unit_test.hpp>
#include "singularity.h"

BOOST_AUTO_TEST_SUITE(SingularitySuite)

BOOST_AUTO_TEST_CASE(erasure) {
  long i[] = {1,2,3};
  eat(&i, sizeof(long), 3);
  BOOST_CHECK_EQUAL(i[0], 0);
  BOOST_CHECK_EQUAL(i[1], 0);
  BOOST_CHECK_EQUAL(i[2], 0);
  i[2] = 34;
  eat(&i, sizeof(long), 2);
  BOOST_CHECK_EQUAL(i[2], 34);
}

BOOST_AUTO_TEST_SUITE_END()

