/**
 * @file legacy/liblegacy2345.h
 * @brief Library interface file for the Legacy 2345 library.
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
#ifndef LEGACY_LIBLEGACY2345_H_
#define LEGACY_LIBLEGACY2345_H_

/* Provide some cross-platform symbol export decorations. */
#if defined _WIN32 || defined __CYGWIN__ || defined __MINGW32__
#  define LEGACY3456_HELPER_DSO_IMPORT __declspec(dllimport)
#  define LEGACY3456_HELPER_DSO_EXPORT __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#  define LEGACY3456_HELPER_DSO_IMPORT __attribute__((visibility("default")))
#  define LEGACY3456_HELPER_DSO_EXPORT __attribute__((visibility("default")))
#else
#  define LEGACY3456_HELPER_DSO_IMPORT
#  define LEGACY3456_HELPER_DSO_EXPORT
#endif

/*
 * Define symbols as exported or imported, depending on what's getting built.
 *
 * On a COFF systen like MS Windows, the library API gets built as a DLL, as
 * an import lib, and used by client software, so exported symols need to be
 * decorated three different ways (one for each), with appropriate preprocessor
 * symbols defined or not depending on which target is being built.  ELF systems
 * are a little easier, they're either the DSO or the client software.
 */
#if defined(LIBLEGACY2345_BUILDING_DSO)
#  if defined(LIBLEGACY2345_EXPORTS)
#    define LIBLEGACY2345_API LEGACY3456_HELPER_DSO_EXPORT
#  else
#    define LIBLEGACY2345_API LEGACY3456_HELPER_DSO_IMPORT
#  endif
#else
#  define LIBLEGACY2345_API
#endif

#endif // end LEGACY_LIBLEGACY2345_H_
