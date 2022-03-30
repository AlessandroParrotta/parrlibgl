#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <mutex>

#include "Context.h"

#include "TextRenderer.h"

namespace prb {
	namespace debug {

		extern bool enabled;

		class logss : public std::wstringstream {
			std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
		public:
			logss& operator<< (const char* str) {
				*this << converter.from_bytes(str);
				return *this;
			}

			logss& operator<< (std::string const& str) {
				*this << converter.from_bytes(str);
				return *this;
			}

			logss& operator<< (std::wstring const& v) { *((std::wstringstream*)(this)) << v; return *this; }

			logss& operator<< (int const& v) { *((std::wstringstream*)(this)) << v; return *this; }
			logss& operator<< (unsigned int const& v) { *((std::wstringstream*)(this)) << v; return *this; }
			logss& operator<< (float const& v) { *((std::wstringstream*)(this)) << v; return *this; }
			logss& operator<< (double const& v) { *((std::wstringstream*)(this)) << v; return *this; }
		};

		extern logss log, rtlog;

		/*class stringstreamall {
		public:
			std::stringstream ss;
			Console &cs;
			template<typename T>
			std::stringstream operator<< (T val) {
				log << val;
				cs::log << val;
				ss << val;
			}

			stringstreamall(Console &cs) : cs(cs) {

			}
		};
		extern stringstreamall logall;*/

		extern float slider;

		extern TextRenderer txr;

		/*extern int numRTStrs;
		extern int numStrs;*/

		extern int maxStrs;
		extern int maxRTStrs;

		extern bool enableMsgCorner;

		extern std::vector<std::wstring> strs;
		extern std::vector<std::wstring> rtStrs;

		void startResizing();
		void resize();
		void endResizing();

		void init();

		void update();

		void print(std::string s);
		void println(std::string s);


		void rtPrint(std::string s);
		void rtPrintln(std::string s);

		inline std::stringstream& composess() { static std::stringstream composesst; return composesst; };
		template<typename... Args> inline std::string compose(Args... args) {
			int unpack[] = { ([](auto& arg) {
				composess() << arg;
			}(args), 0)..., 0 };
			static_cast<void>(unpack);

			std::string str = composess().str();
			composess().clear(); composess().str("");

			return str;
		}
		template<typename... Args> inline std::string fmt(Args... args) { return compose(args...); }
		template<typename... Args> inline void pr(Args... args) { log << compose(args...); }
		template<typename... Args> inline void prt(Args... args) { rtlog << compose(args...); }
		template<typename... Args> inline void out(Args... args) { std::cout << compose(args...); }

		namespace th {
			extern std::mutex mtx;
			extern std::condition_variable cv;
			extern std::stringstream composess;
			template<typename... Args> inline std::string compose(Args... args) {
				int unpack[] = { ([](auto& arg) {
					composess << arg;
				}(args), 0)..., 0 };
				static_cast<void>(unpack);

				//std::unique_lock<std::mutex> lck(mtx);
					std::string str = composess.str();
					composess.clear(); composess.str("");

				return str;
			}
			template<typename... Args> inline void pr(Args... args) { std::lock_guard<std::mutex> lck(mtx); log << compose(args...); }
			template<typename... Args> inline void prt(Args... args) { std::lock_guard<std::mutex> lck(mtx); rtlog << compose(args...); }
			template<typename... Args> inline void out(Args... args) { std::lock_guard<std::mutex> lck(mtx); std::cout << compose(args...); }
		}



		void drawQuad(Vector2f pos, Vector2f size, Vector4f color);

		void drawQuad(Vector2f pos, Vector2f size);

		void drawQuad(AxisAlignedBoundingBox2D const& bb);
		void drawQuad(AxisAlignedBoundingBox2D const& bb, vec4 color);


		void drawCircle(Vector2f pos, float radius, Vector4f color);

		void drawCircle(Vector2f pos, float radius);


		void drawLine(Vector2f p1, Vector2f p2, Vector4f color);

		void drawLine(Vector2f p1, Vector2f p2);


		void drawText(std::string text, Vector2f pos, float textScale, Vector4f color);

		void drawText(std::string text, Vector2f pos, float textScale);


		void drawObjects();
		void draw();
	}

#ifndef PARRLIB_NAMESPACE_SHORTEN
	namespace deb = debug;
#endif
}
