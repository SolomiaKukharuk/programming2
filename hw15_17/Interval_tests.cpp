#include "Interval.h"
#include <iostream>
#include <vector>
#include <cassert>

void test_interval_creation() {
    Interval interval1(1.0, 5.0);
    assert(interval1.get_start() == 1.0);
    assert(interval1.get_end() == 5.0);
    assert(interval1.get_include_start() == true);
    assert(interval1.get_include_end() == true);
    std::cout << "Interval creation test passed." << std::endl;
}

void test_intersection() {
    Interval interval1(1.0, 5.0);
    Interval interval2(3.0, 7.0);
    Interval result = interval1.intersect(interval2);

    assert(result.get_start() == 3.0);
    assert(result.get_end() == 5.0);
    std::cout << "Intersection test passed." << std::endl;
}

void test_union() {
    Interval interval1(1.0, 5.0);
    Interval interval2(3.0, 7.0);
    Interval result = interval1.unite(interval2);

    assert(result.get_start() == 1.0);
    assert(result.get_end() == 7.0);
    std::cout << "Union test passed." << std::endl;
}

void test_max_distance() {
    std::vector<Interval> intervals = { Interval(1.0, 3.0), Interval(4.0, 6.0), Interval(8.0, 10.0) };
    double distance = Interval::max_distance(intervals);
    assert(distance == 9.0);
    std::cout << "Max distance test passed." << std::endl;
}

int main() {
    test_interval_creation();
    test_intersection();
    test_union();
    test_max_distance();

    std::cout << "All tests passed." << std::endl;
    return 0;
}
