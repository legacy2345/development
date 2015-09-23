/**
 * @file test/test_random.cpp
 * @brief Unit tests for liblegacy2345 random number generation module.
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
#include "legacy/random.h"
#include <random>


/**
 * Verify different default-constructed random number generators provide
 * different sequences.
 */
TEST(Random, DefaultGeneratorsAreDifferent)
{
  Legacy::RandomNumberGenerator rng1;
  Legacy::RandomNumberGenerator rng2;

  EXPECT_NE(rng1(), rng2());
  EXPECT_NE(rng1(), rng2());
  EXPECT_NE(rng1(), rng2());
}


/**
 * Verify different random number generators constructed with the same seed
 * provide identical sequences.
 */
TEST(Random, SeededGeneratorsAreIdentical)
{
  Legacy::RandomNumberGenerator rng1(100);
  Legacy::RandomNumberGenerator rng2(100);

  EXPECT_EQ(rng1(), rng2());
  EXPECT_EQ(rng1(), rng2());
  EXPECT_EQ(rng1(), rng2());
}


/**
 * Verify the Legacy2345 random number henerator can be used with the standard
 * random distributions.
 */
TEST(Random, GeneratorsWorkWithStandardDistributions)
{
  Legacy::RandomNumberGenerator legacy_rng;
  std::normal_distribution<> std_normal;

  EXPECT_NE(std_normal(legacy_rng), 0.0);
}
