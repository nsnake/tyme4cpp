#include "basic_culture.h"
#include "../tyme.h"

namespace tyme {
    // Animal 实现
    const vector<string> Animal::NAMES = {
        "蛟", "龙", "貉", "兔", "狐", "虎", "豹", "獬", "牛", "蝠", "鼠", "燕", "猪", "獝", "狼", "狗", "彘", "鸡", "乌", "猴", "猿", "犴", "羊", "獐", "马", "鹿", "蛇", "蚓"
    };

    Animal Animal::from_index(const int index) {
        return Animal(index);
    }

    Animal Animal::from_name(const string &name) {
        return Animal(name);
    }

    Animal Animal::next(const int n) const {
        return from_index(next_index(n));
    }

    TwentyEightStar Animal::get_twenty_eight_star() const {
        return TwentyEightStar::from_index(index);
    }

    // Beast 实现
    const vector<string> Beast::NAMES = {
        "青龙", "玄武", "白虎", "朱雀"
    };

    Beast Beast::from_index(const int index) {
        return Beast(index);
    }

    Beast Beast::from_name(const string &name) {
        return Beast(name);
    }

    Beast Beast::next(const int n) const {
        return from_index(next_index(n));
    }

    Zone Beast::get_zone() const {
        return Zone::from_index(index);
    }

    // Constellation 实现
    const vector<string> Constellation::NAMES = {
        "白羊", "金牛", "双子", "巨蟹", "狮子", "处女", "天秤", "天蝎", "射手", "摩羯", "水瓶", "双鱼"
    };

    Constellation Constellation::from_index(const int index) {
        return Constellation(index);
    }

    Constellation Constellation::from_name(const string &name) {
        return Constellation(name);
    }

    Constellation Constellation::next(const int n) const {
        return from_index(next_index(n));
    }

    // Zodiac 实现
    const vector<string> Zodiac::NAMES = {
        "鼠", "牛", "虎", "兔", "龙", "蛇", "马", "羊", "猴", "鸡", "狗", "猪"
    };

    Zodiac Zodiac::from_index(const int index) {
        return Zodiac(index);
    }

    Zodiac Zodiac::from_name(const string &name) {
        return Zodiac(name);
    }

    Zodiac Zodiac::next(const int n) const {
        return from_index(next_index(n));
    }

    bool Zodiac::equals(const Zodiac &other) const {
        return to_string() == other.to_string();
    }

    EarthBranch Zodiac::get_earth_branch() const {
        return EarthBranch::from_index(index);
    }
}
