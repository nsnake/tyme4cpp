#ifndef TYME_CULTURE_ELEMENTS_H
#define TYME_CULTURE_ELEMENTS_H

#include "abstract_culture.h"

namespace tyme {
    // 前向声明
    class Direction;
    class Land;

    /**
     * @brief 五行
     */
    class Element : public LoopTyme {
    public:
        ~Element() override = default;

        static const vector<string> NAMES;

        explicit Element(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Element(const string &name) : LoopTyme(NAMES, name) {
        }

        static Element from_index(int index);

        static Element from_name(const string &name);

        Element next(int n) const;

        bool equals(const Element &other) const;

        /**
         * @brief 我生者
         * @return 五行
         */
        Element get_reinforce() const;

        /**
         * @brief 我克者
         * @return 五行
         */
        Element get_restrain() const;

        /**
         * @brief 生我者
         * @return 五行
         */
        Element get_reinforced() const;

        /**
         * @brief 克我者
         * @return 五行
         */
        Element get_restrained() const;

        /**
         * @brief 方位
         * @return 方位
         */
        Direction get_direction() const;
    };

    /**
     * @brief 九野
     */
    class Land : public LoopTyme {
    public:
        ~Land() override = default;

        static const vector<string> NAMES;

        explicit Land(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Land(const string &name) : LoopTyme(NAMES, name) {
        }

        static Land from_index(int index);

        static Land from_name(const string &name);

        Land next(int n) const;

        /**
         * 方位
         * @return 方位
         */
        Direction get_direction() const;
    };

    /**
     * @brief 方位
     */
    class Direction : public LoopTyme {
    public:
        ~Direction() override = default;

        /**
         * @brief 依据后天八卦排序（0坎北, 1坤西南, 2震东, 3巽东南, 4中, 5乾西北, 6兑西, 7艮东北, 8离南）
         */
        static const vector<string> NAMES;

        explicit Direction(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Direction(const string &name) : LoopTyme(NAMES, name) {
        }

        static Direction from_index(int index);

        static Direction from_name(const string &name);

        Direction next(int n) const;

        /**
         * @brief 九野
         * @return 九野
         */
        Land get_land() const;

        /**
         * @brief 五行
         * @return 五行
         */
        Element get_element() const;
    };
}

#endif // TYME_CULTURE_ELEMENTS_H
