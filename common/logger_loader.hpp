// SPDX-License-Identifier: MIT

#ifndef SHIGENOY_USDDYNAMICFILEFORMATS_COMMON_LOGGER_LOADER_HPP_INCLUDED
#define SHIGENOY_USDDYNAMICFILEFORMATS_COMMON_LOGGER_LOADER_HPP_INCLUDED

#include <filesystem>
#include <memory>
#include <string>
#include <vector>

#include "spdlog/cfg/env.h"
#include "spdlog/logger.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

namespace shigenoy::usd_dynamic_file_formats::common {
constexpr auto logger_name{"usd-dynamic-file-formats-template"};

inline std::shared_ptr<spdlog::logger> load_logger() {
    auto logger = spdlog::get(logger_name);
    if (!logger) {
        const auto path =
            std::filesystem::temp_directory_path() / logger_name / "simple.log";
        logger = spdlog::basic_logger_mt(logger_name, path.generic_string());
        spdlog::cfg::load_env_levels();
    }

    return logger;
}
}  // namespace shigenoy::usd_dynamic_file_formats::common

#endif  // SHIGENOY_USDDYNAMICFILEFORMATS_COMMON_LOGGER_LOADER_HPP_INCLUDED
