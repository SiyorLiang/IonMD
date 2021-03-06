#ifndef TRAP_HPP
#define TRAP_HPP

#include <sstream>
#include <string>
#include <memory>
#include <json.hpp>
#include <ionmd/constants.hpp>

namespace ionmd {

/**
 * Trap parameters.
 *
 * This remains separate from the `SimParams` struct because it may be
 * interesting in the future to allow for some dynamic changes to, for example,
 * the frequency or voltages.
 *
 * Units are SI.
 */
struct Trap
{
    /// Trap radius
    double r0 = 3.18e-3;

    /// Half the length of the trap.
    double z0 = 0.0125;

    /// Geometric parameter determined empirically.
    double kappa = 0.006;

    /// rf (angular) frequency
    double omega_rf = 2*constants::pi*2.7e6;

    /// rf amplitude
    double V_rf = 125;

    /// rf offset from ground
    double U_dc = 0;

    /// End cap voltage
    double U_ec = 5;

    auto to_string() const -> std::string
    {
        std::stringstream stream;
        stream << "Trap parameters:\n"
               << "  r0 = " << r0 << "\n"
               << "  z0 = " << z0 << "\n"
               << "  kappa = " << kappa << "\n"
               << "  V_rf = " << V_rf << "\n"
               << "  U_dc = " << U_dc << "\n"
               << "  U_ec = " << U_ec << "\n";
        return stream.str();
    }

    auto to_json() const -> std::string
    {
        using nlohmann::json;
        json j = {
            {"r0", r0},
            {"z0", z0},
            {"kappa", kappa},
            {"V_rf", V_rf},
            {"U_dc", U_dc},
            {"U_ec", U_ec}
        };

        return j.dump(2);
    }
};

typedef std::shared_ptr<Trap> trap_ptr;

}

#endif
