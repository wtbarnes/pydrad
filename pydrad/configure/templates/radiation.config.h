// ****
// *
// * #defines for configuring the radiation model
// *
// * (c) Dr. Stephen J. Bradshaw
// *
// * Source code generated by pydrad on {{ date }}
// *
// ****

// **** Physics ****
{% if radiation.elements_nonequilibrium -%}
#define NON_EQUILIBRIUM_RADIATION
{% if radiation.decouple_ionization_state_solver -%}
#define DECOUPLE_IONISATION_STATE_SOLVER
{%- endif %}
{% endif %}
{% if radiation.use_power_law_radiative_losses -%}
#define USE_POWER_LAW_RADIATIVE_LOSSES
{% if radiation.lookup_table %}
#define USE_RADIATION_LOOKUP_TABLE
#define RADIATION_LOOKUP_TABLE "{{ radiation.lookup_table }}"
{%- endif %}
{% endif %}
{% if radiation.density_dependent_rates -%}#define DENSITY_DEPENDENT_RATES{%- endif %}
{% if radiation.optically_thick_radiation -%}
#define OPTICALLY_THICK_RADIATION
{% if radiation.nlte_chromosphere -%}
#define NLTE_CHROMOSPHERE
#define MIN_DENSITY_LIMIT {{ radiation.minimum_density_limit | is_required | units_filter('cm^-3') }}
{%- endif %}
{%- endif %}

#include "../../HYDRAD/source/collisions.h"
// **** End of Physics ****

// **** Solver ****
#define MAX_OPTICALLY_THIN_DENSITY {{ solver.maximum_optically_thin_density | is_required | units_filter('cm^-3') }}
#define SAFETY_ATOMIC {{ solver.safety_atomic | is_required }}
#define CUTOFF_ION_FRACTION {{ solver.cutoff_ion_fraction | is_required }}
#define EPSILON_D {{ solver.epsilon_d | is_required }}
#define EPSILON_R {{ solver.epsilon_r | is_required }}
// **** End of Solver ****

{% if heating.beam -%}
// **** Heating ****
// This needs to be here because the radiation model is needed when constructing the electron
// beam and it is not imported anywhere else
#define BEAM_HEATING
{%- endif %}

