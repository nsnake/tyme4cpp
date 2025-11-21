#include "tyme.h"


using std::ceil;

using namespace std;

namespace tyme {


    const vector<string> Ten::NAMES = {
        "甲子", "甲戌", "甲申", "甲午", "甲辰", "甲寅"
    };

    Ten Ten::from_index(const int index) {
        return Ten(index);
    }

    Ten Ten::from_name(const string &name) {
        return Ten(name);
    }

    Ten Ten::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> Terrain::NAMES = {
        "长生", "沐浴", "冠带", "临官", "帝旺", "衰", "病", "死", "墓", "绝", "胎", "养"
    };

    Terrain Terrain::from_index(const int index) {
        return Terrain(index);
    }

    Terrain Terrain::from_name(const string &name) {
        return Terrain(name);
    }

    Terrain Terrain::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> Twenty::NAMES = {
        "一运", "二运", "三运", "四运", "五运", "六运", "七运", "八运", "九运"
    };

    Twenty Twenty::from_index(const int index) {
        return Twenty(index);
    }

    Twenty Twenty::from_name(const string &name) {
        return Twenty(name);
    }

    Twenty Twenty::next(const int n) const {
        return from_index(next_index(n));
    }

    Sixty Twenty::get_sixty() const {
        return Sixty::from_index(index / 3);
    }

    const vector<string> Week::NAMES = {
        "日", "一", "二", "三", "四", "五", "六"
    };

    Week Week::from_index(const int index) {
        return Week(index);
    }

    Week Week::from_name(const string &name) {
        return Week(name);
    }

    Week Week::next(const int n) const {
        return from_index(next_index(n));
    }

    SevenStar Week::get_seven_star() const {
        return SevenStar::from_index(index);
    }

   
    const vector<string> Zone::NAMES = {
        "东", "北", "西", "南"
    };

    Zone Zone::from_index(const int index) {
        return Zone(index);
    }

    Zone Zone::from_name(const string &name) {
        return Zone(name);
    }

    Zone Zone::next(const int n) const {
        return from_index(next_index(n));
    }

    Direction Zone::get_direction() const {
        return Direction::from_name(get_name());
    }

    Beast Zone::get_best() const {
        return Beast::from_index(index);
    }

    const vector<string> KitchenGodSteed::NUMBERS = {
        "一", "二", "三", "四", "五", "六", "七", "八", "九", "十", "十一", "十二"
    };

    KitchenGodSteed KitchenGodSteed::from_lunar_year(const int lunar_year) {
        return KitchenGodSteed(lunar_year);
    }

    string KitchenGodSteed::by_heaven_stem(const int n) const {
        return NUMBERS[first_day_sixty_cycle.get_heaven_stem().steps_to(n)];
    }

    string KitchenGodSteed::by_earth_branch(int n) const {
        return NUMBERS[first_day_sixty_cycle.get_earth_branch().steps_to(n)];
    }

    string KitchenGodSteed::get_mouse() const {
        return by_earth_branch(0) + "鼠偷粮";
    }

    string KitchenGodSteed::get_grass() const {
        return "草子" + by_earth_branch(0) + "分";
    }

    string KitchenGodSteed::get_cattle() const {
        return by_earth_branch(1) + "牛耕田";
    }

    string KitchenGodSteed::get_flower() const {
        return "花收" + by_earth_branch(3) + "分";
    }

    string KitchenGodSteed::get_dragon() const {
        return by_earth_branch(4) + "龙治水";
    }

    string KitchenGodSteed::get_horse() const {
        return by_earth_branch(6) + "马驮谷";
    }

    string KitchenGodSteed::get_chicken() const {
        return by_earth_branch(9) + "鸡抢米";
    }

    string KitchenGodSteed::get_silkworm() const {
        return by_earth_branch(9) + "姑看蚕";
    }

    string KitchenGodSteed::get_pig() const {
        return by_earth_branch(11) + "屠共猪";
    }

    string KitchenGodSteed::get_field() const {
        return "甲田" + by_heaven_stem(0) + "分";
    }

    string KitchenGodSteed::get_cake() const {
        return by_heaven_stem(2) + "人分饼";
    }

    string KitchenGodSteed::get_gold() const {
        return by_heaven_stem(7) + "日得金";
    }

    string KitchenGodSteed::get_people_cakes() const {
        return by_earth_branch(2) + "人" + by_heaven_stem(2) + "丙";
    }

    string KitchenGodSteed::get_people_hoes() const {
        return by_earth_branch(2) + "人" + by_heaven_stem(3) + "锄";
    }

    string KitchenGodSteed::get_name() const {
        return "灶马头";
    }

    const vector<string> Dog::NAMES = {
        "初伏", "中伏", "末伏"
    };

    Dog Dog::from_index(const int index) {
        return Dog(index);
    }

    Dog Dog::from_name(const string &name) {
        return Dog(name);
    }

    Dog Dog::next(const int n) const {
        return from_index(next_index(n));
    }

    Dog DogDay::get_dog() const {
        return dog;
    }

    int DogDay::get_day_index() const {
        return day_index;
    }

    string DogDay::get_name() const {
        return dog.get_name();
    }

    string DogDay::to_string() const {
        return dog.to_string() + "第" + std::to_string(day_index + 1) + "天";
    }

    const vector<string> FetusHeavenStem::NAMES = {
        "门", "碓磨", "厨灶", "仓库", "房床"
    };

    FetusHeavenStem FetusHeavenStem::from_index(const int index) {
        return FetusHeavenStem(index);
    }

    FetusHeavenStem FetusHeavenStem::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> FetusEarthBranch::NAMES = {
        "碓", "厕", "炉", "门", "栖", "床"
    };

    FetusEarthBranch FetusEarthBranch::from_index(const int index) {
        return FetusEarthBranch(index);
    }

    FetusEarthBranch FetusEarthBranch::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> FetusMonth::NAMES = {
        "占房床", "占户窗", "占门堂", "占厨灶", "占房床", "占床仓", "占碓磨", "占厕户", "占门房", "占房床", "占灶炉", "占房床"
    };

    optional<FetusMonth> FetusMonth::from_lunar_month(const LunarMonth& lunar_month) {
        if (!lunar_month.is_leap()) {
            return FetusMonth(lunar_month.get_month() - 1);
        }
        return nullopt;
    }

    FetusMonth FetusMonth::next(const int n) const {
        return FetusMonth(next_index(n));
    }

    FetusDay FetusDay::from_sixty_cycle_day(const SixtyCycleDay& sixty_cycle_day) {
        return FetusDay(sixty_cycle_day);
    }

    FetusDay FetusDay::from_lunar_day(const LunarDay &lunar_day) {
        return FetusDay(lunar_day);
    }

    string FetusDay::get_name() const {
        string s = fetus_heaven_stem.get_name() + fetus_earth_branch.get_name();
        string door = "门";
        if ("门门" == s) {
            s = "占大门";
        } else if ("碓磨碓" == s) {
            s = "占碓磨";
        } else if ("房床床" == s) {
            s = "占房床";
        } else if (s.compare(0, door.size(), door) == 0) {
            s = "占" + s;
        }

        s += " ";

        s += Side::IN == side ? "房内" : "外";

        string ds = "北南西东";
        string direction_name = direction.get_name();
        if (Side::OUT == side && ds.find(direction_name) != string::npos) {
            s += "正";
        }
        s += direction_name;
        return s;
    }

    Side FetusDay::get_side() const {
        return side;
    }

    Direction FetusDay::get_direction() const {
        return direction;
    }

    FetusHeavenStem FetusDay::get_fetus_heaven_stem() const {
        return fetus_heaven_stem;
    }

    FetusEarthBranch FetusDay::get_fetus_earth_branch() const {
        return fetus_earth_branch;
    }

    const vector<string> Nine::NAMES = {
        "一九", "二九", "三九", "四九", "五九", "六九", "七九", "八九", "九九"
    };

    Nine Nine::from_index(const int index) {
        return Nine(index);
    }

    Nine Nine::from_name(const string &name) {
        return Nine(name);
    }

    Nine Nine::next(const int n) const {
        return from_index(next_index(n));
    }

    Nine NineDay::get_nine() const {
        return nine;
    }

    int NineDay::get_day_index() const {
        return day_index;
    }

    string NineDay::get_name() const {
        return nine.get_name();
    }

    string NineDay::to_string() const {
        return nine.to_string() + "第" + std::to_string(day_index + 1) + "天";
    }

    const vector<string> PengZuHeavenStem::NAMES = {
        "甲不开仓财物耗散", "乙不栽植千株不长", "丙不修灶必见灾殃", "丁不剃头头必生疮", "戊不受田田主不祥", "己不破券二比并亡", "庚不经络织机虚张", "辛不合酱主人不尝", "壬不泱水更难提防", "癸不词讼理弱敌强"
    };

    PengZuHeavenStem PengZuHeavenStem::from_index(const int index) {
        return PengZuHeavenStem(index);
    }

    PengZuHeavenStem PengZuHeavenStem::from_name(const string &name) {
        return PengZuHeavenStem(name);
    }

    PengZuHeavenStem PengZuHeavenStem::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> PengZuEarthBranch::NAMES = {
        "子不问卜自惹祸殃", "丑不冠带主不还乡", "寅不祭祀神鬼不尝", "卯不穿井水泉不香", "辰不哭泣必主重丧", "巳不远行财物伏藏", "午不苫盖屋主更张", "未不服药毒气入肠", "申不安床鬼祟入房", "酉不会客醉坐颠狂", "戌不吃犬作怪上床", "亥不嫁娶不利新郎"
    };

    PengZuEarthBranch PengZuEarthBranch::from_index(const int index) {
        return PengZuEarthBranch(index);
    }

    PengZuEarthBranch PengZuEarthBranch::from_name(const string &name) {
        return PengZuEarthBranch(name);
    }

    PengZuEarthBranch PengZuEarthBranch::next(const int n) const {
        return from_index(next_index(n));
    }

    PengZu PengZu::from_sixty_cycle(const SixtyCycle &sixty_cycle) {
        return PengZu(sixty_cycle);
    }

    string PengZu::get_name() const {
        return peng_zu_heaven_stem.to_string() + " " + peng_zu_earth_branch.to_string();
    }

    PengZuHeavenStem PengZu::get_peng_zu_heaven_stem() const {
        return peng_zu_heaven_stem;
    }

    PengZuEarthBranch PengZu::get_peng_zu_earth_branch() const {
        return peng_zu_earth_branch;
    }

    const vector<string> Phenology::NAMES = {
        "蚯蚓结", "麋角解", "水泉动", "雁北乡", "鹊始巢", "雉始雊", "鸡始乳", "征鸟厉疾", "水泽腹坚", "东风解冻", "蛰虫始振", "鱼陟负冰", "獭祭鱼", "候雁北", "草木萌动", "桃始华", "仓庚鸣", "鹰化为鸠", "玄鸟至", "雷乃发声", "始电", "桐始华", "田鼠化为鴽", "虹始见", "萍始生", "鸣鸠拂其羽", "戴胜降于桑", "蝼蝈鸣", "蚯蚓出", "王瓜生", "苦菜秀", "靡草死", "麦秋至", "螳螂生", "鵙始鸣", "反舌无声", "鹿角解", "蜩始鸣", "半夏生", "温风至", "蟋蟀居壁", "鹰始挚", "腐草为萤", "土润溽暑", "大雨行时", "凉风至", "白露降", "寒蝉鸣", "鹰乃祭鸟", "天地始肃", "禾乃登", "鸿雁来", "玄鸟归", "群鸟养羞", "雷始收声", "蛰虫坯户", "水始涸", "鸿雁来宾", "雀入大水为蛤", "菊有黄花", "豺乃祭兽", "草木黄落", "蛰虫咸俯", "水始冰", "地始冻", "雉入大水为蜃", "虹藏不见", "天气上升地气下降", "闭塞而成冬", "鹖鴠不鸣", "虎始交", "荔挺出"
    };

    Phenology Phenology::from_index(const int year, const int index) {
        return Phenology(year, index);
    }

    Phenology Phenology::from_name(const int year, const string &name) {
        return Phenology(year, name);
    }

    Phenology Phenology::next(const int n) const {
        const int size = get_size();
        const int i = index + n;
        return from_index((year * size + i) / size, index_of(i));
    }

    int Phenology::get_year() const {
        return year;
    }

    JulianDay Phenology::get_julian_day() const {
        const double t = ShouXingUtil::sa_lon_t((year - 2000 + (index - 18) * 5.0 / 360 + 1) * 2 * M_PI);
        return JulianDay::from_julian_day(t * 36525 + JulianDay::J2000 + 8.0 / 24 - ShouXingUtil::dt_t(t * 36525));
    }

    ThreePhenology Phenology::get_three_phenology() const {
        return ThreePhenology::from_index(index % 3);
    }

    Phenology PhenologyDay::get_phenology() const {
        return phenology;
    }

    int PhenologyDay::get_day_index() const {
        return day_index;
    }

    string PhenologyDay::get_name() const {
        return phenology.get_name();
    }

    string PhenologyDay::to_string() const {
        return phenology.to_string() + "第" + std::to_string(day_index + 1) + "天";
    }

    const vector<string> ThreePhenology::NAMES = {
        "初候", "二候", "三候"
    };

    ThreePhenology ThreePhenology::from_index(const int index) {
        return ThreePhenology(index);
    }

    ThreePhenology ThreePhenology::from_name(const string &name) {
        return ThreePhenology(name);
    }

    ThreePhenology ThreePhenology::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> PlumRain::NAMES = {
        "入梅", "出梅"
    };

    PlumRain PlumRain::from_index(const int index) {
        return PlumRain(index);
    }

    PlumRain PlumRain::from_name(const string &name) {
        return PlumRain(name);
    }

    PlumRain PlumRain::next(const int n) const {
        return from_index(next_index(n));
    }

    PlumRain PlumRainDay::get_plum_rain() const {
        return plum_rain;
    }

    int PlumRainDay::get_day_index() const {
        return day_index;
    }

    string PlumRainDay::get_name() const {
        return plum_rain.get_name();
    }

    string PlumRainDay::to_string() const {
        return get_plum_rain().get_index() == 0 ? plum_rain.to_string() + "第" + std::to_string(day_index + 1) + "天" : get_name();
    }

    const vector<string> MinorRen::NAMES = {
        "大安", "留连", "速喜", "赤口", "小吉", "空亡"
    };

    MinorRen MinorRen::from_index(const int index) {
        return MinorRen(index);
    }

    MinorRen MinorRen::from_name(const string &name) {
        return MinorRen(name);
    }

    MinorRen MinorRen::next(const int n) const {
        return from_index(next_index(n));
    }

    Luck MinorRen::get_luck() const {
        return Luck::from_index(index % 2);
    }

    Element MinorRen::get_element() const {
        const int indices[6] = {0, 4, 1, 3, 0, 2};
        return Element::from_index(indices[index]);
    }

    const vector<string> Dipper::NAMES = {
        "天枢", "天璇", "天玑", "天权", "玉衡", "开阳", "摇光", "洞明", "隐元"
    };

    Dipper Dipper::from_index(const int index) {
        return Dipper(index);
    }

    Dipper Dipper::from_name(const string &name) {
        return Dipper(name);
    }

    Dipper Dipper::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> NineStar::NAMES = {
        "一", "二", "三", "四", "五", "六", "七", "八", "九"
    };

    NineStar NineStar::from_index(const int index) {
        return NineStar(index);
    }

    NineStar NineStar::from_name(const string &name) {
        return NineStar(name);
    }

    NineStar NineStar::next(const int n) const {
        return from_index(next_index(n));
    }

    string NineStar::get_color() const {
        string colors[9] = {"白", "黑", "碧", "绿", "黄", "白", "赤", "白", "紫"};
        return colors[index];
    }

    Element NineStar::get_element() const {
        const int indices[9] = {4, 2, 0, 0, 2, 3, 3, 2, 1};
        return Element::from_index(indices[index]);
    }

    Dipper NineStar::get_dipper() const {
        return Dipper::from_index(index);
    }

    Direction NineStar::get_direction() const {
        return Direction::from_index(index);
    }

    string NineStar::to_string() const {
        return get_name() + get_color() + get_element().to_string();
    }

    const vector<string> SevenStar::NAMES = {
        "日", "月", "火", "水", "木", "金", "土"
    };

    SevenStar SevenStar::from_index(const int index) {
        return SevenStar(index);
    }

    SevenStar SevenStar::from_name(const string &name) {
        return SevenStar(name);
    }

    SevenStar SevenStar::next(const int n) const {
        return from_index(next_index(n));
    }

    Week SevenStar::get_week() const {
        return Week::from_index(index);
    }

    const vector<string> SixStar::NAMES = {
        "先胜", "友引", "先负", "佛灭", "大安", "赤口"
    };

    SixStar SixStar::from_index(const int index) {
        return SixStar(index);
    }

    SixStar SixStar::from_name(const string &name) {
        return SixStar(name);
    }

    SixStar SixStar::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> TenStar::NAMES = {
        "比肩", "劫财", "食神", "伤官", "偏财", "正财", "七杀", "正官", "偏印", "正印"
    };

    TenStar TenStar::from_index(const int index) {
        return TenStar(index);
    }

    TenStar TenStar::from_name(const string &name) {
        return TenStar(name);
    }

    TenStar TenStar::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> Ecliptic::NAMES = {
        "黄道", "黑道"
    };

    Ecliptic Ecliptic::from_index(const int index) {
        return Ecliptic(index);
    }

    Ecliptic Ecliptic::from_name(const string &name) {
        return Ecliptic(name);
    }

    Ecliptic Ecliptic::next(const int n) const {
        return from_index(next_index(n));
    }

    Luck Ecliptic::get_luck() const {
        return Luck::from_index(index);
    }

    const vector<string> TwelveStar::NAMES = {
        "青龙", "明堂", "天刑", "朱雀", "金匮", "天德", "白虎", "玉堂", "天牢", "玄武", "司命", "勾陈"
    };

    TwelveStar TwelveStar::from_index(const int index) {
        return TwelveStar(index);
    }

    TwelveStar TwelveStar::from_name(const string &name) {
        return TwelveStar(name);
    }

    TwelveStar TwelveStar::next(const int n) const {
        return from_index(next_index(n));
    }

    Ecliptic TwelveStar::get_ecliptic() const {
        const int indices[12] = {0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1};
        return Ecliptic::from_index(indices[index]);
    }

    const vector<string> TwentyEightStar::NAMES = {
        "角", "亢", "氐", "房", "心", "尾", "箕", "斗", "牛", "女", "虚", "危", "室", "壁", "奎", "娄", "胃", "昴", "毕", "觜", "参", "井", "鬼", "柳", "星", "张", "翼", "轸"
    };

    TwentyEightStar TwentyEightStar::from_index(const int index) {
        return TwentyEightStar(index);
    }

    TwentyEightStar TwentyEightStar::from_name(const string &name) {
        return TwentyEightStar(name);
    }

    TwentyEightStar TwentyEightStar::next(const int n) const {
        return from_index(next_index(n));
    }

    SevenStar TwentyEightStar::get_seven_star() const {
        return SevenStar::from_index(index % 7 + 4);
    }

    Land TwentyEightStar::get_land() const {
        const int indices[28] = {4, 4, 4, 2, 2, 2, 7, 7, 7, 0, 0, 0, 0, 5, 5, 5, 6, 6, 6, 1, 1, 1, 8, 8, 8, 3, 3, 3};
        return Land::from_index(indices[index]);
    }

    Zone TwentyEightStar::get_zone() const {
        return Zone::from_index(index / 7);
    }

    Animal TwentyEightStar::get_animal() const {
        return Animal::from_index(index);
    }

    Luck TwentyEightStar::get_luck() const {
        const int indices[28] = {0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0};
        return Luck::from_index(indices[index]);
    }

    const double JulianDay::J2000 = 2451545;

    JulianDay JulianDay::from_julian_day(const double day) {
        return JulianDay(day);
    }

    JulianDay JulianDay::from_ymd_hms(const int year, const int month, const int day, const int hour, const int minute, const int second) {
        int y = year;
        int m = month;
        const double d = day + ((second * 1.0 / 60 + minute) / 60 + hour) / 24;
        int n = 0;
        const bool g = y * 372 + m * 31 + static_cast<int>(d) >= 588829;
        if (m <= 2) {
            m += 12;
            y--;
        }
        if (g) {
            n = static_cast<int>(y * 0.01);
            n = 2 - n + static_cast<int>(n * 0.25);
        }
        return from_julian_day(static_cast<int>(365.25 * (y + 4716)) + static_cast<int>(30.6001 * (m + 1)) + d + n - 1524.5);
    }

    double JulianDay::get_day() const {
        return day;
    }

    string JulianDay::get_name() const {
        return std::to_string(day);
    }

    JulianDay JulianDay::next(const int n) const {
        return from_julian_day(day + n);
    }

    Week JulianDay::get_week() const {
        return Week::from_index(static_cast<int>(floor(day + 0.5)) + 7000001);
    }

    double JulianDay::subtract(const JulianDay &target) const {
        return day - target.get_day();
    }

    SolarTime JulianDay::get_solar_time() const {
        int d = static_cast<int>(floor(day + 0.5));
        double f = day + 0.5 - d;

        if (d >= 2299161) {
            const int c = static_cast<int>((d - 1867216.25) / 36524.25);
            d += 1 + c - static_cast<int>(c * 0.25);
        }
        d += 1524;
        int y = static_cast<int>((d - 122.1) / 365.25);
        d -= static_cast<int>(365.25 * y);
        int m = static_cast<int>(d / 30.601);
        d -= static_cast<int>(30.601 * m);
        if (m > 13) {
            m -= 12;
        } else {
            y -= 1;
        }
        m -= 1;
        y -= 4715;
        f *= 24;
        const int hour = static_cast<int>(f);

        f -= hour;
        f *= 60;
        const int minute = static_cast<int>(f);

        f -= minute;
        f *= 60;
        const int second = static_cast<int>(round(f));
        if (second < 60) {
            return SolarTime::from_ymd_hms(y, m, d, hour, minute, second);
        }
        return SolarTime::from_ymd_hms(y, m, d, hour, minute, second - 60).next(60);
    }

    SolarDay JulianDay::get_solar_day() const {
        return get_solar_time().get_solar_day();
    }

    const vector<string> HeavenStem::NAMES = {
        "甲", "乙", "丙", "丁", "戊", "己", "庚", "辛", "壬", "癸"
    };

    HeavenStem HeavenStem::from_index(const int index) {
        return HeavenStem(index);
    }

    HeavenStem HeavenStem::from_name(const string &name) {
        return HeavenStem(name);
    }

    HeavenStem HeavenStem::next(const int n) const {
        return from_index(next_index(n));
    }

    Element HeavenStem::get_element() const {
        return Element::from_index(index / 2);
    }

    YinYang HeavenStem::get_yin_yang() const {
        return index % 2 == 0 ? YinYang::YANG : YinYang::YIN;
    }

    TenStar HeavenStem::get_ten_star(const HeavenStem &target) const {
        const int target_index = target.get_index();
        int offset = target_index - index;
        if (index % 2 != 0 && target_index % 2 == 0) {
            offset += 2;
        }
        return TenStar::from_index(offset);
    }

    Direction HeavenStem::get_direction() const {
        return get_element().get_direction();
    }

    Direction HeavenStem::get_joy_direction() const {
        const int indices[5] = {7, 5, 1, 8, 3};
        return Direction::from_index(indices[index % 5]);
    }

    Direction HeavenStem::get_yang_direction() const {
        const int indices[10] = {1, 1, 6, 5, 7, 0, 8, 7, 2, 3};
        return Direction::from_index(indices[index]);
    }

    Direction HeavenStem::get_yin_direction() const {
        const int indices[10] = {7, 0, 5, 6, 1, 1, 7, 8, 3, 2};
        return Direction::from_index(indices[index]);
    }

    Direction HeavenStem::get_wealth_direction() const {
        const int indices[5] = {7, 1, 0, 2, 8};
        return Direction::from_index(indices[index / 2]);
    }

    Direction HeavenStem::get_mascot_direction() const {
        const int indices[10] = {3, 3, 2, 2, 0, 8, 1, 1, 5, 6};
        return Direction::from_index(indices[index]);
    }

    PengZuHeavenStem HeavenStem::get_peng_zu_heaven_stem() const {
        return PengZuHeavenStem::from_index(index);
    }

    Terrain HeavenStem::get_terrain(const EarthBranch &earth_branch) const {
        const int earth_branch_index = earth_branch.get_index();
        const int indices[10] = {1, 6, 10, 9, 10, 9, 7, 0, 4, 3};
        return Terrain::from_index(indices[index] + (YinYang::YANG == get_yin_yang() ? earth_branch_index : -earth_branch_index));
    }

    HeavenStem HeavenStem::get_combine() const {
        return next(5);
    }

    optional<Element> HeavenStem::combine(const HeavenStem &target) const {
        if (get_combine().equals(target)) {
            return Element::from_index(index + 2);
        }
        return nullopt;
    }

    HeavenStem HideHeavenStem::get_heaven_stem() const {
        return heaven_stem;
    }

    HideHeavenStemType HideHeavenStem::get_type() const {
        return type;
    }

    string HideHeavenStem::get_name() const {
        return heaven_stem.get_name();
    }

    HideHeavenStem HideHeavenStemDay::get_hide_heaven_stem() const {
        return hide_heaven_stem;
    }

    int HideHeavenStemDay::get_day_index() const {
        return day_index;
    }

    string HideHeavenStemDay::get_name() const {
        const HeavenStem heaven_stem = get_hide_heaven_stem().get_heaven_stem();
        return heaven_stem.get_name() + heaven_stem.get_element().get_name();
    }

    string HideHeavenStemDay::to_string() const {
        return get_name() + "第" + std::to_string(day_index + 1) + "天";
    }

    bool HeavenStem::equals(const HeavenStem &other) const {
        return to_string() == other.to_string();
    }

    const vector<string> EarthBranch::NAMES = {
        "子", "丑", "寅", "卯", "辰", "巳", "午", "未", "申", "酉", "戌", "亥"
    };

    EarthBranch EarthBranch::from_index(const int index) {
        return EarthBranch(index);
    }

    EarthBranch EarthBranch::from_name(const string &name) {
        return EarthBranch(name);
    }

    EarthBranch EarthBranch::next(const int n) const {
        return from_index(next_index(n));
    }

    Element EarthBranch::get_element() const {
        const int indices[12] = {4, 2, 0, 0, 2, 1, 1, 2, 3, 3, 2, 4};
        return Element::from_index(indices[index]);
    }

    YinYang EarthBranch::get_yin_yang() const {
        return index % 2 == 0 ? YinYang::YANG : YinYang::YIN;
    }

    HeavenStem EarthBranch::get_hide_heaven_stem_main() const {
        const int indices[12] = {9, 5, 0, 1, 4, 2, 3, 5, 6, 7, 4, 8};
        return HeavenStem::from_index(indices[index]);
    }

    optional<HeavenStem> EarthBranch::get_hide_heaven_stem_middle() const {
        constexpr int indices[12] = {-1, 9, 2, -1, 1, 6, 5, 3, 8, -1, 7, 0};
        const int n = indices[index];
        if (n == -1) {
            return nullopt;
        }
        return HeavenStem::from_index(n);
    }

    optional<HeavenStem> EarthBranch::get_hide_heaven_stem_residual() const {
        constexpr int indices[12] = {-1, 7, 4, -1, 9, 4, -1, 1, 4, -1, 3, -1};
        const int n = indices[index];
        if (n == -1) {
            return nullopt;
        }
        return HeavenStem::from_index(n);
    }

    vector<HideHeavenStem> EarthBranch::get_hide_heaven_stems() const {
        auto l = vector<HideHeavenStem>();
        l.emplace_back(get_hide_heaven_stem_main(), HideHeavenStemType::MAIN);
        optional<HeavenStem> o = get_hide_heaven_stem_middle();
        if (o.has_value()) {
            l.emplace_back(o.value(), HideHeavenStemType::MIDDLE);
        }
        o = get_hide_heaven_stem_residual();
        if (o.has_value()) {
            l.emplace_back(o.value(), HideHeavenStemType::RESIDUAL);
        }
        return l;
    }

    Zodiac EarthBranch::get_zodiac() const {
        return Zodiac::from_index(index);
    }

    Direction EarthBranch::get_direction() const {
        const int indices[12] = {0, 4, 2, 2, 4, 8, 8, 4, 6, 6, 4, 0};
        return Direction::from_index(indices[index]);
    }

    Direction EarthBranch::get_ominous() const {
        constexpr int indices[4] = {8, 2, 0, 6};
        return Direction::from_index(indices[index % 4]);
    }

    PengZuEarthBranch EarthBranch::get_peng_zu_earth_branch() const {
        return PengZuEarthBranch::from_index(index);
    }

    EarthBranch EarthBranch::get_opposite() const {
        return next(6);
    }

    EarthBranch EarthBranch::get_combine() const {
        return from_index(1 - index);
    }

    EarthBranch EarthBranch::get_harm() const {
        return from_index(19 - index);
    }

    optional<Element> EarthBranch::combine(const EarthBranch &target) const {
        if (get_combine().equals(&target)) {
            const int indices[12] = {2, 2, 0, 1, 3, 4, 2, 2, 4, 3, 1, 0};
            return Element::from_index(indices[index]);
        }
        return nullopt;
    }

    const vector<string> SixtyCycle::NAMES = {
        "甲子", "乙丑", "丙寅", "丁卯", "戊辰", "己巳", "庚午", "辛未", "壬申", "癸酉", "甲戌", "乙亥", "丙子", "丁丑", "戊寅", "己卯", "庚辰", "辛巳", "壬午", "癸未", "甲申", "乙酉", "丙戌", "丁亥", "戊子", "己丑", "庚寅", "辛卯", "壬辰", "癸巳", "甲午", "乙未", "丙申", "丁酉", "戊戌", "己亥", "庚子", "辛丑", "壬寅", "癸卯", "甲辰", "乙巳", "丙午", "丁未", "戊申", "己酉", "庚戌", "辛亥", "壬子", "癸丑", "甲寅", "乙卯", "丙辰", "丁巳", "戊午", "己未", "庚申", "辛酉", "壬戌", "癸亥"
    };

    SixtyCycle SixtyCycle::from_index(const int index) {
        return SixtyCycle(index);
    }

    SixtyCycle SixtyCycle::from_name(const string &name) {
        return SixtyCycle(name);
    }

    SixtyCycle SixtyCycle::next(const int n) const {
        return from_index(next_index(n));
    }

    HeavenStem SixtyCycle::get_heaven_stem() const {
        return HeavenStem::from_index(index % static_cast<int>(HeavenStem::NAMES.size()));
    }

    EarthBranch SixtyCycle::get_earth_branch() const {
        return EarthBranch::from_index(index % static_cast<int>(EarthBranch::NAMES.size()));
    }

    Sound SixtyCycle::get_sound() const {
        return Sound::from_index(index / 2);
    }

    PengZu SixtyCycle::get_peng_zu() const {
        return PengZu::from_sixty_cycle(*this);
    }

    Ten SixtyCycle::get_ten() const {
        return Ten::from_index((get_heaven_stem().get_index() - get_earth_branch().get_index()) / 2);
    }

    vector<EarthBranch> SixtyCycle::get_extra_earth_branches() const {
        auto l = vector<EarthBranch>();
        const EarthBranch e = EarthBranch::from_index(10 + get_earth_branch().get_index() - get_heaven_stem().get_index());
        l.push_back(e);
        l.push_back(e.next(1));
        return l;
    }

    SixtyCycleYear SixtyCycleYear::from_year(int year) {
        return SixtyCycleYear(year);
    }

    int SixtyCycleYear::get_year() const {
        return year;
    }

    SixtyCycle SixtyCycleYear::get_sixty_cycle() const {
        return SixtyCycle::from_index(year - 4);
    }

    string SixtyCycleYear::get_name() const {
        return get_sixty_cycle().to_string() + "年";
    }

    Twenty SixtyCycleYear::get_twenty() const {
        return Twenty::from_index(static_cast<int>(floor((year - 1864) / 20.0)));
    }

    NineStar SixtyCycleYear::get_nine_star() const {
        return NineStar::from_index(63 + get_twenty().get_sixty().get_index() * 3 - get_sixty_cycle().get_index());
    }

    Direction SixtyCycleYear::get_jupiter_direction() const {
        const int indices[] = {0, 7, 7, 2, 3, 3, 8, 1, 1, 6, 0, 0};
        return Direction::from_index(indices[get_sixty_cycle().get_earth_branch().get_index()]);
    }

    SixtyCycleYear SixtyCycleYear::next(int n) const {
        return from_year(year + n);
    }

    SixtyCycleMonth SixtyCycleYear::get_first_month() const {
        const HeavenStem h = HeavenStem::from_index((get_sixty_cycle().get_heaven_stem().get_index() + 1) * 2);
        return SixtyCycleMonth(*this, SixtyCycle::from_name(h.get_name() + "寅"));
    }

    vector<SixtyCycleMonth> SixtyCycleYear::get_months() const {
        auto l = vector<SixtyCycleMonth>();
        const SixtyCycleMonth m = get_first_month();
        l.push_back(m);
        for (int i = 1; i < 12; i++) {
            l.push_back(m.next(i));
        }
        return l;
    }

    SixtyCycleMonth SixtyCycleMonth::from_index(int year, int index) {
        return SixtyCycleYear::from_year(year).get_first_month().next(index);
    }

    SixtyCycleYear SixtyCycleMonth::get_sixty_cycle_year() const {
        return year;
    }

    SixtyCycle SixtyCycleMonth::get_year() const {
        return year.get_sixty_cycle();
    }

    SixtyCycle SixtyCycleMonth::get_sixty_cycle() const {
        return month;
    }

    string SixtyCycleMonth::get_name() const {
        return month.to_string() + "月";
    }

    string SixtyCycleMonth::to_string() const {
        return year.to_string() + get_name();
    }

    SixtyCycleMonth SixtyCycleMonth::next(const int n) const {
        return SixtyCycleMonth(SixtyCycleYear::from_year((year.get_year() * 12 + get_index_in_year() + n) / 12), month.next(n));
    }

    int SixtyCycleMonth::get_index_in_year() const {
        return month.get_earth_branch().next(-2).get_index();
    }

    NineStar SixtyCycleMonth::get_nine_star() const {
        int index = month.get_earth_branch().get_index();
        if (index < 2) {
            index += 3;
        }
        return NineStar::from_index(27 - get_year().get_earth_branch().get_index() % 3 * 3 - index);
    }

    Direction SixtyCycleMonth::get_jupiter_direction() const {
        constexpr int indices[] = {7, -1, 1, 3};
        const int n = indices[month.get_earth_branch().next(-2).get_index() % 4];
        if (n == -1) {
            return month.get_heaven_stem().get_direction();
        }
        return Direction::from_index(n);
    }

    SixtyCycleDay SixtyCycleMonth::get_first_day() const {
        return SixtyCycleDay::from_solar_day(SolarTerm::from_index(year.get_year(), 3 + get_index_in_year() * 2).get_solar_day());
    }

    vector<SixtyCycleDay> SixtyCycleMonth::get_days() const {
        auto l = vector<SixtyCycleDay>();
        SixtyCycleDay d = get_first_day();
        while (d.get_sixty_cycle_month().equals(this)) {
            l.push_back(d);
            d = d.next(1);
        }
        return l;
    }

    SixtyCycleDay &SixtyCycleDay::operator=(const SixtyCycleDay &other) {
        solar_day = other.solar_day;
        month = other.month;
        day = other.day;
        return *this;
    }

    SixtyCycleDay SixtyCycleDay::from_solar_day(const SolarDay &solar_day) {
        return SixtyCycleDay(solar_day);
    }

    SolarDay SixtyCycleDay::get_solar_day() const {
        return solar_day;
    }

    SixtyCycleMonth SixtyCycleDay::get_sixty_cycle_month() const {
        return month.value();
    }

    SixtyCycle SixtyCycleDay::get_year() const {
        return get_sixty_cycle_month().get_year();
    }

    SixtyCycle SixtyCycleDay::get_month() const {
        return month.value().get_sixty_cycle();
    }

    SixtyCycle SixtyCycleDay::get_sixty_cycle() const {
        return day.value();
    }

    string SixtyCycleDay::get_name() const {
        return get_sixty_cycle().to_string() + "日";
    }

    string SixtyCycleDay::to_string() const {
        return month.value().to_string() + get_name();
    }

    Duty SixtyCycleDay::get_duty() const {
        return Duty::from_index(get_sixty_cycle().get_earth_branch().get_index() - get_month().get_earth_branch().get_index());
    }

    TwelveStar SixtyCycleDay::get_twelve_star() const {
        return TwelveStar::from_index(get_sixty_cycle().get_earth_branch().get_index() + (8 - get_month().get_earth_branch().get_index() % 6) * 2);
    }

    NineStar SixtyCycleDay::get_nine_star() const {
        const SolarTerm dong_zhi = SolarTerm::from_index(solar_day.get_year(), 0);
        const SolarDay dong_zhi_solar = dong_zhi.get_solar_day();
        const SolarDay xia_zhi_solar = dong_zhi.next(12).get_solar_day();
        const SolarDay dong_zhi_solar2 = dong_zhi.next(24).get_solar_day();
        const int dong_zhi_index = dong_zhi_solar.get_lunar_day().get_sixty_cycle().get_index();
        const int xia_zhi_index = xia_zhi_solar.get_lunar_day().get_sixty_cycle().get_index();
        const int dong_zhi_index2 = dong_zhi_solar2.get_lunar_day().get_sixty_cycle().get_index();
        const SolarDay solar_shun_bai = dong_zhi_solar.next(dong_zhi_index > 29 ? 60 - dong_zhi_index : -dong_zhi_index);
        const SolarDay solar_shun_bai2 = dong_zhi_solar2.next(dong_zhi_index2 > 29 ? 60 - dong_zhi_index2 : -dong_zhi_index2);
        const SolarDay solar_ni_zi = xia_zhi_solar.next(xia_zhi_index > 29 ? 60 - xia_zhi_index : -xia_zhi_index);
        int offset = 0;
        if (!solar_day.is_before(solar_shun_bai) && solar_day.is_before(solar_ni_zi)) {
            offset = solar_day.subtract(solar_shun_bai);
        } else if (!solar_day.is_before(solar_ni_zi) && solar_day.is_before(solar_shun_bai2)) {
            offset = 8 - solar_day.subtract(solar_ni_zi);
        } else if (!solar_day.is_before(solar_shun_bai2)) {
            offset = solar_day.subtract(solar_shun_bai2);
        } else if (solar_day.is_before(solar_shun_bai)) {
            offset = 8 + solar_shun_bai.subtract(solar_day);
        }
        return NineStar::from_index(offset);
    }

    Direction SixtyCycleDay::get_jupiter_direction() const {
        if (const int index = get_sixty_cycle().get_index(); index % 12 < 6) {
            return Element::from_index(index / 12).get_direction();
        }
        return get_sixty_cycle_month().get_sixty_cycle_year().get_jupiter_direction();
    }

    FetusDay SixtyCycleDay::get_fetus_day() const {
        return FetusDay::from_sixty_cycle_day(*this);
    }

    TwentyEightStar SixtyCycleDay::get_twenty_eight_star() const {
        const int indices[] = {10, 18, 26, 6, 14, 22, 2};
        return TwentyEightStar::from_index(indices[solar_day.get_week().get_index()]).next(-7 * get_sixty_cycle().get_earth_branch().get_index());
    }

    vector<God> SixtyCycleDay::get_gods() const {
        return God::get_day_gods(get_month(), get_sixty_cycle());
    }

    vector<Taboo> SixtyCycleDay::get_recommends() const {
        return Taboo::get_day_recommends(get_month(), get_sixty_cycle());
    }

    vector<Taboo> SixtyCycleDay::get_avoids() const {
        return Taboo::get_day_avoids(get_month(), get_sixty_cycle());
    }

    SixtyCycleDay SixtyCycleDay::next(int n) const {
        return from_solar_day(solar_day.next(n));
    }

    vector<SixtyCycleHour> SixtyCycleDay::get_hours() const {
        auto l = vector<SixtyCycleHour>();
        const SolarDay d = solar_day.next(-1);
        SixtyCycleHour h = SixtyCycleHour::from_solar_time(SolarTime::from_ymd_hms(d.get_year(), d.get_month(), d.get_day(), 23, 0, 0));
        l.push_back(h);
        for (int i = 0; i < 11; i++) {
            h = h.next(7200);
            l.push_back(h);
        }
        return l;
    }

    ThreePillars SixtyCycleDay::get_three_pillars() const {
        return ThreePillars(get_year(), get_month(), get_sixty_cycle());
    }

    SixtyCycleHour SixtyCycleHour::from_solar_time(const SolarTime &solar_time) {
        return SixtyCycleHour(solar_time);
    }

    SixtyCycle SixtyCycleHour::get_year() const {
        return get_sixty_cycle_day().get_year();
    }

    SixtyCycle SixtyCycleHour::get_month() const {
        return get_sixty_cycle_day().get_month();
    }

    SixtyCycle SixtyCycleHour::get_day() const {
        return get_sixty_cycle_day().get_sixty_cycle();
    }

    SixtyCycle SixtyCycleHour::get_sixty_cycle() const {
        return hour.value();
    }

    SixtyCycleDay SixtyCycleHour::get_sixty_cycle_day() const {
        return day.value();
    }

    SolarTime SixtyCycleHour::get_solar_time() const {
        return solar_time;
    }

    string SixtyCycleHour::get_name() const {
        return get_sixty_cycle().to_string() + "时";
    }

    string SixtyCycleHour::to_string() const {
        return get_sixty_cycle_day().to_string() + get_name();
    }

    int SixtyCycleHour::get_index_in_day() const {
        int h = solar_time.get_hour();
        if (h == 23) {
            return 0;
        }
        return (h + 1) / 2;
    }

    NineStar SixtyCycleHour::get_nine_star() const {
        const SolarDay solar = solar_time.get_solar_day();
        const SolarTerm dong_zhi = SolarTerm::from_index(solar.get_year(), 0);
        const SolarTerm xia_zhi = dong_zhi.next(12);
        const int earth_branch_index = get_index_in_day() % 12;
        constexpr int indices[] = {8, 5, 2};
        int index = indices[get_day().get_earth_branch().get_index() % 3];
        if (!solar.is_before(dong_zhi.get_julian_day().get_solar_day()) && solar.is_before(xia_zhi.get_julian_day().get_solar_day())) {
            index = 8 + earth_branch_index - index;
        } else {
            index -= earth_branch_index;
        }
        return NineStar::from_index(index);
    }

    TwelveStar SixtyCycleHour::get_twelve_star() const {
        return TwelveStar::from_index(get_sixty_cycle().get_earth_branch().get_index() + (8 - get_day().get_earth_branch().get_index() % 6) * 2);
    }

    vector<Taboo> SixtyCycleHour::get_recommends() const {
        return Taboo::get_hour_recommends(get_day(), get_sixty_cycle());
    }

    vector<Taboo> SixtyCycleHour::get_avoids() const {
        return Taboo::get_hour_avoids(get_day(), get_sixty_cycle());
    }

    SixtyCycleHour SixtyCycleHour::next(const int n) const {
        return from_solar_time(solar_time.next(n));
    }

    EightChar SixtyCycleHour::get_eight_char() const {
        return EightChar(get_year(), get_month(), get_day(), get_sixty_cycle());
    }

    vector<vector<int>> LunarYear::LEAP = vector<vector<int>>();

    LunarYear LunarYear::from_year(const int year) {
        return LunarYear(year);
    }

    LunarYear& LunarYear::operator=(const LunarYear &other) {
        year = other.year;
        return *this;
    }

    int LunarYear::get_year() const {
        return year;
    }

    SixtyCycle LunarYear::get_sixty_cycle() const {
        return SixtyCycle::from_index(year - 4);
    }

    int LunarYear::get_day_count() const {
        int n = 0;
        for (const LunarMonth& m: get_months()) {
            n += m.get_day_count();
        }
        return n;
    }

    int LunarYear::get_month_count() const {
        if (get_leap_month() < 1) {
            return 12;
        }
        return 13;
    }

    string LunarYear::get_name() const {
        return "农历" + get_sixty_cycle().to_string() + "年";
    }

    Twenty LunarYear::get_twenty() const {
        return Twenty::from_index(static_cast<int>(floor((year - 1864) / 20.0)));
    }

    NineStar LunarYear::get_nine_star() const {
        return NineStar::from_index(63 + get_twenty().get_sixty().get_index() * 3 - get_sixty_cycle().get_index());
    }

    Direction LunarYear::get_jupiter_direction() const {
        const int indices[] = {0, 7, 7, 2, 3, 3, 8, 1, 1, 6, 0, 0};
        return Direction::from_index(indices[get_sixty_cycle().get_earth_branch().get_index()]);
    }

    LunarYear LunarYear::next(const int n) const {
        return from_year(year + n);
    }

    int LunarYear::get_leap_month() const {
        if (year == -1) {
            return 11;
        }
        for (int i = 0; i < 12; i++) {
            if (vector<int> l = LEAP[i]; find(l.begin(), l.end(), year) != l.end()) {
                return i + 1;
            }
        }
        return 0;
    }

    KitchenGodSteed LunarYear::get_kitchen_god_steed() const {
        return KitchenGodSteed::from_lunar_year(year);
    }

    LunarMonth LunarYear::get_first_month() const {
        return LunarMonth::from_ym(year, 1);
    }

    vector<LunarMonth> LunarYear::get_months() const {
        auto l = vector<LunarMonth>();
        LunarMonth m = get_first_month();
        while (m.get_year() == year) {
            l.push_back(m);
            m = m.next(1);
        }
        return l;
    }

    const vector<string> LunarSeason::NAMES = {"孟春", "仲春", "季春", "孟夏", "仲夏", "季夏", "孟秋", "仲秋", "季秋", "孟冬", "仲冬", "季冬"};

    LunarSeason LunarSeason::from_index(const int index) {
        return LunarSeason(index);
    }

    LunarSeason LunarSeason::from_name(const string &name) {
        return LunarSeason(name);
    }

    LunarSeason LunarSeason::next(const int n) const {
        return from_index(next_index(n));
    }

    const vector<string> LunarMonth::NAMES = {"正月", "二月", "三月", "四月", "五月", "六月", "七月", "八月", "九月", "十月", "十一月", "十二月"};

    LunarMonth LunarMonth::from_ym(const int year, const int month) {
        return LunarMonth(year, month);
    }

    LunarMonth &LunarMonth::operator=(const LunarMonth &other) {
        year = other.year;
        month = other.month;
        leap = other.leap;
        day_count = other.day_count;
        index_in_year = other.index_in_year;
        first_julian_day = other.first_julian_day;
        return *this;
    }

    LunarYear LunarMonth::get_lunar_year() const {
        return year;
    }

    int LunarMonth::get_year() const {
        return year.get_year();
    }

    int LunarMonth::get_month() const {
        return month;
    }

    int LunarMonth::get_month_with_leap() const {
        if (leap) {
            return -month;
        }
        return month;
    }

    int LunarMonth::get_day_count() const {
        return day_count;
    }

    int LunarMonth::get_index_in_year() const {
        return index_in_year;
    }

    LunarSeason LunarMonth::get_season() const {
        return LunarSeason::from_index(month - 1);
    }

    JulianDay LunarMonth::get_first_julian_day() const {
        return first_julian_day;
    }

    bool LunarMonth::is_leap() const {
        return leap;
    }

    int LunarMonth::get_week_count(int start) const {
        return static_cast<int>(ceil((index_of(first_julian_day.get_week().get_index() - start, 7) + get_day_count()) / 7.0));
    }

    string LunarMonth::get_name() const {
        string s = NAMES[month - 1];
        if (leap) {
            return "闰" + s;
        }
        return s;
    }

    string LunarMonth::to_string() const {
        return year.to_string() + get_name();
    }

    LunarMonth LunarMonth::next(const int n) const {
        if (n == 0) {
            return from_ym(get_year(), get_month_with_leap());
        }
        int m = index_in_year + 1 + n;
        LunarYear y = year;
        if (n > 0) {
            int month_count = y.get_month_count();
            while (m > month_count) {
                m -= month_count;
                y = y.next(1);
                month_count = y.get_month_count();
            }
        } else {
            while (m <= 0) {
                y = y.next(-1);
                m += y.get_month_count();
            }
        }
        bool leap = false;
        if (const int leap_month = y.get_leap_month(); leap_month > 0) {
            if (m == leap_month + 1) {
                leap = true;
            }
            if (m > leap_month) {
                m--;
            }
        }
        if (leap) {
            m = -m;
        }
        return from_ym(y.get_year(), m);
    }

    SixtyCycle LunarMonth::get_sixty_cycle() const {
        return SixtyCycle::from_name(HeavenStem::from_index(year.get_sixty_cycle().get_heaven_stem().get_index() * 2 + month + 1).get_name() + EarthBranch::from_index(month + 1).get_name());
    }

    NineStar LunarMonth::get_nine_star() const {
        int index = get_sixty_cycle().get_earth_branch().get_index();
        if (index < 2) {
            index += 3;
        }
        return NineStar::from_index(27 - year.get_sixty_cycle().get_earth_branch().get_index() % 3 * 3 - index);
    }

    Direction LunarMonth::get_jupiter_direction() const {
        const SixtyCycle sixty_cycle = get_sixty_cycle();
        constexpr int indices[] = {7, -1, 1, 3};
        if (const int n = indices[sixty_cycle.get_earth_branch().next(-2).get_index() % 4]; n != -1) {
            return Direction::from_index(n);
        }
        return sixty_cycle.get_heaven_stem().get_direction();
    }

    optional<FetusMonth> LunarMonth::get_fetus() const {
        return FetusMonth::from_lunar_month(*this);
    }

    MinorRen LunarMonth::get_minor_ren() const {
        return MinorRen::from_index((month - 1) % 6);
    }

    const vector<string> LunarWeek::NAMES = {
        "第一周", "第二周", "第三周", "第四周", "第五周", "第六周"
    };

    LunarWeek LunarWeek::from_ym(const int year, const int month, const int index, const int start) {
        return LunarWeek(year, month, index, start);
    }

    LunarMonth LunarWeek::get_lunar_month() const {
        return month;
    }

    int LunarWeek::get_year() const {
        return month.get_year();
    }

    int LunarWeek::get_month() const {
        return month.get_month();
    }

    int LunarWeek::get_index() const {
        return index;
    }

    Week LunarWeek::get_start() const {
        return start;
    }

    string LunarWeek::get_name() const {
        return NAMES[index];
    }

    string LunarWeek::to_string() const {
        return month.to_string() + get_name();
    }

    LunarWeek LunarWeek::next(const int n) const {
        const int start_index = start.get_index();
        int d = index;
        LunarMonth m = month;
        if (n > 0) {
            d += n;
            int weekCount = m.get_week_count(start_index);
            while (d >= weekCount) {
                d -= weekCount;
                m = m.next(1);
                if (!LunarDay::from_ymd(m.get_year(), m.get_month_with_leap(), 1).get_week().equals(&start)) {
                    d += 1;
                }
                weekCount = m.get_week_count(start_index);
            }
        } else if (n < 0) {
            d += n;
            while (d < 0) {
                if (!LunarDay::from_ymd(m.get_year(), m.get_month_with_leap(), 1).get_week().equals(&start)) {
                    d -= 1;
                }
                m = m.next(-1);
                d += m.get_week_count(start_index);
            }
        }
        return from_ym(m.get_year(), m.get_month_with_leap(), d, start_index);
    }

    LunarDay LunarWeek::get_first_day() const {
        const LunarDay first_day = LunarDay::from_ymd(get_year(), get_month(), 1);
        return first_day.next(index * 7 - index_of(first_day.get_week().get_index() - start.get_index(), 7));
    }

    vector<LunarDay> LunarWeek::get_days() const {
        auto l = vector<LunarDay>();
        const LunarDay d = get_first_day();
        l.push_back(d);
        for (int i = 1; i < 7; i++) {
            l.push_back(d.next(i));
        }
        return l;
    }

    bool LunarWeek::equals(const LunarWeek &other) const {
        return get_first_day().equals(other.get_first_day());
    }

    const vector<string> LunarDay::NAMES = {
        "初一", "初二", "初三", "初四", "初五", "初六", "初七", "初八", "初九", "初十", "十一", "十二", "十三", "十四", "十五", "十六", "十七", "十八", "十九", "二十", "廿一", "廿二", "廿三", "廿四", "廿五", "廿六", "廿七", "廿八", "廿九", "三十"
    };

    LunarDay LunarDay::from_ymd(const int year, const int month, const int day) {
        return LunarDay(year, month, day);
    }

    LunarMonth LunarDay::get_lunar_month() const {
        return month;
    }

    int LunarDay::get_year() const {
        return month.get_year();
    }

    int LunarDay::get_month() const {
        return month.get_month_with_leap();
    }

    int LunarDay::get_day() const {
        return day;
    }

    string LunarDay::get_name() const {
        return NAMES[day - 1];
    }

    string LunarDay::to_string() const {
        return month.to_string() + get_name();
    }

    LunarDay LunarDay::next(const int n) const {
        return get_solar_day().next(n).get_lunar_day();
    }

    bool LunarDay::equals(const LunarDay& other) const {
        return to_string() == other.to_string();
    }

    bool LunarDay::is_before(const LunarDay& other) const {
        const int a_year = get_year();
        if (const int b_year = other.get_year(); a_year != b_year) {
            return a_year < b_year;
        }
        const int a_month = get_month();
        if (const int b_month = other.get_month(); a_month != b_month) {
            return abs(a_month) < abs(b_month);
        }
        return day < other.get_day();
    }

    bool LunarDay::is_after(const LunarDay& other) const {
        const int a_year = get_year();
        if (const int b_year = other.get_year(); a_year != b_year) {
            return a_year > b_year;
        }
        const int a_month = get_month();
        if (const int b_month = other.get_month(); a_month != b_month) {
            return abs(a_month) >= abs(b_month);
        }
        return day > other.get_day();
    }

    Week LunarDay::get_week() const {
        return get_solar_day().get_week();
    }

    SixtyCycle LunarDay::get_sixty_cycle() const {
        const int offset = static_cast<int>(month.get_first_julian_day().next(day - 12).get_day());
        return SixtyCycle::from_name(HeavenStem::from_index(offset).get_name() + EarthBranch::from_index(offset).get_name());
    }

    Duty LunarDay::get_duty() const {
        return get_sixty_cycle_day().get_duty();
    }

    TwelveStar LunarDay::get_twelve_star() const {
        return get_sixty_cycle_day().get_twelve_star();
    }

    NineStar LunarDay::get_nine_star() const {
        const SolarDay d = get_solar_day();
        const SolarTerm dong_zhi = SolarTerm::from_index(d.get_year(), 0);
        const SolarDay dong_zhi_solar = dong_zhi.get_solar_day();
        const SolarDay xia_zhi_solar = dong_zhi.next(12).get_solar_day();
        const SolarDay dong_zhi_solar2 = dong_zhi.next(24).get_solar_day();
        const int dong_zhi_index = dong_zhi_solar.get_lunar_day().get_sixty_cycle().get_index();
        const int xia_zhi_index = xia_zhi_solar.get_lunar_day().get_sixty_cycle().get_index();
        const int dong_zhi_index2 = dong_zhi_solar2.get_lunar_day().get_sixty_cycle().get_index();
        const SolarDay solar_shun_bai = dong_zhi_solar.next(dong_zhi_index > 29 ? 60 - dong_zhi_index : -dong_zhi_index);
        const SolarDay solar_shun_bai2 = dong_zhi_solar2.next(dong_zhi_index2 > 29 ? 60 - dong_zhi_index2 : -dong_zhi_index2);
        const SolarDay solar_ni_zi = xia_zhi_solar.next(xia_zhi_index > 29 ? 60 - xia_zhi_index : -xia_zhi_index);
        int offset = 0;
        if (!d.is_before(solar_shun_bai) && d.is_before(solar_ni_zi)) {
            offset = d.subtract(solar_shun_bai);
        } else if (!d.is_before(solar_ni_zi) && d.is_before(solar_shun_bai2)) {
            offset = 8 - d.subtract(solar_ni_zi);
        } else if (!d.is_before(solar_shun_bai2)) {
            offset = d.subtract(solar_shun_bai2);
        } else if (d.is_before(solar_shun_bai)) {
            offset = 8 + solar_shun_bai.subtract(d);
        }
        return NineStar::from_index(offset);
    }

    Direction LunarDay::get_jupiter_direction() const {
        if (const int index = get_sixty_cycle().get_index(); index % 12 < 6) {
            return Element::from_index(index / 12).get_direction();
        }
        return month.get_lunar_year().get_jupiter_direction();
    }

    FetusDay LunarDay::get_fetus_day() const {
        return FetusDay::from_lunar_day(*this);
    }

    PhaseDay LunarDay::get_phase_day() const {
        const SolarDay today = get_solar_day();
        const LunarMonth m = month.next(1);
        Phase p = Phase::from_index(m.get_year(), m.get_month_with_leap(), 0);
        SolarDay d = p.get_solar_day();
        while (d.is_after(today)) {
            p = p.next(-1);
            d = p.get_solar_day();
        }
        return PhaseDay(p, today.subtract(d));
    }

    Phase LunarDay::get_phase() const {
        return get_phase_day().get_phase();
    }

    SixStar LunarDay::get_six_star() const {
        return SixStar::from_index((month.get_month() + day - 2) % 6);
    }

    SolarDay LunarDay::get_solar_day() const {
        return month.get_first_julian_day().next(day - 1).get_solar_day();
    }

    SixtyCycleDay LunarDay::get_sixty_cycle_day() const {
        return get_solar_day().get_sixty_cycle_day();
    }

    TwentyEightStar LunarDay::get_twenty_eight_star() const {
        const int indices[] = {10, 18, 26, 6, 14, 22, 2};
        return TwentyEightStar::from_index(indices[get_solar_day().get_week().get_index()]).next(-7 * get_sixty_cycle().get_earth_branch().get_index());
    }

    vector<God> LunarDay::get_gods() const {
        return get_sixty_cycle_day().get_gods();
    }

    vector<Taboo> LunarDay::get_recommends() const {
        return get_sixty_cycle_day().get_recommends();
    }

    vector<Taboo> LunarDay::get_avoids() const {
        return get_sixty_cycle_day().get_avoids();
    }

    MinorRen LunarDay::get_minor_ren() const {
        return get_lunar_month().get_minor_ren().next(day - 1);
    }

    optional<LunarFestival> LunarDay::get_festival() const {
        return LunarFestival::from_ymd(get_year(), get_month(), day);
    }

    ThreePillars LunarDay::get_three_pillars() const {
        return get_sixty_cycle_day().get_three_pillars();
    }

    LunarHour LunarHour::from_ymd_hms(const int year, const int month, int day, int hour, const int minute, int second) {
        return LunarHour(year, month, day, hour, minute, second);
    }

    LunarDay LunarHour::get_lunar_day() const {
        return day;
    }

    int LunarHour::get_year() const {
        return day.get_year();
    }

    int LunarHour::get_month() const {
        return day.get_month();
    }

    int LunarHour::get_day() const {
        return day.get_day();
    }

    int LunarHour::get_hour() const {
        return hour;
    }

    int LunarHour::get_minute() const {
        return minute;
    }

    int LunarHour::get_second() const {
        return second;
    }

    string LunarHour::get_name() const {
        return EarthBranch::from_index(get_index_in_day()).get_name() + "时";
    }

    string LunarHour::to_string() const {
        return day.to_string() + get_sixty_cycle().get_name() + "时";
    }

    int LunarHour::get_index_in_day() const {
        return (hour + 1) / 2;
    }

    LunarHour LunarHour::next(int n) const {
        if (n == 0) {
            return from_ymd_hms(get_year(), get_month(), get_day(), hour, minute, second);
        }
        const int h = hour + n * 2;
        int diff = 1;
        if (h < 0) {
            diff = -1;
        }
        int hour = abs(h);
        int days = hour / 24 * diff;
        hour = hour % 24 * diff;
        if (hour < 0) {
            hour += 24;
            days--;
        }
        const LunarDay d = day.next(days);
        return from_ymd_hms(d.get_year(), d.get_month(), d.get_day(), hour, minute, second);
    }

    bool LunarHour::is_before(const LunarHour &other) const {
        if (!day.equals(other.get_lunar_day())) {
            return day.is_before(other.get_lunar_day());
        }
        if (hour != other.get_hour()) {
            return hour < other.get_hour();
        }
        if (minute != other.get_minute()) {
            return minute < other.get_minute();
        }
        return second < other.get_second();
    }

    bool LunarHour::is_after(const LunarHour &other) const {
        if (!day.equals(other.get_lunar_day())) {
            return day.is_after(other.get_lunar_day());
        }
        if (hour != other.get_hour()) {
            return hour > other.get_hour();
        }
        if (minute != other.get_minute()) {
            return minute > other.get_minute();
        }
        return second > other.get_second();
    }

    SixtyCycle LunarHour::get_sixty_cycle() const {
        const int earth_branch_index = get_index_in_day() % 12;
        SixtyCycle d = day.get_sixty_cycle();
        if (hour >= 23) {
            d = d.next(1);
        }
        return SixtyCycle::from_name(HeavenStem::from_index(d.get_heaven_stem().get_index() % 5 * 2 + earth_branch_index).get_name() + EarthBranch::from_index(earth_branch_index).get_name());
    }

    TwelveStar LunarHour::get_twelve_star() const {
        return TwelveStar::from_index(get_sixty_cycle().get_earth_branch().get_index() + (8 - get_sixty_cycle_hour().get_day().get_earth_branch().get_index() % 6) * 2);
    }

    NineStar LunarHour::get_nine_star() const {
        const SolarDay solar = day.get_solar_day();
        const SolarTerm dong_zhi = SolarTerm::from_index(solar.get_year(), 0);
        const int earth_branch_index = get_index_in_day() % 12;
        constexpr int indices[] = {8, 5, 2};
        int index = indices[day.get_sixty_cycle().get_earth_branch().get_index() % 3];
        if (!solar.is_before(dong_zhi.get_julian_day().get_solar_day()) && solar.is_before(dong_zhi.next(12).get_julian_day().get_solar_day())) {
            index = 8 + earth_branch_index - index;
        } else {
            index -= earth_branch_index;
        }
        return NineStar::from_index(index);
    }

    SolarTime LunarHour::get_solar_time() const {
        const SolarDay d = day.get_solar_day();
        return SolarTime::from_ymd_hms(d.get_year(), d.get_month(), d.get_day(), hour, minute, second);
    }

    SixtyCycleHour LunarHour::get_sixty_cycle_hour() const {
        return get_solar_time().get_sixty_cycle_hour();
    }

    vector<Taboo> LunarHour::get_recommends() const {
        return Taboo::get_hour_recommends(get_sixty_cycle_hour().get_day(), get_sixty_cycle());
    }

    vector<Taboo> LunarHour::get_avoids() const {
        return Taboo::get_hour_avoids(get_sixty_cycle_hour().get_day(), get_sixty_cycle());
    }

    MinorRen LunarHour::get_minor_ren() const {
        return get_lunar_day().get_minor_ren().next(get_index_in_day());
    }

    EightChar LunarHour::get_eight_char() const {
        return provider->get_eight_char(*this);
    }

    EightCharProvider* LunarHour::provider = new DefaultEightCharProvider();

    const vector<string> SolarTerm::NAMES = {
        "冬至", "小寒", "大寒", "立春", "雨水", "惊蛰", "春分", "清明", "谷雨", "立夏", "小满", "芒种", "夏至", "小暑", "大暑", "立秋", "处暑", "白露", "秋分", "寒露", "霜降", "立冬", "小雪", "大雪"
    };

    void SolarTerm::init_by_year(const int year, const int offset) {
        const double jd = floor((year - 2000) * 365.2422 + 180);
        // 355是2000.12冬至，得到较靠近jd的冬至估计值
        double w = floor((jd - 355 + 183) / 365.2422) * 365.2422 + 355;
        if (ShouXingUtil::calc_qi(w) > jd) {
            w -= 365.2422;
        }
        this->year = year;
        cursory_julian_day = ShouXingUtil::calc_qi(w + 15.2184 * offset);
    }

    SolarTerm SolarTerm::from_index(const int year, const int index) {
        return SolarTerm(year, index);
    }

    SolarTerm SolarTerm::from_name(const int year, const string &name) {
        return SolarTerm(year, name);
    }

    SolarTerm SolarTerm::next(const int n) const {
        const int size = get_size();
        const int i = index + n;
        return from_index((year * size + i) / size, index_of(i));
    }

    bool SolarTerm::is_jie() const {
        return index % 2 == 1;
    }

    bool SolarTerm::is_qi() const {
        return index % 2 == 0;
    }

    JulianDay SolarTerm::get_julian_day() const {
        return JulianDay::from_julian_day(ShouXingUtil::qi_accurate2(cursory_julian_day) + JulianDay::J2000);
    }

    SolarDay SolarTerm::get_solar_day() const {
        return JulianDay::from_julian_day(cursory_julian_day + JulianDay::J2000).get_solar_day();
    }

    int SolarTerm::get_year() const {
        return year;
    }

    double SolarTerm::get_cursory_julian_day() const {
        return cursory_julian_day;
    }

    SolarTerm SolarTermDay::get_solar_term() const {
        return solar_term;
    }

    int SolarTermDay::get_day_index() const {
        return day_index;
    }

    string SolarTermDay::get_name() const {
        return solar_term.get_name();
    }

    string SolarTermDay::to_string() const {
        return solar_term.to_string() + "第" + std::to_string(day_index + 1) + "天";
    }

    SolarYear SolarYear::from_year(const int year) {
        return SolarYear(year);
    }

    int SolarYear::get_day_count() const {
        if (1582 == year) {
            return 355;
        }
        if (is_leap()) {
            return 366;
        }
        return 365;
    }

    bool SolarYear::is_leap() const {
        if (year < 1600) {
            return year % 4 == 0;
        }
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }

    string SolarYear::get_name() const {
        return std::to_string(year) + "年";
    }

    SolarYear SolarYear::next(const int n) const {
        return from_year(year + n);
    }

    int SolarYear::get_year() const {
        return year;
    }

    vector<SolarMonth> SolarYear::get_months() const {
        auto l = vector<SolarMonth>();
        for (int i = 1; i < 13; i++) {
            l.push_back(SolarMonth::from_ym(year, i));
        }
        return l;
    }

    vector<SolarSeason> SolarYear::get_seasons() const {
        auto l = vector<SolarSeason>();
        for (int i = 0; i < 4; i++) {
            l.push_back(SolarSeason::from_index(year, i));
        }
        return l;
    }

    vector<SolarHalfYear> SolarYear::get_half_years() const {
        auto l = vector<SolarHalfYear>();
        for (int i = 0; i < 2; i++) {
            l.push_back(SolarHalfYear::from_index(year, i));
        }
        return l;
    }

    const vector<string> SolarHalfYear::NAMES = {
        "上半年", "下半年"
    };

    SolarHalfYear SolarHalfYear::from_index(const int year, const int index) {
        return SolarHalfYear(year, index);
    }

    SolarYear SolarHalfYear::get_solar_year() const {
        return year;
    }

    int SolarHalfYear::get_year() const {
        return year.get_year();
    }

    int SolarHalfYear::get_index() const {
        return index;
    }

    string SolarHalfYear::get_name() const {
        return NAMES[index];
    }

    string SolarHalfYear::to_string() const {
        return year.to_string() + get_name();
    }

    SolarHalfYear SolarHalfYear::next(const int n) const {
        const int i = index + n;
        return from_index((get_year() * 2 + i) / 2, index_of(i, 2));
    }

    vector<SolarSeason> SolarHalfYear::get_seasons() const {
        auto l = vector<SolarSeason>();
        const int y = get_year();
        for (int i = 0; i < 2; i++) {
            l.push_back(SolarSeason::from_index(y, index * 2 + i));
        }
        return l;
    }

    vector<SolarMonth> SolarHalfYear::get_months() const {
        auto l = vector<SolarMonth>();
        const int y = get_year();
        for (int i = 1; i < 7; i++) {
            l.push_back(SolarMonth::from_ym(y, index * 6 + i));
        }
        return l;
    }

    const vector<string> SolarSeason::NAMES = {
        "一季度", "二季度", "三季度", "四季度"
    };

    SolarSeason SolarSeason::from_index(const int year, const int index) {
        return SolarSeason(year, index);
    }

    SolarYear SolarSeason::get_solar_year() const {
        return year;
    }

    int SolarSeason::get_year() const {
        return year.get_year();
    }

    int SolarSeason::get_index() const {
        return index;
    }

    string SolarSeason::get_name() const {
        return NAMES[index];
    }

    string SolarSeason::to_string() const {
        return year.to_string() + get_name();
    }

    SolarSeason SolarSeason::next(const int n) const {
        const int i = index + n;
        return from_index((get_year() * 4 + i) / 4, index_of(i, 4));
    }

    vector<SolarMonth> SolarSeason::get_months() const {
        auto l = vector<SolarMonth>();
        const int y = get_year();
        for (int i = 1; i < 4; i++) {
            l.push_back(SolarMonth::from_ym(y, index * 3 + i));
        }
        return l;
    }

    const vector<string> SolarMonth::NAMES = {
        "1月", "2月", "3月", "4月", "5月", "6月", "7月", "8月", "9月", "10月", "11月", "12月"
    };

    const int SolarMonth::DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    SolarMonth SolarMonth::from_ym(const int year, const int month) {
        return SolarMonth(year, month);
    }

    SolarYear SolarMonth::get_solar_year() const {
        return year;
    }

    int SolarMonth::get_year() const {
        return year.get_year();
    }

    int SolarMonth::get_month() const {
        return month;
    }

    int SolarMonth::get_day_count() const {
        if (1582 == get_year() && 10 == month) {
            return 21;
        }
        int d = DAYS[get_index_in_year()];
        //公历闰年2月多一天
        if (2 == month && year.is_leap()) {
            d++;
        }
        return d;
    }

    int SolarMonth::get_index_in_year() const {
        return month - 1;
    }

    SolarSeason SolarMonth::get_season() const {
        return SolarSeason::from_index(get_year(), get_index_in_year() / 3);
    }

    int SolarMonth::get_week_count(const int start) const {
        return static_cast<int>(ceil((index_of(SolarDay::from_ymd(get_year(), month, 1).get_week().get_index() - start, 7) + get_day_count()) / 7.0));
    }

    string SolarMonth::get_name() const {
        return NAMES[get_index_in_year()];
    }

    string SolarMonth::to_string() const {
        return year.to_string() + get_name();
    }

    SolarMonth SolarMonth::next(const int n) const {
        const int i = month - 1 + n;
        return from_ym((get_year() * 12 + i) / 12, index_of(i, 12) + 1);
    }

    vector<SolarWeek> SolarMonth::get_weeks(const int start) const {
        const int size = get_week_count(start);
        const int y = get_year();
        auto l = vector<SolarWeek>();
        for (int i = 0; i < size; i++) {
            l.push_back(SolarWeek::from_ym(y, month, i, start));
        }
        return l;
    }

    vector<SolarDay> SolarMonth::get_days() const {
        const int size = get_day_count();
        const int y = get_year();
        auto l = vector<SolarDay>();
        for (int i = 1; i <= size; i++) {
            l.push_back(SolarDay::from_ymd(y, month, i));
        }
        return l;
    }

    const vector<string> SolarWeek::NAMES = {
        "第一周", "第二周", "第三周", "第四周", "第五周", "第六周"
    };

    SolarWeek SolarWeek::from_ym(const int year, const int month, const int index, const int start) {
        return SolarWeek(year, month, index, start);
    }

    SolarMonth SolarWeek::get_solar_month() const {
        return month;
    }

    int SolarWeek::get_year() const {
        return month.get_year();
    }

    int SolarWeek::get_month() const {
        return month.get_month();
    }

    int SolarWeek::get_index() const {
        return index;
    }

    int SolarWeek::get_index_in_year() const {
        int i = 0;
        const SolarDay first_day = get_first_day();
        // 今年第1周
        SolarWeek w = from_ym(get_year(), 1, 0, start.get_index());
        while (!w.get_first_day().equals(first_day)) {
            w = w.next(1);
            i++;
        }
        return i;
    }

    Week SolarWeek::get_start() const {
        return start;
    }

    string SolarWeek::get_name() const {
        return NAMES[index];
    }

    string SolarWeek::to_string() const {
        return month.to_string() + get_name();
    }

    SolarWeek SolarWeek::next(const int n) const {
        const int start_index = start.get_index();
        int d = index;
        SolarMonth m = month;
        if (n > 0) {
            d += n;
            int week_count = m.get_week_count(start_index);
            while (d >= week_count) {
                d -= week_count;
                m = m.next(1);
                if (!SolarDay::from_ymd(m.get_year(), m.get_month(), 1).get_week().equals(&start)) {
                    d += 1;
                }
                week_count = m.get_week_count(start_index);
            }
        } else if (n < 0) {
            d += n;
            while (d < 0) {
                if (!SolarDay::from_ymd(m.get_year(), m.get_month(), 1).get_week().equals(&start)) {
                    d -= 1;
                }
                m = m.next(-1);
                d += m.get_week_count(start_index);
            }
        }
        return from_ym(m.get_year(), m.get_month(), d, start_index);
    }

    SolarDay SolarWeek::get_first_day() const {
        const SolarDay first_day = SolarDay::from_ymd(get_year(), get_month(), 1);
        return first_day.next(index * 7 - index_of(first_day.get_week().get_index() - start.get_index(), 7));
    }

    vector<SolarDay> SolarWeek::get_days() const {
        auto l = vector<SolarDay>();
        const SolarDay d = get_first_day();
        l.push_back(d);
        for (int i = 1; i < 7; i++) {
            l.push_back(d.next(i));
        }
        return l;
    }

    bool SolarWeek::equals(const SolarWeek &other) const {
        return get_first_day().equals(other.get_first_day());
    }

    const vector<string> SolarDay::NAMES = {
        "1日", "2日", "3日", "4日", "5日", "6日", "7日", "8日", "9日", "10日", "11日", "12日", "13日", "14日", "15日", "16日", "17日", "18日", "19日", "20日", "21日", "22日", "23日", "24日", "25日", "26日", "27日", "28日", "29日", "30日", "31日"
    };

    SolarDay SolarDay::from_ymd(const int year, const int month, const int day) {
        return SolarDay(year, month, day);
    }

    SolarMonth SolarDay::get_solar_month() const {
        return month;
    }

    int SolarDay::get_year() const {
        return month.get_year();
    }

    int SolarDay::get_month() const {
        return month.get_month();
    }

    int SolarDay::get_day() const {
        return day;
    }

    Week SolarDay::get_week() const {
        return get_julian_day().get_week();
    }

    Constellation SolarDay::get_constellation() const {
        const int y = get_month() * 100 + day;
        int i = 8;
        if (y > 1221 || y < 120) {
            i = 9;
        } else if (y < 219) {
            i = 10;
        } else if (y < 321) {
            i = 11;
        } else if (y < 420) {
            i = 0;
        } else if (y < 521) {
            i = 1;
        } else if (y < 622) {
            i = 2;
        } else if (y < 723) {
            i = 3;
        } else if (y < 823) {
            i = 4;
        } else if (y < 923) {
            i = 5;
        } else if (y < 1024) {
            i = 6;
        } else if (y < 1123) {
            i = 7;
        }
        return Constellation::from_index(i);
    }

    string SolarDay::get_name() const {
        return NAMES[day - 1];
    }

    string SolarDay::to_string() const {
        return month.to_string() + get_name();
    }

    JulianDay SolarDay::get_julian_day() const {
        return JulianDay::from_ymd_hms(get_year(), get_month(), day, 0, 0, 0);
    }

    SolarDay SolarDay::next(const int n) const {
        return get_julian_day().next(n).get_solar_day();
    }

    bool SolarDay::is_before(const SolarDay &other) const {
        const int a_year = get_year();
        if (const int b_year = other.get_year(); a_year != b_year) {
            return a_year < b_year;
        }
        const int a_month = get_month();
        if (const int b_month = other.get_month(); a_month != b_month) {
            return a_month < b_month;
        }
        return day < other.get_day();
    }

    bool SolarDay::is_after(const SolarDay &other) const {
        const int a_year = get_year();
        if (const int b_year = other.get_year(); a_year != b_year) {
            return a_year > b_year;
        }
        const int a_month = get_month();
        if (const int b_month = other.get_month(); a_month != b_month) {
            return a_month > b_month;
        }
        return day > other.get_day();
    }

    SolarTerm SolarDay::get_term() const {
        return get_term_day().get_solar_term();
    }

    SolarTermDay SolarDay::get_term_day() const {
        int y = get_year();
        int i = get_month() * 2;
        if (i == 24) {
            y += 1;
            i = 0;
        }
        SolarTerm term = SolarTerm::from_index(y, i);
        SolarDay day = term.get_solar_day();
        while (is_before(day)) {
            term = term.next(-1);
            day = term.get_solar_day();
        }
        return SolarTermDay(term, subtract(day));
    }

    SolarWeek SolarDay::get_solar_week(const int start) const {
        const int y = get_year();
        const int m = get_month();
        return SolarWeek::from_ym(y, m, static_cast<int>(ceil((day + from_ymd(y, m, 1).get_week().next(-start).get_index()) / 7.0)) - 1, start);
    }

    Phenology SolarDay::get_phenology() const {
        return get_phenology_day().get_phenology();
    }

    PhenologyDay SolarDay::get_phenology_day() const {
        const SolarTermDay d = get_term_day();
        const int day_index = d.get_day_index();
        int index = day_index / 5;
        if (index > 2) {
            index = 2;
        }
        const SolarTerm term = d.get_solar_term();
        Phenology p = Phenology::from_index(term.get_year(), term.get_index() * 3 + index);
        return PhenologyDay(p, day_index - index * 5);
    }

    optional<DogDay> SolarDay::get_dog_day() const {
        // 夏至
        const SolarTerm xia_zhi = SolarTerm::from_index(get_year(), 12);
        SolarDay start = xia_zhi.get_solar_day();
        // 第3个庚日，即初伏第1天
        start = start.next(start.get_lunar_day().get_sixty_cycle().get_heaven_stem().steps_to(6) + 20);
        int days = subtract(start);
        // 初伏以前
        if (days < 0) {
            return nullopt;
        }
        if (days < 10) {
            Dog d = Dog::from_index(0);
            return DogDay(d, days);
        }
        // 第4个庚日，中伏第1天
        start = start.next(10);
        days = subtract(start);
        if (days < 10) {
            Dog d = Dog::from_index(1);
            return DogDay(d, days);
        }
        // 第5个庚日，中伏第11天或末伏第1天
        start = start.next(10);
        days = subtract(start);
        // 立秋
        if (xia_zhi.next(3).get_solar_day().is_after(start)) {
            if (days < 10) {
                Dog d = Dog::from_index(1);
                return DogDay(d, days + 10);
            }
            start = start.next(10);
            days = subtract(start);
        }
        if (days >= 10) {
            return nullopt;
        }
        Dog d = Dog::from_index(2);
        return DogDay(d, days);
    }

    optional<NineDay> SolarDay::get_nine_day() const {
        const int year = get_year();
        SolarDay start = SolarTerm::from_index(year + 1, 0).get_solar_day();
        if (is_before(start)) {
            start = SolarTerm::from_index(year, 0).get_solar_day();
        }
        if (const SolarDay end = start.next(81); is_before(start) || !is_before(end)) {
            return nullopt;
        }
        const int days = subtract(start);
        Nine n = Nine::from_index(days / 9);
        return NineDay(n, days % 9);
    }

    optional<PlumRainDay> SolarDay::get_plum_rain_day() const {
        // 芒种
        const SolarTerm grain_in_ear = SolarTerm::from_index(get_year(), 11);
        SolarDay start = grain_in_ear.get_solar_day();
        // 芒种后的第1个丙日
        start = start.next(start.get_lunar_day().get_sixty_cycle().get_heaven_stem().steps_to(2));

        // 小暑
        SolarDay end = grain_in_ear.next(2).get_solar_day();
        // 小暑后的第1个未日
        end = end.next(end.get_lunar_day().get_sixty_cycle().get_earth_branch().steps_to(7));

        if (is_before(start) || is_after(end)) {
            return nullopt;
        }
        if (equals(end)) {
            PlumRain p = PlumRain::from_index(1);
            return PlumRainDay(p, 0);
        }
        PlumRain p = PlumRain::from_index(0);
        return PlumRainDay(p, subtract(start));
    }

    HideHeavenStemDay SolarDay::get_hide_heaven_stem_day() const {
        const int day_counts[] = {3, 5, 7, 9, 10, 30};
        SolarTerm term = get_term();
        if (term.is_qi()) {
            term = term.next(-1);
        }
        int day_index = subtract(term.get_solar_day());
        const int start_index = (term.get_index() - 1) * 3;
        string data = "93705542220504xx1513904541632524533533105544806564xx7573304542018584xx95";
        data = data.substr(start_index, 6);
        int days = 0;
        int heaven_stem_index = 0;
        int type_index = 0;
        while (type_index < 3) {
            const int i = type_index * 2;
            string d = data.substr(i, 1);
            int count = 0;
            if (d != "x") {
                heaven_stem_index = stoi(d);
                count = day_counts[stoi(data.substr(i + 1, 1))];
                days += count;
            }
            if (day_index <= days) {
                day_index -= days - count;
                break;
            }
            type_index++;
        }
        HideHeavenStemType type;
        switch (type_index) {
            case 1:
                type = HideHeavenStemType::MIDDLE;
                break;
            case 2:
                type = HideHeavenStemType::MAIN;
                break;
            default:
                type = HideHeavenStemType::RESIDUAL;
        }
        return HideHeavenStemDay(HideHeavenStem(heaven_stem_index, type), day_index);
    }

    int SolarDay::get_index_in_year() const {
        return subtract(from_ymd(get_year(), 1, 1));
    }

    int SolarDay::subtract(const SolarDay &other) const {
        return static_cast<int>(get_julian_day().subtract(other.get_julian_day()));
    }

    bool SolarDay::equals(const SolarDay &other) const {
        return to_string() == other.to_string();
    }

    LunarDay SolarDay::get_lunar_day() const {
        LunarMonth m = LunarMonth::from_ym(get_year(), get_month());
        int days = subtract(m.get_first_julian_day().get_solar_day());
        while (days < 0) {
            m = m.next(-1);
            days += m.get_day_count();
        }
        return LunarDay::from_ymd(m.get_year(), m.get_month_with_leap(), days + 1);
    }

    SixtyCycleDay SolarDay::get_sixty_cycle_day() const {
        return SixtyCycleDay::from_solar_day(*this);
    }

    RabByungDay SolarDay::get_rab_byung_day() const {
        return RabByungDay::from_solar_day(*this);
    }

    optional<SolarFestival> SolarDay::get_festival() const {
        return SolarFestival::from_ymd(get_year(), get_month(), get_day());
    }

    PhaseDay SolarDay::get_phase_day() const {
        const LunarMonth month = get_lunar_day().get_lunar_month().next(1);
        Phase p = Phase::from_index(month.get_year(), month.get_month_with_leap(), 0);
        SolarDay d = p.get_solar_day();
        while (d.is_after(*this)) {
            p = p.next(-1);
            d = p.get_solar_day();
        }
        return PhaseDay(p, subtract(d));
    }

    Phase SolarDay::get_phase() const {
        return get_phase_day().get_phase();
    }

    SolarTime &SolarTime::operator=(const SolarTime &other) {
        day = other.day;
        hour = other.hour;
        minute = other.minute;
        second = other.second;
        return *this;
    }

    SolarTime SolarTime::from_ymd_hms(const int year, const int month, const int day, const int hour, const int minute, const int second) {
        return SolarTime(year, month, day, hour, minute, second);
    }

    SolarDay SolarTime::get_solar_day() const {
        return day;
    }

    int SolarTime::get_year() const {
        return day.get_year();
    }

    int SolarTime::get_month() const {
        return day.get_month();
    }

    int SolarTime::get_day() const {
        return day.get_day();
    }

    int SolarTime::get_hour() const {
        return hour;
    }

    int SolarTime::get_minute() const {
        return minute;
    }

    int SolarTime::get_second() const {
        return second;
    }

    string SolarTime::get_name() const {
        char buffer[9];
        snprintf(buffer, sizeof(buffer), "%02d:%02d:%02d", hour, minute, second);
        return {buffer};
    }

    string SolarTime::to_string() const {
        return day.to_string() + " " + get_name();
    }

    SolarTime SolarTime::next(const int n) const {
        if (n == 0) {
            return from_ymd_hms(get_year(), get_month(), get_day(), hour, minute, second);
        }
        int ts = second + n;
        int tm = minute + ts / 60;
        ts %= 60;
        if (ts < 0) {
            ts += 60;
            tm -= 1;
        }
        int th = hour + tm / 60;
        tm %= 60;
        if (tm < 0) {
            tm += 60;
            th -= 1;
        }
        int td = th / 24;
        th %= 24;
        if (th < 0) {
            th += 24;
            td -= 1;
        }

        const SolarDay d = day.next(td);
        return from_ymd_hms(d.get_year(), d.get_month(), d.get_day(), th, tm, ts);
    }

    bool SolarTime::is_before(const SolarTime &other) const {
        if (!day.equals(other.get_solar_day())) {
            return day.is_before(other.get_solar_day());
        }
        if (hour != other.get_hour()) {
            return hour < other.get_hour();
        }
        if (minute != other.get_minute()) {
            return minute < other.get_minute();
        }
        return second < other.get_second();
    }

    bool SolarTime::is_after(const SolarTime &other) const {
        if (!day.equals(other.get_solar_day())) {
            return day.is_after(other.get_solar_day());
        }
        if (hour != other.get_hour()) {
            return hour > other.get_hour();
        }
        if (minute != other.get_minute()) {
            return minute > other.get_minute();
        }
        return second > other.get_second();
    }

    SolarTerm SolarTime::get_term() const {
        SolarTerm term = day.get_term();
        if (is_before(term.get_julian_day().get_solar_time())) {
            term = term.next(-1);
        }
        return term;
    }

    Phenology SolarTime::get_phenology() const {
        Phenology p = day.get_phenology();
        if (is_before(p.get_julian_day().get_solar_time())) {
            p = p.next(-1);
        }
        return p;
    }

    JulianDay SolarTime::get_julian_day() const {
        return JulianDay::from_ymd_hms(get_year(), get_month(), get_day(), hour, minute, second);
    }

    int SolarTime::subtract(const SolarTime &other) const {
        int days = day.subtract(other.get_solar_day());
        const int cs = hour * 3600 + minute * 60 + second;
        const int ts = other.get_hour() * 3600 + other.get_minute() * 60 + other.get_second();
        int seconds = cs - ts;
        if (seconds < 0) {
            seconds += 86400;
            days--;
        }
        seconds += days * 86400;
        return seconds;
    }

    bool SolarTime::equals(const SolarTime &other) const {
        return to_string() == other.to_string();
    }

    SixtyCycleHour SolarTime::get_sixty_cycle_hour() const {
        return SixtyCycleHour::from_solar_time(*this);
    }

    LunarHour SolarTime::get_lunar_hour() const {
        const LunarDay d = day.get_lunar_day();
        return LunarHour::from_ymd_hms(d.get_year(), d.get_month(), d.get_day(), hour, minute, second);
    }

    Phase SolarTime::get_phase() const {
        const LunarMonth month = get_lunar_hour().get_lunar_day().get_lunar_month().next(1);
        Phase p = Phase::from_index(month.get_year(), month.get_month_with_leap(), 0);
        while (p.get_solar_time().is_after(*this)) {
            p = p.next(-1);
        }
        return p;
    }

    SixtyCycle ThreePillars::get_year() const {
        return year;
    }

    SixtyCycle ThreePillars::get_month() const {
        return month;
    }

    SixtyCycle ThreePillars::get_day() const {
        return day;
    }

    vector<SolarDay> ThreePillars::get_solar_days(const int start_year, const int end_year) const {
        auto l = vector<SolarDay>();
        // 月地支距寅月的偏移值
        int m = month.get_earth_branch().next(-2).get_index();
        // 月天干要一致
        if (!HeavenStem::from_index((year.get_heaven_stem().get_index() + 1) * 2 + m).equals(month.get_heaven_stem())) {
            return l;
        }
        // 1年的立春是辛酉，序号57
        int y = year.next(-57).get_index() + 1;
        // 节令偏移值
        m *= 2;
        if (const int base_year = start_year - 1; base_year > y) {
            y += 60 * static_cast<int>(ceil((base_year - y) / 60.0));
        }
        while (y <= end_year) {
            // 立春为寅月的开始
            SolarTerm term = SolarTerm::from_index(y, 3);
            // 节令推移，年干支和月干支就都匹配上了
            if (m > 0) {
                term = term.next(m);
            }
            if (SolarDay solar_day = term.get_solar_day(); solar_day.get_year() >= start_year) {
                // 日干支和节令干支的偏移值
                int d = day.next(-solar_day.get_lunar_day().get_sixty_cycle().get_index()).get_index();
                if (d > 0) {
                    // 从节令推移天数
                    solar_day = solar_day.next(d);
                }
                // 验证一下
                if (solar_day.get_sixty_cycle_day().get_three_pillars().equals(this)) {
                    l.push_back(solar_day);
                }
            }
            y += 60;
        }
        return l;
    }

    string ThreePillars::get_name() const {
        return year.to_string() + " " + month.to_string() + " " + day.to_string();
    }

    SixtyCycle EightChar::get_year() const {
        return three_pillars.get_year();
    }

    SixtyCycle EightChar::get_month() const {
        return three_pillars.get_month();
    }

    SixtyCycle EightChar::get_day() const {
        return three_pillars.get_day();
    }

    SixtyCycle EightChar::get_hour() const {
        return hour;
    }

    SixtyCycle EightChar::get_fetal_origin() const {
        const SixtyCycle m = get_month();
        return SixtyCycle::from_name(m.get_heaven_stem().next(1).get_name() + m.get_earth_branch().next(3).get_name());
    }

    SixtyCycle EightChar::get_fetal_breath() const {
        const SixtyCycle d = get_day();
        return SixtyCycle::from_name(d.get_heaven_stem().next(5).get_name() + EarthBranch::from_index(13 - d.get_earth_branch().get_index()).get_name());
    }

    SixtyCycle EightChar::get_own_sign() const {
        int m = get_month().get_earth_branch().get_index() - 1;
        if (m < 1) {
            m += 12;
        }
        int h = hour.get_earth_branch().get_index() - 1;
        if (h < 1) {
            h += 12;
        }
        int offset = m + h;
        offset = (offset >= 14 ? 26 : 14) - offset;
        return SixtyCycle::from_name(HeavenStem::from_index((get_year().get_heaven_stem().get_index() + 1) * 2 + offset - 1).get_name() + EarthBranch::from_index(offset + 1).get_name());
    }

    SixtyCycle EightChar::get_body_sign() const {
        int offset = get_month().get_earth_branch().get_index() - 1;
        if (offset < 1) {
            offset += 12;
        }
        offset += hour.get_earth_branch().get_index() + 1;
        if (offset > 12) {
            offset -= 12;
        }
        return SixtyCycle::from_name(HeavenStem::from_index((get_year().get_heaven_stem().get_index() + 1) * 2 + offset - 1).get_name() + EarthBranch::from_index(offset + 1).get_name());
    }

    vector<SolarTime> EightChar::get_solar_times(const int start_year, const int end_year) const {
        const SixtyCycle year = get_year();
        const SixtyCycle month = get_year();
        const SixtyCycle day = get_year();
        auto l = vector<SolarTime>();
        // 月地支距寅月的偏移值
        int m = month.get_earth_branch().next(-2).get_index();
        // 月天干要一致
        if (!HeavenStem::from_index((year.get_heaven_stem().get_index() + 1) * 2 + m).equals(month.get_heaven_stem())) {
            return l;
        }
        // 1年的立春是辛酉，序号57
        int y = year.next(-57).get_index() + 1;
        // 节令偏移值
        m *= 2;
        // 时辰地支转时刻
        const int h = hour.get_earth_branch().get_index() * 2;
        // 兼容子时多流派
        auto hours = vector<int>();
        hours.push_back(h);
        if (h == 0) {
            hours.push_back(23);
        }
        if (const int base_year = start_year - 1; base_year > y) {
            y += 60 * static_cast<int>(ceil((base_year - y) / 60.0));
        }
        while (y <= end_year) {
            // 立春为寅月的开始
            SolarTerm term = SolarTerm::from_index(y, 3);
            // 节令推移，年干支和月干支就都匹配上了
            if (m > 0) {
                term = term.next(m);
            }
            if (SolarTime solar_time = term.get_julian_day().get_solar_time(); solar_time.get_year() >= start_year) {
                // 日干支和节令干支的偏移值
                SolarDay solar_day = solar_time.get_solar_day();
                int d = day.next(-solar_day.get_lunar_day().get_sixty_cycle().get_index()).get_index();
                if (d > 0) {
                    // 从节令推移天数
                    solar_day = solar_day.next(d);
                }
                for (const int hour: hours) {
                    int mi = 0;
                    int s = 0;
                    // 如果正好是节令当天，且小时和节令的小时数相等的极端情况，把分钟和秒钟带上
                    if (d == 0 && hour == solar_time.get_hour()) {
                        mi = solar_time.get_minute();
                        s = solar_time.get_second();
                    }
                    SolarTime time = SolarTime::from_ymd_hms(solar_day.get_year(), solar_day.get_month(), solar_day.get_day(), hour, mi, s);
                    if (d == 30) {
                        time = time.next(-3600);
                    }
                    // 验证一下
                    if (time.get_lunar_hour().get_eight_char().equals(this)) {
                        l.push_back(time);
                    }
                }
            }
            y += 60;
        }
        return l;
    }

    string EightChar::get_name() const {
        return three_pillars.to_string() + " " + hour.to_string();
    }

    EightChar DefaultEightCharProvider::get_eight_char(const LunarHour hour) const {
        return hour.get_sixty_cycle_hour().get_eight_char();
    }

    EightChar LunarSect2EightCharProvider::get_eight_char(const LunarHour hour) const {
        const SixtyCycleHour h = hour.get_sixty_cycle_hour();
        return EightChar(h.get_year(), h.get_month(), hour.get_lunar_day().get_sixty_cycle(), h.get_sixty_cycle());
    }

    SolarTime ChildLimitInfo::get_start_time() const {
        return start_time;
    }

    SolarTime ChildLimitInfo::get_end_time() const {
        return end_time;
    }

    int ChildLimitInfo::get_year_count() const {
        return year_count;
    }

    int ChildLimitInfo::get_month_count() const {
        return month_count;
    }

    int ChildLimitInfo::get_day_count() const {
        return day_count;
    }

    int ChildLimitInfo::get_hour_count() const {
        return hour_count;
    }

    int ChildLimitInfo::get_minute_count() const {
        return minute_count;
    }

    bool ChildLimit::get_forward(const EightChar &eight_char, const Gender gender) {
        // 阳男阴女顺推，阴男阳女逆推
        const bool yang = YinYang::YANG == eight_char.get_year().get_heaven_stem().get_yin_yang();
        const bool man = Gender::MAN == gender;
        return (yang && man) || (!yang && !man);
    }

    ChildLimitProvider* ChildLimit::provider = new DefaultChildLimitProvider();

    ChildLimitInfo ChildLimit::get_info(const SolarTime &birth_time, const bool forward) {
        SolarTerm term = birth_time.get_term();
        if (!term.is_jie()) {
            term = term.next(-1);
        }
        if (forward) {
            term = term.next(2);
        }
        return provider->get_info(birth_time, term);
    }

    Fortune Fortune::from_child_limit(const ChildLimit& child_limit, const int index) {
        return Fortune(child_limit, index);
    }

    int Fortune::get_age() const {
        return child_limit.get_end_sixty_cycle_year().get_year() - child_limit.get_start_sixty_cycle_year().get_year() + 1 + index;
    }

    SixtyCycleYear Fortune::get_sixty_cycle_year() const {
        return child_limit.get_end_sixty_cycle_year().next(index);
    }

    SixtyCycle Fortune::get_sixty_cycle() const {
        const int n = get_age();
        return child_limit.get_eight_char().get_hour().next(child_limit.is_forward() ? n: -n);
    }

    string Fortune::get_name() const {
        return get_sixty_cycle().get_name();
    }

    Fortune Fortune::next(const int n) const {
        return from_child_limit(child_limit, index + n);
    }

    DecadeFortune DecadeFortune::from_child_limit(const ChildLimit& child_limit, const int index) {
        return DecadeFortune(child_limit, index);
    }

    int DecadeFortune::get_start_age() const {
        return child_limit.get_end_sixty_cycle_year().get_year() - child_limit.get_start_sixty_cycle_year().get_year() + 1 + index * 10;
    }

    int DecadeFortune::get_end_age() const {
        return get_start_age() + 9;
    }

    SixtyCycle DecadeFortune::get_sixty_cycle() const {
        return child_limit.get_eight_char().get_month().next(child_limit.is_forward() ? index + 1 : -index - 1);
    }

    SixtyCycleYear DecadeFortune::get_start_sixty_cycle_year() const {
        return child_limit.get_end_sixty_cycle_year().next(index * 10);
    }

    SixtyCycleYear DecadeFortune::get_end_sixty_cycle_year() const {
        return get_start_sixty_cycle_year().next(9);
    }

    string DecadeFortune::get_name() const {
        return get_sixty_cycle().get_name();
    }

    DecadeFortune DecadeFortune::next(const int n) const {
        return from_child_limit(child_limit, index + n);
    }

    Fortune DecadeFortune::get_start_fortune() const {
        return Fortune::from_child_limit(child_limit, index * 10);
    }

    ChildLimit ChildLimit::from_solar_time(const SolarTime& birth_time, const Gender gender) {
        return ChildLimit(birth_time, gender);
    }

    EightChar ChildLimit::get_eight_char() const {
        return eight_char;
    }

    Gender ChildLimit::get_gender() const {
        return gender;
    }

    bool ChildLimit::is_forward() const {
        return forward;
    }

    int ChildLimit::get_year_count() const {
        return info.get_year_count();
    }

    int ChildLimit::get_month_count() const {
        return info.get_month_count();
    }

    int ChildLimit::get_day_count() const {
        return info.get_day_count();
    }

    int ChildLimit::get_hour_count() const {
        return info.get_hour_count();
    }

    int ChildLimit::get_minute_count() const {
        return info.get_minute_count();
    }

    SolarTime ChildLimit::get_start_time() const {
        return info.get_start_time();
    }

    SolarTime ChildLimit::get_end_time() const {
        return info.get_end_time();
    }

    DecadeFortune ChildLimit::get_start_decade_fortune() const {
        return DecadeFortune::from_child_limit(*this, 0);
    }

    DecadeFortune ChildLimit::get_decade_fortune() const {
        return DecadeFortune::from_child_limit(*this, -1);
    }

    Fortune ChildLimit::get_start_fortune() const {
        return Fortune::from_child_limit(*this, 0);
    }

    SixtyCycleYear ChildLimit::get_start_sixty_cycle_year() const {
        return SixtyCycleYear::from_year(get_start_time().get_year());
    }

    SixtyCycleYear ChildLimit::get_end_sixty_cycle_year() const {
        return SixtyCycleYear::from_year(get_end_time().get_year());
    }

    int ChildLimit::get_start_age() const {
        return 1;
    }

    int ChildLimit::get_end_age() const {
        const int n = get_end_sixty_cycle_year().get_year() - get_start_sixty_cycle_year().get_year();
        if (n > 1) {
            return n;
        }
        return 1;
    }

    ChildLimitInfo AbstractChildLimitProvider::next(const SolarTime& birth_time, const int add_year, const int add_month, const int add_day, const int add_hour, const int add_minute, const int add_second) const {
        int d = birth_time.get_day() + add_day;
        int h = birth_time.get_hour() + add_hour;
        int mi = birth_time.get_minute() + add_minute;
        int s = birth_time.get_second() + add_second;
        mi += s / 60;
        s %= 60;
        h += mi / 60;
        mi %= 60;
        d += h / 24;
        h %= 24;

        SolarMonth sm = SolarMonth::from_ym(birth_time.get_year() + add_year, birth_time.get_month()).next(add_month);

        int dc = sm.get_day_count();
        while (d > dc) {
            d -= dc;
            sm = sm.next(1);
            dc = sm.get_day_count();
        }

        return ChildLimitInfo(birth_time, SolarTime::from_ymd_hms(sm.get_year(), sm.get_month(), d, h, mi, s), add_year, add_month, add_day, add_hour, add_minute);
    }

    ChildLimitInfo DefaultChildLimitProvider::get_info(const SolarTime birth_time, const SolarTerm term) const {
        // 出生时刻和节令时刻相差的秒数
        int seconds = abs(term.get_julian_day().get_solar_time().subtract(birth_time));
        // 3天 = 1年，3天=60*60*24*3秒=259200秒 = 1年
        const int year = seconds / 259200;
        seconds %= 259200;
        // 1天 = 4月，1天=60*60*24秒=86400秒 = 4月，85400秒/4=21600秒 = 1月
        const int month = seconds / 21600;
        seconds %= 21600;
        // 1时 = 5天，1时=60*60秒=3600秒 = 5天，3600秒/5=720秒 = 1天
        const int day = seconds / 720;
        seconds %= 720;
        // 1分 = 2时，60秒 = 2时，60秒/2=30秒 = 1时
        const int hour = seconds / 30;
        seconds %= 30;
        // 1秒 = 2分，1秒/2=0.5秒 = 1分
        const int minute = seconds * 2;

        return next(birth_time, year, month, day, hour, minute, 0);
    }

    ChildLimitInfo China95ChildLimitProvider::get_info(const SolarTime birth_time, const SolarTerm term) const {
        // 出生时刻和节令时刻相差的分钟数
        int minutes = abs(term.get_julian_day().get_solar_time().subtract(birth_time)) / 60;
        const int year = minutes / 4320;
        minutes %= 4320;
        const int month = minutes / 360;
        minutes %= 360;
        const int day = minutes / 12;

        return next(birth_time, year, month, day, 0, 0, 0);
    }

    ChildLimitInfo LunarSect1ChildLimitProvider::get_info(const SolarTime birth_time, const SolarTerm term) const {
        const SolarTime term_time = term.get_julian_day().get_solar_time();
        SolarTime end = term_time;
        SolarTime start = birth_time;
        if (birth_time.is_after(term_time)) {
            end = birth_time;
            start = term_time;
        }
        const int end_time_zhi_index = end.get_hour() == 23 ? 11 : end.get_lunar_hour().get_index_in_day();
        const int start_time_zhi_index = start.get_hour() == 23 ? 11 : start.get_lunar_hour().get_index_in_day();
        // 时辰差
        int hour_diff = end_time_zhi_index - start_time_zhi_index;
        // 天数差
        int day_diff = end.get_solar_day().subtract(start.get_solar_day());
        if (hour_diff < 0) {
            hour_diff += 12;
            day_diff--;
        }
        const int month_diff = hour_diff * 10 / 30;
        int month = day_diff * 4 + month_diff;
        const int day = hour_diff * 10 - month_diff * 30;
        const int year = month / 12;
        month = month - year * 12;

        return next(birth_time, year, month, day, 0, 0, 0);
    }

    ChildLimitInfo LunarSect2ChildLimitProvider::get_info(const SolarTime birth_time, const SolarTerm term) const {
        // 出生时刻和节令时刻相差的分钟数
        int minutes = abs(term.get_julian_day().get_solar_time().subtract(birth_time)) / 60;
        const int year = minutes / 4320;
        minutes %= 4320;
        const int month = minutes / 360;
        minutes %= 360;
        const int day = minutes / 12;
        minutes %= 12;
        const int hour = minutes * 2;

        return next(birth_time, year, month, day, hour, 0, 0);
    }

    const vector<string> LegalHoliday::NAMES = {
        "元旦节", "春节", "清明节", "劳动节", "端午节", "中秋节", "国庆节", "国庆中秋", "抗战胜利日"
    };

    string LegalHoliday::DATA = "2001122900+032001123000+022002010110+002002010210-012002010310-022002020901+032002021001+022002021211+002002021311-012002021411-022002021511-032002021611-042002021711-052002021811-062002042703+042002042803+032002050113+002002050213-012002050313-022002050413-032002050513-042002050613-052002050713-062002092806+032002092906+022002100116+002002100216-012002100316-022002100416-032002100516-042002100616-052002100716-062003010110+002003020111+002003020211-012003020311-022003020411-032003020511-042003020611-052003020711-062003020801-072003020901-082003042603+052003042703+042003050113+002003050213-012003050313-022003050413-032003050513-042003050613-052003050713-062003092706+042003092806+032003100116+002003100216-012003100316-022003100416-032003100516-042003100616-052003100716-062004010110+002004011701+052004011801+042004012211+002004012311-012004012411-022004012511-032004012611-042004012711-052004012811-062004050113+002004050213-012004050313-022004050413-032004050513-042004050613-052004050713-062004050803-072004050903-082004100116+002004100216-012004100316-022004100416-032004100516-042004100616-052004100716-062004100906-082004101006-092005010110+002005010210-012005010310-022005020501+042005020601+032005020911+002005021011-012005021111-022005021211-032005021311-042005021411-052005021511-062005043003+012005050113+002005050213-012005050313-022005050413-032005050513-042005050613-052005050713-062005050803-072005100116+002005100216-012005100316-022005100416-032005100516-042005100616-052005100716-062005100806-072005100906-082005123100+012006010110+002006010210-012006010310-022006012801+012006012911+002006013011-012006013111-022006020111-032006020211-042006020311-052006020411-062006020501-072006042903+022006043003+012006050113+002006050213-012006050313-022006050413-032006050513-042006050613-052006050713-062006093006+012006100116+002006100216-012006100316-022006100416-032006100516-042006100616-052006100716-062006100806-072006123000+022006123100+012007010110+002007010210-012007010310-022007021701+012007021811+002007021911-012007022011-022007022111-032007022211-042007022311-052007022411-062007022501-072007042803+032007042903+022007050113+002007050213-012007050313-022007050413-032007050513-042007050613-052007050713-062007092906+022007093006+012007100116+002007100216-012007100316-022007100416-032007100516-042007100616-052007100716-062007122900+032007123010+022007123110+012008010110+002008020201+042008020301+032008020611+002008020711-012008020811-022008020911-032008021011-042008021111-052008021211-062008040412+002008040512-012008040612-022008050113+002008050213-012008050313-022008050403-032008060714+012008060814+002008060914-012008091315+012008091415+002008091515-012008092706+042008092806+032008092916+022008093016+012008100116+002008100216-012008100316-022008100416-032008100516-042009010110+002009010210-012009010310-022009010400-032009012401+012009012511+002009012611-012009012711-022009012811-032009012911-042009013011-052009013111-062009020101-072009040412+002009040512-012009040612-022009050113+002009050213-012009050313-022009052814+002009052914-012009053014-022009053104-032009092706+042009100116+002009100216-012009100316-022009100416-032009100515-022009100615-032009100715-042009100815-052009101005-072010010110+002010010210-012010010310-022010021311+002010021411-012010021511-022010021611-032010021711-042010021811-052010021911-062010022001-072010022101-082010040312+022010040412+012010040512+002010050113+002010050213-012010050313-022010061204+042010061304+032010061414+022010061514+012010061614+002010091905+032010092215+002010092315-012010092415-022010092505-032010092606+052010100116+002010100216-012010100316-022010100416-032010100516-042010100616-052010100716-062010100906-082011010110+002011010210-012011010310-022011013001+042011020211+012011020311+002011020411-012011020511-022011020611-032011020711-042011020811-052011021201-092011040202+032011040312+022011040412+012011040512+002011043013+012011050113+002011050213-012011060414+022011060514+012011060614+002011091015+022011091115+012011091215+002011100116+002011100216-012011100316-022011100416-032011100516-042011100616-052011100716-062011100806-072011100906-082011123100+012012010110+002012010210-012012010310-022012012101+022012012211+012012012311+002012012411-012012012511-022012012611-032012012711-042012012811-052012012901-062012033102+042012040102+032012040212+022012040312+012012040412+002012042803+032012042913+022012043013+012012050113+002012050203-012012062214+012012062314+002012062414-012012092905+012012093015+002012100116+002012100216-012012100316-022012100416-032012100516-042012100616-052012100716-062012100806-072013010110+002013010210-012013010310-022013010500-042013010600-052013020911+012013021011+002013021111-012013021211-022013021311-032013021411-042013021511-052013021601-062013021701-072013040412+002013040512-012013040612-022013042703+042013042803+032013042913+022013043013+012013050113+002013060804+042013060904+032013061014+022013061114+012013061214+002013091915+002013092015-012013092115-022013092205-032013092906+022013100116+002013100216-012013100316-022013100416-032013100516-042013100616-052013100716-062014010110+002014012601+052014013111+002014020111-012014020211-022014020311-032014020411-042014020511-052014020611-062014020801-082014040512+002014040612-012014040712-022014050113+002014050213-012014050313-022014050403-032014053114+022014060114+012014060214+002014090615+022014090715+012014090815+002014092806+032014100116+002014100216-012014100316-022014100416+002014100516-042014100616-052014100716-062014101106-102015010110+002015010210-012015010310-022015010400-032015021501+042015021811+012015021911+002015022011-012015022111-022015022211-032015022311-042015022411-052015022801-092015040412+012015040512+002015040612-012015050113+002015050213-012015050313-022015062014+002015062114-012015062214-022015090318+002015090418-012015090518-022015090608-032015092615+012015092715+002015100116+002015100216-012015100316-022015100416+002015100516-042015100616-052015100716-062015101006-092016010110+002016010210-012016010310-022016020601+022016020711+012016020811+002016020911-012016021011-022016021111-032016021211-042016021311-052016021401-062016040212+022016040312+012016040412+002016043013+012016050113+002016050213-012016060914+002016061014-012016061114-022016061204-032016091515+002016091615-012016091715-022016091805-032016100116+002016100216-012016100316-022016100416-032016100516-042016100616-052016100716-062016100806-072016100906-082016123110+012017010110+002017010210-012017012201+062017012711+012017012811+002017012911-012017013011-022017013111-032017020111-042017020211-052017020401-072017040102+032017040212+022017040312+012017040412+002017042913+022017043013+012017050113+002017052704+032017052814+022017052914+012017053014+002017093006+012017100116+002017100216-012017100316-022017100415+002017100516-042017100616-052017100716-062017100816-072017123010+022017123110+012018010110+002018021101+052018021511+012018021611+002018021711-012018021811-022018021911-032018022011-042018022111-052018022401-082018040512+002018040612-012018040712-022018040802-032018042803+032018042913+022018043013+012018050113+002018061614+022018061714+012018061814+002018092215+022018092315+012018092415+002018092906+022018093006+012018100116+002018100216-012018100316-022018100416-032018100516-042018100616-052018100716-062018122900+032018123010+022018123110+012019010110+002019020201+032019020301+022019020411+012019020511+002019020611-012019020711-022019020811-032019020911-042019021011-052019040512+002019040612-012019040712-022019042803+032019050113+002019050213-012019050313-022019050413-032019050503-042019060714+002019060814-012019060914-022019091315+002019091415-012019091515-022019092906+022019100116+002019100216-012019100316-022019100416-032019100516-042019100616-052019100716-062019101206-112020010110+002020011901+062020012411+012020012511+002020012611-012020012711-022020012811-032020012911-042020013011-052020013111-062020020111-072020020211-082020040412+002020040512-012020040612-022020042603+052020050113+002020050213-012020050313-022020050413-032020050513-042020050903-082020062514+002020062614-012020062714-022020062804-032020092707+042020100117+002020100216-012020100316-022020100416-032020100516-042020100616-052020100716-062020100816-072020101006-092021010110+002021010210-012021010310-022021020701+052021021111+012021021211+002021021311-012021021411-022021021511-032021021611-042021021711-052021022001-082021040312+012021040412+002021040512-012021042503+062021050113+002021050213-012021050313-022021050413-032021050513-042021050803-072021061214+022021061314+012021061414+002021091805+032021091915+022021092015+012021092115+002021092606+052021100116+002021100216-012021100316-022021100416-032021100516-042021100616-052021100716-062021100906-082022010110+002022010210-012022010310-022022012901+032022013001+022022013111+012022020111+002022020211-012022020311-022022020411-032022020511-042022020611-052022040202+032022040312+022022040412+012022040512+002022042403+072022043013+012022050113+002022050213-012022050313-022022050413-032022050703-062022060314+002022060414-012022060514-022022091015+002022091115-012022091215-022022100116+002022100216-012022100316-022022100416-032022100516-042022100616-052022100716-062022100806-072022100906-082022123110+012023010110+002023010210-012023012111+012023012211+002023012311-012023012411-022023012511-032023012611-042023012711-052023012801-062023012901-072023040512+002023042303+082023042913+022023043013+012023050113+002023050213-012023050313-022023050603-052023062214+002023062314-012023062414-022023062504-032023092915+002023093016+012023100116+002023100216-012023100316-022023100416-032023100516-042023100616-052023100706-062023100806-072023123010+022023123110+012024010110+002024020401+062024021011+002024021111-012024021211-022024021311-032024021411-042024021511-052024021611-062024021711-072024021801-082024040412+002024040512-012024040612-022024040702-032024042803+032024050113+002024050213-012024050313-022024050413-032024050513-042024051103-102024060814+022024060914+012024061014+002024091405+032024091515+022024091615+012024091715+002024092906+022024100116+002024100216-012024100316-022024100416-032024100516-042024100616-052024100716-062024101206-112025010110+002025012601+032025012811+012025012911+002025013011-012025013111-022025020111-032025020211-032025020311-042025020411-052025020801-092025040412+002025040512-012025040612-022025042703+042025050113+002025050213-012025050313-022025050413-032025050513-042025053114+002025060114-012025060214-022025092807+032025100117+002025100217-012025100317-022025100417-032025100517-042025100617-052025100717-062025100817-072025101107-102026010110+002026010210-012026010310-022026010400-032026021401+032026021511+022026021611+012026021711+002026021811-012026021911-022026022011-032026022111-042026022211-052026022311-062026022801-112026040412+012026040512+002026040612-012026050113+002026050213-012026050313-022026050413-032026050513-042026050903-082026061914+002026062014-012026062114-022026092006+052026092515+002026092615-012026092715-022026100116+002026100216-012026100316-022026100416-032026100516-042026100616-052026100716-062026101006-09";

    SolarDay LegalHoliday::compute_target(const string &data) const {
        const int offset = stoi(data.substr(data.length()-2));
        return day.next('-' == data[10] ? -offset : offset);
    }

    optional<LegalHoliday> LegalHoliday::from_ymd(const int year, const int month, const int day) {
        char buffer[9];
        snprintf(buffer, sizeof(buffer), "%04d%02d%02d", year, month, day);
        const regex re(string(buffer) + "[0-1][0-8][\\+|-]\\d{2}");
        if (smatch match; regex_search(DATA, match, re)) {
            const string data= match[0];
            return LegalHoliday(year, month, day, data);
        }
        return nullopt;
    }

    SolarDay LegalHoliday::get_day() const {
        return day;
    }

    SolarDay LegalHoliday::get_target() const {
        return target;
    }

    bool LegalHoliday::is_work() const {
        return work;
    }

    string LegalHoliday::get_name() const {
        return name;
    }

    string LegalHoliday::to_string() const {
        return day.to_string() + " " + name + "(" + (work ? "班" : "休") + ")";
    }

    optional<LegalHoliday> LegalHoliday::next(int n) const {
        int year = day.get_year();
        int month = day.get_month();
        if (n == 0) {
            return from_ymd(year, month, day.get_day()).value();
        }
        auto data = vector<string>();
        char buffer[9];
        snprintf(buffer, sizeof(buffer), "%04d%02d%02d", year, month, day.get_day());
        auto today = string(buffer);
        char buffer_y[5];
        snprintf(buffer_y, sizeof(buffer_y), "%04d", year);
        regex re(string(buffer_y) + R"(\d{4}[0-1][0-8][\+|-]\d{2})");
        smatch match;
        auto search_start(DATA.cbegin());
        while (regex_search(search_start, DATA.cend(), match, re)) {
            data.push_back(match[0]);
            search_start = match[0].second;
        }
        int index = -1;
        int size = static_cast<int>(data.size());
        for (int i = 0; i < size; i++) {
            if (equal(today.begin(), today.end(), data[i].begin())) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            return nullopt;
        }
        index += n;
        int y = year;
        if (n > 0) {
            while (index >= size) {
                index -= size;
                y += 1;
                data.clear();
                snprintf(buffer_y, sizeof(buffer_y), "%04d", y);
                regex r(string(buffer_y) + R"(\d{4}[0-1][0-8][\+|-]\d{2})");
                auto start(DATA.cbegin());
                while (regex_search(start, DATA.cend(), match, r)) {
                    data.push_back(match[0]);
                    start = match[0].second;
                }
                size = static_cast<int>(data.size());
                if (size < 1) {
                    return nullopt;
                }
            }
        } else {
            while (index < 0) {
                y -= 1;
                data.clear();
                snprintf(buffer_y, sizeof(buffer_y), "%04d", y);
                regex r(string(buffer_y) + R"(\d{4}[0-1][0-8][\+|-]\d{2})");
                auto start(DATA.cbegin());
                while (regex_search(start, DATA.cend(), match, r)) {
                    data.push_back(match[0]);
                    start = match[0].second;
                }
                size = static_cast<int>(data.size());
                if (size < 1) {
                    return nullopt;
                }
                index += size;
            }
        }
        string d = data[index];
        return LegalHoliday(stoi(d.substr(0, 4)), stoi(d.substr(4, 2)), stoi(d.substr(6, 2)), d);
    }

    const vector<string> SolarFestival::NAMES = {
        "元旦", "三八妇女节", "植树节", "五一劳动节", "五四青年节", "六一儿童节", "建党节", "八一建军节", "教师节", "国庆节"
    };

    string SolarFestival::DATA = "@00001011950@01003081950@02003121979@03005011950@04005041950@05006011950@06007011941@07008011933@08009101985@09010011950";

    optional<SolarFestival> SolarFestival::from_index(const int year, const int index) {
        if (index < 0 || static_cast<size_t>(index) >= NAMES.size()) {
            throw invalid_argument("illegal index: " + std::to_string(index));
        }
        char buffer[3];
        snprintf(buffer, sizeof(buffer), "%02d", index);
        const regex re("@" + string(buffer) + "\\d+");
        if (smatch match; regex_search(DATA, match, re)) {
            FestivalType type;
            const string data = match[0];
            char d = data[3];
            if ('0' == d) {
                type = FestivalType::DAY;
            } else if ('1' == d) {
                type = FestivalType::TERM;
            } else if ('2' == d) {
                type = FestivalType::EVE;
            } else {
                return nullopt;
            }
            const int start_year = stoi(data.substr(8));
            if (year < start_year) {
                return nullopt;
            }
            return SolarFestival(type, SolarDay::from_ymd(year, stoi(data.substr(4, 2)), stoi(data.substr(6, 2))), start_year, data);
        }
        return nullopt;
    }

    optional<SolarFestival> SolarFestival::from_ymd(const int year, const int month, const int day) {
        char buffer[5];
        snprintf(buffer, sizeof(buffer), "%02d%02d", month, day);
        const regex re("@\\d{2}0" + string(buffer) + "\\d+");
        if (smatch match; regex_search(DATA, match, re)) {
            const string data= match[0];
            const int start_year = stoi(data.substr(8));
            if (year < start_year) {
                return nullopt;
            }
            return SolarFestival(FestivalType::DAY, SolarDay::from_ymd(year, month, day), start_year, data);
        }
        return nullopt;
    }

    optional<SolarFestival> SolarFestival::next(const int n) const {
        const int size = static_cast<int>(NAMES.size());
        const int i = index + n;
        return from_index((day.get_year() * size + i) / size, index_of(i, size));
    }

    FestivalType SolarFestival::get_type() const {
        return _type;
    }

    int SolarFestival::get_index() const {
        return index;
    }

    SolarDay SolarFestival::get_day() const {
        return day;
    }

    int SolarFestival::get_start_year() const {
        return start_year;
    }

    string SolarFestival::get_name() const {
        return name;
    }

    string SolarFestival::to_string() const {
        return day.to_string() + " " + name;
    }

    const vector<string> LunarFestival::NAMES = {
        "春节", "元宵节", "龙头节", "上巳节", "清明节", "端午节", "七夕节", "中元节", "中秋节", "重阳节", "冬至节", "腊八节", "除夕"
    };

    string LunarFestival::DATA = "@0000101@0100115@0200202@0300303@04107@0500505@0600707@0700715@0800815@0900909@10124@1101208@122";

    optional<LunarFestival> LunarFestival::from_index(const int year, const int index) {
        if (index < 0 || static_cast<size_t>(index) >= NAMES.size()) {
            throw invalid_argument("illegal index: " + std::to_string(index));
        }
        char buffer[3];
        snprintf(buffer, sizeof(buffer), "%02d", index);
        const regex re("@" + string(buffer) + "\\d+");
        if (smatch match; regex_search(DATA, match, re)) {
            const string data= match[0];
            const char d = data[3];
            if ('0' == d) {
                return LunarFestival(FestivalType::DAY, LunarDay::from_ymd(year, stoi(data.substr(4, 2)), stoi(data.substr(6))), nullopt, data);
            }
            if ('1' == d) {
                SolarTerm solar_term = SolarTerm::from_index(year, stoi(data.substr(4)));
                return LunarFestival(FestivalType::TERM, solar_term.get_solar_day().get_lunar_day(), solar_term, data);
            }
            if ('2' == d) {
                return LunarFestival(FestivalType::EVE, LunarDay::from_ymd(year + 1, 1, 1).next(-1), nullopt, data);
            }
        }
        return nullopt;
    }

    optional<LunarFestival> LunarFestival::from_ymd(int year, int month, int day) {
        char buffer[15];
        snprintf(buffer, sizeof(buffer), "@\\d{2}0%02d%02d", month, day);
        const auto pattern = string(buffer);
        const regex re(pattern);
        smatch match;
        if (regex_search(DATA, match, re)) {
            const string data= match[0];
            return LunarFestival(FestivalType::DAY, LunarDay::from_ymd(year, month, day), nullopt, data);
        }
        const regex re1("@\\d{2}1\\d{2}");
        auto start(DATA.cbegin());
        while (regex_search(start, DATA.cend(), match, re1)) {
            const string data= match[0];
            SolarTerm solar_term = SolarTerm::from_index(year, stoi(data.substr(4)));
            if (LunarDay lunar_day = solar_term.get_solar_day().get_lunar_day(); lunar_day.get_year() == year && lunar_day.get_month() == month && lunar_day.get_day() == day) {
                return LunarFestival(FestivalType::TERM, lunar_day, solar_term, data);
            }
            start = match[0].second;
        }
        if (const regex re2("@\\d{2}2"); regex_search(DATA, match, re2)) {
            LunarDay lunar_day = LunarDay::from_ymd(year, month, day);
            if (LunarDay next_day = lunar_day.next(1); next_day.get_month() == 1 && next_day.get_day() == 1) {
                return LunarFestival(FestivalType::EVE, lunar_day, nullopt, match[0]);
            }
        }
        return nullopt;
    }

    optional<LunarFestival> LunarFestival::next(const int n) const {
        const int size = static_cast<int>(NAMES.size());
        const int i = index + n;
        return from_index((day.get_year() * size + i) / size, index_of(i, size));
    }

    FestivalType LunarFestival::get_type() const {
        return _type;
    }

    int LunarFestival::get_index() const {
        return index;
    }

    LunarDay LunarFestival::get_day() const {
        return day;
    }

    optional<SolarTerm> LunarFestival::get_solar_term() const {
        return solar_term;
    }

    string LunarFestival::get_name() const {
        return name;
    }

    string LunarFestival::to_string() const {
        return day.to_string() + " " + name;
    }

    RabByungElement RabByungElement::from_index(const int index) {
        return RabByungElement(index);
    }

    RabByungElement RabByungElement::from_name(const string &name) {
        return RabByungElement(name);
    }

    RabByungElement RabByungElement::next(const int n) const {
        return from_index(next_index(n));
    }

    bool RabByungElement::equals(const RabByungElement &other) const {
        return to_string() == other.to_string();
    }

    RabByungElement RabByungElement::get_reinforce() const {
        return next(1);
    }

    RabByungElement RabByungElement::get_restrain() const {
        return next(2);
    }

    RabByungElement RabByungElement::get_reinforced() const {
        return next(-1);
    }

    RabByungElement RabByungElement::get_restrained() const {
        return next(-2);
    }

    Direction RabByungElement::get_direction() const {
        const int indices[5] = {2, 8, 4, 6, 0};
        return Direction::from_index(indices[index]);
    }

    string RabByungElement::get_name() const {
        return regex_replace(names[index], regex("金"), "铁");
    }

    RabByungYear RabByungYear::from_sixty_cycle(const int rab_byung_index, const SixtyCycle& sixty_cycle) {
        return RabByungYear(rab_byung_index, sixty_cycle);
    }

    RabByungYear RabByungYear::from_element_zodiac(int rab_byung_index, const RabByungElement& element, const Zodiac& zodiac) {
        for (int i = 0; i < 60; i++) {
            if (SixtyCycle sixty_cycle = SixtyCycle::from_index(i); sixty_cycle.get_earth_branch().get_zodiac().equals(zodiac) && sixty_cycle.get_heaven_stem().get_element().get_index() == element.get_index()) {
                return RabByungYear(rab_byung_index, sixty_cycle);
            }
        }
        throw invalid_argument("illegal rab-byung element " + element.to_string() + ", zodiac " + zodiac.to_string());
    }

    RabByungYear RabByungYear::from_year(int year) {
        return RabByungYear((year - 1024) / 60, SixtyCycle::from_index(year - 4));
    }

    int RabByungYear::get_rab_byung_index() const {
        return rab_byung_index;
    }

    SixtyCycle RabByungYear::get_sixty_cycle() const {
        return sixty_cycle;
    }

    Zodiac RabByungYear::get_zodiac() const {
        return sixty_cycle.get_earth_branch().get_zodiac();
    }

    RabByungElement RabByungYear::get_element() const {
        return RabByungElement::from_index(sixty_cycle.get_heaven_stem().get_element().get_index());
    }

    string RabByungYear::get_name() const {
        const string digits[] = {"零", "一", "二", "三", "四", "五", "六", "七", "八", "九"};
        const string units[] = {"", "十", "百"};
        int n = rab_byung_index + 1;
        string s;
        int pos = 0;
        while (n > 0) {
            if (const int digit = n % 10; digit > 0) {
                s.insert(0, digits[digit] + units[pos]);
            } else if (!s.empty()) {
                s.insert(0, digits[digit]);
            }
            n /= 10;
            pos++;
        }
        if (s.rfind("一十", 0) == 0) {
            const string target = "一";
            s.erase(0, target.length());
        }
        return "第" + s + "饶迥" + get_element().to_string() + get_zodiac().to_string() + "年";
    }

    RabByungYear RabByungYear::next(const int n) const {
        return from_year(get_year() + n);
    }

    int RabByungYear::get_year() const {
        return 1024 + rab_byung_index * 60 + sixty_cycle.get_index();
    }

    int RabByungYear::get_leap_month() const {
        int y = 1;
        int m = 4;
        int t = 0;
        const int current_year = get_year();
        while (y < current_year) {
            const int i = m - 1 + (t % 2 == 0 ? 33 : 32);
            y = (y * 12 + i) / 12;
            m = i % 12 + 1;
            t++;
        }
        return y == current_year ? m : 0;
    }

    SolarYear RabByungYear::get_solar_year() const {
        return SolarYear::from_year(get_year());
    }

    int RabByungYear::get_month_count() const {
        return get_leap_month() < 1 ? 12 : 13;
    }

    RabByungMonth RabByungYear::get_first_month() const {
        return RabByungMonth(*this, 1);
    }

    vector<RabByungMonth> RabByungYear::get_months() const {
        auto l = vector<RabByungMonth>();
        const int leap_month = get_leap_month();
        for (int i = 1; i < 13; i++) {
            l.emplace_back(*this, i);
            if (i == leap_month) {
                l.emplace_back(*this, -i);
            }
        }
        return l;
    }

    std::map<int, vector<int>> RabByungMonth::DAYS = std::map<int, vector<int>>();

    const vector<string> RabByungMonth::NAMES = {
        "正月", "二月", "三月", "四月", "五月", "六月", "七月", "八月", "九月", "十月", "十一月", "十二月"
    };

    const vector<string> RabByungMonth::ALIAS = {
        "神变月", "苦行月", "具香月", "萨嘎月", "作净月", "明净月", "具醉月", "具贤月", "天降月", "持众月", "庄严月", "满意月"
    };

    RabByungMonth RabByungMonth::from_ym(const int year, const int month) {
        return RabByungMonth(year, month);
    }

    RabByungMonth RabByungMonth::from_element_zodiac(const int rab_byung_index, const RabByungElement& element, const Zodiac& zodiac, const int month) {
        return RabByungMonth(rab_byung_index, element, zodiac, month);
    }

    RabByungYear RabByungMonth::get_rab_byung_year() const {
        return year;
    }

    int RabByungMonth::get_year() const {
        return year.get_year();
    }

    int RabByungMonth::get_month() const {
        return month;
    }

    int RabByungMonth::get_month_with_leap() const {
        return leap ? -month : month;
    }

    int RabByungMonth::get_index_in_year() const {
        return index_in_year;
    }

    bool RabByungMonth::is_leap() const {
        return leap;
    }

    string RabByungMonth::get_name() const {
        return (leap ? "闰" : "") + NAMES[month - 1];
    }

    string RabByungMonth::get_alias() const {
        return (leap ? "闰" : "") + ALIAS[month - 1];
    }

    string RabByungMonth::to_string() const {
        return year.to_string() + get_name();
    }

    RabByungMonth RabByungMonth::next(const int n) const {
        if (n == 0) {
            return from_ym(get_year(), get_month_with_leap());
        }
        int m = index_in_year + 1 + n;
        RabByungYear y = year;
        if (n > 0) {
            int month_count = y.get_month_count();
            while (m > month_count) {
                m -= month_count;
                y = y.next(1);
                month_count = y.get_month_count();
            }
        } else {
            while (m <= 0) {
                y = y.next(-1);
                m += y.get_month_count();
            }
        }
        bool leap = false;
        if (const int leap_month = y.get_leap_month(); leap_month > 0) {
            if (m == leap_month + 1) {
                leap = true;
            }
            if (m > leap_month) {
                m--;
            }
        }
        return from_ym(y.get_year(), leap ? -m : m);
    }

    int RabByungMonth::get_day_count() const {
        return 30 + static_cast<int>(get_leap_days().size()) - static_cast<int>(get_miss_days().size());
    }

    vector<int> RabByungMonth::get_special_days() const {
        if (const auto it = DAYS.find(get_year() * 13 + get_index_in_year()); it != DAYS.end()) {
            return it->second;
        }
        return {};
    }

    vector<int> RabByungMonth::get_leap_days() const {
        auto l = vector<int>();
        const auto days = get_special_days();
        for (const int d : days) {
            if (d > 0) {
                l.push_back(d);
            }
        }
        return l;
    }

    vector<int> RabByungMonth::get_miss_days() const {
        auto l = vector<int>();
        const auto days = get_special_days();
        for (const int d : days) {
            if (d < 0) {
                l.push_back(-d);
            }
        }
        return l;
    }

    bool RabByungMonth::equals(const RabByungMonth &other) const {
        return to_string() == other.to_string();
    }

    RabByungDay RabByungMonth::get_first_day() const {
        return RabByungDay(*this, 1);
    }

    vector<RabByungDay> RabByungMonth::get_days() const {
        auto l = vector<RabByungDay>();
        auto miss_days = get_miss_days();
        auto leap_days = get_leap_days();
        for (int i = 1; i < 31; i++) {
            if (find(miss_days.begin(), miss_days.end(), i) != miss_days.end()) {
                continue;
            }
            l.emplace_back(*this, i);
            if (find(leap_days.begin(), leap_days.end(), i) != leap_days.end()) {
                l.emplace_back(*this, -i);
            }
        }
        return l;
    }

    const vector<string> RabByungDay::NAMES = {
        "初一", "初二", "初三", "初四", "初五", "初六", "初七", "初八", "初九", "初十", "十一", "十二", "十三", "十四", "十五", "十六", "十七", "十八", "十九", "二十", "廿一", "廿二", "廿三", "廿四", "廿五", "廿六", "廿七", "廿八", "廿九", "三十"
    };

    RabByungDay RabByungDay::from_ymd(const int year, const int month, const int day) {
        return RabByungDay(year, month, day);
    }

    RabByungDay RabByungDay::from_element_zodiac(const int rab_byung_index, const RabByungElement &element, const Zodiac &zodiac, const int month, const int day) {
        return RabByungDay(rab_byung_index, element, zodiac, month, day);
    }

    RabByungDay RabByungDay::from_solar_day(const SolarDay& solar_day) {
        int days = solar_day.subtract(SolarDay::from_ymd(1951, 1, 8));
        RabByungMonth m = RabByungMonth::from_ym(1950, 12);
        int count = m.get_day_count();
        while (days >= count) {
            days -= count;
            m = m.next(1);
            count = m.get_day_count();
        }
        int day = days + 1;
        for (const int d : m.get_special_days()) {
            if (d < 0) {
                if (day >= -d) {
                    day++;
                }
            } else if (d > 0) {
                if (day == d + 1) {
                    day = -d;
                    break;
                }
                if (day > d + 1) {
                    day--;
                }
            }
        }
        return RabByungDay(m, day);
    }

    RabByungMonth RabByungDay::get_rab_byung_month() const {
        return month;
    }

    int RabByungDay::get_year() const {
        return month.get_year();
    }

    int RabByungDay::get_month() const {
        return month.get_month_with_leap();
    }

    int RabByungDay::get_day() const {
        return day;
    }

    bool RabByungDay::is_leap() const {
        return leap;
    }

    int RabByungDay::get_day_with_leap() const {
        return leap ? -day : day;
    }

    string RabByungDay::get_name() const {
        return (leap ? "闰" : "") + NAMES[day - 1];
    }

    string RabByungDay::to_string() const {
        return month.to_string() + get_name();
    }

    int RabByungDay::subtract(const RabByungDay& target) const {
        return get_solar_day().subtract(target.get_solar_day());
    }

    SolarDay RabByungDay::get_solar_day() const {
        RabByungMonth m = RabByungMonth::from_ym(1950, 12);
        int n = 0;
        while (!month.equals(m)) {
            n += m.get_day_count();
            m = m.next(1);
        }
        int t = day;
        for (const int d : m.get_special_days()) {
            if (d < 0) {
                if (t > -d) {
                    t--;
                }
            } else if (d > 0) {
                if (t > d) {
                    t++;
                }
            }
        }
        if (leap) {
            t++;
        }
        return SolarDay::from_ymd(1951, 1, 7).next(n + t);
    }

    RabByungDay RabByungDay::next(const int n) const {
        return get_solar_day().next(n).get_rab_byung_day();
    }
}
