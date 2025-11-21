#pragma once

#include <string>
#include <vector>

using namespace std;

namespace tyme {
    /**
     * @brief 传统文化(民俗)
     */
    class Culture {
    public:
        virtual ~Culture() = default;

        /**
         * @brief 名称
         * @return 名称
         */
        virtual string get_name() const = 0;

        /**
         * @brief 描述
         * @return 描述
         */
        virtual string to_string() const = 0;
    };

    /**
     * @brief 传统文化抽象
     */
    class AbstractCulture : public Culture {
    public:
        ~AbstractCulture() override = default;

        bool equals(const Culture *o) const;

        /**
         * @brief 名称
         * @return 名称
         */
        string get_name() const override;

        /**
         * @brief 描述
         * @return 描述
         */
        string to_string() const override;

        /**
         * @brief 转换为不超范围的索引
         * @param index 索引
         * @param size 数量
         * @return 索引，从0开始
         */
        static int index_of(int index, int size);
    };

    /**
     * @brief 循环传统文化
     */
    class LoopTyme : public AbstractCulture {
    public:
        ~LoopTyme() override = default;

        /**
         * @brief 通过索引初始化
         * @param names 名称列表
         * @param index 索引，支持负数，自动轮转
         */
        LoopTyme(const vector<string> &names, const int index) : names(names), index(index_of(index)) {
        }

        /**
         * @brief 通过名称初始化
         * @param names 名称列表
         * @param name 名称
         */
        LoopTyme(const vector<string> &names, const string &name) : names(names), index(index_of(name)) {
        }

        LoopTyme(const LoopTyme &other) {
            names = other.names;
            index = other.get_index();
        }

        LoopTyme& operator=(const LoopTyme &other) {
            if (this != &other) {
                names = other.names;
                index = other.get_index();
            }
            return *this;
        }

        /**
         * @brief 索引
         * @return 索引，从0开始
         */
        int get_index() const;

        /**
         * @brief 数量
         * @return 数量
         */
        int get_size() const;

        /**
         * @brief 名称
         * @return 名称
         */
        string get_name() const override;

        /**
         * @brief 名称对应的索引
         * @param name 名称
         * @return 索引，从0开始
         */
        int index_of(const string &name) const;

        /**
         * @brief 转换为不超范围的索引
         * @param index 索引
         * @return 索引，从0开始
         */
        int index_of(int index) const;

        /**
         * @brief 推移后的索引
         * @param n 推移步数
         * @return 索引，从0开始
         */
        int next_index(int n) const;

        /**
         * @brief 到目标索引的步数
         * @param target_index 目标索引
         * @return 步数
         */
        int steps_to(int target_index) const;

    protected:
        /**
         * @brief 名称列表
         */
        vector<string> names;

        /**
         * @brief 索引，从0开始
         */
        int index;
    };
}

