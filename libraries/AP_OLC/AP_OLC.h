/*
 * This file is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * AP_OLC is based on INAV olc.c implemention, thanks @fiam and other contributors.
 */

#pragma once
#include <AP_Common/AP_Common.h>

typedef int32_t olc_coord_t;
typedef uint32_t uolc_coord_t;

static constexpr olc_coord_t OLC_DEG_MULTIPLIER = 10000000; // 1e7

class AP_OLC
{
public:

// olc_encodes the given coordinates in lat and lon (deg * OLC_DEG_MULTIPLIER)
// as an OLC code of the given length. It returns the number of characters
// written to buf.
static int olc_encode(olc_coord_t lat, olc_coord_t lon, size_t length, char *buf, size_t bufsize);

private:

static bool inited;
// Initialized via init_constants()
static olc_coord_t grid_size;
static olc_coord_t initial_resolution;
static const char alphabet[];

static void init_constants(void);
static float compute_precision_for_length(int length);
static olc_coord_t adjust_latitude(olc_coord_t lat, size_t code_len);
static olc_coord_t normalize_longitude(olc_coord_t lon);
static unsigned encode_pairs(uolc_coord_t lat, uolc_coord_t lon, size_t length, char *buf, size_t bufsize);
static int encode_grid(uolc_coord_t lat, uolc_coord_t lon, size_t length,char *buf, size_t bufsize);

};