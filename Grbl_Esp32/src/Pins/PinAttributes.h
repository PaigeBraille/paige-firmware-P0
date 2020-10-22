#pragma once

#include <cstdint>

#include "PinCapabilities.h"

namespace Pins {
    /*
    Pin attributes are what a pin _should_ do in the current configuration. Note that there's 
    an overlap with pin capabilities; in fact, pin attributes are validated with pin capabilities
    to check if they are valid.

    You should use pin attributes in the same way as 'set mode' in native Arduino. When setting pin
    attributes, you basically specify some behavior that you want, and if the pin is capable of 
    delivering these attributes, it will work. Otherwise... you will get a very nasty error.
    */
    class PinAttributes {
        uint32_t _value;

        constexpr PinAttributes(const uint32_t value) : _value(value) {}

    public:
        PinAttributes(const PinAttributes&) = default;
        PinAttributes& operator=(const PinAttributes&) = default;

        // All the capabilities we use and test:
        static PinAttributes Undefined;
        static PinAttributes None;

        static PinAttributes Input;
        static PinAttributes Output;
        static PinAttributes PullUp;
        static PinAttributes PullDown;
        static PinAttributes ISR;

        static PinAttributes ActiveLow;
        static PinAttributes Exclusive;
        static PinAttributes InitialHigh;

        inline PinAttributes operator|(PinAttributes rhs) { return PinAttributes(_value | rhs._value); }
        inline PinAttributes operator&(PinAttributes rhs) { return PinAttributes(_value & rhs._value); }
        inline bool          operator==(PinAttributes rhs) const { return _value == rhs._value; }
        inline bool          operator!=(PinAttributes rhs) const { return _value != rhs._value; }

        inline operator bool() { return _value != 0; }

        bool        conflictsWith(PinAttributes t);
        bool        validateWith(PinCapabilities caps);
        inline bool has(PinAttributes attr) { return ((*this) & attr).operator bool(); }
    };
}
