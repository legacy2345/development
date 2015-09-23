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
generate(Legacy::SexualityConfig const& config,
         Legacy::RandomNumberGenerator& rng)
{
  Legacy::Sexuality sexuality;
  return sexuality;
}


std::istream& Legacy::
operator>>(std::istream& istr, Legacy::Sexuality& sexuality)
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

