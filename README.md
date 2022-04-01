# parrlibgl
OpenGL specific branch of the parrlib framework, see [parrlib](https://github.com/AlessandroParrotta/parrlib) for details.

parrlibgl is a Windows-only framework that facilitates the creation and development of graphics applications based on OpenGL.

in order to build parrlibgl, you'll need:
  * [GLFW](https://www.glfw.org/) (at least version 3.3)
  * [freetype2](https://freetype.org/)
  * [SOIL](https://github.com/littlstar/soil)

# User Macros for include/library paths
parrlibgl uses some User Macros to facilitate the development of multiple projects at the same time; 
A file called PropertySheet.props that contains the names of these macros (with empty value fields) is included in the root folder of the project; it is responsibility of the user to populate the macros of this PropertySheet in order to be able to include the header and library files within the project (alternatively, it is possible to just edit the Include and Library directories in the project properties)

