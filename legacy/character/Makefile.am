#
# @file legacy/character/Makefile.am
# @brief automake recipe for Legacy 2345 character module
#
# Copyright 2015 Stephen M. Webb  <stephen.webb@bregmasoft.ca>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.
#

noinst_LTLIBRARIES = libcharacter.la

libcharacter_la_CPPFLAGS = \
  -I$(top_builddir) \
  -I$(top_srcdir) \
  -DLIBLEGACY2345_BUILDING_DSO=1

libcharacter_la_SOURCES = \
  sexualityconfig.h sexuality.h sexuality.cpp \
  namegenerator.h namegenerator.cpp
