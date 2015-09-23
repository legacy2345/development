/**
 * @file legacy/character/sexuality.cpp
 * @brief Implementation of the Legacy random number generator module.
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
#include <legacy/character/sexuality.h>

#include <iostream>
#include <legacy/random.h>


Legacy::Sexuality Legacy::
generate(Legacy::SexualityConfig const&,
         Legacy::RandomNumberGenerator& rng)
{
  Legacy::Sexuality sexuality;
  std::bernoulli_distribution sex_chooser(0.49);
  std::exponential_distribution<> bias_chooser(0.5);

  sexuality.sex_ = (sex_chooser(rng) ? Sexuality::Physically::male
                                     : Sexuality::Physically::female);
  sexuality.gender_ = std::min(bias_chooser(rng), 1.0);
  sexuality.same_sex_pref_ = 1.0 - std::min(bias_chooser(rng), 1.0);
  sexuality.opposite_sex_pref_ = std::min(bias_chooser(rng), 1.0);

  return sexuality;
}


std::istream& Legacy::
operator>>(std::istream& istr, Legacy::Sexuality&)
{
  return istr;
}


std::ostream& Legacy::
operator<<(std::ostream& ostr, Legacy::Sexuality const& sexuality)
{
  ostr << "sexuality["
       << (sexuality.sex() == Sexuality::Physically::male ? 'M' : 'F') << " "
       << sexuality.gender() << " "
       << sexuality.same_sex_preference() << " "
       << sexuality.opposite_sex_preference() << "]";
  return ostr;
}

