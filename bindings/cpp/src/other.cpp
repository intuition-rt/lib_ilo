#include "common.hpp"
#include "../include/ilo.hpp"

void Ilo::set_debug_state(bool debug) {
  char *builded_trame = build_trame(
      "set_debug_state", {
        { "state", String(debug).c_str() },
      }
  );
}
