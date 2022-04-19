#pragma once

#include <string>
#include <unordered_map>

#include "textrenderer.h"

namespace prb {
	class Sprite;
	class Mesh3D;

	namespace globals {
		bool findTxr(std::string const& name);
		void txr(std::string const& name, std::vector<std::string> const& fonts, int const& fontSize);
		void txr(std::string const& name, std::string const& font, int const& fontSize);
		void txr(std::string const& name, int const& fontSize);
		TextRenderer& txr(std::string const& name);

		bool findSprite(std::string const& name);
		void sprite(std::string const& name, Sprite const& s);
		Sprite& sprite(std::string const& name);

		bool findShader(std::string const& name);
		void shader(std::string const& name, Shader const& sh);
		Shader& shader(std::string const& name);

		bool findVAO(std::string const& name);
		void vao(std::string const& name, VAO const& vao);
		VAO& vao(std::string const& name);

		bool findMesh(std::string const& name);
		void mesh(std::string const& name, Mesh3D const& m);
		Mesh3D& mesh(std::string const& name);
	}

#ifndef PARRLIB_NAMESPACE_SHORTEN
	namespace glb = globals;
#endif
}
