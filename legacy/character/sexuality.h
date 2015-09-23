/**
 * @file legacy/character/sexuality.h
 * @brief Public interface of the Legacy character sexuality submodule.
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
#ifndef LEGACY_CHARACTER_SEXUALITY_H_
#define LEGACY_CHARACTER_SEXUALITY_H_

#include "legacy/liblegacy2345.h"

#include <iosfwd>


namespace Legacy
{
class RandomNumberGenerator;
class SexualityConfig;


/**
 * The embodiment of sexual characteristics for an individual.
 */
class LIBLEGACY2345_API Sexuality
{
public:
  enum class Physically { male, female };

public:
  Physically
  sex() const
  { return sex_; }

  double
  gender() const
  { return gender_; }

  double
  same_sex_preference() const
  { return same_sex_pref_; }

  double
  opposite_sex_preference() const
  { return opposite_sex_pref_; }

  /**
   * Randomly generates the sexual characteristics.
   */
  friend Sexuality
  generate(SexualityConfig const& config, RandomNumberGenerator& rng);

  friend std::istream&
  operator>>(std::istream& istr, Sexuality& sex);

  friend std::ostream&
  operator<<(std::ostream& ostr, Sexuality const& sex);

private:
  Sexuality();

private:
  Physically sex_;
  double     gender_;
  double     same_sex_pref_;
  double     opposite_sex_pref_;
};


LIBLEGACY2345_API Sexuality
generate(SexualityConfig const& config, RandomNumberGenerator& rng);

LIBLEGACY2345_API std::istream&
operator>>(std::istream& istr, Sexuality& sex);

LIBLEGACY2345_API std::ostream&
operator<<(std::ostream& ostr, Sexuality const& sex);

} // namespace Legacy

#endif /* LEGACY_CHARACTER_SEXUALITY_H_ */
