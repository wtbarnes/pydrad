// ****
// *
// * #defines for configuring the hydrodynamic model
// *
// * (c) Dr. Stephen J. Bradshaw
// *
// * Source code generated by hydrad_tools on {{date}}
// *
// ****

// **** Output ****
{% if general.write_file_physical %}#define WRITE_FILE_PHYSICAL{% endif %}
{% if general.write_file_ion_populations %}#define WRITE_FILE_ION_POPULATIONS{% endif %}
{% if general.write_file_hydrogen_level_populations %}#define WRITE_FILE_HSTATE{% endif %}
{% if general.write_file_timescales %}#define WRITE_FILE_SCALES{% endif %}
{% if general.write_file_equation_terms %}#define WRITE_FILE_TERMS{% endif %}
#define OUTPUT_EVERY_N_TIME_STEPS {{ general.logging_frequency }}
// **** End of Output ****

// **** Physics ****
#include "../../Heating_Model/source/config.h"
#include "../../Radiation_Model/source/config.h"
#define HEAT_FLUX_LIMITING_COEFFICIENT {{ general.heat_flux_limiting_coefficient }}
#define TIME_STEP_LIMIT {{ general.heat_flux_timestep_limit }}
{% if general.use_kinetic_model %}#define USE_KINETIC_MODEL{% endif %}
#include "collisions.h"
{% if general.tabulated_gravity_file -%}
#define USE_TABULATED_GRAVITY
#define TABULATED_GRAVITY_FILE {{ general.tabulated_gravity_file }}
{%- endif %}
{% if general.tabulated_cross_section_file -%}
#define USE_TABULATED_CROSS_SECTION
#define TABULATED_CROSS_SECTION_FILE {{ general.tabulated_cross_section_file }}
{%- endif %}
// **** End of Physics ****

// **** Solver ****
#define SAFETY_RADIATION {{ solver.safety_radiation }}
#define SAFETY_CONDUCTION {{ solver.safety_conduction }}
#define SAFETY_ADVECTION {{ solver.safety_advection }}
#define SAFETY_VISCOSITY {{ solver.safety_viscosity }}
#define TIME_STEP_INCREASE_LIMIT {{ solver.timestep_increase_limit | units_filter('%') / 100.0 + 1.0 }}
{% if solver.relative_viscous_timescale -%}
#define NUMERICAL_VISCOSITY
#define RELATIVE_VISCOUS_TIME_SCALE {{ solver.relative_viscous_timescale }}
{%- endif %}
#define MINIMUM_RADIATION_TEMPERATURE {{ solver.minimum_radiation_temperature | units_filter('K') }}
#define ZERO_OVER_TEMPERATURE_INTERVAL {{ solver.zero_over_temperature_interval }}
#define MINIMUM_TEMPERATURE {{ solver.minimum_temperature | units_filter('K') }}
// **** End of Solver ****

// **** Grid ****
#define MAX_REFINEMENT_LEVEL {{ grid.maximum_refinement_level }}
{% if grid.adapt -%}
#define ADAPT
#define ADAPT_EVERY_N_TIME_STEPS {{ grid.adapt_every_n_time_steps }}
{% if grid.refine_on_density %}#define REFINE_ON_DENSITY{% endif %}
{% if grid.refine_on_electron_energy %}#define REFINE_ON_ELECTRON_ENERGY{% endif %}
{% if grid.refine_on_hydrogen_energy %}#define REFINE_ON_HYDROGEN_ENERGY{% endif %}
#define MIN_FRAC_DIFF {{ grid.minimum_fractional_difference | units_filter('%') / 100.0 }}
#define MAX_FRAC_DIFF {{ grid.maximum_fractional_difference | units_filter('%') / 100.0 }}
{% if grid.linear_restriction %}#define LINEAR_RESTRICTION{% endif %}
{% if grid.enforce_conservation %}#define ENFORCE_CONSERVATION{% endif %}
{%- endif %}
// **** End of Grid ****
