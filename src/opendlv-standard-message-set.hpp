
/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SIM_FRAME_HPP
#define OPENDLV_SIM_FRAME_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace sim {
using namespace std::string_literals; // NOLINT
class LIB_API Frame {
    private:
        static constexpr const char* TheShortName = "Frame";
        static constexpr const char* TheLongName = "opendlv.sim.Frame";

    public:
        inline static int32_t ID() {
            return 1001;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Frame() = default;
        Frame(const Frame&) = default;
        Frame& operator=(const Frame&) = default;
        Frame(Frame&&) = default;
        Frame& operator=(Frame&&) = default;
        ~Frame() = default;

    public:
        inline Frame& x(const float &v) noexcept {
            m_x = v;
            return *this;
        }
        inline float x() const noexcept {
            return m_x;
        }
        inline Frame& y(const float &v) noexcept {
            m_y = v;
            return *this;
        }
        inline float y() const noexcept {
            return m_y;
        }
        inline Frame& z(const float &v) noexcept {
            m_z = v;
            return *this;
        }
        inline float z() const noexcept {
            return m_z;
        }
        inline Frame& roll(const float &v) noexcept {
            m_roll = v;
            return *this;
        }
        inline float roll() const noexcept {
            return m_roll;
        }
        inline Frame& pitch(const float &v) noexcept {
            m_pitch = v;
            return *this;
        }
        inline float pitch() const noexcept {
            return m_pitch;
        }
        inline Frame& yaw(const float &v) noexcept {
            m_yaw = v;
            return *this;
        }
        inline float yaw() const noexcept {
            return m_yaw;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("x"s), m_x, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("y"s), m_y, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("z"s), m_z, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("roll"s), m_roll, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("pitch"s), m_pitch, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("yaw"s), m_yaw, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("x"s), m_x, visitor);
            doVisit(2, std::move("float"s), std::move("y"s), m_y, visitor);
            doVisit(3, std::move("float"s), std::move("z"s), m_z, visitor);
            doVisit(4, std::move("float"s), std::move("roll"s), m_roll, visitor);
            doVisit(5, std::move("float"s), std::move("pitch"s), m_pitch, visitor);
            doVisit(6, std::move("float"s), std::move("yaw"s), m_yaw, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("x"s), m_x, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("y"s), m_y, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("z"s), m_z, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("roll"s), m_roll, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("pitch"s), m_pitch, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("yaw"s), m_yaw, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_x{ 0.0f }; // field identifier = 1.
        float m_y{ 0.0f }; // field identifier = 2.
        float m_z{ 0.0f }; // field identifier = 3.
        float m_roll{ 0.0f }; // field identifier = 4.
        float m_pitch{ 0.0f }; // field identifier = 5.
        float m_yaw{ 0.0f }; // field identifier = 6.
};
}}

template<>
struct isVisitable<opendlv::sim::Frame> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::sim::Frame> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SIM_KINEMATICSTATE_HPP
#define OPENDLV_SIM_KINEMATICSTATE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace sim {
using namespace std::string_literals; // NOLINT
class LIB_API KinematicState {
    private:
        static constexpr const char* TheShortName = "KinematicState";
        static constexpr const char* TheLongName = "opendlv.sim.KinematicState";

    public:
        inline static int32_t ID() {
            return 1002;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        KinematicState() = default;
        KinematicState(const KinematicState&) = default;
        KinematicState& operator=(const KinematicState&) = default;
        KinematicState(KinematicState&&) = default;
        KinematicState& operator=(KinematicState&&) = default;
        ~KinematicState() = default;

    public:
        inline KinematicState& vx(const float &v) noexcept {
            m_vx = v;
            return *this;
        }
        inline float vx() const noexcept {
            return m_vx;
        }
        inline KinematicState& vy(const float &v) noexcept {
            m_vy = v;
            return *this;
        }
        inline float vy() const noexcept {
            return m_vy;
        }
        inline KinematicState& vz(const float &v) noexcept {
            m_vz = v;
            return *this;
        }
        inline float vz() const noexcept {
            return m_vz;
        }
        inline KinematicState& rollRate(const float &v) noexcept {
            m_rollRate = v;
            return *this;
        }
        inline float rollRate() const noexcept {
            return m_rollRate;
        }
        inline KinematicState& pitchRate(const float &v) noexcept {
            m_pitchRate = v;
            return *this;
        }
        inline float pitchRate() const noexcept {
            return m_pitchRate;
        }
        inline KinematicState& yawRate(const float &v) noexcept {
            m_yawRate = v;
            return *this;
        }
        inline float yawRate() const noexcept {
            return m_yawRate;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("vx"s), m_vx, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("vy"s), m_vy, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("vz"s), m_vz, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("vx"s), m_vx, visitor);
            doVisit(2, std::move("float"s), std::move("vy"s), m_vy, visitor);
            doVisit(3, std::move("float"s), std::move("vz"s), m_vz, visitor);
            doVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, visitor);
            doVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, visitor);
            doVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("vx"s), m_vx, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("vy"s), m_vy, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("vz"s), m_vz, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_vx{ 0.0f }; // field identifier = 1.
        float m_vy{ 0.0f }; // field identifier = 2.
        float m_vz{ 0.0f }; // field identifier = 3.
        float m_rollRate{ 0.0f }; // field identifier = 4.
        float m_pitchRate{ 0.0f }; // field identifier = 5.
        float m_yawRate{ 0.0f }; // field identifier = 6.
};
}}

template<>
struct isVisitable<opendlv::sim::KinematicState> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::sim::KinematicState> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_BODY_COMPONENTINFO_HPP
#define OPENDLV_BODY_COMPONENTINFO_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace body {
using namespace std::string_literals; // NOLINT
class LIB_API ComponentInfo {
    private:
        static constexpr const char* TheShortName = "ComponentInfo";
        static constexpr const char* TheLongName = "opendlv.body.ComponentInfo";

    public:
        inline static int32_t ID() {
            return 1021;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ComponentInfo() = default;
        ComponentInfo(const ComponentInfo&) = default;
        ComponentInfo& operator=(const ComponentInfo&) = default;
        ComponentInfo(ComponentInfo&&) = default;
        ComponentInfo& operator=(ComponentInfo&&) = default;
        ~ComponentInfo() = default;

    public:
        inline ComponentInfo& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }
        inline ComponentInfo& x(const float &v) noexcept {
            m_x = v;
            return *this;
        }
        inline float x() const noexcept {
            return m_x;
        }
        inline ComponentInfo& y(const float &v) noexcept {
            m_y = v;
            return *this;
        }
        inline float y() const noexcept {
            return m_y;
        }
        inline ComponentInfo& z(const float &v) noexcept {
            m_z = v;
            return *this;
        }
        inline float z() const noexcept {
            return m_z;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("x"s), m_x, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("y"s), m_y, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("z"s), m_z, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("description"s), m_description, visitor);
            doVisit(2, std::move("float"s), std::move("x"s), m_x, visitor);
            doVisit(3, std::move("float"s), std::move("y"s), m_y, visitor);
            doVisit(4, std::move("float"s), std::move("z"s), m_z, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("x"s), m_x, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("y"s), m_y, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("z"s), m_z, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_description{ ""s }; // field identifier = 1.
        float m_x{ 0.0f }; // field identifier = 2.
        float m_y{ 0.0f }; // field identifier = 3.
        float m_z{ 0.0f }; // field identifier = 4.
};
}}

template<>
struct isVisitable<opendlv::body::ComponentInfo> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::body::ComponentInfo> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_BODY_ACTUATORINFO_HPP
#define OPENDLV_BODY_ACTUATORINFO_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace body {
using namespace std::string_literals; // NOLINT
class LIB_API ActuatorInfo {
    private:
        static constexpr const char* TheShortName = "ActuatorInfo";
        static constexpr const char* TheLongName = "opendlv.body.ActuatorInfo";

    public:
        inline static int32_t ID() {
            return 1022;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ActuatorInfo() = default;
        ActuatorInfo(const ActuatorInfo&) = default;
        ActuatorInfo& operator=(const ActuatorInfo&) = default;
        ActuatorInfo(ActuatorInfo&&) = default;
        ActuatorInfo& operator=(ActuatorInfo&&) = default;
        ~ActuatorInfo() = default;

    public:
        inline ActuatorInfo& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }
        inline ActuatorInfo& x(const float &v) noexcept {
            m_x = v;
            return *this;
        }
        inline float x() const noexcept {
            return m_x;
        }
        inline ActuatorInfo& y(const float &v) noexcept {
            m_y = v;
            return *this;
        }
        inline float y() const noexcept {
            return m_y;
        }
        inline ActuatorInfo& z(const float &v) noexcept {
            m_z = v;
            return *this;
        }
        inline float z() const noexcept {
            return m_z;
        }
        inline ActuatorInfo& signalId(const uint32_t &v) noexcept {
            m_signalId = v;
            return *this;
        }
        inline uint32_t signalId() const noexcept {
            return m_signalId;
        }
        inline ActuatorInfo& minValue(const float &v) noexcept {
            m_minValue = v;
            return *this;
        }
        inline float minValue() const noexcept {
            return m_minValue;
        }
        inline ActuatorInfo& maxValue(const float &v) noexcept {
            m_maxValue = v;
            return *this;
        }
        inline float maxValue() const noexcept {
            return m_maxValue;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("x"s), m_x, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("y"s), m_y, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("z"s), m_z, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("uint32_t"s), std::move("signalId"s), m_signalId, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("minValue"s), m_minValue, visitor);
                return;
            }
            if (7 == fieldId) {
                doVisit(7, std::move("float"s), std::move("maxValue"s), m_maxValue, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("description"s), m_description, visitor);
            doVisit(2, std::move("float"s), std::move("x"s), m_x, visitor);
            doVisit(3, std::move("float"s), std::move("y"s), m_y, visitor);
            doVisit(4, std::move("float"s), std::move("z"s), m_z, visitor);
            doVisit(5, std::move("uint32_t"s), std::move("signalId"s), m_signalId, visitor);
            doVisit(6, std::move("float"s), std::move("minValue"s), m_minValue, visitor);
            doVisit(7, std::move("float"s), std::move("maxValue"s), m_maxValue, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("x"s), m_x, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("y"s), m_y, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("z"s), m_z, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("uint32_t"s), std::move("signalId"s), m_signalId, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("minValue"s), m_minValue, preVisit, visit, postVisit);
            doTripletForwardVisit(7, std::move("float"s), std::move("maxValue"s), m_maxValue, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_description{ ""s }; // field identifier = 1.
        float m_x{ 0.0f }; // field identifier = 2.
        float m_y{ 0.0f }; // field identifier = 3.
        float m_z{ 0.0f }; // field identifier = 4.
        uint32_t m_signalId{ 0 }; // field identifier = 5.
        float m_minValue{ 0.0f }; // field identifier = 6.
        float m_maxValue{ 0.0f }; // field identifier = 7.
};
}}

template<>
struct isVisitable<opendlv::body::ActuatorInfo> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::body::ActuatorInfo> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_BODY_SENSORINFO_HPP
#define OPENDLV_BODY_SENSORINFO_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace body {
using namespace std::string_literals; // NOLINT
class LIB_API SensorInfo {
    private:
        static constexpr const char* TheShortName = "SensorInfo";
        static constexpr const char* TheLongName = "opendlv.body.SensorInfo";

    public:
        inline static int32_t ID() {
            return 1023;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SensorInfo() = default;
        SensorInfo(const SensorInfo&) = default;
        SensorInfo& operator=(const SensorInfo&) = default;
        SensorInfo(SensorInfo&&) = default;
        SensorInfo& operator=(SensorInfo&&) = default;
        ~SensorInfo() = default;

    public:
        inline SensorInfo& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }
        inline SensorInfo& x(const float &v) noexcept {
            m_x = v;
            return *this;
        }
        inline float x() const noexcept {
            return m_x;
        }
        inline SensorInfo& y(const float &v) noexcept {
            m_y = v;
            return *this;
        }
        inline float y() const noexcept {
            return m_y;
        }
        inline SensorInfo& z(const float &v) noexcept {
            m_z = v;
            return *this;
        }
        inline float z() const noexcept {
            return m_z;
        }
        inline SensorInfo& signalId(const uint32_t &v) noexcept {
            m_signalId = v;
            return *this;
        }
        inline uint32_t signalId() const noexcept {
            return m_signalId;
        }
        inline SensorInfo& accuracyStd(const float &v) noexcept {
            m_accuracyStd = v;
            return *this;
        }
        inline float accuracyStd() const noexcept {
            return m_accuracyStd;
        }
        inline SensorInfo& minFrequency(const uint16_t &v) noexcept {
            m_minFrequency = v;
            return *this;
        }
        inline uint16_t minFrequency() const noexcept {
            return m_minFrequency;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("x"s), m_x, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("y"s), m_y, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("z"s), m_z, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("uint32_t"s), std::move("signalId"s), m_signalId, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("accuracyStd"s), m_accuracyStd, visitor);
                return;
            }
            if (7 == fieldId) {
                doVisit(7, std::move("uint16_t"s), std::move("minFrequency"s), m_minFrequency, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("description"s), m_description, visitor);
            doVisit(2, std::move("float"s), std::move("x"s), m_x, visitor);
            doVisit(3, std::move("float"s), std::move("y"s), m_y, visitor);
            doVisit(4, std::move("float"s), std::move("z"s), m_z, visitor);
            doVisit(5, std::move("uint32_t"s), std::move("signalId"s), m_signalId, visitor);
            doVisit(6, std::move("float"s), std::move("accuracyStd"s), m_accuracyStd, visitor);
            doVisit(7, std::move("uint16_t"s), std::move("minFrequency"s), m_minFrequency, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("x"s), m_x, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("y"s), m_y, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("z"s), m_z, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("uint32_t"s), std::move("signalId"s), m_signalId, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("accuracyStd"s), m_accuracyStd, preVisit, visit, postVisit);
            doTripletForwardVisit(7, std::move("uint16_t"s), std::move("minFrequency"s), m_minFrequency, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_description{ ""s }; // field identifier = 1.
        float m_x{ 0.0f }; // field identifier = 2.
        float m_y{ 0.0f }; // field identifier = 3.
        float m_z{ 0.0f }; // field identifier = 4.
        uint32_t m_signalId{ 0 }; // field identifier = 5.
        float m_accuracyStd{ 0.0f }; // field identifier = 6.
        uint16_t m_minFrequency{ 0 }; // field identifier = 7.
};
}}

template<>
struct isVisitable<opendlv::body::SensorInfo> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::body::SensorInfo> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_BODY_SIGNALINFO_HPP
#define OPENDLV_BODY_SIGNALINFO_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace body {
using namespace std::string_literals; // NOLINT
class LIB_API SignalInfo {
    private:
        static constexpr const char* TheShortName = "SignalInfo";
        static constexpr const char* TheLongName = "opendlv.body.SignalInfo";

    public:
        inline static int32_t ID() {
            return 1024;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SignalInfo() = default;
        SignalInfo(const SignalInfo&) = default;
        SignalInfo& operator=(const SignalInfo&) = default;
        SignalInfo(SignalInfo&&) = default;
        SignalInfo& operator=(SignalInfo&&) = default;
        ~SignalInfo() = default;

    public:
        inline SignalInfo& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }
        inline SignalInfo& signalId(const uint32_t &v) noexcept {
            m_signalId = v;
            return *this;
        }
        inline uint32_t signalId() const noexcept {
            return m_signalId;
        }
        inline SignalInfo& accuracyStd(const float &v) noexcept {
            m_accuracyStd = v;
            return *this;
        }
        inline float accuracyStd() const noexcept {
            return m_accuracyStd;
        }
        inline SignalInfo& minFrequency(const uint16_t &v) noexcept {
            m_minFrequency = v;
            return *this;
        }
        inline uint16_t minFrequency() const noexcept {
            return m_minFrequency;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("signalId"s), m_signalId, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("accuracyStd"s), m_accuracyStd, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("uint16_t"s), std::move("minFrequency"s), m_minFrequency, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("description"s), m_description, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("signalId"s), m_signalId, visitor);
            doVisit(3, std::move("float"s), std::move("accuracyStd"s), m_accuracyStd, visitor);
            doVisit(4, std::move("uint16_t"s), std::move("minFrequency"s), m_minFrequency, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("signalId"s), m_signalId, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("accuracyStd"s), m_accuracyStd, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("uint16_t"s), std::move("minFrequency"s), m_minFrequency, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_description{ ""s }; // field identifier = 1.
        uint32_t m_signalId{ 0 }; // field identifier = 2.
        float m_accuracyStd{ 0.0f }; // field identifier = 3.
        uint16_t m_minFrequency{ 0 }; // field identifier = 4.
};
}}

template<>
struct isVisitable<opendlv::body::SignalInfo> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::body::SignalInfo> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ACCELERATIONREADING_HPP
#define OPENDLV_PROXY_ACCELERATIONREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AccelerationReading {
    private:
        static constexpr const char* TheShortName = "AccelerationReading";
        static constexpr const char* TheLongName = "opendlv.proxy.AccelerationReading";

    public:
        inline static int32_t ID() {
            return 1030;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AccelerationReading() = default;
        AccelerationReading(const AccelerationReading&) = default;
        AccelerationReading& operator=(const AccelerationReading&) = default;
        AccelerationReading(AccelerationReading&&) = default;
        AccelerationReading& operator=(AccelerationReading&&) = default;
        ~AccelerationReading() = default;

    public:
        inline AccelerationReading& accelerationX(const float &v) noexcept {
            m_accelerationX = v;
            return *this;
        }
        inline float accelerationX() const noexcept {
            return m_accelerationX;
        }
        inline AccelerationReading& accelerationY(const float &v) noexcept {
            m_accelerationY = v;
            return *this;
        }
        inline float accelerationY() const noexcept {
            return m_accelerationY;
        }
        inline AccelerationReading& accelerationZ(const float &v) noexcept {
            m_accelerationZ = v;
            return *this;
        }
        inline float accelerationZ() const noexcept {
            return m_accelerationZ;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("accelerationX"s), m_accelerationX, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("accelerationY"s), m_accelerationY, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("accelerationZ"s), m_accelerationZ, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("accelerationX"s), m_accelerationX, visitor);
            doVisit(2, std::move("float"s), std::move("accelerationY"s), m_accelerationY, visitor);
            doVisit(3, std::move("float"s), std::move("accelerationZ"s), m_accelerationZ, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("accelerationX"s), m_accelerationX, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("accelerationY"s), m_accelerationY, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("accelerationZ"s), m_accelerationZ, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_accelerationX{ 0.0f }; // field identifier = 1.
        float m_accelerationY{ 0.0f }; // field identifier = 2.
        float m_accelerationZ{ 0.0f }; // field identifier = 3.
};
}}

template<>
struct isVisitable<opendlv::proxy::AccelerationReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AccelerationReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ANGULARVELOCITYREADING_HPP
#define OPENDLV_PROXY_ANGULARVELOCITYREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AngularVelocityReading {
    private:
        static constexpr const char* TheShortName = "AngularVelocityReading";
        static constexpr const char* TheLongName = "opendlv.proxy.AngularVelocityReading";

    public:
        inline static int32_t ID() {
            return 1031;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AngularVelocityReading() = default;
        AngularVelocityReading(const AngularVelocityReading&) = default;
        AngularVelocityReading& operator=(const AngularVelocityReading&) = default;
        AngularVelocityReading(AngularVelocityReading&&) = default;
        AngularVelocityReading& operator=(AngularVelocityReading&&) = default;
        ~AngularVelocityReading() = default;

    public:
        inline AngularVelocityReading& angularVelocityX(const float &v) noexcept {
            m_angularVelocityX = v;
            return *this;
        }
        inline float angularVelocityX() const noexcept {
            return m_angularVelocityX;
        }
        inline AngularVelocityReading& angularVelocityY(const float &v) noexcept {
            m_angularVelocityY = v;
            return *this;
        }
        inline float angularVelocityY() const noexcept {
            return m_angularVelocityY;
        }
        inline AngularVelocityReading& angularVelocityZ(const float &v) noexcept {
            m_angularVelocityZ = v;
            return *this;
        }
        inline float angularVelocityZ() const noexcept {
            return m_angularVelocityZ;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("angularVelocityX"s), m_angularVelocityX, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("angularVelocityY"s), m_angularVelocityY, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("angularVelocityZ"s), m_angularVelocityZ, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("angularVelocityX"s), m_angularVelocityX, visitor);
            doVisit(2, std::move("float"s), std::move("angularVelocityY"s), m_angularVelocityY, visitor);
            doVisit(3, std::move("float"s), std::move("angularVelocityZ"s), m_angularVelocityZ, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("angularVelocityX"s), m_angularVelocityX, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("angularVelocityY"s), m_angularVelocityY, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("angularVelocityZ"s), m_angularVelocityZ, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_angularVelocityX{ 0.0f }; // field identifier = 1.
        float m_angularVelocityY{ 0.0f }; // field identifier = 2.
        float m_angularVelocityZ{ 0.0f }; // field identifier = 3.
};
}}

template<>
struct isVisitable<opendlv::proxy::AngularVelocityReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AngularVelocityReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_MAGNETICFIELDREADING_HPP
#define OPENDLV_PROXY_MAGNETICFIELDREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API MagneticFieldReading {
    private:
        static constexpr const char* TheShortName = "MagneticFieldReading";
        static constexpr const char* TheLongName = "opendlv.proxy.MagneticFieldReading";

    public:
        inline static int32_t ID() {
            return 1032;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        MagneticFieldReading() = default;
        MagneticFieldReading(const MagneticFieldReading&) = default;
        MagneticFieldReading& operator=(const MagneticFieldReading&) = default;
        MagneticFieldReading(MagneticFieldReading&&) = default;
        MagneticFieldReading& operator=(MagneticFieldReading&&) = default;
        ~MagneticFieldReading() = default;

    public:
        inline MagneticFieldReading& magneticFieldX(const float &v) noexcept {
            m_magneticFieldX = v;
            return *this;
        }
        inline float magneticFieldX() const noexcept {
            return m_magneticFieldX;
        }
        inline MagneticFieldReading& magneticFieldY(const float &v) noexcept {
            m_magneticFieldY = v;
            return *this;
        }
        inline float magneticFieldY() const noexcept {
            return m_magneticFieldY;
        }
        inline MagneticFieldReading& magneticFieldZ(const float &v) noexcept {
            m_magneticFieldZ = v;
            return *this;
        }
        inline float magneticFieldZ() const noexcept {
            return m_magneticFieldZ;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("magneticFieldX"s), m_magneticFieldX, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("magneticFieldY"s), m_magneticFieldY, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("magneticFieldZ"s), m_magneticFieldZ, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("magneticFieldX"s), m_magneticFieldX, visitor);
            doVisit(2, std::move("float"s), std::move("magneticFieldY"s), m_magneticFieldY, visitor);
            doVisit(3, std::move("float"s), std::move("magneticFieldZ"s), m_magneticFieldZ, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("magneticFieldX"s), m_magneticFieldX, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("magneticFieldY"s), m_magneticFieldY, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("magneticFieldZ"s), m_magneticFieldZ, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_magneticFieldX{ 0.0f }; // field identifier = 1.
        float m_magneticFieldY{ 0.0f }; // field identifier = 2.
        float m_magneticFieldZ{ 0.0f }; // field identifier = 3.
};
}}

template<>
struct isVisitable<opendlv::proxy::MagneticFieldReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::MagneticFieldReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ALTITUDEREADING_HPP
#define OPENDLV_PROXY_ALTITUDEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AltitudeReading {
    private:
        static constexpr const char* TheShortName = "AltitudeReading";
        static constexpr const char* TheLongName = "opendlv.proxy.AltitudeReading";

    public:
        inline static int32_t ID() {
            return 1033;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AltitudeReading() = default;
        AltitudeReading(const AltitudeReading&) = default;
        AltitudeReading& operator=(const AltitudeReading&) = default;
        AltitudeReading(AltitudeReading&&) = default;
        AltitudeReading& operator=(AltitudeReading&&) = default;
        ~AltitudeReading() = default;

    public:
        inline AltitudeReading& altitude(const float &v) noexcept {
            m_altitude = v;
            return *this;
        }
        inline float altitude() const noexcept {
            return m_altitude;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("altitude"s), m_altitude, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("altitude"s), m_altitude, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("altitude"s), m_altitude, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_altitude{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::AltitudeReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AltitudeReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_PRESSUREREADING_HPP
#define OPENDLV_PROXY_PRESSUREREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PressureReading {
    private:
        static constexpr const char* TheShortName = "PressureReading";
        static constexpr const char* TheLongName = "opendlv.proxy.PressureReading";

    public:
        inline static int32_t ID() {
            return 1034;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PressureReading() = default;
        PressureReading(const PressureReading&) = default;
        PressureReading& operator=(const PressureReading&) = default;
        PressureReading(PressureReading&&) = default;
        PressureReading& operator=(PressureReading&&) = default;
        ~PressureReading() = default;

    public:
        inline PressureReading& pressure(const float &v) noexcept {
            m_pressure = v;
            return *this;
        }
        inline float pressure() const noexcept {
            return m_pressure;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_pressure{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::PressureReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PressureReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_TEMPERATUREREADING_HPP
#define OPENDLV_PROXY_TEMPERATUREREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API TemperatureReading {
    private:
        static constexpr const char* TheShortName = "TemperatureReading";
        static constexpr const char* TheLongName = "opendlv.proxy.TemperatureReading";

    public:
        inline static int32_t ID() {
            return 1035;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        TemperatureReading() = default;
        TemperatureReading(const TemperatureReading&) = default;
        TemperatureReading& operator=(const TemperatureReading&) = default;
        TemperatureReading(TemperatureReading&&) = default;
        TemperatureReading& operator=(TemperatureReading&&) = default;
        ~TemperatureReading() = default;

    public:
        inline TemperatureReading& temperature(const float &v) noexcept {
            m_temperature = v;
            return *this;
        }
        inline float temperature() const noexcept {
            return m_temperature;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_temperature{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::TemperatureReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::TemperatureReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_TORQUEREADING_HPP
#define OPENDLV_PROXY_TORQUEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API TorqueReading {
    private:
        static constexpr const char* TheShortName = "TorqueReading";
        static constexpr const char* TheLongName = "opendlv.proxy.TorqueReading";

    public:
        inline static int32_t ID() {
            return 1036;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        TorqueReading() = default;
        TorqueReading(const TorqueReading&) = default;
        TorqueReading& operator=(const TorqueReading&) = default;
        TorqueReading(TorqueReading&&) = default;
        TorqueReading& operator=(TorqueReading&&) = default;
        ~TorqueReading() = default;

    public:
        inline TorqueReading& torque(const float &v) noexcept {
            m_torque = v;
            return *this;
        }
        inline float torque() const noexcept {
            return m_torque;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("torque"s), m_torque, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("torque"s), m_torque, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("torque"s), m_torque, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_torque{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::TorqueReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::TorqueReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_VOLTAGEREADING_HPP
#define OPENDLV_PROXY_VOLTAGEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API VoltageReading {
    private:
        static constexpr const char* TheShortName = "VoltageReading";
        static constexpr const char* TheLongName = "opendlv.proxy.VoltageReading";

    public:
        inline static int32_t ID() {
            return 1037;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        VoltageReading() = default;
        VoltageReading(const VoltageReading&) = default;
        VoltageReading& operator=(const VoltageReading&) = default;
        VoltageReading(VoltageReading&&) = default;
        VoltageReading& operator=(VoltageReading&&) = default;
        ~VoltageReading() = default;

    public:
        inline VoltageReading& voltage(const float &v) noexcept {
            m_voltage = v;
            return *this;
        }
        inline float voltage() const noexcept {
            return m_voltage;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_voltage{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::VoltageReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::VoltageReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ANGLEREADING_HPP
#define OPENDLV_PROXY_ANGLEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AngleReading {
    private:
        static constexpr const char* TheShortName = "AngleReading";
        static constexpr const char* TheLongName = "opendlv.proxy.AngleReading";

    public:
        inline static int32_t ID() {
            return 1038;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AngleReading() = default;
        AngleReading(const AngleReading&) = default;
        AngleReading& operator=(const AngleReading&) = default;
        AngleReading(AngleReading&&) = default;
        AngleReading& operator=(AngleReading&&) = default;
        ~AngleReading() = default;

    public:
        inline AngleReading& angle(const float &v) noexcept {
            m_angle = v;
            return *this;
        }
        inline float angle() const noexcept {
            return m_angle;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("angle"s), m_angle, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("angle"s), m_angle, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("angle"s), m_angle, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_angle{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::AngleReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AngleReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_DISTANCEREADING_HPP
#define OPENDLV_PROXY_DISTANCEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API DistanceReading {
    private:
        static constexpr const char* TheShortName = "DistanceReading";
        static constexpr const char* TheLongName = "opendlv.proxy.DistanceReading";

    public:
        inline static int32_t ID() {
            return 1039;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        DistanceReading() = default;
        DistanceReading(const DistanceReading&) = default;
        DistanceReading& operator=(const DistanceReading&) = default;
        DistanceReading(DistanceReading&&) = default;
        DistanceReading& operator=(DistanceReading&&) = default;
        ~DistanceReading() = default;

    public:
        inline DistanceReading& distance(const float &v) noexcept {
            m_distance = v;
            return *this;
        }
        inline float distance() const noexcept {
            return m_distance;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("distance"s), m_distance, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("distance"s), m_distance, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("distance"s), m_distance, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_distance{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::DistanceReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::DistanceReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_SWITCHSTATEREADING_HPP
#define OPENDLV_PROXY_SWITCHSTATEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API SwitchStateReading {
    private:
        static constexpr const char* TheShortName = "SwitchStateReading";
        static constexpr const char* TheLongName = "opendlv.proxy.SwitchStateReading";

    public:
        inline static int32_t ID() {
            return 1040;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SwitchStateReading() = default;
        SwitchStateReading(const SwitchStateReading&) = default;
        SwitchStateReading& operator=(const SwitchStateReading&) = default;
        SwitchStateReading(SwitchStateReading&&) = default;
        SwitchStateReading& operator=(SwitchStateReading&&) = default;
        ~SwitchStateReading() = default;

    public:
        inline SwitchStateReading& state(const int16_t &v) noexcept {
            m_state = v;
            return *this;
        }
        inline int16_t state() const noexcept {
            return m_state;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int16_t"s), std::move("state"s), m_state, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int16_t"s), std::move("state"s), m_state, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int16_t"s), std::move("state"s), m_state, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int16_t m_state{ 0 }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::SwitchStateReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::SwitchStateReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_PEDALPOSITIONREADING_HPP
#define OPENDLV_PROXY_PEDALPOSITIONREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PedalPositionReading {
    private:
        static constexpr const char* TheShortName = "PedalPositionReading";
        static constexpr const char* TheLongName = "opendlv.proxy.PedalPositionReading";

    public:
        inline static int32_t ID() {
            return 1041;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PedalPositionReading() = default;
        PedalPositionReading(const PedalPositionReading&) = default;
        PedalPositionReading& operator=(const PedalPositionReading&) = default;
        PedalPositionReading(PedalPositionReading&&) = default;
        PedalPositionReading& operator=(PedalPositionReading&&) = default;
        ~PedalPositionReading() = default;

    public:
        inline PedalPositionReading& position(const float &v) noexcept {
            m_position = v;
            return *this;
        }
        inline float position() const noexcept {
            return m_position;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("position"s), m_position, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("position"s), m_position, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("position"s), m_position, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_position{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::PedalPositionReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PedalPositionReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDSTEERINGREADING_HPP
#define OPENDLV_PROXY_GROUNDSTEERINGREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSteeringReading {
    private:
        static constexpr const char* TheShortName = "GroundSteeringReading";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundSteeringReading";

    public:
        inline static int32_t ID() {
            return 1045;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSteeringReading() = default;
        GroundSteeringReading(const GroundSteeringReading&) = default;
        GroundSteeringReading& operator=(const GroundSteeringReading&) = default;
        GroundSteeringReading(GroundSteeringReading&&) = default;
        GroundSteeringReading& operator=(GroundSteeringReading&&) = default;
        ~GroundSteeringReading() = default;

    public:
        inline GroundSteeringReading& groundSteering(const float &v) noexcept {
            m_groundSteering = v;
            return *this;
        }
        inline float groundSteering() const noexcept {
            return m_groundSteering;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundSteering{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundSteeringReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundSteeringReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDSPEEDREADING_HPP
#define OPENDLV_PROXY_GROUNDSPEEDREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSpeedReading {
    private:
        static constexpr const char* TheShortName = "GroundSpeedReading";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundSpeedReading";

    public:
        inline static int32_t ID() {
            return 1046;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSpeedReading() = default;
        GroundSpeedReading(const GroundSpeedReading&) = default;
        GroundSpeedReading& operator=(const GroundSpeedReading&) = default;
        GroundSpeedReading(GroundSpeedReading&&) = default;
        GroundSpeedReading& operator=(GroundSpeedReading&&) = default;
        ~GroundSpeedReading() = default;

    public:
        inline GroundSpeedReading& groundSpeed(const float &v) noexcept {
            m_groundSpeed = v;
            return *this;
        }
        inline float groundSpeed() const noexcept {
            return m_groundSpeed;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundSpeed{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundSpeedReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundSpeedReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_WHEELSPEEDREADING_HPP
#define OPENDLV_PROXY_WHEELSPEEDREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API WheelSpeedReading {
    private:
        static constexpr const char* TheShortName = "WheelSpeedReading";
        static constexpr const char* TheLongName = "opendlv.proxy.WheelSpeedReading";

    public:
        inline static int32_t ID() {
            return 1047;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        WheelSpeedReading() = default;
        WheelSpeedReading(const WheelSpeedReading&) = default;
        WheelSpeedReading& operator=(const WheelSpeedReading&) = default;
        WheelSpeedReading(WheelSpeedReading&&) = default;
        WheelSpeedReading& operator=(WheelSpeedReading&&) = default;
        ~WheelSpeedReading() = default;

    public:
        inline WheelSpeedReading& wheelSpeed(const float &v) noexcept {
            m_wheelSpeed = v;
            return *this;
        }
        inline float wheelSpeed() const noexcept {
            return m_wheelSpeed;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("wheelSpeed"s), m_wheelSpeed, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("wheelSpeed"s), m_wheelSpeed, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("wheelSpeed"s), m_wheelSpeed, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_wheelSpeed{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::WheelSpeedReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::WheelSpeedReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_WEIGHTREADING_HPP
#define OPENDLV_PROXY_WEIGHTREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API WeightReading {
    private:
        static constexpr const char* TheShortName = "WeightReading";
        static constexpr const char* TheLongName = "opendlv.proxy.WeightReading";

    public:
        inline static int32_t ID() {
            return 1050;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        WeightReading() = default;
        WeightReading(const WeightReading&) = default;
        WeightReading& operator=(const WeightReading&) = default;
        WeightReading(WeightReading&&) = default;
        WeightReading& operator=(WeightReading&&) = default;
        ~WeightReading() = default;

    public:
        inline WeightReading& weight(const float &v) noexcept {
            m_weight = v;
            return *this;
        }
        inline float weight() const noexcept {
            return m_weight;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("weight"s), m_weight, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("weight"s), m_weight, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("weight"s), m_weight, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_weight{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::WeightReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::WeightReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GEODETICHEADINGREADING_HPP
#define OPENDLV_PROXY_GEODETICHEADINGREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GeodeticHeadingReading {
    private:
        static constexpr const char* TheShortName = "GeodeticHeadingReading";
        static constexpr const char* TheLongName = "opendlv.proxy.GeodeticHeadingReading";

    public:
        inline static int32_t ID() {
            return 1051;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GeodeticHeadingReading() = default;
        GeodeticHeadingReading(const GeodeticHeadingReading&) = default;
        GeodeticHeadingReading& operator=(const GeodeticHeadingReading&) = default;
        GeodeticHeadingReading(GeodeticHeadingReading&&) = default;
        GeodeticHeadingReading& operator=(GeodeticHeadingReading&&) = default;
        ~GeodeticHeadingReading() = default;

    public:
        inline GeodeticHeadingReading& northHeading(const float &v) noexcept {
            m_northHeading = v;
            return *this;
        }
        inline float northHeading() const noexcept {
            return m_northHeading;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("northHeading"s), m_northHeading, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("northHeading"s), m_northHeading, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("northHeading"s), m_northHeading, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_northHeading{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GeodeticHeadingReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GeodeticHeadingReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GEODETICWGS84READING_HPP
#define OPENDLV_PROXY_GEODETICWGS84READING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GeodeticWgs84Reading {
    private:
        static constexpr const char* TheShortName = "GeodeticWgs84Reading";
        static constexpr const char* TheLongName = "opendlv.proxy.GeodeticWgs84Reading";

    public:
        inline static int32_t ID() {
            return 19;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GeodeticWgs84Reading() = default;
        GeodeticWgs84Reading(const GeodeticWgs84Reading&) = default;
        GeodeticWgs84Reading& operator=(const GeodeticWgs84Reading&) = default;
        GeodeticWgs84Reading(GeodeticWgs84Reading&&) = default;
        GeodeticWgs84Reading& operator=(GeodeticWgs84Reading&&) = default;
        ~GeodeticWgs84Reading() = default;

    public:
        inline GeodeticWgs84Reading& latitude(const double &v) noexcept {
            m_latitude = v;
            return *this;
        }
        inline double latitude() const noexcept {
            return m_latitude;
        }
        inline GeodeticWgs84Reading& longitude(const double &v) noexcept {
            m_longitude = v;
            return *this;
        }
        inline double longitude() const noexcept {
            return m_longitude;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("double"s), std::move("longitude"s), m_longitude, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, visitor);
            doVisit(3, std::move("double"s), std::move("longitude"s), m_longitude, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("double"s), std::move("longitude"s), m_longitude, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        double m_latitude{ 0.0 }; // field identifier = 1.
        double m_longitude{ 0.0 }; // field identifier = 3.
};
}}

template<>
struct isVisitable<opendlv::proxy::GeodeticWgs84Reading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GeodeticWgs84Reading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_IMAGEREADING_HPP
#define OPENDLV_PROXY_IMAGEREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API ImageReading {
    private:
        static constexpr const char* TheShortName = "ImageReading";
        static constexpr const char* TheLongName = "opendlv.proxy.ImageReading";

    public:
        inline static int32_t ID() {
            return 1055;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ImageReading() = default;
        ImageReading(const ImageReading&) = default;
        ImageReading& operator=(const ImageReading&) = default;
        ImageReading(ImageReading&&) = default;
        ImageReading& operator=(ImageReading&&) = default;
        ~ImageReading() = default;

    public:
        inline ImageReading& fourcc(const std::string &v) noexcept {
            m_fourcc = v;
            return *this;
        }
        inline std::string fourcc() const noexcept {
            return m_fourcc;
        }
        inline ImageReading& width(const uint32_t &v) noexcept {
            m_width = v;
            return *this;
        }
        inline uint32_t width() const noexcept {
            return m_width;
        }
        inline ImageReading& height(const uint32_t &v) noexcept {
            m_height = v;
            return *this;
        }
        inline uint32_t height() const noexcept {
            return m_height;
        }
        inline ImageReading& data(const std::string &v) noexcept {
            m_data = v;
            return *this;
        }
        inline std::string data() const noexcept {
            return m_data;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("fourcc"s), m_fourcc, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("width"s), m_width, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint32_t"s), std::move("height"s), m_height, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("std::string"s), std::move("data"s), m_data, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("fourcc"s), m_fourcc, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("width"s), m_width, visitor);
            doVisit(3, std::move("uint32_t"s), std::move("height"s), m_height, visitor);
            doVisit(4, std::move("std::string"s), std::move("data"s), m_data, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("fourcc"s), m_fourcc, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("width"s), m_width, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint32_t"s), std::move("height"s), m_height, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("std::string"s), std::move("data"s), m_data, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_fourcc{ ""s }; // field identifier = 1.
        uint32_t m_width{ 0 }; // field identifier = 2.
        uint32_t m_height{ 0 }; // field identifier = 3.
        std::string m_data{ ""s }; // field identifier = 4.
};
}}

template<>
struct isVisitable<opendlv::proxy::ImageReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::ImageReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_IMAGEREADINGSHARED_HPP
#define OPENDLV_PROXY_IMAGEREADINGSHARED_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API ImageReadingShared {
    private:
        static constexpr const char* TheShortName = "ImageReadingShared";
        static constexpr const char* TheLongName = "opendlv.proxy.ImageReadingShared";

    public:
        inline static int32_t ID() {
            return 14;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ImageReadingShared() = default;
        ImageReadingShared(const ImageReadingShared&) = default;
        ImageReadingShared& operator=(const ImageReadingShared&) = default;
        ImageReadingShared(ImageReadingShared&&) = default;
        ImageReadingShared& operator=(ImageReadingShared&&) = default;
        ~ImageReadingShared() = default;

    public:
        inline ImageReadingShared& name(const std::string &v) noexcept {
            m_name = v;
            return *this;
        }
        inline std::string name() const noexcept {
            return m_name;
        }
        inline ImageReadingShared& size(const uint32_t &v) noexcept {
            m_size = v;
            return *this;
        }
        inline uint32_t size() const noexcept {
            return m_size;
        }
        inline ImageReadingShared& width(const uint32_t &v) noexcept {
            m_width = v;
            return *this;
        }
        inline uint32_t width() const noexcept {
            return m_width;
        }
        inline ImageReadingShared& height(const uint32_t &v) noexcept {
            m_height = v;
            return *this;
        }
        inline uint32_t height() const noexcept {
            return m_height;
        }
        inline ImageReadingShared& bytesPerPixel(const uint32_t &v) noexcept {
            m_bytesPerPixel = v;
            return *this;
        }
        inline uint32_t bytesPerPixel() const noexcept {
            return m_bytesPerPixel;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("name"s), m_name, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("size"s), m_size, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint32_t"s), std::move("width"s), m_width, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("uint32_t"s), std::move("height"s), m_height, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("uint32_t"s), std::move("bytesPerPixel"s), m_bytesPerPixel, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("name"s), m_name, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("size"s), m_size, visitor);
            doVisit(3, std::move("uint32_t"s), std::move("width"s), m_width, visitor);
            doVisit(4, std::move("uint32_t"s), std::move("height"s), m_height, visitor);
            doVisit(5, std::move("uint32_t"s), std::move("bytesPerPixel"s), m_bytesPerPixel, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("name"s), m_name, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("size"s), m_size, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint32_t"s), std::move("width"s), m_width, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("uint32_t"s), std::move("height"s), m_height, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("uint32_t"s), std::move("bytesPerPixel"s), m_bytesPerPixel, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_name{ ""s }; // field identifier = 1.
        uint32_t m_size{ 0 }; // field identifier = 2.
        uint32_t m_width{ 0 }; // field identifier = 3.
        uint32_t m_height{ 0 }; // field identifier = 4.
        uint32_t m_bytesPerPixel{ 0 }; // field identifier = 5.
};
}}

template<>
struct isVisitable<opendlv::proxy::ImageReadingShared> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::ImageReadingShared> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_POINTCLOUDREADING_HPP
#define OPENDLV_PROXY_POINTCLOUDREADING_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PointCloudReading {
    private:
        static constexpr const char* TheShortName = "PointCloudReading";
        static constexpr const char* TheLongName = "opendlv.proxy.PointCloudReading";

    public:
        inline static int32_t ID() {
            return 49;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PointCloudReading() = default;
        PointCloudReading(const PointCloudReading&) = default;
        PointCloudReading& operator=(const PointCloudReading&) = default;
        PointCloudReading(PointCloudReading&&) = default;
        PointCloudReading& operator=(PointCloudReading&&) = default;
        ~PointCloudReading() = default;

    public:
        inline PointCloudReading& startAzimuth(const float &v) noexcept {
            m_startAzimuth = v;
            return *this;
        }
        inline float startAzimuth() const noexcept {
            return m_startAzimuth;
        }
        inline PointCloudReading& endAzimuth(const float &v) noexcept {
            m_endAzimuth = v;
            return *this;
        }
        inline float endAzimuth() const noexcept {
            return m_endAzimuth;
        }
        inline PointCloudReading& entriesPerAzimuth(const uint8_t &v) noexcept {
            m_entriesPerAzimuth = v;
            return *this;
        }
        inline uint8_t entriesPerAzimuth() const noexcept {
            return m_entriesPerAzimuth;
        }
        inline PointCloudReading& distances(const std::string &v) noexcept {
            m_distances = v;
            return *this;
        }
        inline std::string distances() const noexcept {
            return m_distances;
        }
        inline PointCloudReading& numberOfBitsForIntensity(const uint8_t &v) noexcept {
            m_numberOfBitsForIntensity = v;
            return *this;
        }
        inline uint8_t numberOfBitsForIntensity() const noexcept {
            return m_numberOfBitsForIntensity;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("startAzimuth"s), m_startAzimuth, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("endAzimuth"s), m_endAzimuth, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint8_t"s), std::move("entriesPerAzimuth"s), m_entriesPerAzimuth, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("std::string"s), std::move("distances"s), m_distances, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("uint8_t"s), std::move("numberOfBitsForIntensity"s), m_numberOfBitsForIntensity, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("startAzimuth"s), m_startAzimuth, visitor);
            doVisit(2, std::move("float"s), std::move("endAzimuth"s), m_endAzimuth, visitor);
            doVisit(3, std::move("uint8_t"s), std::move("entriesPerAzimuth"s), m_entriesPerAzimuth, visitor);
            doVisit(4, std::move("std::string"s), std::move("distances"s), m_distances, visitor);
            doVisit(5, std::move("uint8_t"s), std::move("numberOfBitsForIntensity"s), m_numberOfBitsForIntensity, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("startAzimuth"s), m_startAzimuth, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("endAzimuth"s), m_endAzimuth, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint8_t"s), std::move("entriesPerAzimuth"s), m_entriesPerAzimuth, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("std::string"s), std::move("distances"s), m_distances, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("uint8_t"s), std::move("numberOfBitsForIntensity"s), m_numberOfBitsForIntensity, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_startAzimuth{ 0.0f }; // field identifier = 1.
        float m_endAzimuth{ 0.0f }; // field identifier = 2.
        uint8_t m_entriesPerAzimuth{ 0 }; // field identifier = 3.
        std::string m_distances{ ""s }; // field identifier = 4.
        uint8_t m_numberOfBitsForIntensity{ 0 }; // field identifier = 5.
};
}}

template<>
struct isVisitable<opendlv::proxy::PointCloudReading> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PointCloudReading> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_POINTCLOUDREADINGSHARED_HPP
#define OPENDLV_PROXY_POINTCLOUDREADINGSHARED_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PointCloudReadingShared {
    private:
        static constexpr const char* TheShortName = "PointCloudReadingShared";
        static constexpr const char* TheLongName = "opendlv.proxy.PointCloudReadingShared";

    public:
        inline static int32_t ID() {
            return 28;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PointCloudReadingShared() = default;
        PointCloudReadingShared(const PointCloudReadingShared&) = default;
        PointCloudReadingShared& operator=(const PointCloudReadingShared&) = default;
        PointCloudReadingShared(PointCloudReadingShared&&) = default;
        PointCloudReadingShared& operator=(PointCloudReadingShared&&) = default;
        ~PointCloudReadingShared() = default;

    public:
        inline PointCloudReadingShared& name(const std::string &v) noexcept {
            m_name = v;
            return *this;
        }
        inline std::string name() const noexcept {
            return m_name;
        }
        inline PointCloudReadingShared& size(const uint32_t &v) noexcept {
            m_size = v;
            return *this;
        }
        inline uint32_t size() const noexcept {
            return m_size;
        }
        inline PointCloudReadingShared& width(const uint32_t &v) noexcept {
            m_width = v;
            return *this;
        }
        inline uint32_t width() const noexcept {
            return m_width;
        }
        inline PointCloudReadingShared& height(const uint32_t &v) noexcept {
            m_height = v;
            return *this;
        }
        inline uint32_t height() const noexcept {
            return m_height;
        }
        inline PointCloudReadingShared& numberOfComponentsPerPoint(const uint8_t &v) noexcept {
            m_numberOfComponentsPerPoint = v;
            return *this;
        }
        inline uint8_t numberOfComponentsPerPoint() const noexcept {
            return m_numberOfComponentsPerPoint;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("std::string"s), std::move("name"s), m_name, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("size"s), m_size, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("uint32_t"s), std::move("width"s), m_width, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("uint32_t"s), std::move("height"s), m_height, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("uint8_t"s), std::move("numberOfComponentsPerPoint"s), m_numberOfComponentsPerPoint, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("std::string"s), std::move("name"s), m_name, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("size"s), m_size, visitor);
            doVisit(3, std::move("uint32_t"s), std::move("width"s), m_width, visitor);
            doVisit(4, std::move("uint32_t"s), std::move("height"s), m_height, visitor);
            doVisit(5, std::move("uint8_t"s), std::move("numberOfComponentsPerPoint"s), m_numberOfComponentsPerPoint, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("std::string"s), std::move("name"s), m_name, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("size"s), m_size, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("uint32_t"s), std::move("width"s), m_width, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("uint32_t"s), std::move("height"s), m_height, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("uint8_t"s), std::move("numberOfComponentsPerPoint"s), m_numberOfComponentsPerPoint, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        std::string m_name{ ""s }; // field identifier = 1.
        uint32_t m_size{ 0 }; // field identifier = 2.
        uint32_t m_width{ 0 }; // field identifier = 3.
        uint32_t m_height{ 0 }; // field identifier = 4.
        uint8_t m_numberOfComponentsPerPoint{ 0 }; // field identifier = 5.
};
}}

template<>
struct isVisitable<opendlv::proxy::PointCloudReadingShared> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PointCloudReadingShared> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_PRESSUREREQUEST_HPP
#define OPENDLV_PROXY_PRESSUREREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PressureRequest {
    private:
        static constexpr const char* TheShortName = "PressureRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.PressureRequest";

    public:
        inline static int32_t ID() {
            return 1080;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PressureRequest() = default;
        PressureRequest(const PressureRequest&) = default;
        PressureRequest& operator=(const PressureRequest&) = default;
        PressureRequest(PressureRequest&&) = default;
        PressureRequest& operator=(PressureRequest&&) = default;
        ~PressureRequest() = default;

    public:
        inline PressureRequest& pressure(const float &v) noexcept {
            m_pressure = v;
            return *this;
        }
        inline float pressure() const noexcept {
            return m_pressure;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("pressure"s), m_pressure, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_pressure{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::PressureRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PressureRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_TEMPERATUREREQUEST_HPP
#define OPENDLV_PROXY_TEMPERATUREREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API TemperatureRequest {
    private:
        static constexpr const char* TheShortName = "TemperatureRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.TemperatureRequest";

    public:
        inline static int32_t ID() {
            return 1081;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        TemperatureRequest() = default;
        TemperatureRequest(const TemperatureRequest&) = default;
        TemperatureRequest& operator=(const TemperatureRequest&) = default;
        TemperatureRequest(TemperatureRequest&&) = default;
        TemperatureRequest& operator=(TemperatureRequest&&) = default;
        ~TemperatureRequest() = default;

    public:
        inline TemperatureRequest& temperature(const float &v) noexcept {
            m_temperature = v;
            return *this;
        }
        inline float temperature() const noexcept {
            return m_temperature;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("temperature"s), m_temperature, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_temperature{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::TemperatureRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::TemperatureRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_TORQUEREQUEST_HPP
#define OPENDLV_PROXY_TORQUEREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API TorqueRequest {
    private:
        static constexpr const char* TheShortName = "TorqueRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.TorqueRequest";

    public:
        inline static int32_t ID() {
            return 1082;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        TorqueRequest() = default;
        TorqueRequest(const TorqueRequest&) = default;
        TorqueRequest& operator=(const TorqueRequest&) = default;
        TorqueRequest(TorqueRequest&&) = default;
        TorqueRequest& operator=(TorqueRequest&&) = default;
        ~TorqueRequest() = default;

    public:
        inline TorqueRequest& torque(const float &v) noexcept {
            m_torque = v;
            return *this;
        }
        inline float torque() const noexcept {
            return m_torque;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("torque"s), m_torque, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("torque"s), m_torque, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("torque"s), m_torque, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_torque{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::TorqueRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::TorqueRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_VOLTAGEREQUEST_HPP
#define OPENDLV_PROXY_VOLTAGEREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API VoltageRequest {
    private:
        static constexpr const char* TheShortName = "VoltageRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.VoltageRequest";

    public:
        inline static int32_t ID() {
            return 1083;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        VoltageRequest() = default;
        VoltageRequest(const VoltageRequest&) = default;
        VoltageRequest& operator=(const VoltageRequest&) = default;
        VoltageRequest(VoltageRequest&&) = default;
        VoltageRequest& operator=(VoltageRequest&&) = default;
        ~VoltageRequest() = default;

    public:
        inline VoltageRequest& voltage(const float &v) noexcept {
            m_voltage = v;
            return *this;
        }
        inline float voltage() const noexcept {
            return m_voltage;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("voltage"s), m_voltage, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_voltage{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::VoltageRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::VoltageRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_ANGLEREQUEST_HPP
#define OPENDLV_PROXY_ANGLEREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API AngleRequest {
    private:
        static constexpr const char* TheShortName = "AngleRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.AngleRequest";

    public:
        inline static int32_t ID() {
            return 1084;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AngleRequest() = default;
        AngleRequest(const AngleRequest&) = default;
        AngleRequest& operator=(const AngleRequest&) = default;
        AngleRequest(AngleRequest&&) = default;
        AngleRequest& operator=(AngleRequest&&) = default;
        ~AngleRequest() = default;

    public:
        inline AngleRequest& angle(const float &v) noexcept {
            m_angle = v;
            return *this;
        }
        inline float angle() const noexcept {
            return m_angle;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("angle"s), m_angle, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("angle"s), m_angle, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("angle"s), m_angle, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_angle{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::AngleRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::AngleRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_SWITCHSTATEREQUEST_HPP
#define OPENDLV_PROXY_SWITCHSTATEREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API SwitchStateRequest {
    private:
        static constexpr const char* TheShortName = "SwitchStateRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.SwitchStateRequest";

    public:
        inline static int32_t ID() {
            return 1085;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SwitchStateRequest() = default;
        SwitchStateRequest(const SwitchStateRequest&) = default;
        SwitchStateRequest& operator=(const SwitchStateRequest&) = default;
        SwitchStateRequest(SwitchStateRequest&&) = default;
        SwitchStateRequest& operator=(SwitchStateRequest&&) = default;
        ~SwitchStateRequest() = default;

    public:
        inline SwitchStateRequest& state(const int16_t &v) noexcept {
            m_state = v;
            return *this;
        }
        inline int16_t state() const noexcept {
            return m_state;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int16_t"s), std::move("state"s), m_state, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int16_t"s), std::move("state"s), m_state, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int16_t"s), std::move("state"s), m_state, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int16_t m_state{ 0 }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::SwitchStateRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::SwitchStateRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_PEDALPOSITIONREQUEST_HPP
#define OPENDLV_PROXY_PEDALPOSITIONREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PedalPositionRequest {
    private:
        static constexpr const char* TheShortName = "PedalPositionRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.PedalPositionRequest";

    public:
        inline static int32_t ID() {
            return 1086;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PedalPositionRequest() = default;
        PedalPositionRequest(const PedalPositionRequest&) = default;
        PedalPositionRequest& operator=(const PedalPositionRequest&) = default;
        PedalPositionRequest(PedalPositionRequest&&) = default;
        PedalPositionRequest& operator=(PedalPositionRequest&&) = default;
        ~PedalPositionRequest() = default;

    public:
        inline PedalPositionRequest& position(const float &v) noexcept {
            m_position = v;
            return *this;
        }
        inline float position() const noexcept {
            return m_position;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("position"s), m_position, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("position"s), m_position, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("position"s), m_position, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_position{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::PedalPositionRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PedalPositionRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_PULSEWIDTHMODULATIONREQUEST_HPP
#define OPENDLV_PROXY_PULSEWIDTHMODULATIONREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API PulseWidthModulationRequest {
    private:
        static constexpr const char* TheShortName = "PulseWidthModulationRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.PulseWidthModulationRequest";

    public:
        inline static int32_t ID() {
            return 1087;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PulseWidthModulationRequest() = default;
        PulseWidthModulationRequest(const PulseWidthModulationRequest&) = default;
        PulseWidthModulationRequest& operator=(const PulseWidthModulationRequest&) = default;
        PulseWidthModulationRequest(PulseWidthModulationRequest&&) = default;
        PulseWidthModulationRequest& operator=(PulseWidthModulationRequest&&) = default;
        ~PulseWidthModulationRequest() = default;

    public:
        inline PulseWidthModulationRequest& dutyCycleNs(const uint32_t &v) noexcept {
            m_dutyCycleNs = v;
            return *this;
        }
        inline uint32_t dutyCycleNs() const noexcept {
            return m_dutyCycleNs;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("dutyCycleNs"s), m_dutyCycleNs, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("dutyCycleNs"s), m_dutyCycleNs, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("dutyCycleNs"s), m_dutyCycleNs, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_dutyCycleNs{ 0 }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::PulseWidthModulationRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::PulseWidthModulationRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDSTEERINGREQUEST_HPP
#define OPENDLV_PROXY_GROUNDSTEERINGREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSteeringRequest {
    private:
        static constexpr const char* TheShortName = "GroundSteeringRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundSteeringRequest";

    public:
        inline static int32_t ID() {
            return 1090;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSteeringRequest() = default;
        GroundSteeringRequest(const GroundSteeringRequest&) = default;
        GroundSteeringRequest& operator=(const GroundSteeringRequest&) = default;
        GroundSteeringRequest(GroundSteeringRequest&&) = default;
        GroundSteeringRequest& operator=(GroundSteeringRequest&&) = default;
        ~GroundSteeringRequest() = default;

    public:
        inline GroundSteeringRequest& groundSteering(const float &v) noexcept {
            m_groundSteering = v;
            return *this;
        }
        inline float groundSteering() const noexcept {
            return m_groundSteering;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundSteering"s), m_groundSteering, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundSteering{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundSteeringRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundSteeringRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDSPEEDREQUEST_HPP
#define OPENDLV_PROXY_GROUNDSPEEDREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSpeedRequest {
    private:
        static constexpr const char* TheShortName = "GroundSpeedRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundSpeedRequest";

    public:
        inline static int32_t ID() {
            return 1091;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSpeedRequest() = default;
        GroundSpeedRequest(const GroundSpeedRequest&) = default;
        GroundSpeedRequest& operator=(const GroundSpeedRequest&) = default;
        GroundSpeedRequest(GroundSpeedRequest&&) = default;
        GroundSpeedRequest& operator=(GroundSpeedRequest&&) = default;
        ~GroundSpeedRequest() = default;

    public:
        inline GroundSpeedRequest& groundSpeed(const float &v) noexcept {
            m_groundSpeed = v;
            return *this;
        }
        inline float groundSpeed() const noexcept {
            return m_groundSpeed;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundSpeed"s), m_groundSpeed, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundSpeed{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundSpeedRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundSpeedRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDACCELERATIONREQUEST_HPP
#define OPENDLV_PROXY_GROUNDACCELERATIONREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundAccelerationRequest {
    private:
        static constexpr const char* TheShortName = "GroundAccelerationRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundAccelerationRequest";

    public:
        inline static int32_t ID() {
            return 1092;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundAccelerationRequest() = default;
        GroundAccelerationRequest(const GroundAccelerationRequest&) = default;
        GroundAccelerationRequest& operator=(const GroundAccelerationRequest&) = default;
        GroundAccelerationRequest(GroundAccelerationRequest&&) = default;
        GroundAccelerationRequest& operator=(GroundAccelerationRequest&&) = default;
        ~GroundAccelerationRequest() = default;

    public:
        inline GroundAccelerationRequest& groundAcceleration(const float &v) noexcept {
            m_groundAcceleration = v;
            return *this;
        }
        inline float groundAcceleration() const noexcept {
            return m_groundAcceleration;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundAcceleration"s), m_groundAcceleration, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundAcceleration"s), m_groundAcceleration, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundAcceleration"s), m_groundAcceleration, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundAcceleration{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundAccelerationRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundAccelerationRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_GROUNDDECELERATIONREQUEST_HPP
#define OPENDLV_PROXY_GROUNDDECELERATIONREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API GroundDecelerationRequest {
    private:
        static constexpr const char* TheShortName = "GroundDecelerationRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.GroundDecelerationRequest";

    public:
        inline static int32_t ID() {
            return 1093;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundDecelerationRequest() = default;
        GroundDecelerationRequest(const GroundDecelerationRequest&) = default;
        GroundDecelerationRequest& operator=(const GroundDecelerationRequest&) = default;
        GroundDecelerationRequest(GroundDecelerationRequest&&) = default;
        GroundDecelerationRequest& operator=(GroundDecelerationRequest&&) = default;
        ~GroundDecelerationRequest() = default;

    public:
        inline GroundDecelerationRequest& groundDeceleration(const float &v) noexcept {
            m_groundDeceleration = v;
            return *this;
        }
        inline float groundDeceleration() const noexcept {
            return m_groundDeceleration;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("groundDeceleration"s), m_groundDeceleration, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("groundDeceleration"s), m_groundDeceleration, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("groundDeceleration"s), m_groundDeceleration, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_groundDeceleration{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::GroundDecelerationRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::GroundDecelerationRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_PROXY_WHEELSPEEDREQUEST_HPP
#define OPENDLV_PROXY_WHEELSPEEDREQUEST_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace proxy {
using namespace std::string_literals; // NOLINT
class LIB_API WheelSpeedRequest {
    private:
        static constexpr const char* TheShortName = "WheelSpeedRequest";
        static constexpr const char* TheLongName = "opendlv.proxy.WheelSpeedRequest";

    public:
        inline static int32_t ID() {
            return 1094;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        WheelSpeedRequest() = default;
        WheelSpeedRequest(const WheelSpeedRequest&) = default;
        WheelSpeedRequest& operator=(const WheelSpeedRequest&) = default;
        WheelSpeedRequest(WheelSpeedRequest&&) = default;
        WheelSpeedRequest& operator=(WheelSpeedRequest&&) = default;
        ~WheelSpeedRequest() = default;

    public:
        inline WheelSpeedRequest& wheelSpeed(const float &v) noexcept {
            m_wheelSpeed = v;
            return *this;
        }
        inline float wheelSpeed() const noexcept {
            return m_wheelSpeed;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("wheelSpeed"s), m_wheelSpeed, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("wheelSpeed"s), m_wheelSpeed, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("wheelSpeed"s), m_wheelSpeed, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_wheelSpeed{ 0.0f }; // field identifier = 1.
};
}}

template<>
struct isVisitable<opendlv::proxy::WheelSpeedRequest> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::proxy::WheelSpeedRequest> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SYSTEM_SIGNALSTATUSMESSAGE_HPP
#define OPENDLV_SYSTEM_SIGNALSTATUSMESSAGE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace system {
using namespace std::string_literals; // NOLINT
class LIB_API SignalStatusMessage {
    private:
        static constexpr const char* TheShortName = "SignalStatusMessage";
        static constexpr const char* TheLongName = "opendlv.system.SignalStatusMessage";

    public:
        inline static int32_t ID() {
            return 1100;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SignalStatusMessage() = default;
        SignalStatusMessage(const SignalStatusMessage&) = default;
        SignalStatusMessage& operator=(const SignalStatusMessage&) = default;
        SignalStatusMessage(SignalStatusMessage&&) = default;
        SignalStatusMessage& operator=(SignalStatusMessage&&) = default;
        ~SignalStatusMessage() = default;

    public:
        inline SignalStatusMessage& code(const int32_t &v) noexcept {
            m_code = v;
            return *this;
        }
        inline int32_t code() const noexcept {
            return m_code;
        }
        inline SignalStatusMessage& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
            doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int32_t"s), std::move("code"s), m_code, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int32_t m_code{ 0 }; // field identifier = 1.
        std::string m_description{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::system::SignalStatusMessage> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::system::SignalStatusMessage> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SYSTEM_SYSTEMOPERATIONSTATE_HPP
#define OPENDLV_SYSTEM_SYSTEMOPERATIONSTATE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace system {
using namespace std::string_literals; // NOLINT
class LIB_API SystemOperationState {
    private:
        static constexpr const char* TheShortName = "SystemOperationState";
        static constexpr const char* TheLongName = "opendlv.system.SystemOperationState";

    public:
        inline static int32_t ID() {
            return 1101;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        SystemOperationState() = default;
        SystemOperationState(const SystemOperationState&) = default;
        SystemOperationState& operator=(const SystemOperationState&) = default;
        SystemOperationState(SystemOperationState&&) = default;
        SystemOperationState& operator=(SystemOperationState&&) = default;
        ~SystemOperationState() = default;

    public:
        inline SystemOperationState& code(const int32_t &v) noexcept {
            m_code = v;
            return *this;
        }
        inline int32_t code() const noexcept {
            return m_code;
        }
        inline SystemOperationState& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
            doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int32_t"s), std::move("code"s), m_code, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int32_t m_code{ 0 }; // field identifier = 1.
        std::string m_description{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::system::SystemOperationState> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::system::SystemOperationState> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_SYSTEM_NETWORKSTATUSMESSAGE_HPP
#define OPENDLV_SYSTEM_NETWORKSTATUSMESSAGE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace system {
using namespace std::string_literals; // NOLINT
class LIB_API NetworkStatusMessage {
    private:
        static constexpr const char* TheShortName = "NetworkStatusMessage";
        static constexpr const char* TheLongName = "opendlv.system.NetworkStatusMessage";

    public:
        inline static int32_t ID() {
            return 1102;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        NetworkStatusMessage() = default;
        NetworkStatusMessage(const NetworkStatusMessage&) = default;
        NetworkStatusMessage& operator=(const NetworkStatusMessage&) = default;
        NetworkStatusMessage(NetworkStatusMessage&&) = default;
        NetworkStatusMessage& operator=(NetworkStatusMessage&&) = default;
        ~NetworkStatusMessage() = default;

    public:
        inline NetworkStatusMessage& code(const int32_t &v) noexcept {
            m_code = v;
            return *this;
        }
        inline int32_t code() const noexcept {
            return m_code;
        }
        inline NetworkStatusMessage& description(const std::string &v) noexcept {
            m_description = v;
            return *this;
        }
        inline std::string description() const noexcept {
            return m_description;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("int32_t"s), std::move("code"s), m_code, visitor);
            doVisit(2, std::move("std::string"s), std::move("description"s), m_description, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("int32_t"s), std::move("code"s), m_code, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("description"s), m_description, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        int32_t m_code{ 0 }; // field identifier = 1.
        std::string m_description{ ""s }; // field identifier = 2.
};
}}

template<>
struct isVisitable<opendlv::system::NetworkStatusMessage> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::system::NetworkStatusMessage> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_SENSATION_DIRECTION_HPP
#define OPENDLV_LOGIC_SENSATION_DIRECTION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace sensation {
using namespace std::string_literals; // NOLINT
class LIB_API Direction {
    private:
        static constexpr const char* TheShortName = "Direction";
        static constexpr const char* TheLongName = "opendlv.logic.sensation.Direction";

    public:
        inline static int32_t ID() {
            return 1110;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Direction() = default;
        Direction(const Direction&) = default;
        Direction& operator=(const Direction&) = default;
        Direction(Direction&&) = default;
        Direction& operator=(Direction&&) = default;
        ~Direction() = default;

    public:
        inline Direction& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline Direction& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_azimuthAngle{ 0.0f }; // field identifier = 1.
        float m_zenithAngle{ 0.0f }; // field identifier = 2.
};
}}}

template<>
struct isVisitable<opendlv::logic::sensation::Direction> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::sensation::Direction> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_SENSATION_POINT_HPP
#define OPENDLV_LOGIC_SENSATION_POINT_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace sensation {
using namespace std::string_literals; // NOLINT
class LIB_API Point {
    private:
        static constexpr const char* TheShortName = "Point";
        static constexpr const char* TheLongName = "opendlv.logic.sensation.Point";

    public:
        inline static int32_t ID() {
            return 1111;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Point() = default;
        Point(const Point&) = default;
        Point& operator=(const Point&) = default;
        Point(Point&&) = default;
        Point& operator=(Point&&) = default;
        ~Point() = default;

    public:
        inline Point& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline Point& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }
        inline Point& distance(const float &v) noexcept {
            m_distance = v;
            return *this;
        }
        inline float distance() const noexcept {
            return m_distance;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("distance"s), m_distance, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_azimuthAngle{ 0.0f }; // field identifier = 1.
        float m_zenithAngle{ 0.0f }; // field identifier = 2.
        float m_distance{ 0.0f }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::sensation::Point> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::sensation::Point> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_SENSATION_GEOLOCATION_HPP
#define OPENDLV_LOGIC_SENSATION_GEOLOCATION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace sensation {
using namespace std::string_literals; // NOLINT
class LIB_API Geolocation {
    private:
        static constexpr const char* TheShortName = "Geolocation";
        static constexpr const char* TheLongName = "opendlv.logic.sensation.Geolocation";

    public:
        inline static int32_t ID() {
            return 1116;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Geolocation() = default;
        Geolocation(const Geolocation&) = default;
        Geolocation& operator=(const Geolocation&) = default;
        Geolocation(Geolocation&&) = default;
        Geolocation& operator=(Geolocation&&) = default;
        ~Geolocation() = default;

    public:
        inline Geolocation& latitude(const double &v) noexcept {
            m_latitude = v;
            return *this;
        }
        inline double latitude() const noexcept {
            return m_latitude;
        }
        inline Geolocation& longitude(const double &v) noexcept {
            m_longitude = v;
            return *this;
        }
        inline double longitude() const noexcept {
            return m_longitude;
        }
        inline Geolocation& altitude(const float &v) noexcept {
            m_altitude = v;
            return *this;
        }
        inline float altitude() const noexcept {
            return m_altitude;
        }
        inline Geolocation& heading(const float &v) noexcept {
            m_heading = v;
            return *this;
        }
        inline float heading() const noexcept {
            return m_heading;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("double"s), std::move("longitude"s), m_longitude, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("altitude"s), m_altitude, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("heading"s), m_heading, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, visitor);
            doVisit(2, std::move("double"s), std::move("longitude"s), m_longitude, visitor);
            doVisit(3, std::move("float"s), std::move("altitude"s), m_altitude, visitor);
            doVisit(4, std::move("float"s), std::move("heading"s), m_heading, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("double"s), std::move("latitude"s), m_latitude, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("double"s), std::move("longitude"s), m_longitude, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("altitude"s), m_altitude, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("heading"s), m_heading, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        double m_latitude{ 0.0 }; // field identifier = 1.
        double m_longitude{ 0.0 }; // field identifier = 2.
        float m_altitude{ 0.0f }; // field identifier = 3.
        float m_heading{ 0.0f }; // field identifier = 4.
};
}}}

template<>
struct isVisitable<opendlv::logic::sensation::Geolocation> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::sensation::Geolocation> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_SENSATION_EQUILIBRIOCEPTION_HPP
#define OPENDLV_LOGIC_SENSATION_EQUILIBRIOCEPTION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace sensation {
using namespace std::string_literals; // NOLINT
class LIB_API Equilibrioception {
    private:
        static constexpr const char* TheShortName = "Equilibrioception";
        static constexpr const char* TheLongName = "opendlv.logic.sensation.Equilibrioception";

    public:
        inline static int32_t ID() {
            return 1017;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Equilibrioception() = default;
        Equilibrioception(const Equilibrioception&) = default;
        Equilibrioception& operator=(const Equilibrioception&) = default;
        Equilibrioception(Equilibrioception&&) = default;
        Equilibrioception& operator=(Equilibrioception&&) = default;
        ~Equilibrioception() = default;

    public:
        inline Equilibrioception& vx(const float &v) noexcept {
            m_vx = v;
            return *this;
        }
        inline float vx() const noexcept {
            return m_vx;
        }
        inline Equilibrioception& vy(const float &v) noexcept {
            m_vy = v;
            return *this;
        }
        inline float vy() const noexcept {
            return m_vy;
        }
        inline Equilibrioception& vz(const float &v) noexcept {
            m_vz = v;
            return *this;
        }
        inline float vz() const noexcept {
            return m_vz;
        }
        inline Equilibrioception& rollRate(const float &v) noexcept {
            m_rollRate = v;
            return *this;
        }
        inline float rollRate() const noexcept {
            return m_rollRate;
        }
        inline Equilibrioception& pitchRate(const float &v) noexcept {
            m_pitchRate = v;
            return *this;
        }
        inline float pitchRate() const noexcept {
            return m_pitchRate;
        }
        inline Equilibrioception& yawRate(const float &v) noexcept {
            m_yawRate = v;
            return *this;
        }
        inline float yawRate() const noexcept {
            return m_yawRate;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("vx"s), m_vx, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("vy"s), m_vy, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("vz"s), m_vz, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("vx"s), m_vx, visitor);
            doVisit(2, std::move("float"s), std::move("vy"s), m_vy, visitor);
            doVisit(3, std::move("float"s), std::move("vz"s), m_vz, visitor);
            doVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, visitor);
            doVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, visitor);
            doVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("vx"s), m_vx, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("vy"s), m_vy, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("vz"s), m_vz, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("rollRate"s), m_rollRate, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("pitchRate"s), m_pitchRate, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("yawRate"s), m_yawRate, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_vx{ 0.0f }; // field identifier = 1.
        float m_vy{ 0.0f }; // field identifier = 2.
        float m_vz{ 0.0f }; // field identifier = 3.
        float m_rollRate{ 0.0f }; // field identifier = 4.
        float m_pitchRate{ 0.0f }; // field identifier = 5.
        float m_yawRate{ 0.0f }; // field identifier = 6.
};
}}}

template<>
struct isVisitable<opendlv::logic::sensation::Equilibrioception> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::sensation::Equilibrioception> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_OBJECT_HPP
#define OPENDLV_LOGIC_PERCEPTION_OBJECT_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API Object {
    private:
        static constexpr const char* TheShortName = "Object";
        static constexpr const char* TheLongName = "opendlv.logic.perception.Object";

    public:
        inline static int32_t ID() {
            return 1130;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        Object() = default;
        Object(const Object&) = default;
        Object& operator=(const Object&) = default;
        Object(Object&&) = default;
        Object& operator=(Object&&) = default;
        ~Object() = default;

    public:
        inline Object& objectId(const uint32_t &v) noexcept {
            m_objectId = v;
            return *this;
        }
        inline uint32_t objectId() const noexcept {
            return m_objectId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_objectId{ 0 }; // field identifier = 1.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::Object> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::Object> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_OBJECTTYPE_HPP
#define OPENDLV_LOGIC_PERCEPTION_OBJECTTYPE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API ObjectType {
    private:
        static constexpr const char* TheShortName = "ObjectType";
        static constexpr const char* TheLongName = "opendlv.logic.perception.ObjectType";

    public:
        inline static int32_t ID() {
            return 1131;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ObjectType() = default;
        ObjectType(const ObjectType&) = default;
        ObjectType& operator=(const ObjectType&) = default;
        ObjectType(ObjectType&&) = default;
        ObjectType& operator=(ObjectType&&) = default;
        ~ObjectType() = default;

    public:
        inline ObjectType& objectId(const uint32_t &v) noexcept {
            m_objectId = v;
            return *this;
        }
        inline uint32_t objectId() const noexcept {
            return m_objectId;
        }
        inline ObjectType& type(const uint32_t &v) noexcept {
            m_type = v;
            return *this;
        }
        inline uint32_t type() const noexcept {
            return m_type;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("type"s), m_type, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("type"s), m_type, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("type"s), m_type, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_objectId{ 0 }; // field identifier = 1.
        uint32_t m_type{ 0 }; // field identifier = 2.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::ObjectType> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::ObjectType> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_OBJECTPROPERTY_HPP
#define OPENDLV_LOGIC_PERCEPTION_OBJECTPROPERTY_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API ObjectProperty {
    private:
        static constexpr const char* TheShortName = "ObjectProperty";
        static constexpr const char* TheLongName = "opendlv.logic.perception.ObjectProperty";

    public:
        inline static int32_t ID() {
            return 1132;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ObjectProperty() = default;
        ObjectProperty(const ObjectProperty&) = default;
        ObjectProperty& operator=(const ObjectProperty&) = default;
        ObjectProperty(ObjectProperty&&) = default;
        ObjectProperty& operator=(ObjectProperty&&) = default;
        ~ObjectProperty() = default;

    public:
        inline ObjectProperty& objectId(const uint32_t &v) noexcept {
            m_objectId = v;
            return *this;
        }
        inline uint32_t objectId() const noexcept {
            return m_objectId;
        }
        inline ObjectProperty& property(const std::string &v) noexcept {
            m_property = v;
            return *this;
        }
        inline std::string property() const noexcept {
            return m_property;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("property"s), m_property, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
            doVisit(2, std::move("std::string"s), std::move("property"s), m_property, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("property"s), m_property, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_objectId{ 0 }; // field identifier = 1.
        std::string m_property{ ""s }; // field identifier = 2.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::ObjectProperty> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::ObjectProperty> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_OBJECTDIRECTION_HPP
#define OPENDLV_LOGIC_PERCEPTION_OBJECTDIRECTION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API ObjectDirection {
    private:
        static constexpr const char* TheShortName = "ObjectDirection";
        static constexpr const char* TheLongName = "opendlv.logic.perception.ObjectDirection";

    public:
        inline static int32_t ID() {
            return 1133;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ObjectDirection() = default;
        ObjectDirection(const ObjectDirection&) = default;
        ObjectDirection& operator=(const ObjectDirection&) = default;
        ObjectDirection(ObjectDirection&&) = default;
        ObjectDirection& operator=(ObjectDirection&&) = default;
        ~ObjectDirection() = default;

    public:
        inline ObjectDirection& objectId(const uint32_t &v) noexcept {
            m_objectId = v;
            return *this;
        }
        inline uint32_t objectId() const noexcept {
            return m_objectId;
        }
        inline ObjectDirection& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline ObjectDirection& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
            doVisit(2, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(3, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_objectId{ 0 }; // field identifier = 1.
        float m_azimuthAngle{ 0.0f }; // field identifier = 2.
        float m_zenithAngle{ 0.0f }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::ObjectDirection> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::ObjectDirection> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_OBJECTDISTANCE_HPP
#define OPENDLV_LOGIC_PERCEPTION_OBJECTDISTANCE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API ObjectDistance {
    private:
        static constexpr const char* TheShortName = "ObjectDistance";
        static constexpr const char* TheLongName = "opendlv.logic.perception.ObjectDistance";

    public:
        inline static int32_t ID() {
            return 1134;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ObjectDistance() = default;
        ObjectDistance(const ObjectDistance&) = default;
        ObjectDistance& operator=(const ObjectDistance&) = default;
        ObjectDistance(ObjectDistance&&) = default;
        ObjectDistance& operator=(ObjectDistance&&) = default;
        ~ObjectDistance() = default;

    public:
        inline ObjectDistance& objectId(const uint32_t &v) noexcept {
            m_objectId = v;
            return *this;
        }
        inline uint32_t objectId() const noexcept {
            return m_objectId;
        }
        inline ObjectDistance& distance(const float &v) noexcept {
            m_distance = v;
            return *this;
        }
        inline float distance() const noexcept {
            return m_distance;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("distance"s), m_distance, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
            doVisit(2, std::move("float"s), std::move("distance"s), m_distance, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("distance"s), m_distance, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_objectId{ 0 }; // field identifier = 1.
        float m_distance{ 0.0f }; // field identifier = 2.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::ObjectDistance> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::ObjectDistance> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_OBJECTANGULARBLOB_HPP
#define OPENDLV_LOGIC_PERCEPTION_OBJECTANGULARBLOB_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API ObjectAngularBlob {
    private:
        static constexpr const char* TheShortName = "ObjectAngularBlob";
        static constexpr const char* TheLongName = "opendlv.logic.perception.ObjectAngularBlob";

    public:
        inline static int32_t ID() {
            return 1135;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        ObjectAngularBlob() = default;
        ObjectAngularBlob(const ObjectAngularBlob&) = default;
        ObjectAngularBlob& operator=(const ObjectAngularBlob&) = default;
        ObjectAngularBlob(ObjectAngularBlob&&) = default;
        ObjectAngularBlob& operator=(ObjectAngularBlob&&) = default;
        ~ObjectAngularBlob() = default;

    public:
        inline ObjectAngularBlob& objectId(const uint32_t &v) noexcept {
            m_objectId = v;
            return *this;
        }
        inline uint32_t objectId() const noexcept {
            return m_objectId;
        }
        inline ObjectAngularBlob& width(const float &v) noexcept {
            m_width = v;
            return *this;
        }
        inline float width() const noexcept {
            return m_width;
        }
        inline ObjectAngularBlob& height(const float &v) noexcept {
            m_height = v;
            return *this;
        }
        inline float height() const noexcept {
            return m_height;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("width"s), m_width, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("height"s), m_height, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, visitor);
            doVisit(2, std::move("float"s), std::move("width"s), m_width, visitor);
            doVisit(3, std::move("float"s), std::move("height"s), m_height, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("objectId"s), m_objectId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("width"s), m_width, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("height"s), m_height, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_objectId{ 0 }; // field identifier = 1.
        float m_width{ 0.0f }; // field identifier = 2.
        float m_height{ 0.0f }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::ObjectAngularBlob> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::ObjectAngularBlob> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_GROUNDSURFACE_HPP
#define OPENDLV_LOGIC_PERCEPTION_GROUNDSURFACE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSurface {
    private:
        static constexpr const char* TheShortName = "GroundSurface";
        static constexpr const char* TheLongName = "opendlv.logic.perception.GroundSurface";

    public:
        inline static int32_t ID() {
            return 1140;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSurface() = default;
        GroundSurface(const GroundSurface&) = default;
        GroundSurface& operator=(const GroundSurface&) = default;
        GroundSurface(GroundSurface&&) = default;
        GroundSurface& operator=(GroundSurface&&) = default;
        ~GroundSurface() = default;

    public:
        inline GroundSurface& surfaceId(const uint32_t &v) noexcept {
            m_surfaceId = v;
            return *this;
        }
        inline uint32_t surfaceId() const noexcept {
            return m_surfaceId;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_surfaceId{ 0 }; // field identifier = 1.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::GroundSurface> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::GroundSurface> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_GROUNDSURFACETYPE_HPP
#define OPENDLV_LOGIC_PERCEPTION_GROUNDSURFACETYPE_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSurfaceType {
    private:
        static constexpr const char* TheShortName = "GroundSurfaceType";
        static constexpr const char* TheLongName = "opendlv.logic.perception.GroundSurfaceType";

    public:
        inline static int32_t ID() {
            return 1141;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSurfaceType() = default;
        GroundSurfaceType(const GroundSurfaceType&) = default;
        GroundSurfaceType& operator=(const GroundSurfaceType&) = default;
        GroundSurfaceType(GroundSurfaceType&&) = default;
        GroundSurfaceType& operator=(GroundSurfaceType&&) = default;
        ~GroundSurfaceType() = default;

    public:
        inline GroundSurfaceType& surfaceId(const uint32_t &v) noexcept {
            m_surfaceId = v;
            return *this;
        }
        inline uint32_t surfaceId() const noexcept {
            return m_surfaceId;
        }
        inline GroundSurfaceType& type(const uint32_t &v) noexcept {
            m_type = v;
            return *this;
        }
        inline uint32_t type() const noexcept {
            return m_type;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("uint32_t"s), std::move("type"s), m_type, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, visitor);
            doVisit(2, std::move("uint32_t"s), std::move("type"s), m_type, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("uint32_t"s), std::move("type"s), m_type, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_surfaceId{ 0 }; // field identifier = 1.
        uint32_t m_type{ 0 }; // field identifier = 2.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::GroundSurfaceType> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::GroundSurfaceType> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_GROUNDSURFACEPROPERTY_HPP
#define OPENDLV_LOGIC_PERCEPTION_GROUNDSURFACEPROPERTY_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSurfaceProperty {
    private:
        static constexpr const char* TheShortName = "GroundSurfaceProperty";
        static constexpr const char* TheLongName = "opendlv.logic.perception.GroundSurfaceProperty";

    public:
        inline static int32_t ID() {
            return 1142;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSurfaceProperty() = default;
        GroundSurfaceProperty(const GroundSurfaceProperty&) = default;
        GroundSurfaceProperty& operator=(const GroundSurfaceProperty&) = default;
        GroundSurfaceProperty(GroundSurfaceProperty&&) = default;
        GroundSurfaceProperty& operator=(GroundSurfaceProperty&&) = default;
        ~GroundSurfaceProperty() = default;

    public:
        inline GroundSurfaceProperty& surfaceId(const uint32_t &v) noexcept {
            m_surfaceId = v;
            return *this;
        }
        inline uint32_t surfaceId() const noexcept {
            return m_surfaceId;
        }
        inline GroundSurfaceProperty& property(const std::string &v) noexcept {
            m_property = v;
            return *this;
        }
        inline std::string property() const noexcept {
            return m_property;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("std::string"s), std::move("property"s), m_property, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, visitor);
            doVisit(2, std::move("std::string"s), std::move("property"s), m_property, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("std::string"s), std::move("property"s), m_property, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_surfaceId{ 0 }; // field identifier = 1.
        std::string m_property{ ""s }; // field identifier = 2.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::GroundSurfaceProperty> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::GroundSurfaceProperty> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_PERCEPTION_GROUNDSURFACEAREA_HPP
#define OPENDLV_LOGIC_PERCEPTION_GROUNDSURFACEAREA_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace perception {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSurfaceArea {
    private:
        static constexpr const char* TheShortName = "GroundSurfaceArea";
        static constexpr const char* TheLongName = "opendlv.logic.perception.GroundSurfaceArea";

    public:
        inline static int32_t ID() {
            return 1143;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSurfaceArea() = default;
        GroundSurfaceArea(const GroundSurfaceArea&) = default;
        GroundSurfaceArea& operator=(const GroundSurfaceArea&) = default;
        GroundSurfaceArea(GroundSurfaceArea&&) = default;
        GroundSurfaceArea& operator=(GroundSurfaceArea&&) = default;
        ~GroundSurfaceArea() = default;

    public:
        inline GroundSurfaceArea& surfaceId(const uint32_t &v) noexcept {
            m_surfaceId = v;
            return *this;
        }
        inline uint32_t surfaceId() const noexcept {
            return m_surfaceId;
        }
        inline GroundSurfaceArea& x1(const float &v) noexcept {
            m_x1 = v;
            return *this;
        }
        inline float x1() const noexcept {
            return m_x1;
        }
        inline GroundSurfaceArea& y1(const float &v) noexcept {
            m_y1 = v;
            return *this;
        }
        inline float y1() const noexcept {
            return m_y1;
        }
        inline GroundSurfaceArea& x2(const float &v) noexcept {
            m_x2 = v;
            return *this;
        }
        inline float x2() const noexcept {
            return m_x2;
        }
        inline GroundSurfaceArea& y2(const float &v) noexcept {
            m_y2 = v;
            return *this;
        }
        inline float y2() const noexcept {
            return m_y2;
        }
        inline GroundSurfaceArea& x3(const float &v) noexcept {
            m_x3 = v;
            return *this;
        }
        inline float x3() const noexcept {
            return m_x3;
        }
        inline GroundSurfaceArea& y3(const float &v) noexcept {
            m_y3 = v;
            return *this;
        }
        inline float y3() const noexcept {
            return m_y3;
        }
        inline GroundSurfaceArea& x4(const float &v) noexcept {
            m_x4 = v;
            return *this;
        }
        inline float x4() const noexcept {
            return m_x4;
        }
        inline GroundSurfaceArea& y4(const float &v) noexcept {
            m_y4 = v;
            return *this;
        }
        inline float y4() const noexcept {
            return m_y4;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("x1"s), m_x1, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("y1"s), m_y1, visitor);
                return;
            }
            if (4 == fieldId) {
                doVisit(4, std::move("float"s), std::move("x2"s), m_x2, visitor);
                return;
            }
            if (5 == fieldId) {
                doVisit(5, std::move("float"s), std::move("y2"s), m_y2, visitor);
                return;
            }
            if (6 == fieldId) {
                doVisit(6, std::move("float"s), std::move("x3"s), m_x3, visitor);
                return;
            }
            if (7 == fieldId) {
                doVisit(7, std::move("float"s), std::move("y3"s), m_y3, visitor);
                return;
            }
            if (8 == fieldId) {
                doVisit(8, std::move("float"s), std::move("x4"s), m_x4, visitor);
                return;
            }
            if (9 == fieldId) {
                doVisit(9, std::move("float"s), std::move("y4"s), m_y4, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, visitor);
            doVisit(2, std::move("float"s), std::move("x1"s), m_x1, visitor);
            doVisit(3, std::move("float"s), std::move("y1"s), m_y1, visitor);
            doVisit(4, std::move("float"s), std::move("x2"s), m_x2, visitor);
            doVisit(5, std::move("float"s), std::move("y2"s), m_y2, visitor);
            doVisit(6, std::move("float"s), std::move("x3"s), m_x3, visitor);
            doVisit(7, std::move("float"s), std::move("y3"s), m_y3, visitor);
            doVisit(8, std::move("float"s), std::move("x4"s), m_x4, visitor);
            doVisit(9, std::move("float"s), std::move("y4"s), m_y4, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("uint32_t"s), std::move("surfaceId"s), m_surfaceId, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("x1"s), m_x1, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("y1"s), m_y1, preVisit, visit, postVisit);
            doTripletForwardVisit(4, std::move("float"s), std::move("x2"s), m_x2, preVisit, visit, postVisit);
            doTripletForwardVisit(5, std::move("float"s), std::move("y2"s), m_y2, preVisit, visit, postVisit);
            doTripletForwardVisit(6, std::move("float"s), std::move("x3"s), m_x3, preVisit, visit, postVisit);
            doTripletForwardVisit(7, std::move("float"s), std::move("y3"s), m_y3, preVisit, visit, postVisit);
            doTripletForwardVisit(8, std::move("float"s), std::move("x4"s), m_x4, preVisit, visit, postVisit);
            doTripletForwardVisit(9, std::move("float"s), std::move("y4"s), m_y4, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        uint32_t m_surfaceId{ 0 }; // field identifier = 1.
        float m_x1{ 0.0f }; // field identifier = 2.
        float m_y1{ 0.0f }; // field identifier = 3.
        float m_x2{ 0.0f }; // field identifier = 4.
        float m_y2{ 0.0f }; // field identifier = 5.
        float m_x3{ 0.0f }; // field identifier = 6.
        float m_y3{ 0.0f }; // field identifier = 7.
        float m_x4{ 0.0f }; // field identifier = 8.
        float m_y4{ 0.0f }; // field identifier = 9.
};
}}}

template<>
struct isVisitable<opendlv::logic::perception::GroundSurfaceArea> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::perception::GroundSurfaceArea> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_ACTION_AIMDIRECTION_HPP
#define OPENDLV_LOGIC_ACTION_AIMDIRECTION_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace action {
using namespace std::string_literals; // NOLINT
class LIB_API AimDirection {
    private:
        static constexpr const char* TheShortName = "AimDirection";
        static constexpr const char* TheLongName = "opendlv.logic.action.AimDirection";

    public:
        inline static int32_t ID() {
            return 1171;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AimDirection() = default;
        AimDirection(const AimDirection&) = default;
        AimDirection& operator=(const AimDirection&) = default;
        AimDirection(AimDirection&&) = default;
        AimDirection& operator=(AimDirection&&) = default;
        ~AimDirection() = default;

    public:
        inline AimDirection& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline AimDirection& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_azimuthAngle{ 0.0f }; // field identifier = 1.
        float m_zenithAngle{ 0.0f }; // field identifier = 2.
};
}}}

template<>
struct isVisitable<opendlv::logic::action::AimDirection> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::action::AimDirection> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_ACTION_AIMPOINT_HPP
#define OPENDLV_LOGIC_ACTION_AIMPOINT_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace action {
using namespace std::string_literals; // NOLINT
class LIB_API AimPoint {
    private:
        static constexpr const char* TheShortName = "AimPoint";
        static constexpr const char* TheLongName = "opendlv.logic.action.AimPoint";

    public:
        inline static int32_t ID() {
            return 1172;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        AimPoint() = default;
        AimPoint(const AimPoint&) = default;
        AimPoint& operator=(const AimPoint&) = default;
        AimPoint(AimPoint&&) = default;
        AimPoint& operator=(AimPoint&&) = default;
        ~AimPoint() = default;

    public:
        inline AimPoint& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline AimPoint& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }
        inline AimPoint& distance(const float &v) noexcept {
            m_distance = v;
            return *this;
        }
        inline float distance() const noexcept {
            return m_distance;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("distance"s), m_distance, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_azimuthAngle{ 0.0f }; // field identifier = 1.
        float m_zenithAngle{ 0.0f }; // field identifier = 2.
        float m_distance{ 0.0f }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::action::AimPoint> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::action::AimPoint> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_ACTION_PREVIEWPOINT_HPP
#define OPENDLV_LOGIC_ACTION_PREVIEWPOINT_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace action {
using namespace std::string_literals; // NOLINT
class LIB_API PreviewPoint {
    private:
        static constexpr const char* TheShortName = "PreviewPoint";
        static constexpr const char* TheLongName = "opendlv.logic.action.PreviewPoint";

    public:
        inline static int32_t ID() {
            return 1173;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        PreviewPoint() = default;
        PreviewPoint(const PreviewPoint&) = default;
        PreviewPoint& operator=(const PreviewPoint&) = default;
        PreviewPoint(PreviewPoint&&) = default;
        PreviewPoint& operator=(PreviewPoint&&) = default;
        ~PreviewPoint() = default;

    public:
        inline PreviewPoint& azimuthAngle(const float &v) noexcept {
            m_azimuthAngle = v;
            return *this;
        }
        inline float azimuthAngle() const noexcept {
            return m_azimuthAngle;
        }
        inline PreviewPoint& zenithAngle(const float &v) noexcept {
            m_zenithAngle = v;
            return *this;
        }
        inline float zenithAngle() const noexcept {
            return m_zenithAngle;
        }
        inline PreviewPoint& distance(const float &v) noexcept {
            m_distance = v;
            return *this;
        }
        inline float distance() const noexcept {
            return m_distance;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
                return;
            }
            if (2 == fieldId) {
                doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
                return;
            }
            if (3 == fieldId) {
                doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, visitor);
            doVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, visitor);
            doVisit(3, std::move("float"s), std::move("distance"s), m_distance, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("azimuthAngle"s), m_azimuthAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(2, std::move("float"s), std::move("zenithAngle"s), m_zenithAngle, preVisit, visit, postVisit);
            doTripletForwardVisit(3, std::move("float"s), std::move("distance"s), m_distance, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_azimuthAngle{ 0.0f }; // field identifier = 1.
        float m_zenithAngle{ 0.0f }; // field identifier = 2.
        float m_distance{ 0.0f }; // field identifier = 3.
};
}}}

template<>
struct isVisitable<opendlv::logic::action::PreviewPoint> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::action::PreviewPoint> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_COGNITION_GROUNDSTEERINGLIMIT_HPP
#define OPENDLV_LOGIC_COGNITION_GROUNDSTEERINGLIMIT_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace cognition {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSteeringLimit {
    private:
        static constexpr const char* TheShortName = "GroundSteeringLimit";
        static constexpr const char* TheLongName = "opendlv.logic.cognition.GroundSteeringLimit";

    public:
        inline static int32_t ID() {
            return 1191;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSteeringLimit() = default;
        GroundSteeringLimit(const GroundSteeringLimit&) = default;
        GroundSteeringLimit& operator=(const GroundSteeringLimit&) = default;
        GroundSteeringLimit(GroundSteeringLimit&&) = default;
        GroundSteeringLimit& operator=(GroundSteeringLimit&&) = default;
        ~GroundSteeringLimit() = default;

    public:
        inline GroundSteeringLimit& steeringLimit(const float &v) noexcept {
            m_steeringLimit = v;
            return *this;
        }
        inline float steeringLimit() const noexcept {
            return m_steeringLimit;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("steeringLimit"s), m_steeringLimit, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("steeringLimit"s), m_steeringLimit, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("steeringLimit"s), m_steeringLimit, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_steeringLimit{ 0.0f }; // field identifier = 1.
};
}}}

template<>
struct isVisitable<opendlv::logic::cognition::GroundSteeringLimit> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::cognition::GroundSteeringLimit> {
    static const bool value = true;
};
#endif


/*
 * THIS IS AN AUTO-GENERATED FILE. DO NOT MODIFY AS CHANGES MIGHT BE OVERWRITTEN!
 */

#ifndef VISITABLE_TYPE_TRAIT
#define VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct visitorSelector {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct visitorSelector<true> {
    template<typename T, class Visitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
        visitor.visit(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<typename T>
struct isVisitable {
    static const bool value = false;
};

template<typename T, class Visitor>
void doVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, Visitor &visitor) {
    visitorSelector<isVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, visitor);
}
#endif

#ifndef TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#define TRIPLET_FORWARD_VISITABLE_TYPE_TRAIT
#include <cstdint>
#include <string>
#include <utility>

template<bool b>
struct tripletForwardVisitorSelector {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)preVisit;
        (void)postVisit;
        std::forward<Visitor>(visit)(fieldIdentifier, std::move(typeName), std::move(name), value);
    }
};

template<>
struct tripletForwardVisitorSelector<true> {
    template<typename T, class PreVisitor, class Visitor, class PostVisitor>
    static void impl(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
        (void)fieldIdentifier;
        (void)typeName;
        (void)name;
        // Apply preVisit, visit, and postVisit on value.
        value.accept(preVisit, visit, postVisit);
    }
};

template<typename T>
struct isTripletForwardVisitable {
    static const bool value = false;
};

template< typename T, class PreVisitor, class Visitor, class PostVisitor>
void doTripletForwardVisit(uint32_t fieldIdentifier, std::string &&typeName, std::string &&name, T &value, PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
    tripletForwardVisitorSelector<isTripletForwardVisitable<T>::value >::impl(fieldIdentifier, std::move(typeName), std::move(name), value, std::move(preVisit), std::move(visit), std::move(postVisit)); // NOLINT
}
#endif


#ifndef OPENDLV_LOGIC_COGNITION_GROUNDSPEEDLIMIT_HPP
#define OPENDLV_LOGIC_COGNITION_GROUNDSPEEDLIMIT_HPP

#ifdef WIN32
    // Export symbols if compile flags "LIB_SHARED" and "LIB_EXPORTS" are set on Windows.
    #ifdef LIB_SHARED
        #ifdef LIB_EXPORTS
            #define LIB_API __declspec(dllexport)
        #else
            #define LIB_API __declspec(dllimport)
        #endif
    #else
        // Disable definition if linking statically.
        #define LIB_API
    #endif
#else
    // Disable definition for non-Win32 systems.
    #define LIB_API
#endif

#include <string>
#include <utility>
namespace opendlv { namespace logic { namespace cognition {
using namespace std::string_literals; // NOLINT
class LIB_API GroundSpeedLimit {
    private:
        static constexpr const char* TheShortName = "GroundSpeedLimit";
        static constexpr const char* TheLongName = "opendlv.logic.cognition.GroundSpeedLimit";

    public:
        inline static int32_t ID() {
            return 1192;
        }
        inline static const std::string ShortName() {
            return TheShortName;
        }
        inline static const std::string LongName() {
            return TheLongName;
        }

    public:
        GroundSpeedLimit() = default;
        GroundSpeedLimit(const GroundSpeedLimit&) = default;
        GroundSpeedLimit& operator=(const GroundSpeedLimit&) = default;
        GroundSpeedLimit(GroundSpeedLimit&&) = default;
        GroundSpeedLimit& operator=(GroundSpeedLimit&&) = default;
        ~GroundSpeedLimit() = default;

    public:
        inline GroundSpeedLimit& speedLimit(const float &v) noexcept {
            m_speedLimit = v;
            return *this;
        }
        inline float speedLimit() const noexcept {
            return m_speedLimit;
        }

    public:
        template<class Visitor>
        inline void accept(uint32_t fieldId, Visitor &visitor) {
            (void)fieldId;
            (void)visitor;
//            visitor.preVisit(ID(), ShortName(), LongName());
            if (1 == fieldId) {
                doVisit(1, std::move("float"s), std::move("speedLimit"s), m_speedLimit, visitor);
                return;
            }
//            visitor.postVisit();
        }

        template<class Visitor>
        inline void accept(Visitor &visitor) {
            visitor.preVisit(ID(), ShortName(), LongName());
            doVisit(1, std::move("float"s), std::move("speedLimit"s), m_speedLimit, visitor);
            visitor.postVisit();
        }

        template<class PreVisitor, class Visitor, class PostVisitor>
        inline void accept(PreVisitor &&preVisit, Visitor &&visit, PostVisitor &&postVisit) {
            (void)visit; // Prevent warnings from empty messages.
            std::forward<PreVisitor>(preVisit)(ID(), ShortName(), LongName());
            doTripletForwardVisit(1, std::move("float"s), std::move("speedLimit"s), m_speedLimit, preVisit, visit, postVisit);
            std::forward<PostVisitor>(postVisit)();
        }

    private:
        float m_speedLimit{ 0.0f }; // field identifier = 1.
};
}}}

template<>
struct isVisitable<opendlv::logic::cognition::GroundSpeedLimit> {
    static const bool value = true;
};
template<>
struct isTripletForwardVisitable<opendlv::logic::cognition::GroundSpeedLimit> {
    static const bool value = true;
};
#endif

