#pragma once

#include <parrlibcore/stringutils.h>

namespace prb {
	namespace strup {
		inline std::wstring fallbackPath(std::wstring const& prefix, std::wstring const& path) { return stru::fallbackPath(prefix, L"parrlibglassets", path); }
		inline std::wstring fallbackPath(std::wstring const& path) { return stru::fallbackPath(L"", L"parrlibglassets", path); }
		
		inline std::string fallbackPath(std::string const& prefix, std::string const& path) { return stru::fallbackPath(prefix, "parrlibglassets", path); }
		inline std::string fallbackPath(std::string const& path) { return stru::fallbackPath("", "parrlibglassets", path); }
	}
}
