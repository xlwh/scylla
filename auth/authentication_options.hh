/*
 * Copyright (C) 2018 ScyllaDB
 */

/*
 * This file is part of Scylla.
 *
 * Scylla is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Scylla is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Scylla.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <iosfwd>
#include <optional>
#include <unordered_map>
#include <unordered_set>

#include <seastar/core/sstring.hh>

#include "seastarx.hh"

namespace auth {

enum class authentication_option {
    password,
    options
};

std::ostream& operator<<(std::ostream&, authentication_option);

using authentication_option_set = std::unordered_set<authentication_option>;

struct authentication_options final {
    std::optional<sstring> password;
    std::optional<std::unordered_map<sstring, sstring>> options;
};

}
