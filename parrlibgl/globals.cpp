#include "globals.h"

#include "sprite.h"

#include "mesh3d.h"

namespace prb {
	namespace globals {
		std::unordered_map<std::string, TextRenderer> txrs;

		bool findTxr(std::string const& name) { return txrs.find(name) != txrs.end(); }
		void txr(std::string const& name, std::vector<std::string> const& fonts, int const& fontSize) { txrs[name] = { fonts, fontSize }; }
		void txr(std::string const& name, std::string const& font, int const& fontSize) { txr(name, std::vector<std::string>{ font }, fontSize); }
		void txr(std::string const& name, int const& fontSize) { txr(name, "assets/fonts/segoeui.ttf", fontSize); }
		TextRenderer& txr(std::string const& name) {
			if (txrs.find(name) == txrs.end()) txr(name, 24);
			return txrs[name];
		}

		std::unordered_map<std::string, Sprite> sprites;
		bool findSprite(std::string const& name) { return sprites.find(name) != sprites.end(); }
		void sprite(std::string const& name, Sprite const& s) { sprites[name] = s; }
		Sprite& sprite(std::string const& name) {
			if (sprites.find(name) == sprites.end()) sprites[name] = name.c_str();
			return sprites[name];
		}

		std::unordered_map<std::string, Shader> shaders;
		bool findShader(std::string const& name) { return shaders.find(name) != shaders.end(); }
		void shader(std::string const& name, Shader const& sh) { shaders[name] = sh; }
		Shader& shader(std::string const& name) {
			if (shaders.find(name) == shaders.end()) shaders[name] = { (name + ".vert"), (name + ".frag") };
			return shaders[name];
		}

		std::unordered_map<std::string, VAO> vaos;
		bool findVAO(std::string const& name) { return vaos.find(name) != vaos.end(); }
		void vao(std::string const& name, VAO const& vao) { vaos[name] = vao; }
		VAO& vao(std::string const& name) {
			if (vaos.find(name) == vaos.end()) vaos[name] = {};
			return vaos[name];
		}


		std::unordered_map<std::string, Mesh3D> meshes;
		bool findMesh(std::string const& name) { return meshes.find(name) != meshes.end(); }
		void mesh(std::string const& name, Mesh3D const& m) { meshes[name] = m; }
		Mesh3D& mesh(std::string const& name) {
			if (!findMesh(name)) meshes[name] = { name.c_str() };
			return meshes[name];
		}
	}
}
