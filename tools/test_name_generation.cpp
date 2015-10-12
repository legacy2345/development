/**
 * @file tools/test_name_generation.cpp
 * @brief Tool to test the legacy2345 characteraracter name generation submodule.
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
#include <iostream>
#include "legacy/character/namegenerator.h"
#include "legacy/character/sexuality.h"
#include "legacy/character/sexualityconfig.h"
#include "legacy/config.h"
#include "legacy/random.h"

using namespace Legacy;


int
main(int argc, char const* argv[])
{
  Config config(argc, argv);
  RandomNumberGenerator rng;
  Sexuality sexuality = Legacy::Sexuality::generate(Legacy::SexualityConfig(), rng);

  NameGenerator::Ptr last_name_generator(NameGenerator::create(config, NameGenerator::NameType::SURNAME, sexuality.gender()));
  NameGenerator::Ptr first_name_generator(NameGenerator::create(config, NameGenerator::NameType::GIVEN, sexuality.gender()));
  NameGenerator::Ptr middle_name_generator(NameGenerator::create(config, NameGenerator::NameType::MIDDLE, sexuality.gender()));

  std::cout << last_name_generator->pick_name(rng) << ", "
            << first_name_generator->pick_name(rng) << " "
            << middle_name_generator->pick_name(rng) << "\n";
}
