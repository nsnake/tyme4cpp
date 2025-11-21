#include "abstract_culture.h"
#include <stdexcept>

using namespace std;

namespace tyme {
    bool AbstractCulture::equals(const Culture *o) const {
        return o && o->to_string() == to_string();
    }

    string AbstractCulture::get_name() const {
        return "";
    }

    string AbstractCulture::to_string() const {
        return get_name();
    }

    int AbstractCulture::index_of(const int index, const int size) {
        const int i = index % size;
        return i < 0 ? i + size : i;
    }

    int LoopTyme::get_index() const {
        return index;
    }

    int LoopTyme::get_size() const {
        return static_cast<int>(names.size());
    }

    string LoopTyme::get_name() const {
        return names[index];
    }

    int LoopTyme::index_of(const string &name) const {
        for (int i = 0, j = get_size(); i < j; i++) {
            if (name == names[i]) {
                return i;
            }
        }
        throw invalid_argument("illegal name: " + name);
    }

    int LoopTyme::index_of(const int index) const {
        return AbstractCulture::index_of(index, get_size());
    }

    int LoopTyme::next_index(const int n) const {
        return index_of(index + n);
    }

    int LoopTyme::steps_to(const int target_index) const {
        return index_of(target_index - index);
    }
}
