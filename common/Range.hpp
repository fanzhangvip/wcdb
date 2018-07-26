/*
 * Tencent is pleased to support the open source community by making
 * WCDB available.
 *
 * Copyright (C) 2017 THL A29 Limited, a Tencent company.
 * All rights reserved.
 *
 * Licensed under the BSD 3-Clause License (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 *       https://opensource.org/licenses/BSD-3-Clause
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef Range_hpp
#define Range_hpp

#include <unistd.h>

namespace WCDB {

class Range {
public:
    using Location = off_t;
    using Length = size_t;

    static const Range& notFound();

    Range();
    Range(Location location, Length length);

    Location location;
    Length length;

    void setEdge(Location edge);
    Location edge() const;

    void restrict_(Location minLocation, Location maxEdge);

    bool contains(Location location_) const;
    bool contains(const Range& other) const;

    bool operator<(const Range& other) const;
    bool operator==(const Range& other) const;
    bool operator!=(const Range& other) const;
};

} // namespace WCDB

#endif /* Range_hpp */
