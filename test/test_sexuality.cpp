/**
 * @file test/test_sexuality.cpp
 * @brief Unit tests for liblegacy2345 character sexuality submodule.
 */
/*
 * Copyright 2015 Stephen M. Webb <stephen.webb@bregmasoft.ca>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <gtest/gtest.h>
#include "legacy/character/sexuality.h"
#include "legacy/character/sexualityconfig.h"
#include "legacy/random.h"
#include <sstream>


/**
 * Verify construction using factory function.
 */
TEST(Sexuality, Factory)
{
  Legacy::RandomNumberGenerator rng;
  Legacy::Sexuality sexuality = Legacy::Sexuality::generate(Legacy::SexualityConfig(), rng);
}


/**
 * Verify a stream-marshalled Sexuality object unmarshalls to an identical
 * object.
 */
TEST(Sexuality, UnmarshallsIdentically)
{
  Legacy::RandomNumberGenerator rng;
  Legacy::Sexuality s1 = Legacy::Sexuality::generate(Legacy::SexualityConfig(), rng);
  Legacy::Sexuality s2 = Legacy::Sexuality::generate(Legacy::SexualityConfig(), rng);

  std::stringstream sstr;
  sstr << s1;
  sstr >> s2;

  EXPECT_EQ(s1.sex(), s2.sex());
  EXPECT_NEAR(s1.gender(), s2.gender(), 0.00001);
  EXPECT_NEAR(s1.same_sex_preference(), s2.same_sex_preference(), 0.00001);
  EXPECT_NEAR(s1.opposite_sex_preference(), s2.opposite_sex_preference(), 0.00001);
}
