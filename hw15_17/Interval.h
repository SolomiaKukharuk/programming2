#ifndef INTERVAL_H
#define INTERVAL_H

#include <stdexcept>
#include <iostream>
#include <vector>

class Interval {
private:
    double start;
    double end;
    bool include_start;
    bool include_end;

public:

    Interval(double s, double e, bool inc_start = true, bool inc_end = true);
    bool is_valid() const;
    Interval intersect(const Interval& other) const;
    Interval unite(const Interval& other) const;
    static double max_distance(const std::vector<Interval>& intervals);
    double get_start() const { return start; }
    double get_end() const { return end; }
    bool get_include_start() const { return include_start; }
    bool get_include_end() const { return include_end; }
};

#endif
