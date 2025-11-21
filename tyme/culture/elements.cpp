#include "elements.h"

namespace tyme {
    // Element 实现
    const vector<string> Element::NAMES = {
        "木", "火", "土", "金", "水"
    };

    Element Element::from_index(const int index) {
        return Element(index);
    }

    Element Element::from_name(const string &name) {
        return Element(name);
    }

    Element Element::next(const int n) const {
        return from_index(next_index(n));
    }

    bool Element::equals(const Element &other) const {
        return to_string() == other.to_string();
    }

    Element Element::get_reinforce() const {
        return next(1);
    }

    Element Element::get_restrain() const {
        return next(2);
    }

    Element Element::get_reinforced() const {
        return next(-1);
    }

    Element Element::get_restrained() const {
        return next(-2);
    }

    Direction Element::get_direction() const {
        const int indices[5] = {2, 8, 4, 6, 0};
        return Direction::from_index(indices[index]);
    }

    // Direction 实现
    const vector<string> Direction::NAMES = {
        "北", "西南", "东", "东南", "中", "西北", "西", "东北", "南"
    };

    Direction Direction::from_index(const int index) {
        return Direction(index);
    }

    Direction Direction::from_name(const string &name) {
        return Direction(name);
    }

    Direction Direction::next(const int n) const {
        return from_index(next_index(n));
    }

    Land Direction::get_land() const {
        return Land::from_index(index);
    }

    Element Direction::get_element() const {
        const int indices[9] = {4, 2, 0, 0, 2, 3, 3, 2, 1};
        return Element::from_index(indices[index]);
    }

    // Land 实现
    const vector<string> Land::NAMES = {
        "玄天", "朱天", "苍天", "阳天", "钧天", "幽天", "颢天", "变天", "炎天"
    };

    Land Land::from_index(const int index) {
        return Land(index);
    }

    Land Land::from_name(const string &name) {
        return Land(name);
    }

    Land Land::next(const int n) const {
        return from_index(next_index(n));
    }

    Direction Land::get_direction() const {
        return Direction::from_index(index);
    }
}
