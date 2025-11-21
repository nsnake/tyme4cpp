#ifndef TYME_CULTURE_DEITIES_H
#define TYME_CULTURE_DEITIES_H

#include "abstract_culture.h"
#include <vector>
#include <string>

using namespace std;

namespace tyme {
    // 前向声明
    class SixtyCycle;

    /**
     * @brief 建除十二值神
     */
    class Duty : public LoopTyme {
    public:
        ~Duty() override = default;

        static const vector<string> NAMES;

        explicit Duty(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Duty(const string &name) : LoopTyme(NAMES, name) {
        }

        static Duty from_index(int index);

        static Duty from_name(const string &name);

        Duty next(int n) const;
    };

    /**
     * @brief 吉凶
     */
    class Luck : public LoopTyme {
    public:
        ~Luck() override = default;

        static const vector<string> NAMES;

        explicit Luck(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Luck(const string &name) : LoopTyme(NAMES, name) {
        }

        static Luck from_index(int index);

        static Luck from_name(const string &name);

        Luck next(int n) const;
    };

    /**
     * @brief 神煞
     */
    class God : public LoopTyme {
    public:
        ~God() override = default;

        static const vector<string> NAMES;

        explicit God(const int index) : LoopTyme(NAMES, index) {
        }

        explicit God(const string &name) : LoopTyme(NAMES, name) {
        }

        static God from_index(int index);

        static God from_name(const string &name);

        static vector<God> get_day_gods(const SixtyCycle &month, const SixtyCycle &day);

        God next(int n) const;

        /**
         * @brief 吉凶
         * @return 吉凶
         */
        Luck get_luck() const;

    protected:
        static const vector<string> DAY_GODS;
    };

    /**
     * @brief 宜忌
     */
    class Taboo : public LoopTyme {
    public:
        ~Taboo() override = default;

        static const vector<string> NAMES;

        explicit Taboo(const int index) : LoopTyme(NAMES, index) {
        }

        explicit Taboo(const string &name) : LoopTyme(NAMES, name) {
        }

        static Taboo from_index(int index);

        static Taboo from_name(const string &name);

        Taboo next(int n) const;

        /**
         * @brief 日宜
         * @param month 月干支
         * @param day 日干支
         * @return 宜忌列表
         */
        static vector<Taboo> get_day_recommends(const SixtyCycle &month, const SixtyCycle &day);

        /**
         * @brief 日忌
         * @param month 月干支
         * @param day 日干支
         * @return 宜忌列表
         */
        static vector<Taboo> get_day_avoids(const SixtyCycle &month, const SixtyCycle &day);

        /**
         * @brief 时辰宜
         * @param day 日干支
         * @param hour 时辰干支
         * @return 宜忌列表
         */
        static vector<Taboo> get_hour_recommends(const SixtyCycle &day, const SixtyCycle &hour);

        /**
         * @brief 时辰忌
         * @param day 日干支
         * @param hour 时辰干支
         * @return 宜忌列表
         */
        static vector<Taboo> get_hour_avoids(const SixtyCycle &day, const SixtyCycle &hour);

    protected:
        static const vector<string> DAY_TABOO;
        static const vector<string> HOUR_TABOO;

    private:
        static vector<Taboo> get_taboos(vector<string> data, int sup_index, int sub_index, int index);
    };
}

#endif // TYME_CULTURE_DEITIES_H
