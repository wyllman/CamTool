Control de versiones y cambios.
==============================

- v 0.0.1:
  - Estructura inicial de archivos y carpetas (ventana principal QT).
  - En main.cpp crear ejemplo de catura de webCam usando OpenCv (sin QT).
  - Iniciar el control de versiones git con repositorio remoto en GitHub.
  - Integración del proyecto en la plataforma Travis CI (creación del archivo .travis.yml)
  - Instalación de las librerías de OpenCV, el compilador de QT y las librerías CppUnit en Travis.(.travis.yml)
  - Crear archivo .pro para travis.(CamTool.travis.pro)
  - Compilar el proyecto en travis usando el archivo .pro propio.(CamTool.travis.pro, .travis.yml)
  - Crear versión inicial de la documentación usando DoxyGen.(Archivo de configuración Doxyfile).
  - Crear la estructura inicial de la clase CameraController y sus expectativas.
  - Instalar en travis Xvfb(xserver) para las ejecuciones del programa.
  - Creación de la clase Base_spec como clase padre para todas las demás clases de las expectativas.
