#include "dev_opts.hpp"

bool& dev_opts::show_perf_info = *reinterpret_cast<bool*>(0x1106978);

bool& dev_opts::god_mode = *reinterpret_cast<bool*>(0xE89AFC);

bool& dev_opts::instant_kill = *reinterpret_cast<bool*>(0xE89AFD);

bool& dev_opts::traffic_enabled = *reinterpret_cast<bool*>(0xD0ED30);