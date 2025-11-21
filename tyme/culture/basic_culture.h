#ifndef TYME_CULTURE_BASIC_CULTURE_H
#define TYME_CULTURE_BASIC_CULTURE_H

#include "abstract_culture.h"

namespace tyme {
    // 前向声明
    class TwentyEightStar;
    class EarthBranch;
    class Zone;

    /**
     * @brief 动物（二十八宿）
     */
    class Animal : public LoopTyme {
    public:
        ~Animal() override = default;

        static const vector<string> NAMES;

        explicit Animal(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Animal(const string &name) : LoopTyme(NAMES, name) {
        }

        static Animal from_index(int index);

        static Animal from_name(const string &name);

        Animal next(int n) const;

        /**
         * @brief 二十八宿
         * @return 二十八宿
         */
        TwentyEightStar get_twenty_eight_star() const;
    };

    /**
     * @brief 神兽（四象）
     */
    class Beast : public LoopTyme {
    public:
        ~Beast() override = default;

        static const vector<string> NAMES;

        explicit Beast(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Beast(const string &name) : LoopTyme(NAMES, name) {
        }

        static Beast from_index(int index);

        static Beast from_name(const string &name);

        Beast next(int n) const;

        /**
         * @brief 宫
         * @return 宫
         */
        Zone get_zone() const;
    };

    /**
     * @brief 星座
     */
    class Constellation : public LoopTyme {
    public:
        ~Constellation() override = default;

        static const vector<string> NAMES;

        explicit Constellation(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Constellation(const string &name) : LoopTyme(NAMES, name) {
        }

        static Constellation from_index(int index);

        static Constellation from_name(const string &name);

        Constellation next(int n) const;
    };

    /**
     * @brief 生肖
     */
    class Zodiac : public LoopTyme {
    public:
        ~Zodiac() override = default;

        static const vector<string> NAMES;

        explicit Zodiac(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Zodiac(const string &name) : LoopTyme(NAMES, name) {
        }

        static Zodiac from_index(int index);

        static Zodiac from_name(const string &name);

        Zodiac next(int n) const;

        bool equals(const Zodiac &other) const;

        /**
         * @brief 地支
         * @return 地支
         */
        EarthBranch get_earth_branch() const;
    };
}

#endif // TYME_CULTURE_BASIC_CULTURE_H
