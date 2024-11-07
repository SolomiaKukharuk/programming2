#include "Interval.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>

Interval::Interval(double s, double e, bool inc_start, bool inc_end)
    : start(s), end(e), include_start(inc_start), include_end(inc_end) {
    if (start > end) throw std::invalid_argument("Start cannot be greater than end.");
}

bool Interval::is_valid() const {
    return start <= end;
}

Interval Interval::intersect(const Interval& other) const {
    double new_start = std::max(start, other.start);
    double new_end = std::min(end, other.end);
    bool new_include_start = (new_start == start ? include_start : other.include_start);
    bool new_include_end = (new_end == end ? include_end : other.include_end);

    if (new_start > new_end || (new_start == new_end && (!new_include_start || !new_include_end))) {
        throw std::runtime_error("Intervals do not intersect.");
    }
    return Interval(new_start, new_end, new_include_start, new_include_end);
}

Interval Interval::unite(const Interval& other) const {
    if (end < other.start || start > other.end) {
        throw std::runtime_error("Intervals do not overlap and cannot be united.");
    }
    double new_start = std::min(start, other.start);
    double new_end = std::max(end, other.end);
    bool new_include_start = (new_start == start ? include_start : other.include_start);
    bool new_include_end = (new_end == end ? include_end : other.include_end);

    return Interval(new_start, new_end, new_include_start, new_include_end);
}

double Interval::max_distance(const std::vector<Interval>& intervals) {
    if (intervals.empty()) return 0;
    double min_point = intervals[0].start;
    double max_point = intervals[0].end;

    for (const auto& interval : intervals) {
        min_point = std::min(min_point, interval.start);
        max_point = std::max(max_point, interval.end);
    }
    return std::abs(max_point - min_point);
}
