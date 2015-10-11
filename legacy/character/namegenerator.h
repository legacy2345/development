/**
 * @file legacy/character/namegenerator.h
 * @brief Public interface of the Legacy character name generator submodule.
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
#ifndef LEGACY_CHARACTER_NAMEGENERATOR_H_
#define LEGACY_CHARACTER_NAMEGENERATOR_H_

#include "legacy/liblegacy2345.h"

#include <memory>
#include <string>
#include <vector>


namespace Legacy
{
class RandomNumberGenerator;
class Config;

/**
 * An abstract factorory (interface) for generatingh names.
 */
class LIBLEGACY2345_API NameGenerator
{
public:
  using Ptr = std::unique_ptr<NameGenerator>;

  enum class NameType
  {
    SURNAME,
    GIVEN,
    MIDDLE
  };

public:
  virtual
  ~NameGenerator() = 0;

  /** Returns a generated name. */
  virtual std::string
  pick_name(RandomNumberGenerator& rng);

  /** Factory function to create a name generator. */
  static Ptr
  create(Config const& config, NameType type);
};

} // namespace Legacy

#endif /* LEGACY_CHARACTER_NAMEGENERATOR_H_ */
