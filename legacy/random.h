/**
 * @file legacy/random.h
 * @brief Public interface of the Legacy random number generator module.
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
#ifndef LEGACY_RANDOM_H_
#define LEGACY_RANDOM_H_

#include "legacy/liblegacy2345.h"

#include <cstdint>
#include <iosfwd>
#include <random>


namespace Legacy
{

/**
 * A wrapper class for all the instanced random number generators.
 *
 * Provides the UniformRandomNumberGenerator concept so instances can be used
 * in C++ std random number distributions.
 */
class LIBLEGACY2345_API RandomNumberGenerator
{
public:
  using result_type = std::uint_fast32_t;

public:
  /**
   * Constructs a default-initialized random number generator.
   *
   * On most systems, default initialized means primed from /dev/random.
   */
  RandomNumberGenerator();

  /**
   * Constructs a random number generator from a specific seed.
   */
  RandomNumberGenerator(result_type seed);

  /**
   * Destroys a random number generator.
   */
  virtual
  ~RandomNumberGenerator();

  /**
   * The smallest value returned by operator().
   * Required by the UniformRandomNumberGenerator concept.
   */
  result_type
  min();

  /**
   * The largest value returned by operator().
   * Required by the UniformRandomNumberGenerator concept.
   */
  result_type
  max();

  /**
   * Returns a random value in the closed interval [min(), max()].
   * Required by the UniformRandomNumberGenerator concept.
   *
   * This function is virtual so it can be overridden in mocks.
   */
  virtual result_type
  operator()();

  friend std::istream&
  operator>>(std::istream& istr, RandomNumberGenerator& rng);

  friend std::ostream&
  operator<<(std::ostream& ostr, RandomNumberGenerator const& rng);

private:
  std::mt19937 mt_;
};

LIBLEGACY2345_API std::istream&
operator>>(std::istream& istr, RandomNumberGenerator& rng);

LIBLEGACY2345_API std::ostream&
operator<<(std::ostream& ostr, RandomNumberGenerator const& rng);

} // namespace Legacy

#endif /* LEGACY_RANDOM_H_ */
