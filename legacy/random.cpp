/**
 * @file legacy/random.cpp
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
#include <legacy/random.h>

#include <iostream>


Legacy::RandomNumberGenerator::
RandomNumberGenerator()
: mt_()
{
  std::random_device rd;
  mt_.seed(rd());
}


Legacy::RandomNumberGenerator::
RandomNumberGenerator(Legacy::RandomNumberGenerator::result_type seed)
: mt_(seed)
{ }


Legacy::RandomNumberGenerator::
~RandomNumberGenerator() = default;


Legacy::RandomNumberGenerator::result_type Legacy::RandomNumberGenerator::
min()
{ return mt_.min(); }


Legacy::RandomNumberGenerator::result_type Legacy::RandomNumberGenerator::
max()
{ return mt_.max(); }


Legacy::RandomNumberGenerator::result_type Legacy::RandomNumberGenerator::
operator()()
{ return mt_(); }


std::istream& Legacy::
operator>>(std::istream& istr, Legacy::RandomNumberGenerator& rng)
{
  istr >> rng.mt_;
  return istr;
}


std::ostream& Legacy::
operator<<(std::ostream& ostr, Legacy::RandomNumberGenerator const& rng)
{
  ostr << rng.mt_;
  return ostr;
}

